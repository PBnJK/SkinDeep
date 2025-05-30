#include "Misc.h"
#include "Entity.h"

#include "Item.h"


class idEMPGrenade : public idMoveableItem
{
public:
	CLASS_PROTOTYPE(idEMPGrenade);

							idEMPGrenade(void);
	virtual					~idEMPGrenade(void);

	void					Save(idSaveGame *savefile) const; // blendo eric: savegame pass 1
	void					Restore(idRestoreGame *savefile);

	void					Spawn(void);	
	virtual bool			Collide(const trace_t &collision, const idVec3 &velocity);
	virtual void			Think(void);
	//virtual void			Killed(idEntity *inflictor, idEntity *attacker, int damage, const idVec3 &dir, int location);
	//void					Event_Touch(idEntity *other, trace_t *trace);	
	//virtual void			Damage(idEntity *inflictor, idEntity *attacker, const idVec3 &dir, const char *damageDefName, const float damageScale, const int location, const int materialType = SURFTYPE_NONE);
	//virtual bool			DoFrob(int index = 0, idEntity * frobber = NULL);
	virtual void			JustThrown();

private:

	bool					DoEMPBlast();

	enum					{ HG_IDLE, HG_AIRBORNE, HG_DEPLOYED, HG_DEPLETED };
	int						state;
	int						stateTimer;

	trace_t					collisionTr;

	
	
};
//#pragma once