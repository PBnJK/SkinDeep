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

#ifndef __LANGDICT_H__
#define __LANGDICT_H__

#include "idlib/containers/List.h"
#include "idlib/containers/HashIndex.h"
#include "idlib/Str.h"

/*
===============================================================================

	Simple dictionary specifically for the localized string tables.

===============================================================================
*/

class idLangKeyValue {
public:
	idStr					key;
	idStr					value;
	idStr					comment; // SM: Added persistent comment data to aid localization
};

class idLangDict {
public:
							idLangDict( void );
							~idLangDict( void );

	void					Clear( void );
	bool					Load( const char *fileName, bool clear = true );
	void					Save( const char *fileName );

	// SM: Modified signatures of AddString/GetString
	const char *			AddString( const char *str, const char *prefix = "#str" );
	const char *			GetString( const char *str, bool warnIfMissing = true ) const;

							// adds the value and key as passed (doesn't generate a "#str_xxxxx" key or ensure the key/value pair is unique)
	void					AddKeyVal( const char *key, const char *val );

	int						GetNumKeyVals( void ) const;
	const idLangKeyValue *	GetKeyVal( int i ) const;

	void					SetBaseID(int id) { baseID = id; };

	// SM: Made this public
	bool					ExcludeString( const char *str ) const;

	// SM: Tells you if key is in this idLangDict
	bool					ContainsKey( const char* str );
	// SM: Will add any keys from other idLangDict which are missing into this one
	void					AddMissingKeys( const idLangDict& otherDict );
private:
	idList<idLangKeyValue>	args;
	idHashIndex				hash;

	int						GetNextId( void ) const;
	int						GetHashKey( const char *str ) const;

	int						baseID;
};

#endif /* !__LANGDICT_H__ */
