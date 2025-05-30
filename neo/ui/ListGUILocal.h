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

#ifndef __LISTGUILOCAL_H__
#define __LISTGUILOCAL_H__

#include "idlib/containers/List.h"
#include "ui/ListGUI.h"

/*
===============================================================================

	feed data to a listDef
	each item has an id and a display string

===============================================================================
*/

class idListGUILocal : protected idList<idStr>, public idListGUI {
public:
						idListGUILocal() { m_pGUI = NULL; m_water = 0; m_stateUpdates = true; }

	void				Save( idSaveGame *savefile ) const; // blendo eric: savegame pass 1
	void				Restore( idRestoreGame *savefile );


	// idListGUI interface
	void				Config( idUserInterface *pGUI, const char *name ) { m_pGUI = pGUI; m_name = name; }
	void				Add( int id, const idStr& s, bool allowDupes = false );
						// use the element count as index for the ids
	void				Push( const idStr& s );
	bool				Del( int id );
	void				Clear( void );
	int					Num( void ) const { return idList<idStr>::Num(); }
	int					GetSelection( char *s, int size, int sel = 0 ) const; // returns the id, not the list index (or -1)
	void				SetSelection( int sel );
	int					GetNumSelections();
	bool				IsConfigured( void ) const;
	void				SetStateChanges( bool enable );
	void				Shutdown( void );

private:
	idUserInterface *	m_pGUI;
	idStr				m_name;
	int					m_water;
	idList<int>			m_ids;
	bool				m_stateUpdates;

	void				StateChanged();
};

#endif /* !__LISTGUILOCAL_H__ */
