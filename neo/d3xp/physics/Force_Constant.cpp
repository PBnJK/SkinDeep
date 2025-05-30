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

#include "sys/platform.h"
#include "physics/Physics.h"
#include "gamesys/SaveGame.h"

#include "physics/Force_Constant.h"

CLASS_DECLARATION( idForce, idForce_Constant )
END_CLASS

/*
================
idForce_Constant::idForce_Constant
================
*/
idForce_Constant::idForce_Constant( void ) {
	force		= vec3_zero;
	physics		= NULL;
	id			= 0;
	point		= vec3_zero;
}

/*
================
idForce_Constant::~idForce_Constant
================
*/
idForce_Constant::~idForce_Constant( void ) {
}

/*
================
idForce_Constant::Save
================
*/
void idForce_Constant::Save( idSaveGame *savefile ) const {
	savefile->WriteVec3( force ); // idVec3 force
	savefile->WriteObject( physics ); // idPhysics * physics
	savefile->WriteInt( id ); // int id
	savefile->WriteVec3( point ); // idVec3 point
}

/*
================
idForce_Constant::Restore
================
*/
void idForce_Constant::Restore( idRestoreGame *savefile ) {
	savefile->ReadVec3( force ); // idVec3 force
	savefile->ReadObject( CastClassPtrRef(physics) ); // idPhysics * physics
	savefile->ReadInt( id ); // int id
	savefile->ReadVec3( point ); // idVec3 point
}

/*
================
idForce_Constant::SetPosition
================
*/
void idForce_Constant::SetPosition( idPhysics *physics, int id, const idVec3 &point ) {
	this->physics = physics;
	this->id = id;
	this->point = point;
}

/*
================
idForce_Constant::SetForce
================
*/
void idForce_Constant::SetForce( const idVec3 &force ) {
	this->force = force;
}

/*
================
idForce_Constant::SetPhysics
================
*/
void idForce_Constant::SetPhysics( idPhysics *physics ) {
	this->physics = physics;
}

/*
================
idForce_Constant::Evaluate
================
*/
void idForce_Constant::Evaluate( int time ) {
	idVec3 p;

	if ( !physics ) {
		return;
	}

	p = physics->GetOrigin( id ) + point * physics->GetAxis( id );

	physics->AddForce( id, p, force );
}

/*
================
idForce_Constant::RemovePhysics
================
*/
void idForce_Constant::RemovePhysics( const idPhysics *phys ) {
	if ( physics == phys ) {
		physics = NULL;
	}
}
