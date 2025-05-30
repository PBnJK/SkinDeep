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

#ifndef __MATH_SIMD_SSE3_H__
#define __MATH_SIMD_SSE3_H__

#if !defined(__BLENDO_SIMD_INLINE__)
#include "idlib/math/Simd_SSE2.h"

/*
===============================================================================

	SSE3 implementation of idSIMDProcessor

===============================================================================
*/

class idSIMD_SSE3 : public idSIMD_SSE2 {
public:

#if defined(__BLENDO_SIMD__) // blendo eric: SIMD using newer header/api
	virtual const char * VPCALL GetName(void) const;
#elif defined(__GNUC__) && defined(__SSE3__)
	virtual const char * VPCALL GetName( void ) const;

#elif defined(_MSC_VER) && defined(_M_IX86)
	virtual const char * VPCALL GetName( void ) const;

	virtual void VPCALL TransformVerts( idDrawVert *verts, const int numVerts, const idJointMat *joints, const idVec4 *weights, const int *index, const int numWeights );

#endif
};
#endif

#endif /* !__MATH_SIMD_SSE3_H__ */
