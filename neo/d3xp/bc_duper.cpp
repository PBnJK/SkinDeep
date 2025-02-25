#include "sys/platform.h"
#include "gamesys/SysCvar.h"
#include "physics/Physics_RigidBody.h"
#include "Entity.h"
#include "Light.h"
#include "Player.h"
#include "Fx.h"
#include "framework/DeclEntityDef.h"
#include "idlib/LangDict.h"

#include "WorldSpawn.h"
#include "bc_duper.h"
#include "bc_skullsaver.h"



//Duper
//Duplicates objects in world.

#define COLLISION_MISFIRE_VELOCITY_THRESHOLD 100
#define MISFIRE_COOLDOWNTIME 300
#define MISFIRE_RADIUS 256

CLASS_DECLARATION(idMoveableItem, idDuper)
//EVENT(EV_Touch, idDuper::Event_Touch)
END_CLASS

void idDuper::Save(idSaveGame *savefile) const
{
}

void idDuper::Restore(idRestoreGame *savefile)
{
}

void idDuper::Spawn(void)
{
	//Allow player to clip through it.
	GetPhysics()->SetContents(CONTENTS_RENDERMODEL | CONTENTS_TRIGGER);
	physicsObj.SetClipMask(MASK_SOLID | CONTENTS_RENDERMODEL);

	misfireCooldownTimer = 0;
	chargesRemaining = spawnArgs.GetInt("charges");
	lastAimState = false;
	this->GetRenderEntity()->gui[0] = uiManager->FindGui(spawnArgs.GetString("gui"), true, true); //Create a UNIQUE gui so that it doesn't auto sync with other guis.
	spawnTime = gameLocal.time;

	Event_SetGuiInt("charges", chargesRemaining);

	BecomeActive(TH_THINK);
}

void idDuper::Think(void)
{
	//only do the item detection of it's being held by the player.
	if (gameLocal.GetLocalPlayer()->GetCarryable() != NULL)
	{
		if (gameLocal.GetLocalPlayer()->GetCarryable() == this)
		{
			aimedEnt = FindAimedEntity();
			if (aimedEnt.IsValid())
			{
				//Is aiming at something.

				Event_SetGuiInt("showitem", 1);

				Event_SetGuiParm("itemname", aimedEnt.GetEntity()->displayName.c_str());

				Event_SetGuiParm("attack_key", gameLocal.GetKeyFromBinding("_attack"));

				if (!lastAimState)
				{
					lastAimState = true;
					StartSound("snd_select", SND_CHANNEL_ANY);
				}
			}
			else
			{
				//Not aiming at anything.
				Event_SetGuiInt("showitem", 0); //Hide the gui prompt

				if (lastAimState)
				{
					lastAimState = false;
					StartSound("snd_deselect", SND_CHANNEL_ANY);
				}
			}
		}
	}
	

	idMoveableItem::Think();
}

idEntity *idDuper::FindAimedEntity()
{
	//Find what is the player currently aiming at.
	
	//Do traceline foward from player eyeball.
	trace_t tr;
	gameLocal.clip.TracePoint(tr,
		gameLocal.GetLocalPlayer()->firstPersonViewOrigin,
		gameLocal.GetLocalPlayer()->firstPersonViewOrigin + gameLocal.GetLocalPlayer()->viewAngles.ToForward() * 1024,
		MASK_SHOT_RENDERMODEL, NULL);

	//Skip if it's worldspawn...
	if (tr.fraction >= 1 || tr.c.entityNum == ENTITYNUM_WORLD || tr.c.entityNum <= 0)
		return NULL;

	//Skip if it's null....
	if (gameLocal.entities[tr.c.entityNum] == NULL)
		return NULL;	

	//TODO: do we want things that are not idmoveableitem?
	if (!gameLocal.entities[tr.c.entityNum]->IsType(idMoveableItem::Type))
		return NULL;
	
	//Skip hidden objects.
	if (gameLocal.entities[tr.c.entityNum]->IsHidden())
		return NULL;

	//Don't allow dupe of skull.
	if (gameLocal.entities[tr.c.entityNum]->IsType(idSkullsaver::Type))
		return NULL;

	return gameLocal.entities[tr.c.entityNum];
}

idEntity *idDuper::FindMisfireEntity()
{
	//Make it very easy for the duper to find something to dupe. This prioritizes whatever the duper is looking straight at.
	//But, if it finds nothing, it resorts to finding just anything, including things behind itself.
	int entityCount;
	idEntity *entityList[MAX_GENTITIES];
	entityCount = gameLocal.EntitiesWithinRadius(this->GetPhysics()->GetOrigin(), MISFIRE_RADIUS, entityList, MAX_GENTITIES);

	float bestVDot = -999;
	int bestIndex = -1;
	for (int i = 0; i < entityCount; i++)
	{
		idEntity *ent = entityList[i];

		if (!ent)
			continue;

		if (ent->IsHidden() || !ent->IsType(idMoveableItem::Type) || ent->entityNumber == this->entityNumber) //todo: make this better
			continue;		

		//dotproduct check. This makes it choose things closest to whatever it's aiming at.
		idVec3 dirToTarget = ent->GetPhysics()->GetOrigin() - this->GetPhysics()->GetOrigin();
		dirToTarget.Normalize();
		float vdot = DotProduct(dirToTarget, this->GetPhysics()->GetAxis().ToAngles().ToForward());

		if (vdot > bestVDot)
		{
			bestVDot = vdot;
			bestIndex = i;
		}
	}

	if (bestIndex >= 0)
	{
		//gameRenderWorld->DebugArrow(colorGreen, this->GetPhysics()->GetOrigin(), entityList[bestIndex]->GetPhysics()->GetOrigin(), 4, 10000);
		return entityList[bestIndex];
	}

	return NULL;
}

bool idDuper::DoFrob(int index, idEntity * frobber)
{
	if (frobber == gameLocal.GetLocalPlayer())
	{
		if (index == CARRYFROB_INDEX)
		{
			//Player is frobbing while holding the item. Do the dupe.
			DoDupe();
		}
		else
		{
			//Player is picking me up.
			idMoveableItem::DoFrob(index, frobber);
		}		
	}
	else
	{
		//Frobbed by something not the player.
		//Do a misfire.
		DoMisfire();
	}

	return true;
}

bool idDuper::Collide(const trace_t &collision, const idVec3 &velocity)
{
	float v;
	v = -(velocity * collision.c.normal);
	if (v > COLLISION_MISFIRE_VELOCITY_THRESHOLD && gameLocal.time > spawnTime + 500) //don't make it misfire right on spawn.
	{
		//If the item hits the ground at sufficient velocity, we do a misfire.
		DoMisfire();
	}

	return idMoveableItem::Collide(collision, velocity);
}

void idDuper::DoMisfire()
{
	if (misfireCooldownTimer > gameLocal.time)
		return;

	misfireCooldownTimer = gameLocal.time + MISFIRE_COOLDOWNTIME; //it's too hard to understand the misfire when it happens too rapidly, so add a cooldown timer.

	if (chargesRemaining > 0)
		gameLocal.AddEventLog("#str_def_gameplay_duper_misfire", GetPhysics()->GetOrigin());

	aimedEnt = FindMisfireEntity();	

	if (aimedEnt.IsValid())
	{
		idEntityFx::StartFx(spawnArgs.GetString("fx_misfire"), &GetPhysics()->GetOrigin(), &mat3_identity, NULL, false);		
	}

	DoDupe();
	aimedEnt = NULL;
}

void idDuper::DoDupe()
{
	if (chargesRemaining <= 0)
	{
		StartSound("snd_dryfire", SND_CHANNEL_ANY);
		Event_GuiNamedEvent(1, "noCharges");
		return;
	}

	if (!aimedEnt.IsValid())
	{
		StartSound("snd_cancel", SND_CHANNEL_ANY);
		Event_GuiNamedEvent(1, "noItem");
		return;
	}

	idVec3 spawnPos = FindClearSpawnSpot();
	if (spawnPos == vec3_zero)
	{
		//failed to find a clear spawn pos.
		StartSound("snd_cancel", SND_CHANNEL_ANY);
		return;
	}

	// SW: entity can call a script when we attempt to dupe it. Used by a milestone in sh_observatory
	idStr dupeAttemptScript;
	if (aimedEnt.GetEntity()->spawnArgs.GetString("callOnDupeAttempt", "", dupeAttemptScript))
	{
		gameLocal.RunMapScript(dupeAttemptScript);
	}

	bool isSuccess = !aimedEnt.GetEntity()->IsType(idDuper::Type);
	if (isSuccess)
	{
		//Successful clone.

		StartSound("snd_dupe", SND_CHANNEL_ANY);
		gameLocal.DoParticle(spawnArgs.GetString("model_spawnparticle"), spawnPos);

		if (gameLocal.GetLocalPlayer()->GetCarryable() != NULL)
		{
			if (gameLocal.GetLocalPlayer()->GetCarryable() == this)
			{
				gameLocal.GetLocalPlayer()->SetImpactSlowmo(true);
			}
		}

		idEntity *clonedEnt;
		idDict args;
		args.Set("classname", aimedEnt.GetEntity()->spawnArgs.GetString("classname"));
		args.SetVector("origin", spawnPos);
		gameLocal.SpawnEntityDef(args, &clonedEnt);
		if (clonedEnt)
		{
			clonedEnt->GetPhysics()->SetLinearVelocity(idVec3(0, 0, 128));
			idVec3 dir = GetPhysics()->GetAxis().ToAngles().ToForward();
			clonedEnt->GetPhysics()->SetAngularVelocity(dir * 32);

			gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_duper_dupe"), clonedEnt->displayName.c_str()), GetPhysics()->GetOrigin());

			Event_GuiNamedEvent(1, "doDupe");
			chargesRemaining--;
			Event_SetGuiInt("charges", chargesRemaining);
		}
	}
	else
	{
		//Fail.  Player is likely trying to dupe a duper.
		StartSound("snd_fail", SND_CHANNEL_ANY);

		Event_GuiNamedEvent(1, "error");
	}
}

idVec3 idDuper::FindClearSpawnSpot()
{
	#define OBJECTRADIUS 8
	idBounds objectBound = idBounds(idVec3(-OBJECTRADIUS, -OBJECTRADIUS, -OBJECTRADIUS), idVec3(OBJECTRADIUS, OBJECTRADIUS, OBJECTRADIUS));

	//Forward, right, up
	#define DUPARRAYSIZE 18
	#define SPAWNDIST 16
	idVec3 clearanceArray[] =
	{
		//in front of it
		idVec3(SPAWNDIST,0,0),
		idVec3(SPAWNDIST,-SPAWNDIST,0),
		idVec3(SPAWNDIST,SPAWNDIST,0),

		idVec3(SPAWNDIST,0,SPAWNDIST),
		idVec3(SPAWNDIST,-SPAWNDIST,SPAWNDIST),
		idVec3(SPAWNDIST,SPAWNDIST,SPAWNDIST),

		idVec3(SPAWNDIST,0,-SPAWNDIST),
		idVec3(SPAWNDIST,-SPAWNDIST,-SPAWNDIST),
		idVec3(SPAWNDIST,SPAWNDIST,-SPAWNDIST),

		//behind it
		idVec3(-SPAWNDIST,0,0),
		idVec3(-SPAWNDIST,-SPAWNDIST,0),
		idVec3(-SPAWNDIST,SPAWNDIST,0),

		idVec3(-SPAWNDIST,0,SPAWNDIST),
		idVec3(-SPAWNDIST,-SPAWNDIST,SPAWNDIST),
		idVec3(-SPAWNDIST,SPAWNDIST,SPAWNDIST),

		idVec3(-SPAWNDIST,0,-SPAWNDIST),
		idVec3(-SPAWNDIST,-SPAWNDIST,-SPAWNDIST),
		idVec3(-SPAWNDIST,SPAWNDIST,-SPAWNDIST),
	};

	idVec3 forward, right, up;
	GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);
	//gameLocal.GetLocalPlayer()->viewAngles.ToVectors(&forward, &right, &up);
	for (int i = 0; i < DUPARRAYSIZE; i++)
	{
		idVec3 candidatePos = GetPhysics()->GetOrigin() + (forward * clearanceArray[i].x) + (right * clearanceArray[i].y) + (up * clearanceArray[i].z);

		int penetrationContents = gameLocal.clip.Contents(candidatePos, NULL, mat3_identity, CONTENTS_SOLID, NULL);
		if (penetrationContents & MASK_SOLID)
		{
			continue; //If it starts in solid, then exit.
		}

		trace_t tr;
		gameLocal.clip.TraceBounds(tr, candidatePos, candidatePos, objectBound, MASK_SOLID, NULL);

		if (tr.fraction >= 1)
		{
			return candidatePos;
		}
	}

	//Failed.
	gameLocal.Warning("Duper: failed to find clear spawn position.\n");
	return vec3_zero;
}