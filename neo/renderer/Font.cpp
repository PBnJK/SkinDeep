/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company. 

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").  

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#pragma hdrstop
#include "sys/platform.h"
#include "Font.h"
#include "idlib/LangDict.h"
#define ID_SWAP_LITE
#include "idlib/Swap.h"
#include "renderer/RenderSystem.h"
#include "framework/Common.h"
#include "framework/FileSystem.h"

const char * idFont::DEFAULT_FONT = "octin";

static const float old_scale2 = 0.6f;
static const float old_scale1 = 0.3f;

idCVar gui_smallFontLimit( "gui_smallFontLimit", "0.30", CVAR_GUI | CVAR_ARCHIVE, "" );
idCVar gui_mediumFontLimit( "gui_mediumFontLimit", "0.90", CVAR_GUI | CVAR_ARCHIVE, "" );

// SM: Added this so new font scales properly match the old ones
static float GetConvertedFontScale( float scale )
{
	if (scale <= gui_smallFontLimit.GetFloat()) {
		return scale * 0.25f;
	}
	else if (scale <= gui_mediumFontLimit.GetFloat()) {
		return scale * 0.5f;
	}
	else {
		return scale;
	}
}

/*
==============================
Old_SelectValueForScale
==============================
*/
ID_INLINE float Old_SelectValueForScale( float scale, float v0, float v1, float v2 ) {
	return ( scale > gui_mediumFontLimit.GetFloat() ) ? v2 : ( scale > gui_smallFontLimit.GetFloat() ) ? v1 : v0;
}

/*
==============================
idFont::RemapFont
==============================
*/
idFont * idFont::RemapFont( const char * baseName ) {
	idStr cleanName = baseName;

	// SM: For some langauges, we actually need to remap the default font
	//if ( cleanName == DEFAULT_FONT ) {
	//	return NULL;
	//}

	// SM: If the font name has a slash in it, assume this is already the remapped name
	if (cleanName.Find( '/' ) != -1) {
		return NULL;
	}

	idStr fontKey = "#font_" + cleanName;
	const char * remapped = common->GetLanguageDict()->GetString( fontKey.c_str() );
	if (remapped != NULL && cleanName.Icmp( remapped) != 0 && remapped[0] != '#') {
		return renderSystem->RegisterFont( remapped );
	}

	const char * wildcard = common->GetLanguageDict()->GetString( "#font_*" );
	if ( wildcard != NULL && cleanName.Icmp( wildcard ) != 0 && wildcard[0] != '#' ) {
		return renderSystem->RegisterFont( wildcard );
	}

	// Note single | so both sides are always executed
	if ( cleanName.ReplaceChar( ' ', '_' ) | cleanName.ReplaceChar( '-', '_' ) ) {
		return renderSystem->RegisterFont( cleanName );
	}

	return NULL;
}

/*
==============================
idFont::~idFont
==============================
*/
idFont::~idFont() {
	delete fontInfo;
}

/*
==============================
idFont::idFont
==============================
*/
idFont::idFont( const char * n ) : name( n ) {
	// SM: There may be old code still trying to load the "fonts" font which is default
	if ( name == "fonts" ) {
		name = DEFAULT_FONT;
	}

	fontInfo = NULL;
	alias = RemapFont( name.c_str() );

	if ( alias != NULL ) {
		// Make sure we don't have a circular reference
		for ( idFont * f = alias; f != NULL; f = f->alias ) {
			if ( f == this ) {
				idLib::Error( "Font alias \"%s\" is a circular reference!", n );
			}
		}
		return;
	}

	if ( !LoadFont() ) {
		if ( name.Icmp( DEFAULT_FONT ) == 0 ) {
			idLib::Error( "Could not load default font \"%s\"", DEFAULT_FONT );
		} else {
			// SM: If the name is empty, this is okay, so just silently accept it
			if ( name.Length() > 0 ) {
				idLib::Warning( "Could not load font %s", name.c_str() );
			}
			alias = renderSystem->RegisterFont( DEFAULT_FONT );
		}
	}
}

struct oldGlyphInfo_t {
	int					height;			// number of scan lines
	int					top;			// top of glyph in buffer
	int					bottom;			// bottom of glyph in buffer
	int					pitch;			// width for copying
	int					xSkip;			// x adjustment
	int					imageWidth;		// width of actual image
	int					imageHeight;	// height of actual image
	float				s;				// x offset in image where glyph starts
	float				t;				// y offset in image where glyph starts
	float				s2;
	float				t2;
	int					junk;
	char				materialName[32];
};
static const int GLYPHS_PER_FONT = 256;

/*
==============================
LoadOldGlyphData
==============================
*/
bool LoadOldGlyphData( const char * filename, oldGlyphInfo_t glyphInfo[GLYPHS_PER_FONT] ) {
	idFile * fd = fileSystem->OpenFileRead( filename );
	if ( fd == NULL ) {
		return false;
	}
	fd->Read( glyphInfo, GLYPHS_PER_FONT * sizeof( oldGlyphInfo_t ) );
	for ( int i = 0; i < GLYPHS_PER_FONT; i++ ) {
		idSwap::Little( glyphInfo[i].height );
		idSwap::Little( glyphInfo[i].top );
		idSwap::Little( glyphInfo[i].bottom );
		idSwap::Little( glyphInfo[i].pitch );
		idSwap::Little( glyphInfo[i].xSkip );
		idSwap::Little( glyphInfo[i].imageWidth );
		idSwap::Little( glyphInfo[i].imageHeight );
		idSwap::Little( glyphInfo[i].s );
		idSwap::Little( glyphInfo[i].t );
		idSwap::Little( glyphInfo[i].s2 );
		idSwap::Little( glyphInfo[i].t2 );
		//assert( glyphInfo[i].imageWidth == glyphInfo[i].pitch );
		assert( glyphInfo[i].imageHeight == glyphInfo[i].height );
		assert( glyphInfo[i].imageWidth == ( glyphInfo[i].s2 - glyphInfo[i].s ) * 256 );
		assert( glyphInfo[i].imageHeight == ( glyphInfo[i].t2 - glyphInfo[i].t ) * 256 );
		assert( glyphInfo[i].junk == 0 );
	}
	delete fd;
	return true;
}

/*
==============================
idFont::LoadFont
==============================
*/
bool idFont::LoadFont() {
	idStr fontName = va( "newfonts/%s/48.dat", GetName() );
	idFile * fd = fileSystem->OpenFileRead( fontName );
	if ( fd == NULL ) {
		return false;
	}

	const int FONT_INFO_VERSION = 42;
	const int FONT_INFO_MAGIC = ( FONT_INFO_VERSION | ( 'i' << 24 ) | ( 'd' << 16 ) | ( 'f' << 8 ) );

	uint32 version = 0;
	fd->ReadBig( version );
	if ( version != FONT_INFO_MAGIC ) {
		idLib::Warning( "Wrong version in %s", GetName() );
		delete fd;
		return false;
	}

	fontInfo = new fontInfo_t;

	short pointSize = 0;

	fd->ReadBig( pointSize );
	assert( pointSize == 48 );

	fd->ReadBig( fontInfo->ascender );
	fd->ReadBig( fontInfo->descender );

	fd->ReadBig( fontInfo->numGlyphs );

	fontInfo->glyphData = (glyphInfo_t *)Mem_Alloc( sizeof( glyphInfo_t ) * fontInfo->numGlyphs );
	fontInfo->charIndex = (uint32 *)Mem_Alloc( sizeof( uint32 ) * fontInfo->numGlyphs );

	fd->Read( fontInfo->glyphData, fontInfo->numGlyphs * sizeof( glyphInfo_t ) );

	for( int i = 0; i < fontInfo->numGlyphs; i++ ) {
		idSwap::Little( fontInfo->glyphData[i].width );
		idSwap::Little( fontInfo->glyphData[i].height );
		idSwap::Little( fontInfo->glyphData[i].top );
		idSwap::Little( fontInfo->glyphData[i].left );
		idSwap::Little( fontInfo->glyphData[i].xSkip );
		idSwap::Little( fontInfo->glyphData[i].s );
		idSwap::Little( fontInfo->glyphData[i].t );
	}

	fd->Read( fontInfo->charIndex, fontInfo->numGlyphs * sizeof( uint32 ) );
	idSwap::LittleArray( fontInfo->charIndex, fontInfo->numGlyphs );

	memset( fontInfo->ascii, -1, sizeof( fontInfo->ascii ) );
	for ( int i = 0; i < fontInfo->numGlyphs; i++ ) {
		if ( fontInfo->charIndex[i] < 128 ) {
			fontInfo->ascii[fontInfo->charIndex[i]] = i;
		} else {
			// Since the characters are sorted, as soon as we find a non-ascii character, we can stop
			break;
		}
	}

	idStr fontTextureName = fontName;
	fontTextureName.SetFileExtension( "tga" );

	fontInfo->material = declManager->FindMaterial( fontTextureName );
	fontInfo->material->SetSort( SS_GUI );

	// Load the old glyph data because we want our new fonts to fit in the old glyph metrics
	int pointSizes[3] = { 12, 24, 48 };
	float scales[3] = { 4.0f, 2.0f, 1.0f };
	for ( int i = 0; i < 3; i++ ) {
		oldGlyphInfo_t oldGlyphInfo[GLYPHS_PER_FONT];
		const char * oldFileName = va( "newfonts/%s/old_%d.dat", GetName(), pointSizes[i] );
		if ( LoadOldGlyphData( oldFileName, oldGlyphInfo ) ) {
			int mh = 0;
			int mw = 0;
			for ( int g = 0; g < GLYPHS_PER_FONT; g++ ) {
				if ( mh < oldGlyphInfo[g].height ) {
					mh = oldGlyphInfo[g].height;
				}
				if ( mw < oldGlyphInfo[g].xSkip ) {
					mw = oldGlyphInfo[g].xSkip;
				}
			}
			fontInfo->oldInfo[i].maxWidth = scales[i] * mw;
			fontInfo->oldInfo[i].maxHeight = scales[i] * mh;
		} else {
			int mh = 0;
			int mw = 0;
			for( int g = 0; g < fontInfo->numGlyphs; g++ ) {
				if ( mh < fontInfo->glyphData[g].height ) {
					mh = fontInfo->glyphData[g].height;
				}
				if ( mw < fontInfo->glyphData[g].xSkip ) {
					mw = fontInfo->glyphData[g].xSkip;
				}
			}
			fontInfo->oldInfo[i].maxWidth = mw;
			fontInfo->oldInfo[i].maxHeight = mh;
		}
	}
	delete fd;
	return true;
}

/*
==============================
idFont::GetGlyphIndex
==============================
*/
int	idFont::GetGlyphIndex( uint32 idx ) const {
	if ( idx < 128 ) {
		return fontInfo->ascii[idx];
	}
	if ( fontInfo->numGlyphs == 0 ) {
		return -1;
	}
	if ( fontInfo->charIndex == NULL ) {
		return idx;
	}
	int len = fontInfo->numGlyphs;
	int mid = fontInfo->numGlyphs;
	int offset = 0;
	while ( mid > 0 ) {
		mid = len >> 1;
		if ( fontInfo->charIndex[offset+mid] <= idx ) {
			offset += mid;
		}
		len -= mid;
	}
	return ( fontInfo->charIndex[offset] == idx ) ? offset : -1;
}

/*
==============================
idFont::GetLineHeight
==============================
*/
float idFont::GetLineHeight( float scale ) const {
	if ( alias != NULL ) {
		return alias->GetLineHeight( scale );
	}
	if ( fontInfo != NULL ) {
		return GetConvertedFontScale( scale ) * Old_SelectValueForScale( scale, fontInfo->oldInfo[0].maxHeight, fontInfo->oldInfo[1].maxHeight, fontInfo->oldInfo[2].maxHeight );
	}
	return 0.0f;
}

/*
==============================
idFont::GetAscender
==============================
*/
float idFont::GetAscender( float scale ) const {
	if ( alias != NULL ) {
		return alias->GetAscender( scale );
	}
	if ( fontInfo != NULL ) {
		return GetConvertedFontScale( scale ) * fontInfo->ascender;
	}
	return 0.0f;
}

/*
==============================
idFont::GetMaxCharWidth
==============================
*/
float idFont::GetMaxCharWidth( float scale ) const {
	if ( alias != NULL ) {
		return alias->GetMaxCharWidth( scale );
	}
	if ( fontInfo != NULL ) {
		return GetConvertedFontScale( scale ) * Old_SelectValueForScale( scale, fontInfo->oldInfo[0].maxWidth, fontInfo->oldInfo[1].maxWidth, fontInfo->oldInfo[2].maxWidth );
	}
	return 0.0f;
}

/*
==============================
idFont::GetGlyphWidth
==============================
*/
float idFont::GetGlyphWidth( float scale, uint32 idx ) const {
	if ( alias != NULL ) {
		return alias->GetGlyphWidth( scale, idx );
	}
	if ( fontInfo != NULL ) {
		int i = GetGlyphIndex( idx );
		const int asterisk = 42;
		if ( i == -1 && idx != asterisk ) {
			i = GetGlyphIndex( asterisk );
		}
		if ( i >= 0 ) {
			return GetConvertedFontScale( scale ) * fontInfo->glyphData[i].xSkip;
		}
	}
	return 0.0f;
}

/*
==============================
idFont::GetScaledGlyph
==============================
*/
void idFont::GetScaledGlyph( float scale, uint32 idx, scaledGlyphInfo_t & glyphInfo ) const {
	if ( alias != NULL ) {
		return alias->GetScaledGlyph( scale, idx, glyphInfo );
	}
	if ( fontInfo != NULL ) {
		int i = GetGlyphIndex( idx );
		const int asterisk = 42;
		if ( i == -1 && idx != asterisk ) {
			i = GetGlyphIndex( asterisk );
		}
		if ( i >= 0 ) {
			scale = GetConvertedFontScale( scale );
			float invMaterialWidth = 1.0f / fontInfo->material->GetImageWidth();
			float invMaterialHeight = 1.0f / fontInfo->material->GetImageHeight();
			glyphInfo_t & gi = fontInfo->glyphData[i];
			glyphInfo.xSkip = scale * gi.xSkip;
			glyphInfo.top = scale * gi.top;
			glyphInfo.left = scale * gi.left;
			glyphInfo.width = scale * gi.width;
			glyphInfo.height = scale * gi.height;
			glyphInfo.s1 = ( gi.s - 0.5f ) * invMaterialWidth;
			glyphInfo.t1 = ( gi.t - 0.5f ) * invMaterialHeight;
			glyphInfo.s2 = ( gi.s + gi.width + 0.5f ) * invMaterialWidth;
			glyphInfo.t2 = ( gi.t + gi.height + 0.5f ) * invMaterialHeight;
			glyphInfo.material = fontInfo->material;
			return;
		}
	}
	memset( &glyphInfo, 0, sizeof( glyphInfo ) );
}

/*
==============================
idFont::Touch
==============================
*/
void idFont::Touch() {
	if ( alias != NULL ) {
		alias->Touch();
	}
	if ( fontInfo != NULL ) {
		const_cast<idMaterial *>( fontInfo->material )->EnsureNotPurged();
		fontInfo->material->SetSort( SS_GUI );
	}
}
