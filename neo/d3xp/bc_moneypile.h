#include "trigger.h"

class idTrigger_moneypile : public idTrigger_Multi
{
public:
	CLASS_PROTOTYPE(idTrigger_moneypile);

						idTrigger_moneypile();
	virtual				~idTrigger_moneypile(void);
	void				Spawn();
	virtual void		Think(void);

	virtual void		Event_PostSpawn(void);

private:
	//void				Event_Touch(idEntity* other, trace_t* trace);
	
	bool				waitingForTrigger;

	int					thinkTimer;

	void				DoParticleBurst();

	idEntityPtr<idEntity>	zenaEnt;
	
};