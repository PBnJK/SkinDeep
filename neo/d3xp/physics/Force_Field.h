/*
===========================================================================

Doom 3 GPL Source Code
Copyright (C) 1999-2011 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 GPL Source Code ("Doom 3 Source Code").

Doom 3 Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#ifndef __FORCE_FIELD_H__
#define __FORCE_FIELD_H__

#include "physics/Force.h"
#include "physics/Clip.h"
#include "Entity.h"
#include "AFEntity.h"

/*
===============================================================================

	Force field

===============================================================================
*/

enum forceFieldType {
	FORCEFIELD_UNIFORM,
	FORCEFIELD_EXPLOSION,
	FORCEFIELD_IMPLOSION
};

enum forceFieldApplyType {
	FORCEFIELD_APPLY_FORCE,
	FORCEFIELD_APPLY_VELOCITY,
	FORCEFIELD_APPLY_IMPULSE
};

class idForce_Field : public idForce {

public:
	CLASS_PROTOTYPE( idForce_Field );

	void				Save( idSaveGame *savefile ) const; // blendo eric: savegame pass 1
	void				Restore( idRestoreGame *savefile );

						idForce_Field( void );
	virtual				~idForce_Field( void );
						// uniform constant force
	void				Uniform( const idVec3 &force );
						// explosion from clip model origin
	void				Explosion( float force );
						// implosion towards clip model origin
	void				Implosion( float force );
						// add random torque
	void				RandomTorque( float force );
						// should the force field apply a force, velocity or impulse
	void				SetApplyType( const forceFieldApplyType type ) { applyType = type; }
						// make the force field only push players
	void				SetPlayerOnly( bool set ) { playerOnly = set; }
						// make the force field only push monsters
	void				SetMonsterOnly( bool set ) { monsterOnly = set; }
						// clip model describing the extents of the force field
	void				SetClipModel( idClipModel *clipModel );

public: // common force interface
	virtual void		Evaluate( int time );

private:
	// force properties
	forceFieldType		type;
	forceFieldApplyType	applyType;
	float				magnitude;
	idVec3				dir;
	float				randomTorque;
	bool				playerOnly;
	bool				monsterOnly;
	idClipModel *		clipModel;
};

#endif /* !__FORCE_FIELD_H__ */
