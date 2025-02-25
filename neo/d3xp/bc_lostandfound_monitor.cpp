#include "sys/platform.h"
#include "gamesys/SysCvar.h"
#include "Entity.h"
//#include "Light.h"
#include "Player.h"
//#include "Fx.h"


#include "framework/DeclEntityDef.h"
#include "idlib/LangDict.h"
#include "bc_ftl.h"

#include "bc_gunner.h"
#include "bc_lostandfound_monitor.h"
#include "bc_lostandfound.h"


const int THINK_INTERVAL = 3000;
const int TOTAL_ENTRIES_IN_GUI = 8; //what is the max amount of entries in security_station.gui

CLASS_DECLARATION(idStaticEntity, idLostandfoundMonitor)
END_CLASS

idLostandfoundMonitor::idLostandfoundMonitor(void)
{
	lostandfoundMachine = NULL;

	proximityAnnouncer.sensor = this;
	proximityAnnouncer.checkHealth = false;
	proximityAnnouncer.coolDownPeriod = 10000;
}

idLostandfoundMonitor::~idLostandfoundMonitor(void)
{
}

void idLostandfoundMonitor::Spawn(void)
{
	securityState = LFM_ACTIVE;

	fl.takedamage = true;
	GetPhysics()->SetContents(CONTENTS_RENDERMODEL);
	GetPhysics()->SetClipMask(MASK_SOLID | CONTENTS_MOVEABLECLIP);
	idleSmoke = NULL;
	thinkTimer = 0;	
    unlocked = false;

    //make it repairable.
    repairNode.SetOwner(this);
    repairNode.AddToEnd(gameLocal.repairEntities);

    this->GetRenderEntity()->gui[0] = uiManager->FindGui(spawnArgs.GetString("gui"), true, true); //Create a UNIQUE gui so that it doesn't auto sync with other guis.

	//Create the gui list.
	itemList = uiManager->AllocListGUI();
	itemList->Config(renderEntity.gui[0], "itemList");
	itemList->Clear();
	//itemList->SetSelection(0);

	BecomeActive(TH_THINK);

	PostEventMS(&EV_PostSpawn, 0);
}

void idLostandfoundMonitor::Event_PostSpawn(void)
{
	for (idEntity* ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	{
		if (!ent)
			continue;

		if (ent->IsType(idLostAndFound::Type))
		{
			lostandfoundMachine = ent;

			idLocationEntity *locEnt = gameLocal.LocationForEntity(ent);
			if (locEnt)
			{
				Event_SetGuiParm("machinelocation", locEnt->GetLocation());
			}
			
			if (!locEnt)
			{
				locEnt = gameLocal.LocationForPoint(ent->GetPhysics()->GetOrigin() + idVec3(0,0,8));
				if (locEnt)
				{
					Event_SetGuiParm("machinelocation", locEnt->GetLocation());
				}
			}

			if (!locEnt)
			{
				gameLocal.Warning("idLostandfoundMonitor '%s' cannot find location entity for vending machine '%s'", GetName(), ent->GetName());
			}
			
			return;
		}
	}

	//failed to find machine.
	gameLocal.Error("idLostandfoundMonitor '%s' unable to find lostandfound machine.", GetName());
}


void idLostandfoundMonitor::Save(idSaveGame *savefile) const
{
}

void idLostandfoundMonitor::Restore(idRestoreGame *savefile)
{
}

void idLostandfoundMonitor::Think(void)
{	
	//if not in PVS, then don't do anything...
	if (!gameLocal.InPlayerConnectedArea(this))
		return;

	if (securityState == LFM_ACTIVE)
	{
		idList<int> entityDefNums = static_cast<idLostAndFound *>(lostandfoundMachine.GetEntity())->cachedEntityDefNums;

		if (gameLocal.time > thinkTimer)
		{
			thinkTimer = gameLocal.time + THINK_INTERVAL;

			//Grab the lost and found list from the lostandfound vending machine.
			itemList->Clear();

			if (lostandfoundMachine.IsValid())
			{

				for (int i = 0; i < entityDefNums.Num(); i++)
				{
					int defNum = entityDefNums[i];
					const idDeclEntityDef* def = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_ENTITYDEF, defNum));
					idStr itemname = def->dict.GetString("displayname", "???");
					if (itemname[0] == '#')
					{
						itemname = common->GetLanguageDict()->GetString(itemname.c_str()); //get localized string.
					}
					itemList->Add(defNum, itemname.c_str());
				}				
			}
		}

		bool hasCriticalItem = false;

		for (int i = 0; i < entityDefNums.Num(); i++)
		{
			int defNum = entityDefNums[i];
			const idDeclEntityDef* def = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_ENTITYDEF, defNum));
			
			bool isCriticalItem = def->dict.GetBool("criticalitem", "0");
			if (isCriticalItem)
			{
				hasCriticalItem = true;
				break;
			}
		}

		if( hasCriticalItem )
		{
			proximityAnnouncer.Update();
		}
	}

	idStaticEntity::Think();
}

void idLostandfoundMonitor::RefreshList()
{
}


void idLostandfoundMonitor::Damage(idEntity *inflictor, idEntity *attacker, const idVec3 &dir, const char *damageDefName, const float damageScale, const int location, const int materialType)
{
	if (securityState == LFM_DEAD)
		return;

    idDict args;

    Event_GuiNamedEvent(1, "onDamaged");

	securityState = LFM_DEAD;
    this->isFrobbable = false;

    needsRepair = true;
    repairrequestTimestamp = gameLocal.time;

	gameLocal.DoParticle("explosion_gascylinder.prt", GetPhysics()->GetOrigin());
	StartSound("snd_broken", SND_CHANNEL_BODY, 0, false, NULL);

	if (idleSmoke == NULL)
	{
		idVec3 forward;
		idAngles angles;

		this->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, NULL, NULL);
		angles = this->GetPhysics()->GetAxis().ToAngles();
		angles.pitch += 90;

		args.Clear();
		args.Set("model", "machine_damaged_smoke.prt");
		args.Set("start_off", "0");
		idleSmoke = static_cast<idFuncEmitter *>(gameLocal.SpawnEntityType(idFuncEmitter::Type, &args));		
		idleSmoke->SetOrigin(GetPhysics()->GetOrigin() + idVec3(0, 0, 4) + (forward * 8));
		idleSmoke->SetAxis(angles.ToMat3());
	}
	else
	{
		idleSmoke->SetActive(true);
	}

	SetSkin(declManager->FindSkin(spawnArgs.GetString("brokenskin")));

    BecomeInactive(TH_THINK);
}

void idLostandfoundMonitor::DoRepairTick(int amount)
{    
    UpdateVisuals();


	Event_GuiNamedEvent(1, "onRepaired"); //return to locked screen.		

	SetSkin(declManager->FindSkin(spawnArgs.GetString("skin")));

	if (idleSmoke != NULL)
	{
		idleSmoke->SetActive(false);
	}

    //Repair is done!
    health = maxHealth;
    needsRepair = false;
    BecomeActive(TH_THINK);
}