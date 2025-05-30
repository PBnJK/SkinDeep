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
#ifndef __BINDWINDOW_H
#define __BINDWINDOW_H

#include "ui/Window.h"

class idUserInterfaceLocal;

class idBindWindow : public idWindow {
public:
	idBindWindow(idUserInterfaceLocal *gui);
	idBindWindow(idDeviceContext *d, idUserInterfaceLocal *gui);
	virtual ~idBindWindow();

	virtual void WriteToSaveGame( idSaveGame *savefile ) const; // blendo eric: savegame pass 1
	virtual void ReadFromSaveGame( idRestoreGame *savefile );

	virtual const char *HandleEvent(const sysEvent_t *event, bool *updateVisuals);
	virtual void PostParse();
	virtual void Draw(int time, float x, float y);
	virtual size_t Allocated(){return idWindow::Allocated();};
//
//
	virtual idWinVar *GetWinVarByName(const char *_name, bool winLookup = false, drawWin_t** owner = NULL );
//
	virtual void Activate( bool activate, idStr &act );

	virtual bool ParseInternalVar(const char* name, idParser* src);
	virtual bool OverchildInteractive() { return true; }

private:
	void CommonInit();
	bool waitingOnKey;
	bool isGamepad;
};

class idBindDisplayWindow : public idWindow {
public:
	idBindDisplayWindow(idUserInterfaceLocal* gui);
	idBindDisplayWindow(idDeviceContext* d, idUserInterfaceLocal* gui);
	virtual ~idBindDisplayWindow();

	virtual void WriteToSaveGame( idSaveGame *savefile ) const; // blendo eric: savegame pass 1
	virtual void ReadFromSaveGame( idRestoreGame *savefile );

	virtual void PostParse();
	virtual void Draw(int time, float x, float y);
	virtual void DrawBackground(const idRectangle& drawRect);
	virtual size_t Allocated() { return idWindow::Allocated(); };
	//
	//
	virtual idWinVar* GetWinVarByName(const char* _name, bool winLookup = false, drawWin_t** owner = NULL);
	//
	virtual void CalcClientRect(float xofs, float yofs);

private:
	void CommonInit();

	bool cursorAttachActive;
};

#endif // __BINDWINDOW_H
