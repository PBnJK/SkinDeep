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

#ifndef __FORCE_GRAB_H__
#define __FORCE_GRAB_H__

#ifdef _D3XP

#include "physics/Force.h"

/*
===============================================================================

	Drag force

===============================================================================
*/

class idForce_Grab : public idForce {

public:
	CLASS_PROTOTYPE( idForce_Grab );

	void				Save( idSaveGame *savefile ) const; // blendo eric: savegame pass 1
	void				Restore( idRestoreGame *savefile );

						idForce_Grab( void );
	virtual				~idForce_Grab( void );
						// initialize the drag force
	void				Init( float damping );
						// set physics object being dragged
	void				SetPhysics( idPhysics *physics, int id, const idVec3 &goal );
						// update the goal position
	void				SetGoalPosition( const idVec3 &goal );


public: // common force interface
	virtual void		Evaluate( int time );
	virtual void		RemovePhysics( const idPhysics *phys );

	// Get the distance from object to goal position
	float				GetDistanceToGoal( void );

private:

	// properties
	float				damping;
	idVec3				goalPosition;

	float				distanceToGoal;

	// positioning
	idPhysics *			physics;		// physics object
	int					id;				// clip model id of physics object
};

#endif /* _D3XP */
#endif /* !__FORCE_GRAB_H__ */
