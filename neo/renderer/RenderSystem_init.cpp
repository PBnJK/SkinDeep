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
#include "idlib/LangDict.h"
#include "framework/Licensee.h"
#include "framework/Console.h"
#include "framework/Session.h"
#include "renderer/VertexCache.h"
#include "renderer/ModelManager.h"
#include "renderer/RenderWorld_local.h"
#include "renderer/GuiModel.h"
#include "sound/sound.h"
#include "ui/UserInterface.h"

#include "renderer/tr_local.h"

// Vista OpenGL wrapper check
#ifdef _WIN32
#include "sys/win32/win_local.h"
#endif
#include "SDL2/SDL.h"

// blendo eric: png support
#define BLENDO_PNG_SCREENSHOT
#ifdef BLENDO_PNG_SCREENSHOT
#define STBI_WRITE_NO_STDIO
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#endif

// functions that are not called every frame

glconfig_t	glConfig;

const char *r_rendererArgs[] = { "best", "glsl", NULL };

idCVar r_inhibitFragmentProgram( "r_inhibitFragmentProgram", "0", CVAR_RENDERER | CVAR_BOOL, "ignore the fragment program extension" );
idCVar r_useLightPortalFlow( "r_useLightPortalFlow", "1", CVAR_RENDERER | CVAR_BOOL, "use a more precise area reference determination" );
idCVar r_multiSamples( "r_multiSamples", "8", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "number of antialiasing samples. 0 = off. Options: 2,4,8", 0, 8 );//BC anti-aliasing
idCVar r_mode( "r_mode", "0", CVAR_ARCHIVE | CVAR_RENDERER | CVAR_INTEGER, "(DEPRECATED) video mode number. [use r_resolution instead]" ); //Refer to r_vidModes[] for the resolution list.
idCVar r_displayRefresh( "r_displayRefresh", "0", CVAR_RENDERER | CVAR_INTEGER | CVAR_NOCHEAT, "optional display refresh rate option for vid mode", 0.0f, 200.0f );
idCVar r_fullscreen("r_fullscreen", "0", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "0 = windowed, 1 = full screen, 2 = borderless");
idCVar r_customWidth( "r_customWidth", "1440", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "(DEPRECATED) custom screen width. set r_mode to -1 to activate [use r_resolution instead]" );
idCVar r_customHeight( "r_customHeight", "800", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "(DEPRECATED) custom screen height. set r_mode to -1 to activate [use r_resolution instead]" );
// SM: Instead of using r_mode, r_customWidth, and r_customHeight, use these different resolution cvar now
idCVar r_resolution("r_resolution", "", CVAR_RENDERER | CVAR_ARCHIVE, "Game resolution. Usage: r_resolution WIDTHxHEIGHT\nExample: r_resolution 1600x900\nTo apply changes: quit and restart game.");
idCVar r_singleTriangle( "r_singleTriangle", "0", CVAR_RENDERER | CVAR_BOOL, "only draw a single triangle per primitive" );
idCVar r_checkBounds( "r_checkBounds", "0", CVAR_RENDERER | CVAR_BOOL, "compare all surface bounds with precalculated ones" );

idCVar r_useConstantMaterials( "r_useConstantMaterials", "1", CVAR_RENDERER | CVAR_BOOL, "use pre-calculated material registers if possible" );
idCVar r_useSilRemap( "r_useSilRemap", "1", CVAR_RENDERER | CVAR_BOOL, "consider verts with the same XYZ, but different ST the same for shadows" );
idCVar r_useNodeCommonChildren( "r_useNodeCommonChildren", "1", CVAR_RENDERER | CVAR_BOOL, "stop pushing reference bounds early when possible" );
idCVar r_useShadowProjectedCull( "r_useShadowProjectedCull", "1", CVAR_RENDERER | CVAR_BOOL, "discard triangles outside light volume before shadowing" );
idCVar r_useShadowVertexProgram( "r_useShadowVertexProgram", "1", CVAR_RENDERER | CVAR_BOOL, "do the shadow projection in the vertex program on capable cards" );
idCVar r_useShadowSurfaceScissor( "r_useShadowSurfaceScissor", "1", CVAR_RENDERER | CVAR_BOOL, "scissor shadows by the scissor rect of the interaction surfaces" );
idCVar r_useInteractionTable( "r_useInteractionTable", "1", CVAR_RENDERER | CVAR_BOOL, "create a full entityDefs * lightDefs table to make finding interactions faster" );
idCVar r_useTurboShadow( "r_useTurboShadow", "1", CVAR_RENDERER | CVAR_BOOL, "use the infinite projection with W technique for dynamic shadows" );
idCVar r_useTwoSidedStencil( "r_useTwoSidedStencil", "1", CVAR_RENDERER | CVAR_BOOL, "do stencil shadows in one pass with different ops on each side" );
idCVar r_useDeferredTangents( "r_useDeferredTangents", "1", CVAR_RENDERER | CVAR_BOOL, "defer tangents calculations after deform" );
idCVar r_useCachedDynamicModels( "r_useCachedDynamicModels", "1", CVAR_RENDERER | CVAR_BOOL, "cache snapshots of dynamic models, disabled in debug" );

idCVar r_useVertexBuffers( "r_useVertexBuffers", "1", CVAR_RENDERER | CVAR_INTEGER, "use ARB_vertex_buffer_object for vertexes", 0, 1, idCmdSystem::ArgCompletion_Integer<0,1>  );
idCVar r_useIndexBuffers( "r_useIndexBuffers", "0", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "use ARB_vertex_buffer_object for indexes", 0, 1, idCmdSystem::ArgCompletion_Integer<0,1>  );

idCVar r_useStateCaching( "r_useStateCaching", "1", CVAR_RENDERER | CVAR_BOOL, "avoid redundant state changes in GL_*() calls" );
idCVar r_useInfiniteFarZ( "r_useInfiniteFarZ", "1", CVAR_RENDERER | CVAR_BOOL, "use the no-far-clip-plane trick" );

idCVar r_znear( "r_znear", "3", CVAR_RENDERER | CVAR_FLOAT, "near Z clip plane distance", 0.001f, 200.0f );

idCVar r_ignoreGLErrors( "r_ignoreGLErrors", "1", CVAR_RENDERER | CVAR_BOOL, "ignore GL errors" );
idCVar r_finish( "r_finish", "0", CVAR_RENDERER | CVAR_BOOL, "force a call to glFinish() every frame" );
idCVar r_swapInterval( "r_swapInterval", "1", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "changes the GL swap interval" );

idCVar r_gamma( "r_gamma", "1", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_FLOAT, "changes gamma tables", 0.5f, 3.0f );
idCVar r_brightness( "r_brightness", "1", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_FLOAT, "changes gamma tables", 0.5f, 2.0f );

idCVar r_renderer( "r_renderer", "best", CVAR_RENDERER | CVAR_ARCHIVE, "Hardware-specific renderer path to use. Values: best, glsl", r_rendererArgs, idCmdSystem::ArgCompletion_String<r_rendererArgs> );

idCVar r_jitter( "r_jitter", "0", CVAR_RENDERER | CVAR_BOOL, "randomly subpixel jitter the projection matrix" );

idCVar r_skipSuppress( "r_skipSuppress", "0", CVAR_RENDERER | CVAR_BOOL, "ignore the per-view suppressions" );
idCVar r_skipPostProcess( "r_skipPostProcess", "0", CVAR_RENDERER | CVAR_BOOL, "skip all post-process renderings" );
idCVar r_skipLightScale( "r_skipLightScale", "0", CVAR_RENDERER | CVAR_BOOL, "don't do any post-interaction light scaling, makes things dim on low-dynamic range cards" );
idCVar r_skipInteractions( "r_skipInteractions", "0", CVAR_RENDERER | CVAR_BOOL, "skip all light/surface interaction drawing" );
idCVar r_skipDynamicTextures( "r_skipDynamicTextures", "0", CVAR_RENDERER | CVAR_BOOL, "don't dynamically create textures" );
idCVar r_skipCopyTexture( "r_skipCopyTexture", "0", CVAR_RENDERER | CVAR_BOOL, "do all rendering, but don't actually copyTexSubImage2D" );
idCVar r_skipBackEnd( "r_skipBackEnd", "0", CVAR_RENDERER | CVAR_BOOL, "don't draw anything" );
idCVar r_skipRender( "r_skipRender", "0", CVAR_RENDERER | CVAR_BOOL, "skip 3D rendering, but pass 2D" );
idCVar r_skipRenderContext( "r_skipRenderContext", "0", CVAR_RENDERER | CVAR_BOOL, "NULL the rendering context during backend 3D rendering" );
idCVar r_skipTranslucent( "r_skipTranslucent", "0", CVAR_RENDERER | CVAR_BOOL, "skip the translucent interaction rendering" );
idCVar r_skipAmbient( "r_skipAmbient", "0", CVAR_RENDERER | CVAR_BOOL, "bypasses all non-interaction drawing" );
idCVar r_skipNewAmbient( "r_skipNewAmbient", "0", CVAR_RENDERER | CVAR_BOOL | CVAR_ARCHIVE, "bypasses all vertex/fragment program ambient drawing" );
idCVar r_skipBlendLights( "r_skipBlendLights", "0", CVAR_RENDERER | CVAR_BOOL, "skip all blend lights" );
idCVar r_skipFogLights( "r_skipFogLights", "0", CVAR_RENDERER | CVAR_BOOL, "skip all fog lights" );
idCVar r_skipDeforms( "r_skipDeforms", "0", CVAR_RENDERER | CVAR_BOOL, "leave all deform materials in their original state" );
idCVar r_skipFrontEnd( "r_skipFrontEnd", "0", CVAR_RENDERER | CVAR_BOOL, "bypasses all front end work, but 2D gui rendering still draws" );
idCVar r_skipUpdates( "r_skipUpdates", "0", CVAR_RENDERER | CVAR_BOOL, "1 = don't accept any entity or light updates, making everything static" );
idCVar r_skipOverlays( "r_skipOverlays", "0", CVAR_RENDERER | CVAR_BOOL, "skip overlay surfaces" );
idCVar r_skipSpecular( "r_skipSpecular", "0", CVAR_RENDERER | CVAR_BOOL | CVAR_CHEAT | CVAR_ARCHIVE, "use black for specular1" );
idCVar r_skipBump( "r_skipBump", "0", CVAR_RENDERER | CVAR_BOOL | CVAR_ARCHIVE, "uses a flat surface instead of the bump map" );
idCVar r_skipDiffuse( "r_skipDiffuse", "0", CVAR_RENDERER | CVAR_BOOL, "use black for diffuse" );
idCVar r_skipROQ( "r_skipROQ", "0", CVAR_RENDERER | CVAR_BOOL, "skip ROQ decoding" );

idCVar r_ignore( "r_ignore", "0", CVAR_RENDERER, "used for random debugging without defining new vars" );
idCVar r_ignore2( "r_ignore2", "0", CVAR_RENDERER, "used for random debugging without defining new vars" );
idCVar r_usePreciseTriangleInteractions( "r_usePreciseTriangleInteractions", "0", CVAR_RENDERER | CVAR_BOOL, "1 = do winding clipping to determine if each ambiguous tri should be lit" );
idCVar r_useCulling( "r_useCulling", "1", CVAR_RENDERER | CVAR_INTEGER, "0 = none, 1 = sphere, 2 = sphere + box", 0, 2, idCmdSystem::ArgCompletion_Integer<0,2> ); // blendo eric todo note: change to 1 for testing
idCVar r_useLightCulling( "r_useLightCulling", "3", CVAR_RENDERER | CVAR_INTEGER, "0 = none, 1 = box, 2 = exact clip of polyhedron faces, 3 = also areas", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_useLightScissors( "r_useLightScissors", "1", CVAR_RENDERER | CVAR_BOOL, "1 = use custom scissor rectangle for each light" );
idCVar r_useClippedLightScissors( "r_useClippedLightScissors", "1", CVAR_RENDERER | CVAR_INTEGER, "0 = full screen when near clipped, 1 = exact when near clipped, 2 = exact always", 0, 2, idCmdSystem::ArgCompletion_Integer<0,2> );
idCVar r_useEntityCulling( "r_useEntityCulling", "1", CVAR_RENDERER | CVAR_BOOL, "0 = none, 1 = box" );
idCVar r_useEntityScissors( "r_useEntityScissors", "0", CVAR_RENDERER | CVAR_BOOL, "1 = use custom scissor rectangle for each entity" );
idCVar r_useInteractionCulling( "r_useInteractionCulling", "1", CVAR_RENDERER | CVAR_BOOL, "1 = cull interactions" );
idCVar r_useInteractionScissors( "r_useInteractionScissors", "2", CVAR_RENDERER | CVAR_INTEGER, "1 = use a custom scissor rectangle for each shadow interaction, 2 = also crop using portal scissors", -2, 2, idCmdSystem::ArgCompletion_Integer<-2,2> );
idCVar r_useShadowCulling( "r_useShadowCulling", "1", CVAR_RENDERER | CVAR_BOOL, "try to cull shadows from partially visible lights" );
idCVar r_useFrustumFarDistance( "r_useFrustumFarDistance", "0", CVAR_RENDERER | CVAR_FLOAT, "if != 0 force the view frustum far distance to this distance" );
idCVar r_clear( "r_clear", "2", CVAR_RENDERER | CVAR_ARCHIVE, "force screen clear every frame, 1 = purple, 2 = black, 'r g b' = custom" );
idCVar r_offsetFactor( "r_offsetfactor", "0", CVAR_RENDERER | CVAR_FLOAT, "polygon offset parameter" );
idCVar r_offsetUnits( "r_offsetunits", "-600", CVAR_RENDERER | CVAR_FLOAT, "polygon offset parameter" );
idCVar r_shadowPolygonOffset( "r_shadowPolygonOffset", "-1", CVAR_RENDERER | CVAR_FLOAT, "bias value added to depth test for stencil shadow drawing" );
idCVar r_shadowPolygonFactor( "r_shadowPolygonFactor", "0", CVAR_RENDERER | CVAR_FLOAT, "scale value for stencil shadow drawing" );
idCVar r_skipSubviews( "r_skipSubviews", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = don't render any gui elements on surfaces" );
idCVar r_skipGuiShaders( "r_skipGuiShaders", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = skip all gui elements on surfaces, 2 = skip drawing but still handle events, 3 = draw but skip events", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_skipParticles( "r_skipParticles", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = skip all particle systems", 0, 1, idCmdSystem::ArgCompletion_Integer<0,1> );
idCVar r_subviewOnly( "r_subviewOnly", "0", CVAR_RENDERER | CVAR_BOOL, "1 = don't render main view, allowing subviews to be debugged" );
idCVar r_shadows( "r_shadows", "1", CVAR_RENDERER | CVAR_BOOL  | CVAR_ARCHIVE, "enable shadows" );
idCVar r_testARBProgram( "r_testARBProgram", "0", CVAR_RENDERER | CVAR_BOOL, "experiment with vertex/fragment programs" );
idCVar r_testGamma( "r_testGamma", "0", CVAR_RENDERER | CVAR_FLOAT, "if > 0 draw a grid pattern to test gamma levels", 0, 195 );
idCVar r_testGammaBias( "r_testGammaBias", "0", CVAR_RENDERER | CVAR_FLOAT, "if > 0 draw a grid pattern to test gamma levels" );
idCVar r_testStepGamma( "r_testStepGamma", "0", CVAR_RENDERER | CVAR_FLOAT, "if > 0 draw a grid pattern to test gamma levels" );
idCVar r_lightScale( "r_lightScale", "2", CVAR_RENDERER | CVAR_FLOAT, "all light intensities are multiplied by this" );
idCVar r_lightSourceRadius( "r_lightSourceRadius", "0", CVAR_RENDERER | CVAR_FLOAT, "for soft-shadow sampling" );
idCVar r_flareSize( "r_flareSize", "1", CVAR_RENDERER | CVAR_FLOAT, "scale the flare deforms from the material def" );

idCVar r_useExternalShadows( "r_useExternalShadows", "1", CVAR_RENDERER | CVAR_INTEGER, "1 = skip drawing caps when outside the light volume, 2 = force to no caps for testing", 0, 2, idCmdSystem::ArgCompletion_Integer<0,2> );
idCVar r_useOptimizedShadows( "r_useOptimizedShadows", "1", CVAR_RENDERER | CVAR_BOOL, "use the dmap generated static shadow volumes" );
idCVar r_useScissor( "r_useScissor", "1", CVAR_RENDERER | CVAR_BOOL, "scissor clip as portals and lights are processed" );
idCVar r_useCombinerDisplayLists( "r_useCombinerDisplayLists", "1", CVAR_RENDERER | CVAR_BOOL | CVAR_NOCHEAT, "put all nvidia register combiner programming in display lists" );
idCVar r_useDepthBoundsTest( "r_useDepthBoundsTest", "1", CVAR_RENDERER | CVAR_BOOL, "use depth bounds test to reduce shadow fill" );

idCVar r_screenFraction( "r_screenFraction", "100", CVAR_RENDERER | CVAR_INTEGER, "for testing fill rate, the resolution of the entire screen can be changed" );
idCVar r_demonstrateBug( "r_demonstrateBug", "0", CVAR_RENDERER | CVAR_BOOL, "used during development to show IHV's their problems" );
idCVar r_usePortals( "r_usePortals", "1", CVAR_RENDERER | CVAR_BOOL, " 1 = use portals to perform area culling, otherwise draw everything" );
idCVar r_singleLight( "r_singleLight", "-1", CVAR_RENDERER | CVAR_INTEGER, "suppress all but one light" );
idCVar r_singleEntity( "r_singleEntity", "-1", CVAR_RENDERER | CVAR_INTEGER, "suppress all but one entity" );
idCVar r_singleSurface( "r_singleSurface", "-1", CVAR_RENDERER | CVAR_INTEGER, "suppress all but one surface on each entity" );
idCVar r_singleArea( "r_singleArea", "0", CVAR_RENDERER | CVAR_BOOL, "only draw the portal area the view is actually in" );
idCVar r_forceLoadImages( "r_forceLoadImages", "0", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_BOOL, "draw all images to screen after registration" );
idCVar r_orderIndexes( "r_orderIndexes", "1", CVAR_RENDERER | CVAR_BOOL, "perform index reorganization to optimize vertex use" );
idCVar r_lightAllBackFaces( "r_lightAllBackFaces", "0", CVAR_RENDERER | CVAR_BOOL, "light all the back faces, even when they would be shadowed" );

// visual debugging info
idCVar r_showPortals( "r_showPortals", "0", CVAR_RENDERER | CVAR_BOOL, "draw portal outlines in color based on passed / not passed" );
idCVar r_showUnsmoothedTangents( "r_showUnsmoothedTangents", "0", CVAR_RENDERER | CVAR_BOOL, "if 1, put all nvidia register combiner programming in display lists" );
idCVar r_showSilhouette( "r_showSilhouette", "0", CVAR_RENDERER | CVAR_BOOL, "highlight edges that are casting shadow planes" );
idCVar r_showVertexColor( "r_showVertexColor", "0", CVAR_RENDERER | CVAR_BOOL, "draws all triangles with the solid vertex color" );
idCVar r_showUpdates( "r_showUpdates", "0", CVAR_RENDERER | CVAR_BOOL, "report entity and light updates and ref counts" );
idCVar r_showDemo( "r_showDemo", "0", CVAR_RENDERER | CVAR_BOOL, "report reads and writes to the demo file" );
idCVar r_showDynamic( "r_showDynamic", "0", CVAR_RENDERER | CVAR_BOOL, "report stats on dynamic surface generation" );
idCVar r_showLightScale( "r_showLightScale", "0", CVAR_RENDERER | CVAR_BOOL, "report the scale factor applied to drawing for overbrights" );
idCVar r_showDefs( "r_showDefs", "0", CVAR_RENDERER | CVAR_BOOL, "report the number of modeDefs and lightDefs in view" );
idCVar r_showTrace( "r_showTrace", "0", CVAR_RENDERER | CVAR_INTEGER, "show the intersection of an eye trace with the world", idCmdSystem::ArgCompletion_Integer<0,2> );
idCVar r_showIntensity( "r_showIntensity", "0", CVAR_RENDERER | CVAR_BOOL, "draw the screen colors based on intensity, red = 0, green = 128, blue = 255" );
idCVar r_showImages( "r_showImages", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = show all images instead of rendering, 2 = show in proportional size", 0, 2, idCmdSystem::ArgCompletion_Integer<0,2> );
idCVar r_showSmp( "r_showSmp", "0", CVAR_RENDERER | CVAR_BOOL, "show which end (front or back) is blocking" );
idCVar r_showLights( "r_showLights", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = just print volumes numbers, highlighting ones covering the view, 2 = also draw planes of each volume, 3 = also draw edges of each volume", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_showShadows( "r_showShadows", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = visualize the stencil shadow volumes, 2 = draw filled in", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_showShadowCount( "r_showShadowCount", "0", CVAR_RENDERER | CVAR_INTEGER, "colors screen based on shadow volume depth complexity.\n>= 2 = print overdraw count based on stencil index values\n3 = only show turboshadows\n4 = only show static shadows", 0, 4, idCmdSystem::ArgCompletion_Integer<0,4> );
idCVar r_showLightScissors( "r_showLightScissors", "0", CVAR_RENDERER | CVAR_BOOL, "show light scissor rectangles" );
idCVar r_showEntityScissors( "r_showEntityScissors", "0", CVAR_RENDERER | CVAR_BOOL, "show entity scissor rectangles" );
idCVar r_showInteractionFrustums( "r_showInteractionFrustums", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = show a frustum for each interaction, 2 = also draw lines to light origin, 3 = also draw entity bbox", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_showInteractionScissors( "r_showInteractionScissors", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = show screen rectangle which contains the interaction frustum, 2 = also draw construction lines", 0, 2, idCmdSystem::ArgCompletion_Integer<0,2> );
idCVar r_showLightCount( "r_showLightCount", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = colors surfaces based on light count, 2 = also count everything through walls, 3 = also print overdraw\n\nGreen = 1 light\nYellow-green = 2\nYellow = 3\nOrange = 4\nRed = 5\nPink = 6\nWhite = 7+", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_showViewEntitys( "r_showViewEntitys", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = displays the bounding boxes of all view models, 2 = print index numbers" );
idCVar r_showTris( "r_showTris", "0", CVAR_RENDERER | CVAR_INTEGER, "enables wireframe rendering of the world, 1 = only draw visible ones, 2 = draw all front facing, 3 = draw all", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_showSurfaceInfo( "r_showSurfaceInfo", "0", CVAR_RENDERER | CVAR_BOOL, "show surface material name under crosshair" );
idCVar r_showNormals( "r_showNormals", "0", CVAR_RENDERER | CVAR_FLOAT, "draws wireframe normals" );
idCVar r_showMemory( "r_showMemory", "0", CVAR_RENDERER | CVAR_BOOL, "print frame memory utilization" );
idCVar r_showCull( "r_showCull", "0", CVAR_RENDERER | CVAR_BOOL, "report sphere and box culling stats" );
idCVar r_showInteractions( "r_showInteractions", "0", CVAR_RENDERER | CVAR_BOOL, "report interaction generation activity" );
idCVar r_showDepth( "r_showDepth", "0", CVAR_RENDERER | CVAR_BOOL, "display the contents of the depth buffer and the depth range" );
idCVar r_showSurfaces( "r_showSurfaces", "0", CVAR_RENDERER | CVAR_BOOL, "report surface/light/shadow counts" );
idCVar r_showPrimitives( "r_showPrimitives", "0", CVAR_RENDERER | CVAR_INTEGER, "report drawsurf/index/vertex counts.\n0 = off\n1 = basics\n2 = detailed\n3 = default" );
idCVar r_showEdges( "r_showEdges", "0", CVAR_RENDERER | CVAR_BOOL, "draw the sil edges" );
idCVar r_showTexturePolarity( "r_showTexturePolarity", "0", CVAR_RENDERER | CVAR_BOOL, "shade triangles by texture area polarity" );
idCVar r_showTangentSpace( "r_showTangentSpace", "0", CVAR_RENDERER | CVAR_INTEGER, "shade triangles by tangent space, 1 = use 1st tangent vector, 2 = use 2nd tangent vector, 3 = use normal vector", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );
idCVar r_showDominantTri( "r_showDominantTri", "0", CVAR_RENDERER | CVAR_BOOL, "draw lines from vertexes to center of dominant triangles" );
idCVar r_showAlloc( "r_showAlloc", "0", CVAR_RENDERER | CVAR_BOOL, "report alloc/free counts" );
idCVar r_showTextureVectors( "r_showTextureVectors", "0", CVAR_RENDERER | CVAR_FLOAT, " if > 0 draw each triangles texture (tangent) vectors" );
idCVar r_showOverDraw( "r_showOverDraw", "0", CVAR_RENDERER | CVAR_INTEGER, "1 = geometry overdraw, 2 = light interaction overdraw, 3 = geometry and light interaction overdraw", 0, 3, idCmdSystem::ArgCompletion_Integer<0,3> );

idCVar r_lockSurfaces( "r_lockSurfaces", "0", CVAR_RENDERER | CVAR_BOOL, "allow moving the view point without changing the composition of the scene, including culling" );
idCVar r_useEntityCallbacks( "r_useEntityCallbacks", "1", CVAR_RENDERER | CVAR_BOOL, "if 0, issue the callback immediately at update time, rather than defering" );

idCVar r_showSkel( "r_showSkel", "0", CVAR_RENDERER | CVAR_INTEGER, "draw the skeleton when model animates, 1 = draw model with skeleton, 2 = draw skeleton only, 3 = origin/body only, 4 = transform data", 0, 4, idCmdSystem::ArgCompletion_Integer<0,4> );
idCVar r_jointNameScale( "r_jointNameScale", "0.05", CVAR_RENDERER | CVAR_FLOAT, "size of joint names when r_showskel is set to 1" );
idCVar r_jointNameOffset( "r_jointNameOffset", "0.05", CVAR_RENDERER | CVAR_FLOAT, "offset of joint names when r_showskel is set to 1" );

idCVar r_debugLineDepthTest( "r_debugLineDepthTest", "0", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_BOOL, "perform depth test on debug lines" );
idCVar r_debugLineWidth( "r_debugLineWidth", "1", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_BOOL, "width of debug lines" );
idCVar r_debugArrowStep( "r_debugArrowStep", "120", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_INTEGER, "step size of arrow cone line rotation in degrees", 0, 120 );
idCVar r_debugPolygonFilled( "r_debugPolygonFilled", "1", CVAR_RENDERER | CVAR_BOOL, "draw a filled polygon" );

idCVar r_materialOverride( "r_materialOverride", "", CVAR_RENDERER, "overrides all materials", idCmdSystem::ArgCompletion_Decl<DECL_MATERIAL> );

idCVar r_debugRenderToTexture( "r_debugRenderToTexture", "0", CVAR_RENDERER | CVAR_INTEGER, "" );

// blendo eric: Custom cvars for new ambience system
idCVar r_useBlendoAmbience("r_useBlendoAmbience", "1", CVAR_RENDERER | CVAR_INTEGER, "render a dim additive pass for all diffuse shaders, making dark areas more readable. 0 = off, 1 = on", 0, 1);
idCVar r_blendoAmbienceScale("r_blendoAmbienceScale", "0.15", CVAR_RENDERER | CVAR_FLOAT, "multiplier to scale brightness of the additive pass that is applied to diffuse shaders. Ranges from 0.0 to 1.0", 0.0f, 1.0f);

idCVar r_blendoTriangleCount("r_blendoTriangleCount", "-1", CVAR_RENDERER | CVAR_INTEGER, "only draw a x triangle per primitive, -1 off"); // blendo eric: perf testing
idCVar r_stencilReverse("r_stencilReverse", "1", CVAR_RENDERER | CVAR_BOOL, "use carmack's reverse"); // blendo eric: re-add carmack's reverse
idCVar r_useStencilOpSeparate( "r_useStencilOpSeparate", "1", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_BOOL, "Use glStencilOpSeparate() (if available) when rendering shadows" );

// DG: let users disable the "scale menus to 4:3" hack
idCVar r_scaleMenusTo169( "r_scaleMenusTo169", "1", CVAR_RENDERER | CVAR_ARCHIVE | CVAR_BOOL, "Scale menus, fullscreen videos and PDA to 16:9 aspect ratio even when widescreen" );
idCVar r_AMDWorkaround( "r_AMDWorkaround", "0", CVAR_RENDERER | CVAR_BOOL | CVAR_INIT, "Whether to force enable to AMD workaround" );

// define qgl functions
#define QGLPROC(name, rettype, args) rettype (APIENTRYP q##name) args;
#include "renderer/qgl_proc.h"

void ( APIENTRY * qglMultiTexCoord2fARB )( GLenum texture, GLfloat s, GLfloat t );
void ( APIENTRY * qglMultiTexCoord2fvARB )( GLenum texture, GLfloat *st );
void ( APIENTRY * qglActiveTextureARB )( GLenum texture );
void ( APIENTRY * qglClientActiveTextureARB )( GLenum texture );

void (APIENTRY *qglTexImage3D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);

void (APIENTRY * qglColorTableEXT)( int, int, int, int, int, const void * );

// EXT_stencil_two_side
PFNGLACTIVESTENCILFACEEXTPROC			qglActiveStencilFaceEXT;

// DG: couldn't find any extension for this, it's supported in GL2.0 and newer, incl OpenGL ES2.0
PFNGLSTENCILOPSEPARATEPROC qglStencilOpSeparate;

// ARB_texture_compression
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC		qglCompressedTexImage2DARB;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC		qglGetCompressedTexImageARB;

// SM: Swap out ARB_vertex_buffer_object for GL_EXT_PROTOTYPES aka Core 2.0+ version
// and only the functions we're actively using
// ARB_vertex_buffer_object
// PFNGLBINDBUFFERARBPROC					qglBindBufferARB;
// PFNGLDELETEBUFFERSARBPROC				qglDeleteBuffersARB;
// PFNGLGENBUFFERSARBPROC					qglGenBuffersARB;
// PFNGLISBUFFERARBPROC					qglIsBufferARB;
// PFNGLBUFFERDATAARBPROC					qglBufferDataARB;
// PFNGLBUFFERSUBDATAARBPROC				qglBufferSubDataARB;
// PFNGLGETBUFFERSUBDATAARBPROC			qglGetBufferSubDataARB;
// PFNGLMAPBUFFERARBPROC					qglMapBufferARB;
// PFNGLUNMAPBUFFERARBPROC					qglUnmapBufferARB;
// PFNGLGETBUFFERPARAMETERIVARBPROC		qglGetBufferParameterivARB;
// PFNGLGETBUFFERPOINTERVARBPROC			qglGetBufferPointervARB;
PFNGLBINDBUFFERPROC						qglBindBuffer;
PFNGLGENBUFFERSPROC						qglGenBuffers;
PFNGLBUFFERDATAPROC						qglBufferData;
PFNGLBUFFERSUBDATAPROC					qglBufferSubData;

// ARB_vertex_program / ARB_fragment_program
PFNGLVERTEXATTRIBPOINTERARBPROC			qglVertexAttribPointerARB;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC		qglEnableVertexAttribArrayARB;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC	qglDisableVertexAttribArrayARB;
PFNGLPROGRAMSTRINGARBPROC				qglProgramStringARB;
PFNGLBINDPROGRAMARBPROC					qglBindProgramARB;
PFNGLGENPROGRAMSARBPROC					qglGenProgramsARB;
PFNGLPROGRAMENVPARAMETER4FVARBPROC		qglProgramEnvParameter4fvARB;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC	qglProgramLocalParameter4fvARB;
PFNGLGETPROGRAMIVARBPROC				qglGetProgramivARB;

// GL_EXT_depth_bounds_test
PFNGLDEPTHBOUNDSEXTPROC                 qglDepthBoundsEXT;

// SM: Debug extensions to help with frame captures
PFNGLOBJECTLABELPROC					qglObjectLabel;
PFNGLPUSHDEBUGGROUPPROC					qglPushDebugGroup;
PFNGLPOPDEBUGGROUPPROC					qglPopDebugGroup;
// GL_ARB_debug_output
PFNGLDEBUGMESSAGECALLBACKARBPROC        qglDebugMessageCallback;

// blendo eric: frame/render buffers
PFNGLGENFRAMEBUFFERSPROC				qglGenFramebuffers;
PFNGLDELETEFRAMEBUFFERSPROC				qglDeleteFramebuffers;
PFNGLBINDFRAMEBUFFERPROC				qglBindFramebuffer;
PFNGLFRAMEBUFFERTEXTURE2DPROC			qglFramebufferTexture2D;
PFNGLCHECKFRAMEBUFFERSTATUSPROC			qglCheckFramebufferStatus;
PFNGLBLITFRAMEBUFFERPROC				qglBlitFramebuffer;
PFNGLDRAWBUFFERSPROC					qglDrawBuffers;
PFNGLCLEARBUFFERUIVPROC					qglClearBufferuiv;
PFNGLCLEARBUFFERFVPROC					qglClearBufferfv;

// SM: GLSL functions
PFNGLCREATEPROGRAMPROC					qglCreateProgram;
PFNGLATTACHSHADERPROC					qglAttachShader;
PFNGLLINKPROGRAMPROC					qglLinkProgram;
PFNGLDELETEPROGRAMPROC					qglDeleteProgram;
PFNGLDELETESHADERPROC					qglDeleteShader;
PFNGLUSEPROGRAMPROC						qglUseProgram;
PFNGLGETUNIFORMLOCATIONPROC				qglGetUniformLocation;
PFNGLUNIFORMMATRIX4FVPROC				qglUniformMatrix4fv;
PFNGLUNIFORM4FVPROC						qglUniform4fv;
PFNGLUNIFORM3FVPROC						qglUniform3fv;
PFNGLUNIFORM2FVPROC						qglUniform2fv;
PFNGLUNIFORM1FPROC						qglUniform1f;
PFNGLUNIFORM1IPROC						qglUniform1i;
PFNGLUNIFORM1UIPROC						qglUniform1ui;
PFNGLCREATESHADERPROC					qglCreateShader;
PFNGLSHADERSOURCEPROC					qglShaderSource;
PFNGLCOMPILESHADERPROC					qglCompileShader;
PFNGLGETSHADERIVPROC					qglGetShaderiv;
PFNGLGETSHADERINFOLOGPROC				qglGetShaderInfoLog;
PFNGLGETPROGRAMIVPROC					qglGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC				qglGetProgramInfoLog;
PFNGLGETUNIFORMBLOCKINDEXPROC			qglGetUniformBlockIndex;
PFNGLUNIFORMBLOCKBINDINGPROC			qglUniformBlockBinding;
PFNGLBINDBUFFERRANGEPROC				qglBindBufferRange;
PFNGLENABLEVERTEXATTRIBARRAYPROC		qglEnableVertexAttribArray;
PFNGLDISABLEVERTEXATTRIBARRAYPROC		qglDisableVertexAttribArray;
PFNGLVERTEXATTRIBPOINTERPROC			qglVertexAttribPointer;
PFNGLACTIVETEXTUREPROC					qglActiveTexture;
PFNGLBINDBUFFERBASEPROC					qglBindBufferBase;


enum {
	// Not all GL.h header know about GL_DEBUG_SEVERITY_NOTIFICATION_*.
	QGL_DEBUG_SEVERITY_NOTIFICATION = 0x826B
};

/*
 * Callback function for debug output.
 */
static void APIENTRY
DebugCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
              const GLchar *message, const void *userParam )
{
	// DG: skindeep added the following lines, but for now show also warnings etc
	//if (type != GL_DEBUG_TYPE_ERROR)
	//	return;
	
	const char* sourceStr = "Source: Unknown";
	const char* typeStr = "Type: Unknown";
	const char* severityStr = "Severity: Unknown";

	switch (severity)
	{
#define SVRCASE(X, STR)  case GL_DEBUG_SEVERITY_ ## X ## _ARB : severityStr = STR; break;
		case QGL_DEBUG_SEVERITY_NOTIFICATION: return;
		SVRCASE(HIGH, "Severity: High")
		SVRCASE(MEDIUM, "Severity: Medium")
		SVRCASE(LOW, "Severity: Low")
#undef SVRCASE
	}

	switch (source)
	{
#define SRCCASE(X)  case GL_DEBUG_SOURCE_ ## X ## _ARB: sourceStr = "Source: " #X; break;
		SRCCASE(API);
		SRCCASE(WINDOW_SYSTEM);
		SRCCASE(SHADER_COMPILER);
		SRCCASE(THIRD_PARTY);
		SRCCASE(APPLICATION);
		SRCCASE(OTHER);
#undef SRCCASE
	}

	switch(type)
	{
#define TYPECASE(X)  case GL_DEBUG_TYPE_ ## X ## _ARB: typeStr = "Type: " #X; break;
		TYPECASE(ERROR);
		TYPECASE(DEPRECATED_BEHAVIOR);
		TYPECASE(UNDEFINED_BEHAVIOR);
		TYPECASE(PORTABILITY);
		TYPECASE(PERFORMANCE);
		TYPECASE(OTHER);
#undef TYPECASE
	}

	common->Warning( "GLDBG %s %s %s: %s\n", sourceStr, typeStr, severityStr, message );

}

/*
=================
R_CheckExtension
=================
*/
bool R_CheckExtension( const char *name ) {
	if ( !strstr( glConfig.extensions_string, name ) ) {
		common->Printf( "X..%s not found\n", name );
		return false;
	}

	common->Printf( "...using %s\n", name );
	return true;
}

/*
==================
R_CheckPortableExtensions

==================
*/
static void R_CheckPortableExtensions( void ) {
	glConfig.glVersion = atof( glConfig.version_string );

	// GL_ARB_multitexture
	glConfig.multitextureAvailable = R_CheckExtension( "GL_ARB_multitexture" );
	if ( glConfig.multitextureAvailable ) {
		qglMultiTexCoord2fARB = (void(APIENTRY *)(GLenum, GLfloat, GLfloat))GLimp_ExtensionPointer( "glMultiTexCoord2fARB" );
		qglMultiTexCoord2fvARB = (void(APIENTRY *)(GLenum, GLfloat *))GLimp_ExtensionPointer( "glMultiTexCoord2fvARB" );
		qglActiveTextureARB = (void(APIENTRY *)(GLenum))GLimp_ExtensionPointer( "glActiveTextureARB" );
		qglClientActiveTextureARB = (void(APIENTRY *)(GLenum))GLimp_ExtensionPointer( "glClientActiveTextureARB" );
		qglGetIntegerv( GL_MAX_TEXTURE_UNITS_ARB, (GLint *)&glConfig.maxTextureUnits );
		if ( glConfig.maxTextureUnits > MAX_MULTITEXTURE_UNITS ) {
			glConfig.maxTextureUnits = MAX_MULTITEXTURE_UNITS;
		}
		if ( glConfig.maxTextureUnits < 2 ) {
			glConfig.multitextureAvailable = false;	// shouldn't ever happen
		}
		qglGetIntegerv( GL_MAX_TEXTURE_COORDS_ARB, (GLint *)&glConfig.maxTextureCoords );
		qglGetIntegerv( GL_MAX_TEXTURE_IMAGE_UNITS_ARB, (GLint *)&glConfig.maxTextureImageUnits );
	}

	// GL_ARB_texture_env_combine
	glConfig.textureEnvCombineAvailable = R_CheckExtension( "GL_ARB_texture_env_combine" );

	// GL_ARB_texture_cube_map
	glConfig.cubeMapAvailable = R_CheckExtension( "GL_ARB_texture_cube_map" );

	// GL_ARB_texture_env_dot3
	glConfig.envDot3Available = R_CheckExtension( "GL_ARB_texture_env_dot3" );

	// GL_ARB_texture_env_add
	glConfig.textureEnvAddAvailable = R_CheckExtension( "GL_ARB_texture_env_add" );

	// GL_ARB_texture_non_power_of_two
	glConfig.textureNonPowerOfTwoAvailable = R_CheckExtension( "GL_ARB_texture_non_power_of_two" );

	// GL_ARB_texture_compression + GL_S3_s3tc
	// DRI drivers may have GL_ARB_texture_compression but no GL_EXT_texture_compression_s3tc
	if ( R_CheckExtension( "GL_ARB_texture_compression" ) && R_CheckExtension( "GL_EXT_texture_compression_s3tc" ) ) {
		glConfig.textureCompressionAvailable = true;
		qglCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)GLimp_ExtensionPointer( "glCompressedTexImage2DARB" );
		qglGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)GLimp_ExtensionPointer( "glGetCompressedTexImageARB" );
	} else {
		glConfig.textureCompressionAvailable = false;
	}

	// GL_EXT_texture_filter_anisotropic
	glConfig.anisotropicAvailable = R_CheckExtension( "GL_EXT_texture_filter_anisotropic" );
	if ( glConfig.anisotropicAvailable ) {
		qglGetFloatv( GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &glConfig.maxTextureAnisotropy );
		common->Printf( "   maxTextureAnisotropy: %f\n", glConfig.maxTextureAnisotropy );
	} else {
		glConfig.maxTextureAnisotropy = 1;
	}

	// GL_EXT_texture_lod_bias
	// The actual extension is broken as specificed, storing the state in the texture unit instead
	// of the texture object.  The behavior in GL 1.4 is the behavior we use.
	if ( glConfig.glVersion >= 1.4 || R_CheckExtension( "GL_EXT_texture_lod" ) ) {
		common->Printf( "...using %s\n", "GL_1.4_texture_lod_bias" );
		glConfig.textureLODBiasAvailable = true;
	} else {
		common->Printf( "X..%s not found\n", "GL_1.4_texture_lod_bias" );
		glConfig.textureLODBiasAvailable = false;
	}

	// GL_EXT_shared_texture_palette
	glConfig.sharedTexturePaletteAvailable = R_CheckExtension( "GL_EXT_shared_texture_palette" );
	if ( glConfig.sharedTexturePaletteAvailable ) {
		qglColorTableEXT = ( void ( APIENTRY * ) ( int, int, int, int, int, const void * ) ) GLimp_ExtensionPointer( "glColorTableEXT" );
	}

	// GL_EXT_texture3D (not currently used for anything)
	glConfig.texture3DAvailable = R_CheckExtension( "GL_EXT_texture3D" );
	if ( glConfig.texture3DAvailable ) {
		qglTexImage3D =
			(void (APIENTRY *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) )
			GLimp_ExtensionPointer( "glTexImage3D" );
	}

	// EXT_stencil_wrap
	// This isn't very important, but some pathological case might cause a clamp error and give a shadow bug.
	// Nvidia also believes that future hardware may be able to run faster with this enabled to avoid the
	// serialization of clamping.
	if ( R_CheckExtension( "GL_EXT_stencil_wrap" ) ) {
		tr.stencilIncr = GL_INCR_WRAP_EXT;
		tr.stencilDecr = GL_DECR_WRAP_EXT;
	} else {
		tr.stencilIncr = GL_INCR;
		tr.stencilDecr = GL_DECR;
	}

	// GL_EXT_stencil_two_side
	glConfig.twoSidedStencilAvailable = R_CheckExtension( "GL_EXT_stencil_two_side" );
	if ( glConfig.twoSidedStencilAvailable )
		qglActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC)GLimp_ExtensionPointer( "glActiveStencilFaceEXT" );

	if( glConfig.glVersion >= 2.0) {
		common->Printf( "... got GL2.0+ glStencilOpSeparate()\n" );
		qglStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)GLimp_ExtensionPointer( "glStencilOpSeparate" );
	} else {
		// TODO: there was an extension by ATI providing glStencilOpSeparateATI - do we care?
		common->Printf( "... don't have GL2.0+ glStencilOpSeparate()\n" );
		qglStencilOpSeparate = nullptr;
	}

	// ARB_vertex_buffer_object
	glConfig.ARBVertexBufferObjectAvailable = R_CheckExtension( "GL_ARB_vertex_buffer_object" );
	if(glConfig.ARBVertexBufferObjectAvailable) {
		qglBindBuffer = (PFNGLBINDBUFFERPROC)GLimp_ExtensionPointer( "glBindBuffer");
		qglGenBuffers = (PFNGLGENBUFFERSPROC)GLimp_ExtensionPointer( "glGenBuffers");
		qglBufferData = (PFNGLBUFFERDATAPROC)GLimp_ExtensionPointer( "glBufferData");
		qglBufferSubData = (PFNGLBUFFERSUBDATAPROC)GLimp_ExtensionPointer( "glBufferSubData");
	}

	// ARB_vertex_program
	glConfig.ARBVertexProgramAvailable = R_CheckExtension( "GL_ARB_vertex_program" );
	if (glConfig.ARBVertexProgramAvailable) {
		qglVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)GLimp_ExtensionPointer( "glVertexAttribPointerARB" );
		qglEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)GLimp_ExtensionPointer( "glEnableVertexAttribArrayARB" );
		qglDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)GLimp_ExtensionPointer( "glDisableVertexAttribArrayARB" );
		qglProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)GLimp_ExtensionPointer( "glProgramStringARB" );
		qglBindProgramARB = (PFNGLBINDPROGRAMARBPROC)GLimp_ExtensionPointer( "glBindProgramARB" );
		qglGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)GLimp_ExtensionPointer( "glGenProgramsARB" );
		qglProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)GLimp_ExtensionPointer( "glProgramEnvParameter4fvARB" );
		qglProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)GLimp_ExtensionPointer( "glProgramLocalParameter4fvARB" );
		qglGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)GLimp_ExtensionPointer("glGetProgramivARB");
	}

	// ARB_fragment_program
	if ( r_inhibitFragmentProgram.GetBool() ) {
		glConfig.ARBFragmentProgramAvailable = false;
	} else {
		glConfig.ARBFragmentProgramAvailable = R_CheckExtension( "GL_ARB_fragment_program" );
		if (glConfig.ARBFragmentProgramAvailable) {
			// these are the same as ARB_vertex_program
			qglProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)GLimp_ExtensionPointer( "glProgramStringARB" );
			qglBindProgramARB = (PFNGLBINDPROGRAMARBPROC)GLimp_ExtensionPointer( "glBindProgramARB" );
			qglProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)GLimp_ExtensionPointer( "glProgramEnvParameter4fvARB" );
			qglProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)GLimp_ExtensionPointer( "glProgramLocalParameter4fvARB" );
		}
	}

	// check for minimum set
	if ( !glConfig.multitextureAvailable || !glConfig.textureEnvCombineAvailable || !glConfig.cubeMapAvailable
		|| !glConfig.envDot3Available ) {
			common->Error( common->GetLanguageDict()->GetString( "#str_06780" ) );
	}

	// GL_EXT_depth_bounds_test
	glConfig.depthBoundsTestAvailable = R_CheckExtension( "EXT_depth_bounds_test" );
	if ( glConfig.depthBoundsTestAvailable ) {
		qglDepthBoundsEXT = (PFNGLDEPTHBOUNDSEXTPROC)GLimp_ExtensionPointer( "glDepthBoundsEXT" );
	}

	// SM: GL_KHR_debug
	glConfig.khrDebugAvailable = R_CheckExtension( "GL_KHR_debug" );
	if ( glConfig.khrDebugAvailable ) {
		qglObjectLabel = (PFNGLOBJECTLABELPROC)GLimp_ExtensionPointer( "glObjectLabel" );
		qglPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)GLimp_ExtensionPointer( "glPushDebugGroup" );
		qglPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)GLimp_ExtensionPointer( "glPopDebugGroup" );

		qglDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKARBPROC)GLimp_ExtensionPointer( "glDebugMessageCallback" );

		// SM: Enable debug output if requested
//#ifdef _DEBUG // DG: always enable this, I see no reason to restrict it to debug builds - it's only active if r_debugGLContext is set
		if ( r_debugGLContext.GetBool() ) {
			common->Printf("Using GL_KHR_debug to log OpenGL Warnings/Errors\n");
			qglEnable( GL_DEBUG_OUTPUT );
			// logging synchronous means that you can put breakpoints in DebugCallback()
			// to see what caused the warning/error
			qglEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			qglDebugMessageCallback(DebugCallback, NULL);
		}
//#endif
	} else if( r_debugGLContext.GetBool() ) {
		common->Warning("r_debugGLContext is set to 1, but GL_KHR_debug is not supported!");
	}

	// blendo eric: gl frame / render buffers
	qglGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)GLimp_ExtensionPointer("glGenFramebuffers");
	qglDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)GLimp_ExtensionPointer("glDeleteFramebuffers");
	qglBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)GLimp_ExtensionPointer("glBindFramebuffer");
	qglFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)GLimp_ExtensionPointer("glFramebufferTexture2D");
	qglCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)GLimp_ExtensionPointer("glCheckFramebufferStatus");
	qglBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)GLimp_ExtensionPointer("glBlitFramebuffer");
	qglDrawBuffers = (PFNGLDRAWBUFFERSPROC)GLimp_ExtensionPointer("glDrawBuffers");
	qglClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)GLimp_ExtensionPointer("glClearBufferuiv");
	qglClearBufferfv = (PFNGLCLEARBUFFERFVPROC)GLimp_ExtensionPointer("glClearBufferfv");

	// SM: GLSL functions
	qglCreateProgram = ( PFNGLCREATEPROGRAMPROC )GLimp_ExtensionPointer( "glCreateProgram" );
	qglAttachShader = ( PFNGLATTACHSHADERPROC )GLimp_ExtensionPointer( "glAttachShader" );
	qglLinkProgram = ( PFNGLLINKPROGRAMPROC ) GLimp_ExtensionPointer( "glLinkProgram" );
	qglDeleteProgram = ( PFNGLDELETEPROGRAMPROC ) GLimp_ExtensionPointer( "glDeleteProgram" );
	qglDeleteShader = ( PFNGLDELETESHADERPROC ) GLimp_ExtensionPointer( "glDeleteShader" );
	qglUseProgram = ( PFNGLUSEPROGRAMPROC ) GLimp_ExtensionPointer( "glUseProgram" );
	qglGetUniformLocation = ( PFNGLGETUNIFORMLOCATIONPROC ) GLimp_ExtensionPointer( "glGetUniformLocation" );
	qglUniformMatrix4fv = ( PFNGLUNIFORMMATRIX4FVPROC ) GLimp_ExtensionPointer( "glUniformMatrix4fv" );
	qglUniform4fv = ( PFNGLUNIFORM4FVPROC ) GLimp_ExtensionPointer( "glUniform4fv" );
	qglUniform3fv = ( PFNGLUNIFORM3FVPROC ) GLimp_ExtensionPointer( "glUniform3fv" );
	qglUniform2fv = ( PFNGLUNIFORM2FVPROC ) GLimp_ExtensionPointer( "glUniform2fv" );
	qglUniform1f = ( PFNGLUNIFORM1FPROC ) GLimp_ExtensionPointer( "glUniform1f" );
	qglUniform1i = ( PFNGLUNIFORM1IPROC ) GLimp_ExtensionPointer( "glUniform1i" );
	qglUniform1ui = ( PFNGLUNIFORM1UIPROC ) GLimp_ExtensionPointer( "glUniform1ui" );
	qglCreateShader = ( PFNGLCREATESHADERPROC ) GLimp_ExtensionPointer( "glCreateShader" );
	qglShaderSource = ( PFNGLSHADERSOURCEPROC ) GLimp_ExtensionPointer( "glShaderSource" );
	qglCompileShader = ( PFNGLCOMPILESHADERPROC ) GLimp_ExtensionPointer( "glCompileShader" );
	qglGetShaderiv = ( PFNGLGETSHADERIVPROC ) GLimp_ExtensionPointer( "glGetShaderiv" );
	qglGetShaderInfoLog = ( PFNGLGETSHADERINFOLOGPROC ) GLimp_ExtensionPointer( "glGetShaderInfoLog" );
	qglGetProgramiv = ( PFNGLGETPROGRAMIVPROC ) GLimp_ExtensionPointer( "glGetProgramiv" );
	qglGetProgramInfoLog = ( PFNGLGETPROGRAMINFOLOGPROC ) GLimp_ExtensionPointer( "glGetProgramInfoLog" );
	qglGetUniformBlockIndex = ( PFNGLGETUNIFORMBLOCKINDEXPROC )GLimp_ExtensionPointer("glGetUniformBlockIndex");
	qglUniformBlockBinding = ( PFNGLUNIFORMBLOCKBINDINGPROC )GLimp_ExtensionPointer("glUniformBlockBinding");
	qglBindBufferRange = ( PFNGLBINDBUFFERRANGEPROC )GLimp_ExtensionPointer("glBindBufferRange");
	qglEnableVertexAttribArray = ( PFNGLENABLEVERTEXATTRIBARRAYPROC )GLimp_ExtensionPointer("glEnableVertexAttribArray");
	qglDisableVertexAttribArray = ( PFNGLDISABLEVERTEXATTRIBARRAYPROC )GLimp_ExtensionPointer("glDisableVertexAttribArray");
	qglVertexAttribPointer = ( PFNGLVERTEXATTRIBPOINTERPROC )GLimp_ExtensionPointer("glVertexAttribPointer");
	qglActiveTexture = ( PFNGLACTIVETEXTUREPROC )GLimp_ExtensionPointer("glActiveTexture");
	qglBindBufferBase = ( PFNGLBINDBUFFERBASEPROC )GLimp_ExtensionPointer("glBindBufferBase");

	glConfig.GLSLAvailable = qglCreateProgram != nullptr;
	idStr gpuStr = glConfig.renderer_string;
	
	// SM: Rendering with GL_COLOR_LOGIC_OP enabled on (~2013-2015) R7 and R9 series cards
	// completely breaks alpha. Pretty sure this is a driver bug, but we have no
	// real way to fix this. Disabling the logic op means that some overlapping
	// outlines of different types may artifact, but that's better than a black screen.
	idStrList amdGPUs;
	amdGPUs.AddUnique("R7 ");			// Reported by Huwiz
	amdGPUs.AddUnique("R9 ");			// Reported by Huwiz
	
	amdGPUs.AddUnique("RX 480");		// Reported on Steam Forums
	amdGPUs.AddUnique("RX 455");		// https://en.wikipedia.org/wiki/Radeon_400_series 
	amdGPUs.AddUnique("RX 460");
	amdGPUs.AddUnique("RX 470");
	amdGPUs.AddUnique("R5 ");

	amdGPUs.AddUnique("HD 78");			// Reported on Steam Forums (there's lots of 78xx)
	amdGPUs.AddUnique("HD 77");			// https://en.wikipedia.org/wiki/Radeon_HD_7000_series
	amdGPUs.AddUnique("HD 73");
	amdGPUs.AddUnique("HD 74");
	amdGPUs.AddUnique("HD 75");
	amdGPUs.AddUnique("HD 76");
	amdGPUs.AddUnique("HD 79");
	amdGPUs.AddUnique("Pro Vega");

	glConfig.isBrokenAMDR7200 = r_AMDWorkaround.GetBool();
	for (int i = 0; i < amdGPUs.Num(); i++) {
		glConfig.isBrokenAMDR7200 = glConfig.isBrokenAMDR7200 || gpuStr.Find(amdGPUs[i]) != -1;
	}

	if (!R_CheckExtension("GL_ARB_texture_float") || !glConfig.GLSLAvailable || !R_CheckExtension("GL_ARB_shading_language_420pack"))
	{
		idStr errorMessage = "Skin Deep requires a graphics card that supports DirectX 11_0 feature level or higher.\n";
		errorMessage += idStr::Format("Your video card is: %s\n\n", glConfig.renderer_string);

		if (!R_CheckExtension("GL_ARB_texture_float"))
			errorMessage += "- Your video card doesn't support GL_ARB_texture_float\n";

		if (!glConfig.GLSLAvailable)
			errorMessage += "- Your video card doesn't support GLSL\n";

		if (!R_CheckExtension("GL_ARB_shading_language_420pack"))
			errorMessage += "- Your video card doesn't support GL_ARB_shading_language_420pack\n";

		errorMessage += "\nExiting now.";

		common->Error(errorMessage.c_str());
	}
}


/*
====================
R_GetModeInfo

r_mode is normally a small non-negative integer that
looks resolutions up in a table, but if it is set to -1,
the values from r_customWidth, and r_customHeight
will be used instead.
====================
*/
// typedef struct vidmode_s {
// 	const char *description;
// 	int         width, height;
// } vidmode_t;
// 
// vidmode_t r_vidModes[] = {
// 	{ "Mode  0: 320x240",		320,	240 },
// 	{ "Mode  1: 400x300",		400,	300 },
// 	{ "Mode  2: 512x384",		512,	384 },
// 	{ "Mode  3: 640x480",		640,	480 },
// 	{ "Mode  4: 800x600",		800,	600 },
// 	{ "Mode  5: 1024x768",		1024,	768 },
// 	{ "Mode  6: 1152x864",		1152,	864 },
// 	{ "Mode  7: 1280x1024",		1280,	1024 },
// 	{ "Mode  8: 1600x1200",		1600,	1200 },
// 	// DG: from here on: modes I added.
// 	{ "Mode  9: 1280x720",		1280,	720 },
// 	{ "Mode 10: 1366x768",		1366,	768 },
// 	{ "Mode 11: 1440x900",		1440,	900 },
// 	{ "Mode 12: 1400x1050",		1400,	1050 },
// 	{ "Mode 13: 1600x900",		1600,	900 },
// 	{ "Mode 14: 1680x1050",		1680,	1050 },
// 	{ "Mode 15: 1920x1080",		1920,	1080 },
// 	{ "Mode 16: 1920x1200",		1920,	1200 },
// 	{ "Mode 17: 2048x1152",		2048,	1152 },
// 	{ "Mode 18: 2560x1600",		2560,	1600 },
// 	{ "Mode 19: 3200x2400",		3200,	2400 },
// 	{ "Mode 20: 3840x2160",		3840,   2160 },
// 	{ "Mode 21: 4096x2304",		4096,   2304 },
// 	{ "Mode 22: 2880x1800",		2880,   1800 },
// 	{ "Mode 23: 2560x1440",		2560,   1440 },
// 	// blendo eric 21:9
// 	{ "Mode 24: 1920x800",		1920,   800  },
// 	{ "Mode 25: 2520x1080",		2520,   1080  },
// 	{ "Mode 26: 2880x1200",		2880,   1200  },
// 	{ "Mode 27: 3840x1600",		3840,	1600  },
// 	{ "Mode 28: 4320x1800",		4320,   1800  },
// };
// // DG: made this an enum so even stupid compilers accept it as array length below
// enum {	s_numVidModes = sizeof( r_vidModes ) / sizeof( r_vidModes[0] ) };
// 
// static bool R_GetModeInfo( int *width, int *height, int mode ) {
// 	vidmode_t	*vm;
// 
// 	if ( mode < -1 ) {
// 		return false;
// 	}
// 	if ( mode >= s_numVidModes ) {
// 		return false;
// 	}
// 
// 	//If using the -1 custom resolution r_mode:
// 	if ( mode == -1 )
// 	{
// 		*width = r_customWidth.GetInteger();
// 		*height = r_customHeight.GetInteger();
// 		return true;
// 	}
// 
// 	vm = &r_vidModes[mode];
// 
// 	if ( width ) {
// 		*width  = vm->width;
// 	}
// 	if ( height ) {
// 		*height = vm->height;
// 	}
// 
// 	return true;
// }
// 
// // DG: I added all this vidModeInfoPtr stuff, so I can have a second list of vidmodes
// //     that are sorted (by width, height), instead of just r_mode index.
// //     That way I can add modes without breaking r_mode, but still display them
// //     sorted in the menu.
// 
// struct vidModePtr {
// 	vidmode_t* vidMode;
// 	int modeIndex;
// };
// 
// static vidModePtr sortedVidModes[s_numVidModes];
// 
// static int vidModeCmp(const void* vm1, const void* vm2)
// {
// 	const vidModePtr* v1 = static_cast<const vidModePtr*>(vm1);
// 	const vidModePtr* v2 = static_cast<const vidModePtr*>(vm2);
// 
// 	// sort primarily by width, secondarily by height
// 	int wdiff = v1->vidMode->width - v2->vidMode->width;
// 	return (wdiff != 0) ? wdiff : (v1->vidMode->height - v2->vidMode->height);
// }
// 
// static void initSortedVidModes()
// {
// 	if(sortedVidModes[0].vidMode != NULL)
// 	{
// 		// already initialized
// 		return;
// 	}
// 
// 	for(int i=0; i<s_numVidModes; ++i)
// 	{
// 		sortedVidModes[i].modeIndex = i;
// 		sortedVidModes[i].vidMode = &r_vidModes[i];
// 	}
// 
// 	qsort(sortedVidModes, s_numVidModes, sizeof(vidModePtr), vidModeCmp);
// }
// 
// bool isValidResolution(int width, int height)
// {
// 	//BC Don't allow some older resolutions. Have a minimum allowed resolution, because the game becomes awkward at mega ancient monitor resolutions
// 	#define VIDEOMODE_MINIMALWIDTH 1024
// 	#define VIDEOMODE_MINIMALHEIGHT 720
// 
// 	if (width < VIDEOMODE_MINIMALWIDTH || height < VIDEOMODE_MINIMALHEIGHT
// 		|| width > glConfig.displayWidth  // blendo eric: don't allow past screen res
// 		|| height > glConfig.displayHeight) {
// 		return false;
// 	}
// 
// 	return true;
// }

// DG: the following two functions are part of a horrible hack in ChoiceWindow.cpp
//     to overwrite the default resolution list in the system options menu

// "r_custom*;640x480;800x600;1024x768;..."
idStrList displayVidModes;
idStrList vidModesToShow;

idStr R_GetVidModeListString()
{
	vidModesToShow = displayVidModes;
	// The current resolution should always also be in the list
	vidModesToShow.AddUnique(r_resolution.GetString());

	vidModesToShow.Sort();

	idStr ret;
	for (int i = 0; i < vidModesToShow.Num(); i++)
	{
		ret += vidModesToShow[i];
		if (vidModesToShow[i] == r_resolution.GetString())
		{
			r_mode.SetInteger(i);
		}
		if (i != vidModesToShow.Num() - 1)
		{
			ret += ';';
		}
	}
// 	idStr ret = "Custom";
// 
// 	for(int i=0; i<s_numVidModes; ++i)
// 	{
// 		//common->Printf("vid %d: %d %d\n", i, sortedVidModes[i].vidMode->width, sortedVidModes[i].vidMode->height);
// 
// 		if(sortedVidModes[i].vidMode != NULL)
// 		{
// 			if (!isValidResolution(sortedVidModes[i].vidMode->width, sortedVidModes[i].vidMode->height))
// 				continue;
// 
// 			idStr modeStr;
// 			sprintf(modeStr, ";%dx %d", sortedVidModes[i].vidMode->width, sortedVidModes[i].vidMode->height);
// 			ret += modeStr;
// 		}
// 	}
	return ret;
}

// r_mode values for resolutions from R_GetVidModeListString(): "-1;3;4;5;..."
idStr R_GetVidModeValsString()
{
	idStr ret;
	for (int i = 0; i < vidModesToShow.Num(); i++)
	{
		ret += idStr::Format("%d", i);
		if (i != vidModesToShow.Num() - 1)
		{
			ret += ';';
		}
	}
// 	idStr ret =  "-1"; // for custom resolutions using r_customWidth/r_customHeight
// 	for(int i=0; i<s_numVidModes; ++i)
// 	{
// 		if(sortedVidModes[i].vidMode != NULL)
// 		{
// 			if (!isValidResolution(sortedVidModes[i].vidMode->width, sortedVidModes[i].vidMode->height))
// 				continue;
// 
// 			ret += ";";
// 			ret += sortedVidModes[i].modeIndex;
// 		}
// 	}
	return ret;
}
// DG end

void R_ValidateResolutionString(int displayIndex)
{
	idStr requestedResolution = r_resolution.GetString();
	idStrList resSplits = requestedResolution.Split('x', true);

	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(displayIndex, &current);
	idStr resString = idStr::Format("%dx%d", current.w, current.h);

	if (resSplits.Num() == 2)
	{
		glConfig.vidWidth = atoi(resSplits[0]);
		glConfig.vidHeight = atoi(resSplits[1]);
	}
	else
	{
		r_resolution.SetString(resString);
		glConfig.vidWidth = current.w;
		glConfig.vidHeight = current.h;
		r_fullscreen.SetInteger(2);
	}

	// Confirm this is a valid resolution, there's different logic depending on what we're in

	// For borderless, only the current screen resolution is allowed
	if (r_fullscreen.GetInteger() == 2 && (glConfig.vidWidth != current.w || glConfig.vidHeight != current.h))
	{
		r_resolution.SetString(resString);
		glConfig.vidWidth = current.w;
		glConfig.vidHeight = current.h;
	}

	// If we're full screen exclusive and this is not a supported resolution
	// go back to borderless default
	if (r_fullscreen.GetInteger() == 1)
	{
		bool supported = false;

		int numDisplayModes = SDL_GetNumDisplayModes(0);
		for (int i = 0; i < numDisplayModes; i++)
		{
			SDL_DisplayMode mode;
			SDL_GetDisplayMode(0, i, &mode);
			if (mode.w == glConfig.vidWidth && mode.h == glConfig.vidHeight)
			{
				supported = true;
				break;
			}
		}

		if (!supported)
		{
			r_resolution.SetString(resString);
			glConfig.vidWidth = current.w;
			glConfig.vidHeight = current.h;
			r_fullscreen.SetInteger(2);
		}
	}

	// If we're windowed, make sure the size is <= current resolution, otherwise go back
	// to borderless default
	if (r_fullscreen.GetInteger() == 0 && (glConfig.vidWidth > current.w || glConfig.vidHeight > current.h))
	{
		r_resolution.SetString(resString);
		glConfig.vidWidth = current.w;
		glConfig.vidHeight = current.h;
		r_fullscreen.SetInteger(2);
	}
}

/*
==================
R_InitOpenGL

This function is responsible for initializing a valid OpenGL subsystem
for rendering.  This is done by calling the system specific GLimp_Init,
which gives us a working OGL subsystem, then setting all necessary openGL
state, including images, vertex programs, and display lists.

Changes to the vertex cache size or smp state require a vid_restart.

If glConfig.isInitialized is false, no rendering can take place, but
all renderSystem functions will still operate properly, notably the material
and model information functions.
==================
*/
void R_InitOpenGL( void ) {
	GLint			temp;
	glimpParms_t	parms;
	int				i;

	common->Printf( "----- Initializing OpenGL -----\n" );

	if ( glConfig.isInitialized ) {
		common->FatalError( "R_InitOpenGL called while active" );
	}

	// in case we had an error while doing a tiled rendering
	tr.viewportOffset[0] = 0;
	tr.viewportOffset[1] = 0;

	//initSortedVidModes();

	//
	// initialize OS specific portions of the renderSystem
	//
	for ( i = 0 ; i < 2 ; i++ ) {
		R_ValidateResolutionString(0);

		// set the parameters we are trying
		//R_GetModeInfo( &glConfig.vidWidth, &glConfig.vidHeight, r_mode.GetInteger() );

		parms.width = glConfig.vidWidth;
		parms.height = glConfig.vidHeight;
		parms.fullScreen = r_fullscreen.GetInteger() == 1;
		parms.borderless = r_fullscreen.GetInteger() == 2;
		parms.displayHz = r_displayRefresh.GetInteger();
		parms.multiSamples = r_multiSamples.GetInteger();
		parms.stereo = false;

		if ( GLimp_Init( parms ) ) {
			// it worked
			break;
		}

		if ( i == 1 ) {
			common->FatalError( "Unable to initialize OpenGL" );
		}

		// if we failed, set everything back to "safe mode"
		// and try again
		r_mode.SetInteger( 3 );
		r_resolution.SetString("1280x720");
		r_fullscreen.SetInteger( 0 );
		r_displayRefresh.SetInteger( 0 );
		r_multiSamples.SetInteger( 0 );
	}

// load qgl function pointers
#define QGLPROC(name, rettype, args) \
	q##name = (rettype(APIENTRYP)args)GLimp_ExtensionPointer(#name); \
	if (!q##name) \
		common->FatalError("Unable to initialize OpenGL (%s)", #name);

#include "renderer/qgl_proc.h"

	// input and sound systems need to be tied to the new window
	Sys_InitInput();
	soundSystem->InitHW();

	// get our config strings
	glConfig.vendor_string = (const char *)qglGetString(GL_VENDOR);
	glConfig.renderer_string = (const char *)qglGetString(GL_RENDERER);


	// blendo eric: create short name for display in options by removing anything after slashes,
	// eg: nvidia geforce gtx 1660 TI / PCIE2 / BLAH / BLAH
	if (strstr(glConfig.renderer_string, "/"))
	{
		char* shortStr = new char[strlen(glConfig.renderer_string)+1];
		strcpy(shortStr, glConfig.renderer_string);
		strtok(shortStr, "/");
		glConfig.renderer_short_string = shortStr;
	}
	else
	{
		glConfig.renderer_short_string = glConfig.renderer_string;
	}

	glConfig.version_string = (const char *)qglGetString(GL_VERSION);
	glConfig.extensions_string = (const char *)qglGetString(GL_EXTENSIONS);

	// OpenGL driver constants
	qglGetIntegerv( GL_MAX_TEXTURE_SIZE, &temp );
	glConfig.maxTextureSize = temp;

	// stubbed or broken drivers may have reported 0...
	if ( glConfig.maxTextureSize <= 0 ) {
		glConfig.maxTextureSize = 256;
	}

	glConfig.isInitialized = true;

	common->Printf("OpenGL vendor: %s\n", glConfig.vendor_string );
	common->Printf("OpenGL renderer: %s\n", glConfig.renderer_string );
	common->Printf("OpenGL version: %s\n", glConfig.version_string );

	// recheck all the extensions (FIXME: this might be dangerous)
	R_CheckPortableExtensions();

	R_GLSL_Init();

	// allocate the vertex array range or vertex objects
	vertexCache.Init();

	// select which renderSystem we are going to use
	r_renderer.SetModified();
	tr.SetBackEndRenderer();

	// allocate the frame data, which may be more if smp is enabled
	R_InitFrameData();

	// SM: Don't mess with gamma anymore because we do brightness in a shader
	// Reset our gamma
	// R_SetColorMappings();

#ifdef _WIN32
	static bool glCheck = false;
	if ( !glCheck && win32.osversion.dwMajorVersion == 6 ) {
		glCheck = true;
		if ( !idStr::Icmp( glConfig.vendor_string, "Microsoft" ) && idStr::FindText( glConfig.renderer_string, "OpenGL-D3D" ) != -1 ) {
			if ( cvarSystem->GetCVarInteger( "r_fullscreen" ) == 1 ) {
				cmdSystem->BufferCommandText( CMD_EXEC_NOW, "vid_restart partial windowed\n" );
				Sys_GrabMouseCursor( false );
			}
			int ret = MessageBox( NULL, "Please install OpenGL drivers from your graphics hardware vendor to run " GAME_NAME ".\nYour OpenGL functionality is limited.",
				"Insufficient OpenGL capabilities", MB_OKCANCEL | MB_ICONWARNING | MB_TASKMODAL );
			if ( ret == IDCANCEL ) {
				cmdSystem->BufferCommandText( CMD_EXEC_APPEND, "quit\n" );
				cmdSystem->ExecuteCommandBuffer();
			}
			if ( cvarSystem->GetCVarInteger( "r_fullscreen" ) == 1) {
				cmdSystem->BufferCommandText( CMD_EXEC_APPEND, "vid_restart\n" );
			}
		}
	}
#endif
}

/*
==================
GL_CheckErrors
==================
*/
void GL_CheckErrors( void ) {
	int		err;
	char	s[64];
	int		i;

	// check for up to 10 errors pending
	for ( i = 0 ; i < 10 ; i++ ) {
		err = qglGetError();
		if ( err == GL_NO_ERROR ) {
			return;
		}
		switch( err ) {
			case GL_INVALID_ENUM:
				strcpy( s, "GL_INVALID_ENUM" );
				break;
			case GL_INVALID_VALUE:
				strcpy( s, "GL_INVALID_VALUE" );
				break;
			case GL_INVALID_OPERATION:
				strcpy( s, "GL_INVALID_OPERATION" );
				break;
			case GL_STACK_OVERFLOW:
				strcpy( s, "GL_STACK_OVERFLOW" );
				break;
			case GL_STACK_UNDERFLOW:
				strcpy( s, "GL_STACK_UNDERFLOW" );
				break;
			case GL_OUT_OF_MEMORY:
				strcpy( s, "GL_OUT_OF_MEMORY" );
				break;
			default:
				idStr::snPrintf( s, sizeof(s), "%i", err);
				break;
		}

		if ( !r_ignoreGLErrors.GetBool() ) {
			common->Printf( "GL_CheckErrors: %s\n", s );
		}
	}
}

/*
=====================
R_ReloadSurface_f

Reload the material displayed by r_showSurfaceInfo
=====================
*/
static void R_ReloadSurface_f( const idCmdArgs &args ) {
	modelTrace_t mt;
	idVec3 start, end;

	// start far enough away that we don't hit the player model
	start = tr.primaryView->renderView.vieworg + tr.primaryView->renderView.viewaxis[0] * 16;
	end = start + tr.primaryView->renderView.viewaxis[0] * 1000.0f;

	if (tr.primaryWorld == NULL) //BC
		return;

	if ( !tr.primaryWorld->Trace( mt, start, end, 0.0f, false ) ) {
		return;
	}

	common->Printf( "Reloading %s\n", mt.material->GetName() );

	// reload the decl
	mt.material->base->Reload();

	// reload any images used by the decl
	mt.material->ReloadImages( false );
}



/*
==============
R_ListModes_f
==============
*/
static void R_ListModes_f( const idCmdArgs &args ) {
	int i;

	common->Printf( "\n" );
	for ( i = 0; i < vidModesToShow.Num(); i++ ) {
		common->Printf( "%s\n", vidModesToShow[i].c_str() );
	}
	common->Printf( "\n" );
}



/*
=============
R_TestImage_f

Display the given image centered on the screen.
testimage <number>
testimage <filename>
=============
*/
void R_TestImage_f( const idCmdArgs &args ) {
	int imageNum;

	if ( tr.testVideo ) {
		delete tr.testVideo;
		tr.testVideo = NULL;
	}
	tr.testImage = NULL;

	if ( args.Argc() != 2 ) {
		return;
	}

	if ( idStr::IsNumeric( args.Argv(1) ) ) {
		imageNum = atoi( args.Argv(1) );
		if ( imageNum >= 0 && imageNum < globalImages->images.Num() ) {
			tr.testImage = globalImages->images[imageNum];
		}
	} else {
		tr.testImage = globalImages->ImageFromFile( args.Argv( 1 ), TF_DEFAULT, false, TR_REPEAT, TD_DEFAULT );
	}
}

/*
=============
R_TestVideo_f

Plays the cinematic file in a testImage
=============
*/
void R_TestVideo_f( const idCmdArgs &args ) {
	if ( tr.testVideo ) {
		delete tr.testVideo;
		tr.testVideo = NULL;
	}
	tr.testImage = NULL;

	if ( args.Argc() < 2 ) {
		return;
	}

	tr.testImage = globalImages->ImageFromFile( "_scratch", TF_DEFAULT, false, TR_REPEAT, TD_DEFAULT );
	tr.testVideo = idCinematic::Alloc();
	tr.testVideo->InitFromFile( args.Argv( 1 ), true );

	cinData_t	cin;
	cin = tr.testVideo->ImageForTime( 0 );
	if ( !cin.image ) {
		delete tr.testVideo;
		tr.testVideo = NULL;
		tr.testImage = NULL;
		return;
	}

	common->Printf( "%i x %i images\n", cin.imageWidth, cin.imageHeight );

	int	len = tr.testVideo->AnimationLength();
	common->Printf( "%5.1f seconds of video\n", len * 0.001 );

	tr.testVideoStartTime = tr.primaryRenderView.time * 0.001;

	// try to play the matching wav file
	idStr	wavString = args.Argv( ( args.Argc() == 2 ) ? 1 : 2 );
	wavString.StripFileExtension();
	wavString = wavString + ".wav";
	session->sw->PlayShaderDirectly( wavString.c_str() );
}

static int R_QsortSurfaceAreas( const void *a, const void *b ) {
	const idMaterial	*ea, *eb;
	int	ac, bc;

	ea = *(idMaterial **)a;
	if ( !ea->EverReferenced() ) {
		ac = 0;
	} else {
		ac = ea->GetSurfaceArea();
	}
	eb = *(idMaterial **)b;
	if ( !eb->EverReferenced() ) {
		bc = 0;
	} else {
		bc = eb->GetSurfaceArea();
	}

	if ( ac < bc ) {
		return -1;
	}
	if ( ac > bc ) {
		return 1;
	}

	return idStr::Icmp( ea->GetName(), eb->GetName() );
}


/*
===================
R_ReportSurfaceAreas_f

Prints a list of the materials sorted by surface area
===================
*/
void R_ReportSurfaceAreas_f( const idCmdArgs &args ) {
	int		i, count;
	idMaterial	**list;

	count = declManager->GetNumDecls( DECL_MATERIAL );
	list = (idMaterial **)_alloca( count * sizeof( *list ) );

	for ( i = 0 ; i < count ; i++ ) {
		list[i] = (idMaterial *)declManager->DeclByIndex( DECL_MATERIAL, i, false );
	}

	qsort( list, count, sizeof( list[0] ), R_QsortSurfaceAreas );

	// skip over ones with 0 area
	for ( i = 0 ; i < count ; i++ ) {
		if ( list[i]->GetSurfaceArea() > 0 ) {
			break;
		}
	}

	for ( ; i < count ; i++ ) {
		// report size in "editor blocks"
		int	blocks = list[i]->GetSurfaceArea() / 4096.0;
		common->Printf( "%7i %s\n", blocks, list[i]->GetName() );
	}
}

/*
===================
R_ReportImageDuplication_f

Checks for images with the same hash value and does a better comparison
===================
*/
void R_ReportImageDuplication_f( const idCmdArgs &args ) {
	int		i, j;

	common->Printf( "Images with duplicated contents:\n" );

	int	count = 0;

	for ( i = 0 ; i < globalImages->images.Num() ; i++ ) {
		idImage	*image1 = globalImages->images[i];

		if ( image1->isPartialImage ) {
			// ignore background loading stubs
			continue;
		}
		if ( image1->generatorFunction ) {
			// ignore procedural images
			continue;
		}
		if ( image1->cubeFiles != CF_2D ) {
			// ignore cube maps
			continue;
		}
		if ( image1->defaulted ) {
			continue;
		}
		byte	*data1;
		int		w1, h1;

		R_LoadImageProgram( image1->imgName, &data1, &w1, &h1, NULL );

		for ( j = 0 ; j < i ; j++ ) {
			idImage	*image2 = globalImages->images[j];

			if ( image2->isPartialImage ) {
				continue;
			}
			if ( image2->generatorFunction ) {
				continue;
			}
			if ( image2->cubeFiles != CF_2D ) {
				continue;
			}
			if ( image2->defaulted ) {
				continue;
			}
			if ( image1->imageHash != image2->imageHash ) {
				continue;
			}
			if ( image2->uploadWidth != image1->uploadWidth
				|| image2->uploadHeight != image1->uploadHeight ) {
				continue;
			}
			if ( !idStr::Icmp( image1->imgName, image2->imgName ) ) {
				// ignore same image-with-different-parms
				continue;
			}

			byte	*data2;
			int		w2, h2;

			R_LoadImageProgram( image2->imgName, &data2, &w2, &h2, NULL );

			if ( w2 != w1 || h2 != h1 ) {
				R_StaticFree( data2 );
				continue;
			}

			if ( memcmp( data1, data2, w1*h1*4 ) ) {
				R_StaticFree( data2 );
				continue;
			}

			R_StaticFree( data2 );

			common->Printf( "%s == %s\n", image1->imgName.c_str(), image2->imgName.c_str() );
			session->UpdateScreen( true );
			count++;
			break;
		}

		R_StaticFree( data1 );
	}
	common->Printf( "%i / %i collisions\n", count, globalImages->images.Num() );
}

/*
==============================================================================

						THROUGHPUT BENCHMARKING

==============================================================================
*/

/*
================
R_RenderingFPS
================
*/
static float R_RenderingFPS( const renderView_t *renderView ) {
	qglFinish();

	int		start = Sys_Milliseconds();
	static const int SAMPLE_MSEC = 1000;
	int		end;
	int		count = 0;

	while( 1 ) {
		// render
		renderSystem->BeginFrame( glConfig.vidWidth, glConfig.vidHeight );
		tr.primaryWorld->RenderScene( renderView );
		renderSystem->EndFrame( NULL, NULL );
		qglFinish();
		count++;
		end = Sys_Milliseconds();
		if ( end - start > SAMPLE_MSEC ) {
			break;
		}
	}

	float fps = count * 1000.0 / ( end - start );

	return fps;
}

/*
================
R_Benchmark_f
================
*/
void R_Benchmark_f( const idCmdArgs &args ) {
	float	fps, msec;
	renderView_t	view;

	if ( !tr.primaryView ) {
		common->Printf( "No primaryView for benchmarking\n" );
		return;
	}
	view = tr.primaryRenderView;

	for ( int size = 100 ; size >= 10 ; size -= 10 ) {
		r_screenFraction.SetInteger( size );
		fps = R_RenderingFPS( &view );
		int	kpix = glConfig.vidWidth * glConfig.vidHeight * ( size * 0.01 ) * ( size * 0.01 ) * 0.001;
		msec = 1000.0 / fps;
		common->Printf( "kpix: %4i  msec:%5.1f fps:%5.1f\n", kpix, msec, fps );
	}

	// enable r_singleTriangle 1 while r_screenFraction is still at 10
	r_singleTriangle.SetBool( 1 );
	fps = R_RenderingFPS( &view );
	msec = 1000.0 / fps;
	common->Printf( "single tri  msec:%5.1f fps:%5.1f\n", msec, fps );
	r_singleTriangle.SetBool( 0 );
	r_screenFraction.SetInteger( 100 );

	// enable r_skipRenderContext 1
	r_skipRenderContext.SetBool( true );
	fps = R_RenderingFPS( &view );
	msec = 1000.0 / fps;
	common->Printf( "no context  msec:%5.1f fps:%5.1f\n", msec, fps );
	r_skipRenderContext.SetBool( false );
}


/*
==============================================================================

						SCREEN SHOTS

==============================================================================
*/

/*
====================
R_ReadTiledPixels

Allows the rendering of an image larger than the actual window by
tiling it into window-sized chunks and rendering each chunk separately

If ref isn't specified, the full session UpdateScreen will be done.
====================
*/
void R_ReadTiledPixels( int width, int height, byte *buffer, renderView_t *ref = NULL ) {
	// include extra space for OpenGL padding to word boundaries
	byte	*temp = (byte *)R_StaticAlloc( (glConfig.vidWidth+3) * glConfig.vidHeight * 3 );

	int	oldWidth = glConfig.vidWidth;
	int oldHeight = glConfig.vidHeight;

	tr.tiledViewport[0] = width;
	tr.tiledViewport[1] = height;

	// disable scissor, so we don't need to adjust all those rects
	r_useScissor.SetBool( false );

	for ( int xo = 0 ; xo < width ; xo += oldWidth ) {
		for ( int yo = 0 ; yo < height ; yo += oldHeight ) {
			tr.viewportOffset[0] = -xo;
			tr.viewportOffset[1] = -yo;

			if ( ref ) {
				tr.BeginFrame( oldWidth, oldHeight );
				tr.primaryWorld->RenderScene( ref );
				tr.EndFrame( NULL, NULL );
			} else {
				session->UpdateScreen(false);
			}

			int w = oldWidth;
			if ( xo + w > width ) {
				w = width - xo;
			}
			int h = oldHeight;
			if ( yo + h > height ) {
				h = height - yo;
			}

			qglReadBuffer( GL_FRONT );
			qglReadPixels( 0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, temp );

			int	row = ( w * 3 + 3 ) & ~3;		// OpenGL pads to dword boundaries

			for ( int y = 0 ; y < h ; y++ ) {
				memcpy( buffer + ( ( yo + y )* width + xo ) * 3,
					temp + y * row, w * 3 );
			}
		}
	}

	r_useScissor.SetBool( true );

	tr.viewportOffset[0] = 0;
	tr.viewportOffset[1] = 0;
	tr.tiledViewport[0] = 0;
	tr.tiledViewport[1] = 0;

	R_StaticFree( temp );

	glConfig.vidWidth = oldWidth;
	glConfig.vidHeight = oldHeight;
}


/*
==================
TakeScreenshot

Move to tr_imagefiles.c...

Will automatically tile render large screen shots if necessary
Downsample is the number of steps to mipmap the image before saving it
If ref == NULL, session->updateScreen will be used
==================
*/
void idRenderSystemLocal::TakeScreenshot( int width, int height, const char *fileName, int blends, renderView_t *ref ) {
	byte		*buffer;
	int			i, j, c, temp;

	takingScreenshot = true;

	int	pix = width * height;

	buffer = (byte *)R_StaticAlloc(pix*3 + 18);
	memset (buffer, 0, 18);

	if ( blends <= 1 ) {
		R_ReadTiledPixels( width, height, buffer + 18, ref );
	} else {
		unsigned short *shortBuffer = (unsigned short *)R_StaticAlloc(pix*2*3);
		memset (shortBuffer, 0, pix*2*3);

		// enable anti-aliasing jitter
		r_jitter.SetBool( true );

		for ( i = 0 ; i < blends ; i++ ) {
			R_ReadTiledPixels( width, height, buffer + 18, ref );

			for ( j = 0 ; j < pix*3 ; j++ ) {
				shortBuffer[j] += buffer[18+j];
			}
		}

		// divide back to bytes
		for ( i = 0 ; i < pix*3 ; i++ ) {
			buffer[18+i] = shortBuffer[i] / blends;
		}

		R_StaticFree( shortBuffer );
		r_jitter.SetBool( false );
	}

// blendo eric: png screen shot
#ifdef BLENDO_PNG_SCREENSHOT
	if (idStr::CheckExtension(fileName,"png")) {
		// blendo eric: flip true for opengl
		stbi_flip_vertically_on_write(true);
		//unsigned char * stbi_write_png_to_mem(const unsigned char *pixels, int stride_bytes, int x, int y, int n, int *out_len)
		int pngDataSize = 0;
		byte * pngData = stbi_write_png_to_mem(buffer + 18, 0, width, height, 3, &pngDataSize);

		// _D3XP adds viewnote screenie save to cdpath
		if (strstr(fileName, "viewnote")) {
			fileSystem->WriteFile(fileName, pngData, pngDataSize, "fs_cdpath");
		}
		else {
			fileSystem->WriteFile(fileName, pngData, pngDataSize);
		}

		STBIW_FREE(pngData);
	} else 
#endif // BLENDO_PNG_SCREENSHOT
	{
		// fill in the header (this is vertically flipped, which qglReadPixels emits)
		buffer[2] = 2;		// uncompressed type
		buffer[12] = width & 255;
		buffer[13] = width >> 8;
		buffer[14] = height & 255;
		buffer[15] = height >> 8;
		buffer[16] = 24;	// pixel size

		// swap rgb to bgr
		c = 18 + width * height * 3;
		for (i = 18; i < c; i += 3) {
			temp = buffer[i];
			buffer[i] = buffer[i + 2];
			buffer[i + 2] = temp;
		}

		// _D3XP adds viewnote screenie save to cdpath
		if (strstr(fileName, "viewnote")) {
			fileSystem->WriteFile(fileName, buffer, c, "fs_cdpath");
		}
		else {
			fileSystem->WriteFile(fileName, buffer, c);
		}
	}

	R_StaticFree( buffer );

	takingScreenshot = false;

}


/*
==================
R_ScreenshotFilename

Returns a filename with digits appended
if we have saved a previous screenshot, don't scan
from the beginning, because recording demo avis can involve
thousands of shots
==================
*/
void R_ScreenshotFilename( int &lastNumber, const char *base, idStr &fileName, const char* extensionType) {
	int	a,b,c,d, e;

	bool fsrestrict = cvarSystem->GetCVarBool( "fs_restrict" );
	cvarSystem->SetCVarBool( "fs_restrict", false );

	lastNumber++;
	if ( lastNumber > 99999 ) {
		lastNumber = 99999;
	}
	for ( ; lastNumber < 99999 ; lastNumber++ ) {
		int	frac = lastNumber;

		a = frac / 10000;
		frac -= a*10000;
		b = frac / 1000;
		frac -= b*1000;
		c = frac / 100;
		frac -= c*100;
		d = frac / 10;
		frac -= d*10;
		e = frac;

		sprintf( fileName, "%s%i%i%i%i%i.%s", base, a, b, c, d, e, extensionType);
		if ( lastNumber == 99999 ) {
			break;
		}
		int len = fileSystem->ReadFile( fileName, NULL, NULL );
		if ( len <= 0 ) {
			break;
		}
		// check again...
	}
	cvarSystem->SetCVarBool( "fs_restrict", fsrestrict );
}

/*
==================
R_BlendedScreenShot

screenshot
screenshot [filename]
screenshot [width] [height]
screenshot [width] [height] [samples]
==================
*/
#define	MAX_BLENDS	256	// to keep the accumulation in shorts
void R_ScreenShot_f( const idCmdArgs &args ) {
	static int lastNumber = 0;
	idStr checkname;

	int width = glConfig.vidWidth;
	int height = glConfig.vidHeight;
	int	blends = 0;

#ifdef BLENDO_PNG_SCREENSHOT
	const char * extensionType = "png";
#else
	const char * extensionType = "tga";
#endif

	switch ( args.Argc() ) {
	case 1:
		width = glConfig.vidWidth;
		height = glConfig.vidHeight;
		blends = 1;
		R_ScreenshotFilename( lastNumber, "screenshots/shot", checkname, extensionType);
		break;
	case 2:
		width = glConfig.vidWidth;
		height = glConfig.vidHeight;
		blends = 1;
		checkname = args.Argv( 1 );
		break;
	case 3:
		width = atoi( args.Argv( 1 ) );
		height = atoi( args.Argv( 2 ) );
		blends = 1;
		R_ScreenshotFilename( lastNumber, "screenshots/shot", checkname, extensionType);
		break;
	case 4:
		width = atoi( args.Argv( 1 ) );
		height = atoi( args.Argv( 2 ) );
		blends = atoi( args.Argv( 3 ) );
		if ( blends < 1 ) {
			blends = 1;
		}
		if ( blends > MAX_BLENDS ) {
			blends = MAX_BLENDS;
		}
		R_ScreenshotFilename( lastNumber, "screenshots/shot", checkname, extensionType);
		break;
	default:
		common->Printf( "usage: screenshot\n       screenshot <filename>\n       screenshot <width> <height>\n       screenshot <width> <height> <blends>\n" );
		return;
	}

	// put the console away
	console->Close();

	tr.TakeScreenshot( width, height, checkname, blends, NULL );

	common->Printf( "Wrote %s\n", checkname.c_str() );
}

/*
===============
R_StencilShot
Save out a screenshot showing the stencil buffer expanded by 16x range
===============
*/
void R_StencilShot( void ) {
	byte		*buffer;
	int			i, c;

	int	width = tr.GetScreenWidth();
	int	height = tr.GetScreenHeight();

	int	pix = width * height;

	c = pix * 3 + 18;
	buffer = (byte *)Mem_Alloc(c);
	memset (buffer, 0, 18);

	byte *byteBuffer = (byte *)Mem_Alloc(pix);

	qglReadPixels( 0, 0, width, height, GL_STENCIL_INDEX , GL_UNSIGNED_BYTE, byteBuffer );

	for ( i = 0 ; i < pix ; i++ ) {
		buffer[18+i*3] =
		buffer[18+i*3+1] =
			//		buffer[18+i*3+2] = ( byteBuffer[i] & 15 ) * 16;
		buffer[18+i*3+2] = byteBuffer[i];
	}

	// fill in the header (this is vertically flipped, which qglReadPixels emits)
	buffer[2] = 2;		// uncompressed type
	buffer[12] = width & 255;
	buffer[13] = width >> 8;
	buffer[14] = height & 255;
	buffer[15] = height >> 8;
	buffer[16] = 24;	// pixel size

	fileSystem->WriteFile( "screenshots/stencilShot.tga", buffer, c, "fs_savepath" );

	Mem_Free( buffer );
	Mem_Free( byteBuffer );
}

/*
==================
R_EnvShot_f

envshot <basename>

Saves out env/<basename>_ft.tga, etc
==================
*/
void R_EnvShot_f( const idCmdArgs &args ) {
	idStr		fullname;
	const char	*baseName;
	int			i;
	idMat3		axis[6];
	renderView_t	ref;
	viewDef_t	primary;
	int			blends;
	const char	*extensions[6] =  { "_px.tga", "_nx.tga", "_py.tga", "_ny.tga",
		"_pz.tga", "_nz.tga" };
	int			size;

	if ( args.Argc() != 2 && args.Argc() != 3 && args.Argc() != 4 ) {
		common->Printf( "USAGE: envshot <basename> [size] [blends]\n" );
		return;
	}
	baseName = args.Argv( 1 );

	blends = 1;
	if ( args.Argc() == 4 ) {
		size = atoi( args.Argv( 2 ) );
		blends = atoi( args.Argv( 3 ) );
	} else if ( args.Argc() == 3 ) {
		size = atoi( args.Argv( 2 ) );
		blends = 1;
	} else {
		size = 256;
		blends = 1;
	}

	if ( !tr.primaryView ) {
		common->Printf( "No primary view.\n" );
		return;
	}

	primary = *tr.primaryView;

	memset( &axis, 0, sizeof( axis ) );
	axis[0][0][0] = 1;
	axis[0][1][2] = 1;
	axis[0][2][1] = 1;

	axis[1][0][0] = -1;
	axis[1][1][2] = -1;
	axis[1][2][1] = 1;

	axis[2][0][1] = 1;
	axis[2][1][0] = -1;
	axis[2][2][2] = -1;

	axis[3][0][1] = -1;
	axis[3][1][0] = -1;
	axis[3][2][2] = 1;

	axis[4][0][2] = 1;
	axis[4][1][0] = -1;
	axis[4][2][1] = 1;

	axis[5][0][2] = -1;
	axis[5][1][0] = 1;
	axis[5][2][1] = 1;

	for ( i = 0 ; i < 6 ; i++ ) {
		ref = primary.renderView;
		ref.x = ref.y = 0;
		ref.fov_x = ref.fov_y = 90;
		ref.width = glConfig.vidWidth;
		ref.height = glConfig.vidHeight;
		ref.viewaxis = axis[i];
		sprintf( fullname, "env/%s%s", baseName, extensions[i] );
		tr.TakeScreenshot( size, size, fullname, blends, &ref );
	}

	common->Printf( "Wrote %s, etc\n", fullname.c_str() );
}

//============================================================================

static idMat3		cubeAxis[6];


/*
==================
R_SampleCubeMap
==================
*/
void R_SampleCubeMap( const idVec3 &dir, int size, byte *buffers[6], byte result[4] ) {
	float	adir[3];
	int		axis, x, y;

	adir[0] = fabs(dir[0]);
	adir[1] = fabs(dir[1]);
	adir[2] = fabs(dir[2]);

	if ( dir[0] >= adir[1] && dir[0] >= adir[2] ) {
		axis = 0;
	} else if ( -dir[0] >= adir[1] && -dir[0] >= adir[2] ) {
		axis = 1;
	} else if ( dir[1] >= adir[0] && dir[1] >= adir[2] ) {
		axis = 2;
	} else if ( -dir[1] >= adir[0] && -dir[1] >= adir[2] ) {
		axis = 3;
	} else if ( dir[2] >= adir[1] && dir[2] >= adir[2] ) {
		axis = 4;
	} else {
		axis = 5;
	}

	float	fx = (dir * cubeAxis[axis][1]) / (dir * cubeAxis[axis][0]);
	float	fy = (dir * cubeAxis[axis][2]) / (dir * cubeAxis[axis][0]);

	fx = -fx;
	fy = -fy;
	x = size * 0.5 * (fx + 1);
	y = size * 0.5 * (fy + 1);
	if ( x < 0 ) {
		x = 0;
	} else if ( x >= size ) {
		x = size-1;
	}
	if ( y < 0 ) {
		y = 0;
	} else if ( y >= size ) {
		y = size-1;
	}

	result[0] = buffers[axis][(y*size+x)*4+0];
	result[1] = buffers[axis][(y*size+x)*4+1];
	result[2] = buffers[axis][(y*size+x)*4+2];
	result[3] = buffers[axis][(y*size+x)*4+3];
}

/*
==================
R_MakeAmbientMap_f

R_MakeAmbientMap_f <basename> [size]

Saves out env/<basename>_amb_ft.tga, etc
==================
*/
void R_MakeAmbientMap_f( const idCmdArgs &args ) {
	idStr fullname;
	const char	*baseName;
	int			i;
	const char	*extensions[6] =  { "_px.tga", "_nx.tga", "_py.tga", "_ny.tga",
		"_pz.tga", "_nz.tga" };
	int			outSize;
	byte		*buffers[6];
	int			width, height;

	if ( args.Argc() != 2 && args.Argc() != 3 ) {
		common->Printf( "USAGE: ambientshot <basename> [size]\n" );
		return;
	}
	baseName = args.Argv( 1 );

	if ( args.Argc() == 3 ) {
		outSize = atoi( args.Argv( 2 ) );
	} else {
		outSize = 32;
	}

	memset( &cubeAxis, 0, sizeof( cubeAxis ) );
	cubeAxis[0][0][0] = 1;
	cubeAxis[0][1][2] = 1;
	cubeAxis[0][2][1] = 1;

	cubeAxis[1][0][0] = -1;
	cubeAxis[1][1][2] = -1;
	cubeAxis[1][2][1] = 1;

	cubeAxis[2][0][1] = 1;
	cubeAxis[2][1][0] = -1;
	cubeAxis[2][2][2] = -1;

	cubeAxis[3][0][1] = -1;
	cubeAxis[3][1][0] = -1;
	cubeAxis[3][2][2] = 1;

	cubeAxis[4][0][2] = 1;
	cubeAxis[4][1][0] = -1;
	cubeAxis[4][2][1] = 1;

	cubeAxis[5][0][2] = -1;
	cubeAxis[5][1][0] = 1;
	cubeAxis[5][2][1] = 1;

	// read all of the images
	for ( i = 0 ; i < 6 ; i++ ) {
		sprintf( fullname, "env/%s%s", baseName, extensions[i] );
		common->Printf( "loading %s\n", fullname.c_str() );
		session->UpdateScreen();
		R_LoadImage( fullname, &buffers[i], &width, &height, NULL, true );
		if ( !buffers[i] ) {
			common->Printf( "failed.\n" );
			for ( i-- ; i >= 0 ; i-- ) {
				Mem_Free( buffers[i] );
			}
			return;
		}
	}

	// resample with hemispherical blending
	int	samples = 1000;

	byte	*outBuffer = (byte *)_alloca( outSize * outSize * 4 );

	for ( int map = 0 ; map < 2 ; map++ ) {
		for ( i = 0 ; i < 6 ; i++ ) {
			for ( int x = 0 ; x < outSize ; x++ ) {
				for ( int y = 0 ; y < outSize ; y++ ) {
					idVec3	dir;
					float	total[3];

					dir = cubeAxis[i][0] + -( -1 + 2.0*x/(outSize-1) ) * cubeAxis[i][1] + -( -1 + 2.0*y/(outSize-1) ) * cubeAxis[i][2];
					dir.Normalize();
					total[0] = total[1] = total[2] = 0;
	//samples = 1;
					float	limit = map ? 0.95 : 0.25;		// small for specular, almost hemisphere for ambient

					for ( int s = 0 ; s < samples ; s++ ) {
						// pick a random direction vector that is inside the unit sphere but not behind dir,
						// which is a robust way to evenly sample a hemisphere
						idVec3	test;
						while( 1 ) {
							for ( int j = 0 ; j < 3 ; j++ ) {
								test[j] = -1 + 2 * (rand()&0x7fff)/(float)0x7fff;
							}
							if ( test.Length() > 1.0 ) {
								continue;
							}
							test.Normalize();
							if ( test * dir > limit ) {	// don't do a complete hemisphere
								break;
							}
						}
						byte	result[4];
	//test = dir;
						R_SampleCubeMap( test, width, buffers, result );
						total[0] += result[0];
						total[1] += result[1];
						total[2] += result[2];
					}
					outBuffer[(y*outSize+x)*4+0] = total[0] / samples;
					outBuffer[(y*outSize+x)*4+1] = total[1] / samples;
					outBuffer[(y*outSize+x)*4+2] = total[2] / samples;
					outBuffer[(y*outSize+x)*4+3] = 255;
				}
			}

			if ( map == 0 ) {
				sprintf( fullname, "env/%s_amb%s", baseName, extensions[i] );
			} else {
				sprintf( fullname, "env/%s_spec%s", baseName, extensions[i] );
			}
			common->Printf( "writing %s\n", fullname.c_str() );
			session->UpdateScreen();
			R_WriteTGA( fullname, outBuffer, outSize, outSize );
		}
	}

	for ( i = 0 ; i < 6 ; i++ ) {
		if ( buffers[i] ) {
			Mem_Free( buffers[i] );
		}
	}
}

//============================================================================


/*
===============
R_SetColorMappings
===============
*/
void R_SetColorMappings( void ) {
	int		i, j;
	float	g, b;
	int		inf;
	unsigned short gammaTable[256];

	b = r_brightness.GetFloat();
	g = r_gamma.GetFloat();

	for ( i = 0; i < 256; i++ ) {
		j = i * b;
		if (j > 255) {
			j = 255;
		}

		if ( g == 1 ) {
			inf = (j<<8) | j;
		} else {
			inf = 0xffff * pow ( j/255.0f, 1.0f / g ) + 0.5f;
		}
		if (inf < 0) {
			inf = 0;
		}
		if (inf > 0xffff) {
			inf = 0xffff;
		}

		gammaTable[i] = inf;
	}

	GLimp_SetGamma( gammaTable, gammaTable, gammaTable );
}


/*
================
GfxInfo_f
================
*/
static void GfxInfo_f( const idCmdArgs &args ) {
	const char *fsstrings[] =
	{
		"windowed",
		"fullscreen"
		"fsborderless"
	};

	common->Printf( "\nGL_VENDOR: %s\n", glConfig.vendor_string );
	common->Printf( "GL_RENDERER: %s\n", glConfig.renderer_string );
	common->Printf( "GL_VERSION: %s\n", glConfig.version_string );
	common->Printf( "GL_EXTENSIONS: %s\n", glConfig.extensions_string );
	common->Printf( "GL_MAX_TEXTURE_SIZE: %d\n", glConfig.maxTextureSize );
	common->Printf( "GL_MAX_TEXTURE_UNITS_ARB: %d\n", glConfig.maxTextureUnits );
	common->Printf( "GL_MAX_TEXTURE_COORDS_ARB: %d\n", glConfig.maxTextureCoords );
	common->Printf( "GL_MAX_TEXTURE_IMAGE_UNITS_ARB: %d\n", glConfig.maxTextureImageUnits );
	common->Printf( "\nPIXELFORMAT: color(%d-bits) Z(%d-bit) stencil(%d-bits)\n", glConfig.colorBits, glConfig.depthBits, glConfig.stencilBits );
	common->Printf( "MODE: %d, %d x %d %s hz:", r_mode.GetInteger(), glConfig.vidWidth, glConfig.vidHeight, fsstrings[r_fullscreen.GetInteger()] );

	if ( glConfig.displayFrequency ) {
		common->Printf( "%d\n", glConfig.displayFrequency );
	} else {
		common->Printf( "N/A\n" );
	}

	const char *active[2] = { "", " (ACTIVE)" };

	if ( r_finish.GetBool() ) {
		common->Printf( "Forcing glFinish\n" );
	} else {
		common->Printf( "glFinish not forced\n" );
	}

	bool tss = glConfig.twoSidedStencilAvailable;

	if ( !r_useTwoSidedStencil.GetBool() && tss ) {
		common->Printf( "Two sided stencil available but disabled\n" );
	} else if ( !tss ) {
		common->Printf( "Two sided stencil not available\n" );
	} else if ( tss ) {
		common->Printf( "Using two sided stencil\n" );
	}

	if ( vertexCache.IsFast() ) {
		common->Printf( "Vertex cache is fast\n" );
	} else {
		common->Printf( "Vertex cache is SLOW\n" );
	}
}

/*
=================
R_VidRestart_f
=================
*/
void R_VidRestart_f( const idCmdArgs &args ) {
	int	err;

	// if OpenGL isn't started, do nothing
	if ( !glConfig.isInitialized ) {
		return;
	}

	bool full = true;
	bool forceWindow = false;
	for ( int i = 1 ; i < args.Argc() ; i++ ) {
		if ( idStr::Icmp( args.Argv( i ), "partial" ) == 0 ) {
			full = false;
			continue;
		}
		if ( idStr::Icmp( args.Argv( i ), "windowed" ) == 0 ) {
			forceWindow = true;
			continue;
		}
	}

	// this could take a while, so give them the cursor back ASAP
	Sys_GrabMouseCursor( false );

	// dump ambient caches
	renderModelManager->FreeModelVertexCaches();

	// free any current world interaction surfaces and vertex caches
	R_FreeDerivedData();

	// make sure the defered frees are actually freed
	R_ToggleSmpFrame();
	R_ToggleSmpFrame();

	// free the vertex caches so they will be regenerated again
	vertexCache.PurgeAll();

	// sound and input are tied to the window we are about to destroy

	GLimp_ClearFrameBuffers(); // blendo eric: deletes old frame buffer sizes

	if ( full ) {
		// free all of our texture numbers
		soundSystem->ShutdownHW();
		Sys_ShutdownInput();
		globalImages->PurgeAllImages();
		// free the context and close the window
		GLimp_Shutdown();
		glConfig.isInitialized = false;

		// create the new context and vertex cache
		bool latch = cvarSystem->GetCVarBool( "r_fullscreen" ) == 1;
		if ( forceWindow ) {
			cvarSystem->SetCVarBool( "r_fullscreen", false );
		}
		R_InitOpenGL();
		cvarSystem->SetCVarBool( "r_fullscreen", latch );

		// regenerate all images
		globalImages->ReloadAllImages();
	} else {
		glimpParms_t	parms;
		if (r_mode.GetInteger() >= 0 && r_mode.GetInteger() < vidModesToShow.Num())
		{
			r_resolution.SetString(vidModesToShow[r_mode.GetInteger()]);
		}
		R_ValidateResolutionString(0);
		//R_GetModeInfo(&glConfig.vidWidth, &glConfig.vidHeight, r_mode.GetInteger());
		parms.width = glConfig.vidWidth;
		parms.height = glConfig.vidHeight;
		parms.fullScreen = (forceWindow) ? false : r_fullscreen.GetInteger() == 1;
		parms.borderless = (forceWindow) ? false : r_fullscreen.GetInteger() == 2;
		parms.displayHz = r_displayRefresh.GetInteger();
		parms.multiSamples = r_multiSamples.GetInteger();
		parms.stereo = false;
		GLimp_SetScreenParms( parms );

		// SM: Need to recreate current render image when changing resolution
		globalImages->currentRenderImage->PurgeImage();
		globalImages->currentRenderImage->Reload(true, true);
		renderSystem->UpdateScreenWidth();
		renderSystem->CaptureRenderToImage("_currentRender");
	}

	// make sure the regeneration doesn't use anything no longer valid
	tr.viewCount++;
	tr.viewDef = NULL;

	// regenerate all necessary interactions
	R_RegenerateWorld_f( idCmdArgs() );

	// check for problems
	err = qglGetError();
	if ( err != GL_NO_ERROR ) {
		common->Printf( "glGetError() = 0x%x\n", err );
	}

	// start sound playing again
	soundSystem->SetMute( false );
}


/*
=================
R_InitMaterials
=================
*/
void R_InitMaterials( void ) {
	tr.defaultMaterial = declManager->FindMaterial( "_default", false );
	if ( !tr.defaultMaterial ) {
		common->FatalError( "_default material not found" );
	}
	declManager->FindMaterial( "_default", false );

	// needed by R_DeriveLightData
	declManager->FindMaterial( "lights/defaultPointLight" );
	declManager->FindMaterial( "lights/defaultProjectedLight" );
}


/*
=================
R_SizeUp_f

Keybinding command
=================
*/
static void R_SizeUp_f( const idCmdArgs &args ) {
	if ( r_screenFraction.GetInteger() + 10 > 100 ) {
		r_screenFraction.SetInteger( 100 );
	} else {
		r_screenFraction.SetInteger( r_screenFraction.GetInteger() + 10 );
	}
}


/*
=================
R_SizeDown_f

Keybinding command
=================
*/
static void R_SizeDown_f( const idCmdArgs &args ) {
	if ( r_screenFraction.GetInteger() - 10 < 10 ) {
		r_screenFraction.SetInteger( 10 );
	} else {
		r_screenFraction.SetInteger( r_screenFraction.GetInteger() - 10 );
	}
}


/*
===============
TouchGui_f

  this is called from the main thread
===============
*/
void R_TouchGui_f( const idCmdArgs &args ) {
	const char	*gui = args.Argv( 1 );

	if ( !gui[0] ) {
		common->Printf( "USAGE: touchGui <guiName>\n" );
		return;
	}

	common->Printf( "touchGui %s\n", gui );
	session->UpdateScreen();
	uiManager->Touch( gui );
}

/*
=================
R_InitCvars
=================
*/
void R_InitCvars( void ) {
	// update latched cvars here
}

/*
=================
R_InitCommands
=================
*/
void R_InitCommands( void ) {
	cmdSystem->AddCommand( "MakeMegaTexture", idMegaTexture::MakeMegaTexture_f, CMD_FL_RENDERER|CMD_FL_CHEAT, "processes giant images" );
	cmdSystem->AddCommand( "sizeUp", R_SizeUp_f, CMD_FL_RENDERER, "makes the rendered view larger" );
	cmdSystem->AddCommand( "sizeDown", R_SizeDown_f, CMD_FL_RENDERER, "makes the rendered view smaller" );
	cmdSystem->AddCommand( "reloadGuis", R_ReloadGuis_f, CMD_FL_RENDERER, "reloads guis" );
	cmdSystem->AddCommand( "listGuis", R_ListGuis_f, CMD_FL_RENDERER, "lists guis" );
	cmdSystem->AddCommand( "touchGui", R_TouchGui_f, CMD_FL_RENDERER, "touches a gui" );
	cmdSystem->AddCommand( "screenshot", R_ScreenShot_f, CMD_FL_RENDERER, "takes a screenshot" );
	cmdSystem->AddCommand( "envshot", R_EnvShot_f, CMD_FL_RENDERER, "takes an environment shot" );
	cmdSystem->AddCommand( "makeAmbientMap", R_MakeAmbientMap_f, CMD_FL_RENDERER|CMD_FL_CHEAT, "makes an ambient map" );
	cmdSystem->AddCommand( "benchmark", R_Benchmark_f, CMD_FL_RENDERER, "benchmark" );
	cmdSystem->AddCommand( "gfxInfo", GfxInfo_f, CMD_FL_RENDERER, "show graphics info" );
	cmdSystem->AddCommand( "modulateLights", R_ModulateLights_f, CMD_FL_RENDERER | CMD_FL_CHEAT, "modifies shader parms on all lights" );
	cmdSystem->AddCommand( "testImage", R_TestImage_f, CMD_FL_RENDERER | CMD_FL_CHEAT, "displays the given image centered on screen", idCmdSystem::ArgCompletion_ImageName );
	cmdSystem->AddCommand( "testVideo", R_TestVideo_f, CMD_FL_RENDERER | CMD_FL_CHEAT, "displays the given cinematic", idCmdSystem::ArgCompletion_VideoName );
	cmdSystem->AddCommand( "reportSurfaceAreas", R_ReportSurfaceAreas_f, CMD_FL_RENDERER, "lists all used materials sorted by surface area" );
	cmdSystem->AddCommand( "reportImageDuplication", R_ReportImageDuplication_f, CMD_FL_RENDERER, "checks all referenced images for duplications" );
	cmdSystem->AddCommand( "regenerateWorld", R_RegenerateWorld_f, CMD_FL_RENDERER, "regenerates all interactions" );
	cmdSystem->AddCommand( "showInteractionMemory", R_ShowInteractionMemory_f, CMD_FL_RENDERER, "shows memory used by interactions" );
	cmdSystem->AddCommand( "showTriSurfMemory", R_ShowTriSurfMemory_f, CMD_FL_RENDERER, "shows memory used by triangle surfaces" );
	cmdSystem->AddCommand( "vid_restart", R_VidRestart_f, CMD_FL_RENDERER, "restarts renderSystem" );
	cmdSystem->AddCommand( "listRenderEntityDefs", R_ListRenderEntityDefs_f, CMD_FL_RENDERER, "lists the entity defs" );
	cmdSystem->AddCommand( "listRenderLightDefs", R_ListRenderLightDefs_f, CMD_FL_RENDERER, "lists the light defs" );
	cmdSystem->AddCommand( "listModes", R_ListModes_f, CMD_FL_RENDERER, "lists all video modes" );
	cmdSystem->AddCommand( "reloadSurface", R_ReloadSurface_f, CMD_FL_RENDERER, "reloads the decl and images for selected surface" );
}

/*
===============
idRenderSystemLocal::Clear
===============
*/
void idRenderSystemLocal::Clear( void ) {
	registered = false;
	frameCount = 0;
	viewCount = 0;
	staticAllocCount = 0;
	frameShaderTime = 0.0f;
	viewportOffset[0] = 0;
	viewportOffset[1] = 0;
	tiledViewport[0] = 0;
	tiledViewport[1] = 0;
	backEndRenderer = BE_BAD;
	backEndRendererHasVertexPrograms = false;
	backEndRendererMaxLight = 1.0f;
	ambientLightVector.Zero();
	sortOffset = 0;
	worlds.Clear();
	primaryWorld = NULL;
	memset( &primaryRenderView, 0, sizeof( primaryRenderView ) );
	primaryView = NULL;
	defaultMaterial = NULL;
	testImage = NULL;
	ambientCubeImage = NULL;
	viewDef = NULL;
	memset( &pc, 0, sizeof( pc ) );
	memset( &lockSurfacesCmd, 0, sizeof( lockSurfacesCmd ) );
	memset( &identitySpace, 0, sizeof( identitySpace ) );
	stencilIncr = 0;
	stencilDecr = 0;
	memset( renderCrops, 0, sizeof( renderCrops ) );
	currentRenderCrop = 0;
	guiRecursionLevel = 0;
	guiModel = NULL;
	demoGuiModel = NULL;
	takingScreenshot = false;
	useBlendoAmbience = true;
	portalSkyEnabled = false;
	portalSkyOrigin = vec3_zero;
	portalSkyViewShiftScale = vec2_zero;
}

/*
===============
idRenderSystemLocal::Init
===============
*/
void idRenderSystemLocal::Init( void ) {
	// clear all our internal state
	viewCount = 1;		// so cleared structures never match viewCount
	// we used to memset tr, but now that it is a class, we can't, so
	// there may be other state we need to reset

	ambientLightVector[0] = 0.5f;
	ambientLightVector[1] = 0.5f - 0.385f;
	ambientLightVector[2] = 0.8925f;
	ambientLightVector[3] = 1.0f;

	memset( &backEnd, 0, sizeof( backEnd ) );

	R_InitCvars();

	R_InitCommands();

	guiModel = new idGuiModel;
	guiModel->Clear();

	demoGuiModel = new idGuiModel;
	demoGuiModel->Clear();

	R_InitTriSurfData();

	globalImages->Init();

	idCinematic::InitCinematic( );

	R_InitMaterials();

	renderModelManager->Init();

	// set the identity space
	identitySpace.modelMatrix[0*4+0] = 1.0f;
	identitySpace.modelMatrix[1*4+1] = 1.0f;
	identitySpace.modelMatrix[2*4+2] = 1.0f;
}

/*
===============
idRenderSystemLocal::Shutdown
===============
*/
void idRenderSystemLocal::Shutdown( void ) {
	common->DPrintf( "idRenderSystem::Shutdown()\n" );

	common->SetRefreshOnPrint( false ); // DG: without a renderer there's nothing to refresh

	R_DoneFreeType( );

	// SM reset the fonts when we shutdown so reloadEngine doesn't crash
	ResetFonts();

	if ( glConfig.isInitialized ) {
		globalImages->PurgeAllImages();
	}

	renderModelManager->Shutdown();

	idCinematic::ShutdownCinematic( );

	globalImages->Shutdown();

	// free frame memory
	R_ShutdownFrameData();

	// free the vertex cache, which should have nothing allocated now
	vertexCache.Shutdown();

	R_ShutdownTriSurfData();

	RB_ShutdownDebugTools();

	delete guiModel;
	delete demoGuiModel;

	Clear();

	ShutdownOpenGL();
}

/*
========================
idRenderSystemLocal::BeginLevelLoad
========================
*/
void idRenderSystemLocal::BeginLevelLoad( void ) {
	renderModelManager->BeginLevelLoad();
	globalImages->BeginLevelLoad();
}

/*
========================
idRenderSystemLocal::EndLevelLoad
========================
*/
void idRenderSystemLocal::EndLevelLoad( void ) {
	renderModelManager->EndLevelLoad();
	globalImages->EndLevelLoad();
	if ( r_forceLoadImages.GetBool() ) {
		RB_ShowImages();
	}
}

/*
========================
idRenderSystemLocal::InitOpenGL
========================
*/
void idRenderSystemLocal::InitOpenGL( void ) {
	// if OpenGL isn't started, start it now
	if ( !glConfig.isInitialized ) {
		int	err;

		R_InitOpenGL();

		globalImages->ReloadAllImages();

		err = qglGetError();
		if ( err != GL_NO_ERROR ) {
			common->Printf( "glGetError() = 0x%x\n", err );
		}
	}
}

/*
========================
idRenderSystemLocal::ShutdownOpenGL
========================
*/
void idRenderSystemLocal::ShutdownOpenGL( void ) {
	// free the context and close the window
	R_ShutdownFrameData();
	GLimp_Shutdown();
	glConfig.isInitialized = false;
}

/*
========================
idRenderSystemLocal::IsOpenGLRunning
========================
*/
bool idRenderSystemLocal::IsOpenGLRunning( void ) const {
	if ( !glConfig.isInitialized ) {
		return false;
	}
	return true;
}

/*
========================
idRenderSystemLocal::IsFullScreen
========================
*/
bool idRenderSystemLocal::IsFullScreen(void) const {
	return glConfig.isFullscreen;
}

/*
========================
idRenderSystemLocal::IsBorderless
========================
*/
bool idRenderSystemLocal::IsBorderless(void) const {
	return glConfig.isBorderless;
}

/*
========================
idRenderSystemLocal::GetScreenWidth
========================
*/
int idRenderSystemLocal::GetScreenWidth( void ) const {
	return glConfig.vidWidth;
}

/*
========================
idRenderSystemLocal::GetScreenHeight
========================
*/
int idRenderSystemLocal::GetScreenHeight( void ) const {
	return glConfig.vidHeight;
}

bool idRenderSystemLocal::UseBlendoAmbience() const {
	return r_useBlendoAmbience.GetBool();
}


float idRenderSystemLocal::GetBlendoAmbienceScale() const
{
	return useBlendoAmbience ? r_blendoAmbienceScale.GetFloat() : 0.0f;
}

/*
// blendo eric: gets set in playerview, used in subviews
=====================
idRenderWorldLocal::PortalSkyViewParams
=====================
*/
void idRenderWorldLocal::SetPortalSkyParams(bool enabled, idVec3 orig, idVec2 shiftScale)
{
	tr.portalSkyEnabled = enabled;
	tr.portalSkyOrigin = orig;
	tr.portalSkyViewShiftScale = shiftScale;
}
