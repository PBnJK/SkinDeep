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
#include "framework/Common.h"
#include "framework/Game.h"

#include "framework/DeclEntityDef.h"

/*
=================
idDeclEntityDef::Size
=================
*/
size_t idDeclEntityDef::Size( void ) const {
	return sizeof( idDeclEntityDef ) + dict.Allocated();
}

/*
================
idDeclEntityDef::FreeData
================
*/
void idDeclEntityDef::FreeData( void ) {
	dict.Clear();
}

/*
================
idDeclEntityDef::Parse
================
*/
bool idDeclEntityDef::Parse( const char *text, const int textLength ) {
	idLexer src;
	idToken	token, token2;

	src.LoadMemory( text, textLength, GetFileName(), GetLineNum() );
	src.SetFlags( DECL_LEXER_FLAGS );
	src.SkipUntilString( "{" );

	while (1) {
		if ( !src.ReadToken( &token ) ) {
			break;
		}

		if ( !token.Icmp( "}" ) ) {
			break;
		}
		if ( token.type != TT_STRING ) {
			src.Warning( "Expected quoted string, but found '%s'", token.c_str() );
			MakeDefault();
			return false;
		}

		if ( !src.ReadToken( &token2 ) ) {
			src.Warning( "Unexpected end of file" );
			MakeDefault();
			return false;
		}

		if ( dict.FindKey( token ) ) {
			src.Warning( "'%s' already defined", token.c_str() );
		}
		dict.Set( token, token2 );
	}

	// blendo eric: aliased keywords
	// DG: Turned from static idDict into array of structs
	//     because static dicts cause crashes on shutdown
	static const struct NameAlias {
		const char* oldName;
		const char* newName;
	} nameAliases[] = {
		{ "bouncyness", "bounce" },
		{ "friction", "contact_friction" }
	};

	// blendo eric: aliasing replaces equivalent names
	for (int idx = 0; idx < sizeof(nameAliases)/sizeof(nameAliases[0]); idx++) {
		const idKeyValue * kv = dict.FindKey(nameAliases[idx].oldName);
		if (kv) {
			dict.Set(nameAliases[idx].newName, kv->GetValue());
			dict.Delete(nameAliases[idx].oldName);
		}
	}

	// we always automatically set a "classname" key to our name
	dict.Set( "classname", GetName() );

	// "inherit" keys will cause all values from another entityDef to be copied into this one
	// if they don't conflict.  We can't have circular recursions, because each entityDef will
	// never be parsed mroe than once

	// find all of the dicts first, because copying inherited values will modify the dict
	idList<const idDeclEntityDef *> defList;

	while ( 1 ) {
		const idKeyValue *kv;
		kv = dict.MatchPrefix( "inherit", NULL );
		if ( !kv ) {
			break;
		}

		const idDeclEntityDef *copy = static_cast<const idDeclEntityDef *>( declManager->FindType( DECL_ENTITYDEF, kv->GetValue(), false ) );
		if ( !copy ) {
			src.Warning( "Unknown entityDef '%s' inherited by '%s'", kv->GetValue().c_str(), GetName() );
		} else {
			defList.Append( copy );
		}

		// delete this key/value pair
		dict.Delete( kv->GetKey() );
	}

	// now copy over the inherited key / value pairs
	for ( int i = 0 ; i < defList.Num() ; i++ ) {
		dict.SetDefaults( &defList[ i ]->dict );
	}

	// precache all referenced media
	// do this as long as we arent in modview
	if ( !( com_editors & (EDITOR_RADIANT|EDITOR_AAS) ) ) {
		game->CacheDictionaryMedia( &dict );
	}

	return true;
}

/*
================
idDeclEntityDef::DefaultDefinition
================
*/
const char *idDeclEntityDef::DefaultDefinition( void ) const {
	return
		"{\n"
	"\t"	"\"DEFAULTED\"\t\"1\"\n"
		"}";
}

/*
================
idDeclEntityDef::Print

Dumps all key/value pairs, including inherited ones
================
*/
void idDeclEntityDef::Print( void ) const {
	dict.Print();
}
