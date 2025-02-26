//TODO:

//blood decals: grow to size?

//hands that appear when clambering.

//Bouncing grenade? Bouncy balls

//Don't update sticky placer when player is dead.

//Lean on wall - show hand on wall

//MMB hold to throw manual aim arc

//Play "skin deep" audio cue when entering new map.

//Placer ent: draw a placer marker when you're jsut outside of placement threshold distance.

//Spit and or sneeze to propel in outer space.

//Sneezevalue : make it float so we have more control over its increase rate.

//3D compass when in zero g.

// Turn off placement ui when in lean mode.

//Big ammo box that shoots out bullets when shot

//Floor vents to crawl through.

//ACID: use milk to neutralize.

//Heartbeat sonar: let baddies use it, have a chargeup time before it activates.

//sticky placement ui: show error message if cannot place

//Make glass not glow in the dark

//Lighter: cannot ignite without oxygen.

//Dashing: do a little camera ducking movement.

//Make viewangle tilt back to normal when blood is entering body.

//add blood fountain on headshot.

//Salvage from enemy shoulder lamps?

//Fix rack state between different weapons.

//FIND a way to lock body angle to a specific angle, for healing animations.

//Healing: only next to walls????

//Fix MD5 batch exporter to export the glasspluck anim frame range correctly.

//Show hands when clambering.

//hallucination grenade

//heal grenade

//bad breath: alerts baddies. Eat Dental Goo to ameliorate.

//Need to regularly check in with your handler, report resting heart rate and whether you're mission-ready

//Make loud hushnoises feel louder

//Camo in algae ??

//Spit in hyperspace: do 1 damage

//Allow player to select jumpsuit color

//Weapon: hack gun. Hacks turrets, makes robots friendly, makes buttons explode. Hack gun is recharged in wall sockets.

//Cloaking ability. Go invisible.

//Wall sockets: recharges things. Can be shot to do an electrical shock radius effect.

//Linen feathers: make you sneeze


//RadiusDamage: have a different radius for players vs. monsters

//Mechcannon worldmodel: add a blinking FLARE light.
//Drop mecah cannon when done with it / switch to other weapon


//Fix glass1_plain so it looks better

//Let you pick up glass

//Final shot of a magazine: does 4x extra damage.

//Spearbot: fix death state.

//Wound text: make it more localization friendly

//AI: be invisible to enemy when crouching under something...

//Laser off when AI is in idle state.

//Downed state: drop the mechcannon
//Mechcannon: have it be thrown a shorter distance?

//Water - creates puddles that people can slip on.

//Repairbot: have different sound/beam fx when it is slow-repairing vs fast repairing.

//AI: slower bullets.
//AI: DOWNEd STATE
//AI : worse vision at far distance.
//AI: if enemy is spotted above or below, then lock every ai in that direction for a while.
//AI: damage/accuracy based on whether is moving/still & how many bones are visible to enemy.
//AI: short delay between hearing noise and becoming suspicious of it.
//AI: searchnode getSearchNode() : bias it to go forward, avoid monster doing a 180.
//AI: searchnode network - have searchnodes be grouped up into a team network.
//AI: if moving AWAY from ai or NOT LOOKING at ai, then reduce the ai accuracy / take less damage / don't get downed
//AI: prevent gun getting stuck in corpse
//AI: coordinate all AI to stop search state at the same time.
//AI: use CheckSearchLook() to do suppressing fire.
//AI: more damage on back and and on head. show damage HEADSHOT And BACKSTAB markers.

//COMBATMANAGER:
//Track time since anyone last saw the player. Use this timer to determine when everyone calls off the search.


//Zero g movement - use air.

//Player inventory system.: item types, ala farcry2?

//Repairbot: normalize repair speed

//options: add click sound fx to the sliderbar.
//option: show a sample image when adjusting brightness.
//option: photo mode.

//Add camera snap sound fx to screenshot button

//Gameplay modifiers: gravity, infinite ammo, etc.
//Render modifiers: black and white, pixel mode, etc.

//Electricity pipe: shoots electric bolts

//Frob: do a wide trace search as last resort.

//Rifle: make the muzzle spin.

//Soundmeter: show timeline for when loud noise begins/ends


//make xhair icon crossed-out when you can't pick up more armor.



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
#include "framework/async/NetworkSystem.h"
#include "framework/DeclEntityDef.h"
#include "framework/KeyInput.h"
#include "renderer/RenderSystem.h"
#include "renderer/ModelManager.h"

#include "gamesys/SysCvar.h"
#include "script/Script_Thread.h"
#include "ai/AI.h"
#include "WorldSpawn.h"
#include "Player.h"
#include "Camera.h"
#include "Fx.h"
#include "Mover.h"
#include "Misc.h"
#include "SmokeParticles.h"
#include "BrittleFracture.h"

#include "bc_doorbarricade.h"
#include "bc_maintpanel.h"
#include "bc_wallspeaker.h"
#include "bc_frobcube.h"
#include "bc_keypad.h"
#include "bc_spectatetimeline.h"
#include "bc_trashexit.h"
#include "bc_catcage.h"
#include "bc_aloe.h"
#include "bc_cat.h"
#include "bc_airlock.h"
#include "bc_beaconlogic.h"
#include "bc_lifeboat.h"
#include "bc_ftl.h"
#include "bc_meta.h"
#include "bc_mech.h"
#include "bc_lever.h"
#include "bc_acropoint.h"
#include "bc_spearprojectile.h"
#include "bc_ventpeek.h"
#include "bc_trigger_confinedarea.h"
#include "bc_ventdoor.h"
#include "bc_gunner.h"
#include "bc_cryointerior.h"
#include "bc_cryospawn.h"
#include "bc_trashchute.h"
#include "SecurityCamera.h"
#include "bc_electricalbox.h"
#include "bc_skullsaver.h"
#include "bc_interestpoint.h"
#include "bc_camerasplice.h"
#include "bc_notewall.h"
#include "bc_tablet.h"
#include "bc_dynatip.h"
#include "bc_radiocheckin.h"
#include "ui/UserInterfaceLocal.h"
#include "ui/Window.h"
#include "framework/Session.h"

const int ASYNC_PLAYER_INV_AMMO_BITS = idMath::BitsForInteger( 999 );	// 9 bits to cover the range [0, 999]
const int ASYNC_PLAYER_INV_CLIP_BITS = -7;								// -7 bits to cover the range [-1, 60]
/*
===============================================================================

	Player control of the Doom Marine.
	This object handles all player movement and world interaction.

===============================================================================
*/

const float GUI_ACTIVATIONRANGE = 80.0f;


// distance between ladder rungs (actually is half that distance, but this sounds better)
const int LADDER_RUNG_DISTANCE = 32;

// amount of health per dose from the health station
const int HEALTH_PER_DOSE = 10;

// time before a weapon dropped to the floor disappears
const int WEAPON_DROP_TIME = 20 * 1000;

// time before a next or prev weapon switch happens
const int WEAPON_SWITCH_DELAY = 150;

// how many units to raise spectator above default view height so it's in the head of someone
const int SPECTATE_RAISE = 25;

const int HEALTHPULSE_TIME = 333;

// minimum speed to bob and play run/walk animations at
const float MIN_BOB_SPEED = 5.0f;




//BC Constants.
const int CONTEXTMENU_DELAYTIME = 100; //A little delay before the context menu can be reactivated.
const int CONTEXTMENU_FLASHTIME = 100; //When contextmenu is doing confirm flash anim, how long until contextmenu can be reactivated.

const int VIEWPOS_OFFSET_MOVETIME = 250;

const int LEAN_MAX_X = 50; //amount you can lean left/right
const int LEAN_MAXROLL = 10;
const int LEAN_MAX_Y = 20; //amount you can lean up/down
const int LEAN_MAX_Y_LEANFORWARD = 40; //amount you can lean up/down when leaning forward
const int LEAN_LEANFORWARD_THRESHOLD = 60; //pitch angle at which we enter lean-forward mode.
const int LEAN_FOV = 85;
const int LEAN_ZOOMINTIME = 500;
const float LEAN_CONTROLSENSITIVITY = .08f;
const int LEAN_RESETTIME = 250;
const int LEAN_HEAD_RADIUS = 6;
const float LEAN_SENSITIVITY_SCALAR = 10.0f; //scales how sensitive/granular the lean sensitivity is.

const int CONFINED_VIEWARC = 160;
const int CONFINED_UPDATETIME = 200;

const float FROB_DISTANCE = 112;
const float FROB_DISTANCE_ACROPOINT = 144; //special distance for acropoints.

const int TELEPORTCROUCH_EASE_TIME = 33; // transition time after teleporting into a crouch

//For sticky weapons, how far can your arms reach to attach a thing to a surface.
const float PLACER_DISTANCE_UPWARD = 60;
const float PLACER_DISTANCE_DOWNWARD = 65;
const int PLACER_BOUNDSIZE = 4;


const float AUTOAIM_MAXDISTANCE = 1024;		//max distance autoaim can acquire targets.
const int AUTOAIM_SCORE_THRESHOLD = 850;

const int AUTOAIM_DOT_IDLEDISTANCE = 48;	//ring size when no target.
const float AUTOAIM_DOT_LOCKDISTANCE = 4;	//ring size when locked onto target.
const float AUTOAIM_DOT_FLASHDISTANCE = 12;	//ring size when acquiring new target.
const int AUTOAIM_DOT_MOVETIME = 200;		//how long dots take to move to new target.
const int AUTOAIM_DOT_MOVETIME_IDLE = 300;	//how long dots take to move to idle position.
const float AUTOAIM_DOT_DIAGSCALE = .8f;	//controls how circular ring is.
const int AUTOAIM_DOT_FLASHTIME = 100;		//how long the target acquisition animation is.
const int AUTOAIM_DOT_BIGSIZE = 384;			//size of autoaim when idle
const int AUTOAIM_DOT_SMALLSIZE = 16;			//size of autoaim when lockon

const int RELOADBUTTON_THRESHOLDTIME = 200;	//how long reload button held to become check-mag function.


const float CONDITION_BURNING_TIME = 10000; //how long does burning condition last.
const int CONDITION_BURNING_WOUNDS_PER_TIME = 1000; //Clamp how many wounds you can get per X milliseconds.

const int CONDITION_GLASSWOUND_MAXWOUNDS = 3;
const int CONDITION_GLASSWOUND_DAMAGEINTERVAL = 400;


const int CONDITION_BULLETWOUND_MAXWOUNDS = 3; //Max amount of bulletwounds you can have.
const int CONDITION_BULLETWOUND_PER_TIME = 300; //Clamp how many bullet wounds you can get per X milliseconds.



const float HEALTH_RECHARGE_INITIALDELAY = 3000; //How long does the player have to remain damage-free in order for health to begin its recharge.
const int HEALTH_RECHARGE_TICKTIME = 10;
const int HEALTH_RECHARGE_HEALTHPERTICK = 1;
const int HEALTH_PER_HEALTHBARBLOCK = 10;
const int HEALTH_BLOODBAG_RECHARGEPERTICK = 1;
const int HEALTH_BLOODBAG_RECHARGERATE = 50;
const int HEALTH_BLOODBAG_DEFAULTHEALTH = 40; //40
const int HEALTH_MUSHROOMMAXCOUNT = 2;
const int HEALTH_BLOODBAG_STARTINGAMOUNT = 0;
const int HEALTH_RECHARGE_INITIALDELAY_SHRAPNELWOUND = 12000;
const int HEALTH_BLOODBAG_ANIMATION_ACTIVATIONTIME = 1600;


const int HEALTHBAR_FADE_DELAYTIME = 6000; //how long to show max healthbar before it fades away.
const int HEALTHBAR_SEGMENTS = 5; //how many pips are in the health bar.
const int HEALTHBAR_DAMAGE_FLASHTIME = 200;

//const int FTL_MOVESPEED_MULTIPLIER = 4.0f;
//const float HEALING_MOVESPEED_MULTIPLIER = 0.5f;
const float HEALING_MOVESPEED = 40;



const int DAMAGEARROW_MAXTIME = 3000;



const int FROB_FLASHTIME = 250;
const int FROB_TRACESIZE = 4; //If frob traceline check fails, do a broader tracebounds check. This is radius of tracebound.
const int FROB_TRACESIZE_AIRLESS = 12; //When in outer space, do a broader trace check to make it easier to frob things.
const float FROB_HOLD_TIME = 300; // How many milliseconds counts as a hold, for entities which are isFrobHoldable


const int SNEEZE_MAXVALUE = 100;
const float SNEEZE_GROWRATE_MULTIPLIER = 0.05f; //.3
const int SNEEZE_RANDOMCHANCE = 6; //random chance 1 out of X that you will increase sneezemeter when standing still.
const float SNEEZE_PEPPER_RATE = 9.0f;

const int	DOWNED_TICKTIME = 400; //when bleeding out, wait this much ms between bleedout DOT damage.
const float DOWNED_VIEWANGLE_ROLL = 4;
const float	DOWNED_TICKTIME_MULTIPLIER_LOWHEALTH = 1.5f;		//slow down bleedout rate when meter is low.
const float	DOWNED_TICKTIME_MULTIPLIER_CRITICALHEALTH = 3.5f;	//slow down bleedout rate DRAMATICALLY when meter is extremely low.

const int SAVINGTHROW_SAVETIME = 700; //how many seconds does saving throw invincibility last.
const int SAVINGTHROW_RESETTIME = 15000; //savingthrow cooldown reset time. After savingthrow happens, how long before it can be used again.
const float SAVINGTHROW_ANGLETHRESHOLD = .6f; //saving throw only happens for things NOT in front of player. Make this number HIGHER to be more lenient to player.

const int HEARTRATE_FASTEST = 400;
const int HEARTRATE_SLOWEST = 1200;
const int HEARTRATE_LOWHEALTH = 20;
const int HEARTRATE_HIGHHEALTH = 60;

const int GRENADE_THROW_HOLDTIME = 80; //if you hold button longer than this much milliseconds, will draw the grenade throw arc.

const int BUTTONPROMPT_DISPLAYTIME = 2500;

const int CHEM_LOWDAMAGE_TIME = 1500; //how long you can stay in chem puddle and take low damage.
const int CHEM_HIGHDAMAGE_MULTIPLIER = 10; //how much to multiply chem damage for staying in puddle for too long.

const int MECH_MOVETOBEHIND_TIME = 500;
const int MECH_ENTERING_TIME = 400;
const int MECH_VIEW_OFFSET = 16;
const int MECH_STARTUPTIME = 1800;

const int	BEACON_FLASHTIME = 1500; //make sure this matches the FLASHTIME value in weapon_signallamp.script
const int	BEACON_BLINKTIME = 75; //how fast to make the beacon ui blink when it's confirmed.
const int	BEACON_SPAWNOFFSET = 128; //how far away from wall to spawn.
const int	BEACON_LINGERTIME = 4000; //how long to make the beacon cross stay onscreen after leaving lockon.
const int	BEACON_SIGNAL_UPDATE_INTERVAL = 70; // How frequently we update the signal strength.
const float	BEACON_SIGNAL_STRENGTH_THRESHOLD = 0.90f; // Signal strength needs to be higher than this to 'lock on'. 0.0 - 1.0. Make this number lower to be more lenient.
const int	BEACON_SIGNAL_RESETTIME = 1500; // How long without any activity before we reset the code.
const float BEACON_PITCH_CORRECTION_THRESHOLD = 0.95f; // Used to decide when to put in the little 'look up/look down' arrows.

const int BEACON_DASH_LENGTH = 300; // How long the player needs to hold down the fire button to register as a 'dash' instead of a 'dot'
const char DOT = '.';
const char DASH = '_';
const char* BEACON_SIGNALCODE_EXTRACTION = "._."; // The code the player should enter for a lifeboat extraction
//const char* BEACON_SIGNALCODE_SHOP = "._."; // The code the player should enter for shop boat




const int ENEMYHEALTHBAR_HEIGHT = 8; //how tall is enemy health bar.
const int ENEMYHEALTHBAR_PIPWIDTH = 3;
const int ENEMYHEALTHBAR_HEIGHTOFFSET = 4; //how far above head do we draw enemy health bar. This is world space, not pixel space.
const float ENEMYHEALTHBAR_GAPSIZE = .8f; //gap between pips

const int SHIELD_SIZE = 7;


const int SHIELD_SIZE_X = 7;
const int SHIELD_SIZE_Y = 9;



const int SUSPICIONARROW_SIZE = 128;
const int SUSPICIONARROW_DIST = 96;


const float MELEETARGET_DISTANCE = 96;

const int CARRYABLE_MELEE_DISTANCE = 50;
const int CARRYABLE_MELEE_DISTANCE_MOVING = 80;
const int CARRYABLE_MELEE_TIME = 200;
const int CARRYABLE_MELEE_ANIMATIONTIME = 600;
const int CARRYABLE_USE_MELEE_TIMETHRESHOLD = 300;


const int SMELLY_SPAWNTIME = 1000; //spawn a smell cloud every xx milliseconds.
const int SMELLY_PURGERADIUS = 96;

const int TURNINGDELTA_SOUNDTHRESHOLD = 2;

const float VENTPEEK_TURNING_SOUNDTHRESHOLD = 30.0f; // default number of degrees to turn in order to trigger a turning sound
const int VENTPEEK_TURNING_SOUNDDELAY = 2000; // default wait between making sounds

const int LISTENMODE_HEAD_RADIUS = 11; //make this larger than the lean_head_radius, to prevent state thrashing
const int LISTENMODE_AUDIOMUFFLE = -30; //for when listening through doors, muffle all other sounds.
const int LISTENMODE_FOOTSTEPVOLUME = 20;
const int LISTENMODE_METERTIME = 900; //how long you have to smush your ear against a door.
const int LISTENMODE_PROBEUPDATETIME = 500;


//lightmeter ranges from 0.0 to 1.0
const float LIGHTMETER_DARKTHRESHOLD = .34f; //if AT or BELOW this, then player is in darkness.
const float LIGHTMETER_LIGHTTHRESHOLD = .68f; //if AT or ABOVE this, then player is in light.

const float LIGHTMETER_SHADOWY_THRESHOLD = 0;

const int DEFIB_ELECTROBLAST_RADIUS = 512; //When defib, do a shock blast around the player.

const int WEAPONSELECT_PAUSETIME = 700;


const int LEAN_CARRYABLE_HIDETIME = 40; //when leaning, make the carryable item hide in xx ms
const int LEAN_CARRYABLE_DISTANCE = -14; //when leaning, make the carryable move away xx units to hide itself


const int SLOTS_AVAILABLE_AT_START = 5; //How many inventory 'pocket' slots are available at game start.

//zoom mode variables
#define ZOOM_MAX				70
#define ZOOM_MIN				15
#define ZOOM_STEP				28
// How much to scale the mouse look by when fully zoomed in
const float ZOOM_MOUSE_SCALE = 0.05f;
const int ZOOM_LERPTIME = 80; //duration of milliseconds to do the zoom activation lerp
const int ZOOM_HOLDTIME_THRESHOLD = 300; //how long to hold zoom button before it enters zoom mode


const int FLYTEXT_FLYTIME = 2000;

const int ARMSTAT_RAISETIME = 500;
const int ARMSTAT_LOWERTIME = 300;

const int OXYGENMETER_FADEDELAY = 3000; //delay before oxygen meter fades out.
const int OXYGENMETER_PAUSETIME = 2000; //when maxed out, how long to pause before depleting again. We pause it to make the full-air-tank more readable.

const int GASCLOUD_DURATION_TIME = 7000; //when hit by landmine gas cloud, how long is coughing fit.

const int INSPECTION_LERPTIME = 100; //when inspecting item, how fast does lerp transition happen
const int INSPECTION_LERPTIME_WEAPON = 200; //weapons need some time for the animation to play, so this transition time is longer.

const int LIFEBOAT_LOCATOR_DISTANCETHRESHOLD = 192; //distance at which lifeboat locator triangle hides itself (we don't want to see if it player is close to lifeboat)

const int AI_THROWABLEDODGE_DISTANCETHRESHOLD = 48; //how close does throwing arc have to be to AI to trigger dodge behavior.


const int JOCKEY_PIPINTERVAL = 500;
const int JOCKEY_DIAMOND_RADIUS = 256; //radius at which we draw the helper diamond icon on kill-entities
const int JOCKEY_KICKPLAYEROFF_FORCE = 256; //When player is pushed off during jockey, how much force to apply to player
const float JOCKEY_STAMINA_FREEAMOUNT = .333f; //Always replenish player to a minimum amount of stamina when jockey starts, in case player has zero stamina.

#define JOCKEY_DEFAULTSTAMINADRAIN  "-2.0"
#define STAMINABAR_HIDEDELAYTIME 5000
#define STAMINABAR_THROW_TIMEINTERVAL 100 //time interval that stamina depletes when in throw aim slow-mo mode.


#define DODGE_DOTTHRESHOLD  -.7f //AI will dodge items thrown directly at the front of them. -1.0 = directly front. 0 = side. 1.0 = back.

const int FALLENSTATE_INITIALPITCH = -20;
const int FALLEN_ROLL_TIME = 500; //when fallen, how long roll takes

const int KNOCKDOWN_ROLLSPEED = 250;
const int KNOCKDOWN_FORWARDSPEED = 30;

const float PLAYERLOOK_TRIGGER_DIST = 3000.0f;

const float DROP_ITEM_THROWARC_DISTANCE = 80;

const int ZOOMINSPECT_LERPTIME = 300;
const float ZOOMINSPECT_MINIMUMSIZE = 20;
const float ZOOMINSPECT_MOVEMENTSPEED_MULTIPLIER = .3f;

const int CHAMBERINSPECT_VO_DELAYTIME = 500;
const int MAGINSPECT_VO_DELAYTIME = 300;


const int	PICKPOCKET_RANGE = 160;			//max range you can be when pickpocketing.
const float PICKPOCKET_FAR_THRESHOLD = .6f; //when this far, show the 'get closer' warning. This is a fraction of PICKPOCKET_RANGE
const int	PICKPOCKET_PIPMAX = 60;
const int	PICKPOCKET_PIPINTERVAL = 100;

//The different wound types.
#define WOUNDIDX_BURN		0
#define WOUNDIDX_GLASS		1
#define WOUNDIDX_BULLET		2
#define WOUNDIDX_SHRAPNEL	3
#define WOUNDIDX_SPEAR		4
//NOTE: make sure this matches the amount defined in WOUNDCOUNT_MAX in player.h

#define NUDGEENT_PROXIMITYRADIUS 160 //if player is xx close to certain objects, then don't do space nudge. i.e. cat evac pod.

#define MEMORYPALACE_DISTANCETHRESHOLD 32 //if player walks away from memory palace XX distance, then close memory palace



const int ITEMINSPECT_YAW_MAXDISTANCE = 30;
const int ITEMINSPECT_PITCH_MAXDISTANCE = 20;

const int MAP_HOLDTIME_THRESHOLD = 300; //if player holds down tab, then do the map.




//This is the name of the persistentLevelInfo variable for how far the player is in the campaign.
#define PERSISTVAR_LEVELPROGRESS "levelProgressIndex"
#define PERSISTVAR_NEXTMAP "nextMap"


#define EMAILFULLSCREEN_LERPTIME 300

const int DF_ZOOMINTIME = 1300;
const int DF_VIDEOTIME = 4600;
const int DF_MAXHEIGHT = 160;
const int DF_FADETIME = 200;
const int DF_ZOOMOUTTIME = 700;
const int DF_CAMERAPITCH_ZOOMOUTMIDPOINT = 40;	//when in defib camera, pitch of camera between the zoomout & zoomintohead
const int DF_CAMERA_FOV = 100;					//fov of defib camera.
const int DF_BUTTONPIPS = 60;					//how many pips does the player need to hold down the defib button to activate it.
const int DF_BUTTONTICKINTERVAL = 20;			//ticks between detecting defib button hold.
const int DF_ORGANS_MOVETIME = 300;

#define	SPECTATE_EXITHOLDTIME 900 //how long button is held to restart level.
#define	SPECTATE_LOADBUTTONTIME 500 //how long button is tapped to load game. make sure this number is smaller than SPECTATE_EXITHOLDTIME

//BC Constants end.

//Make sure this list retains parity with the list in file HUD.GUI
enum	{	LEGEND_NONE,		//0
			LEGEND_GUN,			//1
			LEGEND_THROWMODE,	//2 in aim mode, throwing something
			LEGEND_GRENADE,		//3
			LEGEND_CARRYABLE,	//4
			LEGEND_SIGNALLAMP,	//5
			LEGEND_VENTPEEK,	//6
			LEGEND_JOCKEY,		//7
			LEGEND_TELESCOPE,	//8
			LEGEND_WRISTMAP,	//9
		};



//================================ END CONSTANTS ================================


const idEventDef EV_Player_GetButtons( "getButtons", NULL, 'd' );
const idEventDef EV_Player_GetMove( "getMove", NULL, 'v' );
const idEventDef EV_Player_GetViewAngles( "getViewAngles", NULL, 'v' );
const idEventDef EV_Player_StopFxFov( "stopFxFov" );
const idEventDef EV_Player_EnableWeapon( "enableWeapon" );
const idEventDef EV_Player_DisableWeapon( "disableWeapon" );
const idEventDef EV_Player_GetCurrentWeapon( "getCurrentWeapon", NULL, 's' );
const idEventDef EV_Player_GetPreviousWeapon( "getPreviousWeapon", NULL, 's' );
const idEventDef EV_Player_SelectWeapon( "selectWeapon", "s" );
const idEventDef EV_Player_GetWeaponEntity( "getWeaponEntity", NULL, 'e' );
const idEventDef EV_Player_OpenPDA( "openPDA" );
const idEventDef EV_Player_InPDA( "inPDA", NULL, 'd' );
const idEventDef EV_Player_ExitTeleporter( "exitTeleporter" );
const idEventDef EV_Player_StopAudioLog( "stopAudioLog" );
const idEventDef EV_Player_HideTip( "hideTip" );
const idEventDef EV_Player_LevelTrigger( "levelTrigger" );
const idEventDef EV_SpectatorTouch( "spectatorTouch", "et" );
#ifdef _D3XP
const idEventDef EV_Player_GiveInventoryItem( "giveInventoryItem", "s" );
const idEventDef EV_Player_RemoveInventoryItem( "removeInventoryItem", "s" );
const idEventDef EV_Player_GetIdealWeapon( "getIdealWeapon", NULL, 's' );
const idEventDef EV_Player_SetPowerupTime( "setPowerupTime", "dd" );
const idEventDef EV_Player_IsPowerupActive( "isPowerupActive", "d", 'd' );
const idEventDef EV_Player_WeaponAvailable( "weaponAvailable", "s", 'd');
const idEventDef EV_Player_StartWarp( "startWarp" );
const idEventDef EV_Player_StopHelltime( "stopHelltime", "d" );
const idEventDef EV_Player_ToggleBloom( "toggleBloom", "d" );
const idEventDef EV_Player_SetBloomParms( "setBloomParms", "ff" );
#endif

//BC
const idEventDef EV_Player_SetGlasswoundHeal("SetGlasswoundHeal");
const idEventDef EV_Player_AddGlassWound("AddGlassWound");
const idEventDef EV_Player_GetGlasswounds("GetGlasswounds", NULL, 'd');
const idEventDef EV_Player_GetBulletwounds("GetBulletwounds", NULL, 'd');
const idEventDef EV_Player_GetShrapnelwounds("GetShrapnelwounds", NULL, 'd');
const idEventDef EV_Player_SetArmVisibility("SetArmVisibility", "d");
const idEventDef EV_Player_SetViewLock("SetViewLock", "dff");
const idEventDef EV_Player_SetViewPitchLock("SetViewPitchLock", "dff");
const idEventDef EV_Player_SetBodyAngleLock("SetBodyAngleLock", "d");
const idEventDef EV_Player_SetBurningHeal("SetBurningHeal");
const idEventDef EV_Player_Teleport("Teleport", "v");
const idEventDef EV_Player_TeleportToEnt("TeleportToEnt", "e");
const idEventDef EV_Player_getPlacerAngle("getPlacerAngle", NULL, 'v');
const idEventDef EV_Player_getPlacerPos("getPlacerPos", NULL, 'v');
const idEventDef EV_Player_getPlacerValid("getPlacerValid", NULL, 'd');
const idEventDef EV_Player_getPlacerRotation("getPlacerRotation", NULL, 's');
const idEventDef EV_Player_SetButtonPrompt("SetButtonPrompt", "d");
const idEventDef EV_Player_SetHudEvent("SetHudEvent", "s");
const idEventDef EV_Player_SetCameraGuiEvent("SetCameraGuiEvent", "s");
const idEventDef EV_Player_BindStickyItem("BindStickyItem", "e");
const idEventDef EV_Player_GetYawDelta("GetYawDelta", NULL, 'f');
const idEventDef EV_Player_GetDefibState("GetDefibState", NULL, 'f');
const idEventDef EV_Player_GetMechState("GetMechState", NULL, 'f');
const idEventDef EV_Player_SetViewPitchLerp("SetViewPitchLerp", "fd");
const idEventDef EV_Player_SetViewRollLerp("SetViewRollLerp", "fd");
const idEventDef EV_Player_RemoveWeapon("RemoveWeapon", "d");
const idEventDef EV_Player_DropWeapon("DropWeapon", "d");
const idEventDef EV_Player_EnableBeaconUI("EnableBeaconUI");
const idEventDef EV_Player_SetBeaconCode("SetBeaconCode", "s");
const idEventDef EV_Player_ActivateBeacon("ActivateBeacon", "dv", 'd');
const idEventDef EV_Player_UpdateBeaconSignalLock("UpdateBeaconSignalLock");
const idEventDef EV_Player_UpdateSignalCode("UpdateSignalCode");
const idEventDef EV_Player_StartEnteringCode("StartEnteringCode");
const idEventDef EV_Player_SetDropAmmoMsg("SetDropAmmoMsg", "d");
const idEventDef EV_Player_SetFrozen("setFrozen", "d");
const idEventDef EV_Player_SetViewYawLerp("SetViewYawLerp", "fd");
const idEventDef EV_Player_SetViewLerp("SetViewLerp", "vd");
const idEventDef EV_Player_SetFOVLerp("SetFOVLerp", "fd");
const idEventDef EV_Player_SetFallState("SetFallState", "ddd");
const idEventDef EV_Player_GetFallState("GetFallState", NULL, 'f');
const idEventDef EV_Player_SetCanFrob("SetCanFrob", "d");
const idEventDef EV_Player_ClearInventory("ClearInventory");
const idEventDef EV_Player_EnableBlur("enableBlur");
const idEventDef EV_Player_DisableBlur("disableBlur");
const idEventDef EV_Player_SetBloodRage("setbloodrage", "ff");
const idEventDef EV_Player_ForceSpaceParticles("forceSpaceParticles", "d");
const idEventDef EV_Player_SetCenterMessage("setCenterMessage", "s");
const idEventDef EV_Player_SetFlyText("setflytext", "vs");
const idEventDef EV_Player_HasInventoryItem("hasinventoryitem", "s", 'd');
const idEventDef EV_Player_IsAirless("isAirless", NULL, 'd');
const idEventDef EV_Player_IsBurning("isBurning", NULL, 'd');
const idEventDef EV_Player_ClearWounds("clearWounds", "d");
const idEventDef EV_Player_IsDowned("isDowned", NULL, 'd');
const idEventDef EV_Player_SetDownedState("setDownedState", "d");
const idEventDef EV_Player_SetJockeyMode("setJockeyMode", "de");
const idEventDef EV_Player_HasDefib("hasDefib", NULL, 'd');
const idEventDef EV_Player_SetDefibAvailable("setDefibAvailable", "d");

const idEventDef EV_Player_GiveEmail("giveEmail", "s");
const idEventDef EV_Player_GiveEmailViaTalker("giveEmailViaTalker", "ssd");
const idEventDef EV_Player_HasReadEmail("hasReadEmail", "s", 'd');
const idEventDef EV_Player_HasEmail("hasEmail", "s", 'd');
const idEventDef EV_Player_HasUnreadCriticalEmail("hasUnreadCriticalEmail", NULL, 'd');

const idEventDef EV_Player_HasItemViaClassname("hasitemviaclass", "s", 'd');
const idEventDef EV_Player_RemoveItemViaClassname("removeitemviaclass", "s", 'd');
const idEventDef EV_Player_RemoveItemViaEntity("removeitemviaentity", "e", 'd');
const idEventDef EV_Player_GetItemViaClassname("getitemviaclass", "s", 'e');


const idEventDef EV_Player_DelayedVO_WithInterval("delayedvo_withinterval", "s");
const idEventDef EV_Player_DelayedVO_WithInterval_withDelay("playVO_delayInterval", "sd");

const idEventDef EV_Player_GetNextMap("getNextMap", NULL, 's');
const idEventDef EV_Player_GetMapIndex("getMapIndex", NULL, 'd');
const idEventDef EV_Player_GetNextMapName("getNextMapName", NULL, 's');
const idEventDef EV_Player_GetNextMapDesc("getNextMapDesc", NULL, 's');
const idEventDef EV_Player_GetIsNextmapShip("isNextmapShip", NULL, 'd');
const idEventDef EV_Player_SaveProgression("saveProgression", "s");


const idEventDef EV_Player_SetFallDamageImmune("setFallDamageImmune", "d");

const idEventDef EV_Player_OpenLevelselect("OpenLevelselect", "d");
const idEventDef EV_Player_IsFullscreenUIActive("isFullscreenUIActive", NULL, 'd');


const idEventDef EV_Player_ViewposLerp("ViewposLerp", "vd");

const idEventDef EV_Player_GetLocationLocID("GetLocationLocID", NULL, 's');

const idEventDef EV_Player_ForceDuck("SetDuck", "d");

const idEventDef EV_Player_SetObjective("SetObjective", "sd");
const idEventDef EV_Player_IsEntityLostInSpace("isEntityLostInSpace", "s", 'd');

const idEventDef EV_Player_SetVignetteMode("setVignetteMode", "d");
const idEventDef EV_Player_GetVignetteMode("getVignetteMode", NULL, 'd');
const idEventDef EV_Player_SetSmelly("setSmelly", "d");

const idEventDef EV_Player_DropInventoryItem("dropInventoryItem", "s");

const idEventDef EV_Player_SetTitleFlyMode("settitleflymode", "d");

const idEventDef EV_Player_ResetMaterialTimer("resetmaterialtimer", "s");

const idEventDef EV_Player_ParticleStream("particlestream", "svd");

const idEventDef EV_Player_ForceSpatterFx("forceSpatterFx", "df");

const idEventDef EV_Player_SetPlayerBody("setplayerbody", "d");

const idEventDef EV_Player_DisplayCatBox("displayCatBox", "sss");
 
const idEventDef EV_Player_EnableHeartBeat("enableHeartBeat", "d"); // SW 11th Feb 2025: toggles heartbeat audibility

const idEventDef EV_Player_SetCinematicHUD("setCinematicHUD", "d"); //2-7-2025: do we force hud to draw during cinematics (defaults to true)

//BC script calls.






CLASS_DECLARATION( idActor, idPlayer )
	EVENT( EV_Player_GetButtons,			idPlayer::Event_GetButtons )
	EVENT( EV_Player_GetMove,				idPlayer::Event_GetMove )
	EVENT( EV_Player_GetViewAngles,			idPlayer::Event_GetViewAngles )
	EVENT( EV_Player_StopFxFov,				idPlayer::Event_StopFxFov )
	EVENT( EV_Player_EnableWeapon,			idPlayer::Event_EnableWeapon )
	EVENT( EV_Player_DisableWeapon,			idPlayer::Event_DisableWeapon )
	EVENT( EV_Player_GetCurrentWeapon,		idPlayer::Event_GetCurrentWeapon )
	EVENT( EV_Player_GetPreviousWeapon,		idPlayer::Event_GetPreviousWeapon )
	EVENT( EV_Player_SelectWeapon,			idPlayer::Event_SelectWeapon )
	EVENT( EV_Player_GetWeaponEntity,		idPlayer::Event_GetWeaponEntity )
	EVENT( EV_Player_OpenPDA,				idPlayer::Event_OpenPDA )
	EVENT( EV_Player_InPDA,					idPlayer::Event_InPDA )
	EVENT( EV_Player_ExitTeleporter,		idPlayer::Event_ExitTeleporter )
	EVENT( EV_Player_StopAudioLog,			idPlayer::Event_StopAudioLog )
	EVENT( EV_Player_HideTip,				idPlayer::Event_HideTip )
	EVENT( EV_Player_LevelTrigger,			idPlayer::Event_LevelTrigger )
	EVENT( EV_Gibbed,						idPlayer::Event_Gibbed )
#ifdef _D3XP
	EVENT( EV_Player_GiveInventoryItem,		idPlayer::Event_GiveInventoryItem )
	EVENT( EV_Player_RemoveInventoryItem,	idPlayer::Event_RemoveInventoryItem )
	EVENT( EV_Player_GetIdealWeapon,		idPlayer::Event_GetIdealWeapon )
	EVENT( EV_Player_WeaponAvailable,		idPlayer::Event_WeaponAvailable )
	EVENT( EV_Player_SetPowerupTime,		idPlayer::Event_SetPowerupTime )
	EVENT( EV_Player_IsPowerupActive,		idPlayer::Event_IsPowerupActive )
	EVENT( EV_Player_StartWarp,				idPlayer::Event_StartWarp )
	EVENT( EV_Player_StopHelltime,			idPlayer::Event_StopHelltime )
	EVENT( EV_Player_ToggleBloom,			idPlayer::Event_ToggleBloom )
	EVENT( EV_Player_SetBloomParms,			idPlayer::Event_SetBloomParms )
#endif

	//BC
	EVENT( EV_Player_SetGlasswoundHeal,		idPlayer::Event_SetGlasswoundHeal )
	EVENT(EV_Player_AddGlassWound,			idPlayer::Event_AddGlassWound)
	EVENT( EV_Player_GetGlasswounds,		idPlayer::Event_GetGlasswounds )
	EVENT(EV_Player_GetBulletwounds,		idPlayer::Event_GetBulletwounds)
	EVENT(EV_Player_GetShrapnelwounds,		idPlayer::Event_GetShrapnelwounds)
	EVENT(EV_Player_SetArmVisibility,		idPlayer::SetArmVisibility)
	EVENT(EV_Player_SetViewLock,			idPlayer::SetViewYawLock)
	EVENT( EV_Player_SetViewPitchLock,		idPlayer::SetViewPitchLock )
	EVENT(EV_Player_SetBodyAngleLock,		idPlayer::SetBodyAngleLock)
	EVENT(EV_Player_SetBurningHeal,			idPlayer::Event_SetBurningHeal)
	EVENT(EV_Player_Teleport,				idPlayer::Event_Teleport)
	EVENT(EV_Player_TeleportToEnt,			idPlayer::Event_TeleportToEnt)
	EVENT(EV_Player_getPlacerAngle,			idPlayer::Event_getPlacerAngle)
	EVENT(EV_Player_getPlacerPos,			idPlayer::Event_getPlacerPos)
	EVENT(EV_Player_getPlacerValid,			idPlayer::Event_getPlacerValid)
	EVENT(EV_Player_getPlacerRotation,		idPlayer::Event_getPlacerRotation)
	EVENT(EV_Player_SetButtonPrompt,		idPlayer::Event_SetButtonPrompt)
	EVENT(EV_Player_SetHudEvent,			idPlayer::SetHudEvent)
	EVENT(EV_Player_SetCameraGuiEvent,		idPlayer::SetCameraGuiEvent)
	EVENT(EV_Player_BindStickyItem,			idPlayer::BindStickyItem)
	EVENT(EV_Player_GetYawDelta,			idPlayer::GetYawDelta)
	EVENT(EV_Player_GetDefibState,			idPlayer::GetDefibState)
	EVENT(EV_Player_GetMechState,			idPlayer::IsInMechEvent)
	EVENT(EV_Player_SetViewPitchLerp,		idPlayer::SetViewPitchLerp)
	EVENT(EV_Player_SetViewRollLerp,		idPlayer::SetViewRollLerp)
	EVENT(EV_Player_RemoveWeapon,			idPlayer::RemovePlayerWeapon)
	EVENT(EV_Player_DropWeapon,				idPlayer::DropWeapon)
	EVENT(EV_Player_EnableBeaconUI,			idPlayer::EnableBeaconUI)
	EVENT(EV_Player_SetBeaconCode,			idPlayer::SetBeaconCode)
	EVENT(EV_Player_ActivateBeacon,			idPlayer::ActivateBeacon)
	EVENT(EV_Player_UpdateBeaconSignalLock, idPlayer::UpdateBeaconSignalLock)
	EVENT(EV_Player_UpdateSignalCode,		idPlayer::UpdateSignalCode)
	EVENT(EV_Player_StartEnteringCode,		idPlayer::StartEnteringCode)
	EVENT(EV_Player_SetDropAmmoMsg,			idPlayer::Event_SetDropAmmoMsg)
	EVENT(EV_Player_SetFrozen,				idPlayer::Event_setPlayerFrozen)
	EVENT(EV_Player_SetViewYawLerp,			idPlayer::SetViewYawLerp)
	EVENT(EV_Player_SetViewLerp,			idPlayer::SetViewLerp)
	EVENT(EV_Player_SetFOVLerp,				idPlayer::Event_SetFOVLerp)
	EVENT(EV_Player_SetFallState,			idPlayer::Event_SetFallState)
	EVENT(EV_Player_GetFallState,			idPlayer::Event_GetFallState)
	EVENT(EV_Player_SetCanFrob,				idPlayer::SetCanFrob)
	EVENT(EV_Player_ClearInventory,			idPlayer::Event_ClearInventory)
	EVENT(EV_Player_EnableBlur,				idPlayer::Event_EnableBlur)
	EVENT(EV_Player_DisableBlur,			idPlayer::Event_DisableBlur)
    EVENT(EV_Player_SetBloodRage,           idPlayer::Event_SetBloodRage)
	EVENT(EV_Player_ForceSpaceParticles,	idPlayer::Event_ForceSpaceParticles)
	EVENT(EV_Player_GiveEmail,				idPlayer::Event_GiveEmail)
	EVENT(EV_Player_GiveEmailViaTalker,		idPlayer::Event_GiveEmailViaTalker)
	EVENT(EV_Player_SetCenterMessage,		idPlayer::SetCenterMessage)
	EVENT(EV_Player_IsAirless,				idPlayer::Event_IsAirless)
	EVENT(EV_Player_SetFallDamageImmune,	idPlayer::Event_SetFallDamageImmune)
	EVENT(EV_Player_IsBurning,				idPlayer::Event_IsBurning)
	EVENT(EV_Player_ClearWounds,			idPlayer::Event_ClearWounds)
	EVENT(EV_Player_IsDowned,				idPlayer::Event_IsDowned)
	EVENT(EV_Player_SetDownedState,			idPlayer::Event_SetDownedState)
	EVENT(EV_Player_SetJockeyMode,			idPlayer::Event_SetJockeyMode)
	EVENT(EV_Player_HasDefib,				idPlayer::Event_HasDefib)
	EVENT(EV_Player_SetDefibAvailable,		idPlayer::Event_SetDefibAvailable)

	EVENT(EV_Player_HasReadEmail,			idPlayer::Event_HasReadEmail)
	EVENT(EV_Player_HasEmail,				idPlayer::Event_HasEmail)
	EVENT(EV_Player_HasUnreadCriticalEmail, idPlayer::Event_HasEmailsCritical)
	

	
	
	EVENT(EV_Player_SetFlyText,				idPlayer::Event_flytext)
	EVENT(EV_Player_HasInventoryItem,		idPlayer::Event_HasInventoryItem)

	EVENT(EV_Player_HasItemViaClassname,	idPlayer::Event_HasItemViaClassname)
	EVENT(EV_Player_RemoveItemViaClassname, idPlayer::Event_RemoveItemViaClassname)
	EVENT(EV_Player_RemoveItemViaEntity,	idPlayer::Event_RemoveItemViaEntity)
	EVENT(EV_Player_GetItemViaClassname,	idPlayer::Event_GetItemViaClassname)

	EVENT(EV_Player_DelayedVO_WithInterval,	idPlayer::SayVO_WithIntervalDelay)
	EVENT(EV_Player_DelayedVO_WithInterval_withDelay, idPlayer::SayVO_WithIntervalDelay_msDelayed)
	EVENT(EV_Player_GetNextMap,				idPlayer::Event_GetNextMap)
	EVENT(EV_Player_GetMapIndex,			idPlayer::Event_GetMapIndex)

	EVENT(EV_Player_GetNextMapName,			idPlayer::Event_GetNextMapName)
	EVENT(EV_Player_GetNextMapDesc,			idPlayer::Event_GetNextMapDesc)
	EVENT(EV_Player_GetIsNextmapShip,		idPlayer::Event_GetIsNextmapShip)

	EVENT(EV_Player_SaveProgression,		idPlayer::Event_SaveProgression)	

	EVENT(EV_Player_OpenLevelselect,		idPlayer::LevelselectMenuOpen)

	EVENT(EV_Player_ViewposLerp,			idPlayer::SetViewposAbsLerp)


	EVENT(EV_Player_GetLocationLocID,		idPlayer::Event_GetLocationLocID)

	EVENT(EV_Player_ForceDuck,				idPlayer::Event_ForceDuck)
	
	
	EVENT(EV_Player_SetObjective,			idPlayer::SetObjectiveText)
	EVENT(EV_Player_IsEntityLostInSpace,	idPlayer::Event_IsEntityLostInSpace)
	EVENT(EV_Player_SetVignetteMode,		idPlayer::Event_SetVignetteMode)
	EVENT(EV_Player_GetVignetteMode,		idPlayer::Event_GetVignetteMode)
	EVENT(EV_Player_SetSmelly,				idPlayer::Event_SetSmelly)

	EVENT(EV_Player_DropInventoryItem,		idPlayer::Event_DropInventoryItem)
	
	EVENT(EV_Player_DropInventoryItem,		idPlayer::Event_SetTitleFlyMode)

	EVENT(EV_Player_ResetMaterialTimer,		idPlayer::Event_ResetMaterialTimer)


	EVENT(EV_Player_ParticleStream,			idPlayer::Event_ParticleStream)

	EVENT(EV_Player_SetPlayerBody,			idPlayer::Event_SetPlayerBody)

	EVENT(EV_Player_ForceSpatterFx,			idPlayer::Event_ForceSpatterFx)

	EVENT(EV_Player_IsFullscreenUIActive,	idPlayer::Event_IsFullscreenUIActive)

	EVENT(EV_Player_DisplayCatBox,			idPlayer::Event_DisplayCatBox)
		
	EVENT(EV_Player_SetCinematicHUD,		idPlayer::Event_SetCinematicHUD)
	
	EVENT(EV_Player_EnableHeartBeat,		idPlayer::Event_EnableHeartBeat)

END_CLASS

const int MAX_RESPAWN_TIME = 10000;
const int RAGDOLL_DEATH_TIME = 3000;
const int MAX_PDAS = 64;
const int MAX_PDA_ITEMS = 128;
const int STEPUP_TIME = 200;
const int STEPUPRECOVERY_TIME = 200;
const int MAX_INVENTORY_ITEMS = 20;


#ifdef _D3XP
idVec3 idPlayer::colorBarTable[ 8 ] = {
#else
idVec3 idPlayer::colorBarTable[ 5 ] = {
#endif
	idVec3( 0.25f, 0.25f, 0.25f ),
	idVec3( 1.00f, 0.00f, 0.00f ),
	idVec3( 0.00f, 0.80f, 0.10f ),
	idVec3( 0.20f, 0.50f, 0.80f ),
	idVec3( 1.00f, 0.80f, 0.10f )
#ifdef _D3XP
	,idVec3( 0.425f, 0.484f, 0.445f ),
	idVec3( 0.39f, 0.199f, 0.3f ),
	idVec3( 0.484f, 0.312f, 0.074f)
#endif
};

extern void RigidBodyDerivatives(const float t, const void* clientData, const float* state, float* derivatives);

//TODO: Add falling down system? Detect if running on a pile of shell casings.

/*
==============
idInventory::Clear
==============
*/
void idInventory::Clear( void ) {
	maxHealth		= 0;
	powerups		= 0;
	armor			= 0;
	maxarmor		= 0;
	deplete_armor	= 0;
	deplete_rate	= 0.0f;
	deplete_ammount	= 0;
	nextArmorDepleteTime = 0;

	memset( ammo, 0, sizeof( ammo ) );

	ClearPowerUps();

	items.DeleteContents( true );
	memset(pdasViewed, 0, 4 * sizeof( pdasViewed[0] ) );
	pdas.Clear();
	videos.Clear();
	emails.Clear();
	selVideo = 0;
	selEMail = 0;
	selPDA = 0;
	selAudio = 0;
	pdaOpened = false;
	turkeyScore = false;

	levelTriggers.Clear();

	objectiveNames.Clear();

	ammoPredictTime = 0;

	lastGiveTime = 0;

	ammoPulse	= false;
	weaponPulse	= false;
	armorPulse	= false;


	//BC
	hotbarUnlockedSlots = SLOTS_AVAILABLE_AT_START;
	hotbarCurrentlySelected = 0; //Which slot is currently active.

	//Note: MAX_HOTBARSLOTS in player.h determines the total max # of hotbar slots.


	mushrooms = 0;
	bloodbags = 0;
	catkeys = 0;
	maintbooks = 0;
	
	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		ResetHotbarSlot( i );
	}
}

/*
==============
idInventory::GivePowerUp
==============
*/
void idInventory::GivePowerUp( idPlayer *player, int powerup, int msec ) {
	if ( !msec )
	{
		// get the duration from the .def files
		const idDeclEntityDef *def = NULL;
		switch ( powerup )
		{
			case BERSERK:
				def = gameLocal.FindEntityDef( "powerup_berserk", false );
				break;
			case INVISIBILITY:
				def = gameLocal.FindEntityDef( "powerup_invisibility", false );
				break;
			case MEGAHEALTH:
				def = gameLocal.FindEntityDef( "powerup_megahealth", false );
				break;
			case ADRENALINE:
				def = gameLocal.FindEntityDef( "powerup_adrenaline", false );
				break;
#ifdef _D3XP
			case INVULNERABILITY:
				def = gameLocal.FindEntityDef( "powerup_invulnerability", false );
				break;
			case HASTE:
				def = gameLocal.FindEntityDef( "powerup_haste", false );
				break;
#endif
		}
		assert( def );
		msec = def->dict.GetInt( "time" ) * 1000;
	}

	//BC this is what gives the powerup.
	powerups |= 1 << powerup;
	powerupEndTime[ powerup ] = gameLocal.fast.time + gameLocal.msec;
}

/*
==============
idInventory::ClearPowerUps
==============
*/
void idInventory::ClearPowerUps( void ) {
	int i;
	for ( i = 0; i < MAX_POWERUPS; i++ ) {
		powerupEndTime[ i ] = 0;
	}
	powerups = 0;
}

/*
==============
idInventory::GetPersistantData
==============
*/
void idInventory::GetPersistantData( idDict &dict ) {
	int		i;
//	int		num;
//	idDict	*item;
	idStr	key;
//	const idKeyValue *kv;
//	const char *name;

	// SM: Don't need this in persistent info
// 	// armor
// 	dict.SetInt( "armor", armor );
// 
// 	// don't bother with powerups, maxhealth, maxarmor, or the clip
// 
// 	// ammo
// 	for( i = 0; i < AMMO_NUMTYPES; i++ ) {
// 		name = idWeapon::GetAmmoNameForNum( ( ammo_t )i );
// 		if ( name ) {
// 			dict.SetInt( name, ammo[ i ] );
// 		}
// 	}
// 
// 	// items
// 	num = 0;
// 	for( i = 0; i < items.Num(); i++ ) {
// 		item = items[ i ];
// 
// 		// copy all keys with "inv_"
// 		kv = item->MatchPrefix( "inv_" );
// 		if ( kv ) {
// 			while( kv ) {
// 				sprintf( key, "item_%i %s", num, kv->GetKey().c_str() );
// 				dict.Set( key, kv->GetValue() );
// 				kv = item->MatchPrefix( "inv_", kv );
// 			}
// 			num++;
// 		}
// 	}
// 	dict.SetInt( "items", num );

	// pdas viewed
	for ( i = 0; i < 4; i++ ) {
		dict.SetInt( va("pdasViewed_%i", i), pdasViewed[i] );
	}

	dict.SetInt( "selPDA", selPDA );
	dict.SetInt( "selVideo", selVideo );
	dict.SetInt( "selEmail", selEMail );
	dict.SetInt( "selAudio", selAudio );
	dict.SetInt( "pdaOpened", pdaOpened );
	//dict.SetInt( "turkeyScore", turkeyScore );

	// pdas
	for ( i = 0; i < pdas.Num(); i++ ) {
		sprintf( key, "pda_%i", i );
		dict.Set( key, pdas[ i ] );
	}
	dict.SetInt( "pdas", pdas.Num() );

	// video cds
	for ( i = 0; i < videos.Num(); i++ ) {
		sprintf( key, "video_%i", i );
		dict.Set( key, videos[ i ].c_str() );
	}
	dict.SetInt( "videos", videos.Num() );

	// emails
	for ( i = 0; i < emails.Num(); i++ ) {
		sprintf( key, "email_%i", i );
		dict.Set( key, emails[ i ].c_str() );
	}
	dict.SetInt( "emails", emails.Num() );

	// emailsRead
	for (i = 0; i < emailsRead.Num(); i++) {
		sprintf(key, "emailread_%i", i);
		dict.Set(key, emailsRead[i].c_str());
	}
	dict.SetInt("emailsRead", emailsRead.Num());

	// emailsReplied
	for (i = 0; i < emailsReplied.Num(); i++) {
		sprintf(key, "emailreplied_%i", i);
		dict.Set(key, emailsReplied[i].c_str());
	}
	dict.SetInt("emailsReplied", emailsReplied.Num());

	// SM: Don't need this in persistent info
// 	dict.SetInt( "levelTriggers", levelTriggers.Num() );
// 	for ( i = 0; i < levelTriggers.Num(); i++ ) {
// 		sprintf( key, "levelTrigger_Level_%i", i );
// 		dict.Set( key, levelTriggers[i].levelName );
// 		sprintf( key, "levelTrigger_Trigger_%i", i );
// 		dict.Set( key, levelTriggers[i].triggerName );
// 	}
// 
// 	// weapons
// 	for ( i = 0; i < MAX_HOTBARSLOTS; ++i ) {
// 		sprintf( key, "hotbar_weaponType_%i", i );
// 		dict.SetInt( key, hotbarSlots[i].weaponType );
// 		sprintf( key, "hotbar_clip_%i", i );
// 		dict.SetInt( key, hotbarSlots[i].clip );
// 		sprintf( key, "hotbar_health_%i", i );
// 		dict.SetInt( key, hotbarSlots[i].health );
// 		sprintf( key, "hotbar_chambered_%i", i );
// 		dict.SetBool( key, hotbarSlots[i].chambered );
// 		sprintf( key, "hotbar_carryPtr_%i", i );
// 		dict.SetInt( key, hotbarSlots[i].carryPtr.GetSpawnId() );
// 	}
}

/*
==============
idInventory::RestoreInventory
==============
*/
void idInventory::RestoreInventory( idPlayer *owner, const idDict &dict ) {
	int			i;
	int			num;
//	idDict		*item;
	idStr		key;
	idStr		itemname;
//	const idKeyValue *kv;
//	const char	*name;

	Clear();

	// health/armor
 	maxHealth		= dict.GetInt( "maxhealth", "100" );
 	armor			= dict.GetInt( "armor", "0" );
 	maxarmor		= dict.GetInt( "maxarmor", "900" );
 	deplete_armor	= dict.GetInt( "deplete_armor", "0" );
 	deplete_rate	= dict.GetFloat( "deplete_rate", "2.0" );
 	deplete_ammount	= dict.GetInt( "deplete_ammount", "1" );
// 
// 	// the clip and powerups aren't restored
// 
// 	// ammo
// 	for( i = 0; i < AMMO_NUMTYPES; i++ ) {
// 		name = idWeapon::GetAmmoNameForNum( ( ammo_t )i );
// 		if ( name ) {
// 			ammo[ i ] = dict.GetInt( name );
// 		}
// 	}
// 
// 	// items
// 	num = dict.GetInt( "items" );
// 	items.SetNum( num );
// 	for( i = 0; i < num; i++ ) {
// 		item = new idDict();
// 		items[ i ] = item;
// 		sprintf( itemname, "item_%i ", i );
// 		kv = dict.MatchPrefix( itemname );
// 		while( kv ) {
// 			key = kv->GetKey();
// 			key.Strip( itemname );
// 			item->Set( key, kv->GetValue() );
// 			kv = dict.MatchPrefix( itemname, kv );
// 		}
// 	}

	// pdas viewed
	for ( i = 0; i < 4; i++ ) {
		pdasViewed[i] = dict.GetInt(va("pdasViewed_%i", i));
	}

	selPDA = dict.GetInt( "selPDA" );
	selEMail = dict.GetInt( "selEmail" );
	selVideo = dict.GetInt( "selVideo" );
	selAudio = dict.GetInt( "selAudio" );
	pdaOpened = dict.GetBool( "pdaOpened" );
	//turkeyScore = dict.GetBool( "turkeyScore" );

	// pdas
	num = dict.GetInt( "pdas" );
	pdas.SetNum( num );
	for ( i = 0; i < num; i++ ) {
		sprintf( itemname, "pda_%i", i );
		pdas[i] = dict.GetString( itemname, "default" );
	}

	// videos
	num = dict.GetInt( "videos" );
	videos.SetNum( num );
	for ( i = 0; i < num; i++ ) {
		sprintf( itemname, "video_%i", i );
		videos[i] = dict.GetString( itemname, "default" );
	}

	// emails
	num = dict.GetInt( "emails" );
	emails.SetNum( num );
	for ( i = 0; i < num; i++ ) {
		sprintf( itemname, "email_%i", i );
		emails[i] = dict.GetString( itemname, "default" );
	}

	// emailsRead
	num = dict.GetInt("emailsRead");
	emailsRead.SetNum(num);
	for (i = 0; i < num; i++) {
		sprintf(itemname, "emailread_%i", i);
		emailsRead[i] = dict.GetString(itemname, "default");
	}

	// emailsReplied
	num = dict.GetInt("emailsReplied");
	emailsReplied.SetNum(num);
	for (i = 0; i < num; i++) {
		sprintf(itemname, "emailreplied_%i", i);
		emailsReplied[i] = dict.GetString(itemname, "default");
	}

// 	num = dict.GetInt( "levelTriggers" );
// 	for ( i = 0; i < num; i++ ) {
// 		sprintf( itemname, "levelTrigger_Level_%i", i );
// 		idLevelTriggerInfo lti;
// 		lti.levelName = dict.GetString( itemname );
// 		sprintf( itemname, "levelTrigger_Trigger_%i", i );
// 		lti.triggerName = dict.GetString( itemname );
// 		levelTriggers.Append( lti );
// 	}
// 
// 	for ( i = 0; i < MAX_HOTBARSLOTS; ++i ) {
// 		sprintf( key, "hotbar_weaponType_%i", i );
// 		hotbarSlots[i].weaponType = dict.GetInt( key );
// 		sprintf( key, "hotbar_clip_%i", i );
// 		hotbarSlots[i].clip = dict.GetInt( key, "-1" );
// 		sprintf( key, "hotbar_health_%i", i );
// 		hotbarSlots[i].health = dict.GetInt( key );
// 		sprintf( key, "hotbar_chambered_%i", i );
// 		hotbarSlots[i].chambered = dict.GetBool( key, "1" );
// 		sprintf( key, "hotbar_carryPtr_%i", i );
// 		hotbarSlots[i].carryPtr.SetSpawnId( dict.GetInt( key ) );
// 	}

}

/*
==============
idInventory::Save
==============
*/
void idInventory::Save( idSaveGame *savefile ) const {
	int i;

	savefile->WriteInt( maxHealth );
	//savefile->WriteInt( weapons );
	savefile->WriteInt( powerups );
	savefile->WriteInt( armor );
	savefile->WriteInt( maxarmor );
	savefile->WriteInt( ammoPredictTime );
	savefile->WriteInt( deplete_armor );
	savefile->WriteFloat( deplete_rate );
	savefile->WriteInt( deplete_ammount );
	savefile->WriteInt( nextArmorDepleteTime );

	for( i = 0; i < AMMO_NUMTYPES; i++ ) {
		savefile->WriteInt( ammo[ i ] );
	}
	for( i = 0; i < MAX_POWERUPS; i++ ) {
		savefile->WriteInt( powerupEndTime[ i ] );
	}

	savefile->WriteInt( items.Num() );
	for( i = 0; i < items.Num(); i++ ) {
		savefile->WriteDict( items[ i ] );
	}

	savefile->WriteInt( pdasViewed[0] );
	savefile->WriteInt( pdasViewed[1] );
	savefile->WriteInt( pdasViewed[2] );
	savefile->WriteInt( pdasViewed[3] );

	savefile->WriteInt( selPDA );
	savefile->WriteInt( selVideo );
	savefile->WriteInt( selEMail );
	savefile->WriteInt( selAudio );
	savefile->WriteBool( pdaOpened );
	savefile->WriteBool( turkeyScore );

	savefile->WriteInt( pdas.Num() );
	for( i = 0; i < pdas.Num(); i++ ) {
		savefile->WriteString( pdas[ i ] );
	}

	savefile->WriteInt( pdaSecurity.Num() );
	for( i=0; i < pdaSecurity.Num(); i++ ) {
		savefile->WriteString( pdaSecurity[ i ] );
	}

	savefile->WriteInt( videos.Num() );
	for( i = 0; i < videos.Num(); i++ ) {
		savefile->WriteString( videos[ i ] );
	}

	savefile->WriteInt( emails.Num() );
	for ( i = 0; i < emails.Num(); i++ ) {
		savefile->WriteString( emails[ i ] );
	}

	savefile->WriteInt( objectiveNames.Num() );
	for( i = 0; i < objectiveNames.Num(); i++ ) {
		savefile->WriteString( objectiveNames[i].screenshot );
		savefile->WriteString( objectiveNames[i].text );
		savefile->WriteString( objectiveNames[i].title );
	}

	savefile->WriteInt( levelTriggers.Num() );
	for ( i = 0; i < levelTriggers.Num(); i++ ) {
		savefile->WriteString( levelTriggers[i].levelName );
		savefile->WriteString( levelTriggers[i].triggerName );
	}

	savefile->WriteBool( ammoPulse );
	savefile->WriteBool( weaponPulse );
	savefile->WriteBool( armorPulse );

	savefile->WriteInt( lastGiveTime );

#ifdef _D3XP
	for(i = 0; i < AMMO_NUMTYPES; i++) {
		savefile->WriteInt(rechargeAmmo[i].ammo);
		savefile->WriteInt(rechargeAmmo[i].rechargeTime);
		savefile->WriteString(rechargeAmmo[i].ammoName);
	}
#endif

	for ( i = 0; i < MAX_HOTBARSLOTS; ++i ) {
		savefile->WriteInt( hotbarSlots[i].weaponType );
		savefile->WriteInt( hotbarSlots[i].clip );
		savefile->WriteInt( hotbarSlots[i].health );
		savefile->WriteBool( hotbarSlots[i].chambered );
		savefile->WriteInt( hotbarSlots[i].carryPtr.GetSpawnId() );
	}
}

/*
==============
idInventory::Restore
==============
*/
void idInventory::Restore( idRestoreGame *savefile ) {
	int i, num;

	savefile->ReadInt( maxHealth );
	//savefile->ReadInt( weapons );
	savefile->ReadInt( powerups );
	savefile->ReadInt( armor );
	savefile->ReadInt( maxarmor );
	savefile->ReadInt( ammoPredictTime );
	savefile->ReadInt( deplete_armor );
	savefile->ReadFloat( deplete_rate );
	savefile->ReadInt( deplete_ammount );
	savefile->ReadInt( nextArmorDepleteTime );

	for( i = 0; i < AMMO_NUMTYPES; i++ ) {
		savefile->ReadInt( ammo[ i ] );
	}
// 	for( i = 0; i < MAX_WEAPONS; i++ ) {
// 		savefile->ReadInt( clip[ i ] );
// 	}
	for( i = 0; i < MAX_POWERUPS; i++ ) {
		savefile->ReadInt( powerupEndTime[ i ] );
	}

	savefile->ReadInt( num );
	for( i = 0; i < num; i++ ) {
		idDict *itemdict = new idDict;

		savefile->ReadDict( itemdict );
		items.Append( itemdict );
	}

	// pdas
	savefile->ReadInt( pdasViewed[0] );
	savefile->ReadInt( pdasViewed[1] );
	savefile->ReadInt( pdasViewed[2] );
	savefile->ReadInt( pdasViewed[3] );

	savefile->ReadInt( selPDA );
	savefile->ReadInt( selVideo );
	savefile->ReadInt( selEMail );
	savefile->ReadInt( selAudio );
	savefile->ReadBool( pdaOpened );
	savefile->ReadBool( turkeyScore );

	savefile->ReadInt( num );
	for( i = 0; i < num; i++ ) {
		idStr strPda;
		savefile->ReadString( strPda );
		pdas.Append( strPda );
	}

	// pda security clearances
	savefile->ReadInt( num );
	for ( i = 0; i < num; i++ ) {
		idStr invName;
		savefile->ReadString( invName );
		pdaSecurity.Append( invName );
	}

	// videos
	savefile->ReadInt( num );
	for( i = 0; i < num; i++ ) {
		idStr strVideo;
		savefile->ReadString( strVideo );
		videos.Append( strVideo );
	}

	// email
	savefile->ReadInt( num );
	for( i = 0; i < num; i++ ) {
		idStr strEmail;
		savefile->ReadString( strEmail );
		emails.Append( strEmail );
	}

	savefile->ReadInt( num );
	for( i = 0; i < num; i++ ) {
		idObjectiveInfo obj;

		savefile->ReadString( obj.screenshot );
		savefile->ReadString( obj.text );
		savefile->ReadString( obj.title );

		objectiveNames.Append( obj );
	}

	savefile->ReadInt( num );
	for ( i = 0; i < num; i++ ) {
		idLevelTriggerInfo lti;
		savefile->ReadString( lti.levelName );
		savefile->ReadString( lti.triggerName );
		levelTriggers.Append( lti );
	}

	savefile->ReadBool( ammoPulse );
	savefile->ReadBool( weaponPulse );
	savefile->ReadBool( armorPulse );

	savefile->ReadInt( lastGiveTime );

#ifdef _D3XP
	for(i = 0; i < AMMO_NUMTYPES; i++) {
		savefile->ReadInt(rechargeAmmo[i].ammo);
		savefile->ReadInt(rechargeAmmo[i].rechargeTime);

		idStr name;
		savefile->ReadString(name);
		strcpy(rechargeAmmo[i].ammoName, name);
	}
#endif

	for ( i = 0; i < MAX_HOTBARSLOTS; ++i ) {
		savefile->ReadInt( hotbarSlots[i].weaponType );
		savefile->ReadInt( hotbarSlots[i].clip );
		savefile->ReadInt( hotbarSlots[i].health );
		savefile->ReadBool( hotbarSlots[i].chambered );
		int spawnId;
		savefile->ReadInt( spawnId );
		hotbarSlots[i].carryPtr.SetSpawnId( spawnId );
	}
}

/*
==============
idInventory::AmmoIndexForAmmoClass
==============
*/
ammo_t idInventory::AmmoIndexForAmmoClass( const char *ammo_classname ) const {
	return idWeapon::GetAmmoNumForName( ammo_classname );
}

/*
==============
idInventory::AmmoIndexForAmmoClass
==============
*/
int idInventory::MaxAmmoForAmmoClass( idPlayer *owner, const char *ammo_classname ) const {
	return owner->spawnArgs.GetInt( va( "max_%s", ammo_classname ), "0" );
}

/*
==============
idInventory::AmmoPickupNameForIndex
==============
*/
const char *idInventory::AmmoPickupNameForIndex( ammo_t ammonum ) const {
	return idWeapon::GetAmmoPickupNameForNum( ammonum );
}

/*
==============
idInventory::WeaponIndexForAmmoClass
mapping could be prepared in the constructor
==============
*/
int idInventory::WeaponIndexForAmmoClass( const idDict & spawnArgs, const char *ammo_classname ) const {
	int i;
	const char *weapon_classname;
	for( i = 0; i < MAX_WEAPONS; i++ )
	{
		weapon_classname = spawnArgs.GetString( va( "def_weapon%d", i ) );
		if ( !weapon_classname )
		{
			continue;
		}

		const idDeclEntityDef *decl = gameLocal.FindEntityDef( weapon_classname, false );
		if ( !decl )
		{
			continue;
		}

		if ( !idStr::Icmp( ammo_classname, decl->dict.GetString( "ammoType" ) ) )
		{
			return i;
		}
	}
	return -1;
}

/*
==============
idInventory::AmmoIndexForWeaponClass
==============
*/
ammo_t idInventory::AmmoIndexForWeaponClass( const char *weapon_classname, int *ammoRequired ) {
	const idDeclEntityDef *decl = gameLocal.FindEntityDef( weapon_classname, false );
	if ( !decl ) {
		gameLocal.Error( "Unknown weapon in decl '%s'", weapon_classname );
	}
	if ( ammoRequired ) {
		*ammoRequired = decl->dict.GetInt( "ammoRequired" );
	}
	ammo_t ammo_i = AmmoIndexForAmmoClass( decl->dict.GetString( "ammoType" ) );
	return ammo_i;
}

/*
==============
idInventory::AddPickupName
==============
*/
void idInventory::AddPickupName( const char *name, const char *icon, idPlayer* owner ) { //_D3XP
	
	//BC removing the item pickups from the itempickup info feed.

//	int num;
//	num = pickupItemNames.Num();
//	if ( ( num == 0 ) || ( pickupItemNames[ num - 1 ].name.Icmp( name ) != 0 ) ) {
//		idItemInfo &info = pickupItemNames.Alloc();
//
//		if ( idStr::Cmpn( name, STRTABLE_ID, STRTABLE_ID_LENGTH ) == 0 ) {
//			info.name = common->GetLanguageDict()->GetString( name );
//		} else {
//			info.name = name;
//		}
//		info.icon = icon;
//
//#ifdef _D3XP
//		if ( gameLocal.isServer ) {
//			idBitMsg	msg;
//			byte		msgBuf[MAX_EVENT_PARAM_SIZE];
//
//			msg.Init( msgBuf, sizeof( msgBuf ) );
//			msg.WriteString( name, MAX_EVENT_PARAM_SIZE );
//			owner->ServerSendEvent( idPlayer::EVENT_PICKUPNAME, &msg, false, -1 );
//		}
//	}
//#endif

}

bool idInventory::GiveAmmo(idPlayer *owner, const char *statname, const char *statvalue)
{
    const char				*name = NULL;
	const idDeclEntityDef	*weaponDef = NULL;
	bool showPickupMessage = true;
	int i;
	int max;
	int amount;
	int weapIdx;

	weapIdx = WeaponIndexForAmmoClass( owner->spawnArgs, statname );
	weaponDef = gameLocal.FindEntityDef( owner->spawnArgs.GetString( va( "def_weapon%d", weapIdx ) ), false );
	if ( weaponDef->dict.GetBool( "multiCarry" ) && !weaponDef->dict.GetInt( "ammoRequired" ) ) {
		// SM: If this is multicarry and we aren't doing ammo required, don't show messages related to it
		showPickupMessage = false;
	}

    i = AmmoIndexForAmmoClass(statname);
    max = MaxAmmoForAmmoClass(owner, statname);
    if (ammo[i] >= max) {

        //BC ammo is maxed out.
		if ( showPickupMessage )
			owner->hud->HandleNamedEvent("maxammo");

        return false;
    }
    amount = atoi(statvalue);
    if (amount)
    {
        ammo[i] += amount;
        if ((max > 0) && (ammo[i] > max)) {
            ammo[i] = max;
        }
        ammoPulse = true;

        name = AmmoPickupNameForIndex(i);
        if ( showPickupMessage && idStr::Length(name) )
        {
            //BC Do some grammar. TODO: what the heck was I doing here???? convert this to const char!!!
            //int k;
            //char result[100];
            //for (k = 0; k < 100; k++)
            //{
            //    result[k] = NULL;
            //}
            //sprintf(result, "%d ", amount);
            //strcat(result, name);
			//AddPickupName(result, "", owner); //_D3XP

			idStr outputStr = va("%s (%d)", name, amount);
			AddPickupName(outputStr, "", owner); //_D3XP            
        }
    }

    return true;
}

/*
==============
idInventory::Give
==============
*/
bool idInventory::Give( idPlayer *owner, const idDict &spawnArgs, const char *statname, const char *value, bool updateHud, const char *carryableName, int health, idEntity *ent ) {
	int						i;
	const char				*pos;
	const char				*end;
	int						len;
	idStr					weaponString;
	const idDeclEntityDef	*weaponDecl = nullptr;
	bool					tookWeapon;
	int						amount;



	if ( !idStr::Icmpn( statname, "ammo_", 5 ) )
    {
        //BC this handles the inv_ammo_* keyvalue on item pickups. For example, gives "inv_ammo_riflebullets 5" gives you 5 riflebullets.
		if (atoi(value) <= 0)
			return false;

        return GiveAmmo(owner, statname, value);
	}
    else if ( !idStr::Icmp( statname, "armor" ) )
	{
		if ( armor >= maxarmor )
		{
			return false;	// can't hold any more, so leave the item
		}

		amount = atoi( value );
		if ( amount )
		{
			int amountOfArmorToAdd = amount;

			if (armor + amountOfArmorToAdd > maxarmor)
				amountOfArmorToAdd = maxarmor - armor;

			armor += amountOfArmorToAdd;
			nextArmorDepleteTime = 0;
			armorPulse = true;

			AddPickupName(carryableName, "", owner);

			if (ent != NULL)
			{
				idStr armorStr = idStr::Format("+%d armor", amountOfArmorToAdd);
				owner->SetFlytextEvent(ent->GetPhysics()->GetOrigin(), armorStr.c_str(), idDeviceContext::ALIGN_CENTER);
			}
		}
	}
	/*
	else if ( idStr::FindText( statname, "inclip_" ) == 0 ) {
#ifdef _D3XP
		idStr temp = statname;
		i = atoi(temp.Mid(7, 2));
#else
		i = WeaponIndexForAmmoClass( spawnArgs, statname + 7 );
#endif
		if ( i != -1 ) {
			// set, don't add. not going over the clip size limit.
#ifndef _D3XP
			clip[ i ] = atoi( value );
#endif
		}
	}*/

	//BC retain rounds in magazine.
	else if (idStr::FindText(statname, "inclip_") == 0)
	{
        //BC ok, because of the hotbar system we need to jiggle how this works a bit.
        //So, if the player does NOT have the weapon, then do as normal...
		i = WeaponIndexForAmmoClass(spawnArgs, statname + 7); //get weapon index.
        //int hasWeapon = GetHotbarslotViaWeaponIndex(i);
	
		if (i != -1)
		{
			int slot = GetHotbarslotViaWeaponIndex( i );
            if (slot != -1 && hotbarSlots[slot].clip <= 0)
            {
                //Player has ZERO ammo of this... so do the normal thing here
				hotbarSlots[slot].clip = atoi(value);
            }
            else
            {
                //ammo[i] += atoi(value);
				
				//This is what handles giving the player ammo from a weapon that is picked up from the ground.
				//Basically, the ammo that is inside the weapon's magazine.

				if (ent != NULL && owner != NULL)
				{
					//idStr ammoText = 
					
					int weaponIndex = GetWeaponIndex(owner, ent->spawnArgs.GetBool("isweapon") ? ent->spawnArgs.GetString("inv_weapon") : ent->spawnArgs.GetString("weapon"));
					//const idDeclEntityDef *weaponDef = gameLocal.FindEntityDef(spawnArgs.GetString(va("def_weapon%d", frobitemWeaponIndex)), false);
					int ammoRequired = 0;
					ammo_t ammo_i = AmmoIndexForWeaponClass(spawnArgs.GetString(va("def_weapon%d", weaponIndex)), &ammoRequired);
					idStr ammoName = idWeapon::GetAmmoPickupNameForNum(ammo_i);
					idStr ammopickupStr = idStr::Format("+%s %s", value, ammoName.c_str());
					owner->SetFlytextEvent(ent->GetPhysics()->GetOrigin(), ammopickupStr.c_str(), idDeviceContext::ALIGN_CENTER);
				}

                return GiveAmmo(owner, statname + 7, value);
            }
		}
	}
	else if (idStr::FindText(statname, "inchamber_") == 0)
	{
		//give ammo that was in the weapon chamber.
		i = WeaponIndexForAmmoClass(spawnArgs, statname + 10); //get weapon index.
		if (i != -1)
		{
			if (ent != NULL && owner != NULL)
			{
				int weaponIndex = GetWeaponIndex(owner, ent->spawnArgs.GetBool("isweapon") ? ent->spawnArgs.GetString("inv_weapon") : ent->spawnArgs.GetString("weapon"));
				int ammoRequired = 0;
				ammo_t ammo_i = AmmoIndexForWeaponClass(spawnArgs.GetString(va("def_weapon%d", weaponIndex)), &ammoRequired);
				idStr ammoName = idWeapon::GetAmmoPickupNameForNum(ammo_i);
				idStr ammopickupStr = idStr::Format("+%s %s", value, ammoName.c_str());
				owner->SetFlytextEvent(ent->GetPhysics()->GetOrigin(), ammopickupStr.c_str(), idDeviceContext::ALIGN_CENTER);
			}

			return GiveAmmo(owner, statname + 10, value);			
		}
	}
	else if ( !idStr::Icmp( statname, "invulnerability" ) )
	{
		owner->GivePowerUp( INVULNERABILITY, SEC2MS( atof( value ) ) );
	}
	else if ( !idStr::Icmp( statname, "helltime" ) )
	{
		owner->GivePowerUp( HELLTIME, SEC2MS( atof( value ) ) );
	}
	else if ( !idStr::Icmp( statname, "envirosuit" ) )
	{
		owner->GivePowerUp( ENVIROSUIT, SEC2MS( atof( value ) ) );
		owner->GivePowerUp( ENVIROTIME, SEC2MS( atof( value ) ) );
	}
	else if ( !idStr::Icmp( statname, "berserk" ) )
	{
		owner->GivePowerUp( BERSERK, SEC2MS( atof( value ) ) );
	}
	else if ( !idStr::Icmp( statname, "haste" ) )
	{
		owner->GivePowerUp( HASTE, SEC2MS( atof( value ) ) );
	}
	else if ( !idStr::Icmp( statname, "mega" ) ) {
		GivePowerUp( owner, MEGAHEALTH, SEC2MS( atof( value ) ) );
	}
	else if ( !idStr::Icmp( statname, "weapon" ) )
	{
		tookWeapon = false;
		bool autoSwitch = false;
		for( pos = value; pos != NULL; pos = end ) {
			end = strchr( pos, ',' );
			if ( end ) {
				len = end - pos;
				end++;
			} else {
				len = strlen( pos );
			}

			idStr weaponName( pos, 0, len );

			// find the number of the matching weapon name
			for( i = 0; i < MAX_WEAPONS; i++ ) {
				if ( weaponName == spawnArgs.GetString( va( "def_weapon%d", i ) ) ) {
					break;
				}
			}

			if ( i >= MAX_WEAPONS ) {
				gameLocal.Error( "Unknown weapon '%s'. Check def_weapon list in player.def", weaponName.c_str() );
				return false;
			}

			// cache the media for this weapon
			weaponDecl = gameLocal.FindEntityDef( weaponName, false );

			// SM: Figure out if we have this weapon already and multipickup isn't allowed
			int slot = GetHotbarslotViaWeaponIndex( i );
			bool isMultiCarry = weaponDecl->dict.GetBool( "multiCarry" );
			if ( weaponDecl && slot != -1 && !isMultiCarry )
			{
				//BC don't let player pick up multiple weapons which are not multicarry.


				//if it gives ammo to player (i.e. rifle or shotgun), then we want to suppress the 'you already have this' message.
				const idKeyValue *ammoKeyvalue = weaponDecl->dict.MatchPrefix("inv_ammo_");
				if (!ammoKeyvalue)
				{
					owner->hud->HandleNamedEvent("alreadyhave");
				}


				continue;
			}			


			if ( !gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) || ( weaponName == "weapon_fists" ) || ( weaponName == "weapon_soulcube" ) )
			{
				if ( slot == -1 || isMultiCarry || gameLocal.isMultiplayer || IsAutoswitchWeapon(weaponName, owner))
				{
					//BC this gets called when you pick up an item that's currently not in your inventory.
					
					if (IsAutoswitchWeapon(weaponName, owner))
					{
						assert(!gameLocal.isClient);
						autoSwitch = true;
					}

					/* BC disable autoswitch.
					if ( owner->GetUserInfo()->GetBool( "ui_autoSwitch" ) && idealWeapon )
					{
						assert( !gameLocal.isClient );
						*idealWeapon = i;
					}*/

					//BC allow autoswitch if player is in unarmed state.
					if (owner->currentWeaponSlot == -1 || hotbarSlots[owner->currentWeaponSlot].weaponType <= 0)
					{
						assert(!gameLocal.isClient);
						autoSwitch = true;
					}

					if ( owner->hud && updateHud && lastGiveTime + 1000 < gameLocal.time )
					{
						owner->hud->SetStateInt( "newWeapon", i );
						owner->hud->HandleNamedEvent( "newWeapon" );
						lastGiveTime = gameLocal.time;
					}
					weaponPulse = true;
					tookWeapon = true;
				}
			}
		}

		if (tookWeapon)
		{
			//update hud notifications.

			idStr weaponDisplayname = weaponDecl->dict.GetString("displayname");
			
			//If displayname is blank, then try to fall back to the carryable name.
			if (weaponDisplayname[0] == '\0' && carryableName[0] != '\0')
			{
				weaponDisplayname = carryableName;
			}
			
			if (weaponDisplayname[0] != '\0')
			{
				AddPickupName(weaponDisplayname.c_str(), "", owner); //This is the pickup message that appears on the right-hand side of screen.
				owner->AssignHotbarSlot(weaponDecl->dict.GetString("inv_weapon"), weaponDisplayname.c_str(), health, autoSwitch, ent); //assign hotbar name.
				
				gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_pickedup"), common->GetLanguageDict()->GetString(weaponDisplayname.c_str())), owner->GetPhysics()->GetOrigin(), false);

				if (owner == gameLocal.GetLocalPlayer())
				{
					gameLocal.GetLocalPlayer()->JustPickedupItem(ent);
				}				
			}
		}

		return tookWeapon;
	} else if ( !idStr::Icmp( statname, "item" ) || !idStr::Icmp( statname, "icon" ) || !idStr::Icmp( statname, "name" ) || !idStr::Icmp(statname, "carry") //BC
		
		) {
		// ignore these as they're handled elsewhere
		return false;
	} else {
		// unknown item
		gameLocal.Warning( "Unknown stat '%s' added to player's inventory", statname );
		return false;
	}

	UpdateInventoryCollision();

	return true;
}

/*
===============
idInventoy::Drop
===============
*/
void idInventory::Drop( int hotbarSlot )
{
	if ( hotbarSlot >= 0 && hotbarSlot < MAX_HOTBARSLOTS ) {
		ResetHotbarSlot( hotbarSlot );
	}
}

/*
===============
idInventory::HasAmmo
===============
*/
int idInventory::HasAmmo( ammo_t type, int amount ) {
	if ( ( type == 0 ) || !amount ) {
		// always allow weapons that don't use ammo to fire
		return -1;
	}

	// check if we have infinite ammo
	if ( ammo[ type ] < 0 ) {
		return -1;
	}

	// return how many shots we can fire
	return ammo[ type ] / amount;

}

/*
===============
idInventory::HasAmmo
===============
*/
int idInventory::HasAmmo( const char *weapon_classname, bool includeClip, idPlayer* owner ) {		//_D3XP
	int ammoRequired;
	ammo_t ammo_i = AmmoIndexForWeaponClass( weapon_classname, &ammoRequired );

#ifdef _D3XP
	int ammoCount = HasAmmo( ammo_i, ammoRequired );
	if(includeClip && owner) {
		int hotbarSlot = GetHotbarslotViaWeaponIndex( owner->SlotForWeapon( weapon_classname ) );
		if ( hotbarSlot != -1 ) {
			ammoCount += Max( 0, hotbarSlots[hotbarSlot].clip );
		}
	}
	return ammoCount;
#else
	return HasAmmo( ammo_i, ammoRequired );
#endif

}

#ifdef _D3XP
/*
===============
idInventory::HasEmptyClipCannotRefill
===============
*/
bool idInventory::HasEmptyClipCannotRefill(int hotBarslot, const char *weapon_classname, idPlayer* owner) {

	int clipSize = hotbarSlots[hotBarslot].clip;
	if(clipSize) {
		return false;
	}

	const idDeclEntityDef *decl = gameLocal.FindEntityDef( weapon_classname, false );
	if ( !decl ) {
		gameLocal.Error( "Unknown weapon in decl '%s'", weapon_classname );
	}
	int minclip = decl->dict.GetInt("minclipsize");
	if(!minclip) {
		return false;
	}

	ammo_t ammo_i = AmmoIndexForAmmoClass( decl->dict.GetString( "ammoType" ) );
	int ammoRequired = decl->dict.GetInt( "ammoRequired" );
	int ammoCount = HasAmmo( ammo_i, ammoRequired );
	if(ammoCount < minclip) {
		return true;
	}
	return false;
}
#endif

bool idInventory::IsAutoswitchWeapon(const char *weapon_classname, idPlayer* owner)
{
	const idDeclEntityDef *decl = gameLocal.FindEntityDef(weapon_classname, false);
	if (!decl) {
		gameLocal.Error("Unknown weapon in decl '%s'", weapon_classname);
	}

	return decl->dict.GetBool("autoswitch", "0");
}





/*
===============
idInventory::UseAmmo
===============
*/
bool idInventory::UseAmmo( ammo_t type, int amount ) {
	if ( !HasAmmo( type, amount ) ) {
		return false;
	}

	// take an ammo away if not infinite
	if ( ammo[ type ] >= 0 ) {
		ammo[ type ] -= amount;
		ammoPredictTime = gameLocal.time; // mp client: we predict this. mark time so we're not confused by snapshots
	}

	return true;
}

/*
===============
idInventory::UpdateArmor
===============
*/
void idInventory::UpdateArmor( void ) {
	if ( deplete_armor != 0.0f && deplete_armor < armor ) {
		if ( !nextArmorDepleteTime ) {
			nextArmorDepleteTime = gameLocal.time + deplete_rate * 1000;
		} else if ( gameLocal.time > nextArmorDepleteTime ) {
			armor -= deplete_ammount;
			if ( armor < deplete_armor ) {
				armor = deplete_armor;
			}
			nextArmorDepleteTime = gameLocal.time + deplete_rate * 1000;
		}
	}
}

#ifdef _D3XP
/*
===============
idInventory::InitRechargeAmmo
===============
* Loads any recharge ammo definitions from the ammo_types entity definitions.
*/
void idInventory::InitRechargeAmmo(idPlayer *owner) {

	memset (rechargeAmmo, 0, sizeof(rechargeAmmo));

	const idKeyValue *kv = owner->spawnArgs.MatchPrefix( "ammorecharge_" );
	while( kv ) {
		idStr key = kv->GetKey();
		idStr ammoname = key.Right(key.Length()- strlen("ammorecharge_"));
		int ammoType = AmmoIndexForAmmoClass(ammoname);
		rechargeAmmo[ammoType].ammo = (atof(kv->GetValue().c_str())*1000);
		strcpy(rechargeAmmo[ammoType].ammoName, ammoname);
		kv = owner->spawnArgs.MatchPrefix( "ammorecharge_", kv );
	}
}

/*
===============
idInventory::RechargeAmmo
===============
* Called once per frame to update any ammo amount for ammo types that recharge.
*/
void idInventory::RechargeAmmo(idPlayer *owner) {

	for(int i = 0; i < AMMO_NUMTYPES; i++) {
		if(rechargeAmmo[i].ammo > 0) {
			if(!rechargeAmmo[i].rechargeTime)  {
				//Initialize the recharge timer.
				rechargeAmmo[i].rechargeTime = gameLocal.time;
			}
			int elapsed = gameLocal.time - rechargeAmmo[i].rechargeTime;
			if(elapsed >= rechargeAmmo[i].ammo) {
				int intervals = (gameLocal.time - rechargeAmmo[i].rechargeTime)/rechargeAmmo[i].ammo;
				ammo[i] += intervals;

				int max = MaxAmmoForAmmoClass(owner, rechargeAmmo[i].ammoName);
				if(max > 0) {
					if(ammo[i] > max) {
						ammo[i] = max;
					}
				}
				rechargeAmmo[i].rechargeTime += intervals*rechargeAmmo[i].ammo;
			}
		}
	}
}

/*
===============
idInventory::CanGive
===============
*/
bool idInventory::CanGive( idPlayer *owner, const idDict &spawnArgs, const char *statname, const char *value ) {

	if ( !idStr::Icmp( statname, "item" ) || !idStr::Icmp( statname, "icon" ) || !idStr::Icmp( statname, "name" ) ) {
		// ignore these as they're handled elsewhere
		//These items should not be considered as succesful gives because it messes up the max ammo items
		return false;
	}
	return true;
}


//Return the index of the first available empty slot. If nothing is available, then return -1.
int idInventory::GetEmptyHotbarSlot()
{
	//iterate over all slots. Return the first free empty slot.
	for (int i = 0; i < Min(MAX_HOTBARSLOTS, hotbarUnlockedSlots); i++)
	{
		if (hotbarSlots[i].weaponType <= 0)
			return i;
	}

	return -1;
}

int idInventory::GetWeaponIndex(idPlayer *owner, const char *weaponName)
{
	for (int i = 0; i < MAX_WEAPONS; i++)
	{
		const char *weap = owner->spawnArgs.GetString(va("def_weapon%d", i));

		if (!idStr::Icmp(weap, weaponName))
		{
			return i;
		}
	}

	return -1;
}

bool idInventory::SetHotbarSlot(idPlayer *owner, int slotIndex, int weaponIndex, int health, idEntity *ent)
{
	if ( slotIndex < 0 || slotIndex >= MAX_HOTBARSLOTS )
		return false;

	hotbarSlots[slotIndex].weaponType = weaponIndex; //Assign weapon to slot.
	hotbarSlots[slotIndex].health = health;
	hotbarSlots[slotIndex].carryPtr = ent;

	UpdateInventoryCollision();
	return true;
}

int idInventory::GetHotbarslotViaWeaponIndex(int weaponIndex)
{
	for (int i = 0; i < Min(MAX_HOTBARSLOTS, hotbarUnlockedSlots); i++)
	{
		if (hotbarSlots[i].weaponType == weaponIndex)
			return i;
	}

	return -1;
}

void idInventory::UpdateInventoryCollision(idEntity * changedEnt)
{
	for (int idx = 0; idx < Min(MAX_HOTBARSLOTS, hotbarUnlockedSlots); idx++)
	{
		idEntity * curItem = hotbarSlots[idx].carryPtr.GetEntity();
		if(curItem)
		{
			if (idx == GetHotbarSelection())
			{
				curItem->GetPhysics()->EnableClip();
			}
			else
			{
				curItem->GetPhysics()->DisableClip();
			}

			// no need to do a final update on the changedEnt
			if(curItem == changedEnt)
			{
				changedEnt = nullptr;
			}
		}
	}

	// if no longer held, activate clip
	if( changedEnt )
	{
		changedEnt->GetPhysics()->EnableClip();
	}
}

void idInventory::SetHotbarSelection( int value )
{
	if(value >= 0 && value < Min(MAX_HOTBARSLOTS, hotbarUnlockedSlots))
	{
		hotbarCurrentlySelected = value;
		UpdateInventoryCollision();
	}
}

void idInventory::ResetHotbarSlot( int hotbarSlot )
{
	hotbarSlots[hotbarSlot].weaponType = 0; // set to unarmed
	hotbarSlots[hotbarSlot].clip = -1; // set to -1 so that the gun knows to have a full clip the first time we get it and at the start of the level
	hotbarSlots[hotbarSlot].chambered = true;
	hotbarSlots[hotbarSlot].health = 0;
	idEntity * droppedEnt = hotbarSlots[hotbarSlot].carryPtr.GetEntity();
	hotbarSlots[hotbarSlot].carryPtr = NULL;

	UpdateInventoryCollision(droppedEnt);
}


#endif

/*
==============
idPlayer::idPlayer
==============
*/
idPlayer::idPlayer()
{
	memset( &usercmd, 0, sizeof( usercmd ) );

	noclip					= false;
	godmode					= false;

	spawnAnglesSet			= false;
	spawnAngles				= ang_zero;
	viewAngles				= ang_zero;
	cmdAngles				= ang_zero;

	oldButtons				= 0;
	buttonMask				= 0;
	oldFlags				= 0;

	lastHitTime				= 0;
	lastSndHitTime			= 0;
	lastSavingThrowTime		= 0;

	weapon					= NULL;

	hud						= NULL;
	objectiveSystem			= NULL;
	objectiveSystemOpen		= false;

#ifdef _D3XP
	mountedObject			= NULL;
	enviroSuitLight			= NULL;
#endif

	heartRate				= BASE_HEARTRATE;
	heartInfo.Init( 0, 0, 0, 0 );
	lastHeartAdjust			= 0;
	lastHeartBeat			= 0;
	heartbeatEnabled		= true;
	lastDmgTime				= 0;
	deathClearContentsTime	= 0;
	lastArmorPulse			= -10000;
	stamina					= 0.0f;
	healthPool				= 0.0f;
	nextHealthPulse			= 0;
	healthPulse				= false;
	nextHealthTake			= 0;
	healthTake				= false;

	

	scoreBoardOpen			= false;
	forceScoreBoard			= false;
	forceRespawn			= false;
	spectating				= false;
	spectator				= 0;
	colorBar				= vec3_zero;
	colorBarIndex			= 0;
	forcedReady				= false;
	wantSpectate			= false;

#ifdef CTF
	carryingFlag			= false;
#endif

	lastHitToggle			= false;

	minRespawnTime			= 0;
	maxRespawnTime			= 0;

	firstPersonViewOrigin	= vec3_zero;
	firstPersonViewAxis		= mat3_identity;

	hipJoint				= INVALID_JOINT;
	chestJoint				= INVALID_JOINT;
	headJoint				= INVALID_JOINT;

	bobFoot					= 0;
	bobFrac					= 0.0f;
	bobfracsin				= 0.0f;
	bobCycle				= 0;
	xyspeed					= 0.0f;
	stepUpTime				= 0;
	stepUpDelta				= 0.0f;
	stepUpCorrection		= 0.0f;
	idealLegsYaw			= 0.0f;
	legsYaw					= 0.0f;
	legsForward				= true;
	oldViewYaw				= 0.0f;
	viewBobAngles			= ang_zero;
	viewBob					= vec3_zero;
	landChange				= 0;
	landTime				= 0;

	currentWeaponSlot		= -1;
	idealWeaponSlot			= -1;
	previousWeaponSlot		= -1;
	weaponSwitchTime		=  0;
	weaponEnabled			= true;
	weapon_soulcube			= -1;
	weapon_pda				= -1;
	weapon_fists			= -1;
#ifdef _D3XP


	hudPowerup				= -1;
	lastHudPowerup			= -1;
	hudPowerupDuration		= 0;
#endif
	showWeaponViewModel		= true;

	skin					= NULL;
	powerUpSkin				= NULL;
	baseSkinName			= "";

	numProjectilesFired		= 0;
	numProjectileHits		= 0;

	airless					= false;
	airTics					= 0.0f;
	lastAirDamage			= 0;

	gibDeath				= false;
	gibsLaunched			= false;
	gibsDir					= vec3_zero;

	zoomFov.Init( 0, 0, 0, 0 );
	centerView.Init( 0, 0, 0, 0 );
	fxFov					= false;

	influenceFov			= 0;
	influenceActive			= 0;
	influenceRadius			= 0.0f;
	influenceEntity			= NULL;
	influenceMaterial		= NULL;
	influenceSkin			= NULL;

	privateCameraView		= NULL;

	memset( loggedViewAngles, 0, sizeof( loggedViewAngles ) );
	memset( loggedAccel, 0, sizeof( loggedAccel ) );
	currentLoggedAccel	= 0;

	focusTime				= 0;
	focusGUIent				= NULL;
	focusUI					= NULL;
	focusCharacter			= NULL;
	talkCursor				= 0;
	focusVehicle			= NULL;
	cursor					= NULL;

	oldMouseX				= 0;
	oldMouseY				= 0;

	pdaAudio				= "";
	pdaVideo				= "";
	pdaVideoWave			= "";

	lastDamageDef			= 0;
	lastDamageDir			= vec3_zero;
	lastDamageLocation		= 0;
	smoothedFrame			= 0;
	smoothedOriginUpdated	= false;
	smoothedOrigin			= vec3_zero;
	smoothedAngles			= ang_zero;

	fl.networkSync			= true;

	latchedTeam				= -1;
	doingDeathSkin			= false;
	weaponGone				= false;
	useInitialSpawns		= false;
	tourneyRank				= 0;
	lastSpectateTeleport	= 0;
	tourneyLine				= 0;
	hiddenWeapon			= false;
	tipUp					= false;
	objectiveUp				= false;
	teleportEntity			= NULL;
	teleportKiller			= -1;
	respawning				= false;
	ready					= false;
	leader					= false;
	lastSpectateChange		= 0;
	lastTeleFX				= -9999;
	weaponCatchup			= false;
	lastSnapshotSequence	= 0;

	MPAim					= -1;
	lastMPAim				= -1;
	lastMPAimTime			= 0;
	MPAimFadeTime			= 0;
	MPAimHighlight			= false;

	spawnedTime				= 0;
	lastManOver				= false;
	lastManPlayAgain		= false;
	lastManPresent			= false;

	isTelefragged			= false;

	isLagged				= false;
	isChatting				= false;

	selfSmooth				= false;

	//BC reset variables.
	videoMenu = NULL;
	cameraGuiMenu = NULL;
	contextMenu = NULL;
	contextMenuActive = false;
	contextMenuSoundSpeed = 1.0f;
	soundSlowmoActive = false;
	nextContextMenuAvailableTime = 0;
	nextContextMenuCloseTime = 0;
	contextMenuForbiddenAlertTimer = 0;
	contextMenuState = CONTEXTMENU_OFF;
	contextmenuStartTime = 0;

	viewposTargetOffset = idVec3(0,0,0);
	viewposOffset = idVec3(0, 0, 0);
	viewposState = LERPSTATE_OFF;
	viewposStarttime = 0;

	viewpitchState = LERPSTATE_OFF;
	viewyawState = LERPSTATE_OFF;
	viewrollState = LERPSTATE_OFF;

	leanState = LEANSTATE_OFF;
	confinedstateTimer = 0;
	inConfinedState = false;
	confinedAngleLock = false;
	confinedAngle = 0;
	confinedDustTimer = 0;
	lastConfinedState = false;
    spaceparticleTimer = 0;
	forceSpaceParticles = false;


	frobState = FROBSTATE_NONE;
	frobEnt = NULL;
	lastFrobNumber = -1;
	frobFlashTimer = 0;
	frobHitpos = vec3_zero;
	frobHoldTimer = -1.0f;

	autoaimDefaultPosition = idVec2(320, 240);
	autoaimDotPosition = autoaimDefaultPosition;



	autoaimDotState = AUTOAIMDOTSTATE_IDLE;
	autoaimDotTimer = 0;
	autoaimPos = vec3_zero;

	int i;
	

	for (i = 0; i < DAMAGEARROW_COUNT; i++)
	{
		damageArrowPosition[i] = vec3_zero;
		damageArrowTimers[i] = 0;
	}


	reloadButtonTimer = 0;
	rackslideButtonTimer = 0;

	healthrechargeTimer = 0;
	healthDeclineTimer = 0;
	readyForHealthrechargeSound = false;

	lastHealthValue = 0;
	lastHealthTimer = 0;
	lastHealthState = LASTHEALTH_OFF;

	cond_burnwound = 0;
	lastBurnwoundTime = 0;
	burningTimer = 0;
	burningDOTTimer = 0;
	cond_glasswound = 0;
	cond_bulletwound = 0;
	lastBulletwoundTimer = 0;
	cond_shrapnel = 0;
	cond_spearwound = 0;
	cond_smelly = 0;
	smellyTimer = 0;
	lastSmellPosition = vec3_zero;

	lastChemDamageTime = 0;
	playerInChemTimer = 0;

	glasswoundMoveTimer = 0;
	glasswoundFoot = 0;

	healthFadeTimer = 0;
	healthFadeMaxedBool = false;
	healthbarIsFaded = true;

	healState = HEALSTATE_NONE;

	viewYawLockAngle = 0;
	viewYawLocked = false;

	viewPitchLockAngle = 0;
	viewPitchLocked = false;

	footBloodDecalCount = 0;

	bodyAngleLocked = false;

	lastAcroState = ACROTYPE_NONE;

	sneezeValue = 0;
	nextSneezeTimer = 0;
	sneezeState = SNEEZESTATE_ACCUMULATING;
	lastPlayerPosition = vec3_zero;
	sneezeUpdateTimer = 0;
	sneezeVOTimer = 0;

	healthDamageFlashTimer = 0;

	inDownedState = 0;
	downedTickTimer = 0;

	for (i = 0; i < NOISEEVENT_COUNT; i++)
	{
		noiseEventTimer[i] = 0;
		noiseEventPos[i] = vec3_zero;
		noiseEventType[i] = 0;
	}

	for (i = 0; i < FLYTEXT_COUNT; i++)
	{
		flytext[i].timer = 0;
		flytext[i].pos = vec3_zero;
		flytext[i].text = "";
		flytext[i].textAlign = 0;
	}

	deafenState = DEAFEN_NONE;
	deafenTimer = 0;

	lastAttackDir = vec3_zero;

	downedDecalTimer = 0;
	lastDownedPlayerPosition = vec3_zero;

	lastTargetHeartRate = HEARTRATE_SLOWEST;
	lastHeartVolumeAdjust = 0;
	heartVolume = -40;

	savingthrowState = SAVINGTHROW_AVAILABLE;
	grenadeButtonTimer = 0;
	grenadeThrowState = GRENADETHROW_IDLE;
	shouldDrawThrowArc = false;
	lastThrowArcState = false;
	throwWeaponPhysicsObj = NULL;

	throwPredictionIntegrator = new idODE_Euler(sizeof(rigidBodyIState_t) / sizeof(float), RigidBodyDerivatives, NULL);

	placerClearance = false;
	placerEntityNumber = -1;
	placerEntityCollisionID = -1;

	buttonpromptType = -1;
	buttonpromptTimer = 0;

	viewpitchTransitionTime = 0;

	defibAvailable = true;
	defibState = DEFIB_NONE;
	defibFadeDone = false;
	defibButtonTimer = 0;
	defibButtonCount = 0;
	defibYaw = 0;


	lastBaffleState = 0;
	currentYawDelta = 0;

	bloodbagState = BLOODBAGSTATE_NONE;
	bloodbagTimer = 0;
	bloodbagHealth = HEALTH_BLOODBAG_DEFAULTHEALTH;
	bloodbagDamageTimer = 0;
	

	mountedMech = NULL;
	mechStartupstate = false;
	mechSpeedTimer = 0;
	mechTransitionState = MECHTRANSITION_NONE;

	autoaimEnt = NULL;

	lastGlasswoundTime = 0;

	codeStartTime = 0; // Start time for the current dot/dash
	isEnteringCode = false; // Currently entering morse code string
	signalLock = false; // Is signal locked on?
	lastSignalLockUpdate = 0; // When did we last update the signal lock-on state?
	lastBeaconPosition = vec3_zero; // What is the beacon vector's position?

	beaconUITimer = 0;
	beaconCode = "";
	beaconFlashState = false;
	beaconFlashTimer = 0;
	beaconUIBlink = false;
	beaconUIBlinkTimer = 0;

	nextAttackTime = 0;

	meleeTarget = NULL;

	confinedStealthActive = true;
	confinedlimitsoundTimer = 0;
	confinedRustlesoundTimer = 0;
	confinedRustlesoundLastPos = vec3_zero;

	ventpeekRustleTimer = 0;

	playingSuspicionSound = false;


	viewposAbsTimer = 0;
	viewposAbsActive = false;
	viewposAbsTarget = vec3_zero;
	viewposAbsStart = vec3_zero;

	peekObject = NULL;

	carryableItem = NULL;

	armstatsActive = false;
	armstatsState = ARMST_DORMANT;
	armstatsTimer = 0;

	listenmodeActive = false;
	lastListenmodeActive = false;
	listenmodePos = vec3_zero;
	listenmodeVisualizerTime = 0;

	beaconLingerTimer = 0;

    lastLocationEntityNum = -1;

	lastLuminanceUpdate = 0;
	luminance = 0.0f;
	luminanceState = 0;
	lastLuminanceState = 0;

	eventlogMenu = NULL;
	eventlogMenuActive = false;
	
	levelselectMenu = NULL;
	levelselectMenuActive = false;

	emailFullscreenMenu = NULL;
	emailFullscreenState = EFS_OFF;
	emailFullscreenTimer = 0;
	emailFullscreenOriginalPlayerViewangle = idAngles(0, 0, 0);
	emailInSubMenu = false;


	spectatorMenu = NULL;

	carryableBashActive = false;
	carryableBashTimer = 0;

	zoommodeActive = false;
	zoombuttonTimer = 0;
	zoomWaitingForInitialRelease = false;
	zoomManualInspect = false;


	impactslowmoActive = false;
	impactslowmoTimer = 0;

	lastRulerState = false;

	

	trashchuteFocus = NULL;

	isWeaponselectPaused = false;
	weaponselectPauseTimer = 0;

	healthcloudActive = false;
	healthcloudTimer = 0;

	mushroomDisplayTimer = 0;

	lastLeanState = 0;
	leanCarryableTimer = 0;

	zoomCurrentFOV = ZOOM_MAX;

	
	oxygenmeterIsFaded = false;
	oxygenmeterFadeTimer = 0;
	oxygenFreezeTimer = 0;

	cameraspliceActive = false;
	cameraspliceChannel = 0;
	nextCameraspliceChannelTime = 0;

	inputReadyForTakedown = false;

	jockeyState = JCK_INACTIVE;

	spectateTimer = 0;
	spectateState = SPC_NONE;

	eliminationCounter = 0;

	toggleCrouch = false;
	teleportCrouchTime = -TELEPORTCROUCH_EASE_TIME;

	beaconLastStrength = 0;
	beaconLastVertArrows = false;

	cond_gascloud = false;
	gascloud_timer = 0;
	gascloud_coughtimer = 0;

	isFrozen = FROZ_NONE;

	listenProbeTimer = 0;
	listenProbemodeActive = false;

	fovLerpStart = 0;	
	fovLerpEnd = 0;
	fovLerpTimer = 0;
	fovLerpState = FOVLERP_NONE;
	fovLerpCurrent = 0;
	fovLerpStartTime = 0;

	scriptedBlur = false;

	playerCanFrob = true;

	inspectLerpTimer = 0;
	inspectLerpState = INSP_NONE;

	exitLevelHoldTimer = 0;
	exitLevelButtonAvailable = true;
	postgameLoadButtonAvailable = false;

	didInitialSpawn = false;




	coins = 0;

	jockeyTimer = 0;
	lastAvailableJockeyAttacktype = -1;

	knockeddownLastSpeed = 0;

	zoominspectEntityPtr = NULL;

	zoominspect_LabelmodeActive = false;
	zoominspect_LabelmodePosition = vec3_zero;
	zoominspect_LabelmodeAngle = idAngles( 0, 0, 0 );
	zoominspect_lerptimer = 0;
	zoominspect_lerpStartPos = vec3_zero;
	zoominspect_lerpStartAngle = idAngles(0, 0, 0);
	zoominspect_previousEntNum = -1;

	healbarTotalTime = 0;
	healbarStartTime = 0;

	throwarcDropMode = false;
	lastThrowarcDropMode = false;

	vo_chamberchecktimer = 0;
	hasSaidChambercheckVO = false;

	vo_reloadchecktimer = 0;
	hasSaidReloadcheckVO = false;


	pickpocketPipCount = 0;
	pickpocketPipTimer = 0;
	pickpocketState = PP_NONE;
	pickpocketEnt = NULL;
	pickpocketGoodRange = true;
	lastPickpocketGoodRange = true;

	armstatDoorlockNeedsUpdate = true;
	armstatDoorlockUpdateTimer = 1000;

	armstatFuseboxNeedsUpdate = false;
	armstatFuseboxUpdateTimer = 0;

	cryoexitEntNum = 0;

	memorypalaceState = MEMP_NONE;
	memorypalaceTimer = 0;
	memorypalacePlayerPos = vec3_zero;
	memoryLight = NULL;
	memorypalaceForwardView = vec3_zero;

	playerTouchedByCenterLight = false;

	isFallDamageImmune = false;

	gameLocal.persistentLevelInfo.GetInt(PERSISTVAR_LEVELPROGRESS, "0", levelProgressIndex);

	levelselectGuiList = NULL;

	spectateUIActive = true;
	spectateStatsActive = true;

	spectateTimelineEnt = NULL;

	currentlyActiveEmailInbox = -1; //which email inbox is the player looking at.
	activeEmailInboxTimer = 0;
	emailInboxCheckActive = false;

	roqVideoStateActive = false;

	defibParticleDone = false;
	defibParticleTimer = 0;

	isTitleFlyMode = false;

	particleStreamDestination = vec3_zero;
	particlestreamTimer = -1;
	particleStreamEnt = NULL;

	showPlayerBody_Scripted = true;

	defibButtonState = false;

	lastLocboxtriggerState = false;

	//BC reset variables end
	//idplayer::idplayer end

	armstatMode = AMOD_MAP;

	escapedFullScreenMenu = false;

	doForceSpatter = false;
	forceSpatterAmount = 0;

	fallenRollTimer = 0.0f;
}

/*
==============
idPlayer::LinkScriptVariables

set up conditions for animation
==============
*/
void idPlayer::LinkScriptVariables( void ) {
	AI_FORWARD.LinkTo(			scriptObject, "AI_FORWARD" );
	AI_BACKWARD.LinkTo(			scriptObject, "AI_BACKWARD" );
	AI_STRAFE_LEFT.LinkTo(		scriptObject, "AI_STRAFE_LEFT" );
	AI_STRAFE_RIGHT.LinkTo(		scriptObject, "AI_STRAFE_RIGHT" );
	AI_ATTACK_HELD.LinkTo(		scriptObject, "AI_ATTACK_HELD" );
	AI_WEAPON_FIRED.LinkTo(		scriptObject, "AI_WEAPON_FIRED" );
	AI_JUMP.LinkTo(				scriptObject, "AI_JUMP" );
	AI_DEAD.LinkTo(				scriptObject, "AI_DEAD" );
	AI_CROUCH.LinkTo(			scriptObject, "AI_CROUCH" );
	AI_ONGROUND.LinkTo(			scriptObject, "AI_ONGROUND" );
	AI_ONLADDER.LinkTo(			scriptObject, "AI_ONLADDER" );
	AI_HARDLANDING.LinkTo(		scriptObject, "AI_HARDLANDING" );
	AI_SOFTLANDING.LinkTo(		scriptObject, "AI_SOFTLANDING" );
	AI_RUN.LinkTo(				scriptObject, "AI_RUN" );
	AI_PAIN.LinkTo(				scriptObject, "AI_PAIN" );
	AI_RELOAD.LinkTo(			scriptObject, "AI_RELOAD" );
	AI_TELEPORT.LinkTo(			scriptObject, "AI_TELEPORT" );
	AI_TURN_LEFT.LinkTo(		scriptObject, "AI_TURN_LEFT" );
	AI_TURN_RIGHT.LinkTo(		scriptObject, "AI_TURN_RIGHT" );

	AI_HEAL_GLASSWOUND.LinkTo(	scriptObject, "AI_HEAL_GLASSWOUND");
	AI_HEAL_BURNING.LinkTo(		scriptObject, "AI_HEAL_BURNING");
	AI_HEAL_BLEEDOUT.LinkTo(	scriptObject, "AI_HEAL_BLEEDOUT");
	AI_HEAL_BULLETPLUCK.LinkTo(scriptObject, "AI_HEAL_BULLETPLUCK");
	AI_HEAL_SHRAPNEL.LinkTo(scriptObject, "AI_HEAL_SHRAPNEL");
	AI_HEAL_HEALWOUND.LinkTo(scriptObject, "AI_HEAL_HEALWOUND");
	AI_ACRO_CEILINGHIDE.LinkTo( scriptObject, "AI_ACRO_CEILINGHIDE");
	AI_ACRO_SPLITS.LinkTo(		scriptObject, "AI_ACRO_SPLITS");
	AI_ACRO_SPLITS_DOWN.LinkTo(	scriptObject, "AI_ACRO_SPLITS_DOWN");
	AI_FALLEN.LinkTo(			scriptObject, "AI_FALLEN");
	AI_FALLEN_GETUP.LinkTo(		scriptObject, "AI_FALLEN_GETUP");
	AI_FALLEN_ROLL.LinkTo(		scriptObject, "AI_FALLEN_ROLL");
	AI_HEAL_SPEARPLUCK.LinkTo(scriptObject, "AI_HEAL_SPEARPLUCK");
	AI_JOCKEYRIDE.LinkTo(scriptObject, "AI_JOCKEYRIDE");
}

/*
==============
idPlayer::SetupWeaponEntity
==============
*/
void idPlayer::SetupWeaponEntity( void ) {
	int w;
	const char *weap;

	if ( weapon.GetEntity() ) {
		// get rid of old weapon
		weapon.GetEntity()->Clear();
		currentWeaponSlot = -1;
	} else if ( !gameLocal.isClient ) {
		weapon = static_cast<idWeapon *>( gameLocal.SpawnEntityType( idWeapon::Type, NULL ) );
		weapon.GetEntity()->SetOwner( this );
		currentWeaponSlot = -1;
	}

	for( w = 0; w < MAX_WEAPONS; w++ ) {
		weap = spawnArgs.GetString( va( "def_weapon%d", w ) );
		if ( weap && *weap ) {
			idWeapon::CacheWeapon( weap );
		}
	}
}

/*
==============
idPlayer::Init
==============
*/
void idPlayer::Init( void ) {
	const char			*value;
	const idKeyValue	*kv;

	noclip					= false;
	godmode					= false;

	oldButtons				= 0;
	oldFlags				= 0;

	currentWeaponSlot		= -1;
	idealWeaponSlot			= -1;
	previousWeaponSlot		= -1;
	weaponSwitchTime		= 0;
	weaponEnabled			= true;
	weapon_soulcube			= SlotForWeapon( "weapon_soulcube" );
	weapon_pda				= SlotForWeapon( "weapon_pda" );
	weapon_fists			= SlotForWeapon( "weapon_fists" );

	showWeaponViewModel		= GetUserInfo()->GetBool( "ui_showGun" );


	lastDmgTime				= 0;
	lastArmorPulse			= -10000;
	lastHeartAdjust			= 0;
	lastHeartBeat			= 0;
	heartInfo.Init( 0, 0, 0, 0 );

	bobCycle				= 0;
	bobFrac					= 0.0f;
	landChange				= 0;
	landTime				= 0;
	zoomFov.Init( 0, 0, 0, 0 );
	centerView.Init( 0, 0, 0, 0 );
	fxFov					= false;

	influenceFov			= 0;
	influenceActive			= 0;
	influenceRadius			= 0.0f;
	influenceEntity			= NULL;
	influenceMaterial		= NULL;
	influenceSkin			= NULL;

#ifdef _D3XP
	mountedObject			= NULL;
	if( enviroSuitLight.IsValid() ) {
		enviroSuitLight.GetEntity()->PostEventMS( &EV_Remove, 0 );
	}
	enviroSuitLight			= NULL;
	
	
	
	new_g_damageScale		= 1.f;
	bloomEnabled			= false;
	bloomSpeed				= 1.f;
	bloomIntensity			= -0.01f;
	inventory.InitRechargeAmmo(this);
	hudPowerup				= -1;
	lastHudPowerup			= -1;
	hudPowerupDuration		= 0;
#endif

	currentLoggedAccel		= 0;

	focusTime				= 0;
	focusGUIent				= NULL;
	focusUI					= NULL;
	focusCharacter			= NULL;
	talkCursor				= 0;
	focusVehicle			= NULL;

	// remove any damage effects
	playerView.ClearEffects();

	// damage values
	fl.takedamage			= true;
	ClearPain();

	// restore persistent data
	RestorePersistantInfo();

	bobCycle		= 0;
	stamina			= 0.0f;
	healthPool		= 0.0f;
	nextHealthPulse = 0;
	healthPulse		= false;
	nextHealthTake	= 0;
	healthTake		= false;

	SetupWeaponEntity();
	currentWeaponSlot = -1;
	previousWeaponSlot = -1;

	heartRate = BASE_HEARTRATE;
	AdjustHeartRate( BASE_HEARTRATE, 0.0f, 0.0f, true );

	idealLegsYaw = 0.0f;
	legsYaw = 0.0f;
	legsForward	= true;
	oldViewYaw = 0.0f;

	// set the pm_ cvars
	if ( !gameLocal.isMultiplayer || gameLocal.isServer ) {
		kv = spawnArgs.MatchPrefix( "pm_", NULL );
		while( kv ) {
			cvarSystem->SetCVarString( kv->GetKey(), kv->GetValue() );
			kv = spawnArgs.MatchPrefix( "pm_", kv );
		}
	}

	// disable stamina on hell levels
	if ( gameLocal.world && gameLocal.world->spawnArgs.GetBool( "no_stamina" ) ) {
		pm_stamina.SetFloat( 0.0f );
	}

	// stamina always initialized to maximum
	stamina = pm_stamina.GetFloat();

	// air always initialized to maximum too
	//airTics = pm_airTics.GetFloat();
	
	//airTics = (g_oxygenscale.GetFloat() > 0) ? 1.0f : pm_airTics.GetInteger(); //BC initial airtank amount. If using the oxygenscale cvar, then just give player a full air tank.
	airTics = pm_airTics.GetInteger(); //Start with full oxygen.

	airless = false;

	if (isInVignette)
	{
		airTics = pm_airTics.GetInteger(); //during vignette, give max air amount
	}

	gibDeath = false;
	gibsLaunched = false;
	gibsDir.Zero();

	// set the gravity
	physicsObj.SetGravity( gameLocal.GetGravity() );

	// start out standing
	SetEyeHeight( pm_normalviewheight.GetFloat() );

	stepUpTime = 0;
	stepUpDelta = 0.0f;
	stepUpCorrection = 0.0f;
	viewBobAngles.Zero();
	viewBob.Zero();

	value = spawnArgs.GetString( "model" );
	if ( value && ( *value != 0 ) ) {
		SetModel( value );
	}

	if ( cursor ) {
		cursor->SetStateInt( "talkcursor", 0 );
		cursor->SetStateString( "combatcursor", "1" );
		cursor->SetStateString( "itemcursor", "0" );
		cursor->SetStateString( "guicursor", "0" );
#ifdef _D3XP
		cursor->SetStateString( "grabbercursor", "0" );
#endif
	}

	if ( ( gameLocal.isMultiplayer || g_testDeath.GetBool() ) && skin ) {
		SetSkin( skin );
		renderEntity.shaderParms[6] = 0.0f;
	} else if ( spawnArgs.GetString( "spawn_skin", NULL, &value ) ) {
		skin = declManager->FindSkin( value );
		SetSkin( skin );
		renderEntity.shaderParms[6] = 0.0f;
	}

	value = spawnArgs.GetString( "bone_hips", "" );
	hipJoint = animator.GetJointHandle( value );
	if ( hipJoint == INVALID_JOINT ) {
		gameLocal.Error( "Joint '%s' not found for 'bone_hips' on '%s'", value, name.c_str() );
	}

	value = spawnArgs.GetString( "bone_chest", "" );
	chestJoint = animator.GetJointHandle( value );
	if ( chestJoint == INVALID_JOINT ) {
		gameLocal.Error( "Joint '%s' not found for 'bone_chest' on '%s'", value, name.c_str() );
	}

	value = spawnArgs.GetString( "bone_head", "" );
	headJoint = animator.GetJointHandle( value );
	if ( headJoint == INVALID_JOINT ) {
		gameLocal.Error( "Joint '%s' not found for 'bone_head' on '%s'", value, name.c_str() );
	}

	// initialize the script variables
	AI_FORWARD		= false;
	AI_BACKWARD		= false;
	AI_STRAFE_LEFT	= false;
	AI_STRAFE_RIGHT	= false;
	AI_ATTACK_HELD	= false;
	AI_WEAPON_FIRED	= false;
	AI_JUMP			= false;
	AI_DEAD			= false;
	AI_CROUCH		= false;
	AI_ONGROUND		= true;
	AI_ONLADDER		= false;
	AI_HARDLANDING	= false;
	AI_SOFTLANDING	= false;
	AI_RUN			= false;
	AI_PAIN			= false;
	AI_RELOAD		= false;
	AI_TELEPORT		= false;
	AI_TURN_LEFT	= false;
	AI_TURN_RIGHT	= false;

	AI_HEAL_GLASSWOUND			= false;
	AI_HEAL_BURNING				= false;
	AI_HEAL_BLEEDOUT			= false;
	AI_HEAL_BULLETPLUCK			= false;
	AI_HEAL_SHRAPNEL			= false;
	AI_HEAL_HEALWOUND			= false;
	AI_ACRO_CEILINGHIDE			= false;
	AI_ACRO_SPLITS				= false;
	AI_ACRO_SPLITS_DOWN			= false;
	AI_FALLEN					= false;
	AI_FALLEN_GETUP				= false;
	AI_FALLEN_ROLL				= false;
	AI_HEAL_SPEARPLUCK			= false;
	AI_JOCKEYRIDE				= false;

	// reset the script object
	ConstructScriptObject();

	// execute the script so the script object's constructor takes effect immediately
	scriptThread->Execute();

	forceScoreBoard		= false;
	forcedReady			= false;

	privateCameraView	= NULL;

	lastSpectateChange	= 0;
	lastTeleFX			= -9999;

	hiddenWeapon		= false;
	tipUp				= false;
	objectiveUp			= false;
	teleportEntity		= NULL;
	teleportKiller		= -1;
	leader				= false;

	SetPrivateCameraView( NULL );

	lastSnapshotSequence	= 0;

	MPAim				= -1;
	lastMPAim			= -1;
	lastMPAimTime		= 0;
	MPAimFadeTime		= 0;
	MPAimHighlight		= false;

	if ( hud ) {
		hud->HandleNamedEvent( "aim_clear" );
	}

	//isChatting = false;
	cvarSystem->SetCVarBool("ui_chat", false);



	//BC INIT
	
	//Spawn throw arc endpoint / placer UI.
	idDict		args;
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "models/objects/ui_throwdisc/ui_throwdisc.ase");
	args.Set("skin", "skins/objects/ui_throwdisc/skin_slow");
	placerEnt = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
	placerEnt->Hide();

	//Spawn tripwire line UI.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "models/objects/ui_throwdisc/tripwireline/ui_tripwireline.ase");
	placerEntLine = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
	placerEntLine->Hide();
	placerEntLine->Bind(placerEnt, true);

	//Spawn placer arrow model.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "models/objects/ui_jockeyarrow/jockeyarrow.ase");
	placerEntArrow = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
	placerEntArrow->Hide();

	


	//Spawn jockey arrow UI.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "models/objects/ui_jockeyarrow/jockeyarrow.ase");
	jockeyArrow = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
	jockeyArrow->Hide();
	

	//Jockey attack disc. This is the UI that is drawn on walls , signifiying where the wall attack will end up.
	//args.Clear();
	//args.SetInt("solid", 0);
	//args.Set("model", "models/objects/ui_throwdisc/ui_square.ase");
	//args.SetVector("_color", idVec3(1, .3f, .3f));
	//jockeyDisc = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
	//jockeyDisc->Hide();



	//Teleport prediction UI 'person' entity.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "models/objects/ui_person/ui_person.ase");
    args.SetBool("drawGlobally", true); //This has to be set because the entity is sometimes in places that are out of the player's PVS.
	tele_ui_entity = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
    tele_ui_entity->SetDepthHack(true);    
	tele_ui_entity->Hide();

    args.Clear();
    args.SetInt("solid", 0);
    args.Set("model", "models/objects/ui_throwdisc/ui_throwdisc_big.ase");
    args.Set("skin", "skins/objects/ui_throwdisc/skin_color");
    args.SetBool("drawGlobally", true);
    tele_ui_disc = (idStaticEntity *)gameLocal.SpawnEntityType(idStaticEntity::Type, &args);
    tele_ui_disc->SetDepthHack(true);
    tele_ui_disc->SetColor(idVec4(1, 1, 0, .5f));
    tele_ui_disc->Hide();
	



		
	AttachBloodbag();


	//Attach mech cockpit.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "model_mechcockpit");
	args.Set("snd_mechenter", "mech_enter");
	args.Set("speakername", "#str_speaker_mech");
	mechCockpit = (idAnimated *)gameLocal.SpawnEntityType(idAnimated::Type, &args);
	mechCockpit->SetDepthHack(true);
	mechCockpit->Event_PlayAnim("idle", 1);
	mechCockpit->Hide();	


	//spawn wristwatch
	//Load the wristwatch model.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "model_playerwatch");
	args.Set("gui", "guis/armstatsmenu.gui");
	args.Set("snd_rustle", "gun_handle");
	args.Set("snd_cameraswitch", "monitor_on");
	armstatsModel = (idAnimatedEntity *)gameLocal.SpawnEntityType(idAnimatedEntity::Type, &args);
	armstatsModel->SetDepthHack(true);
	armstatsModel->Hide();



	ninaOrgansPosStart = vec3_zero;
	ninaOrgansPosEnd = vec3_zero;
	ninaOrgansTimer = 0;
	

	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "model_defib");
	ninaOrgansModel = (idAnimatedEntity*)gameLocal.SpawnEntityType(idAnimatedEntity::Type, &args);
	ninaOrgansModel->Hide();
	
	


	//Not sure if this is the best place for this, but spawn the idMeta object at the player's location. So that we can guarantee the idMeta is inside the world bounds.
	if (gameLocal.FindEntity("meta1") == NULL)
	{
		const idDeclEntityDef *metaDef;
		idEntity *metaEnt;

		metaDef = gameLocal.FindEntityDef("target_meta", false);
		if (!metaDef)
		{
			gameLocal.Error("Failed to find def for target_meta.");
		}

		gameLocal.SpawnEntityDef(metaDef->dict, &metaEnt, false);
		if (metaEnt)
		{
			metaEnt->SetOrigin(this->GetPhysics()->GetOrigin());
			metaEnt->SetName("meta1");
		}
		else
		{
			gameLocal.Error("Failed to spawn target_meta.");
		}

		//For some reason the spawnarg flags aren't getting propagated....... so manually copy them here.
		const idKeyValue *kv = metaDef->dict.MatchPrefix("snd_");
		while (kv)
		{
			metaEnt->spawnArgs.Set(kv->GetKey(), kv->GetValue());
			kv = metaDef->dict.MatchPrefix("snd_", kv);
		}

		const idKeyValue *kv_def = metaDef->dict.MatchPrefix("def_");
		while (kv_def)
		{
			metaEnt->spawnArgs.Set(kv_def->GetKey(), kv_def->GetValue());
			kv_def = metaDef->dict.MatchPrefix("def_", kv_def);
		}

		gameLocal.metaEnt = metaEnt;
	}



	peekObject = NULL;

	reverbLocation = "default";

	int i;
	idDict args1;

	//bc grenade arc.
	for (i = 0; i < THROWARC_BEAMCOUNT; i++)
	{
		float arcWidth = THROWARC_WIDTH;

		if (i <= 0)
			arcWidth = THROWARC_WIDTH / 4.0f;
		else if (i == 1)
			arcWidth = THROWARC_WIDTH / 2.0f;
		else if (i == 2)
			arcWidth = THROWARC_WIDTH * .75f;

		args.Clear();
		args.SetVector("origin", vec3_origin);
		args.SetFloat("width", arcWidth);
		this->throwBeamTarget[i] = (idBeam*)gameLocal.SpawnEntityType(idBeam::Type, &args);

		args.Clear();
		args.Set("target", throwBeamTarget[i]->name.c_str());
		args.SetBool("start_off", false);
		args.SetVector("origin", vec3_origin);
		args.SetFloat("width", arcWidth);
		args.Set("skin", "skins/beam_grenadearc");

		this->throwBeamOrigin[i] = (idBeam*)gameLocal.SpawnEntityType(idBeam::Type, &args);
		this->throwBeamOrigin[i]->BecomeActive(TH_PHYSICS);
		this->throwBeamTarget[i]->BecomeActive(TH_PHYSICS);
		//this->grenadebeamTarget[i]->Event_SetWidth(16);
		//this->grenadebeamTarget[i]->Bind(this, false);
	}

	args1.Clear();
	args1.SetInt("solid", 0);
	args1.SetVector("origin", vec3_origin);
	args1.Set("model", "models/objects/ui_throwdisc/ui_throwdisc.ase");
	throwdisc = (idStaticEntity*)gameLocal.SpawnEntityType(idStaticEntity::Type, &args1);
	throwdisc->Hide();

	args1.Set("model", "");
	throwPredictionModel = (idStaticEntity*)gameLocal.SpawnEntityType(idStaticEntity::Type, &args1);
	throwPredictionModel->GetRenderEntity()->customShader = declManager->FindMaterial("textures/fx/throw_model_ghost");
	throwPredictionModel->Hide();

	//Reset hotbar gui stuff.
	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		this->hud->SetStateString(va("hotbarname%d", i), ""); //Reset hotbar.

		this->hud->SetStateBool(va("hotbarvisible%d", i), (i <= inventory.hotbarUnlockedSlots - 1) ? true : false ); //Set hotbar visibility.

		this->hud->SetStateBool(va("hotbarselected%d", i), (i == inventory.GetHotbarSelection()) ? true : false);
	}

	this->hud->SetStateBool("carryableBoxVisible", false);
	this->hud->SetStateString("equippedCarryable", "");

	lastSelectedHotbarslot = -1;
	
	this->renderEntity.trackInteractions = spawnArgs.GetBool("trackInteractions");
	if (this->renderEntity.trackInteractions && g_luminance_enabled.GetBool())
	{
		// SW: Instantiate the 'light probe' model that sits on the player's origin and receives lighting information.
		// We use an invisible model instead of directly accessing the player's lighting info because that can vary depending on orientation.
		args1.Clear();
		args1.SetInt("solid", 0);
		args1.SetVector("origin", this->physicsObj.GetOrigin() + idVec3(0,0,31)); //BC raise probe up a little so the flashlight can hit it
		args1.SetBool("trackInteractions", true);
		args1.SetBool("dynamicSpectrum", this->spawnArgs.GetBool("dynamicSpectrum"));
		args1.SetBool("noFrustumCull", this->spawnArgs.GetBool("noFrustumCull"));
		args1.Set("model", "models/player/player_lightProbe.ase");

		this->lightProbe = (idStaticEntity*)gameLocal.SpawnEntityType(idStaticEntity::Type, &args1);
		this->lightProbe.GetEntity()->Bind(this, false);
		this->lightProbe.GetEntity()->GetRenderEntity()->interactionCallback = idPlayer::UpdateTrackedInteractions;

		// Unset the relevant parameters on the player entity itself, as we don't want to track interactions from here -- only from the light probe
		this->renderEntity.trackInteractions = false;
		this->renderEntity.interactionCallback = NULL;
		this->renderEntity.noFrustumCull = false;
	}

	toggleCrouch = false;
	teleportCrouchTime = -TELEPORTCROUCH_EASE_TIME;


	gameLocal.GetLocalPlayer()->SetObjectiveText("", false);

	confinedType = 0;
	wasCaughtEnteringCargoHide = false;

	ingresspointsDrawActive = false;

	statsPickpocketAttempts = 0;
	statsPickpocketSuccesses = 0;


	staminaChargeDelayTimer = 0;
	staminaHideTimer = 0;
	staminaHideDelayMode = STAMBAR_HIDDEN;
    staminaThrowTimer = 0;

	drawCinematicHUD = true;

	//BC INIT END
}

void idPlayer::AttachBloodbag()
{
	idDict		args;

	//Spawn bloodbag. Attach bloodbag to headbone.
	args.Clear();
	args.SetInt("solid", 0);
	args.Set("model", "model_bloodbag");
	args.Set("snd_transfuse", "blood_transfusion_loop");
	args.Set("snd_pop", "blood_pop");
	bloodbagMesh = (idAnimated *)gameLocal.SpawnEntityType(idAnimated::Type, &args);
	bloodbagMesh->SetDepthHack(true);
	bloodbagMesh->Hide();

	bloodbagParticles = static_cast<const idDeclParticle *>(declManager->FindType(DECL_PARTICLE, "bloodbag_damage_1.prt"));
	bloodbagParticleFlytime = gameLocal.time;

	bloodbagJoint  = bloodbagMesh->GetAnimator()->GetJointHandle("tube01");

	
	args.Clear();
	args.Set("model", "bloodbag_damage_1.prt");
	args.Set("start_off", "1");
	bloodbagEmitter = static_cast<idFuncEmitter *>(gameLocal.SpawnEntityType(idFuncEmitter::Type, &args));
}

/*
==============
idPlayer::Spawn

Prepare any resources used by the player.
==============
*/
void idPlayer::Spawn( void ) {
	idStr		temp;
	idBounds	bounds;
	

	if ( entityNumber >= MAX_CLIENTS ) {
		gameLocal.Error( "entityNum > MAX_CLIENTS for player.  Player may only be spawned with a client." );
	}

	// allow thinking during cinematics
	cinematic = true;

	if ( gameLocal.isMultiplayer ) {
		// always start in spectating state waiting to be spawned in
		// do this before SetClipModel to get the right bounding box
		spectating = true;
	}

	// set our collision model
	physicsObj.SetSelf( this );
	SetClipModel();
	physicsObj.SetMass( spawnArgs.GetFloat( "mass", "100" ) );
	physicsObj.SetContents( CONTENTS_BODY );
	physicsObj.SetClipMask( MASK_PLAYERSOLID );
	SetPhysics( &physicsObj );
	InitAASLocation();

	skin = renderEntity.customSkin;






	// only the local player needs guis
	if ( !gameLocal.isMultiplayer || entityNumber == gameLocal.localClientNum ) {

		// load HUD
		if ( gameLocal.isMultiplayer ) {
			hud = uiManager->FindGui( "guis/mphud.gui", true, false, true );
		} else if ( spawnArgs.GetString( "hud", "", temp ) ) {
			hud = uiManager->FindGui( temp, true, false, true );
		}
		if ( hud ) {
			hud->Activate( true, gameLocal.time );
#ifdef CTF
			if ( gameLocal.mpGame.IsGametypeFlagBased() ) {
				hud->SetStateInt( "red_team_score", gameLocal.mpGame.GetFlagPoints(0) );
				hud->SetStateInt( "blue_team_score", gameLocal.mpGame.GetFlagPoints(1) );
			}
#endif
		}

		// load cursor
		if ( spawnArgs.GetString( "cursor", "", temp ) ) {
			cursor = uiManager->FindGui( temp, true, gameLocal.isMultiplayer, gameLocal.isMultiplayer );
		}
		if ( cursor ) {
			cursor->Activate( true, gameLocal.time );
		}

		objectiveSystem = uiManager->FindGui( "guis/pda.gui", true, false, true );
		objectiveSystemOpen = false;
	}

	SetLastHitTime( 0 );

	// load the armor sound feedback
	declManager->FindSound( "player_hitarmor" );

	// set up conditions for animation
	LinkScriptVariables();

	animator.RemoveOriginOffset( true );

	// initialize user info related settings
	// on server, we wait for the userinfo broadcast, as this controls when the player is initially spawned in game
	if ( gameLocal.isClient || entityNumber == gameLocal.localClientNum ) {
		UserInfoChanged( false );
	}

	// create combat collision hull for exact collision detection
	SetCombatModel();

	// init the damage effects
	playerView.SetPlayerEntity( this );

	// supress model in non-player views, but allow it in mirrors and remote views
	renderEntity.suppressSurfaceInViewID = entityNumber+1;

	// don't project shadow on self or weapon
	renderEntity.noSelfShadow = true;

	idAFAttachment *headEnt = head.GetEntity();
	if ( headEnt ) {
		headEnt->GetRenderEntity()->suppressSurfaceInViewID = entityNumber+1;
		headEnt->GetRenderEntity()->noSelfShadow = true;
	}

	if ( gameLocal.isMultiplayer ) {
		Init();
		Hide();	// properly hidden if starting as a spectator
		if ( !gameLocal.isClient ) {
			// set yourself ready to spawn. idMultiplayerGame will decide when/if appropriate and call SpawnFromSpawnSpot
			SetupWeaponEntity();
			SpawnFromSpawnSpot();
			forceRespawn = true;
			assert( spectating );
		}
	} else {
		SetupWeaponEntity();
		SpawnFromSpawnSpot();
	}

	// trigger playtesting item gives, if we didn't get here from a previous level
	// the devmap key will be set on the first devmap, but cleared on any level
	// transitions
	if ( !gameLocal.isMultiplayer && gameLocal.serverInfo.FindKey( "devmap" ) ) {
		// fire a trigger with the name "devmap"
		idEntity *ent = gameLocal.FindEntity( "devmap" );
		if ( ent ) {
			ent->ActivateTargets( this );
		}
	}
	if ( hud ) {
		// We can spawn with a full soul cube, so we need to make sure the hud knows this
#ifndef _D3XP
		if ( weapon_soulcube > 0 && ( inventory.weapons & ( 1 << weapon_soulcube ) ) ) {
			int max_souls = inventory.MaxAmmoForAmmoClass( this, "ammo_souls" );
			if ( inventory.ammo[ idWeapon::GetAmmoNumForName( "ammo_souls" ) ] >= max_souls ) {
				hud->HandleNamedEvent( "soulCubeReady" );
			}
		}
#endif

		hud->HandleNamedEvent( "itemPickup" );
	}

	if ( GetPDA() ) {
		// Add any emails from the inventory
		for ( int i = 0; i < inventory.emails.Num(); i++ ) {
			idStrList splits = inventory.emails[i].Split(';');
			if (splits.Num() == 2) {
				if (splits[0] == "default") {
					GiveEmail(splits[1]);
				} else {
					GiveEmailViaTalker(splits[0], splits[1], false);
				}
			}
		}

		// Read emails
		for (int i = 0; i < inventory.emailsRead.Num(); i++) {
			idStrList splits = inventory.emailsRead[i].Split(';');
			if (splits.Num() == 2) {
				if (splits[0] == "default") {
					GetPDA()->AddEmailRead(splits[1]);
				}
				else {
					const idDeclPDA* pda = GetPDAViaTalker(splits[0]);
					if (pda)
					{
						pda->AddEmailRead(splits[1]);
					}
				}
			}
		}

		// Replied emails
		for (int i = 0; i < inventory.emailsReplied.Num(); i++) {
			idStrList splits = inventory.emailsReplied[i].Split(';');
			if (splits.Num() == 2) {
				if (splits[0] == "default") {
					GetPDA()->AddEmailReplied(splits[1]);
				}
				else {
					const idDeclPDA* pda = GetPDAViaTalker(splits[0]);
					if (pda)
					{
						pda->AddEmailReplied(splits[1]);
					}
				}
			}
		}

		GetPDA()->SetSecurity( common->GetLanguageDict()->GetString( "#str_loc_unknown_00104" ) ); //BC general email access, this might be safe to delete
	}

	if ( gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) ) {
		hiddenWeapon = true;
		if ( weapon.GetEntity() ) {
			weapon.GetEntity()->LowerWeapon();
		}
		idealWeaponSlot = -1;
	} else {
		hiddenWeapon = false;
	}

	if ( hud ) {
		UpdateHudWeapon();
		hud->StateChanged( gameLocal.time );
	}

	tipUp = false;
	objectiveUp = false;

	if ( inventory.levelTriggers.Num() ) {
		PostEventMS( &EV_Player_LevelTrigger, 0 );
	}

	inventory.pdaOpened = false;
	inventory.selPDA = 0;

	if ( !gameLocal.isMultiplayer )
	{
		if ( g_skill.GetInteger() < 2 ) {
			if ( health < 25 ) {
				health = 25;
			}
			if ( g_useDynamicProtection.GetBool() ) {
#ifdef _D3XP
				new_g_damageScale = 1.0f;
#else
				g_damageScale.SetFloat( 1.0f );
#endif
			}
		} else {
#ifdef _D3XP
			new_g_damageScale = 1.0f;
#else
			g_damageScale.SetFloat( 1.0f );
#endif
			g_armorProtection.SetFloat( ( g_skill.GetInteger() < 2 ) ? 0.4f : 0.2f );

			if ( g_skill.GetInteger() == 3 ) {
				healthTake = true;
				nextHealthTake = gameLocal.time + g_healthTakeTime.GetInteger() * 1000;
			}
		}
	}

#ifdef _D3XP
	//Setup the weapon toggle lists
	const idKeyValue *kv;
	kv = spawnArgs.MatchPrefix( "weapontoggle", NULL );
	while( kv ) {
		WeaponToggle_t newToggle;
		strcpy(newToggle.name, kv->GetKey().c_str());

		idStr toggleData = kv->GetValue();

		idLexer src;
		idToken token;
		src.LoadMemory(toggleData, toggleData.Length(), "toggleData");
		while(1) {
			if(!src.ReadToken(&token)) {
				break;
			}
			int index = atoi(token.c_str());
			newToggle.toggleList.Append(index);

			//Skip the ,
			src.ReadToken(&token);
		}
		weaponToggles.Set(newToggle.name, newToggle);

		kv = spawnArgs.MatchPrefix( "weapontoggle", kv );
	}
#endif

#ifdef _D3XP


	bloomEnabled			= false;
	bloomSpeed				= 1;
	bloomIntensity			= -0.01f;
#endif


	//BC
	contextMenu = uiManager->FindGui("guis/contextmenu.gui", true, false, true);
	contextMenuActive = false;

	


	spitDef = gameLocal.FindEntityDefDict(spawnArgs.GetString("def_spit", "projectile_spit"), false);
	bloodspitDef = gameLocal.FindEntityDefDict(spawnArgs.GetString("def_bloodspit", "projectile_bloodspit"), false);

	lastSavingThrowTime = 0;
	savingthrowState = SAVINGTHROW_AVAILABLE;


	videoMenu = uiManager->FindGui("guis/videomenu.gui", true, false, true);
	cameraGuiMenu = uiManager->FindGui("guis/game/cameragui.gui", true, false, false);

	mountedMech = NULL;	
	mechTransitionState = MECHTRANSITION_NONE;


	//This is to fix the bug where teh smelly status pops up after a level change.
	hud->SetStateInt("smelly", cond_smelly);
	hud->SetStateInt("confined", 0);
    hud->SetStateBool("cond_confinedstealth", false);
    hud->SetStateInt("escalationlevel", 0);
	hud->SetStateBool("playerdead", false);
	hud->SetStateBool("showjockeyattackprompt", false);
	hud->SetStateBool("takefinalphoto", false);
	//hud->SetStateBool("showstamina", false);
	
	contextMenu->SetStateInt("smelly", cond_smelly);
	

	gameSoundWorld->FadeSoundClasses(SOUNDCLASS_ALL, 0, .1f);


	eventlogMenu = uiManager->FindGui("guis/eventlog.gui", true, false, true);
	eventlogMenuActive = false;

	levelselectMenu = uiManager->FindGui("guis/levelselect.gui", true, false, true);
	levelselectMenuActive = false;

	emailFullscreenMenu = uiManager->FindGui("guis/pda.gui", true, false, true);



	spectatorMenu = uiManager->FindGui("guis/spectate.gui");

	AddBloodMushroom(0, vec3_zero); //set the hud text for mushrooms.

	isInVignette = gameLocal.world->spawnArgs.GetBool("vignette");
	UpdateHudVignetteState(isInVignette);

	didInitialSpawn = true;
	hud->HandleNamedEvent( "playerdeathreset" );
	inDownedState = false;
	viewAngles.roll = 0;
	deltaViewAngles.roll = 0;

	for (int i = 0; i < WOUNDCOUNT_MAX; i++)
	{
		woundArray[i] = false;
	}

	hud->SetStateBool("hasredkey", false);
	hud->SetStateBool("hasbluekey", false);
	hud->SetStateBool("showreinforcements", false);

	armstatsModel->Event_SetGuiInt("hasredkey", 0);
	armstatsModel->Event_SetGuiInt("hasbluekey", 0);

	contextMenu->SetStateInt("hasredkey", 0);
	contextMenu->SetStateInt("hasbluekey", 0);
	contextMenu->SetStateInt("catkeys", 0);
	contextMenu->SetStateInt("sakkeys", 0);


	idStr mapName = gameLocal.world->spawnArgs.GetString("mtr_image");
	if (mapName.Length() > 0)
	{
		armstatsModel->Event_SetGuiParm("mapimage", mapName.c_str());
	}

	//Special spectrum light for memory palace.
	idDict lightArgs;
	lightArgs.Clear();
	lightArgs.SetVector("origin", firstPersonViewOrigin);
	lightArgs.Set("texture", "lights/memorylight");
	lightArgs.SetInt("noshadows", 1);
	lightArgs.Set("_color", ".4 .4 .4 1");
	lightArgs.SetFloat("light", 64);
	lightArgs.SetBool("start_off", true);
	memoryLight = (idLight *)gameLocal.SpawnEntityType(idLight::Type, &lightArgs);

	damageTaken = 0;
	enemiesPounced = 0;
	brutalslams = 0;
	enemyrespawns = 0;

	
	iteminspectActive = false;
	iteminspectFOV = 90;

	
	SetArmstatsFuseboxNeedUpdate(); //update the fusebox display on wrist map

	AI_FALLEN = false;

	

	SetupArmstatRoomLabels();

	DisplayLocbox("");

	DisplayCatBox("", "", "");

	//BC spawn end
}

void idPlayer::SetupArmstatRoomLabels()
{
	idStr mapname;
	mapname = gameLocal.GetMapName();
	mapname.StripPath();
	mapname.StripFileExtension();
	mapname.ToLower();

	const idDecl* mapDecl = declManager->FindType(DECL_MAPDEF, mapname, false);
	const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(mapDecl);
	if (mapDef)
	{
		for (int i = 0; i < ROOMLABELCOUNT; i++)
		{
			idStr roomVarName = idStr::Format("roomlabel%d", i);

			idStr roomLabel = mapDef->dict.GetString(roomVarName.c_str());
			if (roomLabel.Length() > 0)
			{
				armstatsModel->Event_SetGuiParm(roomVarName.c_str(), roomLabel.c_str());

				idStr roomXVarName = idStr::Format("roomlabel%d_x", i);
				idStr roomYVarName = idStr::Format("roomlabel%d_y", i);
				armstatsModel->Event_SetGuiFloat(roomXVarName.c_str(), mapDef->dict.GetFloat(roomXVarName));
				armstatsModel->Event_SetGuiFloat(roomYVarName.c_str(), mapDef->dict.GetFloat(roomYVarName));
			}
			else
			{
				armstatsModel->Event_SetGuiParm(roomVarName.c_str(), "");
			}			
		}		
	}
}


/*
==============
idPlayer::~idPlayer()

Release any resources used by the player.
==============
*/
idPlayer::~idPlayer() {
	delete weapon.GetEntity();
	weapon = NULL;
#ifdef CTF
	if ( enviroSuitLight.IsValid() ) {
		enviroSuitLight.GetEntity()->ProcessEvent( &EV_Remove );
	}
	// have to do this here, idMultiplayerGame::DisconnectClient() is too late
	if ( gameLocal.isMultiplayer && gameLocal.mpGame.IsGametypeFlagBased() ) {
		ReturnFlag();
	}
#endif
}

/*
===========
idPlayer::Save
===========
*/
void idPlayer::Save( idSaveGame *savefile ) const {
	int i;

	savefile->WriteUsercmd( usercmd );
	playerView.Save( savefile );

	savefile->WriteBool( noclip );
	savefile->WriteBool( godmode );

	// don't save spawnAnglesSet, since we'll have to reset them after loading the savegame
	savefile->WriteAngles( spawnAngles );
	savefile->WriteAngles( viewAngles );
	savefile->WriteAngles( cmdAngles );

	savefile->WriteInt( buttonMask );
	savefile->WriteInt( oldButtons );
	savefile->WriteInt( oldFlags );

	savefile->WriteInt( lastHitTime );
	savefile->WriteInt( lastSndHitTime );
	savefile->WriteInt( lastSavingThrowTime );

	// idBoolFields don't need to be saved, just re-linked in Restore

	inventory.Save( savefile );
	weapon.Save( savefile );

	savefile->WriteUserInterface( hud, false );
	savefile->WriteUserInterface( objectiveSystem, false );
	savefile->WriteBool( objectiveSystemOpen );

	savefile->WriteInt( weapon_soulcube );
	savefile->WriteInt( weapon_pda );
	savefile->WriteInt( weapon_fists );
#ifdef _D3XP

	savefile->WriteInt( hudPowerup );
	savefile->WriteInt( lastHudPowerup );
	savefile->WriteInt( hudPowerupDuration );


#endif

	savefile->WriteInt( heartRate );

	savefile->WriteFloat( heartInfo.GetStartTime() );
	savefile->WriteFloat( heartInfo.GetDuration() );
	savefile->WriteFloat( heartInfo.GetStartValue() );
	savefile->WriteFloat( heartInfo.GetEndValue() );

	savefile->WriteInt( lastHeartAdjust );
	savefile->WriteInt( lastHeartBeat );
	savefile->WriteInt( lastDmgTime );
	savefile->WriteInt( deathClearContentsTime );
	savefile->WriteBool( doingDeathSkin );
	savefile->WriteInt( lastArmorPulse );
	savefile->WriteFloat( stamina );
	savefile->WriteFloat( healthPool );
	savefile->WriteInt( nextHealthPulse );
	savefile->WriteBool( healthPulse );
	savefile->WriteInt( nextHealthTake );
	savefile->WriteBool( healthTake );

	savefile->WriteBool( hiddenWeapon );
	soulCubeProjectile.Save( savefile );

	savefile->WriteInt( spectator );
	savefile->WriteVec3( colorBar );
	savefile->WriteInt( colorBarIndex );
	savefile->WriteBool( scoreBoardOpen );
	savefile->WriteBool( forceScoreBoard );
	savefile->WriteBool( forceRespawn );
	savefile->WriteBool( spectating );
	savefile->WriteInt( lastSpectateTeleport );
	savefile->WriteBool( lastHitToggle );
	savefile->WriteBool( forcedReady );
	savefile->WriteBool( wantSpectate );
	savefile->WriteBool( weaponGone );
	savefile->WriteBool( useInitialSpawns );
	savefile->WriteInt( latchedTeam );
	savefile->WriteInt( tourneyRank );
	savefile->WriteInt( tourneyLine );

	teleportEntity.Save( savefile );
	savefile->WriteInt( teleportKiller );

	savefile->WriteInt( minRespawnTime );
	savefile->WriteInt( maxRespawnTime );

	savefile->WriteVec3( firstPersonViewOrigin );
	savefile->WriteMat3( firstPersonViewAxis );

	// don't bother saving dragEntity since it's a dev tool

	savefile->WriteJoint( hipJoint );
	savefile->WriteJoint( chestJoint );
	savefile->WriteJoint( headJoint );

	savefile->WriteStaticObject( physicsObj );

	savefile->WriteInt( aasLocation.Num() );
	for( i = 0; i < aasLocation.Num(); i++ ) {
		savefile->WriteInt( aasLocation[ i ].areaNum );
		savefile->WriteVec3( aasLocation[ i ].pos );
	}

	savefile->WriteInt( bobFoot );
	savefile->WriteFloat( bobFrac );
	savefile->WriteFloat( bobfracsin );
	savefile->WriteInt( bobCycle );
	savefile->WriteFloat( xyspeed );
	savefile->WriteInt( stepUpTime );
	savefile->WriteFloat( stepUpDelta );
	savefile->WriteFloat( stepUpCorrection );
	savefile->WriteFloat( idealLegsYaw );
	savefile->WriteFloat( legsYaw );
	savefile->WriteBool( legsForward );
	savefile->WriteFloat( oldViewYaw );
	savefile->WriteAngles( viewBobAngles );
	savefile->WriteVec3( viewBob );
	savefile->WriteInt( landChange );
	savefile->WriteInt( landTime );

	savefile->WriteInt( currentWeaponSlot );
	savefile->WriteInt( idealWeaponSlot );
	savefile->WriteInt( previousWeaponSlot );
	savefile->WriteInt( weaponSwitchTime );
	savefile->WriteBool( weaponEnabled );
	savefile->WriteBool( showWeaponViewModel );

	savefile->WriteSkin( skin );
	savefile->WriteSkin( powerUpSkin );
	savefile->WriteString( baseSkinName );

	savefile->WriteInt( numProjectilesFired );
	savefile->WriteInt( numProjectileHits );

	savefile->WriteBool( airless );
	savefile->WriteFloat( airTics );
	savefile->WriteInt( lastAirDamage );

	savefile->WriteBool( gibDeath );
	savefile->WriteBool( gibsLaunched );
	savefile->WriteVec3( gibsDir );

	savefile->WriteFloat( zoomFov.GetStartTime() );
	savefile->WriteFloat( zoomFov.GetDuration() );
	savefile->WriteFloat( zoomFov.GetStartValue() );
	savefile->WriteFloat( zoomFov.GetEndValue() );

	savefile->WriteFloat( centerView.GetStartTime() );
	savefile->WriteFloat( centerView.GetDuration() );
	savefile->WriteFloat( centerView.GetStartValue() );
	savefile->WriteFloat( centerView.GetEndValue() );

	savefile->WriteBool( fxFov );

	savefile->WriteFloat( influenceFov );
	savefile->WriteInt( influenceActive );
	savefile->WriteFloat( influenceRadius );
	savefile->WriteObject( influenceEntity );
	savefile->WriteMaterial( influenceMaterial );
	savefile->WriteSkin( influenceSkin );

	savefile->WriteObject( privateCameraView );

	for( i = 0; i < NUM_LOGGED_VIEW_ANGLES; i++ ) {
		savefile->WriteAngles( loggedViewAngles[ i ] );
	}
	for( i = 0; i < NUM_LOGGED_ACCELS; i++ ) {
		savefile->WriteInt( loggedAccel[ i ].time );
		savefile->WriteVec3( loggedAccel[ i ].dir );
	}
	savefile->WriteInt( currentLoggedAccel );

	savefile->WriteObject( focusGUIent );
	// can't save focusUI
	savefile->WriteObject( focusCharacter );
	savefile->WriteInt( talkCursor );
	savefile->WriteInt( focusTime );
	savefile->WriteObject( focusVehicle );
	savefile->WriteUserInterface( cursor, false );

	savefile->WriteInt( oldMouseX );
	savefile->WriteInt( oldMouseY );

	savefile->WriteString( pdaAudio );
	savefile->WriteString( pdaVideo );
	savefile->WriteString( pdaVideoWave );

	savefile->WriteBool( tipUp );
	savefile->WriteBool( objectiveUp );

	savefile->WriteInt( lastDamageDef );
	savefile->WriteVec3( lastDamageDir );
	savefile->WriteInt( lastDamageLocation );
	savefile->WriteInt( smoothedFrame );
	savefile->WriteBool( smoothedOriginUpdated );
	savefile->WriteVec3( smoothedOrigin );
	savefile->WriteAngles( smoothedAngles );

	savefile->WriteBool( ready );
	savefile->WriteBool( respawning );
	savefile->WriteBool( leader );
	savefile->WriteInt( lastSpectateChange );
	savefile->WriteInt( lastTeleFX );

	savefile->WriteFloat( pm_stamina.GetFloat() );

	if ( hud ) {
		hud->SetStateString( "message", common->GetLanguageDict()->GetString( "#str_02916" ) );
		hud->HandleNamedEvent( "Message" );
	}

#ifdef _D3XP
	savefile->WriteInt(weaponToggles.Num());
	for(i = 0; i < weaponToggles.Num(); i++) {
		WeaponToggle_t* weaponToggle = weaponToggles.GetIndex(i);
		savefile->WriteString(weaponToggle->name);
		savefile->WriteInt(weaponToggle->toggleList.Num());
		for(int j = 0; j < weaponToggle->toggleList.Num(); j++) {
			savefile->WriteInt(weaponToggle->toggleList[j]);
		}
	}
	savefile->WriteObject( mountedObject );
	enviroSuitLight.Save( savefile );
	
	
	
	savefile->WriteFloat( new_g_damageScale );

	savefile->WriteBool( bloomEnabled );
	savefile->WriteFloat( bloomSpeed );
	savefile->WriteFloat( bloomIntensity );

#endif

	savefile->WriteBool( toggleCrouch );
	savefile->WriteInt( teleportCrouchTime );
}

/*
===========
idPlayer::Restore
===========
*/
void idPlayer::Restore( idRestoreGame *savefile ) {
	int	  i;
	int	  num;
	float set;

	savefile->ReadUsercmd( usercmd );
	playerView.Restore( savefile );

	savefile->ReadBool( noclip );
	savefile->ReadBool( godmode );

	savefile->ReadAngles( spawnAngles );
	savefile->ReadAngles( viewAngles );
	savefile->ReadAngles( cmdAngles );

	memset( usercmd.angles, 0, sizeof( usercmd.angles ) );
	SetViewAngles( viewAngles );
	spawnAnglesSet = true;

	savefile->ReadInt( buttonMask );
	savefile->ReadInt( oldButtons );
	savefile->ReadInt( oldFlags );

	usercmd.flags = 0;
	oldFlags = 0;

	savefile->ReadInt( lastHitTime );
	savefile->ReadInt( lastSndHitTime );
	savefile->ReadInt( lastSavingThrowTime );

	// Re-link idBoolFields to the scriptObject, values will be restored in scriptObject's restore
	LinkScriptVariables();

	inventory.Restore( savefile );
	weapon.Restore( savefile );

	for ( i = 0; i < inventory.emails.Num(); i++ ) {
		GetPDA()->AddEmail( inventory.emails[i] );
	}

	savefile->ReadUserInterface( hud );
	savefile->ReadUserInterface( objectiveSystem );
	savefile->ReadBool( objectiveSystemOpen );

	savefile->ReadInt( weapon_soulcube );
	savefile->ReadInt( weapon_pda );
	savefile->ReadInt( weapon_fists );
#ifdef _D3XP

	savefile->ReadInt( hudPowerup );
	savefile->ReadInt( lastHudPowerup );
	savefile->ReadInt( hudPowerupDuration );


#endif

	savefile->ReadInt( heartRate );

	savefile->ReadFloat( set );
	heartInfo.SetStartTime( set );
	savefile->ReadFloat( set );
	heartInfo.SetDuration( set );
	savefile->ReadFloat( set );
	heartInfo.SetStartValue( set );
	savefile->ReadFloat( set );
	heartInfo.SetEndValue( set );

	savefile->ReadInt( lastHeartAdjust );
	savefile->ReadInt( lastHeartBeat );
	savefile->ReadInt( lastDmgTime );
	savefile->ReadInt( deathClearContentsTime );
	savefile->ReadBool( doingDeathSkin );
	savefile->ReadInt( lastArmorPulse );
	savefile->ReadFloat( stamina );
	savefile->ReadFloat( healthPool );
	savefile->ReadInt( nextHealthPulse );
	savefile->ReadBool( healthPulse );
	savefile->ReadInt( nextHealthTake );
	savefile->ReadBool( healthTake );

	savefile->ReadBool( hiddenWeapon );
	soulCubeProjectile.Restore( savefile );

	savefile->ReadInt( spectator );
	savefile->ReadVec3( colorBar );
	savefile->ReadInt( colorBarIndex );
	savefile->ReadBool( scoreBoardOpen );
	savefile->ReadBool( forceScoreBoard );
	savefile->ReadBool( forceRespawn );
	savefile->ReadBool( spectating );
	savefile->ReadInt( lastSpectateTeleport );
	savefile->ReadBool( lastHitToggle );
	savefile->ReadBool( forcedReady );
	savefile->ReadBool( wantSpectate );
	savefile->ReadBool( weaponGone );
	savefile->ReadBool( useInitialSpawns );
	savefile->ReadInt( latchedTeam );
	savefile->ReadInt( tourneyRank );
	savefile->ReadInt( tourneyLine );

	teleportEntity.Restore( savefile );
	savefile->ReadInt( teleportKiller );

	savefile->ReadInt( minRespawnTime );
	savefile->ReadInt( maxRespawnTime );

	savefile->ReadVec3( firstPersonViewOrigin );
	savefile->ReadMat3( firstPersonViewAxis );

	// don't bother saving dragEntity since it's a dev tool
	dragEntity.Clear();

	savefile->ReadJoint( hipJoint );
	savefile->ReadJoint( chestJoint );
	savefile->ReadJoint( headJoint );

	savefile->ReadStaticObject( physicsObj );
	RestorePhysics( &physicsObj );

	savefile->ReadInt( num );
	aasLocation.SetGranularity( 1 );
	aasLocation.SetNum( num );
	for( i = 0; i < num; i++ ) {
		savefile->ReadInt( aasLocation[ i ].areaNum );
		savefile->ReadVec3( aasLocation[ i ].pos );
	}

	savefile->ReadInt( bobFoot );
	savefile->ReadFloat( bobFrac );
	savefile->ReadFloat( bobfracsin );
	savefile->ReadInt( bobCycle );
	savefile->ReadFloat( xyspeed );
	savefile->ReadInt( stepUpTime );
	savefile->ReadFloat( stepUpDelta );
	savefile->ReadFloat( stepUpCorrection );
	savefile->ReadFloat( idealLegsYaw );
	savefile->ReadFloat( legsYaw );
	savefile->ReadBool( legsForward );
	savefile->ReadFloat( oldViewYaw );
	savefile->ReadAngles( viewBobAngles );
	savefile->ReadVec3( viewBob );
	savefile->ReadInt( landChange );
	savefile->ReadInt( landTime );

	savefile->ReadInt( currentWeaponSlot );
	savefile->ReadInt( idealWeaponSlot );
	savefile->ReadInt( previousWeaponSlot );
	savefile->ReadInt( weaponSwitchTime );
	savefile->ReadBool( weaponEnabled );
	savefile->ReadBool( showWeaponViewModel );

	savefile->ReadSkin( skin );
	savefile->ReadSkin( powerUpSkin );
	savefile->ReadString( baseSkinName );

	savefile->ReadInt( numProjectilesFired );
	savefile->ReadInt( numProjectileHits );

	savefile->ReadBool( airless );
	savefile->ReadFloat( airTics );
	savefile->ReadInt( lastAirDamage );

	savefile->ReadBool( gibDeath );
	savefile->ReadBool( gibsLaunched );
	savefile->ReadVec3( gibsDir );

	savefile->ReadFloat( set );
	zoomFov.SetStartTime( set );
	savefile->ReadFloat( set );
	zoomFov.SetDuration( set );
	savefile->ReadFloat( set );
	zoomFov.SetStartValue( set );
	savefile->ReadFloat( set );
	zoomFov.SetEndValue( set );

	savefile->ReadFloat( set );
	centerView.SetStartTime( set );
	savefile->ReadFloat( set );
	centerView.SetDuration( set );
	savefile->ReadFloat( set );
	centerView.SetStartValue( set );
	savefile->ReadFloat( set );
	centerView.SetEndValue( set );

	savefile->ReadBool( fxFov );

	savefile->ReadFloat( influenceFov );
	savefile->ReadInt( influenceActive );
	savefile->ReadFloat( influenceRadius );
	savefile->ReadObject( reinterpret_cast<idClass *&>( influenceEntity ) );
	savefile->ReadMaterial( influenceMaterial );
	savefile->ReadSkin( influenceSkin );

	savefile->ReadObject( reinterpret_cast<idClass *&>( privateCameraView ) );

	for( i = 0; i < NUM_LOGGED_VIEW_ANGLES; i++ ) {
		savefile->ReadAngles( loggedViewAngles[ i ] );
	}
	for( i = 0; i < NUM_LOGGED_ACCELS; i++ ) {
		savefile->ReadInt( loggedAccel[ i ].time );
		savefile->ReadVec3( loggedAccel[ i ].dir );
	}
	savefile->ReadInt( currentLoggedAccel );

	savefile->ReadObject( reinterpret_cast<idClass *&>( focusGUIent ) );
	// can't save focusUI
	focusUI = NULL;
	savefile->ReadObject( reinterpret_cast<idClass *&>( focusCharacter ) );
	savefile->ReadInt( talkCursor );
	savefile->ReadInt( focusTime );
	savefile->ReadObject( reinterpret_cast<idClass *&>( focusVehicle ) );
	savefile->ReadUserInterface( cursor );

	savefile->ReadInt( oldMouseX );
	savefile->ReadInt( oldMouseY );

	savefile->ReadString( pdaAudio );
	savefile->ReadString( pdaVideo );
	savefile->ReadString( pdaVideoWave );

	savefile->ReadBool( tipUp );
	savefile->ReadBool( objectiveUp );

	savefile->ReadInt( lastDamageDef );
	savefile->ReadVec3( lastDamageDir );
	savefile->ReadInt( lastDamageLocation );
	savefile->ReadInt( smoothedFrame );
	savefile->ReadBool( smoothedOriginUpdated );
	savefile->ReadVec3( smoothedOrigin );
	savefile->ReadAngles( smoothedAngles );

	savefile->ReadBool( ready );
	savefile->ReadBool( respawning );
	savefile->ReadBool( leader );
	savefile->ReadInt( lastSpectateChange );
	savefile->ReadInt( lastTeleFX );

	// set the pm_ cvars
	const idKeyValue	*kv;
	kv = spawnArgs.MatchPrefix( "pm_", NULL );
	while( kv ) {
		cvarSystem->SetCVarString( kv->GetKey(), kv->GetValue() );
		kv = spawnArgs.MatchPrefix( "pm_", kv );
	}

	savefile->ReadFloat( set );
	pm_stamina.SetFloat( set );

	// create combat collision hull for exact collision detection
	SetCombatModel();

#ifdef _D3XP
	int weaponToggleCount;
	savefile->ReadInt(weaponToggleCount);
	for(i = 0; i < weaponToggleCount; i++) {
		WeaponToggle_t newToggle;
		memset(&newToggle, 0, sizeof(newToggle));

		idStr name;
		savefile->ReadString(name);
		strcpy(newToggle.name, name.c_str());

		int indexCount;
		savefile->ReadInt(indexCount);
		for(int j = 0; j < indexCount; j++) {
			int temp;
			savefile->ReadInt(temp);
			newToggle.toggleList.Append(temp);
		}
		weaponToggles.Set(newToggle.name, newToggle);
	}
	savefile->ReadObject(reinterpret_cast<idClass *&>(mountedObject));
	enviroSuitLight.Restore( savefile );
	
	
	
	savefile->ReadFloat( new_g_damageScale );

	savefile->ReadBool( bloomEnabled );
	savefile->ReadFloat( bloomSpeed );
	savefile->ReadFloat( bloomIntensity );
#endif

	savefile->ReadBool( toggleCrouch );
	savefile->ReadInt( teleportCrouchTime );
}

/*
===============
idPlayer::PrepareForRestart
================
*/
void idPlayer::PrepareForRestart( void ) {
	ClearPowerUps();
	Spectate( true );
	forceRespawn = true;

#ifdef CTF
	// Confirm reset hud states
	DropFlag();

	if ( hud ) {
		hud->SetStateInt( "red_flagstatus", 0 );
		hud->SetStateInt( "blue_flagstatus", 0 );
	}
#endif

	// we will be restarting program, clear the client entities from program-related things first
	ShutdownThreads();

	// the sound world is going to be cleared, don't keep references to emitters
	FreeSoundEmitter( false );
}

/*
===============
idPlayer::Restart
================
*/
void idPlayer::Restart( void ) {
	idActor::Restart();

	// client needs to setup the animation script object again
	if ( gameLocal.isClient ) {
		Init();
	} else {
		// choose a random spot and prepare the point of view in case player is left spectating
		assert( spectating );
		SpawnFromSpawnSpot();
	}

	useInitialSpawns = true;
	UpdateSkinSetup( true );
}

/*
===============
idPlayer::ServerSpectate
================
*/
void idPlayer::ServerSpectate( bool spectate )
{
	assert( !gameLocal.isClient );

	if (spectateState == SPC_FANFAREREADY)
	{
		spectateState = SPC_FANFAREDELAY;
		spectateTimer = gameLocal.hudTime;

		gameSoundWorld->PlayShaderDirectly(spawnArgs.GetString("snd_victorymusic"), SND_CHANNEL_MUSIC);
	}

	if ( spectating != spectate )
	{
		//Set the post-game stats.
		
		spectatorMenu->SetStateString("shipname", gameLocal.GetShipName().c_str());
		
		spectatorMenu->SetStateString("shipdesc", gameLocal.GetShipDesc().c_str());

		//BC get the mission time.
		idStr timeStr = gameLocal.ParseTimeVerbose(gameLocal.time);
		spectatorMenu->SetStateString("missiontime", timeStr.c_str());


		//get the time spent in space.
		int totalspacetime = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->GetTotalTimeSpentInSpace();
		idStr spacetimeDisplayStr;
		idStr spacetimeStr = gameLocal.ParseTimeVerbose(totalspacetime);

		if (totalspacetime > 0)
		{			
			spacetimeDisplayStr = idStr::Format("%s (%.1f%%)", spacetimeStr.c_str(), ((float)totalspacetime / gameLocal.time) * 100);
		}
		else
		{
			spacetimeDisplayStr = idStr::Format("%s (0%%)", spacetimeStr.c_str());
		}

		spectatorMenu->SetStateString("spacetime", spacetimeDisplayStr.c_str());


		spectatorMenu->SetStateInt("projectiletotal", numProjectilesFired);
		//safeguard against divide by zero....
		idStr percentileStr;
		if (numProjectilesFired <= 0)
		{
			spectatorMenu->SetStateString("projectilepct", "0");			
		}
		else
		{
			spectatorMenu->SetStateString("projectilepct", idStr::Format("%d (%.1f%%)", numProjectileHits, ((float)numProjectileHits / numProjectilesFired) * 100));
		}


		spectatorMenu->SetStateInt("pickpocket_attempts", statsPickpocketAttempts);
		if (statsPickpocketAttempts <= 0)
		{
			//if pickpocket stat is zero, then skip the percentage stuff.
			spectatorMenu->SetStateString("pickpocket_successes", "0");			
		}
		else
		{
			//pickpocket stat is NOT zero. Do the percentage stuff.
			spectatorMenu->SetStateString("pickpocket_successes", idStr::Format("%d (%.1f%%)", statsPickpocketSuccesses, ((float)statsPickpocketSuccesses / statsPickpocketAttempts) * 100));
		}

		spectatorMenu->SetStateInt("damagetaken", damageTaken);
		spectatorMenu->SetStateInt("enemiespounced", enemiesPounced);
		spectatorMenu->SetStateInt("brutalslams", brutalslams);
		spectatorMenu->SetStateInt("enemyrespawns", enemyrespawns);


		SetupSpectatorMilestones(spectatorMenu);

		Spectate( spectate );
		if ( spectate ) {
			SetJockeyMode(false);
			SetSpectateOrigin();
		} else {
			if ( gameLocal.gameType == GAME_DM ) {
				// make sure the scores are reset so you can't exploit by spectating and entering the game back
				// other game types don't matter, as you either can't join back, or it's team scores
				gameLocal.mpGame.ClearFrags( entityNumber );
			}
		}

		if (spectateState != SPC_NONE)
		{
			//Update the player progression. Only do this if player was victorious.
			UpdateLevelProgressionIndex();
		}




		//When spectate starts, stop some sounds from playing.

		//Stop the suspicion sizzle sound.
		static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->StopSound(SND_CHANNEL_ANY, 0);

		//Stop ambient sounds from some things.
		idEntity* ent = NULL;
		for (ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
		{
			if (ent == nullptr)
				continue;

			if (ent->IsType(idActor::Type) 
				|| ent->IsType(idWallspeaker::Type) 
				|| ent->IsType(idSecurityCamera::Type)
				|| ent->IsType(idMaintPanel::Type)
				|| ent->IsType(idDoorBarricade::Type))
			{
				ent->StopSound(SND_CHANNEL_ANY, 0);
			}
		}




	}
	if ( !spectate ) {
		SpawnFromSpawnSpot();
	}
#ifdef CTF
	// drop the flag if player was carrying it
	if ( spectate && gameLocal.isMultiplayer && gameLocal.mpGame.IsGametypeFlagBased() && carryingFlag )
	{
		DropFlag();
	}
#endif

	
	//BC player has started to spectate. Stop any sounds that player is doing.
	StopSound(SND_CHANNEL_ANY, false);

	exitLevelHoldTimer = gameLocal.hudTime + 10000; //if final keystroke during mission is frob, this prevents that keystroke from instantly exiting the postgame screen.
}

//Set up the milestone info for the spectator screen.
//This isn't super great as it re-uses code from idPlayer::OnSelectLevelselectIndex
void idPlayer::SetupSpectatorMilestones(idUserInterface* statsGui)
{
	//Grab def of current map.
	idStr mapname;
	mapname = gameLocal.GetMapName();
	mapname.StripPath();
	mapname.StripFileExtension();
	mapname.ToLower();

	const idDecl* mapDecl = declManager->FindType(DECL_MAPDEF, mapname, false);
	const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(mapDecl);
	if (mapDef)
	{
		int currentLevelIndex = mapDef->dict.GetInt("levelindex");

		for (int k = 0; k < MAXMILESTONES; k++)
		{
			//Set up the milestone description text.
			idStr milestoneDesc = mapDef->dict.GetString(idStr::Format("milestone%d", k).c_str());
			statsGui->SetStateString(idStr::Format("milestone%d_desc", k).c_str(), common->GetLanguageDict()->GetString(milestoneDesc.c_str()));

			//Set up the coin stuff.
			bool milestoneIsTrueNow = false;
			statsGui->SetStateBool(idStr::Format("milestonecoin%d_visible", k).c_str(), 0); //turn off all the milestone coins.
			idStr milestoneName = gameLocal.GetMilestonenameViaLevelIndex(currentLevelIndex, k);
			if (milestoneName.Length() > 0)
			{
				if (gameLocal.persistentLevelInfo.GetBool(milestoneName))
				{
					statsGui->SetStateBool(idStr::Format("milestonecoin%d_visible", k).c_str(), 1); //player has achieved this milestone. Mark coin as visible.
					milestoneIsTrueNow = true;
				}
			}

			//Set the sparkles to appear if the milestone was earned during this run.
			bool hadMilestoneAtLevelStart = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->WasMilestoneTrueAtLevelStart(k);
			statsGui->SetStateBool(idStr::Format("milestone%d_justearned", k).c_str(), (milestoneIsTrueNow && !hadMilestoneAtLevelStart));
		}
	}
	else
	{
		gameLocal.Warning("SetupSpectatorMilestones: failed to find .def for current map (%s)", mapname.c_str());
	}
}

//BC this updates the player's level progression index. It only updates it if the latest level completed is FURTHEST in the campaign. So,
//if the player somehow plays an earlier level, it' won't "roll back" the player's progress.
//This gets called when: enter spectator mode OR when you exit a map.
void idPlayer::UpdateLevelProgressionIndex()
{
	idStr mapname;
	mapname = gameLocal.GetMapName();
	mapname.StripPath();
	mapname.StripFileExtension();
	mapname.ToLower();

	//Grab map def of current map.
	const idDecl* mapDecl = declManager->FindType(DECL_MAPDEF, mapname, false);
	const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(mapDecl);
	if (mapDef)
	{
		//found the map def.
		int justcompletedLevelIndex = mapDef->dict.GetInt("levelindex");


		
		if (justcompletedLevelIndex > levelProgressIndex)
		{
			levelProgressIndex = justcompletedLevelIndex;
			gameLocal.persistentLevelInfo.SetInt(PERSISTVAR_LEVELPROGRESS, levelProgressIndex);
			SaveProgression("vig_hub");

			//TODO: set a little flag so that the level select list gui knows how many levels the player has completed.
			//See: quadcow "g_leveldone" logic

			return;
		}
	}

	//player completed a level , but its level index was NOT further along than
	//our current level progress index, so do nothing.
}

int idPlayer::GetLevelProgressionIndex()
{
	return levelProgressIndex;
}

void idPlayer::DebugSetLevelProgressionIndex(int value)
{
	levelProgressIndex = value;
	gameLocal.persistentLevelInfo.SetInt(PERSISTVAR_LEVELPROGRESS, value);
	SavePersistantInfo();
}

/*
===========
idPlayer::SelectInitialSpawnPoint

Try to find a spawn point marked 'initial', otherwise
use normal spawn selection.
============
*/
void idPlayer::SelectInitialSpawnPoint( idVec3 &origin, idAngles &angles ) {
	idEntity *spot;
	idStr skin;


	spot = gameLocal.SelectInitialSpawnPoint( this );

	// set the player skin from the spawn location
	if ( spot->spawnArgs.GetString( "skin", NULL, skin ) ) {
		spawnArgs.Set( "spawn_skin", skin );
	}

	// activate the spawn locations targets
	spot->PostEventMS( &EV_ActivateTargets, 0, this );

	origin = spot->GetPhysics()->GetOrigin();
	origin[2] += 4.0f + CM_BOX_EPSILON;		// move up to make sure the player is at least an epsilon above the floor
	angles = spot->GetPhysics()->GetAxis().ToAngles();
}

/*
===========
idPlayer::SpawnFromSpawnSpot

Chooses a spawn location and spawns the player
============
*/
void idPlayer::SpawnFromSpawnSpot( void )
{
	// SM: Only way this happens is with respawn cheat
	if ( didInitialSpawn )
	{
		SpawnToPoint( GetPhysics()->GetOrigin(), viewAngles );
		return;
	}

	//BC
	if (DoCryoSpawnLogic())
		return; //Cryo spawn successful. Do not do the normal spawn, exit here.

	common->Printf("Skipping cryospawn, doing normal spawn.\n");

	//Do normal spawn.
	idVec3		spawn_origin;
	idAngles	spawn_angles;

	SelectInitialSpawnPoint( spawn_origin, spawn_angles );
	SpawnToPoint( spawn_origin, spawn_angles );
}

/*
===========
idPlayer::SpawnToPoint

Called every time a client is placed fresh in the world:
after the first ClientBegin, and after each respawn
Initializes all non-persistant parts of playerState

when called here with spectating set to true, just place yourself and init
============
*/
void idPlayer::SpawnToPoint( const idVec3 &spawn_origin, const idAngles &spawn_angles ) {
	idVec3 spec_origin;

	assert( !gameLocal.isClient );

	respawning = true;

	Init();

	fl.noknockback = false;

	// stop any ragdolls being used
	StopRagdoll();

	// set back the player physics
	SetPhysics( &physicsObj );

	physicsObj.SetClipModelAxis();
	physicsObj.EnableClip();

	if ( !spectating ) {
		SetCombatContents( true );
	}

	physicsObj.SetLinearVelocity( vec3_origin );

	// setup our initial view
	if ( !spectating ) {
		SetOrigin( spawn_origin );
	} else {
		spec_origin = spawn_origin;
		spec_origin[ 2 ] += pm_normalheight.GetFloat();
		spec_origin[ 2 ] += SPECTATE_RAISE;
		SetOrigin( spec_origin );
	}

	// if this is the first spawn of the map, we don't have a usercmd yet,
	// so the delta angles won't be correct.  This will be fixed on the first think.
	viewAngles = ang_zero;
	SetDeltaViewAngles( ang_zero );
	// <blendo> eric: fixed spawn view angle on map load
	//SetConfinedState(spawn_angles[1],0.0f,false);
	viewAngles = spawn_angles;
	spawnAngles = spawn_angles;
	spawnAnglesSet = false;

	legsForward = true;
	legsYaw = 0.0f;
	idealLegsYaw = 0.0f;
	oldViewYaw = viewAngles.yaw;

	if ( spectating ) {
		Hide();
	} else {
		Show();
	}

	if ( gameLocal.isMultiplayer ) {
		if ( !spectating ) {
			// we may be called twice in a row in some situations. avoid a double fx and 'fly to the roof'
			if ( lastTeleFX < gameLocal.time - 1000 ) {
				idEntityFx::StartFx( spawnArgs.GetString( "fx_spawn" ), &spawn_origin, NULL, this, true );
				lastTeleFX = gameLocal.time;
			}
		}
		AI_TELEPORT = true;
	} else {
		AI_TELEPORT = false;
	}

	// kill anything at the new position
	if ( !spectating ) {
		physicsObj.SetClipMask( MASK_PLAYERSOLID ); // the clip mask is usually maintained in Move(), but KillBox requires it
		gameLocal.KillBox( this );
	}

	// don't allow full run speed for a bit
	physicsObj.SetKnockBack( 100 );

	// set our respawn time and buttons so that if we're killed we don't respawn immediately
	minRespawnTime = gameLocal.time;
	maxRespawnTime = gameLocal.time;
	if ( !spectating ) {
		forceRespawn = false;
	}

	privateCameraView = NULL;

	BecomeActive( TH_THINK );

	// run a client frame to drop exactly to the floor,
	// initialize animations and other things
	Think();

	respawning			= false;
	lastManOver			= false;
	lastManPlayAgain	= false;
	isTelefragged		= false;
}

/*
===============
idPlayer::SavePersistantInfo

Saves any inventory and player stats when changing levels.
===============
*/
void idPlayer::SavePersistantInfo( void ) {
	idDict &playerInfo = gameLocal.persistentPlayerInfo[entityNumber];

	playerInfo.Clear();
	inventory.GetPersistantData( playerInfo );
	playerInfo.SetInt( "health", health );

	idStr tapeStr;
	for (int i = 0; i < tapesCollected.Num(); i++)
	{
		if (i < tapesCollected.Num() - 1)
		{
			tapeStr += idStr::Format("%d,", tapesCollected[i]);
		}
		else
		{
			tapeStr += idStr::Format("%d", tapesCollected[i]);
		}
	}
	playerInfo.Set("tapesCollected", tapeStr.c_str());
	//playerInfo.SetInt( "current_weapon", currentWeaponSlot );
}

/*
===============
idPlayer::RestorePersistantInfo

Restores any inventory and player stats when changing levels.
===============
*/
void idPlayer::RestorePersistantInfo( void ) {
	if ( gameLocal.isMultiplayer ) {
		gameLocal.persistentPlayerInfo[entityNumber].Clear();
	}

	spawnArgs.Copy( gameLocal.persistentPlayerInfo[entityNumber] );

	inventory.RestoreInventory( this, spawnArgs );
 	health = spawnArgs.GetInt( "health", "100" );

	idStr tapeStr = spawnArgs.GetString("tapesCollected", "");
	idStrList tapes = tapeStr.Split(',');
	for (int i = 0; i < tapes.Num(); i++)
	{
		tapesCollected.AddUnique(atoi(tapes[i].c_str()));
	}
// 	if ( !gameLocal.isClient ) {
// 		int currentWeapon = spawnArgs.GetInt( "current_weapon", "1" );
// 		if ( currentWeapon > 0 ) {
// 			GiveItem( spawnArgs.GetString( va( "def_weapon%d", currentWeapon ) ) );
// 		}
// 	}
}

bool idPlayer::SaveProgression(const char* nextMap)
{
#ifndef DEMO
	SavePersistantInfo();
	gameLocal.persistentLevelInfo.Set(PERSISTVAR_NEXTMAP, nextMap);
	idFile* fileOut = fileSystem->OpenFileWrite("savegames/progression.sav");
	if (fileOut)
	{
		gameLocal.persistentLevelInfo.WriteToFileHandle(fileOut);
		gameLocal.persistentPlayerInfo[entityNumber].WriteToFileHandle(fileOut);
		delete fileOut;

		if (spectatorMenu)
		{
			spectatorMenu->HandleNamedEvent("savegame");


		}

		return true;
	}
#endif // DEMO
	return false;
}

void idPlayer::Event_SaveProgression(const char* nextMap)
{
	SaveProgression(nextMap);
}

/*
================
idPlayer::GetUserInfo
================
*/
idDict *idPlayer::GetUserInfo( void ) {
	return &gameLocal.userInfo[ entityNumber ];
}

/*
==============
idPlayer::UpdateSkinSetup
==============
*/
void idPlayer::UpdateSkinSetup( bool restart ) {
	if ( restart ) {
		team = ( idStr::Icmp( GetUserInfo()->GetString( "ui_team" ), "Blue" ) == 0 );
	}
	if ( gameLocal.mpGame.IsGametypeTeamBased() ) { /* CTF */
		if ( team ) {
			baseSkinName = "skins/characters/player/marine_mp_blue";
		} else {
			baseSkinName = "skins/characters/player/marine_mp_red";
		}
		if ( !gameLocal.isClient && team != latchedTeam ) {
			gameLocal.mpGame.SwitchToTeam( entityNumber, latchedTeam, team );
		}
		latchedTeam = team;
	} else {
		baseSkinName = GetUserInfo()->GetString( "ui_skin" );
	}
	if ( !baseSkinName.Length() ) {
		baseSkinName = "skins/characters/player/marine_mp";
	}
	skin = declManager->FindSkin( baseSkinName, false );
	assert( skin );
	// match the skin to a color band for scoreboard
	if ( baseSkinName.Find( "red" ) != -1 ) {
		colorBarIndex = 1;
	} else if ( baseSkinName.Find( "green" ) != -1 ) {
		colorBarIndex = 2;
	} else if ( baseSkinName.Find( "blue" ) != -1 ) {
		colorBarIndex = 3;
	} else if ( baseSkinName.Find( "yellow" ) != -1 ) {
		colorBarIndex = 4;
	} else if ( baseSkinName.Find( "grey" ) != -1 ) {
		colorBarIndex = 5;
	} else if ( baseSkinName.Find( "purple" ) != -1 ) {
		colorBarIndex = 6;
	} else if ( baseSkinName.Find( "orange" ) != -1 ) {
		colorBarIndex = 7;
	} else {
		colorBarIndex = 0;
	}
	colorBar = colorBarTable[ colorBarIndex ];
	if ( PowerUpActive( BERSERK ) ) {
		powerUpSkin = declManager->FindSkin( baseSkinName + "_berserk" );
	}
#ifdef _D3XP
	else if ( PowerUpActive( INVULNERABILITY ) ) {
		powerUpSkin = declManager->FindSkin( baseSkinName + "_invuln" );
	//} else if ( PowerUpActive( HASTE ) ) {
	//	powerUpSkin = declManager->FindSkin( baseSkinName + "_haste" );
	}
#endif
}

/*
==============
idPlayer::BalanceTDM
==============
*/
bool idPlayer::BalanceTDM( void ) {
	int			i, balanceTeam, teamCount[2];
	idEntity	*ent;

	teamCount[ 0 ] = teamCount[ 1 ] = 0;
	for( i = 0; i < gameLocal.numClients; i++ ) {
		ent = gameLocal.entities[ i ];
		if ( ent && ent->IsType( idPlayer::Type ) ) {
			teamCount[ static_cast< idPlayer * >( ent )->team ]++;
		}
	}
	balanceTeam = -1;
	if ( teamCount[ 0 ] < teamCount[ 1 ] ) {
		balanceTeam = 0;
	} else if ( teamCount[ 0 ] > teamCount[ 1 ] ) {
		balanceTeam = 1;
	}
	if ( balanceTeam != -1 && team != balanceTeam ) {
		common->DPrintf( "team balance: forcing player %d to %s team\n", entityNumber, balanceTeam ? "blue" : "red" );
		team = balanceTeam;
		GetUserInfo()->Set( "ui_team", team ? "Blue" : "Red" );
		return true;
	}
	return false;
}

/*
==============
idPlayer::UserInfoChanged
==============
*/
bool idPlayer::UserInfoChanged( bool canModify ) {
	idDict	*userInfo;
	bool	modifiedInfo;
	bool	spec;
	bool	newready;

	userInfo = GetUserInfo();
	showWeaponViewModel = userInfo->GetBool( "ui_showGun" );

	if ( !gameLocal.isMultiplayer ) {
		return false;
	}

	modifiedInfo = false;

	spec = ( idStr::Icmp( userInfo->GetString( "ui_spectate" ), "Spectate" ) == 0 );
	if ( gameLocal.serverInfo.GetBool( "si_spectators" ) ) {
		// never let spectators go back to game while sudden death is on
		if ( canModify && gameLocal.mpGame.GetGameState() == idMultiplayerGame::SUDDENDEATH && !spec && wantSpectate == true ) {
			userInfo->Set( "ui_spectate", "Spectate" );
			modifiedInfo |= true;
		} else {
			if ( spec != wantSpectate && !spec ) {
				// returning from spectate, set forceRespawn so we don't get stuck in spectate forever
				forceRespawn = true;
			}
			wantSpectate = spec;
		}
	} else {
		if ( canModify && spec ) {
			userInfo->Set( "ui_spectate", "Play" );
			modifiedInfo |= true;
		} else if ( spectating ) {
			// allow player to leaving spectator mode if they were in it when si_spectators got turned off
			forceRespawn = true;
		}
		wantSpectate = false;
	}

	newready = ( idStr::Icmp( userInfo->GetString( "ui_ready" ), "Ready" ) == 0 );
	if ( ready != newready && gameLocal.mpGame.GetGameState() == idMultiplayerGame::WARMUP && !wantSpectate ) {
		gameLocal.mpGame.AddChatLine( common->GetLanguageDict()->GetString( "#str_07180" ), userInfo->GetString( "ui_name" ), newready ? common->GetLanguageDict()->GetString( "#str_04300" ) : common->GetLanguageDict()->GetString( "#str_04301" ) );
	}
	ready = newready;
	team = ( idStr::Icmp( userInfo->GetString( "ui_team" ), "Blue" ) == 0 );
	// server maintains TDM balance
	if ( canModify && gameLocal.mpGame.IsGametypeTeamBased() && !gameLocal.mpGame.IsInGame( entityNumber ) && g_balanceTDM.GetBool() ) { /* CTF */
		modifiedInfo |= BalanceTDM( );
	}
	UpdateSkinSetup( false );

	isChatting = userInfo->GetBool( "ui_chat", "0" );
	if ( canModify && isChatting && AI_DEAD ) {
		// if dead, always force chat icon off.
		isChatting = false;
		userInfo->SetBool( "ui_chat", false );
		modifiedInfo |= true;
	}

	return modifiedInfo;
}

/*
===============
idPlayer::UpdateHudAmmo
===============
*/
void idPlayer::UpdateHudAmmo( idUserInterface *_hud ) {
	int inclip;
	int ammoamount;

	assert( weapon.GetEntity() );
	assert( _hud );

	inclip		= weapon.GetEntity()->AmmoInClip();
	ammoamount	= weapon.GetEntity()->AmmoAvailable();


	if ( (ammoamount < 0 || !weapon.GetEntity()->IsReady()) && !contextMenuActive) {
		// show infinite ammo
		_hud->SetStateString( "player_ammo", "" );
		_hud->SetStateString( "player_totalammo", "" );
		_hud->SetStateBool("drawammo", false); //bc
	}
	else
	{
		if (!contextMenuActive)
		{
			_hud->SetStateBool("drawammo", true); //bc
		}

		// show remaining ammo
#ifdef _D3XP

		if (ammoamount >= 0)
		{
			_hud->SetStateString("player_totalammo", va("%i", ammoamount));
		}

#else
		_hud->SetStateString( "player_totalammo", va( "%i", ammoamount - inclip ) );
#endif
		_hud->SetStateString( "player_ammo", weapon.GetEntity()->ClipSize() ? va( "%i", inclip ) : "--" );		// how much in the current clip
		_hud->SetStateString( "player_clips", weapon.GetEntity()->ClipSize() ? va( "%i", ammoamount / weapon.GetEntity()->ClipSize() ) : "--" );

#ifdef _D3XP
		_hud->SetStateString( "player_allammo", va( "%i/%i", inclip, ammoamount ) );
#else
		_hud->SetStateString( "player_allammo", va( "%i/%i", inclip, ammoamount - inclip ) );
#endif

		//BC draw the ammo label string
		idStr ammoname = inventory.AmmoPickupNameForIndex(weapon.GetEntity()->GetAmmoType());
		hud->SetStateString("ammolabel", idStr::Format("%s in pocket", ammoname.c_str()));

	}

	_hud->SetStateBool( "player_ammo_empty", ( ammoamount == 0 ) );
	_hud->SetStateBool( "player_clip_empty", ( weapon.GetEntity()->ClipSize() ? inclip == 0 : false ) );
	_hud->SetStateBool( "player_clip_low", ( weapon.GetEntity()->ClipSize() ? inclip <= weapon.GetEntity()->LowAmmo() : false ) );



#ifdef _D3XP
	//Let the HUD know the total amount of ammo regardless of the ammo required value
	_hud->SetStateString( "player_ammo_count", va("%i", weapon.GetEntity()->AmmoCount()));
#endif



	//_hud->HandleNamedEvent( "updateAmmo" );

	if (mechTransitionState == MECHTRANSITION_PILOTING)
	{
		int displayDir;		

		_hud->SetStateBool("mechreloadprompt", mountedMech.GetEntity()->Player_NeedsReload());

		_hud->SetStateBool("mechrackprompt", mountedMech.GetEntity()->Player_NeedsRack() && !mountedMech.GetEntity()->Player_IsReloading());
		_hud->SetStateBool("mechchambered", !mountedMech.GetEntity()->Player_NeedsRack() && mountedMech.GetEntity()->Player_GetClip() > 0);

		_hud->SetStateBool("mechreloading", mountedMech.GetEntity()->Player_IsReloading());
		_hud->SetStateInt("mechammo", mountedMech.GetEntity()->Player_GetClip());
		_hud->SetStateInt("mechtotalammo", mountedMech.GetEntity()->Player_GetAmmo());

		//Mech speed display.
		if (mechSpeedTimer < gameLocal.time)
		{
			int speedNum;
			mechSpeedTimer = gameLocal.time + 75;
			speedNum = GetPhysics()->GetLinearVelocity().Length();
			//common->Printf("%d\n", speedNum);
			_hud->SetStateInt("mechspeed", speedNum);

			_hud->SetStateString("mechpitch", va("%.1f", viewAngles.pitch));

			_hud->SetStateInt("mech_x", GetPhysics()->GetOrigin().x);
			_hud->SetStateInt("mech_y", GetPhysics()->GetOrigin().y);
			_hud->SetStateInt("mech_z", GetPhysics()->GetOrigin().z);
		}
				
		//Mech compass.
		if (viewAngles.yaw < 112 && viewAngles.yaw > 68)
		{
			_hud->SetStateString("compassdir", "N");
		}
		else if (viewAngles.yaw < 157 && viewAngles.yaw > 112)
		{
			_hud->SetStateString("compassdir", "NW");
		}
		else if (viewAngles.yaw < 68 && viewAngles.yaw > 23)
		{
			_hud->SetStateString("compassdir", "NE");
		}
		else if (viewAngles.yaw > -112 && viewAngles.yaw < -68)
		{
			_hud->SetStateString("compassdir", "S");
		}
		else if (viewAngles.yaw > -157 && viewAngles.yaw < -112)
		{
			_hud->SetStateString("compassdir", "SW");
		}
		else if (viewAngles.yaw > -68 && viewAngles.yaw < -23)
		{
			_hud->SetStateString("compassdir", "SE");
		}
		else if (viewAngles.yaw > -23 && viewAngles.yaw < 23)
		{
			_hud->SetStateString("compassdir", "E");
		}
		else
		{
			_hud->SetStateString("compassdir", "W");
		}

		if (viewAngles.yaw < 135 && viewAngles.yaw > 45)
		{
			_hud->SetStateString("shipdir", "FORWARD");
		}
		else if (viewAngles.yaw > -135 && viewAngles.yaw < -45)
		{
			_hud->SetStateString("shipdir", "AFT");
		}
		else if (viewAngles.yaw < 45 && viewAngles.yaw > -45)
		{
			_hud->SetStateString("shipdir", "STARBOARD");
		}
		else
		{
			_hud->SetStateString("shipdir", "PORT");
		}
		

		if (viewAngles.yaw > 90)
		{
			displayDir = 180 - viewAngles.yaw + 270;
		}
		else if (viewAngles.yaw > 0)
		{
			displayDir = 180 - viewAngles.yaw - 90;
		}
		else
		{
			displayDir = -viewAngles.yaw + 90;
		}

		_hud->SetStateInt("compassnum", displayDir);		
		
	}

	//item durability.
	int itemHealth = -1;
	if (carryableItem.IsValid())
	{
		itemHealth = carryableItem.GetEntity()->health;
	}
	else if (weapon.IsValid())
	{
		int currentWeapon = inventory.hotbarSlots[currentWeaponSlot].weaponType;
		if (currentWeapon > 0)
		{
			int equippedSlot = inventory.GetHotbarSelection();
			itemHealth = inventory.hotbarSlots[equippedSlot].health;
		}
	}

	_hud->SetStateInt("item_durability", itemHealth);
	
	





	//weapon chamber state.
	_hud->SetStateBool("chambered", weapon.GetEntity()->Event_RoundIsChambered());
}

/*
===============
idPlayer::UpdateHudStats
===============
*/
void idPlayer::UpdateHudStats( idUserInterface *_hud ) {
	int staminapercentage;
	float max_stamina;

	assert( _hud );

	max_stamina = pm_stamina.GetFloat();
	if ( !max_stamina ) {
		// stamina disabled, so show full stamina bar
		staminapercentage = 100.0f;
	} else {
		staminapercentage = idMath::FtoiFast( 100.0f * stamina / max_stamina );
	}

	
	float healthPercentage = float(health / float(maxHealth));
	healthPercentage = Min(healthPercentage, 1.0f);
	_hud->SetStateFloat("player_healthpercent", healthPercentage);

	_hud->SetStateInt( "player_health", health );
	_hud->SetStateInt( "player_stamina", staminapercentage );
	_hud->SetStateInt( "player_armor", inventory.armor );
	_hud->SetStateInt( "player_hr", heartRate );


	if (health <= 0)
		_hud->SetStateInt("player_healthpips", 0);
	else
	{
		int healthPips = Max(1, (health / HEALTH_PER_HEALTHBARBLOCK));
		_hud->SetStateInt("player_healthpips", healthPips);
	}


	_hud->SetStateInt( "player_nostamina", ( max_stamina == 0 ) ? 1 : 0 );

	_hud->HandleNamedEvent( "updateArmorHealthAir" );

#ifdef _D3XP
	//_hud->HandleNamedEvent( "updatePowerup" );
#endif

	if ( healthPulse ) {
		_hud->HandleNamedEvent( "healthPulse" );
		StartSound( "snd_healthpulse", SND_CHANNEL_ITEM, 0, false, NULL );
		healthPulse = false;
	}

	if ( healthTake ) {
		_hud->HandleNamedEvent( "healthPulse" );
		StartSound( "snd_healthtake", SND_CHANNEL_ITEM, 0, false, NULL );
		healthTake = false;
	}

	if ( inventory.ammoPulse ) {
		_hud->HandleNamedEvent( "ammoPulse" );
		inventory.ammoPulse = false;
	}
	if ( inventory.weaponPulse ) {
		// We need to update the weapon hud manually, but not
		// the armor/ammo/health because they are updated every
		// frame no matter what
		UpdateHudWeapon();
		_hud->HandleNamedEvent( "weaponPulse" );
		inventory.weaponPulse = false;
	}
	if ( inventory.armorPulse ) {
		_hud->HandleNamedEvent( "armorPulse" );
		inventory.armorPulse = false;
	}

#ifdef CTF
	if ( gameLocal.mpGame.IsGametypeFlagBased() && _hud )
	{
		_hud->SetStateInt( "red_flagstatus", gameLocal.mpGame.GetFlagStatus( 0 ) );
		_hud->SetStateInt( "blue_flagstatus", gameLocal.mpGame.GetFlagStatus( 1 ) );

		_hud->SetStateInt( "red_team_score",  gameLocal.mpGame.GetFlagPoints( 0 ) );
		_hud->SetStateInt( "blue_team_score", gameLocal.mpGame.GetFlagPoints( 1 ) );

		_hud->HandleNamedEvent( "RedFlagStatusChange" );
		_hud->HandleNamedEvent( "BlueFlagStatusChange" );
	}

	//_hud->HandleNamedEvent( "selfTeam" );

#endif


	UpdateHudAmmo( _hud );


	//BC Conditions
	_hud->SetStateFloat("cond_burning", burningTimer > 0 ? (burningTimer - gameLocal.time) / CONDITION_BURNING_TIME : 0);
	_hud->SetStateInt("cond_burnwoundcount", cond_burnwound);
	_hud->SetStateInt("cond_glasswoundcount", cond_glasswound);
	_hud->SetStateInt("cond_woundcount", GetWoundCount());
	_hud->SetStateInt("cond_bulletwoundcount", cond_bulletwound);
	_hud->SetStateInt("cond_shrapnelcount", cond_shrapnel);
	_hud->SetStateInt("cond_spearcount", cond_spearwound);
	_hud->SetStateInt("cond_smelly", cond_smelly);

	_hud->SetStateInt("sneezevalue", sneezeValue);

	_hud->SetStateBool("fallenstate", (physicsObj.GetFallState() == FALLEN_IDLE) && (!inDownedState));

	_hud->SetStateBool("cargohidestate", (physicsObj.GetAcroType() != ACROTYPE_NONE) && (physicsObj.GetClamberState() == CLAMBERSTATE_ACRO));

	_hud->SetStateBool("dragbodystate", bodyDragger.isDragging && !contextMenuActive);

	_hud->SetStateBool("carrying", carryableItem.IsValid() && !contextMenuActive && !peekObject.IsValid());


	_hud->SetStateInt("bloodbagCount", inventory.bloodbags);

	if (inventory.bloodbags > 0 && inDownedState) //for the MMB prompt when player is downed.
	{
		_hud->SetStateBool("show_bloodprompt", true);
	}
	else
	{
		_hud->SetStateBool("show_bloodprompt", false);
	}

	_hud->SetStateBool("armstats_active", armstatsActive == true);
	_hud->SetStateBool("contextmenu_active", contextMenuState == CONTEXTMENU_ACTIVE);

	//Determine which legend to show.
	int legendToShow = LEGEND_NONE;
	if (weapon.IsValid())
	{
		if (grenadeThrowState == GRENADETHROW_AIMING && shouldDrawThrowArc)
		{
			lastThrowArcState = true;
			legendToShow = LEGEND_THROWMODE;
		}
		else if (peekObject.IsValid())
		{
			if (static_cast<idVentpeek*>(peekObject.GetEntity())->forTelescope)
			{
				if (static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->CanPanAndZoom())
				{
					legendToShow = LEGEND_TELESCOPE;

					_hud->SetStateBool("showCanTakePhoto", static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->CanTakePhoto());
					_hud->SetStateInt("photoCount", static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->GetPhotoCount());
					_hud->SetStateBool("showTelescopeExit", static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->CanFrobExit());
				}
				else
				{
					legendToShow = LEGEND_NONE; // We're in the telescope, but our normal inputs are locked for some reason
				}
			}
			else
			{
				legendToShow = LEGEND_VENTPEEK;

				if (peekObject.GetEntity()->IsType(idVentpeek::Type))
				{
					bool peekHasOwner = static_cast<idVentpeek*>(peekObject.GetEntity())->ownerEnt.IsValid();

					_hud->SetStateBool("showEmerge", peekHasOwner);
				}
			}
		}
		else if (armstatsActive)
		{
			legendToShow = LEGEND_WRISTMAP;
		}
		else if (jockeyState == JCK_ATTACHED)
		{
			legendToShow = LEGEND_JOCKEY;
		}
		else if (ShouldHideLegend())
		{
			legendToShow = LEGEND_NONE;
		}
		else if (weapon.GetEntity()->spawnArgs.GetInt("clipsize") > 0)
		{		
			legendToShow = LEGEND_GUN;
		}
		else if (weapon.GetEntity()->spawnArgs.GetBool("isgrenade"))
		{
			//grenade.
			legendToShow = LEGEND_GRENADE;
		}
		else if (weapon.GetEntity()->spawnArgs.GetInt("legend") == LEGEND_SIGNALLAMP)
		{
			legendToShow = LEGEND_SIGNALLAMP;
		}
		else if (carryableItem.IsValid())
		{
			legendToShow = LEGEND_CARRYABLE;

			bool carryfrob = carryableItem.GetEntity()->spawnArgs.GetBool("carryfrob"); //is this something that can be activated with LMB=use , i.e. deodorant, pepperbag.
			_hud->SetStateBool("carryfrob", carryfrob);

			bool caninspect = carryableItem.GetEntity()->spawnArgs.GetVector("inspect_offset") != vec3_zero;
			_hud->SetStateBool("caninspect", caninspect);
			
		}
	}

	
	_hud->SetStateInt("buttonlegend", legendToShow);

	if (!placerEnt->IsHidden() && placerClearance && !peekObject.IsValid() && viewyawState == LERPSTATE_OFF)
	{
		//Placer is available, visible, ready to place.
		_hud->SetStateBool("placervisible", true);
		_hud->SetStateBool("invalidplacer", false);
	}
	else if (!placerEnt->IsHidden() && !placerClearance)
	{
		//Placer is visible, but does not have clearance.
		_hud->SetStateBool("placervisible", false);
		_hud->SetStateBool("invalidplacer", true);
	}
	else
	{
		//Placer is hidden.
		_hud->SetStateBool("placervisible", false);
		_hud->SetStateBool("invalidplacer", false);
	}

	//check if player is holding anything.
	bool playerIsEquipped = false;
	int currentHotbarslotIndex = inventory.GetHotbarSelection();
	if (currentHotbarslotIndex >= 0)
	{
		playerIsEquipped = inventory.hotbarSlots[currentHotbarslotIndex].weaponType > 0;
	}

	_hud->SetStateBool("showtrashprompt", playerIsEquipped && trashchuteFocus.IsValid());

	//update grab ring UI.
	bool isHoldingGrabring = physicsObj.GetGrabringState();
	_hud->SetStateBool("showgrabringprompt", isHoldingGrabring);

	//update heal progress bar.
	_hud->SetStateBool("showhealbar", (healState != HEALSTATE_NONE));
	if (healState != HEALSTATE_NONE)
	{
		int elapsedTime = gameLocal.time - healbarStartTime;
		float ratioComplete = elapsedTime / (float)healbarTotalTime;

		_hud->SetStateFloat("healbaramount", ratioComplete);

		//Set the heal text label on the heal bar ui.
		idStr healText = "";
		switch (healState)
		{
			case HEALSTATE_GLASSPULL:
				healText = idStr::Format("Removing glass (%d remaining)", cond_glasswound);
				break;
			case HEALSTATE_BURNING:
				healText = "Patting out fire";
				break;
			case HEALSTATE_SHRAPNEL:
				healText = idStr::Format("Removing shrapnel (%d remaining)", cond_shrapnel);
				break;
			case HEALSTATE_BULLETPLUCK:
				healText = idStr::Format("Removing bullets (%d remaining)", cond_bulletwound);
				break;
		}
		_hud->SetStateString("healtext", healText.c_str());
	}
}

bool idPlayer::ShouldHideLegend()
{
	if (weapon.GetEntity()->IsReloading() ||  weapon.GetEntity()->IsRacking() || leanState != LEANSTATE_OFF
		|| contextMenuActive || armstatsActive || iteminspectActive || physicsObj.GetAcroType() != ACROTYPE_NONE)
		return true;

	if (weapon.GetEntity()->IsInspectingMagazine() || weapon.GetEntity()->IsInspectingChamber())
	{
		if (weapon.GetEntity()->spawnArgs.GetInt("clipSize") > 0)
			return true;
	}

	return false;
}

/*
===============
idPlayer::UpdateHudWeapon
===============
*/
void idPlayer::UpdateHudWeapon( bool flashWeapon ) {
	idUserInterface *hud = idPlayer::hud;

	// if updating the hud of a followed client
	if ( gameLocal.localClientNum >= 0 && gameLocal.entities[ gameLocal.localClientNum ] && gameLocal.entities[ gameLocal.localClientNum ]->IsType( idPlayer::Type ) ) {
		idPlayer *p = static_cast< idPlayer * >( gameLocal.entities[ gameLocal.localClientNum ] );
		if ( p->spectating && p->spectator == entityNumber ) {
			assert( p->hud );
			hud = p->hud;
		}
	}

	if ( !hud ) {
		return;
	}

	for ( int i = 0; i < MAX_HOTBARSLOTS; ++i ) {
		int weaponType = inventory.hotbarSlots[i].weaponType;
		if ( weaponType != -1 ) {
			const char *weapnum = va( "def_weapon%d", weaponType );
			const char *weap = spawnArgs.GetString( weapnum );
			if ( weap && *weap && idealWeaponSlot == i ) {
				//BC player switched weapons. update the weapon UI on the hud.
				const char *weap = spawnArgs.GetString( weapnum );
				const idDeclEntityDef *weapDef = gameLocal.FindEntityDef( weap, false );
				if ( weapDef )
				{
					//hud->SetStateString("equippedweapon", weapDef->dict.GetString("displayname") );
					UpdateThrownWeapon( weapDef );
				}
				break;
			}
		}
	}

	if ( flashWeapon ) {

/*#ifdef _D3XP
		//Clear all hud weapon varaibles for the weapon change
		hud->SetStateString( "player_ammo", "" );
		hud->SetStateString( "player_totalammo", "" );
		hud->SetStateString( "player_clips", "" );
		hud->SetStateString( "player_allammo", "" );
		hud->SetStateBool( "player_ammo_empty", false );
		hud->SetStateBool( "player_clip_empty", false );
		hud->SetStateBool( "player_clip_low", false );
		hud->SetStateString( "player_ammo_count", "");
#endif*/

		
		
		hud->HandleNamedEvent( "weaponChange" );
	}
}

bool idPlayer::ShouldDrawJockeyWallUI(bool baseValue)
{
	if (baseValue)
	{
		if (meleeTarget.IsValid()) //Do not draw the wall attack UI if a jockey attack animation is currently in progress.
		{
			idGunnerMonster *aiEnt = static_cast<idGunnerMonster *>(meleeTarget.GetEntity());
			if (aiEnt->IsJockeyBeingAttacked())
			{
				return false;
			}
		}

		return true;		
	}

	return false;
}

/*
===============
idPlayer::DrawHUD
===============
*/
void idPlayer::DrawHUD( idUserInterface *_hud )
{
	if (!weapon.GetEntity() || influenceActive != INFLUENCE_NONE || privateCameraView || gameLocal.GetCamera() || !_hud
		|| !g_showHud.GetBool() || g_hideHudInternal.GetBool())
	{
		//if (defibState == DEFIB_HEARTANIM)
		if (gameLocal.inCinematic)
		{
			videoMenu->Redraw(gameLocal.time); //Obsolete?

			if (drawCinematicHUD)
			{
				_hud->Redraw(gameLocal.hudTime);
				gameLocal.DrawSubtitles(_hud);
			}

			if (cameraGuiMenu != nullptr)
			{
				cameraGuiMenu->Redraw(gameLocal.time);
				return;
			}
		}

		return;
	}




	if (!zoommodeActive && !zoominspect_LabelmodeActive && !iteminspectActive && health > 0 && !inDownedState && ActiveGui() == nullptr && !armstatsActive)
	{
		// SW: Ventpeeks can specifically opt-in to dynatips if necessary
		if (!peekObject.IsValid() || peekObject.GetEntity()->spawnArgs.GetBool("allowDynatip", "0"))
		{

			idDynaTip* bestTip = NULL;
			float bestAngle = 0.0f;
			for (idEntity* ent = gameLocal.dynatipEntities.Next(); ent != NULL; ent = ent->dynatipNode.Next())
			{
				if (!ent)
					continue;

				if (ent->IsType(idDynaTip::Type))
				{
					idDynaTip* tip = static_cast<idDynaTip*>(ent);
					tip->Draw();

					if (tip->GetDotAngle() > bestAngle && tip->OnScreen())
					{
						bestTip = tip;
						bestAngle = tip->GetDotAngle();
					}
				}
			}

			if (bestTip != NULL && bestTip->OnScreen())
			{
				//Check player LOS to the dynatip.
				#define TRDELTA_THRESHOLD 4 //distance the tracepoint can be from the zoominspect point

				idVec3 inspectPosition = GetZoominspectAdjustedPosition(bestTip->GetTarget());
				trace_t	tr;
				gameLocal.clip.TracePoint(tr, GetEyePosition(), inspectPosition, MASK_SOLID, this, CONTENTS_TRANSLUCENT);
				float trDelta = (tr.endpos - inspectPosition).Length();			
				if (trDelta < TRDELTA_THRESHOLD)
				{
					//The player has LOS. Draw the dynatip text.
					bestTip->DrawText();
				}
			}
		}
	}

	DrawZoomInspect();

	DrawPickpocketUI();

	DrawIngressPoints();

	//Handle the jockey UI stuff.
	hud->SetStateBool("showjockeyprompts", (jockeyState == JCK_ATTACHED));
	//bool jockeyDraw = DrawJockeyUI();
	DrawJockeyUI();

	//Handle whether to draw or hide the jockey wall smash UI.
	//bool drawJockeyWallUI = ShouldDrawJockeyWallUI(jockeyDraw);
	//if (drawJockeyWallUI)
	//{
	//	if (jockeyDisc->IsHidden())
	//		jockeyDisc->Show();
	//}
	//else if (!jockeyDisc->IsHidden())
	//	jockeyDisc->Hide();

	DrawMemoryPalace();

	DrawEnemyHealth();

	UpdateHudStats( _hud );

	_hud->SetStateString( "weapicon", weapon.GetEntity()->Icon() );

	// FIXME: this is temp to allow the sound meter to show up in the hud
	// it should be commented out before shipping but the code can remain
	// for mod developers to enable for the same functionality
	_hud->SetStateInt( "s_debug", cvarSystem->GetCVarInteger( "s_showLevelMeter" ) );

	weapon.GetEntity()->UpdateGUI();	



	//Draw the frob cursor.
	if (cursor->GetStateInt("frobcursor") > 0 && frobEnt != NULL && health > 0 && mechTransitionState == MECHTRANSITION_NONE
		&& (physicsObj.GetClamberState() == CLAMBERSTATE_NONE) && jockeyState != JCK_ATTACHED) //TODO: this hides all frob prompts when in any acro mode.... may need to change this!!!!
	{
		DrawFrobHUD(gameLocal.hudTime);
	}
	else
	{
		hud->SetStateBool("showfrobprompt", false);
	}
	DrawMeleeCursor();


	_hud->Redraw(gameLocal.hudTime);

	if (contextMenuActive)
	{
		//update every frame with condition updates.
		UpdateContextConditions();
		contextMenu->Redraw(gameLocal.hudTime);
	}

	

	//DrawAIDodgeUI();
	

	

	// weapon targeting crosshair
	if ( !GuiActive() && health > 0)
	{
		if ( cursor && weapon.GetEntity()->ShowCrosshair() )
		{

			if ( weapon.GetEntity()->GetGrabberState() == 1 || weapon.GetEntity()->GetGrabberState() == 2 || mechTransitionState == MECHTRANSITION_PILOTING || armstatsActive) //BC hide crosshair if in mech mode.
			{
				cursor->SetStateString( "grabbercursor", "1" );
				cursor->SetStateString( "combatcursor", "0" );
			}
			else
			{
				cursor->SetStateString( "grabbercursor", "0" );
				cursor->SetStateString( "combatcursor", "1" );
			}


			cursor->Redraw( gameLocal.realClientTime );
		}
	}

	



	//Update the Auto-aim UI.
	if (weapon.GetEntity() != NULL && !hiddenWeapon && health > 0 && !carryableItem.IsValid())
	{
		if (weapon.GetEntity()->autoaimEnabled)
		{
			DrawAutoAimUI();
		}
	}

	if (weapon.GetEntity() != NULL && health > 0)
	{
		DrawBeaconUI();
	}

	DrawGrabUI();	

	//Draw weapon button prompt.
	if (weapon.GetEntity())
	{
		if (!weapon.GetEntity()->IsReady())
			buttonpromptType = -1;

		if (buttonpromptType >= 0)
		{
			if (gameLocal.time > buttonpromptTimer)
			{
				buttonpromptType = -1;
			}
			else if (weapon.GetEntity()->IsReady())
			{
				jointHandle_t slideJoint;
				
				if (buttonpromptType == BUTTONPROMPT_RACKSLIDE)
					slideJoint = weapon.GetEntity()->GetAnimator()->GetJointHandle(weapon.GetEntity()->spawnArgs.GetString("bone_slideprompt", "slide"));
				else
					slideJoint = weapon.GetEntity()->GetAnimator()->GetJointHandle(weapon.GetEntity()->spawnArgs.GetString("bone_reloadprompt", "reloadprompt"));

				if (slideJoint)
				{
					idVec2 slideScreenPos;
					idVec3 slidePos;

					slidePos = weapon.GetEntity()->GetJointPosition(slideJoint);
					slideScreenPos = GetWorldToScreen(slidePos);

					hud->SetStateFloat("rackbutton_x", slideScreenPos.x);
					hud->SetStateFloat("rackbutton_y", slideScreenPos.y);
				}
			}
		}

		hud->SetStateBool("showrackbutton", buttonpromptType == BUTTONPROMPT_RACKSLIDE);
		hud->SetStateBool("showreloadbutton", buttonpromptType == BUTTONPROMPT_RELOAD);

		hud->SetStateBool("mechhud", mechTransitionState == MECHTRANSITION_PILOTING);
	}

	
	


	if (healthDamageFlashTimer > gameLocal.time && (health > 0) && !inDownedState)
	{
		float lerp = (healthDamageFlashTimer - gameLocal.time) / (float)HEALTHBAR_DAMAGE_FLASHTIME;

		float imageWidth = idMath::Lerp(1, 64, lerp);
		float imageHeight = idMath::Lerp(32, 128, lerp);


		//Check hud.gui for these values. x,y of healthbar position.
		#define	DAMAGEFLASH_X 20
		#define DAMAGEFLASH_Y 440
		#define HEALTHBAR_IMAGEWIDTH 160 //total length of healthbar in virtual 640x480 resolution.


		//Damage flash below the healthbar.

		float flashLerpedPos = float(health / float(maxHealth)) * HEALTHBAR_IMAGEWIDTH;

		renderSystem->DrawStretchPic(
			DAMAGEFLASH_X + (flashLerpedPos)  - (imageWidth / 2.0f),
			440 + 12,
			imageWidth, imageHeight,
			0, 0, 1, 1, declManager->FindMaterial("guis/assets/healthdamageflash"));

		//Damage flash above the healthbar.
		renderSystem->DrawStretchPic(
			DAMAGEFLASH_X + (flashLerpedPos) - (imageWidth / 2.0f),
			440 - imageHeight,
			imageWidth, imageHeight,
			0, 0, 1, -1, declManager->FindMaterial("guis/assets/healthdamageflash"));
	}

	//draw suspicion arrows.

	DrawSuspicionArrows();


	//DRAW DAMAGE ARROWS.
	/*
	for (i = 0; i < DAMAGEARROW_COUNT; i++)
	{
		idVec3 damagePosition, myPosition, viewForward, angleToTarget;
		idVec2 drawPosition;
		float finalAngle, arrowSize, arrowDistance;
		int isDot;

		if (damageArrowTimers[i] < gameLocal.time)
			continue;

		if (damageArrowTimers[i] - gameLocal.time > (DAMAGEARROW_MAXTIME * .95f))
		{
			float lerp = 1.0f - (((damageArrowTimers[i] - gameLocal.time) - (DAMAGEARROW_MAXTIME * .95f)) / (DAMAGEARROW_MAXTIME * .05f));

			if (lerp > 1.0f)
				lerp = 1;
			
			arrowSize = idMath::Lerp(400,100,lerp);
			arrowDistance = idMath::Lerp(300,60,lerp);
			isDot = false;
		}
		else if (damageArrowTimers[i] - gameLocal.time > (DAMAGEARROW_MAXTIME * .8f))
		{
			float lerp = 1.0f - (((damageArrowTimers[i] - gameLocal.time) - (DAMAGEARROW_MAXTIME * .8f)) / (DAMAGEARROW_MAXTIME * .2f));

			//this lerp value calculation is not 100% correct but is good enough
			arrowSize = 10;
			lerp = idMath::CubicEaseOut(lerp);
			arrowDistance = idMath::Lerp(5, 30, lerp);
			//common->Printf("%f\n", lerp);
			isDot = true;
		}
		else
		{
			float lerp = 1.0f - (((damageArrowTimers[i] - gameLocal.time) - (DAMAGEARROW_MAXTIME * .05f)) / (DAMAGEARROW_MAXTIME * .95f));

			arrowSize = idMath::Lerp(10,.1f,lerp);
			arrowDistance = 30;
			isDot = true;
		}

		damagePosition = damageArrowPosition[i];
		damagePosition.z = 0;

		myPosition = this->GetPhysics()->GetOrigin();
		myPosition.z = 0;

		viewForward = viewAngles.ToForward();
		viewForward.Normalize();

		angleToTarget = damagePosition - myPosition;
		angleToTarget.Normalize();

		finalAngle = atan2(angleToTarget.x, angleToTarget.y) * -1.0f; //Player position.
		finalAngle -= DEG2RAD(viewAngles.yaw - 90);  //Player yaw.


		drawPosition = idVec2(320 - (arrowSize/2), 240 - (arrowSize/2));

		drawPosition.x += cos(finalAngle + 1.57f) * arrowDistance;
		drawPosition.y += sin(finalAngle - 1.57f) * arrowDistance;


		renderSystem->DrawStretchPicRotated(drawPosition.x, drawPosition.y, arrowSize, arrowSize, 0, 0, 1, 1,
			isDot ? declManager->FindMaterial("guis/assets/damagearrowdot") : declManager->FindMaterial("guis/assets/damagearrow"), finalAngle);
	}
	*/

	//DRAW THE LISTEN MODE NOISEEVENTS. THE FOOTSTEP TAP TAP TAPS
	//if (this->listenmodeVisualizerTime > gameLocal.time)
	//{
	//	const int NOISE_MAXDIST = 900000;
	//	const int NOISE_MINDIST = 200000;
    //
	//	for (i = 0; i < NOISEEVENT_COUNT; i++)
	//	{
	//		idVec2 noiseScreenPos;
	//		float lerp, size, baseSize;
	//		idStr texture;
    //
	//		if (noiseEventTimer[i] < gameLocal.time)
	//			continue;
    //
	//		//An active noiseEvent.
    //
	//		//Scale the size depending on distance to player.
	//		baseSize = (noiseEventPos[i] - this->GetPhysics()->GetOrigin()).LengthSqr();
    //
	//		if (baseSize > NOISE_MAXDIST)
	//			continue;
    //
	//		baseSize = NOISE_MAXDIST - baseSize;
	//		
	//		if (baseSize < NOISE_MINDIST)
	//			baseSize = NOISE_MINDIST;
    //
	//		baseSize *= .00006f;
    //
	//		if (noiseEventType[i] == NOISETYPE_GUNSHOT)
	//			baseSize *= 2.0f;
    //
    //
	//		lerp = (noiseEventTimer[i] - gameLocal.time) / 1000.0f;
	//		size = idMath::PopLerp(0, baseSize, baseSize * .75f, lerp);
    //
    //
	//		noiseScreenPos = GetWorldToScreen(noiseEventPos[i]);
	//		noiseScreenPos.x -= size / 2.0f;
	//		noiseScreenPos.y -= size / 2.0f;
    //
	//		if (noiseEventType[i] == NOISETYPE_FOOTSTEP)
	//			texture = "guis/assets/noise_tap";
	//		else if (noiseEventType[i] == NOISETYPE_GUNSHOT)
	//			texture = "guis/assets/noise_bang";
    //
    //
	//		renderSystem->DrawStretchPicRotated(noiseScreenPos.x, noiseScreenPos.y, size, size, 0, 0, 1, 1, declManager->FindMaterial(texture), 0);
	//	}
	//}

	UpdateFlytext();
	
	//draw the placerEnt button prompt.
	if (!placerEnt->IsHidden() && placerClearance)
	{
		//Draw the prompt.
		//renderSystem->DrawStretchPic(100, 100, 40, 20, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/buttonprompt"));
		//gameLocal.GetKeyFromBinding("_attack")
		idVec2 placerScreenPos;
		idVec3 up;
		
		placerEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(NULL, NULL, &up);
		placerScreenPos = GetWorldToScreen(placerEnt->GetPhysics()->GetOrigin() + (up * -9));
		hud->SetStateInt("placer_y", placerScreenPos.y);

		idStr displayName = weapon.GetEntity()->displayName;
		if ( GetCarryable() )
		{
			displayName = GetCarryable()->displayName;
		}

		//Show displayname of placer weapon.
		hud->SetStateString("placertext", va("%s %s\n",
			common->GetLanguageDict()->GetString("#str_gui_hud_100073"), //"place"
			common->GetLanguageDict()->GetString( displayName.c_str())));	
	}

	//Throw arc Drop Prompt
	if (shouldDrawThrowArc && !throwdisc->IsHidden() && throwarcDropMode)
	{
		#define THROWDISC_RADIUS 9		
		idAngles playerViewangleNoPitch = viewAngles;
		playerViewangleNoPitch.pitch = 0;
		playerViewangleNoPitch.roll = 0;
		
		idVec3 drawPosition = throwdisc->GetPhysics()->GetOrigin() + (playerViewangleNoPitch.ToForward() * THROWDISC_RADIUS);
		idVec2 placerScreenPos = GetWorldToScreen(drawPosition);
		//hud->DrawArbitraryText("DROP", .6f, idVec4(1, 1, 1, 1), placerScreenPos.x, placerScreenPos.y - 50, "fonts/sofia", idVec4(0, 0, 0, 1), idDeviceContext::ALIGN_CENTER);

		#define DROPICONRADIUS 15
		renderSystem->DrawStretchPic(placerScreenPos.x - DROPICONRADIUS, placerScreenPos.y - 10 - DROPICONRADIUS * 2, DROPICONRADIUS*2, DROPICONRADIUS*4, 0, 0, 1,1, declManager->FindMaterial(spawnArgs.GetString("mtr_dropicon")));
	}

	if (g_editEntityMode.GetInteger() > 0)
	{
		if (g_editEntityMode.GetInteger() == 1)
		{
			gameEdit->lighteditMenu->Redraw(gameLocal.time); //BC draw the editmode GUI menu.
		}
	}

	if (armstatsActive || zoommodeActive)
	{
		//Get stats to display.
		int enemyActors = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetEnemiesRemaining(true);		

		//for (i = 0; i < AMMO_NUMTYPES; i++)
		//{
		//	int amount = inventory.ammo[i];
		//
		//	renderSystem->DrawSmallStringExt(20, 50 + i*15,
		//		va("Ammo %s (%d): %d", inventory.AmmoPickupNameForIndex(i),  i, amount),
		//		idVec4(0, 1, 0, 1), true, declManager->FindMaterial("textures/bigchars"));
		//}

		if (armstatsActive)
		{
			idLocationEntity* locationEntity = gameLocal.LocationForPoint(GetEyePosition());
			armstatsModel->Event_SetGuiInt("enemiesremaining", enemyActors);

			armstatsModel->Event_SetGuiInt("ammo_rifle", inventory.ammo[10]);
			armstatsModel->Event_SetGuiInt("ammo_shell", inventory.ammo[5]);
			armstatsModel->Event_SetGuiInt("ammo_autobullet", inventory.ammo[1]);

			armstatsModel->Event_SetGuiInt("defibs", defibAvailable ? 1 : 0);
			armstatsModel->Event_SetGuiParm("mushrooms", va("%d/%d", inventory.mushrooms, HEALTH_MUSHROOMMAXCOUNT));
			armstatsModel->Event_SetGuiInt("bloodbags", inventory.bloodbags);

			float secondsLeft = (airTics * 16.666666666f) / 1000.0f;
			armstatsModel->Event_SetGuiInt("oxygensec", secondsLeft);

			armstatsModel->Event_SetGuiParm("locationname", locationEntity ? locationEntity->GetLocation() : "UNKNOWN...");


			armstatsModel->Event_SetGuiInt("eliminations", eliminationCounter);


			armstatsModel->Event_SetGuiInt("coins", coins);

			armstatsModel->Event_SetGuiInt("catkeys", inventory.catkeys);


			armstatsModel->Event_SetGuiParm("shipname", gameLocal.GetShipName().c_str());
			armstatsModel->Event_SetGuiParm("shipdesc", gameLocal.GetShipDesc().c_str());
		}




		if (viewAngles.yaw < 135 && viewAngles.yaw > 45)
		{
			//Front of ship.
			armstatsModel->Event_SetGuiParm("compass", "FORWARD");
			hud->SetStateString("compass", "FORWARD");
		}
		else if (viewAngles.yaw > -135 && viewAngles.yaw < -45)
		{
			//Rear of ship.
			armstatsModel->Event_SetGuiParm("compass", "AFT");
			hud->SetStateString("compass", "AFT");
		}
		else if (viewAngles.yaw < 45 && viewAngles.yaw > -45)
		{
			armstatsModel->Event_SetGuiParm("compass", "STARBOARD");
			hud->SetStateString("compass", "STARBOARD");
		}
		else
		{
			armstatsModel->Event_SetGuiParm("compass", "PORT");
			hud->SetStateString("compass", "PORT");
		}

		armstatsModel->Event_SetGuiFloat("compassraw", -viewAngles.yaw);
		hud->SetStateFloat("compassraw", -viewAngles.yaw);
	}

	// Draw interest point HUD
	const idVec2 MIN_INTEREST_SCREEN( 290.0f, 210.0f ); //Determines how centered the interestpoint has to be to draw the label.
	const idVec2 MAX_INTEREST_SCREEN = idVec2( 640.0f, 480.0f ) - MIN_INTEREST_SCREEN;
	const idVec2 CENTER_SCREEN( 320.0f, 240.0f );
	idEntity* interestEntity = nullptr;
	float bestDist = 10000.0f;
	idVec3 viewForward = viewAngles.ToForward();
	
	//We position the label a bit to the right so the label doesn't overlap the interestpoint.
	//We do this in screenspace because the interestpoint is a 3D model. So the label offset changes depending on how close/far the player is to the interestpoint.
	idVec3 viewRight;
	viewAngles.ToVectors(NULL, &viewRight, NULL);
	const float LABEL_OFFSET = 3;
	
	for ( idEntity* entity = gameLocal.interestEntities.Next(); entity != NULL; entity = entity->interestNode.Next() )
	{
		if ( static_cast< idInterestPoint* >( entity )->isClaimed )
		{
			idVec2 screenPos = GetWorldToScreen( entity->GetPhysics()->GetOrigin() + viewRight * LABEL_OFFSET);

			if ( screenPos.x >= MIN_INTEREST_SCREEN.x && screenPos.y >= MIN_INTEREST_SCREEN.y &&
				screenPos.x <= MAX_INTEREST_SCREEN.x && screenPos.y <= MAX_INTEREST_SCREEN.y)
			{
				screenPos -= CENTER_SCREEN;
				float dist = screenPos.Length();
				if ( dist < bestDist )
				{
					if (entity->DoesPlayerHaveLOStoMe())
					{
						interestEntity = entity;
					}
				}
			}
		}
	}

	if ( interestEntity )
	{
		//Do a check to see if it's in front of player's fov
		idVec3 labelWorldPos = interestEntity->GetPhysics()->GetOrigin() + viewRight * LABEL_OFFSET;

		idVec3 dirToEnt = labelWorldPos - this->firstPersonViewOrigin;
		float facingResult = DotProduct(dirToEnt, viewAngles.ToForward());
		if (facingResult > 0)
		{
			idVec2 screenPos = GetWorldToScreen(labelWorldPos);
			hud->SetStateFloat("interestpointlabel_x", screenPos.x);
			hud->SetStateFloat("interestpointlabel_y", screenPos.y);
			idStr name = static_cast<idInterestPoint*>(interestEntity)->GetHUDName();
			hud->SetStateString("interestpointname", name.c_str());
			hud->SetStateBool("showinterestpointlabel", true);
		}
		else
		{
			//Is behind player.
			hud->SetStateBool("showinterestpointlabel", false);			
		}
	}
	else
	{
		hud->SetStateBool( "showinterestpointlabel", false );
	}
	

    /*
    //Draw the magazine pips.
	if (weapon.GetEntity())
	{
		if (weapon.GetEntity()->IsReady())
		{			
			int ammoInReserve = weapon.GetEntity()->AmmoAvailable();

			if (ammoInReserve > 0)
			{
				#define MAGWIDTH 12
				#define MAGHEIGHT 16
				#define MAG_POSY 440
				#define BG_MARGIN 8

				int startingPosX;
				int pipsToDraw;
				const char *ammoName = spawnArgs.GetString(va("def_weapon%d", currentWeapon));
				int ammoPerMag = weapon.GetEntity()->ClipSize();

				if (ammoPerMag > 0 && spawnArgs.GetBool(va("weapon%d_magdisplay", currentWeapon), "1"))
				{
					pipsToDraw = Max(ceil((float)ammoInReserve / (float)ammoPerMag), 1); //Get the amount of mags to draw. At least one. Round up for any remaining ammo.
				}
				else
				{
					pipsToDraw = ammoInReserve;
				}

				startingPosX = 615;

				renderSystem->DrawStretchPic(startingPosX - (MAGWIDTH * (pipsToDraw -1)) - BG_MARGIN, MAG_POSY - BG_MARGIN, (MAGWIDTH * pipsToDraw) + BG_MARGIN*2, MAGHEIGHT + (BG_MARGIN*2), 0, 0, 1, 1, declManager->FindMaterial("guis/assets/ammo_bg"));

				for (int i = 0; i < pipsToDraw; i++)
				{
					//draw ammo icons. right-aligned.
					renderSystem->DrawStretchPic(startingPosX, MAG_POSY, MAGWIDTH, MAGHEIGHT, 0, 0, 1, 1, declManager->FindMaterial(va("guis/assets/ammo_%s", ammoName)));
					startingPosX -= MAGWIDTH;
				}
			}
		}
	}*/



    //Kill tally. TODO: why is this called every frame.... we should make this be called less frequently.
    //if (gameLocal.time > 700)
    //{
    //    //The amount of enemies at game start.
    //    int totalEnemies = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetTotalEnemyCount();
	//
    //    int aliveEnemies = 0;
    //    for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
    //    {
    //        if (!entity || entity == this)
    //            continue;
	//
    //        if (!entity->IsType(idActor::Type))
    //            continue;
	//
    //        if (static_cast<idActor *>(entity)->team != TEAM_ENEMY)
    //            continue;
	//
    //        aliveEnemies++;
    //    }
	//
    //    if (totalEnemies > 0)
    //    {
    //        int deadEnemies = totalEnemies - aliveEnemies;
    //        if (deadEnemies > 0)
    //        {
	//			SetHudNamedEvent(va("deadenemies%d", deadEnemies));                
    //        }
    //    }
    //}

	//BC debug for ammo list.
	//for (i = 0; i < AMMO_NUMTYPES; i++)
	//{
	//	int amount = inventory.ammo[i];
	//
	//	renderSystem->DrawSmallStringExt(20, 50 + i*15, va("Ammo %d: %d", i, amount), idVec4(0, 1, 0, 1), true, declManager->FindMaterial("textures/bigchars"));
	//}

	// Draw subtitles
	if (!contextMenuActive)
	{
		gameLocal.DrawSubtitles(hud);
	}

	

	if (eventlogMenuActive)
	{
		eventlogMenu->Redraw(gameLocal.hudTime);
	}

	if (levelselectMenuActive)
	{
		levelselectMenu->Redraw(gameLocal.hudTime);
	}

	if (emailFullscreenState == EFS_ACTIVE)
	{
		emailFullscreenMenu->Redraw(gameLocal.hudTime);
	}

	DrawThrowUI();

	hud->SetStateBool("defibavailable", defibAvailable);
}

void idPlayer::DrawThrowUI()
{
	if (grenadeThrowState != GRENADETHROW_AIMING)
		return;

	idVec2 placerScreenPos;


	if (throwarcDropMode)
	{
		//drop mode. position UI to be next to drop icon.
		#define THROWDISC_RADIUS 9		
		idAngles playerViewangleNoPitch = viewAngles;
		playerViewangleNoPitch.pitch = 0;
		playerViewangleNoPitch.roll = 0;

		idVec3 drawPosition = throwdisc->GetPhysics()->GetOrigin() + (playerViewangleNoPitch.ToForward() * THROWDISC_RADIUS);
		placerScreenPos = GetWorldToScreen(drawPosition);
		placerScreenPos.x += 15;
		placerScreenPos.y -= 20;
	}
	else
	{
		#define THROWUI_WORLDDISTANCE 12

		//throw mode. position UI to top enter.
		idVec3 throwdiscUp, throwDiscForward;
		throwdisc->GetPhysics()->GetAxis().ToAngles().ToVectors(&throwDiscForward, NULL, &throwdiscUp);

		idVec2 candidatePos1 = GetWorldToScreen(throwdisc->GetPhysics()->GetOrigin() + (throwdiscUp * THROWUI_WORLDDISTANCE));
		idVec2 candidatePos2 = GetWorldToScreen(throwdisc->GetPhysics()->GetOrigin() + (throwDiscForward * THROWUI_WORLDDISTANCE));


		if (candidatePos1.y < candidatePos2.y)
			placerScreenPos = candidatePos1;
		else
			placerScreenPos = candidatePos2;

		placerScreenPos.x -= 12;
		placerScreenPos.y -= 25;
	}

	
	hud->SetStateInt("throwprompt_x", placerScreenPos.x);
	hud->SetStateInt("throwprompt_y", placerScreenPos.y);


}

// blendo eric: get position where plane and line intersect,
// couldn't find this in id libs
idVec3 LinePlaneIntersect(idVec3 & positionOnPlane, idVec3 & planeNorm, idVec3 &lineStart, idVec3& lineEnd)
{
	idVec3 lineVec = (lineEnd - lineStart).Normalized();
	float distOnLine = (planeNorm* positionOnPlane - planeNorm*lineStart) / (planeNorm* lineVec);
	return lineStart + distOnLine * lineVec;
}

//This is the UI for when pressing and holding Z to look at things in the world.
void idPlayer::DrawZoomInspect()
{
	if (!zoommodeActive || zoominspect_LabelmodeActive)
		return;

	#define ZOOMBORDER_BUFFERSIZEX 32
	#define ZOOMBORDER_BUFFERSIZEY 24
	#define ZOOMBORDER_WIDTH	1
	//Draw the border.
	renderSystem->SetColor4(1, .8f, 0, 1);

	//horizontal top/bottom
	//renderSystem->DrawStretchPic(ZOOMBORDER_BUFFERSIZEX, ZOOMBORDER_BUFFERSIZEY, 640 - ZOOMBORDER_BUFFERSIZEX * 2, ZOOMBORDER_WIDTH, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/white.tga"));
	//renderSystem->DrawStretchPic(ZOOMBORDER_BUFFERSIZEX, 480 - ZOOMBORDER_BUFFERSIZEY - 1, 640 - ZOOMBORDER_BUFFERSIZEX * 2, ZOOMBORDER_WIDTH, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/white.tga"));
	//
	////vertical left/right
	//renderSystem->DrawStretchPic(ZOOMBORDER_BUFFERSIZEX, ZOOMBORDER_BUFFERSIZEY, ZOOMBORDER_WIDTH, 480 - ZOOMBORDER_BUFFERSIZEY * 2, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/white.tga"));
	//renderSystem->DrawStretchPic(640 - ZOOMBORDER_BUFFERSIZEX - 1, ZOOMBORDER_BUFFERSIZEY, ZOOMBORDER_WIDTH, 480 - ZOOMBORDER_BUFFERSIZEY * 2, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/white.tga"));

	idVec3 forwardDir;
	idVec3 rightDir;
	idVec3 upDir;

	firstPersonViewAxis.ToAngles().ToVectors(&forwardDir, &rightDir, &upDir);

	// blendo eric: approximate border limited FOV for border frustum
	float fovXAdj = renderView->fov_x*0.5f* (1.0f - (ZOOMBORDER_BUFFERSIZEX / 640.f));
	float fovYAdj = renderView->fov_y*0.5f* (1.0f - (ZOOMBORDER_BUFFERSIZEY / 480.f));
	// note: untested accurate border fov: screenLen = sin(fov), borderLen = screenLen-borderPct*screenLen, fovAdjTrue = asin(borderLen) ???

	idQuat forwardRot = firstPersonViewAxis.ToQuat();
	
	// get frustum points for border
	// note: could be calc'd using near/far frustum construction instead of angles
	static idVec3 straight = idAngles(0, 0, 0).ToForward();
	idVec3 cornerRotR = idAngles(0, -fovXAdj, 0).ToForward();
	idVec3 cornerRotL = idAngles(0, fovXAdj, 0).ToForward();
	idVec3 cornerRotU = idAngles(-fovYAdj, 0, 0).ToForward();
	idVec3 cornerRotD = idAngles(fovYAdj, 0, 0).ToForward();

	float projectionR = (cornerRotR * straight);
	float projectionU = (cornerRotU * straight);
	cornerRotR = cornerRotR / projectionR;
	cornerRotL = cornerRotL / projectionR;
	cornerRotU = cornerRotU / projectionU;
	cornerRotD = cornerRotD / projectionU;

	// corner points
	idVec3 cornerDirUR = ((cornerRotU - straight) + (cornerRotR - straight) + straight).Normalized() * forwardRot;
	idVec3 cornerDirDR = ((cornerRotD - straight) + (cornerRotR - straight) + straight).Normalized() * forwardRot;
	idVec3 cornerDirUL = ((cornerRotU - straight) + (cornerRotL - straight) + straight).Normalized() * forwardRot;
	idVec3 cornerDirDL = ((cornerRotD - straight) + (cornerRotL - straight) + straight).Normalized() * forwardRot;

	// adjusted border plane norms
	idVec3 planeNormL = cornerDirUL.Cross(cornerDirDL);
	idVec3 planeNormR = cornerDirDR.Cross(cornerDirUR);
	idVec3 planeNormU = cornerDirUR.Cross(cornerDirUL);
	idVec3 planeNormD = cornerDirDL.Cross(cornerDirDR);

	// angle between horizontal axis and the screen corner
	float screenCornerAngle = idMath::ATan(fovYAdj/fovXAdj);

	idVec3 eyeOrig = GetEyePosition(); // firstPersonViewOrigin is sometimes zero?
	// arbitrary center point inside border frustum acting as a new screen plane
	idVec3 frustumOrigin = eyeOrig + forwardDir * 100.0f;

	//draw a POI interest marker on things in the room.
	for (idEntity* ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	{
		if (!ent)
			continue;

		if (ent->IsHidden() || !ent->spawnArgs.GetBool("zoominspect") || ent->spawnArgs.GetBool("zoominspect_brush"))
			continue;


		//get dot product. make sure it's in front of player.
		idVec3 dirToEnt = (ent->GetPhysics()->GetOrigin() - eyeOrig).Normalized();
		
		idVec3 dirToEntFlat = dirToEnt;
		dirToEntFlat.z = 0.0f;
		dirToEntFlat.Normalize();

		idVec3 forwardDirFlat = forwardDir;
		forwardDirFlat.z = 0.0f;
		forwardDirFlat.Normalize();

		float facingResult = DotProduct(dirToEnt, forwardDir);
		bool itemIsBehindPlayer = facingResult < 0.0f;
		
		idVec3 entityWorldPos = GetZoominspectAdjustedPosition(ent);
		idVec2 entScreenPosOrig = GetWorldToScreen(entityWorldPos);
		idVec2 entScreenPos = entScreenPosOrig;

		bool outSideClampView = itemIsBehindPlayer
			|| ZOOMBORDER_BUFFERSIZEX > entScreenPosOrig.x
			|| (640 - ZOOMBORDER_BUFFERSIZEX) < entScreenPosOrig.x
			|| ZOOMBORDER_BUFFERSIZEY > entScreenPosOrig.y
			|| (480 - ZOOMBORDER_BUFFERSIZEY) < entScreenPosOrig.y;

		// blendo eric:
		// we need to recalculate screen coords for the icon due to irregularities in the device to screen function
		// and also position icons at bottom of screen for entities behind the player
		if (outSideClampView)
		{
			//On the offscreen border, we only want to draw unread notes.
			if (!ent->IsType(idNoteWall::Type) && !ent->IsType(idTablet::Type))
				continue;

			if (IsReadableRead(ent))
				continue;

			// point projected on adjusted screen plane
			idVec3 localPosAdj = entityWorldPos - frustumOrigin;
			idVec3 pointPlaneProj = localPosAdj - ((localPosAdj * forwardDir) * forwardDir);

			// angle between horizontal axis and projected point
			float entCornerAngle = idMath::ACos(idMath::Fabs(rightDir * pointPlaneProj) / (pointPlaneProj.LengthFast()+0.0001f));
			bool isHorizontalBiased = entCornerAngle < screenCornerAngle;

			idVec2 projPoint;
			if (isHorizontalBiased) // use side planes
			{
				bool isRightSide = pointPlaneProj * rightDir > 0.0f;
				if (isRightSide)
				{
					idVec3 planeIntersectR = LinePlaneIntersect(eyeOrig, planeNormR, frustumOrigin, entityWorldPos);
					projPoint = GetWorldToScreen(planeIntersectR);

				}
				else // left
				{
					idVec3 planeIntersectL = LinePlaneIntersect(eyeOrig, planeNormL, frustumOrigin, entityWorldPos);
					projPoint = GetWorldToScreen(planeIntersectL);
				}
			}
			else // use top bottom planes
			{
				bool isTopSide = pointPlaneProj * upDir > 0.0f;
				if (isTopSide)
				{
					idVec3 planeIntersectU = LinePlaneIntersect(eyeOrig, planeNormU, frustumOrigin, entityWorldPos);
					projPoint = GetWorldToScreen(planeIntersectU);
				}
				else // down
				{
					idVec3 planeIntersectD = LinePlaneIntersect(eyeOrig, planeNormD, frustumOrigin, entityWorldPos);
					projPoint = GetWorldToScreen(planeIntersectD);
				}
			}
			entScreenPos.x = idMath::ClampFloat(ZOOMBORDER_BUFFERSIZEX, 640 - ZOOMBORDER_BUFFERSIZEX, projPoint.x);
			entScreenPos.y = idMath::ClampFloat(ZOOMBORDER_BUFFERSIZEY, 480 - ZOOMBORDER_BUFFERSIZEY, projPoint.y);

			// the icon position when behind player
			idVec2 entScreenPosBehind;
			{
				// just use approximation x direction, better approx would lessen discontinuity jumps
				float sideResult = idMath::ClampFloat(0.0f,1.0f,DotProduct(dirToEnt, rightDir) * 0.5f + 0.5f);
				entScreenPosBehind.x = idMath::Lerp(ZOOMBORDER_BUFFERSIZEX, 640 - ZOOMBORDER_BUFFERSIZEX, sideResult);

				// clamp to bottom of screen
				entScreenPosBehind.y = 480 - ZOOMBORDER_BUFFERSIZEY;
			}

			float facingResultFlat = DotProduct(dirToEntFlat, forwardDirFlat);
			float facingFrontInterp = idMath::ClampFloat(0.0f, 1.0f, facingResultFlat * 2.0f);
			// clamp to edge when lerping to behind view calc
			if (facingFrontInterp < 1.0f)
			{
				entScreenPos.x = (entScreenPos.x - 640*0.5f) < 0 ? ZOOMBORDER_BUFFERSIZEX : 640 - ZOOMBORDER_BUFFERSIZEX;
			}
			entScreenPos.x = facingFrontInterp <= 0.0f ? entScreenPosBehind.x : entScreenPos.x;
			entScreenPos.y = idMath::Lerp(entScreenPosBehind.y, entScreenPos.y, facingFrontInterp);
		}
		
		//traceline check.
		if (!IsZoominspectEntInLOS(ent))
		{
			ent->SetPostFlag(POST_ZOOM_INSPECT, false);
			continue;
		}
		
		ent->SetPostFlag(POST_ZOOM_INSPECT, true);

		idVec3 highlightColor;
		idVec3 markerColor;
		idStr iconName;
		if (ent->IsType(idNoteWall::Type) || ent->IsType(idTablet::Type))
		{
			//Note icon.
			iconName = "mtr_zoommarkernote";
			markerColor = idVec3(1, .8f, 0);

			bool isRead = IsReadableRead(ent);			

			if (isRead)
			{
				//already-read note.			
				highlightColor = idVec3(.2f, .2f, .2f);
			}
			else
			{
				//unread note.				
				highlightColor = idVec3(1.0f, .8f, 0);
			}
		}		
		else
		{
			//default icon.
			iconName = "mtr_zoommarkerdefault";
			markerColor = idVec3(1, .8f, 0);			
		}

		if (zoominspectEntityPtr.IsValid() && zoominspectEntityPtr.GetEntityNum() == ent->entityNumber)
		{
			markerColor = idVec3(1, .4f, 0);
			highlightColor = idVec3(1, .4f, 0);
		}


		//Draw the faint highlight circle.
		if (ent->IsType(idNoteWall::Type) || ent->IsType(idTablet::Type))
		{
			if (!IsReadableRead(ent))
			{
				#define MARKER2SIZEX 52
				#define MARKER2SIZEY 60
				renderSystem->SetColor4(highlightColor.x, highlightColor.y, highlightColor.z, 1);
				renderSystem->DrawStretchPic(entScreenPos.x - MARKER2SIZEX / 2, entScreenPos.y - MARKER2SIZEY / 2, MARKER2SIZEX, MARKER2SIZEY, 0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_zoominspect_marker2")));


				hud->DrawArbitraryText("UNREAD", .5f, idVec4(highlightColor.x, highlightColor.y, highlightColor.z, 1), entScreenPos.x + 12, entScreenPos.y - 7, "petme", idVec4(0, 0, 0, 1));
			}
		}
		
		//Draw the icon.
		#define MARKERSIZEX 14
		#define MARKERSIZEY 18
		renderSystem->SetColor4(markerColor.x, markerColor.y, markerColor.z, 1);
		renderSystem->DrawStretchPic(entScreenPos.x - MARKERSIZEX / 2, entScreenPos.y - MARKERSIZEY / 2, MARKERSIZEX, MARKERSIZEY, 0, 0, 1, 1, declManager->FindMaterial( spawnArgs.GetString(iconName) ));

		if (ent->IsType(idNoteWall::Type) || ent->IsType(idTablet::Type))
		{
			if (!IsReadableRead(ent))
			{
				//The note read notification.
				#define READNOTIF_SIZEX 12
				#define READNOTIF_SIZEY 16
				renderSystem->SetColor4(1, .8f, 0, 1);
				renderSystem->DrawStretchPic(entScreenPos.x - (MARKERSIZEX / 2) - (READNOTIF_SIZEX/3), entScreenPos.y - (MARKERSIZEY / 2) - (READNOTIF_SIZEY/2), READNOTIF_SIZEX, READNOTIF_SIZEY, 0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_readnotification")));
			}
		}		
	}


	if (!zoominspectEntityPtr.IsValid())
	{
		hud->SetStateBool("zoominspect_draw", false);
		return;
	}

	//Set hud text values.
	hud->SetStateBool("zoominspect_draw", true);
	hud->SetStateString("zoominspect_name", zoominspectEntityPtr.GetEntity()->displayName.c_str());

	
	idStr descText = (inventory.maintbooks > 0) ? zoominspectEntityPtr.GetEntity()->spawnArgs.GetString("zoominspect_hasbook") : zoominspectEntityPtr.GetEntity()->spawnArgs.GetString("zoominspect_nobook");
	hud->SetStateString("zoominspect_desc", descText.c_str());

	//Draw the selector box.
	float zoominspect_size = zoominspectEntityPtr.GetEntity()->spawnArgs.GetFloat("zoominspect_size", "24");
	if (zoominspect_size > 0)
	{
		idVec3 entityWorldPos = GetZoominspectAdjustedPosition(zoominspectEntityPtr.GetEntity());

		//position of ent.
		idVec2 entScreenPos = GetWorldToScreen(entityWorldPos);

		if (zoominspectEntityPtr.GetEntity()->spawnArgs.GetBool("zoominspect_brush"))
		{
			entScreenPos = idVec2(320, 240); //centerscreen.

			trace_t tr;
			idVec3 forwardPos = firstPersonViewOrigin + firstPersonViewAxis.ToAngles().ToForward() * 1024;
			gameLocal.clip.TracePoint(tr, firstPersonViewOrigin, forwardPos, MASK_SOLID, NULL);
			entityWorldPos = tr.endpos;
		}

		//how large sprite is.
		idVec3 viewRight, viewUp;
		viewAngles.ToVectors(NULL, &viewRight, &viewUp);
		zoominspect_size = Max(zoominspect_size, ZOOMINSPECT_MINIMUMSIZE); //it looks weird if it gets too small. Enforce a minimum size.
		idVec2 sizePos = GetWorldToScreen(entityWorldPos + (viewRight * zoominspect_size) + (viewUp * zoominspect_size));
		idVec2 spriteSize = idVec2(idMath::Fabs(sizePos.x - entScreenPos.x), idMath::Fabs(sizePos.y - entScreenPos.y));
		

		renderSystem->SetColor4(1, .2f, 0, 1);
		renderSystem->DrawStretchPic(entScreenPos.x - spriteSize.x/2, entScreenPos.y - spriteSize.y/2, spriteSize.x, spriteSize.y, 0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_zoomselectordefault")));

		//draw the arrow line.
		const idVec2 ARROWSTARTPOS = idVec2(355, 230); //this is the position of the zoominspect label, in hud.gui 'inspectTitle'. Note: add +5 to nudge it right a bit, so that the gui element hides the origin end of the arrow.		

		idVec2 arrowDir = ARROWSTARTPOS - entScreenPos;
		float arrowLength = arrowDir.Length();
		arrowDir.Normalize();
		float finalAngle = atan2(arrowDir.x, arrowDir.y)  + 1.57f;
		renderSystem->SetColor4(1, .5f, 0, 1);
		renderSystem->DrawStretchPicRotated(ARROWSTARTPOS.x - arrowLength, ARROWSTARTPOS.y, arrowLength*2, 4, 0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_zoominspect_arrow")), finalAngle);
	}
}

bool idPlayer::IsZoominspectEntInLOS(idEntity *ent)
{
	idVec3 entityWorldPos = GetZoominspectAdjustedPosition(ent);

	//Do LOS check.	

	//This is a bit of a magic number. To ensure we're not marking things through walls, we make sure we have LOS.
	//However we also need some slop room in case the object is close enough to the trace end position.
	#define ENDPOS_DISTANCETHRESHOLD 3 

	//Make the trace check respect solid surfaces but ignore glass.
	//const int MASK_ZOOMINSPECT = CONTENTS_RENDERMODEL | CONTENTS_SOLID | CONTENTS_MONSTERCLIP | CONTENTS_BODY;
	const int MASK_ZOOMINSPECT = CONTENTS_SOLID;
	const int MASK_ZOOMINSPECT_IGNORE = CONTENTS_TRANSLUCENT;

	trace_t tr;
	gameLocal.clip.TracePoint(tr, firstPersonViewOrigin, entityWorldPos, MASK_ZOOMINSPECT, this, MASK_ZOOMINSPECT_IGNORE);
	float distToEndpos = (entityWorldPos - tr.endpos).Length();

	//gameRenderWorld->DrawTextA(idStr::Format("%f", distToEndpos).c_str(), entityWorldPos, .5f, colorGreen, viewAngles.ToMat3());
	//gameRenderWorld->DebugArrow(colorGreen, firstPersonViewOrigin, tr.endpos, 4, 10000);

	if (tr.c.entityNum == ent->entityNumber || tr.fraction >= 1 || distToEndpos < ENDPOS_DISTANCETHRESHOLD)
	{
		return true;
	}
	
	return false;
}

//Diagnosticbox ingress UI.
void idPlayer::DrawIngressPoints()
{
	if (!ingresspointsDrawActive)
		return;
	
	for (idEntity *ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	{
		if (!ent)
			continue;
	
		//filter in only the ingress entities. Airlocks, windows, trash chutes.
		if (!ent->spawnArgs.GetBool("ingress_ent") || ent->IsHidden())
			continue;
	
		idVec3 adjustedIngressPos = ent->GetPhysics()->GetOrigin();
		if (ent->IsType(idBrittleFracture::Type))
		{
			//Force the ingress to be at the origin point of window.
			adjustedIngressPos = ent->spawnArgs.GetVector("origin");
		}

		idVec3 dirToEnt = adjustedIngressPos - firstPersonViewOrigin;
		dirToEnt.Normalize();
		float facingResult = DotProduct(dirToEnt, viewAngles.ToForward());
		if (facingResult < 0)
			continue;

		

		idVec3 ingressOffset = ent->spawnArgs.GetVector("ingress_offset");
		if (ingressOffset != vec3_zero)
		{
			//Offset position. Used for airlock.
			idVec3 forward, right, up;
			ent->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);
			adjustedIngressPos += (forward * ingressOffset.x) + (right * ingressOffset.y) + (up * ingressOffset.z);
		}

		bool isLocked = false;
		idVec3 iconColor = idVec3(1, .8f, 0);

		//if the entity is fusebox-locked, then change its color.
		if (IsEntityFuseboxLocked(ent))
		{
			//Locked. Make it red.
			isLocked = true;
			iconColor = idVec3(.9f, 0, 0);
		}

	
		#define ING_MARKERSIZEX 12
		#define ING_MARKERSIZEY 16
		idVec2 entScreenPos = GetWorldToScreen(adjustedIngressPos);
		renderSystem->SetColor4(iconColor.x, iconColor.y, iconColor.z, 1);
		renderSystem->DrawStretchPic(entScreenPos.x - ING_MARKERSIZEX / 2, entScreenPos.y - ING_MARKERSIZEY / 2, ING_MARKERSIZEX, ING_MARKERSIZEY,
			0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString(isLocked ? "mtr_ingress_lock" : "mtr_ingress")));

		//we only want to draw the text label if:
		//1. player is close
		//2. or, if player is looking directly at the icon
		
		//physical distance check.
		#define INGRESS_STRING_DRAWDISTANCE 20
		float dist = (ent->GetPhysics()->GetOrigin() - firstPersonViewOrigin).Length();
		dist *= DOOM_TO_METERS;

		//vieweangle check.
		#define INGRESS_2D_DISTANCETHRESHOLD 32
		float screenDist = (entScreenPos - idVec2(320, 240)).Length();
		if (dist <= INGRESS_STRING_DRAWDISTANCE || screenDist < INGRESS_2D_DISTANCETHRESHOLD)
		{
			idStr ingressStr = idStr::Format("%s [%.1fm]", ent->displayName.c_str(), dist);
			hud->DrawArbitraryText(ingressStr, .4f, idVec4(iconColor.x, iconColor.y, iconColor.z, 1), entScreenPos.x + 8, entScreenPos.y - 5, "petme", idVec4(0, 0, 0, 1));
		}
	}
}

//Return TRUE if the entity is LOCKED, and cannot be accessed. Return FALSE if entity is UNLOCKED and available to player.
bool idPlayer::IsEntityFuseboxLocked(idEntity* ent)
{
	if (ent->IsType(idAirlock::Type))
	{
		if (static_cast<idAirlock*>(ent)->IsFuseboxgateShut())
			return true;
	}
	else if (ent->IsType(idBrittleFracture::Type))
	{
		if (ent->health >= ent->maxHealth) //if window has full health, it's inaccesible.
			return true;
	}
	else if (ent->IsType(idTrashExit::Type))
	{
		if (static_cast<idTrashExit*>(ent)->IsFuseboxTrashgateShut())
			return true;
	}

	return false;
}


void idPlayer::DrawSpectatorHUD()
{
	//hide all the spectator ui stuff if player is in the pausemenu
	if (g_hideHudInternal.GetBool())
		return;

	UpdateSpectatenodes();

	spectatorMenu->Redraw(gameLocal.hudTime); //draw the spectator fullscreen gui.

	if (eventlogMenuActive)
	{
		eventlogMenu->Redraw(gameLocal.hudTime);
	}
}

void idPlayer::UpdateSpectatenodes()
{
	if (!spectating || spectateTimelineEnt == NULL)
		return;

	spectateTimelineEnt->Think();
}

//BC
void idPlayer::DrawSuspicionArrows()
{
	if (health <= 0)
		return;

	idVec3 noisePosition = vec3_zero;

	for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	{
		if (!entity->IsActive() || entity->IsHidden() || entity == this || entity->health <= 0 || entity->team != TEAM_ENEMY)
			continue;

		//Do not target friendlies.
		if (!entity->IsType(idAI::Type))
			continue;

        //Only do suspicious UI if an enemy is suspicious of player. Otherwise, ignore.
        bool isLookingAtPlayer = false;
		bool drawSightedFanfare = false;
		bool shouldDrawSuspicionPip = false;
		int currentSuspicion = 0;

		//See if this entity is valid to draw suspicion stuff for.
        if (entity->IsType(idGunnerMonster::Type))
        {
            if (static_cast<idGunnerMonster *>(entity)->lastEnemySeen.IsValid())
            {
                if (static_cast<idGunnerMonster *>(entity)->lastEnemySeen.GetEntity() == this)
                {
					if (static_cast<idGunnerMonster *>(entity)->CanAcceptStimulus())
					{
						isLookingAtPlayer = true;

						if (static_cast<idGunnerMonster *>(entity)->GetSightedFlashTime())
						{
							drawSightedFanfare = true;
						}						
					}
                }
            }

			currentSuspicion = static_cast<idGunnerMonster *>(entity)->GetSuspicionCounter();
			if (currentSuspicion > 0)
			{
				shouldDrawSuspicionPip = true;
			}

            //BC attempt fix: don't draw suspicion ui if enemy is being jockeyed.
            if (static_cast<idGunnerMonster *>(entity)->aiState == AISTATE_JOCKEYED)
            {
                continue;
            }
        }


        if ((/*!static_cast<idAI*>(entity)->lastFovCheck || */static_cast<idAI*>(entity)->combatState > 0) && !drawSightedFanfare)
        {
            continue;
        }
        else if ((isLookingAtPlayer || drawSightedFanfare || shouldDrawSuspicionPip) && currentSuspicion > 0)
		{
			//We now have a valid enemy actor who sees enemy.

			idVec3 suspicionPosition, myPosition, viewForward, angleToTarget;
			idVec2 drawPosition;
			float finalAngle;

			if (isLookingAtPlayer)
				noisePosition = entity->GetPhysics()->GetOrigin();

			suspicionPosition = entity->GetPhysics()->GetOrigin();
			suspicionPosition.z = 0;

			myPosition = this->GetPhysics()->GetOrigin();
			myPosition.z = 0;

			viewForward = viewAngles.ToForward();
			viewForward.Normalize();

			angleToTarget = suspicionPosition - myPosition;
			angleToTarget.Normalize();

			finalAngle = atan2(angleToTarget.x, angleToTarget.y) * -1.0f; //Player position.
			finalAngle -= DEG2RAD(viewAngles.yaw - 90);  //Player yaw.

			drawPosition = idVec2(320 - (SUSPICIONARROW_SIZE / 2), 240 - (SUSPICIONARROW_SIZE / 2));

			drawPosition.x += cos(finalAngle + 1.57f) * SUSPICIONARROW_DIST;
			drawPosition.y += sin(finalAngle - 1.57f) * SUSPICIONARROW_DIST;


			if (drawSightedFanfare)
			{
				//The AI has sighted (entered combat state) the player. Do the shaking/jitter effect, and then exit here.
				renderSystem->SetColor4(1, 0, 0, 1);
				renderSystem->DrawStretchPicRotated(drawPosition.x, drawPosition.y, SUSPICIONARROW_SIZE, SUSPICIONARROW_SIZE, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/sighted_arc"), finalAngle);
				continue;
			}
			
			//Enemy is suspicious.....


			//draw the suspicion crescent shape
			if (isLookingAtPlayer)
			{
				renderSystem->SetColor4(1, 1, 1, 1);
				renderSystem->DrawStretchPicRotated(drawPosition.x, drawPosition.y, SUSPICIONARROW_SIZE, SUSPICIONARROW_SIZE, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/suspicion_arc"), finalAngle);
			}

			if (entity->IsType(idGunnerMonster::Type))
			{
				//the suspicion circle. Fills up, shows suspicion grow rate.
				const int SUSPICIONCIRCLE_SIZE_X = 12;
				const int SUSPICIONCIRCLE_SIZE_Y = 16;
				idVec2 circlePosition = idVec2(320 - (SUSPICIONCIRCLE_SIZE_X / 2), 240 - (SUSPICIONCIRCLE_SIZE_Y / 2));
				circlePosition.x += cos(finalAngle + 1.57f) * SUSPICIONARROW_DIST;
				circlePosition.y += sin(finalAngle - 1.57f) * SUSPICIONARROW_DIST;
				//Draw circle background.
				renderSystem->SetColor(idVec4(.5f, .5f, .5f, 1));
				renderSystem->DrawStretchPic(circlePosition.x, circlePosition.y, SUSPICIONCIRCLE_SIZE_X, SUSPICIONCIRCLE_SIZE_Y, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/suspicion_circle_bg"));

				//Get info for the circle innards.				
				float circleLerpValue = currentSuspicion / (float)static_cast<idGunnerMonster *>(entity)->GetSuspicionMaxValue();

				//The shader effect uses special values to make the empty/full circle look right
				#define CIRCLE_FILLED -.1f
				#define CIRCLE_EMPTY -.75f
				float displayLerpValue = idMath::Lerp(CIRCLE_EMPTY, CIRCLE_FILLED, circleLerpValue);

				//Draw circle foreground.
				if (isLookingAtPlayer)
					renderSystem->SetColor(idVec4(1, 1, 1, displayLerpValue));
				else
					renderSystem->SetColor(idVec4(.5f, .5f, .5f, displayLerpValue));

				renderSystem->DrawStretchPic(circlePosition.x, circlePosition.y, SUSPICIONCIRCLE_SIZE_X, SUSPICIONCIRCLE_SIZE_Y, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/suspicion_circle_fg"));
			}
		}
	}

	if (noisePosition == vec3_zero && playingSuspicionSound)
	{
		//Stop playing sizzle noise.
		playingSuspicionSound = false;
		static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->StopSound(SND_CHANNEL_BODY3, 0);		
	}
	else if (noisePosition != vec3_zero && !playingSuspicionSound)
	{
		//Start playing sizzle noise.
		playingSuspicionSound = true;
		static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetPhysics()->SetOrigin(noisePosition);
		static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->StartSound("snd_suspicionloop", SND_CHANNEL_BODY3, 0, false, NULL);
	}
}

//Enemy health bar visibility is set in the player.cpp UpdateFocus() function (via ShowHealthbar()).
void idPlayer::DrawEnemyHealth()
{
	

	if (GetFocusedGUI() != NULL)
	{
		//If player is looking at a gui, don't draw healthbars.
		return;
	}

	if (zoominspect_LabelmodeActive || iteminspectActive || armstatsActive) //if inspecting something, then skip.
		return;

	for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	{
		idVec2 spriteScreenPos;
		idBounds enemyBounds;
		int _maxhealth;
		float barwidth;

		float facingResult;
		idVec3 dirToEnemy;
		idVec2 nametagPos;

		if (!entity->IsActive() || entity->IsHidden() || entity == this)
		{
			continue;
		}

		if (entity->team != TEAM_ENEMY || entity->health <= 0)
			continue;
		
		if (entity->healthbarDisplaytime <= gameLocal.time && entity->cameraiconDisplaytime <= gameLocal.time)
			continue;

		//If player has LOS to an active healthbar, re-fresh the healthbar's timer. This is so that once a player sees someone, the healthbar remains active as long as a wall doesn't divide them.
		if (!noclip)
		{
			trace_t updateTr;
			gameLocal.clip.TracePoint(updateTr, firstPersonViewOrigin, entity->GetPhysics()->GetOrigin() + idVec3(0, 0, 4), MASK_SOLID, NULL);
			if (updateTr.fraction >= 1)
			{
				entity->ShowHealthbar();
			}
		}

		// We compare against the view origin rather than the player's location so that this doesn't get funky around ventpeeks/cryopeeks
		dirToEnemy = entity->GetPhysics()->GetOrigin() - this->firstPersonViewOrigin;
		facingResult = DotProduct(dirToEnemy, viewAngles.ToForward() );
		if (facingResult <= 0)
			continue; //If enemy is behind me, then exit here.
		
		#define	HEALTHBAR_PIPAMOUNT 1

		_maxhealth = entity->maxHealth;
		//barAmount = entity->health / (float)_maxhealth;

		barwidth = (_maxhealth * float(ENEMYHEALTHBAR_PIPWIDTH + ENEMYHEALTHBAR_GAPSIZE)) + ENEMYHEALTHBAR_GAPSIZE;

		enemyBounds = entity->GetPhysics()->GetBounds();
		idVec3 spriteWorldPosition = entity->GetPhysics()->GetOrigin() + idVec3(0, 0, enemyBounds[1].z + ENEMYHEALTHBAR_HEIGHTOFFSET);

		//have an enemy. Draw the bar background.		
		spriteScreenPos = GetWorldToScreen(spriteWorldPosition);

		renderSystem->DrawStretchPic(spriteScreenPos.x - (barwidth / 2) - .5f, spriteScreenPos.y - .5f - ENEMYHEALTHBAR_HEIGHT,
			barwidth+1, ENEMYHEALTHBAR_HEIGHT+1,
			0, 0, 1, 1, declManager->FindMaterial("enemyhealthbar_outline")); //Outline.
		renderSystem->DrawStretchPic(spriteScreenPos.x - barwidth/2, spriteScreenPos.y - ENEMYHEALTHBAR_HEIGHT,
			barwidth, ENEMYHEALTHBAR_HEIGHT,
			0, 0, 1, 1, declManager->FindMaterial("enemyhealthbar_bg")); //Dark background.
		
		//draw the health pips.
		for (int i = 0; i < _maxhealth; i++)
		{
			float startingX = i * float(ENEMYHEALTHBAR_PIPWIDTH + ENEMYHEALTHBAR_GAPSIZE);
		
			const char *materialName;
		
			if (i <= entity->health - 1)
			{
				materialName = "enemyhealthbar";
			}
			else if (entity->lastHealthTimer > gameLocal.time)
			{
				//there might be some pips that display the amount of damage last taken.
		
				if (i <= entity->lastHealth - 1)
				{
					//Draw a red pip for the damage most recently-taken. This is to make it easier to read how much damage was recently inflicted.
					materialName = "enemyhealthbar_damagepip"; //red pip.
				}
				else
				{
					materialName = "enemyhealthbar_emptypip"; //empty pip.
				}
			}
			else
			{
				materialName = "enemyhealthbar_emptypip"; //empty pip.
			}
		
			renderSystem->DrawStretchPic(
				spriteScreenPos.x - (barwidth / 2.0f) + startingX + ENEMYHEALTHBAR_GAPSIZE,
				spriteScreenPos.y - ENEMYHEALTHBAR_HEIGHT + (ENEMYHEALTHBAR_GAPSIZE * 1.15f),
				ENEMYHEALTHBAR_PIPWIDTH,
				ENEMYHEALTHBAR_HEIGHT - (ENEMYHEALTHBAR_GAPSIZE*2.0f),
				0, 0, 1, 1, declManager->FindMaterial(materialName)); //Innards.
		}
		
		nametagPos = idVec2(spriteScreenPos.x - (barwidth / 2.0f) - 1.0f, spriteScreenPos.y - ENEMYHEALTHBAR_HEIGHT - 12);
		uiManager->SetSize( VIRTUAL_WIDTH, VIRTUAL_HEIGHT );
		hud->DrawArbitraryText(entity->spawnArgs.GetString("displayname", "TOPAZ"), .4f, idVec4(1, 1, 1, 1), nametagPos.x, nametagPos.y, "fonts", idVec4(0,0,0,.3f));
		
		//draw numeric health amount.
		hud->DrawArbitraryText(va("%d",entity->health), .4f, idVec4(0, .9f, 0, 1), spriteScreenPos.x + (barwidth / 2.0f) + 2, spriteScreenPos.y - ENEMYHEALTHBAR_HEIGHT - 3, "fonts", idVec4(0, 0, 0, 1));


		//Draw the vertical dividing lines on the healthbar.
		//healthPipAmount = _maxhealth / HEALTHBAR_PIPAMOUNT; //Draw a vertical line per every XX amount of health.
		//if (healthPipAmount >= 2)
		//{
		//	int pipWidth = barwidth / healthPipAmount;
		//
		//	for (int i = 0; i < healthPipAmount - 1; i++)
		//	{
		//		renderSystem->DrawStretchPic(spriteScreenPos.x - (barwidth / 2) + (pipWidth*(i+1)), spriteScreenPos.y - (ENEMYHEALTHBAR_HEIGHT / 2), .7f, ENEMYHEALTHBAR_HEIGHT, 0, 0, 1, 1, declManager->FindMaterial("enemyhealthbar_bg"));
		//	}
		//}

		//Draw camera icon.
		if (entity->cameraiconDisplaytime > gameLocal.time)
		{
			#define CAMERAICON_SIZE 16
			#define	CAMERAICON_SIZEOFFSET 4
			renderSystem->DrawStretchPic(
				nametagPos.x - CAMERAICON_SIZE + CAMERAICON_SIZEOFFSET - 2,
				nametagPos.y,
				CAMERAICON_SIZE - CAMERAICON_SIZEOFFSET, //to make the shape more square-ish we squeeze the width
				CAMERAICON_SIZE,
				0, 0, 1, 1, declManager->FindMaterial("guis/assets/icon_camera"));
			entity->SetPostFlag(POST_OUTLINE_ENEMY, true);
			entity->DynamicUpdateDrawGlobally(true);
		}
		else
		{
			entity->SetPostFlag(POST_OUTLINE_ENEMY, false);
			entity->DynamicUpdateDrawGlobally(false);
		}

		//Draw point defense robot info.
		if (entity->IsType(idActor::Type))
		{
			int amountOfPointdefenseAmountLeft = static_cast<idActor*>(entity)->pointdefenseAmount;

			if (amountOfPointdefenseAmountLeft > 0)
			{
				//draw the shield icon.
				idVec2 shieldIconPos = idVec2(spriteScreenPos.x + (barwidth / 2) + 16, spriteScreenPos.y - SHIELD_SIZE_Y);
				renderSystem->DrawStretchPic(shieldIconPos.x,shieldIconPos.y,
					SHIELD_SIZE_X, SHIELD_SIZE_Y, 0, 0, 1, 1, declManager->FindMaterial("shield_filled"));

				hud->DrawArbitraryText(va("%d", amountOfPointdefenseAmountLeft), .4f, idVec4(1, 0, 1, 1), shieldIconPos.x + SHIELD_SIZE_X, shieldIconPos.y - 2, "fonts", idVec4(0, 0, 0, 1));
			}
		}


		//Draw the stun bar.
		if (entity->IsType(idAI::Type))
		{			
			if (static_cast<idAI*>(entity)->aiState == AISTATE_STUNNED)
			{
				float stunLerp = (gameLocal.time - static_cast<idActor*>(entity)->stunStartTime) / (float)static_cast<idActor*>(entity)->stunTime;
				stunLerp = idMath::ClampFloat(0, 1, 1 - stunLerp);

				//common->Printf("stun %f\n", stunLerp);

				#define STUNBAR_HEIGHT 6
				#define STUBAR_YOFFSET -21

				renderSystem->DrawStretchPic(spriteScreenPos.x - (barwidth / 2) - .5f, spriteScreenPos.y - .5f - STUNBAR_HEIGHT + STUBAR_YOFFSET,
					barwidth + 1, STUNBAR_HEIGHT + 1,
					0, 0, 1, 1, declManager->FindMaterial("stunbar")); //Outline.

				renderSystem->DrawStretchPic(spriteScreenPos.x - (barwidth / 2), spriteScreenPos.y - STUNBAR_HEIGHT + STUBAR_YOFFSET,
					barwidth, STUNBAR_HEIGHT,
					0, 0, 1, 1, declManager->FindMaterial("enemyhealthbar_bg")); //Dark background.

				renderSystem->DrawStretchPic(
					spriteScreenPos.x - (barwidth / 2) + .5f,
					spriteScreenPos.y - STUNBAR_HEIGHT + .5f + STUBAR_YOFFSET,
					stunLerp  * (barwidth - 1),
					STUNBAR_HEIGHT - 1,
					0, 0, 1, 1, declManager->FindMaterial("stunbar")); //Innards.

				float stunFontSize = .5f + (idMath::Cos(gameLocal.time * .02f) * .02f);
				hud->DrawArbitraryText("STUNNED", stunFontSize, idVec4(0, 0, 0, 1),
					spriteScreenPos.x - (barwidth / 2) - .5f,
					spriteScreenPos.y - .5f - STUNBAR_HEIGHT + STUBAR_YOFFSET - 16,
					"fonts", idVec4(0, 0, 0, 0), 0, 0, idVec4(1, .8f, 0, 1));
			}
		}

		

		//Draw the shield icons. This is for the energy shield.
		if (entity->IsType(idActor::Type))
		{
			if (!static_cast<idActor*>(entity)->GetEnergyshieldActive())
				continue;

			int shieldMax = static_cast<idActor*>(entity)->energyShieldMax;
			if (shieldMax > 0)
			{
				int shieldCurrent = static_cast<idActor*>(entity)->energyShieldCurrent;
				for (int i = 0; i < shieldMax; i++)
				{
					renderSystem->DrawStretchPic(spriteScreenPos.x + (barwidth / 2) + 2 + (i * SHIELD_SIZE), spriteScreenPos.y - SHIELD_SIZE,
						SHIELD_SIZE, SHIELD_SIZE, 0, 0, 1, 1, (shieldCurrent - 1) >= i ? declManager->FindMaterial("shield_filled") : declManager->FindMaterial("shield_empty"));
				}
			}
		}





		
	}
}

//Draw frob UI.
void idPlayer::DrawFrobHUD(int time)
{
	idVec2 spriteScreenPos;
	float fingerWidth, fingerHeight, textOffsetX;
	idVec3 cursorOffset;
	int displaynameLength;
	idStr frobkey;

	if (frobFlashTimer > time)
	{
		//do the poplerp animation.
		float lerp = (frobFlashTimer - time) / (float)FROB_FLASHTIME;
		lerp = 1.0f - lerp;

		fingerWidth = idMath::PopLerp(1, 40, 24, lerp);
		fingerHeight = idMath::PopLerp(1, 72, 64, lerp);
		textOffsetX = idMath::PopLerp(-17, 4, 0, lerp);
	}
	else
	{
		//draw normal finger.
		fingerWidth = 24;
		fingerHeight = 64;
		textOffsetX = 0;
	}

	idVec3 additionalOffset = vec3_zero;
	cursorOffset = frobEnt->spawnArgs.GetVector("cursoroffset", "0 0 0"); //X = forward/back Y = left/right   Z = up

	int frobdooroffset = frobEnt->spawnArgs.GetInt("frobdooroffset", "0");
	if (frobdooroffset > 0)
	{
		//OFFSET THE FINGER ICON SO IT IS RIGHT ON THE BUTTON.
		idAngles doormoveAng;
		float doormovedir;
		

		if (frobEnt->spawnArgs.GetInt("autodir", "0") == 1)
		{
			//Autodir. Do some math.
			doormovedir = frobEnt->GetPhysics()->GetAxis().ToAngles().yaw - 90;
		}
		else
		{
			//Manual movedir.
			doormovedir = frobEnt->spawnArgs.GetFloat("movedir");
		}

		bool doDoorOpenOffset = false;
		if (frobEnt->IsType(idDoor::Type))
		{
			idDoor *door = static_cast<idDoor *>(frobEnt);
			if (door->IsOpen())
			{
				//DOOR IS OPENING. THEN LOCK THE CURSOR TO EDGE OF DOOR.
				doormoveAng = idAngles(0, doormovedir, 0);
				additionalOffset = doormoveAng.ToForward() * frobEnt->spawnArgs.GetInt("cursoroffset_open", "-32");
				doDoorOpenOffset = true;
			}
		}
		
		if (!doDoorOpenOffset)
		{
			//IF DOOR IS CLOSED THEN LOCK THE CURSOR ONTO THE BUTTON.
			//float angDiff;
			//doormovedir += 90;
			//idVec3 frontOfMachinePos = frobEnt->GetPhysics()->GetOrigin();
			//idVec3 toPlayer = frontOfMachinePos - idVec3(gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin().x, gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin().y, frontOfMachinePos.z);
			//toPlayer.Normalize();
			//idVec3 machineFacing = frobEnt->GetPhysics()->GetAxis().ToAngles().ToForward();
			//float facingResult = DotProduct(toPlayer, machineFacing);
			//if (facingResult > 0)
			//{
			//	doormovedir += 180;
			//}
			//doormoveAng = idAngles(0, doormovedir, 0);
			//additionalOffset = doormoveAng.ToForward() * frobdooroffset;


			//figure out which side is closest to player.
			idVec3 doorForward;
			frobEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(&doorForward, NULL, NULL);

			idVec3 candidateOffset1 = doorForward * frobdooroffset;
			idVec3 candidateOffset2 = doorForward * -frobdooroffset;

			if (((frobEnt->GetPhysics()->GetOrigin() + candidateOffset1) - GetPhysics()->GetOrigin()).LengthFast() < ((frobEnt->GetPhysics()->GetOrigin() + candidateOffset2) - GetPhysics()->GetOrigin()).LengthFast())
			{
				additionalOffset = candidateOffset1;
			}
			else
			{
				additionalOffset = candidateOffset2;
			}
		}
		
	}
	else if (frobEnt->spawnArgs.GetBool("frobcable", "0"))
	{
		cursorOffset.z = frobHitpos.z - frobEnt->GetPhysics()->GetOrigin().z;
	}
	else if (frobEnt->spawnArgs.GetBool("frobcable_space", "0"))
	{
		//This handles positioning the frob cursor for the elevatorcable (zipline) in outer space.


		idVec3 lineStartPos = frobEnt->GetPhysics()->GetOrigin();		

		float triggerLength = frobEnt->GetPhysics()->GetBounds()[1].z;
		idVec3 triggerUpDir;
		frobEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(NULL, NULL, &triggerUpDir);
		idVec3 lineEndPos = frobEnt->GetPhysics()->GetOrigin() + (triggerUpDir * triggerLength);		

		idVec3 closetPointOnLine = GetClosestPointOnLine(frobHitpos, lineStartPos, lineEndPos);
		additionalOffset = closetPointOnLine - frobEnt->GetPhysics()->GetOrigin();
	}



	//else if (cursorOffset != vec3_zero)
	//{
	//	//Offset the frob cursor. X = forward/back Y = left/right   Z = up
	//	idVec3 frobForward, frobRight, frobUp;		
	//	frobEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(&frobForward, &frobRight, &frobUp);
	//	cursorOffset = (frobForward * cursorOffset.x) + (frobRight * cursorOffset.y) + (frobUp * cursorOffset.z);
	//}

	//Final screen position of the frob cursor. Convert world coordinates to screen coordinates.

	idVec3 modelForward, modelRight, modelUp;
	frobEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(&modelForward, &modelRight, &modelUp);
	spriteScreenPos = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + (modelForward * cursorOffset.x) + (modelRight * cursorOffset.y) + (modelUp * cursorOffset.z) + additionalOffset);

	if (frobEnt->spawnArgs.GetBool("frobcable", "0") && frobHitpos.z == 0)
	{
		//When player is inside a frobbable entity (i.e. zipcord) just lock the UI to center screen. This special case (inside frobbbable) gets activated when we set frobhitpos to 0
		spriteScreenPos.y = 240;
	}
	
	//Get frob item displayname.
	displaynameLength = frobEnt->displayName.Length();

	
	#define SCREEN_RIGHT_THRESHOLD 610
	#define SCREEN_BOTTOM_THRESHOLD 458

	//Clamp frobcursor screen position to edge of screen.
	if (spriteScreenPos.x < 5)
		spriteScreenPos.x = 5;
	else if (spriteScreenPos.x > SCREEN_RIGHT_THRESHOLD  && !frobEnt->spawnArgs.GetBool("frobtextoffset", "0"))
		spriteScreenPos.x = SCREEN_RIGHT_THRESHOLD ;

	if (spriteScreenPos.y < 0)
		spriteScreenPos.y = 0;
	else if (spriteScreenPos.y > SCREEN_BOTTOM_THRESHOLD)
		spriteScreenPos.y = SCREEN_BOTTOM_THRESHOLD;


    idVec2 promptPos = spriteScreenPos;



	//if we want to adjust the frobprompt ui to NOT block the object with text.
	if (frobEnt->spawnArgs.GetBool("frobtextoffset","0"))
	{
		idVec3 forward, right, up;
		idVec2 screenCoords;
		idBounds bounds;
		float rightmostPoint = 0;


		//Figure out the right-most point.
		frobEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);		
		bounds = frobEnt->GetPhysics()->GetBounds();

		screenCoords = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + forward * bounds[0][0]);

		if (screenCoords.x > rightmostPoint)
			rightmostPoint = screenCoords.x;

		screenCoords = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + forward * bounds[1][0]);

		if (screenCoords.x > rightmostPoint)
			rightmostPoint = screenCoords.x;

		screenCoords = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + right * bounds[0][1]);

		if (screenCoords.x > rightmostPoint)
			rightmostPoint = screenCoords.x;

		screenCoords = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + right * bounds[1][1]);

		if (screenCoords.x > rightmostPoint)
			rightmostPoint = screenCoords.x;

		screenCoords = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + up * bounds[0][2]);

		if (screenCoords.x > rightmostPoint)
			rightmostPoint = screenCoords.x;

		screenCoords = GetWorldToScreen(frobEnt->GetPhysics()->GetOrigin() + up * bounds[1][2]);

		if (screenCoords.x > rightmostPoint)
			rightmostPoint = screenCoords.x;

        promptPos.x = Max(rightmostPoint, spriteScreenPos.x + 10);

		//If prompt gets pushed off screen right, then clamp its position.
		if (promptPos.x > SCREEN_RIGHT_THRESHOLD)
		{
			promptPos.x = Max(spriteScreenPos.x + 10, (float)SCREEN_RIGHT_THRESHOLD);
		}
	}
	else
	{
        promptPos.x += 10;
	}


	

	bool drawProhibitMarker = false;
	//Determine whether the frob text should say SWAP or PICK UP.
	int cursorType = CURSOR_FROB;
	//if (frobEnt->spawnArgs.GetBool("carryable"))
	//{
	//	//Teapot, pepperbag, etc.
	//	hud->SetStateString("frob_swaptext", "");
	//	cursorType = CURSOR_CARRY;
	//}
	//else if (frobEnt->IsType(idMover_Binary::Type))
	//{
	//	//doors.
	//	hud->SetStateString("frob_swaptext", "open");
	//}
	if (frobEnt->spawnArgs.GetInt("inv_carry") > 0)
	{
		//For things teh player can always get more of: armor, security cards, etc
		hud->SetStateString("frob_swaptext", ""); //empty swap text.			
		cursorType = CURSOR_ADDMORE; //"add more" icon.
	}
	else if (frobEnt->spawnArgs.GetBool("isweapon") || frobEnt->spawnArgs.GetBool("carryable") || frobEnt->spawnArgs.GetBool("canpickup"))
	{
		//This item is sometimes swappable, sometimes pickuppable.

		//Figure out whether to show swap icon or default icon.
		int frobitemWeaponIndex = inventory.GetWeaponIndex(this, frobEnt->spawnArgs.GetBool("isweapon") ? frobEnt->spawnArgs.GetString("inv_weapon") : frobEnt->spawnArgs.GetString("weapon"));
		bool isAlreadyEquipped = inventory.GetHotbarslotViaWeaponIndex(frobitemWeaponIndex) >= 0;
		const idDeclEntityDef *weaponDef = gameLocal.FindEntityDef( spawnArgs.GetString( va( "def_weapon%d", frobitemWeaponIndex ) ), false );
		if ( isAlreadyEquipped && !weaponDef->dict.GetBool( "multiCarry" ) )
		{
			//player already has this weapon.
			hud->SetStateString("frob_swaptext", ""); //empty swap text.			
			cursorType = CURSOR_ADDMORE; //"add more" icon.

			//See if player CAN carry more of this item. Example: the player can pick up rifles to get extra rifle ammo.
			//If not, then draw a big red X on it.
			int ammoRequired  = 0;
			ammo_t ammo_i = inventory.AmmoIndexForWeaponClass(spawnArgs.GetString(va("def_weapon%d", frobitemWeaponIndex)), &ammoRequired);
			if (ammoRequired > 0)
			{
				//requires ammo. do ammo check.
				int currentAmmo = inventory.ammo[ammo_i];			
				const char *ammoName = idWeapon::GetAmmoNameForNum(ammo_i);
				int maxAmmo = inventory.MaxAmmoForAmmoClass(this, ammoName);
				
				if (currentAmmo >= maxAmmo)
				{
					drawProhibitMarker = true; //Player has maxed out ammo. Draw prohibit marker.
				}
			}
			else
			{
				//this is kinda a kludge... if no no ammo required, then it means the player can only carry one of it.
				drawProhibitMarker = true;
			}
		}
		else
		{
			//it might be an ammo pickup. Check if so.
			const idKeyValue * keyval = frobEnt->spawnArgs.MatchPrefix("inv_ammo_");
			if (keyval && !frobEnt->spawnArgs.GetBool("isweapon"))
			{
				cursorType = CURSOR_ADDMORE; //"add more" icon.

				idStr keyName = keyval->GetKey();
				keyName = keyName.Right(keyName.Length() - 9);

				ammo_t ammo_i = inventory.AmmoIndexForAmmoClass(va("ammo_%s", keyName.c_str()));
				int currentAmmo = inventory.ammo[ammo_i];				
				
				int maxAmmo = inventory.MaxAmmoForAmmoClass(this, va("ammo_%s", keyName.c_str()));

				if (currentAmmo >= maxAmmo)
				{
					drawProhibitMarker = true;
				}
			}
			else
			{

				bool hasFreeSlot = inventory.GetEmptyHotbarSlot() >= 0;
				if (hasFreeSlot)
				{
					//If player has available hotbar slot, then do default cursor.
					hud->SetStateString("frob_swaptext", "");
				}
				else
				{
					//TODO: don't draw this if the frobEnt dotproduct is behind player viewangle.


					hud->SetStateString("frob_swaptext", "swap");
					cursorType = CURSOR_SWAP;


					//Swap line. This draws a line to the hotbar slot that will be replaced.

					//Draw vertical line.
					const int SWAPLINEWIDTH = 2;
					renderSystem->SetColor4(1, 1, 1, .8f);
					idVec2 swapStartPos = idVec2(promptPos.x + 8, promptPos.y + 20);
										
					
					//Find XY of the hotbar button we want to connect to. Make sure this retains parity with the values in hud.gui
					const int HOTBAR_POSX = (510) - 2; //nudge it left a bit so that it has a small gap
					const int HOTBAR_POSY_OFFSET = 8;
					idVec2 hotbarslotPos;
					switch (inventory.GetHotbarSelection())
					{
						case 0:
							hotbarslotPos = idVec2(HOTBAR_POSX, 340 + HOTBAR_POSY_OFFSET);
							break;
						case 1:
							hotbarslotPos = idVec2(HOTBAR_POSX, 360 + HOTBAR_POSY_OFFSET);
							break;
						case 2:
							hotbarslotPos = idVec2(HOTBAR_POSX, 380 + HOTBAR_POSY_OFFSET);
							break;
						case 3:
							hotbarslotPos = idVec2(HOTBAR_POSX, 400 + HOTBAR_POSY_OFFSET);
							break;
						default:
							hotbarslotPos = idVec2(HOTBAR_POSX, 420 + HOTBAR_POSY_OFFSET);
							break;
					}

					//Vertical line.
					renderSystem->DrawStretchPic(swapStartPos.x, swapStartPos.y, SWAPLINEWIDTH, hotbarslotPos.y - swapStartPos.y, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/swapline_vert"));

					//Horizontal line.
					renderSystem->DrawStretchPic(swapStartPos.x, hotbarslotPos.y, hotbarslotPos.x - swapStartPos.x, SWAPLINEWIDTH, 0, 0, 1, 1, declManager->FindMaterial("guis/assets/swapline_horz"));
					



				}
			}
			
		}
	}
	//else if (frobEnt->spawnArgs.GetBool("canpickup"))
	//{
	//	//Probably ammo.
	//	hud->SetStateString("frob_swaptext", "pick up");
	//}
	//else
	//{
	//	//Just make it empty.
	//	hud->SetStateString("frob_swaptext", "use");
	//}
	else
	{
		//Just make it empty.
		hud->SetStateString("frob_swaptext", "");
	}


	


    //Draw finger.
	//cursorType 0 = default frob finger. 1 = swap icon. 2 = carry icon.
	switch (cursorType)
	{
		case CURSOR_SWAP:
			renderSystem->DrawStretchPic(
				spriteScreenPos.x - (24 / 2.0f),
				spriteScreenPos.y - (30 / 2.0f) + 10,
				24, 30,
				0, 0, 1, 1, declManager->FindMaterial("guis/assets/swapicon"));
				hud->SetStateBool("swaptext_visible", true);
			break;
		case CURSOR_ADDMORE:
			renderSystem->DrawStretchPic(
				spriteScreenPos.x - (18 / 2.0f),
				spriteScreenPos.y - (22 / 2.0f) + 10,
				18, 22,
				0, 0, 1, 1, declManager->FindMaterial("guis/assets/addmoreicon"));
			hud->SetStateBool("swaptext_visible", false);
			break;
		case CURSOR_CARRY:
			renderSystem->DrawStretchPic(
				spriteScreenPos.x - (fingerWidth / 2.0f),
				spriteScreenPos.y - (fingerHeight / 2.0f),
				fingerWidth, fingerHeight,
				0, 0, 1, 1, declManager->FindMaterial("guis/assets/crosshaircarry"));
				hud->SetStateBool("swaptext_visible", true);
			break;
		case CURSOR_FROB:
		default:
			renderSystem->DrawStretchPic(
				spriteScreenPos.x - (fingerWidth / 2.0f),
				spriteScreenPos.y - (fingerHeight / 2.0f),
				fingerWidth, fingerHeight,
				0, 0, 1, 1, declManager->FindMaterial("guis/assets/crosshairfinger"));
				hud->SetStateBool("swaptext_visible", false);
			break;
	}
	
	if (drawProhibitMarker)
	{
		renderSystem->SetColor4(0, 0, 0, .8f);
		renderSystem->DrawStretchPic(
			spriteScreenPos.x - (22 / 2.0f),
			spriteScreenPos.y - (27 / 2.0f) + 10,
			22, 27,
			0, 0, 1, 1, declManager->FindMaterial("guis/assets/cursor_prohibit_bg"));

		renderSystem->DrawStretchPic(
			spriteScreenPos.x - (28 / 2.0f),
			spriteScreenPos.y - (32 / 2.0f) + 10,
			28, 32,
			0, 0, 1, 1, declManager->FindMaterial("guis/assets/prohibitmarker"));
	}

	
    if (frobEnt->GetFrobName()[0] == '\0')
    {
        hud->SetStateBool("showfrobprompt", false);
        return;
    }


	
	hud->SetStateBool("frobholdable", frobEnt->IsFrobHoldable()); //control whether to show the frob-hold prompt.	
	if (frobEnt->IsFrobHoldable())
	{
		hud->SetStateString("frobhold_name", frobEnt->GetFrobNameHold());
	}

	hud->SetStateString("frob_name", common->GetLanguageDict()->GetString(frobEnt->GetFrobName()));
	hud->SetStateFloat("frobbutton_x", promptPos.x);
	hud->SetStateFloat("frobbutton_y", promptPos.y);

	hud->SetStateBool("showfrobprompt", true);

	
	//BC old frob rendering system. We're not using this because it uses the drawsmallstringext call; we want to instead keep everything piped into the gui system.
	/*
	//Draw the button prompt.
	frobkey = gameLocal.GetKeyFromBinding("_frob");

	if (frobkey.Length() <= 1)
	{
		//Frob key is just one letter long. i.e. "E"
		frobbuttonWidth = 15;
		renderSystem->DrawStretchPic(
			spriteScreenPos.x +  textOffsetX,
			spriteScreenPos.y + 1,
			frobbuttonWidth, 20,
			0, 0, 1, 1, declManager->FindMaterial("guis/assets/buttonprompt2"));
	}
	else
	{
		frobbuttonWidth = 30;
		renderSystem->DrawStretchPic(
			spriteScreenPos.x +  textOffsetX,
			spriteScreenPos.y + 1,
			frobbuttonWidth, 20,
			0, 0, 1, 1, declManager->FindMaterial("guis/assets/buttonprompt"));
	}

	renderSystem->DrawSmallStringExt(spriteScreenPos.x +  textOffsetX + (frobbuttonWidth/2) - ((frobkey.Length() * 7) / 2.0f ), spriteScreenPos.y + 4, frobkey, idVec4(0, 0, 0, 1), true, declManager->FindMaterial("textures/bigchars"));

	//Draw frob display name.
	if (displaynameLength > 0)
	{
		spriteScreenPos.x += frobbuttonWidth + 4 + textOffsetX;
		spriteScreenPos.y += 4;

		//TODO: CHANGE displayamebox to be a variable so game isn't checking it every frame
		renderSystem->DrawStretchPic(spriteScreenPos.x - 2, spriteScreenPos.y - 2, (displaynameLength * 8) + 2, 18, 0, 0, 1, 1, declManager->FindMaterial("displaynamebox"));



		//Draw text and draw text shadow.
		//renderSystem->DrawSmallStringExt(spriteScreenPos.x+1, spriteScreenPos.y+1, frobEnt->displayName, idVec4(0,0,0,1), true, declManager->FindMaterial("textures/bigchars"));//Shadow
		renderSystem->DrawSmallStringExt(spriteScreenPos.x, spriteScreenPos.y, frobEnt->displayName, idVec4(1, 1, 1, 1), true, declManager->FindMaterial("textures/bigchars"));
	}*/
}

void idPlayer::DrawMemoryPalace()
{
	if (memorypalaceState != MEMP_ACTIVE)
		return;

	for (idEntity* ent = gameLocal.memorypalaceEntities.Next(); ent != NULL; ent = ent->memorypalaceNode.Next())
	{
		if (!ent)
			continue;

		if (!ent->IsType(idNoteWall::Type))
			continue;

		if (!static_cast<idNoteWall*>(ent)->IsMemorypalaceClone())
			continue;

		idVec3 dirToText = ent->GetPhysics()->GetOrigin() - this->firstPersonViewOrigin;
		dirToText.Normalize();
		float facingResult = DotProduct(dirToText, viewAngles.ToForward());
		if (facingResult <= 0)
			continue; //If text is behind me, then exit here.

		//We have a memory palace note.
		if (static_cast<idNoteWall*>(ent)->GetMarkedDone())
		{
			//Draw the X.
			#define CROSSOUTSIZEX 60
			#define CROSSOUTSIZEY 70
			idVec2 noteScreenPos = GetWorldToScreen(ent->GetPhysics()->GetOrigin());
			renderSystem->DrawStretchPic(
				noteScreenPos.x - (CROSSOUTSIZEX / 2),
				noteScreenPos.y - (CROSSOUTSIZEY / 2),
				CROSSOUTSIZEX,
				CROSSOUTSIZEY,
				0, 0, 1, 1,
				declManager->FindMaterial(spawnArgs.GetString("mtr_memp_crossout")));
		}
	}
}

//draw jockey killspot UI in world.
bool idPlayer::DrawJockeyUI()
{
	if (jockeyState != JCK_ATTACHED || !meleeTarget.IsValid())
		return false;

	if (!meleeTarget.GetEntity()->IsType(idGunnerMonster::Type))
		return false;

	//dont draw ui if my target is being actively slammed into wall
	if (static_cast<idGunnerMonster*>(meleeTarget.GetEntity())->IsJockeyBeingSlammed())
	{
		hud->SetStateBool("showjockeyattackprompt", false);
		return false;
	}

	//Draw an icon on top of nearby killspots.
	idEntity		*entityList[MAX_GENTITIES];
	int				nodeList, i;
	nodeList = gameLocal.EntitiesWithinRadius(GetPhysics()->GetOrigin() + idVec3(0,0,64), JOCKEY_DIAMOND_RADIUS, entityList, MAX_GENTITIES);

	for (i = 0; i < nodeList; i++)
	{
		idEntity		*ent = entityList[i];

		if (!static_cast<idGunnerMonster *>(meleeTarget.GetEntity())->IsObjectKillEntity(ent))
			continue;
		
		//skip it if it's behind me
		idVec3 dirToEnemy = ent->GetPhysics()->GetOrigin() - firstPersonViewOrigin;
		dirToEnemy.Normalize();
		float facingResult = DotProduct(dirToEnemy, viewAngles.ToForward());
		if (facingResult < 0)
			continue;

		//check for same room. We do this because we want to see things around corners, which tracelines won't hit.
		bool isInSameRoom = false;
		idLocationEntity *entLocation = NULL;
		entLocation = gameLocal.LocationForEntity(ent);
		idLocationEntity *playerLocation = NULL;
		playerLocation = gameLocal.LocationForEntity(this);
		if (entLocation != NULL && playerLocation != NULL)
		{
			if (entLocation->entityNumber == playerLocation->entityNumber)
			{
				isInSameRoom = true;
			}
		}

		//check for LOS
		if (gameLocal.HasJockeyLOSToEnt(ent) || isInSameRoom)
		{			
			//valid!
		}
		else
		{
			continue;
		}



		//draw icon on object.
		idVec3 offset = ent->spawnArgs.GetVector("jockey_offset");
		idVec3 diamondWorldPos = ent->GetPhysics()->GetOrigin();

		if (offset.x != 0 || offset.y != 0 || offset.z != 0)
		{
			idVec3 forward, right, up;
			ent->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);
			diamondWorldPos += (forward * offset[0]) + (right * offset[1]) + (up * offset[2]);
		}

		idVec2 diamondPos = GetWorldToScreen(diamondWorldPos);

		#define DIAMONDMARKER_ICONWIDTH 50
		#define DIAMONDMARKER_ICONHEIGHT 60
		renderSystem->SetColor(idVec4(1, .3f, .3f, .8f));
		renderSystem->DrawStretchPic(
			diamondPos.x - (DIAMONDMARKER_ICONWIDTH / 2),
			diamondPos.y - (DIAMONDMARKER_ICONHEIGHT / 2),
			DIAMONDMARKER_ICONWIDTH,
			DIAMONDMARKER_ICONHEIGHT,
			0, 0, 1, 1,
			declManager->FindMaterial("guis/assets/jockey_attractor"));

		//gameRenderWorld->DrawTextA(idStr::Format("%s", ent->GetName()).c_str(), ent->GetPhysics()->GetOrigin(), 0.3f, colorGreen, viewAngles.ToMat3(), 1, 100);
	}


	//Check if an attack currently available
	idGunnerMonster *aiEnt = static_cast<idGunnerMonster *>(meleeTarget.GetEntity());
	if (aiEnt->jockeyAttackCurrentlyAvailable == JOCKATKTYPE_NONE)
	{
		lastAvailableJockeyAttacktype = -1;
		hud->SetStateBool("showjockeyattackprompt", false);
		return false;
	}

	if (aiEnt->IsJockeyBeingAttacked())
	{
		lastAvailableJockeyAttacktype = -1;
		hud->SetStateBool("showjockeyattackprompt", false);
	}
	else
	{
		hud->SetStateBool("showjockeyattackprompt", true);
	}

	//Get world position of where the available attack is.
	idVec3 iconPos = vec3_zero;
	idMat3 iconAng = mat3_identity;
	if (aiEnt->jockeyAttackCurrentlyAvailable == JOCKATKTYPE_WALLSMASH)
	{
		iconPos = aiEnt->GetJockeySmashTrace().endpos;
		iconAng = aiEnt->GetJockeySmashTrace().c.normal.ToMat3();
	}
	else if (aiEnt->jockeyAttackCurrentlyAvailable == JOCKATKTYPE_KILLENTITY && aiEnt->jockeyKillEntity.IsValid())
	{
		idVec3 offset = aiEnt->jockeyKillEntity.GetEntity()->spawnArgs.GetVector("jockey_offset");
		idVec3 diamondWorldPos = aiEnt->jockeyKillEntity.GetEntity()->GetPhysics()->GetOrigin();

		if (offset.x != 0 || offset.y != 0 || offset.z != 0)
		{
			idVec3 forward, right, up;
			aiEnt->jockeyKillEntity.GetEntity()->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);
			diamondWorldPos += (forward * offset[0]) + (right * offset[1]) + (up * offset[2]);
		}

		iconPos = diamondWorldPos;
		iconAng = aiEnt->jockeyKillEntity.GetEntity()->GetPhysics()->GetAxis();
	}

	if (iconPos == vec3_zero) //This shouldn't happen, but just in case .... if no attack available, then exit out.
	{
		hud->SetStateBool("showjockeyattackprompt", false);
		return false;
	}

	//jockeyDisc->GetPhysics()->SetOrigin(iconPos); //Position the attack disc model.

	//idVec3 dirToIcon =  idVec3(aiEnt->GetPhysics()->GetOrigin().x, aiEnt->GetPhysics()->GetOrigin().y, iconPos.z) - iconPos;
	//dirToIcon.Normalize();
	//jockeyDisc->SetAxis(iconAng);

	idVec2 spriteScreenPos = GetWorldToScreen(iconPos);
	if (aiEnt->jockeyAttackCurrentlyAvailable == JOCKATKTYPE_KILLENTITY)
	{
		//Draw skull icon.
		#define JOCKPOS_ICONWIDTH 35
		#define JOCKPOS_ICONHEIGHT 45
		renderSystem->DrawStretchPic(
			spriteScreenPos.x - (JOCKPOS_ICONWIDTH / 2),
			spriteScreenPos.y - (JOCKPOS_ICONHEIGHT / 2),
			JOCKPOS_ICONWIDTH,
			JOCKPOS_ICONHEIGHT,
			0, 0, 1, 1,
			declManager->FindMaterial("guis/assets/jockey_boomicon"));

		hud->SetStateString("jockeyattack_name", "BRUTAL SLAM");

		if (aiEnt->jockeyKillEntity.IsValid())
		{
			idStr killEntName;
			if (aiEnt->jockeyKillEntity.GetEntity()->displayName.Length() > 0)
				killEntName = aiEnt->jockeyKillEntity.GetEntity()->displayName;
			else
				killEntName = aiEnt->GetName(); //This is an emergency fallback to help us find objects that don't have a displayname.

			hud->SetStateString("jockeyitem_name", killEntName.c_str());
		}
		else
		{
			hud->SetStateString("jockeyitem_name", "");
		}	
	}
	else
	{
		hud->SetStateString("jockeyattack_name", "WALL BASH");
	}

	//Clamp it to edge of screen.
	spriteScreenPos.x = idMath::ClampFloat(10,  640 - 200, spriteScreenPos.x);
	spriteScreenPos.y = idMath::ClampFloat(10,  480 - 30, spriteScreenPos.y);

	hud->SetStateFloat("jockeyattack_x", spriteScreenPos.x);
	hud->SetStateFloat("jockeyattack_y", spriteScreenPos.y);

	//Controls legend
	//renderSystem->DrawBigStringExt(320, 300, (aiEnt->jockeyAttackCurrentlyAvailable == JOCKATKTYPE_KILLENTITY) ? "LMB = object bash" : "LMB = wall bash", idVec4(1, 1, 1, 1), true, declManager->FindMaterial("textures/bigchars"));

	if (lastAvailableJockeyAttacktype != aiEnt->jockeyAttackCurrentlyAvailable)
	{
		hud->HandleNamedEvent("jockeyattackFlash");
		lastAvailableJockeyAttacktype = aiEnt->jockeyAttackCurrentlyAvailable;
	}
	


	return true;
}

void idPlayer::DrawPickpocketUI()
{
	#define CIRCLE_BASERADIUS  12

	if (pickpocketState == PP_NONE)
	{
		hud->SetStateBool("pp_draw", false);
		return;
	}

	if (!pickpocketEnt.IsValid())
	{
		hud->SetStateBool("pp_draw", false);
		return;
	}

	hud->SetStateBool("pp_draw", true);

	idVec3 entPos = pickpocketEnt.GetEntity()->GetPhysics()->GetOrigin();

	
	//check if behind...
	idVec3 dirToPickpocket = entPos - firstPersonViewOrigin;
	float facingResult = DotProduct(dirToPickpocket, viewAngles.ToForward());
	if (facingResult <= 0)
		return; //If it is behind me, then exit here.


	idVec2 entCirclePos = GetWorldToScreen(entPos);
	idVec2 entPromptPos = GetWorldToScreen(entPos + idVec3(0,0, CIRCLE_BASERADIUS));

	hud->SetStateFloat("pp_x", entPromptPos.x);
	hud->SetStateFloat("pp_y", entPromptPos.y);



	float barLerp = pickpocketPipCount / (float)PICKPOCKET_PIPMAX;
	barLerp = idMath::ClampFloat(0, 1, barLerp);
	hud->SetStateFloat("pp_amount", barLerp);


	#define CIRCLE_WIDTHMODIFIER .8f
	float circleSize = (entCirclePos.y - entPromptPos.y) * 2;
	circleSize *= 1.1f;
	renderSystem->SetColor4(1,1,1,.5f);
	renderSystem->DrawStretchPic(
		entCirclePos.x - ((circleSize*CIRCLE_WIDTHMODIFIER) / 2),
		entCirclePos.y - (circleSize / 2),
		circleSize * CIRCLE_WIDTHMODIFIER,
		circleSize,
		0, 0, 1, 1,
		declManager->FindMaterial("textures/particles/soundwave_blend"));

	float dist = GetPickpocketDistance();
	float distLerp = dist / (float)PICKPOCKET_RANGE;

	float distCircleSize = circleSize * distLerp;

	if (distLerp < PICKPOCKET_FAR_THRESHOLD)
	{
		renderSystem->SetColor4(1, .8f, 0, 1); //player is close-ish to the object. default color.
		hud->SetStateBool("pp_toofar", false);
		pickpocketGoodRange = true;
	}
	else
	{
		renderSystem->SetColor4(1, .2f, .2f, 1); //player is kinda far, so make the ui element turn red.
		hud->SetStateBool("pp_toofar", true);
		pickpocketGoodRange = false;
	}

	if (lastPickpocketGoodRange != pickpocketGoodRange && pickpocketEnt.IsValid())
	{
		lastPickpocketGoodRange = pickpocketGoodRange;

		if (pickpocketGoodRange)
			pickpocketEnt.GetEntity()->StartSoundShader(declManager->FindSound("pickpocket_7s"), SND_CHANNEL_PDA, 0, false, NULL);
		else
			pickpocketEnt.GetEntity()->StartSoundShader(declManager->FindSound("pickpocket_paused"), SND_CHANNEL_PDA, 0, false, NULL);			
		
	}

	renderSystem->DrawStretchPic(
		entCirclePos.x - ((distCircleSize*CIRCLE_WIDTHMODIFIER) / 2),
		entCirclePos.y - (distCircleSize / 2),
		distCircleSize * CIRCLE_WIDTHMODIFIER,
		distCircleSize,
		0, 0, 1, 1,
		declManager->FindMaterial("guis/assets/pickpocket_circle"));
}

//BC the dodge UI is currently not being used.
void idPlayer::DrawAIDodgeUI()
{
	//Draw the 'ai will dodge your throwable' ui.

	if (!shouldDrawThrowArc)
		return;

	for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	{
		if (!entity || !entity->IsActive() || entity->IsHidden() || entity == this || entity->team == TEAM_FRIENDLY || entity->health <= 0 )
			continue;

		if (!entity->IsType(idGunnerMonster::Type))
			continue;

		if (!static_cast<idGunnerMonster *>(entity)->drawDodgeUI)
			continue;

		//found an AI that will do the dodge. draw the dodge UI on them.
		idVec3 headPosition = static_cast<idGunnerMonster *>(entity)->GetEyePosition();
		idVec2 spriteScreenPos = GetWorldToScreen(headPosition);

		#define CROSS_ICONWIDTH 16
		#define CROSS_ICONHEIGHT 20
		renderSystem->DrawStretchPic(
			spriteScreenPos.x - (CROSS_ICONWIDTH/2),
			spriteScreenPos.y - (CROSS_ICONHEIGHT /2),
			CROSS_ICONWIDTH,
			CROSS_ICONHEIGHT,
			0, 0, 1, 1,
			declManager->FindMaterial("guis/assets/circlecross"));		

		hud->DrawArbitraryText("WILL DODGE", 0.4f, idVec4(1, 0, 0, 1), spriteScreenPos.x + 12, spriteScreenPos.y - 4, "fonts", idVec4(0, 0, 0, 1), 0);
	}
}


// SW: Ported from weapon_signallamp script. Used for displaying the 'you need to be outside' message,
// but may have other uses?
//
// Probably also needs work to be made more robust
bool idPlayer::CanSeeSpace()
{
	idVec3 viewDir = viewAngles.ToForward().Normalized();
	idVec3 eyePosition = GetEyePosition();

	trace_t forwardTrace;
	gameLocal.clip.TracePoint(forwardTrace, eyePosition, eyePosition + (viewDir * 8192), MASK_SOLID, this);
	if (forwardTrace.fraction < 1.0f && forwardTrace.c.material->GetSurfaceFlags() & SURF_NOIMPACT)
		return true;

	trace_t backwardTrace;
	gameLocal.clip.TracePoint(backwardTrace, eyePosition, eyePosition + (viewDir * -8192), MASK_SOLID, this);
	if (backwardTrace.fraction < 1.0f && backwardTrace.c.material->GetSurfaceFlags() & SURF_NOIMPACT)
		return true;

	if (isInOuterSpace())
		return true;

	return false;
}

// Called from the signal lamp script when the player has started 'firing' it. Only relevant when locked-on.
void idPlayer::StartEnteringCode()
{
	this->codeStartTime = gameLocal.time;
	this->isEnteringCode = true;
}

// SW: Ported from weapon_signallamp script. Updates the morse code being entered by the player
void idPlayer::UpdateSignalCode()
{
	//idUserInterface* weaponGui = this->weapon.GetEntity()->GetRenderEntity()->gui[0];

	// Only allow us to change the code if we're actually locked on (and not currently activating a beacon!)
	if (this->signalLock && !beaconFlashState)
	{
		if (!CanSeeSpace())
		{
			// Tell the player to move outside!
			//weaponGui->HandleNamedEvent("los_msg");
		}
		else
		{
			if (this->isEnteringCode)
			{
				if (!(usercmd.buttons & BUTTON_ATTACK))
				{
					// Player just released the attack button
					this->isEnteringCode = false;

					if (gameLocal.time < this->codeStartTime + BEACON_DASH_LENGTH)
					{
						// We released the button before the threshold, make a dot
						this->beaconCode.Append(DOT);
						StartSoundShader(declManager->FindSound("morse_dot"), SND_CHANNEL_VOICE, 0, false, NULL);
					}
				}
				else if (gameLocal.time >= this->codeStartTime + BEACON_DASH_LENGTH)
				{
					// We held the button down long enough to make a dash.
					// Note that this doesn't require the player to release the button,
					// but we will not register any new dots or dashes until they release and re-press.
					this->isEnteringCode = false;
					this->beaconCode.Append(DASH);
					StartSoundShader(declManager->FindSound("morse_dash"), SND_CHANNEL_VOICE2, 0, false, NULL);
				}
			}

			
			idStr customMapCode = gameLocal.world->spawnArgs.GetString("signal_code1");

			if (this->beaconCode == BEACON_SIGNALCODE_EXTRACTION)
			{
				ActivateBeacon(BEACONTYPE_EXTRACTION, this->lastBeaconPosition);
			}
			//else if (this->beaconCode == BEACON_SIGNALCODE_SHOP)
			//{
			//	ActivateBeacon(BEACONTYPE_SHOP, this->lastBeaconPosition);
			//}
			else if (CallCustomMorsesignal(this->beaconCode))
			{
				//Custom signal called successfully.
				this->beaconCode = "";
			}
			else if (gameLocal.time > this->codeStartTime + BEACON_SIGNAL_RESETTIME && this->beaconCode != "" && !(usercmd.buttons & BUTTON_ATTACK))
			{
				// The player has lingered too long without doing anything. Reset the code.
				this->beaconCode = "";
				StartSoundShader(declManager->FindSound("cancel"), SND_CHANNEL_ITEM, 0, false, NULL);
			}
		}
	}
}

bool idPlayer::CallCustomMorsesignal(idStr _playercode)
{
	#define SIGNAL_STRINGLENGTH 10 //how many characters are in 'signal_code'
	const idKeyValue *kv;
	kv = gameLocal.world->spawnArgs.MatchPrefix("signalcode", NULL);
	while (kv)
	{
		idStr suffix = kv->GetKey();
		suffix = suffix.Right(suffix.Length() - SIGNAL_STRINGLENGTH);

		idStr codekey = kv->GetValue();
		if (idStr::Icmp(_playercode, codekey) == 0)
		{
			//Match.
			idStr functionName = idStr::Format("_onSignalcode%s", suffix.c_str());
			gameLocal.RunMapScript(functionName);
			return true;
		}

		kv = gameLocal.world->spawnArgs.MatchPrefix("signal_code", kv); //Iterate to next entry.
	}

	return false;
}


// SW: Ported from the weapon_signallamp script. Updates signal strength, lock-on, various gui bits & pieces
void idPlayer::UpdateBeaconSignalLock()
{
	//Check if FTL is currently on.
	//if (static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->FTL_IsActive()) //Sab2.0
	//{
	//	//FTL is currently active.
	//
	//	idUserInterface* weaponGui = this->weapon.GetEntity()->GetRenderEntity()->gui[0];
	//	weaponGui->GetStateString("gui_parm7", "");
	//	weaponGui->SetStateBool("showText", false);
	//	weaponGui->SetStateFloat("trianglevisible", 0);
	//	weaponGui->SetStateFloat("vert_arrows", 0);
	//	weaponGui->SetStateBool("sig_indoor", false);
	//	weaponGui->SetStateBool("sig_ftl", true);
	//	//weaponGui->StateChanged(gameLocal.time, true);
	//	return;
	//}

	//First, check if lifeboat is already in the world.
	if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.IsValid() && weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
	{
		idUserInterface* weaponGui = this->weapon.GetEntity()->GetRenderEntity()->gui[0];

		if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idLifeboat::Type))
		{
			//the lifeboat is IN the world.
			weaponGui->SetStateString("gui_parm7", common->GetLanguageDict()->GetString("#str_def_gameplay_signallamp_here"));
			weaponGui->SetStateBool("showText", false); //Hide the % and the "SIGNAL" text
			weaponGui->SetStateBool("trianglevisible", true);
		}
		else
		{
			bool displayWaitText = false;
			if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idBeaconLogic::Type))
			{
				idMeta *metaEnt = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity());
				idBeaconLogic *beaconEnt = static_cast<idBeaconLogic *>(metaEnt->signallampEntity.GetEntity());
				displayWaitText = beaconEnt->HasLockedOn();
			}

			//player is AIMING the lifeboat for deployment.
			weaponGui->SetStateString("gui_parm7", displayWaitText ? common->GetLanguageDict()->GetString("#str_def_gameplay_signallamp_wait") : "");
			weaponGui->SetStateBool("showText", false); //Hide the % and the "SIGNAL" text
			weaponGui->SetStateBool("trianglevisible", true);

			EnableBeaconUI();
		}

		return;
	}

	//Ok, lifeboat is NOT in the world right now.

	//Check if player is in outer space.	
	if (!isInOuterSpace())
	{
		//Player is NOT in outer space.
		idUserInterface* weaponGui = this->weapon.GetEntity()->GetRenderEntity()->gui[0];
		weaponGui->GetStateString("gui_parm7", "");
		//weaponGui->Redraw(gameLocal.time);
		weaponGui->SetStateBool("showText", false);		
		weaponGui->SetStateFloat("trianglevisible", 0);
		weaponGui->SetStateFloat("vert_arrows", 0);
		weaponGui->SetStateBool("sig_indoor", true);
		weaponGui->SetStateBool("sig_ftl", false);
		return;
	}

	//Update the signal strength.
	if (gameLocal.time > this->lastSignalLockUpdate + BEACON_SIGNAL_UPDATE_INTERVAL)
	{
		this->lastSignalLockUpdate = gameLocal.time;

		idVec3 viewDir = viewAngles.ToForward().Normalized();
		idVec3 beaconPosition = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->beaconPosition;
		idVec3 eyePosition = GetEyePosition();
		idUserInterface* weaponGui = this->weapon.GetEntity()->GetRenderEntity()->gui[0];

		trace_t toBeaconTr;
		gameLocal.clip.TracePoint(toBeaconTr, eyePosition, beaconPosition, MASK_SOLID, this);
		this->lastBeaconPosition = toBeaconTr.endpos;

		weaponGui->SetStateBool("showText", true); //Show the % and the "SIGNAL" text
		weaponGui->SetStateBool("sig_indoor", false); //Hide the "you're indoors" warning.
		weaponGui->SetStateBool("sig_ftl", false); //Hide the ftl warning.


		// Figure out where the player is looking relative to the direction they *should* be looking,
		// if they want to lock on.
		idVec3 toBeacon = (beaconPosition - eyePosition).Normalized();
		float dotProductWithBeacon = DotProduct(viewDir, toBeacon);
		float signalStrength = (dotProductWithBeacon + 1.0f) / 2.0f; // Change dot product's range from (-1, 1) to (0, 1)

		bool hasClearLOSToBeacon = (toBeaconTr.fraction < 1 && (toBeaconTr.c.material && toBeaconTr.c.material->GetSurfaceFlags() >= 256));
		if (!hasClearLOSToBeacon)
		{
			//If we don't have LOS to the beacon, then just artifically "degrade" the signal strength, so the player can't input a code.
			EnableBeaconUI();
			signalStrength = Min(signalStrength, BEACON_SIGNAL_STRENGTH_THRESHOLD - .022f);
		}

		if (signalStrength < BEACON_SIGNAL_STRENGTH_THRESHOLD)
		{
			// Our signal strength isn't good enough. Show it on the gui (as a percentage)
			char* signalString = va("%.0f", idMath::Floor(signalStrength * 100));
			weaponGui->SetStateString("gui_parm7", signalString);

			int beaconCurrentStrength = atoi(signalString);
			

			// Turn off lock-on visuals, if they're on
			if (this->signalLock)
			{
				this->signalLock = false;
				StartSoundShader(declManager->FindSound("morse_lockoff"), SND_CHANNEL_HEART, 0, false, NULL);
			}
			weaponGui->SetStateFloat("trianglevisible", 0);

			// If the player's yaw is correct but their pitch is off, 
			// we want to draw little guide arrows to help them zero-in
			// So, we create versions of the above vectors with the pitch flattened out, 
			// and compare them on the X/Y plane
			idVec3 toBeaconFlattened(toBeacon.x, toBeacon.y, 0);
			idVec3 viewDirFlattened(viewDir.x, viewDir.y, 0);
			if (DotProduct(toBeaconFlattened.Normalized(), viewDirFlattened.Normalized()) >= BEACON_PITCH_CORRECTION_THRESHOLD)
			{
				// Yaw is correct-ish.
				// Show the arrows to indicate they should pitch up/down.
				weaponGui->SetStateFloat("vert_arrows", 1);

				if (!beaconLastVertArrows)
				{
					//We do particle sparkle at beacon position when player yaw is correct. This is to help the player along, to make the aiming process less finicky.
					
					trace_t skyTrace;
					idVec3 beaconPos = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->beaconPosition;
					gameLocal.clip.TracePoint(skyTrace, firstPersonViewOrigin, beaconPos, MASK_SOLID, NULL);
					if (skyTrace.fraction < 1 && (skyTrace.c.material && skyTrace.c.material->GetSurfaceFlags() >= 256))
					{
						idVec3 angleToBeacon = beaconPos - firstPersonViewOrigin;
						angleToBeacon.NormalizeFast();
						
						idVec3 particlePos = skyTrace.endpos + angleToBeacon  * -96;						
						gameLocal.DoParticle("sparkle_lifepod_hint.prt", particlePos);
					}				


					beaconLastVertArrows = true;
				}
			}
			else
			{
				// Our yaw isn't there yet either.
				weaponGui->SetStateFloat("vert_arrows", 0);

				if (beaconLastVertArrows)
				{
					beaconLastVertArrows = false;
				}
			}

			if (beaconCurrentStrength != beaconLastStrength)
			{
				beaconLastStrength = beaconCurrentStrength;
				
				idStr shaderToPlay = "";

				if (beaconCurrentStrength >= 90)
					shaderToPlay = "morse_str_90";
				else if (beaconCurrentStrength >= 80)
					shaderToPlay = "morse_str_80";
				else if (beaconCurrentStrength >= 70)
					shaderToPlay = "morse_str_70";
				else if (beaconCurrentStrength >= 60)
					shaderToPlay = "morse_str_60";
				else if (beaconCurrentStrength >= 50)
					shaderToPlay = "morse_str_50";
				else if (beaconCurrentStrength >= 40)
					shaderToPlay = "morse_str_40";
				else if (beaconCurrentStrength >= 30)
					shaderToPlay = "morse_str_30";
				else if (beaconCurrentStrength >= 20)
					shaderToPlay = "morse_str_20";
				else if (beaconCurrentStrength >= 10)
					shaderToPlay = "morse_str_10";
				else
					shaderToPlay = "morse_str_00";

				StartSoundShader(declManager->FindSound(shaderToPlay.c_str()), SND_CHANNEL_PDA, 0, false, NULL);
			}
		}
		else
		{
			// Our signal strength is good enough!
			// Turn on lock-on visuals, if they're off
			if (!this->signalLock)
			{
				this->signalLock = true;
				StartSoundShader(declManager->FindSound("morse_lockon"), SND_CHANNEL_HEART, 0, false, NULL);
				weaponGui->SetStateFloat("vert_arrows", 0);
			}
			weaponGui->SetStateFloat("trianglevisible", 1);
			weaponGui->SetStateString("gui_parm7", common->GetLanguageDict()->GetString("#str_def_gameplay_signallamp_lock"));

			// This just extends the time we can use the beacon, so it needs to be called every update
			EnableBeaconUI(); 
		}

		weaponGui->StateChanged(gameLocal.time);
	}
}

void idPlayer::EnableBeaconUI()
{
	beaconUITimer = gameLocal.time + 100;
}

void idPlayer::ActivateBeacon(int beaconType, const idVec3 &beaconSpawnPos)
{
	const idDeclEntityDef *botDef;
	idEntity *beaconlogicEnt;

	//Player has used the signal lamp to call in a beacon request.... begin the payload delivery sequence!

	//Spawn the beacon logic object. This object is invisible and does the laser aiming thing.
	botDef = gameLocal.FindEntityDef("target_beaconlogic", false);

	if (!botDef)
	{
		gameLocal.Error("Failed to find def for target_beaconlogic.");
	}
	else
	{
        //TODO: pause hte beacon position when this happens??


		//So, we do some logic to find a suitable location for the pod to spawn.
		//This is a little hairy because it's possible for the player to summon the pod when it's BEHIND the ship/geometry.


		idVec3 newBeaconPos = FindSuitableBeaconSpawn(beaconSpawnPos);

		if (newBeaconPos == vec3_zero)
		{
			idThread::ReturnInt(0);
			return;
		}
		
		gameLocal.SpawnEntityDef(botDef->dict, &beaconlogicEnt, false);

		if (beaconlogicEnt)
		{
			beaconlogicEnt->SetOrigin(newBeaconPos);

			if (beaconlogicEnt->IsType(idBeaconLogic::Type))
			{
				static_cast<idBeaconLogic *>(beaconlogicEnt)->SetPodType(beaconType);
			}

			//Do the UI flashing.
			beaconFlashState = true;
			beaconFlashTimer = gameLocal.time + BEACON_FLASHTIME;

			static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity = beaconlogicEnt;
		}
		else
		{
			gameLocal.Error("target_beaconlogic failed to spawn.");
		}
	}

	idThread::ReturnInt(1);
}


idVec3 idPlayer::FindSuitableBeaconSpawn(idVec3 beaconPos)
{
	//First see if player has direct LOS to the beacon.
	#define TRACE_DISTANCE 8192
	trace_t beaconTr;
	idVec3 dirToBeacon = beaconPos - GetEyePosition();
	dirToBeacon.NormalizeFast();

	gameLocal.clip.TracePoint(beaconTr, GetEyePosition(), GetEyePosition() + dirToBeacon * TRACE_DISTANCE, MASK_SOLID, this);
	if (beaconTr.c.material->GetSurfaceFlags() >= 256)
	{
		//touched sky. valid beacon. Player has direct LOS to beacon. Done. Spawn the pod at the beacon position.
		return beaconTr.endpos + (dirToBeacon * -BEACON_SPAWNOFFSET); //make it stick out a little to avoid accidental clipping
	}



	//Player doesn't have LOS to beacn spawnpoint. So, we need to do some logic to find a good spawnpoint.


	//First check: try to find a spot that biased in FRONT of player camera.
	//This array is a list of angles to check. (forward, right, up)	
	#define CHECK_ANGLE_AMOUNT 12
	idVec3 checkDirections[CHECK_ANGLE_AMOUNT]
	{
		idVec3(1,0,1),
		idVec3(1,0,-1),
		idVec3(1,1,0),
		idVec3(1,-1,0),

		idVec3(.5f,0,1),
		idVec3(.5f,0,-1),
		idVec3(.5f,1,0),
		idVec3(.5f,-1,0),

		idVec3(.1f,0,1),
		idVec3(.1f,0,-1),
		idVec3(.1f,1,0),
		idVec3(.1f,-1,0)
	};

	idVec3 dirLeft, dirDown;	
	dirToBeacon.NormalVectors(dirLeft, dirDown);

	for (int i = 0; i < CHECK_ANGLE_AMOUNT; i++)
	{
		idVec3 targetDir = (dirToBeacon * checkDirections[i].x) + (dirLeft * checkDirections[i].y) + (dirDown * checkDirections[i].z);
		targetDir.NormalizeFast();
		idVec3 targetPos = GetEyePosition() + targetDir * TRACE_DISTANCE;

		trace_t tr;
		gameLocal.clip.TracePoint(tr, GetEyePosition(), targetPos, MASK_SOLID, this);
		if (tr.c.material->GetSurfaceFlags() >= 256)
		{
			//Has touched the sky. Valid location found.
			return tr.endpos + (dirToBeacon * -BEACON_SPAWNOFFSET); //make it stick out a little to avoid accidental clipping
		}
	}


	//Failed to find anything in front of player camera.
	//Fallback attempt: check behind player, diametrically opposite of beacon position.
	trace_t backTr;
	gameLocal.clip.TracePoint(backTr, GetEyePosition(), GetEyePosition() + dirToBeacon * -TRACE_DISTANCE, MASK_SOLID, this);
	if (backTr.c.material->GetSurfaceFlags() >= 256)
	{
		//touched sky. valid beacon.
		return backTr.endpos + (dirToBeacon * -BEACON_SPAWNOFFSET); //make it stick out a little to avoid accidental clipping
	}


	//TODO: we need a more robust reaction to a total fail, as it's very busted to have a correct code input result in nothing happening.

	//Total fail.
	return vec3_zero;
}



void idPlayer::SetBeaconCode(const char * _code)
{
	beaconCode = _code;
}

//TODO: carry ui.

//UI for when dragging bodies.
void idPlayer::DrawGrabUI(void)
{
	if (!bodyDragger.isDragging)
		return;

	idVec2 screenPos = GetWorldToScreen(bodyDragger.cursor->draggedPosition);
	
	renderSystem->DrawStretchPic(
		screenPos.x - 14,
		screenPos.y - 16,
		28, 32,
		0, 0, 1, 1, declManager->FindMaterial("guis/assets/crosshairgrab"));
}

#define BEACONCOLOR_R .8f
#define BEACONCOLOR_G .6f
#define BEACONCOLOR_B 0

void idPlayer::DrawBeaconUI(void)
{
    if (!gameLocal.metaEnt.IsValid())
        return;

	if (carryableItem.IsValid() || bodyDragger.isDragging) //if carrying something, don't render beacon stuff
	{
		hud->SetStateBool("showbeaconbutton", false);
		hud->SetStateBool("showbeaconconfirm", false);
		return;
	}

	if (beaconLingerTimer > gameLocal.time)
	{
		//Draw the beacon even after you lose lockon. This makes it easier for the player to re-locate if they accidentally move off the signal. It disappears after a bit.

		idVec3 beaconPos1 = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->beaconPosition;
		idVec3 dirToBeacon = beaconPos1 - this->GetPhysics()->GetOrigin();
		float facingResult = DotProduct(dirToBeacon, viewAngles.ToForward());
		if (facingResult > 0)
		{
			//beacon is in FRONT of viewangle. Draw it.

			idVec2 screenPos1 = GetWorldToScreen(beaconPos1);
			float lerp = (beaconLingerTimer - gameLocal.time) / (float)BEACON_LINGERTIME;

			renderSystem->SetColor4(BEACONCOLOR_R * lerp, BEACONCOLOR_G * lerp, BEACONCOLOR_B * lerp, 1);
			renderSystem->DrawStretchPic(
				screenPos1.x - 4,
				screenPos1.y - 5,
				8, 10,
				0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_signal_scanbeacon")));
		}
	}


    //If lifeboat is in world, draw UI marker on it.
    if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.IsValid() && weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
    {
        if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idLifeboat::Type))
        {
            //Ok, found the lifeboat.
			idVec3 boatPos = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->GetPhysics()->GetOrigin();

			//Check if it is in front or behind us.
			idVec3 dirToEnemy = boatPos - this->GetPhysics()->GetOrigin();
			float facingResult = DotProduct(dirToEnemy, viewAngles.ToForward());
			if (facingResult <= 0)
				return; //If it is behind me, then exit here.

			//Get distance to it.
			float distanceToBoat = (boatPos - GetEyePosition()).Length();
			if (distanceToBoat < LIFEBOAT_LOCATOR_DISTANCETHRESHOLD)
				return;

			//Draw the marker on it.            
            idVec2 boatScreenpos = GetWorldToScreen(boatPos);

            #define BOATWIDTH 128
            #define BOATHEIGHT 160
            renderSystem->DrawStretchPic(
                boatScreenpos.x - (BOATWIDTH/2),
                boatScreenpos.y - (BOATHEIGHT/2),
                BOATWIDTH, BOATHEIGHT,
                0, 0, 1, 1, declManager->FindMaterial("lifeboat_locator"));

            return;
        }
		else if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idBeaconLogic::Type))
		{			
			idMeta *metaEnt = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity());
			idBeaconLogic *beaconEnt = static_cast<idBeaconLogic *>(metaEnt->signallampEntity.GetEntity());
			bool lockedOn = beaconEnt->HasLockedOn();
			
			if (!lockedOn)
			{
				//Draw the LMB confirm ui.
				idEntity *signallampEnt = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity();
				bool validLandingPosition = static_cast<idBeaconLogic *>(signallampEnt)->validLandingPosition;

				hud->SetStateBool("showbeaconconfirm", true);
				hud->SetStateBool("showbeaconbutton", validLandingPosition);

				idVec3 landingPosition = static_cast<idBeaconLogic *>(signallampEnt)->placerEnt->GetPhysics()->GetOrigin();

				idVec2 screenPos = GetWorldToScreen(landingPosition);

				//TODO: if the landing position is invalid and is not in the player's POV, then we need to adjust beaconbutton_x beaconbutton_y so the prompt doesn't appear at crazy locations on screen 
				if (!validLandingPosition)
				{
					hud->SetStateFloat("beaconbutton_x", 330);
					hud->SetStateFloat("beaconbutton_y", 240);
				}
				else
				{
					#define	BEACONPROMPTWIDTH_BUFFER 200
					#define	BEACONPROMPTHEIGHT_BUFFER 60
					idVec2 adjustedPos = screenPos + idVec2(20, -10);
					adjustedPos.x = idMath::ClampFloat(0, 640 - BEACONPROMPTWIDTH_BUFFER, adjustedPos.x);
					adjustedPos.y = idMath::ClampFloat(0, 480 - BEACONPROMPTHEIGHT_BUFFER, adjustedPos.y);

					hud->SetStateFloat("beaconbutton_x", adjustedPos.x);
					hud->SetStateFloat("beaconbutton_y", adjustedPos.y);
				}
			}
		}
    }
	else if (!weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
	{
		hud->SetStateBool("showbeaconbutton", false);
		hud->SetStateBool("showbeaconconfirm", false);
	}



	if (gameLocal.time > beaconUITimer || !weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
		return;     



	bool drawCode = true;
	idVec3 beaconPos = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->beaconPosition;

	//Only draw if in FRONT of player viewangle.
	idVec3 dirToTriangle = beaconPos - this->GetPhysics()->GetOrigin();
	float triangleFacingResult = DotProduct(dirToTriangle, viewAngles.ToForward());
	idVec2 screenPos = GetWorldToScreen(beaconPos);
	if (triangleFacingResult <= 0)
		return;
	
	//This is what gets rendered when the player is searching for the beacon signal.

	//The small rotating small triangle
	renderSystem->DrawStretchPic(
		screenPos.x - 6,
		screenPos.y - 8,
		12, 16,
		0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_signal_lock")));

	//The large static dot-matrix triangle.
	renderSystem->DrawStretchPic(
		screenPos.x - 96,
		screenPos.y - 128,
		192, 256,
		0, 0, 1, 1, declManager->FindMaterial(spawnArgs.GetString("mtr_signal_scantriangle")));
	
	
	if (beaconFlashState)
	{
		if (gameLocal.time > beaconFlashTimer)
		{
			beaconFlashState = false;
			beaconCode = "";
		}

		
		if (gameLocal.time > beaconUIBlinkTimer)
		{
			beaconUIBlinkTimer = gameLocal.time + BEACON_BLINKTIME;
			beaconUIBlink = !beaconUIBlink;
		}

		if (!beaconUIBlink)
			drawCode = false;
	}
	
	if (drawCode)
	{
		if (strstr(beaconCode, "snd"))
		{
			//SHAMEFUL HACK. Hide this weird string that sometimes mysteriously appears here... if it appears, just don't render it. This is hideous don't look at it!!!!! Let's ship this video game!!!!
			// 
			// SW: I'm fairly sure this shouldn't be a problem any more, but better safe than sorry.
		}
		else
		{
			renderSystem->DrawSmallStringExt(screenPos.x + 8 + 1, screenPos.y + 1 - 10, beaconCode, idVec4(0, 0, 0, .3f), true, declManager->FindMaterial("textures/bigchars"));
			renderSystem->DrawSmallStringExt(screenPos.x + 8, screenPos.y - 10, beaconCode, idVec4(1, .8f, 0, 1), true, declManager->FindMaterial("textures/bigchars"));
		}
	}

	beaconLingerTimer = gameLocal.time + BEACON_LINGERTIME;
}

void idPlayer::DrawAutoAimUI(void)
{
	idStr dotMaterial;
	float dotSize = AUTOAIM_DOT_SMALLSIZE;

	if (autoaimDotState == AUTOAIMDOTSTATE_MOVING_TO_LOCK)
	{
		idVec2 dotScreenPos = GetWorldToScreen(autoaimPos);
		float lerp = Min(1.0f, (gameLocal.time - autoaimDotTimer) / (float)AUTOAIM_DOT_MOVETIME);
		lerp = idMath::CubicEaseOut(lerp);

		autoaimDotEndPos = dotScreenPos;
		autoaimDotPosition.Lerp(autoaimDotStartPos, autoaimDotEndPos, lerp);


		dotSize = idMath::Lerp( lastAutoaimDotState == AUTOAIMDOTSTATE_LOCKED ? AUTOAIM_DOT_BIGSIZE / 3 : AUTOAIM_DOT_BIGSIZE, AUTOAIM_DOT_SMALLSIZE, lerp);

		if (lerp >= 1)
		{
			autoaimDotState = AUTOAIMDOTSTATE_LOCKED;
			autoaimDotTimer = gameLocal.time;
		}
	}
	else if (autoaimDotState == AUTOAIMDOTSTATE_LOCKED)
	{
		float lerp = Min(1.0f, (gameLocal.time - autoaimDotTimer) / (float)AUTOAIM_DOT_FLASHTIME);
		idVec2 dotScreenPos = GetWorldToScreen(autoaimPos);
		float dotDist;

		if (lerp > 1.0f)
			dotDist = AUTOAIM_DOT_LOCKDISTANCE;
		else
			dotDist = idMath::Lerp(AUTOAIM_DOT_FLASHDISTANCE, AUTOAIM_DOT_LOCKDISTANCE, lerp);

		autoaimDotPosition = dotScreenPos;

		dotSize = AUTOAIM_DOT_SMALLSIZE;

		//Draw the "LOCK" text.
		renderSystem->DrawStretchPic(
			autoaimDotPosition.x - 16,
			autoaimDotPosition.y - 20,
			32, 40,
			0, 0, 1, 1, declManager->FindMaterial("autolock"));
	}
	else if (autoaimDotState == AUTOAIMDOTSTATE_MOVING_TO_IDLE)
	{
		float lerp = Min(1.0f, (gameLocal.time - autoaimDotTimer) / (float)AUTOAIM_DOT_MOVETIME_IDLE);
		lerp = idMath::CubicEaseOut(lerp);

		autoaimDotPosition.Lerp(autoaimDotStartPos, autoaimDefaultPosition, lerp);

		dotSize = idMath::Lerp(AUTOAIM_DOT_SMALLSIZE, AUTOAIM_DOT_BIGSIZE, lerp);


		if (lerp >= 1)
		{
			autoaimDotState = AUTOAIMDOTSTATE_IDLE;
		}
	}	

	if (autoaimDotState == AUTOAIMDOTSTATE_IDLE)
	{
		dotSize = AUTOAIM_DOT_BIGSIZE;
		dotMaterial = "autoaim_big";
	}
	else if (autoaimDotState == AUTOAIMDOTSTATE_MOVING_TO_IDLE)
		dotMaterial = "autoaim_big_bright";
	else
		dotMaterial = "autoaim_small";

	//Draw the dots.

	//16 = small

	renderSystem->DrawStretchPic(
		autoaimDotPosition.x - ((dotSize * .78f)/2.0f),
		autoaimDotPosition.y - (dotSize/2.0f),
		dotSize * .78f, dotSize,
		0,0,1,1, declManager->FindMaterial(dotMaterial));

	/*
	for (i = 0; i < AUTOAIM_DOTCOUNT; i++)
	{
		renderSystem->DrawStretchPic(
			autoaimDotPositions[i].x - (AUTOAIM_DOT_DRAWSIZE / 2),
			autoaimDotPositions[i].y - (AUTOAIM_DOT_DRAWSIZE / 2),
			AUTOAIM_DOT_DRAWSIZE, AUTOAIM_DOT_DRAWSIZE,
			0, 0, 1, 1, declManager->FindMaterial(dotMaterial));
	}*/

	/*
	if (autoaimDotState == AUTOAIMDOTSTATE_LOCKED)
	{
		//draw the line.
		idVec3 muzzle = weapon.GetEntity()->GetMuzzlePosition(true);
		gameRenderWorld->DebugLine(idVec4(1, .7f, 0, 1), muzzle , autoaimPos, 10, true);
	}*/
}

idVec3 idPlayer::GetWorldToDeviceCoords(const idVec3& worldPos)
{
	// Don't try to translate coordinates before the view exists!
	if (!renderSystem->PrimaryViewExists())
		return vec3_zero;

	idVec3 output;
	renderSystem->GlobalToNormalizedDeviceCoordinates(worldPos, output);
	return output;
}

idVec2 idPlayer::GetWorldToScreen(const idVec3& worldPos)
{
	idVec3 output = GetWorldToDeviceCoords(worldPos);

	if (output.x < 0)
		output.x = ((1 - idMath::Fabs(output.x)) * .5f) * 640.0f;
	else
		output.x = ((output.x * .5f) + .5f) * 640.0f;

	if (output.y > 0)
		output.y = ((1 - idMath::Fabs(output.y)) * .5f) * 480.0f;
	else
		output.y = (idMath::Fabs(output.y * .5f) + .5f)  * 480.0f;

	return idVec2(output.x, output.y);
}

/*
===============
idPlayer::EnterCinematic
===============
*/
void idPlayer::EnterCinematic( void ) {
#ifdef _D3XP
	if ( PowerUpActive( HELLTIME ) ) {
		StopHelltime();
	}
#endif

	//Hide();  //BC don't hide player during cinematics.
	StopAudioLog();
	StopSound( SND_CHANNEL_PDA, false );
	if ( hud ) {
		hud->HandleNamedEvent( "radioChatterDown" );
	}

	physicsObj.SetLinearVelocity( vec3_origin );

	SetState( "EnterCinematic", true );

	if ( weaponEnabled && weapon.GetEntity() ) {
		weapon.GetEntity()->EnterCinematic();
	}

	AI_FORWARD		= false;
	AI_BACKWARD		= false;
	AI_STRAFE_LEFT	= false;
	AI_STRAFE_RIGHT	= false;
	AI_RUN			= false;
	AI_ATTACK_HELD	= false;
	AI_WEAPON_FIRED	= false;
	AI_JUMP			= false;
	AI_CROUCH		= false;
	AI_ONGROUND		= true;
	AI_ONLADDER		= false;
	AI_DEAD			= ( health <= 0 );
	AI_RUN			= false;
	AI_PAIN			= false;
	AI_HARDLANDING	= false;
	AI_SOFTLANDING	= false;
	AI_RELOAD		= false;
	AI_TELEPORT		= false;
	AI_TURN_LEFT	= false;
	AI_TURN_RIGHT	= false;

	AI_HEAL_GLASSWOUND			= false;
	AI_HEAL_BURNING				= false;
	AI_HEAL_BLEEDOUT			= false;
	AI_HEAL_BULLETPLUCK			= false;
	AI_HEAL_HEALWOUND			= false;
	AI_HEAL_SHRAPNEL			= false;
	AI_ACRO_CEILINGHIDE			= false;
	AI_ACRO_SPLITS				= false;
	AI_ACRO_SPLITS_DOWN			= false;
	AI_FALLEN					= false;
	AI_FALLEN_GETUP				= false;
	AI_FALLEN_ROLL				= false;
	AI_HEAL_SPEARPLUCK = false;
}

/*
===============
idPlayer::ExitCinematic
===============
*/
void idPlayer::ExitCinematic( void ) {
	Show();

	if ( weaponEnabled && weapon.GetEntity() ) {
		weapon.GetEntity()->ExitCinematic();
	}

	SetState( "ExitCinematic", true );
}

/*
=====================
idPlayer::UpdateConditions
=====================
*/
void idPlayer::UpdateConditions( void ) {
	idVec3	velocity;
	float	forwardspeed;
	float	sidespeed;

	// minus the push velocity to avoid playing the walking animation and sounds when riding a mover
	velocity = physicsObj.GetLinearVelocity() - physicsObj.GetPushedLinearVelocity();

	if ( influenceActive )
	{
		AI_FORWARD		= false;
		AI_BACKWARD		= false;
		AI_STRAFE_LEFT	= false;
		AI_STRAFE_RIGHT	= false;
	}
	else if ( gameLocal.time - lastDmgTime < 500 ) {
		forwardspeed = velocity * viewAxis[ 0 ];
		sidespeed = velocity * viewAxis[ 1 ];
		AI_FORWARD		= AI_ONGROUND && ( forwardspeed > 20.01f );
		AI_BACKWARD		= AI_ONGROUND && ( forwardspeed < -20.01f );
		AI_STRAFE_LEFT	= AI_ONGROUND && ( sidespeed > 20.01f );
		AI_STRAFE_RIGHT	= AI_ONGROUND && ( sidespeed < -20.01f );
	} else if ( xyspeed > MIN_BOB_SPEED ) {
		AI_FORWARD		= AI_ONGROUND && ( usercmd.forwardmove > 0 );
		AI_BACKWARD		= AI_ONGROUND && ( usercmd.forwardmove < 0 );
		AI_STRAFE_LEFT	= AI_ONGROUND && ( usercmd.rightmove < 0 );
		AI_STRAFE_RIGHT	= AI_ONGROUND && ( usercmd.rightmove > 0 );
	} else {
		AI_FORWARD		= false;
		AI_BACKWARD		= false;
		AI_STRAFE_LEFT	= false;
		AI_STRAFE_RIGHT	= false;
	}

	AI_RUN			= ( usercmd.buttons & BUTTON_RUN ) && ( ( !pm_stamina.GetFloat() ) || ( stamina > pm_staminathreshold.GetFloat() ) );
	AI_DEAD			= ( health <= 0 );


	AI_FALLEN_ROLL = (AI_FALLEN_ROLL && gameLocal.time < fallenRollTimer) && physicsObj.GetFallState() == FALLEN_IDLE && !AI_FALLEN_GETUP;
}

/*
==================
WeaponFireFeedback

Called when a weapon fires, generates head twitches, etc
==================
*/
void idPlayer::WeaponFireFeedback( const idDict *weaponDef ) {
	// force a blink
	blink_time = 0;

	// play the fire animation
	AI_WEAPON_FIRED = true;

	// update view feedback
	playerView.WeaponFireFeedback( weaponDef );
}

/*
===============
idPlayer::StopFiring
===============
*/
void idPlayer::StopFiring( void ) {
	AI_ATTACK_HELD	= false;
	AI_WEAPON_FIRED = false;
	AI_RELOAD		= false;
	if ( weapon.GetEntity() ) {
		weapon.GetEntity()->EndAttack();

		weaponDropCheck();
	}
}

/*
===============
idPlayer::FireWeapon
===============
*/
void idPlayer::FireWeapon( void ) {
	idMat3 axis;
	idVec3 muzzle;

	if ( privateCameraView ) {
		return;
	}

	if ( g_editEntityMode.GetInteger() && !gameEdit->editmenuActive) //If in edit mode...
	{
		GetViewPos(muzzle, axis);
		//if (!gameLocal.editEntities->UpdateDrag(this, muzzle, axis[0])) //BC drag the edit entity (light, sound, etc) around.
		{			
			if (gameLocal.editEntities->SelectEntity(muzzle, axis[0], this)) //BC player left-clicks when they are in edit mode. Select an item...
			{
				return;
			}
		}
	}

	if ( !hiddenWeapon && weapon.GetEntity()->IsReady() )
	{
		//BC Remove the ammo check. Fire weapon if no ammo. Handle dry-fire in script.
		int currentWeapon = inventory.hotbarSlots[currentWeaponSlot].weaponType;
		if ( weapon.GetEntity()->AmmoInClip() || weapon.GetEntity()->AmmoAvailable()  || spawnArgs.GetBool(va("weapon%d_allowempty", currentWeapon )))
		{
			if (!AI_ATTACK_HELD && currentWeapon > 0) //ignore unarmed weapon.
			{
				//event log.
				const char *weaponName;
				if (weapon.GetEntity()->displayName[0] != '\0')
					weaponName = weapon.GetEntity()->displayName.c_str();
				else
					weaponName = weapon.GetEntity()->GetName();



				idStr playerName = (displayName.Length() > 0) ? displayName : idStr(GetName());
				gameLocal.AddEventLog(idStr::Format2(common->GetLanguageDict()->GetString("#str_def_gameplay_attack"), playerName.c_str(), common->GetLanguageDict()->GetString(weaponName)), GetPhysics()->GetOrigin());
			}

			AI_ATTACK_HELD = true;
			weapon.GetEntity()->BeginAttack();
			/*
			if ( ( weapon_soulcube >= 0 ) && ( currentWeapon == weapon_soulcube ) )
			{
				if ( hud ) {
					hud->HandleNamedEvent( "soulCubeNotReady" );
				}
				SelectWeapon( previousWeapon, false );
			}*/

			if (weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
			{
				//For calling in lifeboat. Confirm lifeboat position.

				if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.IsValid())
				{
					if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idBeaconLogic::Type))
					{
						// Ensures that we don't automatically call in the pod if the player was still holding down the final 'dash' of the morse code sequence
						if (!(oldButtons & BUTTON_ATTACK))
						{
							idEntity* signallampEnt = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity();
							static_cast<idBeaconLogic*>(signallampEnt)->FlashConfirm();
						}
						
					}
				}
			}



			

		}
		else
		{
			//No more ammo in this weapon. Switch to a different weapon.
			//NextBestWeapon();

			SelectWeapon(currentWeaponSlot, 0, true);
		}
	}

	if ( hud ) {
		if ( tipUp ) {
			HideTip();
		}
		// may want to track with with a bool as well
		// keep from looking up named events so often
		if ( objectiveUp ) {
			HideObjective();
		}
	}


	

}

/*
===============
idPlayer::CacheWeapons
===============
*/
void idPlayer::CacheWeapons( void ) {
	idStr	weap;

	for ( int i = 0; i < MAX_HOTBARSLOTS; ++i ) {
		int weaponType = inventory.hotbarSlots[i].weaponType;
		if ( weaponType >= 0 ) {
			weap = spawnArgs.GetString( va( "def_weapon%d", weaponType ) );
			if ( weap != "" ) {
				idWeapon::CacheWeapon( weap );
			}
		}
	}
}

/*
===============
idPlayer::Give
===============
*/
bool idPlayer::Give( const char *statname, const char *value, int health, const char *carryableName, idEntity *ent ) {
	int amount;

	if ( AI_DEAD ) {
		return false;
	}

	if ( !idStr::Icmp( statname, "health" ) ) {
		if ( health >= inventory.maxHealth ) {
			return false;
		}
		amount = atoi( value );
		if ( amount ) {
			health += amount;
			if ( health > inventory.maxHealth ) {
				health = inventory.maxHealth;
			}
			if ( hud ) {
				hud->HandleNamedEvent( "healthPulse" );
			}
		}

	} else if ( !idStr::Icmp( statname, "stamina" ) ) {
		if ( stamina >= 100 ) {
			return false;
		}
		stamina += atof( value );
		if ( stamina > 100 ) {
			stamina = 100;
		}

	} else if ( !idStr::Icmp( statname, "heartRate" ) ) {
		heartRate += atoi( value );
		if ( heartRate > MAX_HEARTRATE ) {
			heartRate = MAX_HEARTRATE;
		}

	} else if ( !idStr::Icmp( statname, "air" ) ) {
		if ( airTics >= pm_airTics.GetInteger() ) {
			return false;
		}
		//airTics += atoi( value ) / 100.0f * pm_airTics.GetInteger();
		//if ( airTics > pm_airTics.GetInteger() ) {
		//	airTics = pm_airTics.GetInteger();
		//}


		//BC give air canister, oxygenbubble, use oxygenstation, etc.
		GiveAirtics(atoi(value));
		




	} else if ( !idStr::Icmp( statname, "enviroTime" ) ) {
		if ( PowerUpActive( ENVIROTIME ) ) {
			inventory.powerupEndTime[ ENVIROTIME ] += (atof(value) * 1000);
		} else {
			GivePowerUp( ENVIROTIME, atoi(value)*1000 );
		}
	}
    else if (!idStr::Icmp(statname, "coin"))
    {
        //Player has picked up a coin.
        coins += atoi(value);

        hud->SetStateInt("coins", coins);
        hud->HandleNamedEvent("coinFlash");

		if (ent != NULL)
		{
			idStr coinStr = idStr::Format("+%d coin", atoi(value));
			SetFlytextEvent(ent->GetPhysics()->GetOrigin(), coinStr.c_str(), idDeviceContext::ALIGN_CENTER);
		}
    }
	else if (!idStr::Icmp(statname, "catkey"))
	{
		//Player has picked up a catkey.
		inventory.catkeys += atoi(value);

		if (ent != NULL)
		{
			idStr catkeyStr = "+1 cat key";
			SetFlytextEvent(ent->GetPhysics()->GetOrigin(), catkeyStr.c_str(), idDeviceContext::ALIGN_CENTER);
		}
	}
	else if (!idStr::Icmp(statname, "maintbook"))
	{
		//Player has picked up maintenance book. (ship manual)
		inventory.maintbooks += atoi(value);

		if (ent != NULL)
		{
			hud->HandleNamedEvent("pickupMaintBook");
		}
	}
	else
	{
		return inventory.Give(this, spawnArgs, statname, value, true, carryableName, health, ent);
	}

	return true;
}


/*
===============
idPlayer::GiveHealthPool

adds health to the player health pool
===============
*/
void idPlayer::GiveHealthPool( float amt ) {
	if (AI_DEAD) {
		return;
	}

	if (health > 0) {
		healthPool += amt;
		if (healthPool > inventory.maxHealth - health) {
			healthPool = inventory.maxHealth - health;
		}
		nextHealthPulse = gameLocal.time;
	}
}

//bool idPlayer::GiveHealthAdjustedMax()
//{
//	if (AI_DEAD || health <= 0) {
//		return false;
//	}
//
//	int adjustedMaxHealth = inventory.maxHealth;
//	adjustedMaxHealth -= GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK;
//	if (health >= adjustedMaxHealth)
//		return false;
//
//	healthPool = (adjustedMaxHealth - health);
//	if (healthPool > inventory.maxHealth - health) {
//		healthPool = inventory.maxHealth - health;
//	}
//	nextHealthPulse = gameLocal.time;
//	return true;
//}

//This is for the health healing cloud.
bool idPlayer::GiveHealthAdjustedMax()
{
	//Verify player can accept more health.
	if (AI_DEAD || health <= 0) {
		return false;
	}
	
	int adjustedMaxHealth = inventory.maxHealth;
	adjustedMaxHealth -= GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK;
	if (health >= adjustedMaxHealth)
		return false;

	healthcloudActive = true;
	healthcloudTimer = gameLocal.time + 500;
	healthrechargeTimer = 0;
	return true;
}

//After heal a major wound, heal the next health block.
void idPlayer::WoundRegenerateHealthblock()
{
	int adjustedMaxHealth = inventory.maxHealth;
	adjustedMaxHealth -= GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK;
	if (health >= adjustedMaxHealth)
		return; //health is maxed out; cannot give anything more.

	health = ((health + 9) / 10 * 10) + 1; //give 1 HP to the next health block to kickstart the recharge logic.
	health = Min(health, adjustedMaxHealth);
	healthrechargeTimer = 0; //instantly start recharging the health block ; don't wait for the recharge time to fill up.
}

//This is used for the drinking fountain.
//Gives a tiny bit of health and resets the health recharge timer.
void idPlayer::GiveHealthGranular(int amount)
{
	if (AI_DEAD || health <= 0) {
		return;
	}

	int adjustedMaxHealth = inventory.maxHealth;
	adjustedMaxHealth -= GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK;
	if (health >= adjustedMaxHealth)
		return; //already maxed out.

	health = Min(health + amount, adjustedMaxHealth);
	healthrechargeTimer = gameLocal.time + (cond_shrapnel > 0 ? HEALTH_RECHARGE_INITIALDELAY_SHRAPNELWOUND : HEALTH_RECHARGE_INITIALDELAY);
	readyForHealthrechargeSound = true;
}

void idPlayer::GiveBleedoutHealth(int amount)
{
	#define BLEEDOUT_HEALTHMAX 100
	if (AI_DEAD || health <= 0 || !inDownedState)	
		return;
	
	if (health >= BLEEDOUT_HEALTHMAX)
		return; //already maxed out.

	health = Min(health + amount, BLEEDOUT_HEALTHMAX);
	downedTickTimer = gameLocal.time + 300; //reset the bleedout tick timer so that the bleedout DOT doesn't interfere with this.

	if (health >= BLEEDOUT_HEALTHMAX)
	{
		inDownedState = false;
		viewAngles.roll = 0;
		SetViewAngles(idAngles(0, viewAngles.yaw, 0));
		bloodbagState = BLOODBAGSTATE_EXITING;

		//activate health recharge.
		health = maxHealth - (GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK); //max health.
		healthrechargeTimer = gameLocal.time;
		savingthrowState = SAVINGTHROW_AVAILABLE; //make saving throw immediately available again.

		hud->HandleNamedEvent("fullofblood");

		ForceShowHealthbar(0);

		SayVO_WithIntervalDelay_msDelayed("snd_vo_bloodfill", 500);

	}
}


/*
===============
idPlayer::GiveItem

Returns false if the item shouldn't be picked up
===============
*/
bool idPlayer::GiveItem( idItem *item ) {
	int					i;
	const idKeyValue	*arg;
	idDict				attr;
	bool				gave;

	if ( gameLocal.isMultiplayer && spectating ) {
		return false;
	}

	item->GetAttributes( attr );

	gave = false;
	for( i = 0; i < attr.GetNumKeyVals(); i++ )
	{
		arg = attr.GetKeyVal( i );
        //BC debug for exactly what an item gives the player. This iterates over the different keyvalues on an item pick up. Pick up an item and it'll spit out this debug...
        //common->Printf("Gave: '%s'  value: '%s'\n", arg->GetKey().c_str(), arg->GetValue().c_str());		

		if ( Give( arg->GetKey(), arg->GetValue(), (item != NULL) ? item->health : -1, (item != NULL) ? item->displayName.c_str() : "", item ) ) {
			gave = true;
		}
	}

	arg = item->spawnArgs.MatchPrefix( "inv_weapon", NULL );
	if ( arg && hud ) {
		// We need to update the weapon hud manually, but not
		// the armor/ammo/health because they are updated every
		// frame no matter what
		UpdateHudWeapon( false );
		hud->HandleNamedEvent( "weaponPulse" );
	}

	// display the pickup feedback on the hud
	//if (gave && (numPickup == inventory.pickupItemNames.Num())) //only display if you don't already own the weapon
	//if (gave) //BC always display name of weapon pickup when you pick up weapon.
	//{
	//	inventory.AddPickupName( item->spawnArgs.GetString( "inv_name" ), item->spawnArgs.GetString( "inv_icon" ), this ); //_D3XP
	//}


	

	return gave;
}

//Special weapon drop for when you swap weapons.
void idPlayer::SwapDropWeapon(int hotbarSlot, const char *newWeaponToSelect, idEntity* newEnt)
{
	if (spectating || weaponGone || weapon.GetEntity() == NULL)
	{
		return;
	}

	//todo: put ammo from mag back into player ammo repository, to be nice to player.


	//See if the swapped-out item is a carryable.
	int currentWeapon = inventory.hotbarSlots[currentWeaponSlot].weaponType;
	if (spawnArgs.GetBool(va("weapon%d_carryable", currentWeapon)))
	{
		//Player wants to swap out their currently-active carryable.
		
		//Spawn it the thing to drop.
		if (inventory.hotbarSlots[hotbarSlot].carryPtr.IsValid())
		{
			DropCurrentCarryable( newEnt, false );
		}
		//Event_SelectWeapon(newWeaponToSelect); //Select the weapon player just picked up.
	}
	else
	{
		//Player is swapping out a WEAPON and picking something else up...
		DropCurrentWeapon( newEnt );
		//Event_SelectWeapon(newWeaponToSelect); //Select the weapon player just picked up.
	}
}

void idPlayer::DropCurrentWeapon(idEntity* dropEntTo)
{
	//idEntity *droppedItem = NULL;

	int equippedSlot = inventory.GetHotbarSelection();
// 	if (weapon.GetEntity()->spawnArgs.GetBool("isgrenade"))
// 	{
// 		//This is a grenade that may have a stack of multiple items.
// 
// 		//Remove all ammo from inventory.
// 		ammo_t ammo_i = inventory.AmmoIndexForWeaponClass(spawnArgs.GetString(va("def_weapon%d", inventory.hotbarSlots[equippedSlot].weaponType)), NULL);
// 		inventory.ammo[ammo_i] = 0; //Remove all ammo.

// 		for (int i = 0; i < ammoStackTotal; i++)
// 		{
// 			droppedItem = DropCurrentWeapon_SingleItem(i);
// 		}
//	}
// 	else
// 	{
// 		//No stack. Just a single item, like a shotgun or rifle.
// 		droppedItem = DropCurrentWeapon_SingleItem(0);
// 	}
	
	DropCurrentWeapon_SingleItem( 0, dropEntTo );
	//if (droppedItem != NULL)
	//{
	//	SetCenterMessage(va("Dropped %s", droppedItem->displayName.c_str()));
	//}

	inventory.Drop( equippedSlot );
	SetHotbarSlot(equippedSlot, 0, "", 0, NULL); //set unarmed.

	//int ammoInMag = weapon.GetEntity()->AmmoInClip(); //How much rounds in magazine. //BC todo: put these ammo rounds into player ammo repository?
	weapon.GetEntity()->ResetAmmoClip();
	//Event_SelectWeapon("weapon_unarmed"); //goto unarmed weapon.
	weapon.GetEntity()->WeaponStolen();
	currentWeaponSlot = -1;
	weaponGone = true;
}

//Call this to drop a specific entity from the player's inventory. The Aloe heal uses this.
bool idPlayer::DropCarryable(idEntity *ent)
{
	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		if (!inventory.hotbarSlots[i].carryPtr.IsValid())
			continue;

		if (!inventory.hotbarSlots[i].carryPtr.GetEntity())
			continue;

		if (inventory.hotbarSlots[i].carryPtr.GetEntityNum() == ent->entityNumber)
		{
			RemoveCarryableFromHotbar(i);
			return true;
		}
	}

	return false;

}

idEntity * idPlayer::DropCurrentWeapon_SingleItem(int index, idEntity* dropEntTo)
{
	idEntity *item = NULL;
	idVec3 up, right;

	viewAngles.ToVectors(NULL, &right, &up);
	item = weapon.GetEntity()->DropItem(up * 2.0f, 0, -1, false, false);
	if (item)
	{
		item->SetAxis(mat3_identity);

		//make it spawn close to the ground.

		#define STACK_GAP 6

		//check if player looking at trash chute.
		idVec3 dropPosition = vec3_zero;
		if (trashchuteFocus.IsValid())
		{
			//Drop onto trash chute.
			idVec3 trashplatformPos = trashchuteFocus.GetEntity()->GetPhysics()->GetOrigin();

			idVec3 itemDropPos = trashplatformPos + (right * (STACK_GAP * index));
			itemDropPos.z += 2; //raise up to the top of trash platform's surface.
			itemDropPos.z += idMath::Fabs(item->GetPhysics()->GetBounds().zMin());
			itemDropPos.z += .5f; //extra buffer space.

			dropPosition = itemDropPos;
			idAngles chuteAngle = trashchuteFocus.GetEntity()->GetPhysics()->GetAxis().ToAngles();
			chuteAngle.yaw += 90;
			item->GetPhysics()->SetAxis(chuteAngle.ToMat3());
		}
		else
		{
			//Drop to ground.
			trace_t dropTr;
			idVec3 itemPos = item->GetPhysics()->GetOrigin();
			if ( dropEntTo )
			{
				itemPos = dropEntTo->GetPhysics()->GetOrigin();
			}
			itemPos += ( right * ( STACK_GAP * index ) );
			float itemTop = item->GetPhysics()->GetBounds().zMax();
			float itemBottom = item->GetPhysics()->GetBounds().zMin();
			gameLocal.clip.TraceBounds(
				dropTr,
				// We start tracing from the *top* of the item, so it doesn't fall through the floor if we place it while crouching
				// SM: Need to add an offset of 10 to z to account for tiny z bounds on many weapons
				itemPos + idVec3(0, 0, itemTop) + idVec3(0, 0, 10),
				itemPos + idVec3(0, 0, itemBottom) + idVec3(0, 0, -70),
				item->GetPhysics()->GetBounds(),
				MASK_SOLID,
				this
			);
			dropPosition = dropTr.endpos + idVec3(0, 0, .5f);
		}

		item->GetPhysics()->SetOrigin(dropPosition);
		if (item->IsType(idItem::Type))
		{
			static_cast<idItem *>(item)->SetJustDropped(true);
		}

		//Update the item with appropriate health.
		item->health = inventory.hotbarSlots[inventory.GetHotbarSelection()].health;
		return item;
	}

	return NULL;
}



bool idPlayer::SetHotbarSlot(int slotIndex, int weaponIndex, const char *weaponName, int health, idEntity *ent)
{
	//Update the hud.	
	this->hud->SetStateString(va("hotbarname%d", slotIndex), common->GetLanguageDict()->GetString( weaponName ) );

	if (weaponName[0])
	{
		this->hud->HandleNamedEvent(va("hotbarflash%d", slotIndex));
	}

	return inventory.SetHotbarSlot(this, slotIndex, weaponIndex, health, ent);
}

// SW: Tutorial method for emptying the player's inventory of troublesome items
// Note that this destroys the items -- it does not force the player to drop them
void idPlayer::Event_ClearInventory(void)
{
	//for (int i = 0; i < inventory.hotbarUnlockedSlots; i++)
	//{
	//	if (inventory.hotbarSlots[i].carryPtr.IsValid())
	//	{
	//		inventory.hotbarSlots[i].carryPtr.GetEntity()->ProcessEvent(&EV_Remove);
	//	}
	//	this->hud->SetStateString(va("hotbarname%d", i), "");
	//
    //    inventory.Drop(i);
	//}
    //
    //weapon.GetEntity()->WeaponStolen();
    //weaponGone = true;

	
	ThrowCurrentWeapon();

	for (int i = 0; i < Min(MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots); i++)
	{
		if (inventory.hotbarSlots[i].carryPtr.IsValid())
		{			
			//Remove item.
			idEntityPtr<idEntity>	itemPtr = inventory.hotbarSlots[i].carryPtr;
			RemoveCarryableFromHotbar(i);
			if (itemPtr.IsValid())
			{
				itemPtr.GetEntity()->PostEventMS(&EV_Remove, 0);
			}
		}
	}
}

bool idPlayer::SelectHotbarslot(int slotIndex)
{
	if (usercmd.buttons & BUTTON_QUICKTHROW || IsLeaning() || iteminspectActive
		|| mechTransitionState != MECHTRANSITION_NONE || physicsObj.GetAcroType() != ACROTYPE_NONE)
	{
		return false;
	}

	

	if (armstatsActive)
	{
		SetArmStatsActive(false);
	}

	if (grenadeThrowState == GRENADETHROW_AIMING || zoommodeActive)
		return false;

	if (slotIndex >= inventory.hotbarUnlockedSlots)
	{
		StartSound("snd_error", SND_CHANNEL_ANY, 0, false, NULL);
		return false; //player attempting to access beyond the available slots.
	}

	//Attempt to select the weapon in the hotbar slot.
	int desiredWeapon = inventory.hotbarSlots[slotIndex].weaponType; //Get the weapon index that's in the slot.
	desiredWeapon = Max(desiredWeapon, 0);
	
	if (desiredWeapon <= 0)
	{
		StartSound("snd_click", SND_CHANNEL_ANY);
	}

	this->lastSelectedHotbarslot = slotIndex;
	int currentWeapon = inventory.hotbarSlots[slotIndex].weaponType;
	if (currentWeapon <= 0) //If unarmed, then force the hotbar ui update. This is to fix the funkiness when the player selects different Empty hotbar slots in a row.
		UpdateHotbarHighlight(true);

	this->hud->HandleNamedEvent(va("hotbar_btnpop%d", slotIndex));

	SelectWeapon(slotIndex, desiredWeapon, false);
	return true;
}


void idPlayer::UpdateHotbarHighlight(bool activate)
{
	if (activate)
	{
		if (!weapon.IsValid())
			return;



		//Figure out which slot we want to highlight.
		int slotToHighlight = currentWeaponSlot;
		

		//See if player is trying to select an empty slot.
		if (this->lastSelectedHotbarslot < inventory.hotbarUnlockedSlots &&  this->lastSelectedHotbarslot >= 0 && inventory.hotbarSlots[this->lastSelectedHotbarslot].weaponType < 0)
		{
			slotToHighlight = this->lastSelectedHotbarslot;
		}

		if (slotToHighlight >= 0)
		{
			inventory.SetHotbarSelection(slotToHighlight);

			for (int i = 0; i < MAX_HOTBARSLOTS; i++)
			{
				this->hud->SetStateBool(va("hotbarselected%d", i), (i == slotToHighlight) ? true : false);
			}
		}
	}
	else
	{
		//activate = false. just turn everything off.

		for (int i = 0; i < MAX_HOTBARSLOTS; i++)
		{
			this->hud->SetStateBool(va("hotbarselected%d", i), false);
		}
	}
}



/*
===============
idPlayer::PowerUpModifier
===============
*/
float idPlayer::PowerUpModifier( int type ) {
	float mod = 1.0f;

	if ( PowerUpActive( BERSERK ) ) {
		switch( type ) {
			case SPEED: {
				mod *= 1.7f;
				break;
			}
			case PROJECTILE_DAMAGE: {
				mod *= 2.0f;
				break;
			}
			case MELEE_DAMAGE: {
				mod *= 30.0f;
				break;
			}
			case MELEE_DISTANCE: {
				mod *= 2.0f;
				break;
			}
		}
	}

	if (mechTransitionState == MECHTRANSITION_PILOTING)
	{
		mod = .5f; //BC mech speed modifier
	}

	if ( gameLocal.isMultiplayer && !gameLocal.isClient )
	{
		if ( PowerUpActive( MEGAHEALTH ) ) {
			if ( healthPool <= 0 ) {
				GiveHealthPool( 100 );
			}
		} else {
			healthPool = 0;
		}
	}

	if (PowerUpActive(HASTE))
	{
		switch (type)
		{
			case SPEED:
			{
				mod = 1.7f;
				break;
			}
		}
	}

	return mod;
}

/*
===============
idPlayer::PowerUpActive
===============
*/
bool idPlayer::PowerUpActive( int powerup ) const {
	return ( inventory.powerups & ( 1 << powerup ) ) != 0;
}

/*
===============
idPlayer::GivePowerUp
===============
*/
bool idPlayer::GivePowerUp( int powerup, int time ) {
	const char *sound;
	const char *skin;

	if ( powerup >= 0 && powerup < MAX_POWERUPS )
	{

		if ( gameLocal.isServer )
		{
			idBitMsg	msg;
			byte		msgBuf[MAX_EVENT_PARAM_SIZE];

			msg.Init( msgBuf, sizeof( msgBuf ) );
			msg.WriteShort( powerup );
			msg.WriteBits( 1, 1 );
			ServerSendEvent( EVENT_POWERUP, &msg, false, -1 );
		}

		if ( powerup != MEGAHEALTH )
		{
			//Give the powerup.
			inventory.GivePowerUp( this, powerup, time );
		}

		const idDeclEntityDef *def = NULL;

		switch( powerup ) {
			case BERSERK: {
				if(gameLocal.isMultiplayer && !gameLocal.isClient) {
					inventory.AddPickupName("#str_00100627", "", this);
				}

				if(gameLocal.isMultiplayer) {
					if ( spawnArgs.GetString( "snd_berserk_third", "", &sound ) ) {
						StartSoundShader( declManager->FindSound( sound ), SND_CHANNEL_DEMONIC, 0, false, NULL );
					}
				}


				if ( baseSkinName.Length() ) {
					powerUpSkin = declManager->FindSkin( baseSkinName + "_berserk" );
				}
				if ( !gameLocal.isClient ) {
#ifdef _D3XP
					if( !gameLocal.isMultiplayer ) {
						// Trying it out without the health boost (1/3/05)
						// Give the player full health in single-player
						// health = 100;
					} else {
						// Switch to fists in multiplayer
						//idealWeapon = 1;
					}
#else
					idealWeapon = 0;
#endif
				}
				break;
			}
			case INVISIBILITY: {
				if(gameLocal.isMultiplayer && !gameLocal.isClient) {
					inventory.AddPickupName("#str_00100628", "", this);
				}
				spawnArgs.GetString( "skin_invisibility", "", &skin );
				powerUpSkin = declManager->FindSkin( skin );
				// remove any decals from the model
				if ( modelDefHandle != -1 ) {
					gameRenderWorld->RemoveDecals( modelDefHandle );
				}
				if ( weapon.GetEntity() ) {
					weapon.GetEntity()->UpdateSkin();
				}
/*				if ( spawnArgs.GetString( "snd_invisibility", "", &sound ) ) {
					StartSoundShader( declManager->FindSound( sound ), SND_CHANNEL_ANY, 0, false, NULL );
				} */
				break;
			}
			case ADRENALINE: {
#ifdef _D3XP
				inventory.AddPickupName("#str_00100799", "", this);
#endif
				stamina = 100.0f;
				break;
			 }
			case MEGAHEALTH: {
				if(gameLocal.isMultiplayer && !gameLocal.isClient) {
					inventory.AddPickupName("#str_00100629", "", this);
				}
				if ( spawnArgs.GetString( "snd_megahealth", "", &sound ) ) {
					StartSoundShader( declManager->FindSound( sound ), SND_CHANNEL_ANY, 0, false, NULL );
				}
				def = gameLocal.FindEntityDef( "powerup_megahealth", false );
				if ( def ) {
					health = def->dict.GetInt( "inv_health" );
				}
				break;
			 }
#ifdef _D3XP
			case HELLTIME:
			{
				if ( spawnArgs.GetString( "snd_helltime_start", "", &sound ) )
				{
					PostEventMS( &EV_StartSoundShader, 0, sound, SND_CHANNEL_ANY );
				}
				if ( spawnArgs.GetString( "snd_helltime_loop", "", &sound ) )
				{
					PostEventMS( &EV_StartSoundShader, 0, sound, SND_CHANNEL_DEMONIC );
				}
				break;
			}
			case ENVIROSUIT: {
				// Turn on the envirosuit sound
				if ( gameSoundWorld ) {
					gameSoundWorld->SetEnviroSuit( true );
				}

				// Put the helmet and lights on the player
				idDict	args;

				// Light
				const idDict *lightDef = gameLocal.FindEntityDefDict( "envirosuit_light", false );
				if ( lightDef ) {
					idEntity *temp;
					gameLocal.SpawnEntityDef( *lightDef, &temp, false );

					idLight *eLight = static_cast<idLight *>(temp);
					eLight->GetPhysics()->SetOrigin( firstPersonViewOrigin );
					eLight->UpdateVisuals();
					eLight->Present();

					enviroSuitLight = eLight;
				}
				break;
			}
			case ENVIROTIME: {
				hudPowerup = ENVIROTIME;
				// The HUD display bar is fixed at 60 seconds
				hudPowerupDuration = 60000;
				break;
			}
			case INVULNERABILITY: {
				if(gameLocal.isMultiplayer && !gameLocal.isClient) {
					inventory.AddPickupName("#str_00100630", "", this);
				}
				if(gameLocal.isMultiplayer) {
					/*if ( spawnArgs.GetString( "snd_invulnerable", "", &sound ) ) {
						StartSoundShader( declManager->FindSound( sound ), SND_CHANNEL_DEMONIC, 0, false, NULL );
					}*/
					if ( baseSkinName.Length() ) {
						powerUpSkin = declManager->FindSkin( baseSkinName + "_invuln" );
					}
				}
				break;
			}
			/*case HASTE: {
				if(gameLocal.isMultiplayer && !gameLocal.isClient) {
					inventory.AddPickupName("#str_00100631", "", this);
				}

				if ( baseSkinName.Length() ) {
					powerUpSkin = declManager->FindSkin( baseSkinName + "_haste" );
				}
				break;
			}*/
#endif
		}

		if ( hud ) {
			hud->HandleNamedEvent( "itemPickup" );
		}

		return true;
	} else {
		gameLocal.Warning( "Player given power up %i\n which is out of range", powerup );
	}
	return false;
}

/*
==============
idPlayer::ClearPowerup
==============
*/
void idPlayer::ClearPowerup( int i ) {

	if ( gameLocal.isServer ) {
		idBitMsg	msg;
		byte		msgBuf[MAX_EVENT_PARAM_SIZE];

		msg.Init( msgBuf, sizeof( msgBuf ) );
		msg.WriteShort( i );
		msg.WriteBits( 0, 1 );
		ServerSendEvent( EVENT_POWERUP, &msg, false, -1 );
	}

	powerUpSkin = NULL;
	inventory.powerups &= ~( 1 << i );
	inventory.powerupEndTime[ i ] = 0;
	switch( i ) {
		case BERSERK: {
			if(gameLocal.isMultiplayer) {
				StopSound( SND_CHANNEL_DEMONIC, false );
			}
#ifdef _D3XP
			
#endif
			break;
		}
		case INVISIBILITY: {
			if ( weapon.GetEntity() ) {
				weapon.GetEntity()->UpdateSkin();
			}
			break;
		}
#ifdef _D3XP
		case HELLTIME: {
			StopSound( SND_CHANNEL_DEMONIC, false );
			break;
		}
		case ENVIROSUIT: {

			hudPowerup = -1;

			// Turn off the envirosuit sound
			if ( gameSoundWorld ) {
				gameSoundWorld->SetEnviroSuit( false );
			}

			// Take off the helmet and lights
			if ( enviroSuitLight.IsValid() ) {
				enviroSuitLight.GetEntity()->PostEventMS( &EV_Remove, 0 );
			}
			enviroSuitLight = NULL;
			break;
		}
		case INVULNERABILITY: {
			if(gameLocal.isMultiplayer) {
				StopSound( SND_CHANNEL_DEMONIC, false );
			}
		}
		/*case HASTE: {
			if(gameLocal.isMultiplayer) {
				StopSound( SND_CHANNEL_DEMONIC, false );
			}
		}*/
#endif
	}
}

/*
==============
idPlayer::UpdatePowerUps
==============
*/
void idPlayer::UpdatePowerUps( void ) {
	int i;

	if ( !gameLocal.isClient )
	{
		for ( i = 0; i < MAX_POWERUPS; i++ )
		{
#ifdef _D3XP
			if ( ( inventory.powerups & ( 1 << i ) ) && inventory.powerupEndTime[i] > gameLocal.time ) {
				switch( i )
				{
					case ENVIROSUIT: {
						if ( enviroSuitLight.IsValid() ) {
							idAngles lightAng = firstPersonViewAxis.ToAngles();
							idVec3 lightOrg = firstPersonViewOrigin;
							const idDict *lightDef = gameLocal.FindEntityDefDict( "envirosuit_light", false );

							idVec3 enviroOffset = lightDef->GetVector( "enviro_offset" );
							idVec3 enviroAngleOffset = lightDef->GetVector( "enviro_angle_offset" );

							lightOrg += (enviroOffset.x * firstPersonViewAxis[0]);
							lightOrg += (enviroOffset.y * firstPersonViewAxis[1]);
							lightOrg += (enviroOffset.z * firstPersonViewAxis[2]);
							lightAng.pitch += enviroAngleOffset.x;
							lightAng.yaw += enviroAngleOffset.y;
							lightAng.roll += enviroAngleOffset.z;

							enviroSuitLight.GetEntity()->GetPhysics()->SetOrigin( lightOrg );
							enviroSuitLight.GetEntity()->GetPhysics()->SetAxis( lightAng.ToMat3() );
							enviroSuitLight.GetEntity()->UpdateVisuals();
							enviroSuitLight.GetEntity()->Present();
						}
						break;
					}
					default: {
						break;
					}
				}
			}
#endif

			//BC code that updates the timers on powerups.
			if ( PowerUpActive( i ) && inventory.powerupEndTime[i] <= gameLocal.fast.time )
			{
				ClearPowerup( i );
			}
		}
	}

	if ( health > 0 )
	{
		if ( powerUpSkin ) {
			renderEntity.customSkin = powerUpSkin;
		} else {
			renderEntity.customSkin = skin;
		}
	}

	if ( healthPool && gameLocal.time > nextHealthPulse && !AI_DEAD && health > 0 ) {
		assert( !gameLocal.isClient );	// healthPool never be set on client
		int amt = ( healthPool > 5 ) ? 5 : healthPool;
		health += amt;
		if ( health > inventory.maxHealth ) {
			health = inventory.maxHealth;
			healthPool = 0;
		} else {
			healthPool -= amt;
		}
		nextHealthPulse = gameLocal.time + HEALTHPULSE_TIME;
		healthPulse = true;
	}

	if ( !gameLocal.inCinematic && influenceActive == 0 && g_skill.GetInteger() == 3 && gameLocal.time > nextHealthTake && !AI_DEAD && health > g_healthTakeLimit.GetInteger() )
	{
		assert( !gameLocal.isClient );	// healthPool never be set on client

#ifdef _D3XP
		if(!PowerUpActive(INVULNERABILITY)) {
#endif
		health -= g_healthTakeAmt.GetInteger();
		if ( health < g_healthTakeLimit.GetInteger() ) {
			health = g_healthTakeLimit.GetInteger();
		}
#ifdef _D3XP
		}
#endif
		nextHealthTake = gameLocal.time + g_healthTakeTime.GetInteger() * 1000;
		healthTake = true;
	}
}

/*
===============
idPlayer::ClearPowerUps
===============
*/
void idPlayer::ClearPowerUps( void ) {
	int i;
	for ( i = 0; i < MAX_POWERUPS; i++ ) {
		if ( PowerUpActive( i ) ) {
			ClearPowerup( i );
		}
	}
	inventory.ClearPowerUps();

#ifdef _D3XP
	if ( gameLocal.isMultiplayer ) {
		if ( enviroSuitLight.IsValid() ) {
			enviroSuitLight.GetEntity()->PostEventMS( &EV_Remove, 0 );
		}
	}
#endif
}

/*
===============
idPlayer::GiveInventoryItem
===============
*/
bool idPlayer::GiveInventoryItem( idDict *item ) {
	if ( gameLocal.isMultiplayer && spectating ) {
		return false;
	}
	inventory.items.Append( new idDict( *item ) );


	//BC the infofeed stuff is now handled in item.cpp GiveToPlayer()
	//idItemInfo info;
	//const char* itemName = item->GetString( "inv_name" );
	//if ( idStr::Cmpn( itemName, STRTABLE_ID, STRTABLE_ID_LENGTH ) == 0 ) {
	//	info.name = common->GetLanguageDict()->GetString( itemName );
	//} else {
	//	info.name = itemName;
	//}
	//info.icon = item->GetString( "inv_icon" );
	//inventory.pickupItemNames.Append( info ); //This adds to the item pickup list UI on the right side of the screen.
	//if ( hud ) {
	//	hud->SetStateString( "itemicon", info.icon );
	//	hud->HandleNamedEvent( "invPickup" );
	//}

#ifdef _D3XP //Added to support powercells
	if(item->GetInt("inv_powercell") && focusUI) {
		//Reset the powercell count
		int powerCellCount = 0;
		for ( int j = 0; j < inventory.items.Num(); j++ ) {
			idDict *item = inventory.items[ j ];
			if(item->GetInt("inv_powercell")) {
				powerCellCount++;
			}
		}
		focusUI->SetStateInt( "powercell_count", powerCellCount );
	}
#endif

	return true;
}

#ifdef _D3XP //BSM: Implementing this defined function for scripted give inventory items
/*
==============
idPlayer::GiveInventoryItem
==============
*/
bool idPlayer::GiveInventoryItem( const char *name ) {
	//idDict args;
	//
	//args.Set( "classname", name );
	//args.Set( "owner", this->name.c_str() );
	//gameLocal.SpawnEntityDef( args);
	//return true;

	//BC our changes break the default giveItem command. So....
	GiveItem(name);
	return true;
}
#endif

void idPlayer::CurrentEmailReplied()
{
	int currentPDA = objectiveSystem->State().GetInt("listPDA_sel_0", "0");
	if (currentPDA == -1) {
		currentPDA = 0;
	}

	if (currentPDA < inventory.pdas.Num())
	{
		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[currentPDA], false));
		int currentEmail = objectiveSystem->State().GetInt("listPDAEmail_sel_0", "-1");
		if (currentEmail >= 0)
		{
			const idDeclEmail* email = pda->GetEmailByIndex(currentEmail);
			idStr emailName = email->GetName();
			objectiveSystem->SetStateBool("replybuttonvisible1", false);
			objectiveSystem->SetStateBool("replybuttonvisible2", false);
			pda->AddEmailReplied(emailName);
			
			idStr inventoryName = pda->GetName();
			inventoryName += ";";
			inventoryName += emailName;
			inventory.emailsReplied.AddUnique(inventoryName);
		}
	}
}

/*
==============
idPlayer::UpdateObjectiveInfo
==============
 */
void idPlayer::UpdateObjectiveInfo( void ) {
	if ( objectiveSystem == NULL ) {
		return;
	}
	objectiveSystem->SetStateString( "objective1", "" );
	objectiveSystem->SetStateString( "objective2", "" );
	objectiveSystem->SetStateString( "objective3", "" );
	for ( int i = 0; i < inventory.objectiveNames.Num(); i++ ) {
		objectiveSystem->SetStateString( va( "objective%i", i+1 ), "1" );
		objectiveSystem->SetStateString( va( "objectivetitle%i", i+1 ), inventory.objectiveNames[i].title.c_str() );
		objectiveSystem->SetStateString( va( "objectivetext%i", i+1 ), inventory.objectiveNames[i].text.c_str() );
		objectiveSystem->SetStateString( va( "objectiveshot%i", i+1 ), inventory.objectiveNames[i].screenshot.c_str() );
	}
	objectiveSystem->StateChanged( gameLocal.time );
}

/*
===============
idPlayer::GiveObjective
===============
*/
void idPlayer::GiveObjective( const char *title, const char *text, const char *screenshot ) {
	idObjectiveInfo info;
	info.title = title;
	info.text = text;
	info.screenshot = screenshot;
	inventory.objectiveNames.Append( info );
	ShowObjective( "newObjective" );
	if ( hud ) {
		hud->HandleNamedEvent( "newObjective" );
	}
}

/*
===============
idPlayer::CompleteObjective
===============
*/
void idPlayer::CompleteObjective( const char *title ) {
	int c = inventory.objectiveNames.Num();
	for ( int i = 0;  i < c; i++ ) {
		if ( idStr::Icmp(inventory.objectiveNames[i].title, title) == 0 ) {
			inventory.objectiveNames.RemoveIndex( i );
			break;
		}
	}
	ShowObjective( "newObjectiveComplete" );

	if ( hud ) {
		hud->HandleNamedEvent( "newObjectiveComplete" );
	}
}

/*
===============
idPlayer::GiveVideo
===============
*/
void idPlayer::GiveVideo( const char *videoName, idDict *item ) {

	if ( videoName == NULL || *videoName == 0 ) {
		return;
	}

	inventory.videos.AddUnique( videoName );

	if ( item ) {
		gameLocal.DisplayEventLogAlert( item->GetString( "inv_name" ), item->GetString( "inv_icon" ) );
	}
	if ( hud ) {
		hud->HandleNamedEvent( "videoPickup" );
	}
}

/*
===============
idPlayer::GiveSecurity
===============
*/
void idPlayer::GiveSecurity( const char *security ) {
	GetPDA()->SetSecurity( security );
	if ( hud ) {
		hud->SetStateString( "pda_security", "1" );
		hud->HandleNamedEvent( "securityPickup" );
	}
}

void idPlayer::Event_GiveEmail(const char* emailName)
{
	const idDeclPDA* pda = GetPDA();

	if (pda == nullptr)
	{
		GivePDA("personal", NULL);
	}

	GiveEmail(emailName);

	UpdatePDAInfo(true);
}

void idPlayer::Event_GiveEmailViaTalker(const char* talkerName, const char* emailName, int autoSelect)
{
	idEntity* ent = gameLocal.FindEntity("prop_emailmonitor"); //bc ugh this is a kludge.......
	if (ent)
	{
		ent->StartSound("snd_email_new", SND_CHANNEL_ANY);
	}

	GiveEmailViaTalker(talkerName, emailName, autoSelect == 1);
	UpdatePDAInfo(false);
}

void idPlayer::Event_HasEmail(const char* emailname)
{
	for (int j = 0; j < inventory.pdas.Num(); j++)
	{
		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[j], false));

		if (pda == NULL)
			continue;

		if (pda->IsEmailExist(emailname))
		{
			idThread::ReturnInt(1);
			return;
		}
	}

	idThread::ReturnInt(0);
}

void idPlayer::Event_HasReadEmail(const char* emailname)
{
	for (int j = 0; j < inventory.pdas.Num(); j++)
	{
		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[j], false));

		if (pda == NULL)		
			continue;

		if (pda->IsEmailRead(emailname))
		{
			idThread::ReturnInt(1);
			return;
		}
	}

	idThread::ReturnInt(0);
}

//This is for the notification dot on the back arrow in the email gui screen.
bool idPlayer::HasUnreadEmail_ExceptSpecifiedInbox(int inboxIndex)
{
	for (int j = 0; j < inventory.pdas.Num(); j++)
	{
		if (j == inboxIndex)
			continue; //ignore the specified inbox.

		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[j], false));

		if (pda == NULL)
			continue;

		int numEmails = pda->GetNumEmails();
		if (numEmails > 0)
		{
			for (int i = 0; i < numEmails; i++)
			{
				const idDeclEmail* email = pda->GetEmailByIndex(i);

				if (!pda->IsEmailRead(email->GetName()))
				{
					//Email is UNREAD and is in an inbox that is not the specified email inbox.
					return true;
				}
			}
		}		
	}

	return false;
}

/*
===============
idPlayer::GiveEmail
===============
*/
void idPlayer::GiveEmail(const char *emailName ) {

	if ( emailName == NULL || emailName[0] == '\0')
	{
		gameLocal.Warning("GiveEmail: failed to give email.\n");
		return;
	}

	idStr emailSanitized = emailName;
	emailSanitized.ToLower();

	idStr emailInventoryName = "default;";
	emailInventoryName += emailSanitized;
	inventory.emails.AddUnique(emailInventoryName);

	if (GetPDA() == nullptr)
	{
		GivePDA("palanka", NULL); //This shouldn't ever be called during normal gameplay. This is just for debug in case the email inbox is totally empty.
	}

	GetPDA()->AddEmail(emailSanitized);

	if ( hud )
	{
		hud->HandleNamedEvent( "emailPickup" );
	}
}

void idPlayer::GiveEmailViaTalker(const char* talkerName, const char* emailName, bool autoSelect) {

	if (emailName == NULL || emailName[0] == '\0' || talkerName == NULL || talkerName[0] == '\0')
	{
		gameLocal.Warning("GiveEmail: failed to give email.\n");
		return;
	}

	idStr emailSanitized = emailName;
	emailSanitized.ToLower();
	const idDeclPDA* pda = GetPDAViaTalker(talkerName);
	if (pda == nullptr)
	{
		//couldn't find pda. Give PDA.
		GivePDA(talkerName, NULL);

		//Verify it worked.
		pda = GetPDAViaTalker(talkerName);
		if (pda == nullptr)
		{
			gameLocal.Warning("GiveEmailViaTalker: failed to create pda.");
			return;
		}
	}

	idStr emailInventoryName = talkerName;
	emailInventoryName += ";";
	emailInventoryName += emailSanitized;
	inventory.emails.AddUnique(emailInventoryName);
	pda->AddEmail(emailSanitized);

	if (hud)
	{
		hud->HandleNamedEvent("emailPickup");
	}

	if (autoSelect)
	{
		inventory.selEMail = pda->GetNumEmails() - 1;
		objectiveSystem->SetStateInt("listPDAEmail_sel_0", inventory.selEMail);
	}
}

/*
===============
idPlayer::GivePDA
===============
*/
void idPlayer::GivePDA( const char *pdaName, idDict *item )
{
	if ( gameLocal.isMultiplayer && spectating ) {
		return;
	}

	if ( item ) {
		inventory.pdaSecurity.AddUnique( item->GetString( "inv_name" ) );
	}

	if ( pdaName == NULL || *pdaName == 0 ) {
		pdaName = "personal";
	}

	const idDeclPDA *pda = static_cast< const idDeclPDA* >( declManager->FindType( DECL_PDA, pdaName ) );

	inventory.pdas.AddUnique( pdaName );

	// Copy any videos over
	for ( int i = 0; i < pda->GetNumVideos(); i++ ) {
		const idDeclVideo *video = pda->GetVideoByIndex( i );
		if ( video ) {
			inventory.videos.AddUnique( video->GetName() );
		}
	}

	// This is kind of a hack, but it works nicely
	// We don't want to display the 'you got a new pda' message during a map load
	if ( gameLocal.GetFrameNum() > 10 ) {
		if ( pda && hud ) {
			idStr pdaName = pda->GetPdaName();
			pdaName.RemoveColors();
			hud->SetStateString( "pda", "1" );
			hud->SetStateString( "pda_text", pdaName );
			const char *sec = pda->GetSecurity();
			hud->SetStateString( "pda_security", ( sec && *sec ) ? "1" : "0" );
			hud->HandleNamedEvent( "pdaPickup" );
		}

		if ( inventory.pdas.Num() == 1 ) {
			GetPDA()->RemoveAddedEmailsAndVideos();
			
			//if ( !objectiveSystemOpen ) {
			//	TogglePDA();
			//}
			//objectiveSystem->HandleNamedEvent( "showPDATip" );
			//ShowTip( spawnArgs.GetString( "text_infoTitle" ), spawnArgs.GetString( "text_firstPDA" ), true );
		}

		if ( inventory.pdas.Num() > 1 && pda->GetNumVideos() > 0 && hud ) {
			hud->HandleNamedEvent( "videoPickup" );
		}
	}
}

/*
===============
idPlayer::FindInventoryItem
===============
*/
idDict *idPlayer::FindInventoryItem( const char *name ) {
	for ( int i = 0; i < inventory.items.Num(); i++ ) {
		const char *iname = inventory.items[i]->GetString( "inv_name" );
		if ( iname && *iname ) {
			if ( idStr::Icmp( name, iname ) == 0 ) {
				return inventory.items[i];
			}
		}
	}
	return NULL;
}

/*
===============
idPlayer::RemoveInventoryItem
===============
*/
void idPlayer::RemoveInventoryItem( const char *name ) {
	//Hack for localization
	if(!idStr::Icmp(name, "Pwr Cell")) {
		name = common->GetLanguageDict()->GetString( "#str_00101056" );
	}
	idDict *item = FindInventoryItem(name);
	if ( item ) {
		RemoveInventoryItem( item );
	}
}

/*
===============
idPlayer::RemoveInventoryItem
===============
*/
void idPlayer::RemoveInventoryItem( idDict *item ) {
	inventory.items.Remove( item );

#ifdef _D3XP //Added to support powercells
	if(item->GetInt("inv_powercell") && focusUI) {
		//Reset the powercell count
		int powerCellCount = 0;
		for ( int j = 0; j < inventory.items.Num(); j++ ) {
			idDict *item = inventory.items[ j ];
			if(item->GetInt("inv_powercell")) {
				powerCellCount++;
			}
		}
		focusUI->SetStateInt( "powercell_count", powerCellCount );
	}
#endif

	delete item;
}

/*
===============
idPlayer::GiveItem
===============
*/
void idPlayer::GiveItem( const char *itemname ) {
	
	idDict args;
	idEntity *spawnedEnt;
	
	args.Set( "classname", itemname );
	args.Set( "owner", name.c_str() );
	gameLocal.SpawnEntityDef( args, &spawnedEnt);
	if ( hud ) {
		hud->HandleNamedEvent( "itemPickup" );
	}

	//bc our changes break the default giveitem functionality so we add this. This is .... not a good hack
	if (spawnedEnt == NULL)
	{
		gameLocal.Warning("unable to spawn '%s'", itemname);
		return;
	}

	if (!spawnedEnt->IsType(idItem::Type))
	{
		gameLocal.Warning("unable to give '%s'", itemname);
		return;
	}

	if (idStr::Cmpn(itemname, "item_", 5) == 0)
	{
		static_cast<idItem *>(spawnedEnt)->Pickup(this);
	}
	else
	{
		GiveItem(static_cast<idItem *>(spawnedEnt));
	}

	spawnedEnt->PostEventMS(&EV_Remove, 0);
}

/*
==================
idPlayer::SlotForWeapon
==================
*/
int idPlayer::SlotForWeapon( const char *weaponName ) {
	int i;

	for( i = 0; i < MAX_WEAPONS; i++ ) {
		const char *weap = spawnArgs.GetString( va( "def_weapon%d", i ) );
		if ( !idStr::Cmp( weap, weaponName ) ) {
			return i;
		}
	}

	// not found
	return -1;
}

/*
===============
idPlayer::Reload
===============
*/
void idPlayer::Reload( void ) {
	if ( gameLocal.isClient ) {
		return;
	}

	if ( spectating || gameLocal.inCinematic || influenceActive ) {
		return;
	}

	if ( weapon.GetEntity() && weapon.GetEntity()->IsLinked() ) {
		weapon.GetEntity()->Reload();
	}
}





/*
===============
idPlayer::NextBestWeapon
===============
*/
void idPlayer::NextBestWeapon( void ) {


	const char *weap;

	if ( gameLocal.isClient || !weaponEnabled ) {
		return;
	}

	for (int i = 0; i < MAX_HOTBARSLOTS; ++i) {
		if ( inventory.hotbarSlots[i].weaponType == -1 )
			continue;

		weap = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[i].weaponType ) );
		if ( !weap[ 0 ] || ( !inventory.HasAmmo( weap, true, this ) ) ) {
			continue;
		}
		if ( !spawnArgs.GetBool( va( "weapon%d_best", weap ) ) ) {
			continue;
		}

		//Some weapons will report having ammo but the clip is empty and
		//will not have enough to fill the clip (i.e. Double Barrel Shotgun with 1 round left)
		//We need to skip these weapons because they cannot be used
		if(inventory.HasEmptyClipCannotRefill(i, weap, this)) {
			continue;
		}

		idealWeaponSlot = i;
		break;
	}
	
	weaponSwitchTime = gameLocal.time + WEAPON_SWITCH_DELAY;
	UpdateHudWeapon();
}

/*
===============
idPlayer::NextWeapon
===============
*/
void idPlayer::NextWeapon( void ) {

	//mouse wheel down.

	if (usercmd.buttons & BUTTON_QUICKTHROW || IsLeaning() || iteminspectActive)
	{
		return;
	}

	if (armstatsActive)
	{
		//if (cameraspliceActive)
		//{
		//	SwitchCameraSpliceChannel(cameraspliceChannel + 1);
		//}

		//Go to objectives screen.
		if (armstatMode == AMOD_MAP)
		{
			armstatsModel->Event_GuiNamedEvent(1, "gotoObjectives");
			armstatsModel->StartSound("snd_cameraswitch", SND_CHANNEL_ANY);
			armstatMode = AMOD_OBJECTIVES;
			hud->SetStateInt("wristmode", 1);
		}

		return;
	}

	//if (zoommodeActive && !zoominspect_LabelmodeActive)
	//{
	//	//zoom out.
	//	this->zoomCurrentFOV += ZOOM_STEP;
	//
	//	if (this->zoomCurrentFOV > ZOOM_MAX)
	//	{
	//		this->zoomCurrentFOV = ZOOM_MAX;
	//		StartSound("snd_zoomerror", SND_CHANNEL_ANY, 0, false, NULL);
	//	}
	//	else
	//	{
	//		StartSound("snd_zoomstepout", SND_CHANNEL_ANY, 0, false, NULL);
	//	}
	//
	//	return;
	//}

	// Peering through telescope, try to zoom out
	if (peekObject.IsValid() && static_cast<idVentpeek*>(peekObject.GetEntity())->forTelescope)
	{
		static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->ZoomOut();
		return;
	}

	int targetSlot = Max(this->lastSelectedHotbarslot, 0) + 1;
	if (targetSlot >= inventory.hotbarUnlockedSlots)
	{
		targetSlot = 0;
	}

	SelectHotbarslot(targetSlot);

	//uncomment this for the weapon select pause.
	//gameLocal.menuPause = true;
	//isWeaponselectPaused = true;
	//weaponselectPauseTimer = gameLocal.hudTime + WEAPONSELECT_PAUSETIME;


//BC stock retail code.
//	const char *weap;
//	int w;
//
//	if ( !weaponEnabled || spectating || hiddenWeapon || gameLocal.inCinematic || gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) || health < 0 ) {
//		return;
//	}
//
//	if ( gameLocal.isClient ) {
//		return;
//	}
//
//	// check if we have any weapons
//	if ( !inventory.weapons ) {
//		return;
//	}
//
//	w = idealWeapon;
//	while( 1 ) {
//		w++;
//		if ( w >= MAX_WEAPONS ) {
//			w = 0;
//		}
//		weap = spawnArgs.GetString( va( "def_weapon%d", w ) );
//		if ( !spawnArgs.GetBool( va( "weapon%d_cycle", w ) ) ) {
//			continue;
//		}
//		if ( !weap[ 0 ] ) {
//			continue;
//		}
//		if ( ( inventory.weapons & ( 1 << w ) ) == 0 ) {
//			continue;
//		}
//
//#ifdef _D3XP
//		if ( inventory.HasAmmo( weap, true, this )  ) {
//#else
//		if ( inventory.HasAmmo( weap ) ) {
//#endif
//			break;
//		}
//	}
//
//	if ( ( w != currentWeapon ) && ( w != idealWeapon ) ) {
//		idealWeapon = w;
//		weaponSwitchTime = gameLocal.time + WEAPON_SWITCH_DELAY;
//		UpdateHudWeapon();
//	}
}

/*
===============
idPlayer::PrevWeapon
===============
*/
void idPlayer::PrevWeapon( void )
{
	//mouse wheel up.

	if (usercmd.buttons & BUTTON_QUICKTHROW || IsLeaning() || iteminspectActive)
	{
		return;
	}

	if (armstatsActive)
	{
		//if (cameraspliceActive)
		//{
		//	SwitchCameraSpliceChannel(cameraspliceChannel - 1);
		//}

		//Go to map screen.
		if (armstatMode == AMOD_OBJECTIVES)
		{
			armstatsModel->Event_GuiNamedEvent(1, "gotoMap");
			armstatsModel->StartSound("snd_cameraswitch", SND_CHANNEL_ANY);
			armstatMode = AMOD_MAP;
			hud->SetStateInt("wristmode", 0);
		}

		return;
	}

	//if (zoommodeActive &&  !zoominspect_LabelmodeActive)
	//{
	//	//zoom in.
	//	this->zoomCurrentFOV += -ZOOM_STEP;
	//
	//	if (this->zoomCurrentFOV < ZOOM_MIN)
	//	{
	//		this->zoomCurrentFOV = ZOOM_MIN;
	//		StartSound("snd_zoomerror", SND_CHANNEL_ANY, 0, false, NULL);
	//	}
	//	else
	//	{
	//		StartSound("snd_zoomstepin", SND_CHANNEL_ANY, 0, false, NULL);
	//	}
	//	return;
	//}

	// Peering through telescope, try to zoom in
	if (peekObject.IsValid() && static_cast<idVentpeek*>(peekObject.GetEntity())->forTelescope)
	{
		static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->ZoomIn();
		return;
	}

	int targetSlot = Max(this->lastSelectedHotbarslot,0) - 1;
	if (targetSlot < 0)
	{
		targetSlot = inventory.hotbarUnlockedSlots - 1;
	}

	SelectHotbarslot(targetSlot);

	//uncomment this for the weapon select pause.
	//gameLocal.menuPause = true;
	//isWeaponselectPaused = true;
	//weaponselectPauseTimer = gameLocal.hudTime + WEAPONSELECT_PAUSETIME;
	

	//BC stock retail code.
//	const char *weap;
//	int w;
//
//	if ( !weaponEnabled || spectating || hiddenWeapon || gameLocal.inCinematic || gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) || health < 0 ) {
//		return;
//	}
//
//	if ( gameLocal.isClient ) {
//		return;
//	}
//
//	// check if we have any weapons
//	if ( !inventory.weapons ) {
//		return;
//	}
//
//	w = idealWeapon;
//	while( 1 ) {
//		w--;
//		if ( w < 0 ) {
//			w = MAX_WEAPONS - 1;
//		}
//		weap = spawnArgs.GetString( va( "def_weapon%d", w ) );
//		if ( !spawnArgs.GetBool( va( "weapon%d_cycle", w ) ) ) {
//			continue;
//		}
//		if ( !weap[ 0 ] ) {
//			continue;
//		}
//		if ( ( inventory.weapons & ( 1 << w ) ) == 0 ) {
//			continue;
//		}
//#ifdef _D3XP
//		if ( inventory.HasAmmo( weap, true, this ) ) {
//#else
//		if ( inventory.HasAmmo( weap ) ) {
//#endif
//			break;
//		}
//	}
//
//	if ( ( w != currentWeapon ) && ( w != idealWeapon ) ) {
//		idealWeapon = w;
//		weaponSwitchTime = gameLocal.time + WEAPON_SWITCH_DELAY;
//		UpdateHudWeapon();
//	}
}

/*
===============
idPlayer::SelectWeapon
===============
*/
void idPlayer::SelectWeapon( int hotbarSlot, int weaponNum, bool force ) {
	const char *weap;

	if ( !weaponEnabled || spectating || gameLocal.inCinematic || health < 0)
	{
		return;
	}

	if ( ( weaponNum < 0 ) || ( weaponNum >= MAX_WEAPONS ) ) {
		return;
	}

	if ( gameLocal.isClient ) {
		return;
	}	


	if ( ( weaponNum != weapon_pda ) && gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) ) {
		weaponNum = weapon_fists;
		hiddenWeapon ^= 1;
		if ( hiddenWeapon && weapon.GetEntity() ) {
			weapon.GetEntity()->LowerWeapon();
		} else {
			weapon.GetEntity()->RaiseWeapon();
		}
	}

	weap = spawnArgs.GetString( va( "def_weapon%d", weaponNum ) );
	if ( !weap[ 0 ] ) {
		gameLocal.Printf( "Invalid weapon\n" );
		return;
	}


	//Is the weapon a toggle weapon
	WeaponToggle_t* weaponToggle;
	if(weaponToggles.Get(va("weapontoggle%d", weaponNum), &weaponToggle)) {

		int weaponToggleIndex = 0;

		//Find the current Weapon in the list
		int currentIndex = -1;
		for(int i = 0; i < weaponToggle->toggleList.Num(); i++) {
			if(weaponToggle->toggleList[i] == inventory.hotbarSlots[idealWeaponSlot].weaponType) {
				currentIndex = i;
				break;
			}
		}
		if(currentIndex == -1) {
			//Didn't find the current weapon so select the first item
			weaponToggleIndex = 0;
		} else {
			//Roll to the next available item in the list
			weaponToggleIndex = currentIndex;
			weaponToggleIndex++;
			if(weaponToggleIndex >= weaponToggle->toggleList.Num()) {
				weaponToggleIndex = 0;
			}
		}

		for(int i = 0; i < weaponToggle->toggleList.Num(); i++) {

			//Is it available
			if ( inventory.hotbarSlots[hotbarSlot].weaponType == weaponToggle->toggleList[weaponToggleIndex] ) {
				break;
			}

			weaponToggleIndex++;
			if(weaponToggleIndex >= weaponToggle->toggleList.Num()) {
				weaponToggleIndex = 0;
			}
		}

		weaponNum = weaponToggle->toggleList[weaponToggleIndex];
	}


	if ( force || currentWeaponSlot != hotbarSlot )
	{

		if ( !inventory.HasAmmo( weap, true, this ) && !spawnArgs.GetBool( va( "weapon%d_allowempty", weaponNum ) ) ) //if allowempty flag is false, don't allow player to select this empty weapon.
		{
			return;
		}

		if ( ( previousWeaponSlot >= 0 ) && ( inventory.hotbarSlots[idealWeaponSlot].weaponType == weaponNum ) && ( spawnArgs.GetBool( va( "weapon%d_toggle", weaponNum ) ) ) ) {
			weap = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[previousWeaponSlot].weaponType ) );

			if ( !inventory.HasAmmo( weap, true, this ) && !spawnArgs.GetBool( va( "weapon%d_allowempty", inventory.hotbarSlots[previousWeaponSlot].weaponType ) ) ) {
				return;
			}
			idealWeaponSlot = previousWeaponSlot;
		} else if ( ( weapon_pda >= 0 ) && ( weaponNum == weapon_pda ) && ( inventory.pdas.Num() == 0 ) ) {
			ShowTip( spawnArgs.GetString( "text_infoTitle" ), spawnArgs.GetString( "text_noPDA" ), true );
			return;
		}
		else
		{
			idealWeaponSlot = hotbarSlot;


			//BC check if it's a carryable.
			//First, we start by hiding the carryables the player is NOT selecting.
			for (int i = 0; i < MAX_HOTBARSLOTS; i++)
			{
				if (i == idealWeaponSlot)
					continue;

				if (spawnArgs.GetBool(va("weapon%d_carryable", inventory.hotbarSlots[i].weaponType)))
				{
					//it's a carryable. See if we can find its pointer.
					idEntityPtr<idEntity> carryPtr = inventory.hotbarSlots[i].carryPtr;
					if ( carryPtr.IsValid() )
					{
						//This is NOT the one the player wants to select. Hide it.
						carryPtr.GetEntity()->Hide();
					}
				}
			}
			
			//Now we select the carryable the player wants, if applicable.
			bool foundItem = false;
			if (spawnArgs.GetBool(va("weapon%d_carryable", weaponNum)))
			{
				//it's a carryable. See if we can find its pointer.
				idEntityPtr<idEntity> carryPtr = inventory.hotbarSlots[hotbarSlot].carryPtr;
				if ( carryPtr.IsValid() )
				{
					//found it.
					//The one the player wants to select.
					
					if (carryableItem.IsValid() && carryableItem.GetEntity() == carryPtr.GetEntity() && !carryPtr.GetEntity()->IsHidden())
					{
						//this was already selected. Do nothing.
						foundItem = true;
					}
					else
					{
						//Unhide it, put it in player's hand.
						carryPtr.GetEntity()->Show();
						SetCarryable( carryPtr.GetEntity(), true );
						carryPtr.GetEntity()->UpdateVisuals();
						foundItem = true;
					}
				}
			}
			
			if (!foundItem)
				carryableItem = NULL;
			

		}
		UpdateHudWeapon();
	}
}


void idPlayer::ThrowCarryable(void)
{
	idVec3 throwAngle;
	idEntity *item;
	idVec3 forward, right;

	UpdateThrowableAIDodge(GetPhysics()->GetOrigin() + idVec3(0,0,48), true);

	viewAngles.ToVectors(&forward, &right, NULL);
	throwAngle = forward;

	if (!airless)
	{
		//if have gravity, then give it upward throwing arc.
		throwAngle.z += QUICKTHROW_UPWARD_DIR;
	}

	throwAngle.Normalize();

	idVec3 carryOffset = GetCarryableOffset();
	item = carryableItem.GetEntity();
	SetCarryable(NULL, false);

	item->GetPhysics()->SetOrigin( firstPersonViewOrigin + forward * carryOffset.x + right * carryOffset.y );
	item->GetPhysics()->SetLinearVelocity(throwAngle * GetThrowPower(item));
	item->GetPhysics()->SetAngularVelocity(GetThrowAngularVelocity());
	item->throwTime = gameLocal.time;

	if ( item->IsType( idMoveableItem::Type ) )
	{
		static_cast<idMoveableItem*>(item)->lastThrower = this;
		static_cast< idMoveableItem* >( item )->canDealEntDamage = true;
		static_cast<idMoveableItem*>(item)->JustThrown();
	}

	//Event log.
	gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_player_throw"),  item->displayName.c_str()), GetPhysics()->GetOrigin(), false);
}


//BC throw the current WEAPON (not carryable). Copied from the DropWeapon function.
void idPlayer::ThrowCurrentWeapon(void)
{
	idVec3 throwAngle;
	idEntity* item;
	int inclip;
	idVec3 forward, right;

	if (weaponGone || weapon.GetEntity() == NULL || !weapon.GetEntity()->IsReady())
	{
		return;
	}

	item = NULL;

	//Normal unguided throw. Make sure these values match the values in the script files (weapon_wiregrenade.script, etc.)	
	viewAngles.ToVectors(&forward, &right, NULL);
	throwAngle = forward;

	if (!airless)
	{
		throwAngle.z += QUICKTHROW_UPWARD_DIR; //if in gravity, then do upward arc. if in space, then skip this.
	}

	throwAngle.Normalize();

	item = weapon.GetEntity()->DropItem(throwAngle * GetThrowPower(NULL), 500, -1, false, true);
	if (!item)
	{
		return;
	}

	if (item->IsType(idMoveableItem::Type))
	{
		static_cast<idMoveableItem*>(item)->canDealEntDamage = true;
		static_cast<idMoveableItem*>(item)->JustThrown();
	}
	//item->GetPhysics()->SetAngularVelocity(idVec3( 0, 64, 0));

	//update the item with appropriate health.
	int equippedSlot = inventory.GetHotbarSelection();
	item->health = inventory.hotbarSlots[equippedSlot].health;

	//Event log.
	gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_player_throw"), item->spawnArgs.GetString("displayname")), GetPhysics()->GetOrigin(), false);

	UpdateThrowableAIDodge(GetPhysics()->GetOrigin() + idVec3(0, 0, 48), true);

	item->throwTime = gameLocal.time;

	//Remember how many rounds are in the mag.
	inclip = weapon.GetEntity()->AmmoInClip();
	const idKeyValue* keyval = item->spawnArgs.MatchPrefix("inv_ammo_");
	if (keyval)
	{
		//int ammoavailable = weapon.GetEntity()->AmmoAvailable();
		//item->spawnArgs.SetInt(keyval->GetKey(), ammoavailable);
		idStr inclipKey = keyval->GetKey();
		inclipKey.Insert("inclip_", 4);
		//inclipKey.Insert(va("%.2d", currentWeapon), 11);
		item->spawnArgs.SetInt(inclipKey, inclip);
	}

	if (weapon.GetEntity()->isGrenade)
	{
		//Threw a grenade.

		//Lose one ammo.
		ammo_t ammo_i = inventory.AmmoIndexForWeaponClass(spawnArgs.GetString(va("def_weapon%d", inventory.hotbarSlots[currentWeaponSlot].weaponType)), NULL);
		inventory.ammo[ammo_i]--;

		if (inventory.ammo[ammo_i] <= 0 || weapon.GetEntity()->multiCarry)
		{
			//No more grenade ammo.

			//Update the hotbar.
			inventory.Drop(equippedSlot);
			SetHotbarSlot(equippedSlot, 0, "", 0, NULL); //set unarmed.
			weapon.GetEntity()->ResetAmmoClip();
			Event_SelectWeapon("weapon_unarmed"); //BC go to unarmed.
			weapon.GetEntity()->WeaponStolen();
			weaponGone = true;
		}
	}
	else
	{
		//Lose the item.

		//Update the hotbar.
		inventory.Drop(equippedSlot);
		SetHotbarSlot(equippedSlot, 0, "", 0, NULL); //set unarmed.
		weapon.GetEntity()->ResetAmmoClip();
		//NextWeapon();
		Event_SelectWeapon("weapon_unarmed"); //BC go to unarmed.
		weapon.GetEntity()->WeaponStolen();
		weaponGone = true;
	}

	currentWeaponSlot = -1;
}


//Gently place carryable on the ground (or release into space, if in zero g)
void idPlayer::DropCurrentCarryable(idEntity* dropEntTo, bool showMessage)
{
	if (!carryableItem.IsValid())
		return;

	if (trashchuteFocus.IsValid())
	{
		//Place it on trash chute.
		idVec3 trashplatformPos = trashchuteFocus.GetEntity()->GetPhysics()->GetOrigin();

		idVec3 itemDropPos = trashplatformPos;
		itemDropPos.z += 2; //raise up to the top of trash platform's surface.
		itemDropPos.z += idMath::Fabs(carryableItem.GetEntity()->GetPhysics()->GetBounds().zMin());
		itemDropPos.z += 2; //extra buffer space.

		carryableItem.GetEntity()->SetOrigin(itemDropPos);
		idAngles chuteAngle = trashchuteFocus.GetEntity()->GetPhysics()->GetAxis().ToAngles();
		chuteAngle.yaw += 90;
		carryableItem.GetEntity()->SetAxis(chuteAngle.ToMat3());

		if (!airless)
		{
			carryableItem.GetEntity()->GetPhysics()->SetGravity(gameLocal.GetGravity()); //Restore its gravity.
		}
	}
	else if (!airless)
	{
		//There is gravity. Attempt to place it down gently on the floor.
		trace_t dropTr;
		idPhysics* phys = carryableItem.GetEntity()->GetPhysics();

		idVec3 itemPos = phys->GetOrigin();
		if ( dropEntTo )
		{
			itemPos = dropEntTo->GetPhysics()->GetOrigin();
		}
		float itemTop = phys->GetBounds().zMax();
		float itemBottom = phys->GetBounds().zMin();

		gameLocal.clip.TraceBounds(
			dropTr,
			itemPos + idVec3(0, 0, itemTop), // We start tracing from the *top* of the item, so it doesn't fall through the floor if we place it while crouching
			itemPos + idVec3(0, 0, itemBottom) + idVec3(0, 0, -70),
			phys->GetBounds(),
			MASK_SOLID,
			this
		);
		idAngles angles( 0.0f, viewAngles.yaw, 0.0f );
		carryableItem.GetEntity()->SetAxis(angles.ToMat3()); //Rotate it to a sensible facing forward angle
		carryableItem.GetEntity()->SetOrigin(dropTr.endpos); //Snap it to be near ground.
		carryableItem.GetEntity()->GetPhysics()->SetGravity(gameLocal.GetGravity()); //Restore its gravity.
	}
	else
	{
		//No gravity. Just release it.
		carryableItem.GetEntity()->GetPhysics()->SetLinearVelocity(vec3_zero);
		carryableItem.GetEntity()->GetPhysics()->SetAngularVelocity(vec3_zero);
	}

	if (showMessage)
	{
		hud->SetStateString("centermessage", va("Dropped %s", carryableItem.GetEntity()->displayName.c_str()));
		hud->HandleNamedEvent("droppedAmmo");
	}

	SetCarryable(NULL, false, true);
}


// SW:
// In order to accurately predict where a thrown object is going to land,
// we must have consistent initial parameters.
// Thrown objects must rotate as they fly through the air (it looks wacky otherwise),
// but that rotation must be a constant value to ensure we can factor it into our predictions
//
// EDIT: We're dropping rotation for now, may revisit this later
// eric: changed to use forward rotation based on throw power
idVec3 idPlayer::GetThrowAngularVelocity()
{
	idVec3 forward, right;
	viewAngles.ToVectors(&forward, &right, NULL);
	return right * (GetThrowPower(NULL) * -1) * 0.1f;
}

idEntity* idPlayer::GetFrobEnt(void)
{
	return frobEnt;
}

// SW: The player code normally decides the frob ent for itself, and nothing else needs to know about it.
// The only current exception to this rule is if the frob entity is destroyed, and needs to null out the pointer.
void idPlayer::SetFrobEnt(idEntity* ent)
{
	if (frobEnt)
	{
		frobEnt->SetPostFlag(POST_OUTLINE_FROB, false);
	}

	frobEnt = ent;

	if (frobEnt)
	{
		frobEnt->SetPostFlag(POST_OUTLINE_FROB, true);
	}
}


/*
===============
idPlayer::UpdateThrownWeapon

	SW: Before throwing a weapon, we need to know its physical properties so we can accurately draw its predicted trajectory.
	Since these physical properties only change when the weapon itself changes,
	it really doesn't make sense to be updating them every time we draw the throwing arc.
===============
*/
void idPlayer::UpdateThrownWeapon(const idDeclEntityDef* weaponDef)
{
	idTraceModel trm;

	const char* worldWeaponClassName = weaponDef->dict.GetString("def_dropItem"); // Get the classname of the entity that we *would* drop if we tried to throw this
	if (!worldWeaponClassName[0])
		return;

	const idDeclEntityDef* worldWeaponDef = gameLocal.FindEntityDef(worldWeaponClassName);
	if (!worldWeaponDef)
		return;

	// We want to initialize but not *spawn* this physics object. 
	// It exists only to assist our predictive calculations and should not exist in the world
	idPhysics_RigidBody* physicsObj = new idPhysics_RigidBody();
	
	physicsObj->SetSelf(weapon.GetEntity());
	physicsObj->SetFriction(0.6f, 0.6f, worldWeaponDef->dict.GetFloat("friction", "0.05"));
	physicsObj->SetBouncyness(worldWeaponDef->dict.GetFloat("bouncyness", "0.6"));
	physicsObj->SetMass(worldWeaponDef->dict.GetFloat("mass", "10"));

	// check if a clip model is set
	idStr clipModelName = worldWeaponDef->dict.GetString("clipmodel", "");
	if (!clipModelName[0]) {
		clipModelName = worldWeaponDef->dict.GetString("model");// use the visual model
	}

	if (!collisionModelManager->TrmFromModel(clipModelName, trm)) {
		gameLocal.Error("idMoveable '%s': cannot load collision model %s", name.c_str(), clipModelName.c_str());
		return;
	}

	// Set a clip model and density (these have to be done simultaneously because ????)
	physicsObj->SetClipModel(new idClipModel(trm), worldWeaponDef->dict.GetFloat("density", "0.5"));
	
	// Even though we haven't 'properly' initialized this physics object, it still technically exists in the world.
	// We need to zero these fields to stop it creating an invisible solid
	physicsObj->SetClipMask(0); 
	physicsObj->SetContents(0);

	if (throwWeaponPhysicsObj)
		delete throwWeaponPhysicsObj;

	throwWeaponPhysicsObj = physicsObj;

	assert(throwPredictionModel);

	throwPredictionModel->SetModel(worldWeaponDef->dict.GetString("model"));
}


/*
=================
idPlayer::DropWeapon
=================
*/
void idPlayer::DropWeapon( bool died ) {
	idVec3 forward, up;
	int inclip, ammoavailable;

	assert( !gameLocal.isClient );

	if ( spectating || weaponGone || weapon.GetEntity() == NULL ) {
		return;
	}

	if ( ( !died && !weapon.GetEntity()->IsReady() ) || weapon.GetEntity()->IsReloading() ) {
		return;
	}
	// ammoavailable is how many shots we can fire
	// inclip is which amount is in clip right now
	ammoavailable = weapon.GetEntity()->AmmoAvailable();
	inclip = weapon.GetEntity()->AmmoInClip();

	// don't drop a grenade if we have none left
	if ( !idStr::Icmp( idWeapon::GetAmmoNameForNum( weapon.GetEntity()->GetAmmoType() ), "ammo_grenades" ) && ( ammoavailable - inclip <= 0 ) )
	{
		return;
	}


	ammoavailable += inclip;


	// expect an ammo setup that makes sense before doing any dropping
	// ammoavailable is -1 for infinite ammo, and weapons like chainsaw
	// a bad ammo config usually indicates a bad weapon state, so we should not drop
	// used to be an assertion check, but it still happens in edge cases

	if ( ( ammoavailable != -1 ) && ( ammoavailable < 0 ) )
	{
		common->DPrintf( "idPlayer::DropWeapon: bad ammo setup\n" );
		return;
	}

	idEntity *item = NULL;
	if ( died )
	{
		// throw weapon.
		viewAngles.ToVectors(&forward, NULL, &up);
		item = weapon.GetEntity()->DropItem( (128 * forward) + (100 * up), 0, -1, died, false );
	}
	else
	{
		viewAngles.ToVectors( &forward, NULL, &up );
		item = weapon.GetEntity()->DropItem( 250.0f * forward + 150.0f * up, 0, -1, died, false );
	}

	if ( !item )
	{
		return;
	}

	// set the appropriate ammo in the dropped object
	const idKeyValue * keyval = item->spawnArgs.MatchPrefix( "inv_ammo_" );
	if ( keyval )
	{
		item->spawnArgs.SetInt( keyval->GetKey(), ammoavailable );
		idStr inclipKey = keyval->GetKey();
		inclipKey.Insert( "inclip_", 4 );

		inclipKey.Insert( va("%.2d", inventory.hotbarSlots[currentWeaponSlot].weaponType), 11);

		item->spawnArgs.SetInt( inclipKey, inclip );
	}

	if ( !died )
	{
		// remove from our local inventory completely
		int equippedSlot = inventory.GetHotbarSelection();
		inventory.Drop( equippedSlot );
		weapon.GetEntity()->ResetAmmoClip();
		NextWeapon();
		weapon.GetEntity()->WeaponStolen();
		weaponGone = true;
	}
}

/*
=================
idPlayer::StealWeapon
steal the target player's current weapon
=================
*/
void idPlayer::StealWeapon( idPlayer *player )
{
	assert( !gameLocal.isClient );

	// SM: This is only used in multiplayer, so just comment this out for the hotbar refactor

	// make sure there's something to steal
// 	idWeapon *player_weapon = static_cast< idWeapon * >( player->weapon.GetEntity() );
// 	if ( !player_weapon || !player_weapon->CanDrop() || weaponGone )
// 	{
// 		return;
// 	}
// 
// 	// steal - we need to effectively force the other player to abandon his weapon
// 	int newweap = player->currentWeapon;
// 	if ( newweap == -1 )
// 	{
// 		return;
// 	}
// 	// might be just dropped - check inventory
// 	if ( ! ( player->inventory.weapons & ( 1 << newweap ) ) )
// 	{
// 		return;
// 	}
// 
// 	const char *weapon_classname = spawnArgs.GetString( va( "def_weapon%d", newweap ) );
// 	assert( weapon_classname );
// 	int ammoavailable = player->weapon.GetEntity()->AmmoAvailable();
// 	int inclip = player->weapon.GetEntity()->AmmoInClip();
// 
// 
// 	ammoavailable += inclip;
// 
// 
// 	if ( ( ammoavailable != -1 ) && ( ammoavailable < 0 ) )
// 	{
// 		// see DropWeapon
// 		common->DPrintf( "idPlayer::StealWeapon: bad ammo setup\n" );
// 		// we still steal the weapon, so let's use the default ammo levels
// 		inclip = -1;
// 		const idDeclEntityDef *decl = gameLocal.FindEntityDef( weapon_classname );
// 		assert( decl );
// 		const idKeyValue *keypair = decl->dict.MatchPrefix( "inv_ammo_" );
// 		assert( keypair );
// 		ammoavailable = atoi( keypair->GetValue() );
// 	}
// 
// 	player->weapon.GetEntity()->WeaponStolen();
// 	player->inventory.Drop( player->spawnArgs, NULL, newweap );
// 	player->SelectWeapon( weapon_fists, false );
// 	// in case the robbed player is firing rounds with a continuous fire weapon like the chaingun/plasma etc.
// 	// this will ensure the firing actually stops
// 	player->weaponGone = true;
// 
// 	// give weapon, setup the ammo count
// 	Give( "weapon", weapon_classname );
// 	ammo_t ammo_i = player->inventory.AmmoIndexForWeaponClass( weapon_classname, NULL );
// 	idealWeapon = newweap;
// 	inventory.ammo[ ammo_i ] += ammoavailable;


}






/*
===============
idPlayer::ActiveGui
===============
*/
idUserInterface *idPlayer::ActiveGui(void) {

	if (g_editEntityMode.GetInteger() > 0 && gameEdit->editmenuActive)
	{
		return gameEdit->lighteditMenu;
	}

	if (eventlogMenuActive)
	{
		return eventlogMenu;
	}

	if (emailFullscreenState == EFS_ACTIVE)
	{
		return emailFullscreenMenu;
	}

	if (levelselectMenuActive)
	{
		return levelselectMenu;
	}

	if (contextMenuActive)
	{
		return contextMenu;
	}

	if ( objectiveSystemOpen )
	{
		return objectiveSystem;
	}
		
	return focusUI;
}

/*
===============
idPlayer::Weapon_Combat
===============
*/
void idPlayer::Weapon_Combat( void ) {
	if ( influenceActive || !weaponEnabled || gameLocal.inCinematic || privateCameraView) {
		return;
	}

	weapon.GetEntity()->RaiseWeapon();
	if ( weapon.GetEntity()->IsReloading() ) {
		if ( !AI_RELOAD ) {
			AI_RELOAD = true;
			SetState( "ReloadWeapon", true );


			idStr reloadVO = weapon.GetEntity()->spawnArgs.GetString("snd_vo_reload", "player_vo_reload");
			SayVO_WithIntervalDelay_msDelayed(reloadVO.c_str(), 400);
		}
	} else {
		AI_RELOAD = false;
	}

// 	if ( idealWeapon == weapon_soulcube && soulCubeProjectile.GetEntity() != NULL ) {
// 		idealWeapon = currentWeapon;
// 	}

	if ( idealWeaponSlot != currentWeaponSlot )
	{
		if ( weaponCatchup )
		{
			assert( gameLocal.isClient );

			currentWeaponSlot = idealWeaponSlot;
			weaponGone = false;
			animPrefix = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[currentWeaponSlot].weaponType ) );
			weapon.GetEntity()->GetWeaponDef( animPrefix, inventory.hotbarSlots[currentWeaponSlot].clip );
			animPrefix.Strip( "weapon_" );

			weapon.GetEntity()->NetCatchup();
			const function_t *newstate = GetScriptFunction( "NetCatchup" );
			if ( newstate ) {
				SetState( newstate, true );
			}
			weaponCatchup = false;
		}
		else
		{
			//Transitioning from one weapon to the next.

			if ( weapon.GetEntity()->IsReady() )
			{
				weapon.GetEntity()->PutAway();
			}

			if ( weapon.GetEntity()->IsHolstered() )
			{
				assert( idealWeaponSlot >= 0 );
				assert( idealWeaponSlot < MAX_HOTBARSLOTS );

				int weaponType = inventory.hotbarSlots[currentWeaponSlot].weaponType;
				if ( weaponType != weapon_pda && !spawnArgs.GetBool( va( "weapon%d_toggle", weaponType ) ) ) {
					previousWeaponSlot = currentWeaponSlot;
				}
				currentWeaponSlot = idealWeaponSlot;
				weaponType = inventory.hotbarSlots[currentWeaponSlot].weaponType;
				weaponGone = false;
				animPrefix = spawnArgs.GetString( va( "def_weapon%d", weaponType ) );
				weapon.GetEntity()->GetWeaponDef( animPrefix, inventory.hotbarSlots[currentWeaponSlot].clip );
				animPrefix.Strip( "weapon_" );

				weapon.GetEntity()->Raise();
			}
		}
	} else {
		weaponGone = false;	// if you drop and re-get weap, you may miss the = false above
		if ( weapon.GetEntity()->IsHolstered() )
		{
			//if ( !weapon.GetEntity()->AmmoAvailable() )
			//{
			//	// weapons can switch automatically if they have no more ammo
			//	// NextBestWeapon(); //BC disable this.
			//}
			//else
			{
				weapon.GetEntity()->Raise();
				state = GetScriptFunction( "RaiseWeapon" );
				if ( state ) {
					SetState( state );
				}
			}
		}
	}


	


	// check for attack
	AI_WEAPON_FIRED = false;
	if (!influenceActive && weapon.GetEntity() != NULL && !hiddenWeapon && !IsLeaning() && !zoommodeActive && mechTransitionState == MECHTRANSITION_NONE && !iteminspectActive)
	{
		if (grenadeThrowState == GRENADETHROW_IDLE)
		{
			//Normal gun firing. Shotguns, pistols, etc.
			if ((usercmd.buttons & BUTTON_ATTACK) && !weaponGone && gameLocal.time > nextAttackTime)
			{
				FireWeapon();
			}
			else if (oldButtons & BUTTON_ATTACK)
			{
				AI_ATTACK_HELD = false;
				weapon.GetEntity()->EndAttack();

				weaponDropCheck();
			}

			
			if ((usercmd.buttons & BUTTON_QUICKTHROW) && !weaponGone && inventory.hotbarSlots[currentWeaponSlot].weaponType != 0
				&& !weapon.GetEntity()->IsInspectingChamber() && !weapon.GetEntity()->IsInspectingMagazine())
			{
				grenadeThrowState = GRENADETHROW_AIMING;
			}
		}
		else
		{
			if (grenadeThrowState == GRENADETHROW_IDLE || grenadeThrowState == GRENADETHROW_AIMING)
			{
                UpdateGrenadethrowStamina();                

				if ((usercmd.buttons & BUTTON_QUICKTHROW) && !weaponGone)
				{
					//Player holding down throw button.

					grenadeThrowState = GRENADETHROW_AIMING;					

					if (grenadeButtonTimer <= 0)
					{
						grenadeButtonTimer = gameLocal.time + GRENADE_THROW_HOLDTIME;
					}

					if (gameLocal.time >= grenadeButtonTimer && !GetThrowArcVisible() && (gameLocal.slowmoState == SLOWMO_STATE_OFF || gameLocal.slowmoState == SLOWMO_STATE_RAMPDOWN))
					{
						SetThrowArcVisible(true);
						gameLocal.SetSlowmo(true); //In throw mode, go to slow motion.
					}

					if (weapon.IsValid())
					{
						//if (weapon.GetEntity()->spawnArgs.GetBool("draw_tele_ui"))
						//{
						//	//draw the teleport prediction UI. Draw where the player will teleport to.
                        //    idVec3 throwStartPosition = weapon.GetEntity()->GetThrowSpawnPosition();
                        //    idVec3 phasedDestination = gameLocal.GetPhasedDestination(throwarcCollision, throwStartPosition);
						//
                        //    if (phasedDestination == vec3_zero)
                        //    {
                        //        //no good position found, hide the teleport UI.
                        //        if (!tele_ui_entity->IsHidden() || !tele_ui_disc->IsHidden())
                        //        {
                        //            tele_ui_entity->Hide();
                        //            tele_ui_disc->Hide();
                        //        }
                        //    }
                        //    else if (shouldDrawThrowArc)
                        //    {
                        //        //we have a teleport position, draw it.
						//
                        //        //Position/Draw the tele disc at the other side of the wall.
                        //        trace_t teleExteriorTr;
                        //        gameLocal.clip.TracePoint(teleExteriorTr, phasedDestination, throwdisc->GetPhysics()->GetOrigin(), MASK_SOLID, NULL);
                        //        tele_ui_disc->SetOrigin(teleExteriorTr.endpos);
                        //        tele_ui_disc->SetAxis(teleExteriorTr.c.normal.ToMat3());
						//
						//		//We fudge the person icon a bit -- make it positioned FURTHER than it actually is, to make the effect more pronounced/exaggerated.
						//		idVec3 phaseDir = tele_ui_disc->GetPhysics()->GetOrigin() - GetEyePosition();
						//		phaseDir.NormalizeFast();
						//		tele_ui_entity->SetOrigin(phasedDestination + phaseDir * 64);
                        //        
						//
                        //        if (tele_ui_entity->IsHidden() || tele_ui_disc->IsHidden())
                        //        {
                        //            tele_ui_entity->Show();
                        //            tele_ui_disc->Show();
                        //        }
                        //    }
						//}

						if (shouldDrawThrowArc)
						{
							throwarcDropMode = IsThrowarcAtDropPosition();

							hud->SetStateString("throwtext", throwarcDropMode ? "Drop" : "Throw");
							if (lastThrowarcDropMode != throwarcDropMode)
							{
								lastThrowarcDropMode = throwarcDropMode;
								hud->HandleNamedEvent("onChangeThrowmode");
							}
						}
					}
				}
				else if (oldButtons & BUTTON_QUICKTHROW)
				{
					//Player has released the throw button, with throw arc. Cancel the throw. (WEAPON)

					SetThrowArcVisible(false);
					grenadeThrowState = GRENADETHROW_NOTREADY;
					grenadeButtonTimer = 0;
					StartSound("snd_cancel", SND_CHANNEL_ANY);
					throwarcDropMode = false;
				}

				if (shouldDrawThrowArc)
				{
					UpdateThrowableAIDodge(GetPhysics()->GetOrigin() + idVec3(0, 0, 48), false);
				}

				//Confirm throw. (WEAPONS)
				if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
				{
					if (throwarcDropMode)
					{
						//Drop the weapon at the throwdisc position.
						DropCurrentWeapon(throwdisc);

						idAngles discAngle = throwdisc->GetPhysics()->GetAxis().ToAngles();
						discAngle.pitch += 90;
						gameLocal.DoParticle("smoke_ring16.prt", throwdisc->GetPhysics()->GetOrigin(), discAngle.ToForward());
					}
					else
					{
						ThrowCurrentWeapon(); //BC we no longer have quick drop on button tap, it now does a quick throw on button tap
					}


					AI_ATTACK_HELD = false;
					SetThrowArcVisible(false);
					grenadeThrowState = GRENADETHROW_FIRINGINPROGRESS;
					grenadeButtonTimer = gameLocal.time + 100;

					if (!tele_ui_entity->IsHidden() || !tele_ui_disc->IsHidden())
					{
						tele_ui_entity->Hide();
						tele_ui_disc->Hide();
					}

					throwarcDropMode = false;
					return;					
				}
			}
			else if (grenadeThrowState == GRENADETHROW_FIRINGINPROGRESS)
			{
				if (gameLocal.time >= grenadeButtonTimer)
				{
					grenadeButtonTimer = 0;
					grenadeThrowState = GRENADETHROW_IDLE;
					weapon.GetEntity()->EndAttack();
					gameLocal.SetSlowmo(false);

					weaponDropCheck();
				}
			}
			else if (grenadeThrowState == GRENADETHROW_NOTREADY)
			{
				//Wait for player to release button.
				if (!(usercmd.buttons & BUTTON_QUICKTHROW))
				{
					grenadeThrowState = GRENADETHROW_IDLE;
					gameLocal.SetSlowmo(false);
				}
			}
		}

		
	}
	else
	{
		//is leaning...

		if (grenadeThrowState != GRENADETHROW_IDLE)
		{
			//kick player out of throw mode.
			grenadeThrowState = GRENADETHROW_IDLE;
			gameLocal.SetSlowmo(false);
			SetThrowArcVisible(false);
		}
	}

	// update our ammo clip in our inventory
	if ( ( currentWeaponSlot >= 0 ) && ( currentWeaponSlot < MAX_HOTBARSLOTS ) )
	{
		inventory.hotbarSlots[currentWeaponSlot].clip = weapon.GetEntity()->AmmoInClip();
		if ( hud && ( currentWeaponSlot == idealWeaponSlot ) ) {
			UpdateHudAmmo( hud );
		}
	}
}

/*
===============
idPlayer::Weapon_NPC
===============
*/
void idPlayer::Weapon_NPC( void ) {
	if ( idealWeaponSlot != currentWeaponSlot ) {
		Weapon_Combat();
	}
	StopFiring();
	weapon.GetEntity()->LowerWeapon();

	if ( ( usercmd.buttons & BUTTON_ATTACK ) && !( oldButtons & BUTTON_ATTACK ) ) {
		buttonMask |= BUTTON_ATTACK;
		focusCharacter->TalkTo( this );
	}
}

/*
===============
idPlayer::LowerWeapon
===============
*/
void idPlayer::LowerWeapon( void ) {
	if ( weapon.GetEntity() && !weapon.GetEntity()->IsHidden() ) {
		weapon.GetEntity()->LowerWeapon();
	}
}

/*
===============
idPlayer::RaiseWeapon
===============
*/
void idPlayer::RaiseWeapon( void ) {
	if ( weapon.GetEntity() && weapon.GetEntity()->IsHidden() ) {
		weapon.GetEntity()->RaiseWeapon();
	}
}

/*
===============
idPlayer::WeaponLoweringCallback
===============
*/
void idPlayer::WeaponLoweringCallback( void ) {
	SetState( "LowerWeapon", true );
}

/*
===============
idPlayer::WeaponRisingCallback
===============
*/
void idPlayer::WeaponRisingCallback( void ) {
	SetState( "RaiseWeapon", true);


	//BC Update hotbar highlight. We do it here because we want the highlight to only change when the on-screen weapon actually changes.
	//We don't want the hotbar highlight to change immediately on the button press because if the weapon is in mid-reload or mid-something, it's visually confusing to have the UI and on-screen weapon not match up.
	UpdateHotbarHighlight(true);
}

/*
===============
idPlayer::Weapon_GUI
===============
*/
void idPlayer::Weapon_GUI( void ) {

	if ( (!objectiveSystemOpen && !contextMenuActive) || armstatsActive) { //Lower weapon when using guis
		if ( idealWeaponSlot != currentWeaponSlot ) {
			Weapon_Combat();
		}
		StopFiring();
		weapon.GetEntity()->LowerWeapon();
	}

	// disable click prediction for the GUIs. handy to check the state sync does the right thing
	if ( gameLocal.isClient && !net_clientPredictGUI.GetBool() ) {
		return;
	}

	if ((oldButtons ^ usercmd.buttons) & BUTTON_CONTEXTMENU)
	{
		sysEvent_t ev;
		const char *command = NULL;
		bool updateVisuals = false;

		idUserInterface *ui = ActiveGui();

		if (ui)
		{
			ev = sys->GenerateMouseButtonEvent(2, (usercmd.buttons & BUTTON_CONTEXTMENU) != 0);
			command = ui->HandleEvent(&ev, gameLocal.time, &updateVisuals);

			if (updateVisuals && focusGUIent && ui == focusUI)
			{
				focusGUIent->UpdateVisuals();
			}
		}

		if (gameLocal.isClient)
		{
			// we predict enough, but don't want to execute commands
			return;
		}

		if (focusGUIent) {
			HandleGuiCommands(focusGUIent, command);
		}
		else {
			HandleGuiCommands(this, command);
		}
	}


	// If the cvar is set or we're in full screen email, use the mouse click. Otherwise, us frob
	bool allowLeftClickGUI = gui_inGameLeftClick.GetBool() || emailFullscreenState != EFS_OFF || contextMenuActive || levelselectMenuActive || gameEdit->editmenuActive;
	int guiButton = allowLeftClickGUI ? BUTTON_ATTACK : BUTTON_FROB;

	if ( ( oldButtons ^ usercmd.buttons ) & guiButton) {
		sysEvent_t ev;
		const char *command = NULL;
		bool updateVisuals = false;

		idUserInterface *ui = ActiveGui();

		// If we're trying to transition into the email view, we need to bypass the click and do the zoom instead
		if (emailFullscreenState == EFS_OFF && focusGUIent && focusGUIent->spawnArgs.GetBool("fullscreenzoom"))
		{
			//Do the zoom.
			emailFullscreenEnt = focusGUIent;
			SetEmailFullscreen(true);
			return;
		}

		if ( ui ) {
			ev = sys->GenerateMouseButtonEvent( 1, ( usercmd.buttons & guiButton ) != 0 );
			command = ui->HandleEvent( &ev, gameLocal.time, &updateVisuals );
			if ( updateVisuals && focusGUIent && ui == focusUI ) {
				focusGUIent->UpdateVisuals();
			}
		}
		if ( gameLocal.isClient ) {
			// we predict enough, but don't want to execute commands
			return;
		}
		if ( focusGUIent ) {
			HandleGuiCommands( focusGUIent, command );
		} else {
			HandleGuiCommands( this, command );
		}
	}
	static bool flagImpulsed = (usercmd.flags & UCF_IMPULSE_SEQUENCE);
	bool curImpulse = (usercmd.flags & UCF_IMPULSE_SEQUENCE);

	if (curImpulse != flagImpulsed){
		bool wheelUpPressed = usercmd.impulse == IMPULSE_15;
		bool wheelDownPressed = usercmd.impulse == IMPULSE_14;

		if (wheelUpPressed || wheelDownPressed) {
			const char* command = NULL;
			idUserInterface *ui = ActiveGui();
			if (ui) {
				bool updateVisuals = false;

				int wheelButton = wheelUpPressed ? K_UPARROW : K_DOWNARROW;
				sysEvent_t ev;
				ev.evType = SE_KEY;
				ev.evValue = wheelButton;
				ev.evValue2 = 1;
				ev.evPtrLength = 0;
				ev.evPtr = NULL;

				command = ui->HandleEvent(&ev, gameLocal.time, &updateVisuals);
				if (focusGUIent) {
					HandleGuiCommands(focusGUIent, command);
				}
				else {
					HandleGuiCommands(this, command);
				}
			}
		}
	}
	flagImpulsed = curImpulse;
}

/*
===============
idPlayer::UpdateWeapon
===============
*/
void idPlayer::UpdateWeapon( void ) {
	if ( health <= 0 ) {
		return;
	}

	if (peekObject.IsValid()) //no weapon interaction while looking through ventpeek.
	{
		// Telescope ventpeek may have the ability to take a photo (note: this is largely just for flavour EXCEPT when ending the sequence)
		if (peekObject.GetEntity()->IsType(idVentpeek::Type) && static_cast<idVentpeek*>(peekObject.GetEntity())->forTelescope)
		{
			//Handle telescope stuff
			idVentpeekTelescope* telescope = static_cast<idVentpeekTelescope*>(peekObject.GetEntity());
			if (telescope->CanTakePhoto() && (usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
			{
				telescope->TakePhoto();
			}
		}
		
		if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
		{
			//zoom mode LMB inspect mode.
			HandleZoomInspectPressFire();
		}

		return;
	}

	assert( !spectating );

	if ( gameLocal.isClient ) {
		// clients need to wait till the weapon and it's world model entity
		// are present and synchronized ( weapon.worldModel idEntityPtr to idAnimatedEntity )
		if ( !weapon.GetEntity()->IsWorldModelReady() ) {
			return;
		}
	}

	// always make sure the weapon is correctly setup before accessing it
	if ( !weapon.GetEntity()->IsLinked() ) {
		int weaponType = (idealWeaponSlot == -1) ? 0 : inventory.hotbarSlots[idealWeaponSlot].weaponType;
		int clip = ( idealWeaponSlot == -1 ) ? 0 : inventory.hotbarSlots[idealWeaponSlot].clip;
		animPrefix = spawnArgs.GetString( va( "def_weapon%d", weaponType ) );
		weapon.GetEntity()->GetWeaponDef( animPrefix, clip );
		assert( weapon.GetEntity()->IsLinked() );
	}

	if ( hiddenWeapon && tipUp && usercmd.buttons & BUTTON_ATTACK ) {
		HideTip();
	}


	
	if (zoommodeActive && (usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
	{
		//zoom mode LMB inspect mode.
		HandleZoomInspectPressFire();
	}

	if (jockeyState == JCK_ATTACHED)
	{
		Weapon_Jockey();
	}
	else if (ShouldLowerWeapon()) //Player is doing something that should lower the weapon. Example: clambering.
	{
		StopFiring();
		weapon.GetEntity()->LowerWeapon();		

		//all left click to close the watch
		if ((((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK)) || physicsObj.GetClamberState() == CLAMBERSTATE_RAISING || physicsObj.GetClamberState() == CLAMBERSTATE_SETTLING) && armstatsActive && (gameLocal.time > armstatsTimer + 200))
		{
			SetArmStatsActive(false);
			nextAttackTime = gameLocal.time + 300;
		}


		if (g_dragEntity.GetBool())
			dragEntity.Update( this );

		if (bodyDragger.isDragging)
		{
			bodyDragger.Update(this);
			
			if (ActiveGui() && contextMenuActive)
			{
				//if context menu, then handle it.
				Weapon_GUI();
			}

			if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK) && !contextMenuActive && !armstatsActive)
			{
				//Press attack to throw the body.
				bodyDragger.dragEnt.GetEntity()->throwTime = gameLocal.time;
				bodyDragger.StopDrag(true);
				nextAttackTime = gameLocal.time + 200;
				return;
			}
		}

		lastThrowArcState = shouldDrawThrowArc;
		if (carryableItem.IsValid() && !zoommodeActive)
		{
			UpdateCarryableItem(); //Update carryable's position.
			Weapon_GUI();

			if (!IsLeaning() && !weapon.GetEntity()->IsInspectingChamber() && !iteminspectActive && memorypalaceState != MEMP_ACTIVE) //dont allow item throw/use when it's being inspected.
			{
				//Handle player pressing LMB while holding a carryable.
				if (grenadeThrowState == GRENADETHROW_IDLE && !contextMenuActive && !armstatsActive)
				{
					if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK) 
						&& gameLocal.time >= nextAttackTime && !ActiveGui())
					{						
						if (carryableItem.GetEntity()->spawnArgs.GetBool("carryfrob"))
						{
							idStr carryfrobsound = carryableItem.GetEntity()->spawnArgs.GetString("snd_carryfrob");
							if (carryfrobsound.Length() > 0)
							{
								carryableItem.GetEntity()->StartSound("snd_carryfrob", SND_CHANNEL_ANY);
							}

							//Frob held item.
							carryableItem.GetEntity()->DoFrob(CARRYFROB_INDEX, this);							
							nextAttackTime = gameLocal.time + 400; //how often can it be re-fired
							return;
						}
						else
						{
							//Player pressed LMB while holding a carrayble.
							
							if (!DoCarryablePlacerLogic())
							{
								//Player pressed LMB, but the item does not have any LMB functionality.

								StartSound("snd_error", SND_CHANNEL_ANY);
							}

							return;
						}
					}
				}


				//THROWING CODE FOR CARRYABLE ITEMS.
				if (grenadeThrowState == GRENADETHROW_IDLE && !influenceActive && !hiddenWeapon && (usercmd.buttons & BUTTON_QUICKTHROW))
				{
					grenadeThrowState = GRENADETHROW_AIMING;
				}
				else if (/*grenadeThrowState == GRENADETHROW_IDLE ||*/ grenadeThrowState == GRENADETHROW_AIMING)
				{
                    UpdateGrenadethrowStamina();

					if ((usercmd.buttons & BUTTON_QUICKTHROW) && !weaponGone)
					{
						grenadeThrowState = GRENADETHROW_AIMING;

						if (grenadeButtonTimer <= 0)
						{
							grenadeButtonTimer = gameLocal.time + GRENADE_THROW_HOLDTIME;
						}

						if (gameLocal.time >= grenadeButtonTimer && !GetThrowArcVisible() && (gameLocal.slowmoState == SLOWMO_STATE_OFF || gameLocal.slowmoState == SLOWMO_STATE_RAMPDOWN))
						{
							SetThrowArcVisible(true);
							gameLocal.SetSlowmo(true); //In throw mode, go to slow motion.
						}

						if (GetThrowArcVisible())
						{
							throwarcDropMode = IsThrowarcAtDropPosition() && (lastThrowArcState == shouldDrawThrowArc);

							hud->SetStateString("throwtext", throwarcDropMode ? "Drop" : "Throw");
							if (lastThrowarcDropMode != throwarcDropMode)
							{
								lastThrowarcDropMode = throwarcDropMode;
								hud->HandleNamedEvent("onChangeThrowmode");
							}
						}
					}
					else if (oldButtons & BUTTON_QUICKTHROW)
					{
						//Player has released the throw button. Cancel the throw. (CARRYABLE)

						SetThrowArcVisible(false);
						grenadeThrowState = GRENADETHROW_NOTREADY;
						grenadeButtonTimer = 0;
						StartSound("snd_cancel", SND_CHANNEL_ANY);
						throwarcDropMode = false;
					}

					if (shouldDrawThrowArc)
					{
						UpdateThrowableAIDodge(GetPhysics()->GetOrigin() + idVec3(0, 0, 48), false);
					}

					//Confirm throw. (CARRYABLES)
					if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
					{
						if (throwarcDropMode)
						{
							//Drop the carryable.
							DropCurrentCarryable(throwdisc, false);

							idAngles discAngle = throwdisc->GetPhysics()->GetAxis().ToAngles();
							discAngle.pitch += 90;
							gameLocal.DoParticle("smoke_ring16.prt", throwdisc->GetPhysics()->GetOrigin(), discAngle.ToForward());
						}
						else
						{
							//throw it.
							ThrowCarryable();
						}

						//AI_ATTACK_HELD = false;
						SetThrowArcVisible(false);
						grenadeThrowState = GRENADETHROW_FIRINGINPROGRESS;
						grenadeButtonTimer = gameLocal.time + 100;

						throwarcDropMode = false;
						return;
					}
				}
				else if (grenadeThrowState == GRENADETHROW_FIRINGINPROGRESS)
				{
					if (gameLocal.time >= grenadeButtonTimer)
					{
						grenadeButtonTimer = 0;
						grenadeThrowState = GRENADETHROW_IDLE;
						//weapon.GetEntity()->EndAttack();
						gameLocal.SetSlowmo(false);
					}
				}
				else if (grenadeThrowState == GRENADETHROW_NOTREADY)
				{
					//Wait for player to release button.
					if (!(usercmd.buttons & BUTTON_QUICKTHROW))
					{
						grenadeThrowState = GRENADETHROW_IDLE;
						gameLocal.SetSlowmo(false);
					}
				}
			}
			else if (!iteminspectActive && memorypalaceState != MEMP_ACTIVE)
			{
				if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
				{
					StartSound("snd_error", SND_CHANNEL_ANY);
				}

				if (grenadeThrowState != GRENADETHROW_IDLE)
				{
					//kick player out of throw mode.
					grenadeThrowState = GRENADETHROW_IDLE;
					gameLocal.SetSlowmo(false);
					SetThrowArcVisible(false);
				}
			}




		}


		//special case for lowered beacon: we want to still recognize its LMB presses.
		//Generally we ignore LMB when the weapon is lowered. But for the signal lamp we want to confirm LMB presses.
		if (weapon.IsValid())
		{
			if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK) && weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
			{
				if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.IsValid())
				{
					if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idBeaconLogic::Type))
					{
						//pressed LMB while holding beacon weapon.
						idEntity* signallampEnt = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity();
						static_cast<idBeaconLogic*>(signallampEnt)->FlashConfirm();
					}
				}
			}

			//Fix bug where player would get stuck in contextmenu if contextmenu is opened while aiming the lifeboat beacon landing position.
			if (weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
			{
				Weapon_GUI();
			}
		}

		////LMB to interact with keypad.
		//if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK) && IsLookingatKeypad())
		//{
		//	//frob the keypad button.
		//	frobEnt->DoFrob(0, this);
		//}
	}
	else if (physicsObj.GetFallState() == FALLEN_RISING || physicsObj.GetFallState() == FALLEN_HEADONGROUND || physicsObj.GetFallState() == FALLEN_GETUP_KICKUP || AI_FALLEN_ROLL || physicsObj.GetSwoopState())
	{
		//BC lower weapon when in fallen state.
		StopFiring();
		weapon.GetEntity()->LowerWeapon();
	}
	else if ( ActiveGui() )
	{
		// gui handling overrides weapon use
		Weapon_GUI();
	}
	else	if ( focusCharacter && ( focusCharacter->health > 0 ) )
	{
		Weapon_NPC();
	}
	else
	{
		Weapon_Combat();

		//BC for making the signal lamp show the key prompt for inspecting the weapon
		//if (weapon.IsValid() && weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
		//{
		//	weapon.GetEntity()->GetRenderEntity()->gui[1]->SetStateString("rack_key", gameLocal.GetKeyFromBinding("_rackslide"));
		//}
	}


	if ( hiddenWeapon )
	{
		//Gets called when player is doing heal animation.
		weapon.GetEntity()->LowerWeapon();
	}

	//What conditons make the carryable item hide itself.
	if (hiddenWeapon || ActiveGui() || zoommodeActive || memorypalaceState != MEMP_NONE)
	{
		if (carryableItem.IsValid())
		{
			if (!carryableItem.GetEntity()->IsHidden())
			{
				carryableItem.GetEntity()->Hide();
			}
		}
	}
	else
	{
		if (carryableItem.IsValid())
		{
			if (carryableItem.GetEntity()->IsHidden())
			{
				carryableItem.GetEntity()->Show();
			}
		}
	}


	if (shouldDrawThrowArc )
	{
        //Draw the throw arc.
		DrawThrowArc();
	}
	else
	{
		if (!throwBeamOrigin[0]->IsHidden())
		{
			//Hide the throw arc.
			int i;
			for (i = 0; i < THROWARC_BEAMCOUNT; i++)
			{
				throwBeamOrigin[i]->Hide();
			}
		}

		throwdisc->Hide();
		throwPredictionModel->Hide();
        tele_ui_entity->Hide();
		tele_ui_disc->Hide();
	}

	// update weapon state, particles, dlights, etc
	weapon.GetEntity()->PresentWeapon( showWeaponViewModel );
}

//Determines when the player weapon should be lowered. Example: when clambering.
bool idPlayer::ShouldLowerWeapon()
{
	if (carryableItem.IsValid() || bodyDragger.isDragging || g_dragEntity.GetBool() || (physicsObj.GetClamberState() == CLAMBERSTATE_RAISING
		|| physicsObj.GetClamberState() == CLAMBERSTATE_SETTLING) || mechTransitionState == MECHTRANSITION_ENTERING
		|| mechTransitionState == MECHTRANSITION_MOVINGTOBEHIND || peekObject.IsValid() || armstatsActive || physicsObj.GetAcroType() != ACROTYPE_NONE)
		return true;


	//We want to lower the weapon when using a keypad, because it feels natural to use LMB on keypads.
	//if (IsLookingatKeypad())
	//{
	//	return true;
	//}
		



	//Lower the signal lamp when the player is aiming the lifeboat landing position.
	if (weapon.IsValid())
	{
		if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.IsValid() && weapon.GetEntity()->spawnArgs.GetBool("hasbeacon"))
		{
			if (static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->signallampEntity.GetEntity()->IsType(idBeaconLogic::Type))
			{
				return true;
			}
		}
	}

	return false;
}

bool idPlayer::IsLookingatKeypad()
{
	if (frobEnt != NULL)
	{
		if (frobEnt->IsType(idFrobcube::Type))
		{
			if (frobEnt->GetPhysics()->GetClipModel()->GetOwner() != nullptr)
			{
				if (frobEnt->GetPhysics()->GetClipModel()->GetOwner()->IsType(idKeypad::Type))
				{
					//Player is looking at a keypad.
					return true;
				}
			}
		}
	}

	return false;
}

/*
===============
idPlayer::DrawThrowArc()
===============
*/
void idPlayer::DrawThrowArc()
{
	int k;
	trace_t trArc;
	idVec3 viewRight, viewForward, throwForward;
	bool colorCounter = false;
	int arcCount = 0;
	int i;
	idVec3 gravityVec = airless ? idVec3(0, 0, 0) : gameLocal.GetGravity();
	idVec3 lastDrawPoint;
	idMat3 lastOrientation;
	idVec3 actualCarryPos = idVec3(0.f, 0.f, 0.f);

	viewAngles.ToVectors(&viewForward, &viewRight, NULL);
	throwForward = viewForward;

	if (!airless)
		throwForward.z += QUICKTHROW_UPWARD_DIR;

	throwForward.Normalize();

	// Figure out whether we're going to throw a weapon or a carryable.
	idPhysics* physicsObj;
	if (GetCarryable() != NULL)
	{
		physicsObj = GetCarryable()->GetPhysics();
		// Save the true position because for the throw arc we have to fake the position
		actualCarryPos = physicsObj->GetOrigin();
		idVec3 carryOffset = GetCarryableOffset();
		physicsObj->SetOrigin( firstPersonViewOrigin + viewForward * carryOffset.x + viewRight * carryOffset.y );
		throwPredictionModel->SetModel(GetCarryable()->GetRenderEntity()->hModel->Name());
		throwPredictionModel->SetAxis(GetCarryable()->GetPhysics()->GetAxis());
	}
	else if (throwWeaponPhysicsObj)
	{
		// If we're throwing a weapon, we find the 'abstract' physics object that we created when we last switched weapons
		physicsObj = throwWeaponPhysicsObj;
		physicsObj->SetOrigin(firstPersonViewOrigin + viewRight * QUICKTHROW_OFFSET_RIGHT);
		physicsObj->SetAxis(weapon.GetEntity()->GetWorldModelAxis());
	}
	else
	{
		physicsObj = NULL;
	}

	if (physicsObj && physicsObj->IsType(idPhysics_RigidBody::Type))
	{
		// SW: Set up our theoretical 'throw'. We extract the rigidbody state and physical properties from the object,
		// allowing us to accurately predict how it will fly through the air.
		rigidBodyPState_t currentState = static_cast<idPhysics_RigidBody*>(physicsObj)->GetCurrentState();
		rigidBodyPState_t nextState = currentState;
		throwPredictionIntegrator->SetRigidBodyData(physicsObj);

		// SW: Set the initial linear momentum -- this should bleed off as gravity/friction take over
		// The formula here should be mass multiplied by the velocity applied by ThrowCarryable()/ThrowWeapon()
		currentState.i.linearMomentum = throwForward * GetThrowPower(GetCarryable()) * physicsObj->GetMass();
		currentState.i.angularMomentum = (GetThrowAngularVelocity() * physicsObj->GetMass());

		lastDrawPoint = currentState.i.position;
		lastOrientation = currentState.i.orientation;

		for (k = 0; k < 256; k += 1)
		{
			nextState = PredictNextThrowArc(currentState, gravityVec, MS2SEC(THROWARC_INTERVAL), physicsObj->GetMass(), static_cast<idPhysics_RigidBody*>(physicsObj)->GetCenterOfMass());

			if (k > 0)
			{
				// SW: This covers the eventuality in zero-G where the predicted arc slowly loses all its momentum and comes to a halt in space.
				// We don't want to be performing unnecessary work, so we break out when the difference grows too small
				if ((nextState.i.position - currentState.i.position).LengthFast() < 3)
					break;

				// SW: We need to calculate every interval for accuracy, but we don't need to *draw* every interval.
				// To simplify the drawn arc (and avoid calling a ridiculous number of traces), we only draw once every THROWARC_DRAWINTERVAL intervals
				if (k % THROWARC_DRAWINTERVAL == 0)
				{
					gameLocal.clip.Translation(
						trArc,
						lastDrawPoint,
						nextState.i.position,
						physicsObj->GetClipModel(),
						lastOrientation,
						MASK_SOLID | MASK_SHOT_RENDERMODEL | MASK_OPAQUE,
						( GetCarryable() != NULL ) ? GetCarryable() : this
					);
					if (arcCount <= THROWARC_BEAMCOUNT - 1)
					{
						throwBeamOrigin[arcCount]->Show();
						throwBeamOrigin[arcCount]->GetPhysics()->SetOrigin(lastDrawPoint);
						throwBeamTarget[arcCount]->GetPhysics()->SetOrigin(trArc.endpos);
						arcCount++;
					}

					lastDrawPoint = trArc.endpos;
					lastOrientation = trArc.endAxis;

					if (trArc.fraction < 1) //hit a wall. exit.
					{
						break;
					}

					colorCounter = !colorCounter;
				}
			}

			currentState = nextState;
		}
	}
	//Hide the rest of the arc beams.
	bool hideAllBeam = (lastThrowArcState != shouldDrawThrowArc) || throwarcDropMode;

	int hideBeamStart = hideAllBeam ? 0 : arcCount;
	if (hideBeamStart < THROWARC_BEAMCOUNT)
	{
		for (i = hideBeamStart; i < THROWARC_BEAMCOUNT; i++)
		{
			throwBeamOrigin[i]->Hide();
		}
	}

	idVec3 landcircleNormal = trArc.c.normal;
	//landcircleNormal.z = -landcircleNormal.z;
	//gameRenderWorld->DebugCircle(colorWhite, trArc.endpos, landcircleNormal, 16, 12, 1, true);
	//gameRenderWorld->DebugCircle(colorWhite, trArc.endpos, landcircleNormal, 1, 4, 1, true);


	bool isAimingAtActor = false;
	if (trArc.c.entityNum <= MAX_GENTITIES - 2 && trArc.c.entityNum > 0)
	{
		//see if this is an actor.
		if (gameLocal.entities[trArc.c.entityNum])
		{
			if (gameLocal.entities[trArc.c.entityNum]->IsType(idActor::Type))
			{
				isAimingAtActor = true;
			}
			else
			{
				//See if item is bound to actor.
				if (gameLocal.entities[trArc.c.entityNum]->GetBindMaster() != NULL)
				{
					if (gameLocal.entities[trArc.c.entityNum]->GetBindMaster()->IsType(idActor::Type))
					{
						isAimingAtActor = true;
					}
				}
			}
		}
	}

	throwdisc->Show();
	throwdisc->SetOrigin(trArc.endpos);

	if (isAimingAtActor)
	{
		//throwdisc is on an actor. make it directly face the player camera.
		idMat3 playerViewMat = viewAngles.ToMat3();
		throwdisc->SetAxis(playerViewMat);
	}
	else
	{
		//throwdisc is on a non-actor. make it face the normal it's hitting.
		throwdisc->SetAxis(landcircleNormal.ToMat3());
	}

	throwPredictionModel->SetAxis(trArc.endAxis);
	throwPredictionModel->SetOrigin(trArc.endpos);
	//throwPredictionModel->Show(); //BC hide for now, until we figure out which items we want to draw/not draw

    throwarcCollision = trArc; //this is used for telepuck predicted position UI.

	// For carryables, set the position back to the real one
	if (GetCarryable() != NULL && physicsObj) {
		physicsObj->SetOrigin(actualCarryPos);
	}
}

/*
===============
idPlayer::PredictThrowArc()

	SW: A carbon copy of the evaluation code used by physics rigidbodies.
	We unfortunately *do* have to deal with rotational transformations, 
	as thrown objects will rotate as they fly (deterministically, thank god)
===============
*/
rigidBodyPState_t idPlayer::PredictNextThrowArc(rigidBodyPState_t currentState, idVec3 gravityVector, float deltaTime, float mass, idVec3 centerOfMass)
{
	rigidBodyPState_t nextState;
	idVec3 position;

	position = currentState.i.position;
	currentState.i.position += centerOfMass * currentState.i.orientation;

	currentState.i.orientation.TransposeSelf();

	throwPredictionIntegrator->Evaluate((float*)&currentState.i, (float*)&nextState.i, 0, deltaTime);
	nextState.i.orientation.OrthoNormalizeSelf();

	// The integrator doesn't take gravity into account for some godforsaken reason (?)
	nextState.i.linearMomentum += (gravityVector * deltaTime * mass);

	currentState.i.orientation.TransposeSelf();
	nextState.i.orientation.TransposeSelf();

	currentState.i.position = position;
	nextState.i.position -= centerOfMass * nextState.i.orientation;

	return nextState;
}

bool idPlayer::GetThrowArcVisible()
{
	return shouldDrawThrowArc;
}

void idPlayer::SetThrowArcVisible(bool value)
{
	shouldDrawThrowArc = value;

	if (weapon.GetEntity() != NULL)
	{
		weapon.GetEntity()->SetAimMode(value);
	}

	if (!value)
	{
		//Turn off grenade arc.
		//Turn off slow mo.
		gameLocal.SetSlowmo(false);
	}
}

/*
===============
idPlayer::SpectateFreeFly
===============
*/
void idPlayer::SpectateFreeFly( bool force ) {
	idPlayer	*player;
	idVec3		newOrig;
	idVec3		spawn_origin;
	idAngles	spawn_angles;

	player = gameLocal.GetClientByNum( spectator );
	if ( force || gameLocal.time > lastSpectateChange ) {
		spectator = entityNumber;
		if ( player && player != this && !player->spectating && !player->IsInTeleport() ) {
			newOrig = player->GetPhysics()->GetOrigin();
			if ( player->physicsObj.IsCrouching() ) {
				newOrig[ 2 ] += pm_crouchviewheight.GetFloat();
			} else {
				newOrig[ 2 ] += pm_normalviewheight.GetFloat();
			}
			newOrig[ 2 ] += SPECTATE_RAISE;
			idBounds b = idBounds( vec3_origin ).Expand( pm_spectatebbox.GetFloat() * 0.5f );
			idVec3 start = player->GetPhysics()->GetOrigin();
			start[2] += pm_spectatebbox.GetFloat() * 0.5f;
			trace_t t;
			// assuming spectate bbox is inside stand or crouch box
			gameLocal.clip.TraceBounds( t, start, newOrig, b, MASK_PLAYERSOLID, player );
			newOrig.Lerp( start, newOrig, t.fraction );
			SetOrigin( newOrig );
			idAngles angle = player->viewAngles;
			angle[ 2 ] = 0;
			SetViewAngles( angle );
		} else {
			SelectInitialSpawnPoint( spawn_origin, spawn_angles );
			spawn_origin[ 2 ] += pm_normalviewheight.GetFloat();
			spawn_origin[ 2 ] += SPECTATE_RAISE;
			SetOrigin( spawn_origin );
			SetViewAngles( spawn_angles );
		}
		lastSpectateChange = gameLocal.time + 500;
	}
}

/*
===============
idPlayer::SpectateCycle
===============
*/
void idPlayer::SpectateCycle( void ) {
	idPlayer *player;

	if ( gameLocal.time > lastSpectateChange ) {
		int latchedSpectator = spectator;
		spectator = gameLocal.GetNextClientNum( spectator );
		player = gameLocal.GetClientByNum( spectator );
		assert( player ); // never call here when the current spectator is wrong
		// ignore other spectators
		while ( latchedSpectator != spectator && player->spectating ) {
			spectator = gameLocal.GetNextClientNum( spectator );
			player = gameLocal.GetClientByNum( spectator );
		}
		lastSpectateChange = gameLocal.time + 500;
	}
}

/*
===============
idPlayer::UpdateSpectating
===============
*/
bool idPlayer::UpdateSpectating( void ) {
	assert( spectating );
	assert( !gameLocal.isClient );
	assert( IsHidden() );

	//BC retail code
	//idPlayer *player;
	//if ( !gameLocal.isMultiplayer ) {
	//	return;
	//}
	//player = gameLocal.GetClientByNum( spectator );
	//if ( !player || ( player->spectating && player != this ) ) {
	//	SpectateFreeFly( true );
	//} else if ( usercmd.upmove > 0 ) {
	//	SpectateFreeFly( false );
	//} else if ( usercmd.buttons & BUTTON_ATTACK ) {
	//	SpectateCycle();
	//}

	spectatorMenu->SetStateBool("draw_spectate", spectateUIActive);
	spectatorMenu->SetStateBool("draw_spectatestats", spectateStatsActive);


	//Delay before fanfare starts
	if (spectateState == SPC_FANFAREDELAY)
	{
		if (gameLocal.hudTime >= spectateTimer + 100)
		{
			spectateState = SPC_FANFAREPOST;
			spectatorMenu->HandleNamedEvent("victory");
		}
	}

	
	//BC press zoom to toggle entire UI
	if ((usercmd.buttons & BUTTON_ZOOM) && !(oldButtons & BUTTON_ZOOM))
	{
		StartSound("snd_click", SND_CHANNEL_ANY);
		spectateUIActive = !spectateUIActive;

		if (spectateTimelineEnt != NULL)
		{
			if (spectateTimelineEnt->IsType(idSpectateTimeline::Type))
			{
				static_cast<idSpectateTimeline *>(spectateTimelineEnt)->ToggleAllNodes(spectateUIActive);
			}			
		}
	}
	

	//Press lmb to ?????????
	if ( ( oldButtons ^ usercmd.buttons ) & BUTTON_ATTACK )
	{
		sysEvent_t ev;
		const char *command = NULL;
		bool updateVisuals = false;

		idUserInterface *ui = ActiveGui();
		if ( ui ) {
			ev = sys->GenerateMouseButtonEvent( 1, ( usercmd.buttons & BUTTON_ATTACK ) != 0 );
			command = ui->HandleEvent( &ev, gameLocal.time, &updateVisuals );
			if ( updateVisuals && focusGUIent && ui == focusUI ) {
				focusGUIent->UpdateVisuals();
			}
		}
		if ( gameLocal.isClient ) {
			// we predict enough, but don't want to execute commands
			return false;
		}
		if ( focusGUIent ) {
			HandleGuiCommands( focusGUIent, command );
		}
		else {
			HandleGuiCommands( this, command );
		}
	}

	//Press tab to toggle contextmenu
	if ((usercmd.buttons & BUTTON_CONTEXTMENU) && !(oldButtons & BUTTON_CONTEXTMENU))
	{
		EventlogMenuOpen(!eventlogMenuActive);
	}

	//Press bash to toggle stats display
	//if ((usercmd.buttons & BUTTON_BASH) && !(oldButtons & BUTTON_BASH))
	//{
	//	StartSound("snd_click", SND_CHANNEL_ANY);
	//	spectateStatsActive = !spectateStatsActive;
	//}

	//Hold frob to exit spectate and continue to next level.
	if (usercmd.buttons & BUTTON_FROB)
	{
		if ((oldButtons ^ usercmd.buttons) & BUTTON_FROB)
		{
			exitLevelHoldTimer = gameLocal.hudTime + SPECTATE_EXITHOLDTIME;
			StartSound("snd_guienter", SND_CHANNEL_ANY);
			postgameLoadButtonAvailable = true;
		}

		if (!spectateUIActive)
		{
			spectateUIActive = true;
		}

		//the little progress bar on holding down the button.
		float delta = (exitLevelHoldTimer - gameLocal.hudTime) / (float)(SPECTATE_EXITHOLDTIME);
		delta = 1.0f - delta;
		delta = idMath::ClampFloat(0, 1, delta);
		spectatorMenu->SetStateFloat("holdbar", delta);

		if ((gameLocal.hudTime > exitLevelHoldTimer) && exitLevelButtonAvailable)
		{
			exitLevelButtonAvailable = false; //set a flag to guarantee the level transition only happens once.
			gameLocal.spectatePause = false;

			if (spectateState == SPC_NONE)
			{
				//The player is DEAD.
				//So, we restart the map.
				
				//gameLocal.sessionCommand = "died"; //BC the restart screen.
				idStr mapName = gameLocal.GetMapNameStripped();
				if (mapName.Length() > 0)
				{
					idStr commandtext = idStr::Format("map %s", mapName.c_str());
					cmdSystem->BufferCommandText(CMD_EXEC_NOW, commandtext.c_str());
				}				
			}
			else
			{
				//The player is VICTORIOUS.
				//This runs the a function in the map script. It generally just calls sys.loadmap
				gameLocal.RunMapScript("_OnVictory");
			}

			return true;
		}
	}
	else
	{
		if (spectateState == SPC_NONE && postgameLoadButtonAvailable)
		{
			int buttonHoldDelta = (gameLocal.hudTime + SPECTATE_EXITHOLDTIME) - (exitLevelHoldTimer);
			if (buttonHoldDelta <= SPECTATE_LOADBUTTONTIME)
			{				
				//TODO: bring up load menu.				
			}
		}

		spectatorMenu->SetStateFloat("holdbar", 0);
		postgameLoadButtonAvailable = false;
	}
	
	return false;
}



/*
===============
idPlayer::HandleSingleGuiCommand
===============
*/
bool idPlayer::HandleSingleGuiCommand( idEntity *entityGui, idLexer *src ) {
	idToken token;

	if ( !src->ReadToken( &token ) ) {
		return false;
	}

	if ( token == ";" ) {
		return false;
	}

	//BC restart current mission.
	//if (!idStr::Icmp(cmd, "restartMission"))
	//{
	//	idStr mapName = gameLocal.GetMapName();
	//	if (mapName.Length() > 0)
	//	{
	//		cmdSystem->BufferCommandArgs(CMD_EXEC_APPEND, rl_args);
	//	}
	//
	//}
	
	if (token.Icmp("contextmenu_close") == 0)
	{
		//immediately close the menu. Player has cancelled out of the context menu.
		ContextmenuConfirm(false);

		return true;
	}
	else if (token.Icmp("contextmenu_threaten") == 0)
	{
		ContextmenuConfirm(true);

		StartSound("snd_threat", SND_CHANNEL_VOICE, 0, false, NULL);	
		gameLocal.SpawnInterestPoint(this, this->GetEyePosition(), spawnArgs.GetString("def_threaten"));
		DoLocalSoundwave(spawnArgs.GetString("model_soundwave"));

		gameLocal.AddEventLog("#str_def_gameplay_threatened", GetPhysics()->GetOrigin());

		return true;
	}
	else if (token.Icmp("contextmenu_snapfingers") == 0)
	{
		ContextmenuConfirm(true);

		StartSound("snd_snapfingers", SND_CHANNEL_VOICE, 0, false, NULL);
		gameLocal.SpawnInterestPoint(this, this->GetEyePosition(), spawnArgs.GetString("def_snapfingers"));

		gameLocal.AddEventLog("#str_def_gameplay_snapfingers", GetPhysics()->GetOrigin());
		DoLocalSoundwave(spawnArgs.GetString("model_soundwave"));

		return true;
	}
	else if (token.Icmp("contextmenu_liedown") == 0)
	{
		ContextmenuConfirm(true);

		if (airless)
		{
			SetCenterMessage("#str_def_gameplay_cannotlie");
		}
		else
		{
			SetFallState(true, false);
		}

		return true;
	}
	else if (token.Icmp("contextmenu_putoutfire") == 0)
	{
		ContextmenuConfirm(true);

		StartHealState(HEALSTATE_BURNING);

		return true;
	}
	else if (token.Icmp("contextmenu_bulletpluck") == 0)
	{
		ContextmenuConfirm(true);
		StartHealState(HEALSTATE_BULLETPLUCK);
		return true;
	}
	else if (token.Icmp("contextmenu_healburnwound") == 0)
	{
		//Player needs aloe. Check if player has aloe.

		idEntity *aloe = NULL;

		if (carryableItem.IsValid()) //First see if the player's current carryable is aloe.
		{
			if (carryableItem.GetEntity()->IsType(idAloe::Type))
			{
				aloe = carryableItem.GetEntity();
			}
		}
		
		if (!aloe)
		{
			aloe = GetCarryableFromInventory("weapon_aloeleaf"); //See if player has any aloe leaves.
		}

		if (!aloe)
		{
			aloe = GetCarryableFromInventory("weapon_aloeplant"); //Then see if player has aloe plant.
		}
		
		if (aloe)
		{
			aloe->DoFrob(CARRYFROB_INDEX, this);
			hud->HandleNamedEvent("onHealBurnwound");			
		}
		else
		{
			//Player doesn't have aloe.
			SetCenterMessage("#str_def_gameplay_aloe_needaloe");
		}
		


		ContextmenuConfirm(true);
		return true;
	}
	else if (token.Icmp("contextmenu_healglasswound") == 0)
	{
		ContextmenuConfirm(true);

		StartHealState(HEALSTATE_GLASSPULL);

		return true;
	}
	else if (token.Icmp("contextmenu_healspear") == 0)
	{
		ContextmenuConfirm(true);
		
		StartHealState(HEALSTATE_SPEARPLUCK);

		return true;
	}
	else if (token.Icmp("contextmenu_spit") == 0)
	{
		ContextmenuConfirm(true);

		//do spit.
		DoSpit(0);
		gameLocal.AddEventLog("#str_def_gameplay_spit", GetPhysics()->GetOrigin());

		return true;
	}
	else if (token.Icmp("contextmenu_bloodcough") == 0)
	{
		ContextmenuConfirm(true);

		//do spit.
		DoSpit(1);
		gameLocal.AddEventLog("#str_def_gameplay_coughblood", GetPhysics()->GetOrigin());

		return true;
	}
	else if (token.Icmp("contextmenu_autoaimtoggle") == 0)
	{
		ContextmenuConfirm(true);

		//toggle weapon autoaim.
		if (weapon.GetEntity() != NULL)
		{
			weapon.GetEntity()->autoaimEnabled = !weapon.GetEntity()->autoaimEnabled;
		}

		return true;
	}
	else if (token.Icmp("contextmenu_healbleedout") == 0)
	{
		ContextmenuConfirm(true);

		StartHealState(HEALSTATE_BLEEDOUT);

		return true;
	}
	else if (token.Icmp("contextmenu_healshrapnel") == 0)
	{
		ContextmenuConfirm(true);

		StartHealState(HEALSTATE_SHRAPNEL);

		return true;
	}
	else if (token.IcmpPrefix("contextmenu_selecthotbar") == 0)
	{
		ContextmenuConfirm(true);

		idStr hotbarStr = token.Right(1);
		int hotbarNum = atoi(hotbarStr);
		if (hotbarNum < 0 || hotbarNum >= inventory.hotbarUnlockedSlots)
			return false;

		SelectHotbarslot(hotbarNum);
		return true;
	}
	else if (token.IcmpPrefix("contextmenu_selectinv") == 0)
	{
		idStr weaponStr;
		if (token.Length() > 22) //Sometimes the number is single digit and sometimes it's double digit... accommodate for that here.
			weaponStr = token.Right(2);
		else
			weaponStr = token.Right(1);

		int weaponNum = atoi(weaponStr); //Convert string to integer.
		int hotbarSlot = inventory.GetHotbarslotViaWeaponIndex( weaponNum );
		SelectWeapon( hotbarSlot, weaponNum, false );

		ContextmenuConfirm(true);
		return true;
	}
	else if (token.Icmp("contextmenu_openeventlog") == 0)
	{
		//context menu. Open the event log.
		if (!eventlogMenuActive)
		{
			EventlogMenuOpen(true);
		}
	}
	else if (token.Icmp("contextmenu_memorypalace") == 0)
	{
		//context menu. Open the memory palace.
		if (contextMenuState == CONTEXTMENU_ACTIVE)
			StartMemoryPalace();

		ContextmenuConfirm(true);
	}
	else if (token.Icmp("contextmenu_map") == 0)
	{
		//context menu. Open the map.
		if (contextMenuState == CONTEXTMENU_ACTIVE)
		{			
			SetArmStatsActive(true);			
		}

		ContextmenuConfirm(true);
	}	
	else if (token.Icmp("close_eventlog") == 0)
	{
		//event log. The Exit button on event log.
		if (eventlogMenuActive)
		{
			EventlogMenuOpen(false);
		}
	}
	else if (token.Icmp("close_levelselect") == 0)
	{
		//close the level select menu.
		LevelselectMenuOpen(0);					
	}
	else if (token.Icmp("close_emailmenu") == 0)
	{
		//close the level select menu.
		SetEmailFullscreen(false);
	}
	else if (token.Icmp("edit_savelights") == 0)
	{
		//BC Lighteditor. Save the light changes.
		cmdSystem->BufferCommandText(CMD_EXEC_NOW, "saveLights");
		return true;
	}
	else if (token.Icmp("edit_resetlights") == 0)
	{
		//BC Lighteditor. Reset all lights and the current light edit UI
		cmdSystem->BufferCommandText(CMD_EXEC_NOW, "reloadLights");
		idEntity *selectedLight = gameEdit->GetFirstSelectedEntity();
		if (selectedLight)
		{
			idLight	*lightEnt = static_cast<idLight*>(selectedLight);

			if (lightEnt)
			{
				Lightedit_reset();
			}
		}
		return true;
	}
	else if (token.Icmp("edit_resetlight") == 0)
	{
		idEntity *selectedLight = gameEdit->GetFirstSelectedEntity();

		if (selectedLight)
		{
			idLight	*lightEnt = static_cast<idLight*>(selectedLight);

			if (lightEnt)
			{
				Lightedit_reset();
			}
		}
		return true;
	}
	else if (token.Icmp("edit_noshadows") == 0)
	{
		//BC lighteditor. Toggle the noshadow mode.
		int value = gameEdit->lighteditMenu->GetStateInt("ch_noshadows");

		idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();
		
		if (selectedLight)
		{
			idLight	*lightEnt = static_cast<idLight*>(selectedLight);

			if (lightEnt)
			{
				lightEnt->SetNoShadow(value > 0 ? false : true);
			}
		}

		return true;
	}
	else if (token.Icmp("edit_ambient") == 0)
	{
		//BC lighteditor. Toggle the ambient mode.
		int value = gameEdit->lighteditMenu->GetStateInt("ch_ambient");

		idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();

		if (selectedLight)
		{
			idLight	*lightEnt = static_cast<idLight*>(selectedLight);

			if (lightEnt)
			{
				lightEnt->Event_SetAmbient(value > 0 ? true : false);
			}
		}

		return true;
	}
	else if (token.Icmp("edit_lightactive") == 0)
	{
		//Toggle light on/off.
		int value = gameEdit->lighteditMenu->GetStateInt("ch_lightactive");

		idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();

		if (selectedLight)
		{
			idLight	*lightEnt = static_cast<idLight*>(selectedLight);

			if (lightEnt)
			{
				if (value)
					lightEnt->On();
				else
					lightEnt->Off();
			}
		}

		return true;
	}
	//else if (token.Icmp("edit_color") == 0)
	//{
	//	float val2 = gameEdit->lighteditMenu->GetStateFloat("slider_red_valueFloat");
	//	common->Printf("test test  red %f\n", val2);
	//}
	else if (token.Icmp("edit_shrink_x") == 0)
	{
		Lightedit_resize(idVec3(-16, 0, 0));
	}
	else if (token.Icmp("edit_expand_x") == 0)
	{
		Lightedit_resize(idVec3(16, 0, 0));
	}
	else if (token.Icmp("edit_shrink_y") == 0)
	{
		Lightedit_resize(idVec3(0, -16, 0));
	}
	else if (token.Icmp("edit_expand_y") == 0)
	{
		Lightedit_resize(idVec3(0, 16, 0));
	}
	else if (token.Icmp("edit_shrink_z") == 0)
	{
		Lightedit_resize(idVec3(0, 0, -16));
	}
	else if (token.Icmp("edit_expand_z") == 0)
	{
		Lightedit_resize(idVec3(0, 0, 16));
	}



	else if (token.Icmp("edit_move_x_bigminus") == 0)
	{
		Lightedit_reposition(idVec3(-8, 0, 0));
	}
	else if (token.Icmp("edit_move_x_smallminus") == 0)
	{
		Lightedit_reposition(idVec3(-1, 0, 0));
	}
	else if (token.Icmp("edit_move_x_smallplus") == 0)
	{
		Lightedit_reposition(idVec3(1, 0, 0));
	}
	else if (token.Icmp("edit_move_x_bigplus") == 0)
	{
		Lightedit_reposition(idVec3(8, 0, 0));
	}



	else if (token.Icmp("edit_move_y_bigminus") == 0)
	{
		Lightedit_reposition(idVec3(0, -8, 0));
	}
	else if (token.Icmp("edit_move_y_smallminus") == 0)
	{
		Lightedit_reposition(idVec3(0, -1, 0));
	}
	else if (token.Icmp("edit_move_y_smallplus") == 0)
	{
		Lightedit_reposition(idVec3(0, 1, 0));
	}
	else if (token.Icmp("edit_move_y_bigplus") == 0)
	{
		Lightedit_reposition(idVec3(0, 8, 0));
	}


	else if (token.Icmp("edit_move_z_bigminus") == 0)
	{
		Lightedit_reposition(idVec3(0, 0, -8));
	}
	else if (token.Icmp("edit_move_z_smallminus") == 0)
	{
		Lightedit_reposition(idVec3(0, 0, -1));
	}
	else if (token.Icmp("edit_move_z_smallplus") == 0)
	{
		Lightedit_reposition(idVec3(0, 0, 1));
	}
	else if (token.Icmp("edit_move_z_bigplus") == 0)
	{
		Lightedit_reposition(idVec3(0, 0, 8));
	}




	else if (token.Icmp("edit_shrink_all") == 0)
	{
		Lightedit_resize(idVec3(-16, -16, -16));
	}
	else if (token.Icmp("edit_expand_all") == 0)
	{
		Lightedit_resize(idVec3(16, 16, 16));
	}
	else if (token.Icmp("edit_rgbshrink") == 0)
	{
		//all color sliders.
		Lightedit_colordelta(-.1f);
	}
	else if (token.Icmp("edit_rgbexpand") == 0)
	{
		//all color sliders.
		Lightedit_colordelta(.1f);
	}


	if ( token.Icmp( "addhealth" ) == 0 ) {
		if ( entityGui && health < 100 ) {
			int _health = entityGui->spawnArgs.GetInt( "gui_parm1" );
			int amt = ( _health >= HEALTH_PER_DOSE ) ? HEALTH_PER_DOSE : _health;
			_health -= amt;
			entityGui->spawnArgs.SetInt( "gui_parm1", _health );
			if ( entityGui->GetRenderEntity() && entityGui->GetRenderEntity()->gui[ 0 ] ) {
				entityGui->GetRenderEntity()->gui[ 0 ]->SetStateInt( "gui_parm1", _health );
			}
			health += amt;
			if ( health > 100 ) {
				health = 100;
			}
		}
		return true;
	}

	if ( token.Icmp( "ready" ) == 0 ) {
		PerformImpulse( IMPULSE_17 );
		return true;
	}

	if ( token.Icmp( "updatepda" ) == 0 ) {
		UpdatePDAInfo( true );
		emailInSubMenu = true;
		return true;
	}

	if (token.Icmp("exitsubmenu") == 0) {
		emailInSubMenu = false;
		return true;
	}

	if ( token.Icmp( "updatepda2" ) == 0 ) {
		UpdatePDAInfo( false );
		return true;
	}

	if ( token.Icmp( "stoppdavideo" ) == 0 ) {
		if ( objectiveSystem && objectiveSystemOpen && pdaVideoWave.Length() > 0 ) {
			StopSound( SND_CHANNEL_PDA, false );
		}
		return true;
	}

	if ( token.Icmp( "close" ) == 0 ) {
		if ( objectiveSystem && objectiveSystemOpen ) {
			TogglePDA();
		}
	}

	if ( token.Icmp( "playpdavideo" ) == 0 ) {
		if ( objectiveSystem && objectiveSystemOpen && pdaVideo.Length() > 0 ) {
			const idMaterial *mat = declManager->FindMaterial( pdaVideo );
			if ( mat ) {
				int c = mat->GetNumStages();
				for ( int i = 0; i < c; i++ ) {
					const shaderStage_t *stage = mat->GetStage(i);
					if ( stage && stage->texture.cinematic ) {
						stage->texture.cinematic->ResetTime( gameLocal.time );
					}
				}
				if ( pdaVideoWave.Length() ) {
					const idSoundShader *shader = declManager->FindSound( pdaVideoWave );
					StartSoundShader( shader, SND_CHANNEL_PDA, 0, false, NULL );
				}
			}
		}
	}

	if ( token.Icmp( "playpdaaudio" ) == 0 ) {
		if ( objectiveSystem && objectiveSystemOpen && pdaAudio.Length() > 0 ) {
			const idSoundShader *shader = declManager->FindSound( pdaAudio );
			int ms;
			StartSoundShader( shader, SND_CHANNEL_PDA, 0, false, &ms );
			StartAudioLog();
			CancelEvents( &EV_Player_StopAudioLog );
			PostEventMS( &EV_Player_StopAudioLog, ms + 150 );
		}
		return true;
	}

	if ( token.Icmp( "stoppdaaudio" ) == 0 ) {
		if ( objectiveSystem && objectiveSystemOpen && pdaAudio.Length() > 0 ) {
			// idSoundShader *shader = declManager->FindSound( pdaAudio );
			StopAudioLog();
			StopSound( SND_CHANNEL_PDA, false );
		}
		return true;
	}

	//Email reply system.
	if (token.Icmp("emailreply1") == 0)
	{
		if (!emailReplyFunc1.IsEmpty())
		{
			if (g_debugEmailScript.GetBool())
			{
				common->Printf("Email: calling REPLYFUNC1 '%s'\n", emailReplyFunc1.c_str());
			}

			gameLocal.RunMapScript(emailReplyFunc1);
			CurrentEmailReplied();
		}
#if _DEBUG
		else
		{
			common->Warning("email: has no replyfunc1 script function.");
		}
#endif
		UpdatePDAInfo(false);
		return true;
	}

	//Email reply system.
	if (token.Icmp("emailreply2") == 0)
	{
		if (!emailReplyFunc2.IsEmpty())
		{
			if (g_debugEmailScript.GetBool())
			{
				common->Printf("Email: calling REPLYFUNC2 '%s'\n", emailReplyFunc1.c_str());
			}

			gameLocal.RunMapScript(emailReplyFunc2);
			CurrentEmailReplied();
		}
#if _DEBUG
		else
		{
			common->Warning("email: has no replyfunc2 script function.");
		}
#endif
		UpdatePDAInfo(false);
		return true;
	}

	if (token.IcmpPrefix("select_eventlog") == 0)
	{
		//what index is selected in event log.
		int eventIndex = eventlogMenu->State().GetInt("eventlist_sel_0", "0"); //Note: the name comes from the listDef's "listName" gui keyvalue.

		if (eventIndex >= 0 && eventIndex <= gameLocal.eventLogList.Num() - 1)
		{
			char listItem[2048];
			gameLocal.eventlogGuiList->SetSelection(eventIndex);
			gameLocal.eventlogGuiList->GetSelection(listItem, 2048);

			eventlogMenu->HandleNamedEvent("showpopup");
			eventlogMenu->SetStateString("popuptext", listItem);			
		}
		
		return true;
	}

	if (token.IcmpPrefix("select_levellist") == 0)
	{
		//what index is selected in level list log.
		int eventIndex = levelselectMenu->State().GetInt("levellist_sel_0", "0"); //Note: the name comes from the listDef's "listName" gui keyvalue.
		OnSelectLevelselectIndex(eventIndex);
		return true;
	}

	if (token.IcmpPrefix("set_levelselect") == 0)
	{
		//when player starts a level select mission.
		int eventIndex = levelselectMenu->State().GetInt("levellist_sel_0", "0"); //Note: the name comes from the listDef's "listName" gui keyvalue.
		OnStartLevelselectIndex(eventIndex);
		return true;
	}

	

	src->UnreadToken( &token );
	return false;
}

//Open or close the levelselect menu.
void idPlayer::LevelselectMenuOpen(int value)
{
	if (value > 0)
	{
		//turn on.
		levelselectMenu->SetCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //move mouse to screen center.
		oldMouseX = usercmd.mx;
		oldMouseY = usercmd.my;

		levelselectMenuActive = true;
		session->SetGUI(levelselectMenu, NULL);

		UpdateLevelselectMenu();

		return;
	}

	session->SetGUI(NULL, NULL);
	levelselectMenuActive = false;
}

bool idPlayer::LevelHasAnyMilestones(const idDeclEntityDef* mapDef)
{
	idStr milestone0 = mapDef->dict.GetString("milestone0");
	idStr milestone1 = mapDef->dict.GetString("milestone1");
	idStr milestone2 = mapDef->dict.GetString("milestone2");

	if (milestone0.Length() > 0 || milestone1.Length() > 0 || milestone2.Length() > 0)
		return true;

	return false;	
}

//When the levelselect menu is opened up. Initialize all the info in it.
void idPlayer::UpdateLevelselectMenu()
{
	//update the level select gui.

	//levelselectMenu
	if (levelselectGuiList != NULL)
		return;

	idList<idStr> mapnames; //this is a list of level display names (not internal name).
	idList<int> milestones; //this is a list of milestone coins earned per level. This has to retain parity with the above 'mapnames' variable.
	int num = declManager->GetNumDecls(DECL_MAPDEF);
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (!mapDef)
			continue;

		int levelindex = mapDef->dict.GetInt("levelindex", "-1");

		if (levelindex <= -1)
			continue; //no map index. ignore it.

		if (levelindex > levelProgressIndex)
			continue; //haven't done this level yet.

		idStr mapname = common->GetLanguageDict()->GetString(mapDef->dict.GetString("name"));
		mapnames.Append(mapname.c_str());

		//Determine how many milestones the player has earned in this level.
		int milestoneCount = 0;
		for (int k = 0; k < MAXMILESTONES; k++)
		{
			idStr milestoneName = gameLocal.GetMilestonenameViaLevelIndex(levelindex, k);
			if (milestoneName.Length() > 0)
			{
				if (gameLocal.persistentLevelInfo.GetBool(milestoneName))
				{
					milestoneCount++;
				}
			}
		}

		if (!LevelHasAnyMilestones(mapDef))
		{
			//Vignettes have zero milestones.
			milestoneCount = -1;
		}

		milestones.Append(milestoneCount);
	}

	levelselectGuiList = uiManager->AllocListGUI();
	levelselectGuiList->Clear();
	levelselectGuiList->Config(levelselectMenu, "levellist");
	levelselectGuiList->SetSelection(0);

	for (int i = 0; i < mapnames.Num(); i++)
	{
		//Place items into the levelselect gui list.

		//We create a string, separated by \t tab separators. The tab separater determines what data we display in what column.
		//The 2 columns are: Milestone coins, Level name.

		idStr output;

		if (milestones[i] >= 0)
		{
			idStr milestoneMaterial;
			if (milestones[i] >= 3)
				milestoneMaterial = "mtr_levelpip3";
			else if (milestones[i] == 2)
				milestoneMaterial = "mtr_levelpip2";
			else if (milestones[i] == 1)
				milestoneMaterial = "mtr_levelpip1";
			else
				milestoneMaterial = "mtr_levelpip0";

			output = idStr::Format("%s\t%s", milestoneMaterial.c_str(), mapnames[i].c_str());
		}
		else
		{
			//No milestone icons for this, as it's a vignette level.
			output = idStr::Format("\t%s", mapnames[i].c_str());
		}

		levelselectGuiList->Push(output.c_str());
	}



	//Now generate the total percentage amount.

	//Calculate total amount of levels and milestones.
	int totalMilestones = 0;
	int totalLevels = 0;
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (!mapDef)
			continue;

		int levelindex = mapDef->dict.GetInt("levelindex", "-1");

		if (levelindex <= -1)
			continue; //no map index. ignore it.

		totalLevels++;

		if (LevelHasAnyMilestones(mapDef))
		{
			totalMilestones += MAXMILESTONES;
		}
	}

	int totalLevelsCompleted = milestones.Num();

	int milestonesCompleted = 0;
	for (int i = 0; i < milestones.Num(); i++)
	{
		if (milestones[i] >= 1)
		{
			milestonesCompleted += milestones[i];
		}
	}

	//Ok, we have all the values. Now generate a total percentage number.
	int finalPercentage;

	if ((totalLevelsCompleted + milestonesCompleted) >= (totalLevels + totalMilestones))
	{
		finalPercentage = 100; //if everything is done, then guarantee it says "100"
	}
	else
	{
		finalPercentage = (int)(((totalLevelsCompleted + milestonesCompleted) / (float)(totalLevels + totalMilestones)) * 100.0f);
		finalPercentage = idMath::ClampInt(0, 99, finalPercentage); //ensure it's clamped it to valid values (so we don't get a "100" false positive)		
	}

	levelselectMenu->SetStateString("percentdone", idStr::Format("%d%%", finalPercentage).c_str());	
}

//When player RUNS a map via the levelselect menu.
void idPlayer::OnStartLevelselectIndex(int index)
{
	if (index < 0 || !levelselectGuiList || index >= levelselectGuiList->Num())
		return;

	int num = declManager->GetNumDecls(DECL_MAPDEF);
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (!mapDef)
			continue;

		int levelindex = mapDef->dict.GetInt("levelindex", "-1");

		if (levelindex <= -1)
			continue; //no map index. ignore it.

		if (levelindex == index + 1)
		{
			//Found it.
					
			idStr mapname = mapDef->GetName();
			if (mapname.Length() > 0)
			{
				idStr command = idStr::Format("map %s", mapname.c_str());
				gameLocal.sessionCommand = command.c_str();
			}

			return;
		}
	}
}

//When player CLICKS ON MAP in the levelselect list.
void idPlayer::OnSelectLevelselectIndex(int index)
{
	if (index < 0 || !levelselectGuiList || index >= levelselectGuiList->Num())
		return;

	int num = declManager->GetNumDecls(DECL_MAPDEF);
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (!mapDef)
			continue;

		int levelindex = mapDef->dict.GetInt("levelindex", "-1");

		if (levelindex <= -1)
			continue; //no map index. ignore it.

		if (levelindex == index + 1)
		{
			//Found correct level.
						
			//Set the ship name and description.
			idStr mapname = common->GetLanguageDict()->GetString(mapDef->dict.GetString("name"));
			idStr mapdesc = common->GetLanguageDict()->GetString(mapDef->dict.GetString("description"));			
			levelselectMenu->SetStateString("levelname", mapname.c_str());
			levelselectMenu->SetStateString("leveldesc", mapdesc.c_str());

			//Set the levelimage. (the top down image of ship)
			idStr imagename = mapDef->dict.GetString("levelimage");
			levelselectMenu->SetStateString("levelimage", imagename.c_str());
			
			if (LevelHasAnyMilestones(mapDef))
			{
				for (int k = 0; k < MAXMILESTONES; k++)
				{
					//Set up the milestone description text.
					idStr milestoneDesc = mapDef->dict.GetString(idStr::Format("milestone%d", k).c_str());
					levelselectMenu->SetStateString(idStr::Format("milestone%d_desc", k).c_str(), common->GetLanguageDict()->GetString(milestoneDesc.c_str()));

					//Set up the coin stuff.
					levelselectMenu->SetStateBool(idStr::Format("milestonecoin%d_visible", k).c_str(), 0); //turn off all the milestone coins.
					idStr milestoneName = gameLocal.GetMilestonenameViaLevelIndex(levelindex, k);
					if (milestoneName.Length() > 0)
					{
						if (gameLocal.persistentLevelInfo.GetBool(milestoneName))
						{
							levelselectMenu->SetStateBool(idStr::Format("milestonecoin%d_visible", k).c_str(), 1); //player has achieved this milestone. Mark coin as visible.
						}
					}
				}

				levelselectMenu->SetStateBool("showmilestones", true);
			}
			else
			{
				levelselectMenu->SetStateBool("showmilestones", false);
			}

			return;
		}
	}

	//failed to find the map that was clicked....
	gameLocal.Warning("OnSelectLevelselectIndex: unable to find map with index '%d'", index);	
}

//Called when the player selects an action from context menu.
void idPlayer::ContextmenuConfirm(bool isCommand)
{
	nextContextMenuAvailableTime = gameLocal.time + CONTEXTMENU_DELAYTIME;

	if (isCommand)
	{
		//Flash the selected command.
		nextContextMenuCloseTime = gameLocal.time + CONTEXTMENU_FLASHTIME;
		contextMenuState = CONTEXTMENU_DEACTIVATING;
		contextMenuActive = true;
	}
	else
	{
		//Cancel out.
		nextContextMenuCloseTime = gameLocal.time;
		CloseContextMenu();
	}

	gameLocal.menuPause = false;

	
}

/*
==============
idPlayer::Collide
==============
*/
bool idPlayer::Collide( const trace_t &collision, const idVec3 &velocity ) {
	idEntity *other;

	if ( gameLocal.isClient ) {
		return false;
	}

	other = gameLocal.entities[ collision.c.entityNum ];
	if ( other ) {
		other->Signal( SIG_TOUCH );
		if ( !spectating )
		{
			if ( other->RespondsTo( EV_Touch ) )
			{
				other->ProcessEvent( &EV_Touch, this, &collision );
			}
		}
		else
		{
			if ( other->RespondsTo( EV_SpectatorTouch ) )
			{
				other->ProcessEvent( &EV_SpectatorTouch, this, &collision );
			}
		}
	}
	return false;
}


/*
================
idPlayer::UpdateLocation

Searches nearby locations
================
*/
void idPlayer::UpdateLocation( void ) {
	if ( hud )
    {
		idLocationEntity *locationEntity = gameLocal.LocationForPoint( GetEyePosition() );
		if ( locationEntity )
		{
			hud->SetStateString( "location", locationEntity->GetLocation() );
			reverbLocation = locationEntity->spawnArgs.GetString("reverb", "default");
		}
		else
		{
			hud->SetStateString( "location", common->GetLanguageDict()->GetString( "#str_loc_unknown_00104" ) );
			reverbLocation = "default"; //BC
		}

        if (locationEntity == NULL)
        {
            lastLocationEntityNum = -1;
        }
        else if (lastLocationEntityNum != locationEntity->entityNumber)
        {
			//entered a new location.

            lastLocationEntityNum = locationEntity->entityNumber;

            hud->SetStateString("locationname", locationEntity->GetLocation());
            //hud->HandleNamedEvent("locationEvent");

			gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_player_enter"), locationEntity->GetLocation()), GetPhysics()->GetOrigin(), false);
			
			if (ingresspointsDrawActive)
			{
				if (idStr::Cmp(locationEntity->GetLocation(), common->GetLanguageDict()->GetString("#str_00000")))
				{
					//if entering a new space, turn off the ingress UI.
					SetDrawIngressPoints(false);
				}
			}
        }
	}
}

/*
================
idPlayer::ClearFocus

Clears the focus cursor
================
*/
void idPlayer::ClearFocus( void ) {
	focusCharacter	= NULL;
	focusGUIent		= NULL;
	focusUI			= NULL;
	focusVehicle	= NULL;
	talkCursor		= 0;
}

/*
================
idPlayer::UpdateFocus

Searches nearby entities for interactive guis, possibly making one of them
the focus and sending it a mouse move event
================
*/
void idPlayer::UpdateFocus( void ) {
	idClipModel *clipModelList[ MAX_GENTITIES ];
	idClipModel *clip;
	int			listedClipModels;
	idEntity	*oldFocus;
	idEntity	*ent;
	idUserInterface *oldUI;
	idAI		*oldChar;
	int			oldTalkCursor;
	int			i, j;
	idVec3		start, end;
	bool		allowFocus;
	const char *command;
	trace_t		trace;
	guiPoint_t	pt;
	const idKeyValue *kv;
	sysEvent_t	ev;
	idUserInterface *ui;

	if ( gameLocal.inCinematic ) {
		return;
	}

	if (emailFullscreenState != EFS_OFF)
		return;

	// only update the focus character when attack button isn't pressed so players
	// can still chainsaw NPC's
	if ( gameLocal.isMultiplayer || ( !focusCharacter && ( usercmd.buttons & BUTTON_ATTACK ) ) ) {
		allowFocus = false;
	} else {
		allowFocus = true;
	}

	oldFocus		= focusGUIent;
	oldUI			= focusUI;
	oldChar			= focusCharacter;
	oldTalkCursor	= talkCursor;

	if ( focusTime <= gameLocal.time ) {
		ClearFocus();
	}

	// don't let spectators interact with GUIs
	if ( spectating ) {
		return;
	}

	start = GetEyePosition();
	end = start + viewAngles.ToForward() * GUI_ACTIVATIONRANGE;

	// player identification -> names to the hud
	if ( gameLocal.isMultiplayer && entityNumber == gameLocal.localClientNum ) {
		idVec3 end = start + viewAngles.ToForward() * 768.0f;
		gameLocal.clip.TracePoint( trace, start, end, MASK_SHOT_BOUNDINGBOX, this );
		int iclient = -1;
		if ( ( trace.fraction < 1.0f ) && ( trace.c.entityNum < MAX_CLIENTS ) ) {
			iclient = trace.c.entityNum;
		}
		if ( MPAim != iclient ) {
			lastMPAim = MPAim;
			MPAim = iclient;
			lastMPAimTime = gameLocal.realClientTime;
		}
	}

	//Update the enemy healthbar visibility.
	if (entityNumber == gameLocal.localClientNum)
	{
		idVec3 targetPos;
		idEntity* autoaimEnt = FindAimAssistTarget(targetPos);
		if (autoaimEnt != NULL)
		{
			if (IsEntityEnemyTarget(autoaimEnt))
			{
				//If player looks at enemy, reset the enemy's healthbar display time.
				if (autoaimEnt->healthbarDisplaytime < gameLocal.time)
				{
					//click sound.
					if (autoaimEnt->IsType(idActor::Type))
					{
						StartSound("snd_showenemyhealth", SND_CHANNEL_ANY, 0, false, NULL);
					}
				}

				autoaimEnt->ShowHealthbar();
			}
		}

		/*
		trace_t healthTrace;
		idVec3 eyeStart;
		idVec3 end;

		eyeStart = peekObject.IsValid() ? firstPersonViewOrigin : start;

		end = eyeStart + viewAngles.ToForward() * 1024.0f;
		gameLocal.clip.TracePoint(healthTrace, eyeStart, end, MASK_SHOT_BOUNDINGBOX, this);

		if (healthTrace.fraction < 1.0f)
		{
			//if (IsEntityEnemyTarget(gameLocal.entities[healthTrace.c.entityNum]) && gameLocal.entities[healthTrace.c.entityNum]->IsType(idAnimatedEntity::Type))
			if (IsEntityEnemyTarget(gameLocal.entities[healthTrace.c.entityNum]))
			{
				//If player looks at enemy, reset the enemy's healthbar display time.
				if (static_cast<idAnimatedEntity*>(gameLocal.entities[healthTrace.c.entityNum])->healthbarDisplaytime < gameLocal.time)
				{
					//click sound.
					StartSound("snd_showenemyhealth", SND_CHANNEL_ANY, 0, false, NULL);
				}

				static_cast<idAnimatedEntity *>(gameLocal.entities[healthTrace.c.entityNum])->ShowHealthbar();
			}			
		}*/
	}

	idBounds bounds( start );
	bounds.AddPoint( end );

	listedClipModels = gameLocal.clip.ClipModelsTouchingBounds( bounds, -1, clipModelList, MAX_GENTITIES );

	// no pretense at sorting here, just assume that there will only be one active
	// gui within range along the trace
	for ( i = 0; i < listedClipModels; i++ )
	{
		clip = clipModelList[ i ];
		ent = clip->GetEntity();



		//BC CRASH
		if (ent->IsHidden() || ent->entityNumber <= 0 || ent->entityNumber >= MAX_GENTITIES - 1 || ent->entityDefNumber < -1 || !ent->name || !ent->GetPhysics())
		{
			continue;
		}



		if ( allowFocus ) {
			if ( ent->IsType( idAFAttachment::Type ) ) {
				idEntity *body = static_cast<idAFAttachment *>( ent )->GetBody();
				if ( body && body->IsType( idAI::Type ) && ( static_cast<idAI *>( body )->GetTalkState() >= TALK_OK ) ) {
					gameLocal.clip.TracePoint( trace, start, end, MASK_SHOT_RENDERMODEL, this );
					if ( ( trace.fraction < 1.0f ) && ( trace.c.entityNum == ent->entityNumber ) ) {
						ClearFocus();
						focusCharacter = static_cast<idAI *>( body );
						talkCursor = 1;
						focusTime = gameLocal.time + FOCUS_TIME;
						break;
					}
				}
				continue;
			}

			if ( ent->IsType( idAI::Type ) ) {
				if ( static_cast<idAI *>( ent )->GetTalkState() >= TALK_OK ) {
					gameLocal.clip.TracePoint( trace, start, end, MASK_SHOT_RENDERMODEL, this );
					if ( ( trace.fraction < 1.0f ) && ( trace.c.entityNum == ent->entityNumber ) ) {
						ClearFocus();
						focusCharacter = static_cast<idAI *>( ent );
						talkCursor = 1;
						focusTime = gameLocal.time + FOCUS_TIME;
						break;
					}
				}
				continue;
			}

			if ( ent->IsType( idAFEntity_Vehicle::Type ) ) {
				gameLocal.clip.TracePoint( trace, start, end, MASK_SHOT_RENDERMODEL, this );
				if ( ( trace.fraction < 1.0f ) && ( trace.c.entityNum == ent->entityNumber ) ) {
					ClearFocus();
					focusVehicle = static_cast<idAFEntity_Vehicle *>( ent );
					focusTime = gameLocal.time + FOCUS_TIME;
					break;
				}
				continue;
			}
		}

		if ( !ent->GetRenderEntity() || !ent->GetRenderEntity()->gui[ 0 ] || !ent->GetRenderEntity()->gui[ 0 ]->IsInteractive() ) {
			continue;
		}

		if ( ent->spawnArgs.GetBool( "inv_item" ) ) {
			// don't allow guis on pickup items focus
			continue;
		}

		pt = gameRenderWorld->GuiTrace( ent->GetModelDefHandle(), start, end );
		if ( pt.x != -1 ) {
			// we have a hit
			renderEntity_t *focusGUIrenderEntity = ent->GetRenderEntity();
			if ( !focusGUIrenderEntity ) {
				continue;
			}

			if ( pt.guiId == 1 ) {
				ui = focusGUIrenderEntity->gui[ 0 ];
			} else if ( pt.guiId == 2 ) {
				ui = focusGUIrenderEntity->gui[ 1 ];
			} else {
				ui = focusGUIrenderEntity->gui[ 2 ];
			}

			if ( ui == NULL ) {
				continue;
			}

			ClearFocus();
			focusGUIent = ent;
			focusUI = ui;

			if ( oldFocus != ent ) {
				// new activation
				// going to see if we have anything in inventory a gui might be interested in
				// need to enumerate inventory items
				focusUI->SetStateInt( "inv_count", inventory.items.Num() );
				for ( j = 0; j < inventory.items.Num(); j++ ) {
					idDict *item = inventory.items[ j ];
					const char *iname = item->GetString( "inv_name" );
					const char *iicon = item->GetString( "inv_icon" );
					const char *itext = item->GetString( "inv_text" );

					focusUI->SetStateString( va( "inv_name_%i", j), iname );
					focusUI->SetStateString( va( "inv_icon_%i", j), iicon );
					focusUI->SetStateString( va( "inv_text_%i", j), itext );
					kv = item->MatchPrefix("inv_id", NULL);
					if ( kv ) {
						focusUI->SetStateString( va( "inv_id_%i", j ), kv->GetValue() );
					}
					focusUI->SetStateInt( iname, 1 );
				}


				for( j = 0; j < inventory.pdaSecurity.Num(); j++ ) {
					const char *p = inventory.pdaSecurity[ j ];
					if ( p && *p ) {
						focusUI->SetStateInt( p, 1 );
					}
				}

#ifdef _D3XP		//BSM: Added for powercells
				int powerCellCount = 0;
				for ( j = 0; j < inventory.items.Num(); j++ ) {
					idDict *item = inventory.items[ j ];
					if(item->GetInt("inv_powercell")) {
						powerCellCount++;
					}
				}
				focusUI->SetStateInt( "powercell_count", powerCellCount );
#endif

				int staminapercentage = ( int )( 100.0f * stamina / pm_stamina.GetFloat() );
				focusUI->SetStateString( "player_health", va("%i", health ) );
				focusUI->SetStateString( "player_stamina", va( "%i%%", staminapercentage ) );
				focusUI->SetStateString( "player_armor", va( "%i%%", inventory.armor ) );

				kv = focusGUIent->spawnArgs.MatchPrefix( "gui_parm", NULL );
				while ( kv ) {
					focusUI->SetStateString( kv->GetKey(), kv->GetValue() );
					kv = focusGUIent->spawnArgs.MatchPrefix( "gui_parm", kv );
				}
			}

			// clamp the mouse to the corner
			ev = sys->GenerateMouseMoveEvent( -2000, -2000 );
			command = focusUI->HandleEvent( &ev, gameLocal.time );
			HandleGuiCommands( focusGUIent, command );

			// move to an absolute position
			ev = sys->GenerateMouseMoveEvent( pt.x * SCREEN_WIDTH, pt.y * SCREEN_HEIGHT );
			command = focusUI->HandleEvent( &ev, gameLocal.time );
			HandleGuiCommands( focusGUIent, command );
			focusTime = gameLocal.time + FOCUS_GUI_TIME;
			break;
		}
	}

	if ( focusGUIent && focusUI ) {
		if ( !oldFocus || oldFocus != focusGUIent ) {
			command = focusUI->Activate( true, gameLocal.time );
			HandleGuiCommands( focusGUIent, command );
			StartSound( "snd_guienter", SND_CHANNEL_ANY, 0, false, NULL );
			// HideTip();
			// HideObjective();
		}
	} else if ( oldFocus && oldUI ) {
		command = oldUI->Activate( false, gameLocal.time );
		HandleGuiCommands( oldFocus, command );
		StartSound( "snd_guiexit", SND_CHANNEL_ANY, 0, false, NULL );
	}

	if ( cursor && ( oldTalkCursor != talkCursor ) ) {
		cursor->SetStateInt( "talkcursor", talkCursor );
	}

	if ( oldChar != focusCharacter && hud ) {
		if ( focusCharacter ) {
			hud->SetStateString( "npc", focusCharacter->spawnArgs.GetString( "npc_name", "Joe" ) );
#ifdef _D3XP
			//Use to code to update the npc action string to fix bug 1159
			hud->SetStateString( "npc_action", common->GetLanguageDict()->GetString( "#str_02036" ));
#endif
			hud->HandleNamedEvent( "showNPC" );
			// HideTip();
			// HideObjective();
		} else {
			hud->SetStateString( "npc", "" );
#ifdef _D3XP
			hud->SetStateString( "npc_action", "" );
#endif
			hud->HandleNamedEvent( "hideNPC" );
		}
	}
}

/*
=================
idPlayer::CrashLand

Check for hard landings that generate sound events
=================
*/
void idPlayer::CrashLand( const idVec3 &oldOrigin, const idVec3 &oldVelocity ) {
	idVec3		origin, velocity;
	idVec3		gravityVector, gravityNormal;
	float		delta;
	float		hardDelta, fatalDelta;
	float		dist;
	float		vel, acc;
	float		t;
	float		a, b, c, den;
	waterLevel_t waterLevel;
	bool		noDamage;
	bool		landedOnFlesh = false;
	int			takedownTarget = -1;

	AI_SOFTLANDING = false;
	AI_HARDLANDING = false;

	if (noclip)
		return;

	// if the player is not on the ground
	if ( !physicsObj.HasGroundContacts() ) {
		return;
	}

	gravityNormal = physicsObj.GetGravityNormal();

	// if the player wasn't going down
	if ( ( oldVelocity * -gravityNormal ) >= 0.0f ) {
		return;
	}

	waterLevel = physicsObj.GetWaterLevel();

	// never take falling damage if completely underwater
	if ( waterLevel == WATERLEVEL_HEAD ) {
		return;
	}

	// no falling damage if touching a nodamage surface
	noDamage = false;
	for ( int i = 0; i < physicsObj.GetNumContacts(); i++ ) {
		const contactInfo_t &contact = physicsObj.GetContact( i );
		if ( contact.material->GetSurfaceFlags() & SURF_NODAMAGE ) {
			noDamage = true;
			StartSound( "snd_land_hard", SND_CHANNEL_ANY, 0, false, NULL );
			break;
		}
	}

	origin = GetPhysics()->GetOrigin();
	gravityVector = physicsObj.GetGravity();

	// calculate the exact velocity on landing
	dist = ( origin - oldOrigin ) * -gravityNormal;
	vel = oldVelocity * -gravityNormal;
	acc = -gravityVector.Length();

	a = acc / 2.0f;
	b = vel;
	c = -dist;

	den = b * b - 4.0f * a * c;
	if ( den < 0 ) {
		return;
	}
	t = ( -b - idMath::Sqrt( den ) ) / ( 2.0f * a );

	delta = vel + t * acc;
	delta = delta * delta * 0.0001;

	// reduce falling damage if there is standing water
	if ( waterLevel == WATERLEVEL_WAIST ) {
		delta *= 0.25f;
	}
	if ( waterLevel == WATERLEVEL_FEET ) {
		delta *= 0.5f;
	}

	if ( delta < 1.0f ) {
		return;
	}

	fatalDelta	= 75.0f;
	hardDelta	= 45.0f;	

	
	if (physicsObj.GetNumContacts() > 0)
	{
		for (int i = 0; i < physicsObj.GetNumContacts(); i++)
		{
			const contactInfo_t &contact = physicsObj.GetContact(i);
			if (gameLocal.entities[contact.entityNum]->IsType(idActor::Type) && gameLocal.entities[contact.entityNum]->health > 0)
			{
				//Landed on monster
				landedOnFlesh = true;
				takedownTarget = contact.entityNum;
				break;
			}
		}
	}

	if ( delta > fatalDelta )
	{
		//BC fall from long distance.
		AI_HARDLANDING = true;
		landChange = -32;
		landTime = gameLocal.time;

		if (AI_FALLEN == false)
		{
			StartSound("snd_longfall", SND_CHANNEL_ANY, 0, false, NULL);
		}

		if (!landedOnFlesh && !isFallDamageImmune)
		{
			if (AI_FALLEN == false)
			{
				idEntityFx::StartFx("fx/smoke_longfall", &GetPhysics()->GetOrigin(), &mat3_identity, NULL, false);
			}

			SetFallState(true, true);			

			if (!noDamage)
			{
				pain_debounce_time = gameLocal.time + pain_delay + 1;  // ignore pain since we'll play our landing anim
				Damage(NULL, NULL, idVec3(0, 0, -1), "damage_megafall", 1.0f, 0);
			}
		}

		PlayerLanded();
	}
	else if ( delta > hardDelta )
	{
		AI_HARDLANDING = true;
		landChange	= -24;
		landTime	= gameLocal.time;

		//if ( !noDamage && !landedOnFlesh)
		//{
		//	pain_debounce_time = gameLocal.time + pain_delay + 1;  // ignore pain since we'll play our landing anim
		//	Damage( NULL, NULL, idVec3( 0, 0, -1 ), "damage_hardfall", 1.0f, 0 );
		//}
		//
		//StartSound("snd_longfall", SND_CHANNEL_ANY, 0, false, NULL);
		StartSound("snd_softfall", SND_CHANNEL_ANY, 0, false, NULL);
		PlayerLanded();
	}
	else if ( delta > 30 )
	{
		AI_HARDLANDING = true;
		landChange	= -16;
		landTime	= gameLocal.time;
		if ( !noDamage ) {
			pain_debounce_time = gameLocal.time + pain_delay + 1;  // ignore pain since we'll play our landing anim
			Damage( NULL, NULL, idVec3( 0, 0, -1 ), "damage_softfall", 1.0f, 0 );
		}
		StartSound("snd_softfall", SND_CHANNEL_ANY, 0, false, NULL);
		PlayerLanded();
	}
	else if ( delta > 7 )
	{
		AI_SOFTLANDING = true;
		landChange	= -8;
		landTime	= gameLocal.time;
		StartSound("snd_softfall", SND_CHANNEL_ANY, 0, false, NULL);
		PlayerLanded();
	}
	else if ( delta > 3 )
	{
		// just walk on
		StartSound("snd_softfall", SND_CHANNEL_ANY, 0, false, NULL);
	}

	//Handle Death From Above
	//#define DEATHFROMABOVE_FALLDELTA 20
	//if (delta > DEATHFROMABOVE_FALLDELTA)
	//{
	//	if (landedOnFlesh && takedownTarget >= 0)
	//	{
	//		gameLocal.entities[takedownTarget]->Damage(this, this, idVec3(0, 0, 1), "damage_jumpattack", 1.0f, 0);
	//		StartSound("snd_melee", SND_CHANNEL_ANY, 0, false, NULL);
	//	}
	//	else
	//	{
	//		#define DEATHFROMABOVE_PROXIMITYCHECK 64
	//
	//		//Ok, didn't land on a monster's head. However, do leniency check to see if we landed NEXT to a monster. If so, then still do the takedown.
	//		for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	//		{
	//			float dist;
	//
	//			if (!entity || !entity->IsActive() || entity->IsHidden() || entity->health <= 0)
	//				continue;
	//
	//			if (!entity->IsType(idAI::Type))
	//				continue;
	//
	//			if (static_cast<idActor*>(entity)->team != 1)
	//				continue; //if you're not a bad guy, or if you already have LOS to enemy, then we're SKIPPING you.
	//
	//			dist = (GetPhysics()->GetOrigin() - entity->GetPhysics()->GetOrigin()).LengthFast();
	//
	//			if (dist <= DEATHFROMABOVE_PROXIMITYCHECK)
	//			{
	//				//Turn to look at them.
	//				float viewDelta = (entity->GetPhysics()->GetOrigin() - GetPhysics()->GetOrigin()).ToYaw();
	//				gameLocal.GetLocalPlayer()->SetViewYawLerp(viewDelta, 100);
	//				gameLocal.GetLocalPlayer()->SetViewPitchLerp(0, 100);
	//
	//				entity->Damage(this, this, idVec3(0, 0, 1), "damage_jumpattack", 1.0f, 0);
	//				StartSound("snd_melee", SND_CHANNEL_ANY, 0, false, NULL);
	//			}
	//		}
	//	}
	//}

	

	//Glass wound, and landed after a fall/jump. Do damage.
	if (cond_glasswound > 0 && delta > 7)
	{
		float glassDamageMultiplier = 2.0f;

		if (delta > fatalDelta)
			glassDamageMultiplier = 8.0f;
		else if (delta > hardDelta)
			glassDamageMultiplier =  4.0f;


		//Clamp the health to be below the max wound count. This is so the player doesn't regen health that is currently being blocked-out by the glasswound.
		int woundcount = GetWoundCount();
		if (health > maxHealth - (woundcount * HEALTH_PER_HEALTHBARBLOCK))
		{
			health = maxHealth - (woundcount * HEALTH_PER_HEALTHBARBLOCK);
		}
		
		Damage(NULL, NULL, vec3_origin, "damage_glasswound", (1 + gameLocal.random.RandomInt(cond_glasswound)) * glassDamageMultiplier, 0);
		hud->HandleNamedEvent("cond_glassdamage");

		
	}
}

/*
===============
idPlayer::BobCycle
===============
*/
void idPlayer::BobCycle( const idVec3 &pushVelocity ) {
	float		bobmove;
	int			old;
	idVec3		vel, gravityDir, velocity;
	idMat3		viewaxis;
	float		bob;
	float		delta;
	float		speed;

	

	//
	// calculate speed and cycle to be used for
	// all cyclic walking effects
	//
	velocity = physicsObj.GetLinearVelocity() - pushVelocity;

	gravityDir = physicsObj.GetGravityNormal();
	vel = velocity - ( velocity * gravityDir ) * gravityDir;
	xyspeed = vel.LengthFast();

	// do not evaluate the bob for other clients
	// when doing a spectate follow, don't do any weapon bobbing
	if ( gameLocal.isClient && entityNumber != gameLocal.localClientNum || !g_headbob.GetBool() || noclip || zoommodeActive)
	{
		viewBobAngles.Zero();
		viewBob.Zero();
		return;
	}

	if ( !physicsObj.HasGroundContacts() || influenceActive == INFLUENCE_LEVEL2 || ( gameLocal.isMultiplayer && spectating ) ) {
		// airborne
		bobCycle = 0;
		bobFoot = 0;
		bobfracsin = 0;
	} else if ( ( !usercmd.forwardmove && !usercmd.rightmove ) || ( xyspeed <= MIN_BOB_SPEED ) ) {
		// start at beginning of cycle again
		bobCycle = 0;
		bobFoot = 0;
		bobfracsin = 0;
	}
	else
	{
		if ( physicsObj.IsCrouching() )
		{
			bobmove = pm_crouchbob.GetFloat();
			// ducked characters never play footsteps
		}
		else
		{
			// vary the bobbing based on the speed of the player
			bobmove = pm_walkbob.GetFloat() * ( 1.0f - bobFrac ) + pm_runbob.GetFloat() * bobFrac;
		}

		// check for footstep / splash sounds
		old = bobCycle;
		bobCycle = (int)( old + bobmove * gameLocal.msec ) & 255;
		bobFoot = ( bobCycle & 128 ) >> 7;
		bobfracsin = idMath::Fabs( sin( ( bobCycle & 127 ) / 127.0 * idMath::PI ) );
	}

	// calculate angles for view bobbing
	viewBobAngles.Zero();

	viewaxis = viewAngles.ToMat3() * physicsObj.GetGravityAxis();

	// add angles based on velocity
	delta = velocity * viewaxis[0];
	viewBobAngles.pitch += delta * pm_runpitch.GetFloat();

	delta = velocity * viewaxis[1];
	viewBobAngles.roll -= delta * pm_runroll.GetFloat();

	//bc
	if (viewBobAngles.roll > 1)
		viewBobAngles.roll = 1.0f;
	else if (viewBobAngles.roll < -1)
		viewBobAngles.roll = -1;


	// add angles based on bob
	// make sure the bob is visible even at low speeds
	speed = xyspeed > 200 ? xyspeed : 200;

	delta = bobfracsin * pm_bobpitch.GetFloat() * speed;
	if ( physicsObj.IsCrouching() ) {
		delta *= 3;		// crouching
	}
	viewBobAngles.pitch += delta;
	delta = bobfracsin * pm_bobroll.GetFloat() * speed;
	if ( physicsObj.IsCrouching() ) {
		delta *= 3;		// crouching accentuates roll
	}
	if ( bobFoot & 1 ) {
		delta = -delta;
	}
	viewBobAngles.roll += delta;

	bob = bobfracsin * xyspeed * pm_bobup.GetFloat();
	if (bob > 6) {
		bob = 6;
	}

	idVec3 gravity = physicsObj.GetGravityNormal();
	float landTimeDelta = gameLocal.time - landTime;
	float deltaStepUpTime = gameLocal.time - stepUpTime;

	// readjust stepUpDelta on every step
	if ( physicsObj.HasSteppedUp() ) {
		// TODO sometimes physobj returns a negative stepup value, should that be corrected?
		float stepUpHeight = physicsObj.GetStepUp();

		// check for stepping up before a previous step is completed
		if ( deltaStepUpTime < STEPUP_TIME ) {
			stepUpDelta = (stepUpDelta * ( STEPUP_TIME - deltaStepUpTime ) / STEPUP_TIME) + stepUpHeight;
		} else {
			stepUpDelta = stepUpHeight;
		}
		if ( stepUpDelta > 2.0f * pm_stepsize.GetFloat() ) {
			stepUpDelta = 2.0f * pm_stepsize.GetFloat();
		}
		stepUpTime = gameLocal.time;
		deltaStepUpTime = 0.0f;

		// use largest correction until stepups time out to avoid jitter
		if (stepUpHeight > stepUpCorrection) {
			stepUpCorrection = idMath::ClampFloat(0.0f, pm_stepsize.GetFloat(), stepUpHeight);
		}
	}
	else if (deltaStepUpTime > STEPUP_TIME + STEPUPRECOVERY_TIME)
	{
		stepUpCorrection = 0.0f;
	}

	viewBob.Zero();

	//
	// calculate position for view bobbing
	//

	if (teleportCrouchTime + TELEPORTCROUCH_EASE_TIME > gameLocal.time)
	{ // fix body clipping on teleport
		float easeInterp = idMath::ClampFloat( 0.0f, 1.0f, (float)(gameLocal.time-teleportCrouchTime) / TELEPORTCROUCH_EASE_TIME );
#if 1
		idVec3 viewforward = idAngles(0, viewAngles.yaw, 0).ToForward();
		viewBob += viewforward* pm_bobstepup.GetFloat() * (1.0f-easeInterp);
#endif
		bob *= easeInterp;
	}
	else if (deltaStepUpTime < STEPUP_TIME + STEPUPRECOVERY_TIME)
	{ // if the player stepped up recently
		// stepup smoothing
		if (deltaStepUpTime < STEPUP_TIME)
		{
			viewBob += (gravity) * stepUpDelta * ((STEPUP_TIME - deltaStepUpTime) / STEPUP_TIME);
		}
		float recoveryInterp = idMath::ClampFloat( 0.0f, 1.0f, (deltaStepUpTime - STEPUP_TIME) / STEPUPRECOVERY_TIME );
		if (stepUpCorrection > 0.0f)
		{ // shift head forward and up to avoid body clipping on large step ups
			// then softly revert after stepup recovers
			idVec3 viewforward = idAngles(0, viewAngles.yaw, 0).ToForward();
			// reach max pm_bobstepup distance at half step size
			float bobForwardScale = 2.0f*(stepUpCorrection / (pm_stepsize.GetFloat() + 0.001f));
			bobForwardScale = idMath::ClampFloat(0.0f,1.0f,bobForwardScale);
			viewBob += (-gravity + viewforward) * pm_bobstepup.GetFloat() * bobForwardScale * (1.0f- recoveryInterp);
		}
		bob *= (0.5f + recoveryInterp * 0.5f); // slight bob to prevent clipping, increases as recovery ends
	}
	else if (landTimeDelta < LAND_DEFLECT_TIME + LAND_RETURN_TIME)
	{ // add fall height
		float f;
		if (landTimeDelta < LAND_DEFLECT_TIME)
		{ // initial deflect
			f = landTimeDelta / LAND_DEFLECT_TIME;
		}
		else
		{ // recovery
			f = 1.0 - ((landTimeDelta - LAND_DEFLECT_TIME) / LAND_RETURN_TIME);
		}
		float bounceReduce = IsCrouching() ? 0.25f : 1.0f; // reduce crouch bounce to prevent head clipping
		viewBob -= gravity * (landChange * f) * bounceReduce;
		bob *= (landTimeDelta  / (LAND_DEFLECT_TIME + LAND_RETURN_TIME)); // smooth back into bob
	}

	// add bob height after any movement smoothing
	viewBob[2] += bob;
}

/*
================
idPlayer::UpdateDeltaViewAngles
================
*/
void idPlayer::UpdateDeltaViewAngles( const idAngles &angles ) {
	// set the delta angle
	idAngles delta;
	for( int i = 0; i < 3; i++ )
	{
		delta[i] = angles[i] - SHORT2ANGLE(usercmd.angles[i]);
	}
	SetDeltaViewAngles( delta );
}

/*
================
idPlayer::SetViewAngles
================
*/
void idPlayer::SetViewAngles( const idAngles &angles ) {
	UpdateDeltaViewAngles( angles );
	viewAngles = angles;
}

/*
================
idPlayer::UpdateViewAngles
================
*/
void idPlayer::UpdateViewAngles( void ) {
	int i;
	idAngles delta;

	//TODO: in lean state, hide gun.

	if (zoominspect_LabelmodeActive)
	{
		if (gameLocal.hudTime >= zoominspect_lerptimer)
		{
			//fully lerped angle.
			//viewAngles = zoominspect_LabelmodeAngle;

			if (!zoominspect_lerpDone)
			{
				zoominspect_lerpDone = true;

				//Inspecting a label in the world. Pause the game.
				if (zoominspectEntityPtr.IsValid())
				{
					//By default we pause the world. However, in certain cases we want to not pause the world.
					//An example of this is in Miaocorp vignette when inspecting the conference room plaques.
					if (zoominspectEntityPtr.GetEntity()->spawnArgs.GetBool("do_pause", "1"))
					{
						if (!gameSoundWorld->IsPaused())
						{
							gameSoundWorld->Pause();
						}
						gameLocal.menuPause = true; //Pause the game world.
					}
				}

				SetViewYawLock(true, viewAngles.yaw, ITEMINSPECT_YAW_MAXDISTANCE);
				SetViewPitchLock(true, viewAngles.pitch, ITEMINSPECT_PITCH_MAXDISTANCE);				
			}
		}
		else
		{
			//currently lerping angle to the zoominspect angle.
			float lerp = 1.0f - ((zoominspect_lerptimer - gameLocal.hudTime) / (float)ZOOMINSPECT_LERPTIME);
			lerp = idMath::ClampFloat(0, 1, lerp);
			lerp = idMath::CubicEaseInOut(lerp);

			viewAngles.yaw = idMath::LerpShort(zoominspect_lerpStartAngle.yaw, zoominspect_LabelmodeAngle.yaw, lerp); //quickest lerp between two yaw angles.
			viewAngles.pitch = idMath::LerpShort(zoominspect_lerpStartAngle.pitch, zoominspect_LabelmodeAngle.pitch, lerp); //quickest lerp between two yaw angles.
			viewAngles.roll = idMath::LerpShort(zoominspect_lerpStartAngle.roll, zoominspect_LabelmodeAngle.roll, lerp); //quickest lerp between two yaw angles.
			UpdateDeltaViewAngles(viewAngles); //update it, or else the angles get wonky when we exit this lerp
			return;
		}

		if (zoominspect_lerpDone)
		{
			//if there's camera roll, then don't do the limited camera movement; just lock the camera.
			//The camera movement is too weird when there's roll involved.

			if (zoominspect_LabelmodeAngle.roll != 0) 
			{
				return;
			}			
		}
	}

	if (iteminspectActive)
	{
		if (inspectLerpState == INSP_LERPON)
		{
			if (gameLocal.time > inspectLerpTimer)
			{
				inspectLerpState = INSP_INSPECTING;

				//Pause the game.
				if (!gameSoundWorld->IsPaused())
				{
					gameSoundWorld->Pause();
				}
				gameLocal.menuPause = true; //Pause the game world.
			}
		}
	}





	//BC update view angle changes. If you want to lock the view angle, put it in the conditions in this next line:
	if ( !noclip && ((leanState == LEANSTATE_TRANSITIONON || leanState == LEANSTATE_ACTIVE) || eventlogMenuActive || levelselectMenuActive || emailFullscreenState == EFS_ACTIVE || 
		(contextMenuActive && contextMenuState == CONTEXTMENU_ACTIVE)
		|| gameLocal.inCinematic || privateCameraView || gameLocal.GetCamera() 
		|| influenceActive == INFLUENCE_LEVEL2 || objectiveSystemOpen || static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->GetHightlighterActive()) )
	{
		// no view changes at all, but we still want to update the deltas or else when
		// we get out of this mode, our view will snap to a kind of random angle
		UpdateDeltaViewAngles( viewAngles );
		return;
	}

	if (g_editEntityMode.GetInteger() > 0 && gameEdit->editmenuActive)
	{
		UpdateDeltaViewAngles(viewAngles);
		return;
	}

	

	// if dead
	//BC retain camera control when dead.
	/*if ( health <= 0 )
	{
		if ( pm_thirdPersonDeath.GetBool() )
		{
			viewAngles.roll = 0.0f;
			viewAngles.pitch = 30.0f;
		}
		else
		{
			viewAngles.roll = 40.0f;
			viewAngles.pitch = -15.0f;
		}
		return;
	}*/

	// circularly clamp the angles with deltas	
		
	
		
	if (isFrozen != FROZ_LEGSANDCAMERA)
	{			
		if (zoommodeActive ||
			(peekObject.IsValid() && peekObject.GetEntity()->IsType(idVentpeek::Type) && static_cast<idVentpeek*>(peekObject.GetEntity())->peekEnt.IsValid()))
		{
			// SW: Scale mouse sensitivity down if the player is zoomed in (only via telescope for now, but could also be used for the 'zoom' button).
			// This mitigates the jittery view movement at very low FOVs.
			// Rather than hooking directly into UsercmdGen and its sensitivity-handling code (which has no knowledge of the player state),
			// we calculate our own delta using our knowledge of the desired viewangles and the previous viewangles.
			
			// Scale the rotation down using a float defined by the peek target
			// Or if in zoom, based on Zoom FOV
			float scale = peekObject.IsValid() ? static_cast< idVentpeek* >( peekObject.GetEntity() )->GetRotateScale() : 1.0f;
			if ( zoommodeActive )
			{
				float fov = CalcFov(true);
				float pct = ( DefaultFov() - fov ) / ( DefaultFov() - ZOOM_MIN );
				scale = idMath::Lerp( 1.0f, ZOOM_MOUSE_SCALE, pct );
			}

			idAngles difference;
			for (i = 0; i < 3; i++)
			{
				cmdAngles[i] = SHORT2ANGLE(usercmd.angles[i]);
				difference[i] = idMath::AngleNormalize180(cmdAngles[i] + deltaViewAngles[i] - viewAngles[i]);
				difference[i] *= scale;
				viewAngles[i] = idMath::AngleNormalize180(viewAngles[i] + difference[i]);
			}
		}
		else
		{
			// No scaling, apply angles normally
			for (i = 0; i < 3; i++)
			{
				cmdAngles[i] = SHORT2ANGLE(usercmd.angles[i]);

				/*if (influenceActive == INFLUENCE_LEVEL3 )
				{
					viewAngles[i] += idMath::ClampFloat( -1.0f, 1.0f, idMath::AngleDelta( idMath::AngleNormalize180( SHORT2ANGLE( usercmd.angles[i]) + deltaViewAngles[i] ) , viewAngles[i] ) );
				}*/

				viewAngles[i] = idMath::AngleNormalize180(cmdAngles[i] + deltaViewAngles[i]); // Apply viewangles normally
			}
		}

			
	}

	if (inDownedState && IsInMech())
	{
		viewAngles.roll = 0.0f;
	}
	else if (inDownedState && !pm_thirdPerson.GetBool())
	{
		//Downed state, rolled view.
		viewAngles.roll = DOWNED_VIEWANGLE_ROLL;
	}

	if (health <= 0)
	{
		viewAngles.roll = 0.0f;
		return;
	}

	

	if ( !centerView.IsDone( gameLocal.time ) )
	{
		viewAngles.pitch = centerView.GetCurrentValue(gameLocal.time);
	}



	if (viewpitchState == LERPSTATE_TRANSITIONON)
	{
		float lerp = (gameLocal.time - viewpitchStarttime) / (float)viewpitchTransitionTime;

		if (lerp > 1.0f)
		{
			lerp = 1.0f;
			viewpitchState = LERPSTATE_OFF;
		}

		viewAngles.pitch = idMath::Lerp(viewpitchStartAngle, viewpitchTargetAngle, lerp);
	}
	else if (physicsObj.GetFallState() == FALLEN_HEADONGROUND)
	{
		viewAngles.pitch = FALLENSTATE_INITIALPITCH;
	}
	

	if (viewyawState == LERPSTATE_TRANSITIONON)
	{
		float lerp = (gameLocal.time - viewyawStarttime) / (float)viewyawMovetime;

		if (lerp > 1.0f)
		{
			lerp = 1.0f;
			viewyawState = LERPSTATE_OFF;
		}

		viewAngles.yaw = idMath::LerpShort(viewyawStartAngle, viewyawTargetAngle, lerp); //quickest lerp between two yaw angles.
	}
	
	if (viewrollState == LERPSTATE_TRANSITIONON)
	{
		float lerp = (gameLocal.time - viewrollStarttime) / (float)viewrollMovetime;

		if (lerp > 1.0f)
		{
			lerp = 1.0f;
			viewrollState = LERPSTATE_OFF;
		}

		viewAngles.roll = idMath::LerpShort(viewrollStartAngle, viewrollTargetAngle, lerp);
	}



	// clamp the pitch
	if ( noclip )
	{
		if ( viewAngles.pitch > 89.0f ) {
			// don't let the player look down more than 89 degrees while noclipping
			viewAngles.pitch = 89.0f;
		} else if ( viewAngles.pitch < -89.0f ) {
			// don't let the player look up more than 89 degrees while noclipping
			viewAngles.pitch = -89.0f;
		}

	}	
	else if ((physicsObj.GetAcroType() == ACROTYPE_SPLITS || physicsObj.GetAcroType() == ACROTYPE_CEILINGHIDE || physicsObj.GetAcroType() == ACROTYPE_CARGOHIDE) && physicsObj.GetClamberState() == CLAMBERSTATE_ACRO)
	{
		//lock the viewangles when doing the splits.

		float baseAngle;
		int arcSize;

		this->physicsObj.GetAcroAngleRestrictions(baseAngle, arcSize);

		viewAngles.yaw = ClampViewArc(baseAngle, arcSize);


		if (physicsObj.GetAcroType() == ACROTYPE_CEILINGHIDE)
		{
			viewAngles.pitch = Min(viewAngles.pitch, 89.0f); //downward pitch.		
			viewAngles.pitch = Max(viewAngles.pitch, -20.0f); //upward pitch.*/
		}
		else if (physicsObj.GetAcroType() == ACROTYPE_CARGOHIDE)
		{
			if (physicsObj.hideType == CARGOHIDETYPE_ROW)
			{
				//Row cargo hide.
				viewAngles.pitch = Min(viewAngles.pitch, 89.0f); //downward pitch.		
				viewAngles.pitch = Max(viewAngles.pitch, -10.0f); //upward pitch.
			}
			else if (physicsObj.hideType == CARGOHIDETYPE_STACK)
			{
				//Stacked cargo hide.
				viewAngles.pitch = Min(viewAngles.pitch, 30.0f); //downward pitch.		
				viewAngles.pitch = Max(viewAngles.pitch, -30.0f); //upward pitch.
			}
			else if (physicsObj.hideType == CARGOHIDETYPE_LAUNDRYMACHINE)
			{
				//Stacked cargo hide.
				viewAngles.pitch = Min(viewAngles.pitch, 60.0f); //downward pitch.		
				viewAngles.pitch = Max(viewAngles.pitch, -30.0f); //upward pitch.
			}
		}
		else
		{
			//allow full range of pitch control.
			viewAngles.pitch = Min(viewAngles.pitch, pm_maxviewpitch.GetFloat()); //downward pitch.		
			viewAngles.pitch = Max(viewAngles.pitch, pm_minviewpitch.GetFloat()); //upward pitch.
		}
	}
	else if (physicsObj.GetAcroType() == ACROTYPE_SPLITS_DOWN && physicsObj.GetClamberState() == CLAMBERSTATE_ACRO)
	{
		//player is flipping upside down splits
		//common->Printf("%f\n", viewAngles.pitch);

		if (viewpitchState == LERPSTATE_OFF)
		{
			if (viewAngles.pitch > 0)
			{
				viewAngles.pitch = Max(viewAngles.pitch, 91.0f);
			}
			else
			{
				viewAngles.pitch = Min(viewAngles.pitch, -91.0f);
			}
		}
		
	}
	else if ( mountedObject )
	{
		int yaw_min, yaw_max, varc;

		mountedObject->GetAngleRestrictions( yaw_min, yaw_max, varc );

		if ( yaw_min < yaw_max ) {
			viewAngles.yaw = idMath::ClampFloat( yaw_min, yaw_max, viewAngles.yaw );
		} else {
			if ( viewAngles.yaw < 0 ) {
				viewAngles.yaw = idMath::ClampFloat( -180.f, yaw_max, viewAngles.yaw );
			} else {
				viewAngles.yaw = idMath::ClampFloat( yaw_min, 180.f, viewAngles.yaw );
			}
		}
		viewAngles.pitch = idMath::ClampFloat( -varc, varc, viewAngles.pitch );
	}
	else if (peekObject.IsValid())
	{
		//Ventpeek.	

		//restrict view angles.
		if (peekObject.GetEntity()->IsType(idVentpeek::Type))
		{
			float yaw_min, yaw_max, varc_min, varc_max;

			static_cast<idVentpeek *>(peekObject.GetEntity())->GetAngleRestrictions(yaw_min, yaw_max, varc_min, varc_max);

			if (yaw_min != 0 && yaw_max != 0)
			{
				// make sure yaw_min is smaller
				if (yaw_min > yaw_max) {
					yaw_min -= 360.0f;
				}

				// convert back to arc point and arc size,
				// simplifying edge cases when crossing between -180 to 180 normalized angles
				float midArc = (yaw_max+yaw_min)*0.5f;
				float arcSize = yaw_max-yaw_min;

				viewAngles.yaw = ClampViewArc( midArc, arcSize, false );
			}
			viewAngles.pitch = idMath::ClampFloat(varc_min, varc_max, viewAngles.pitch);
		}
	}
	else if (confinedAngleLock)
	{		
		//player is in confined area state. Lock the viewing arc.
		viewAngles.yaw = ClampViewArc(confinedAngle, CONFINED_VIEWARC);

		viewAngles.pitch = Min(viewAngles.pitch, pm_maxviewpitch.GetFloat()); //downward pitch.		
		viewAngles.pitch = Max(viewAngles.pitch, pm_minviewpitch.GetFloat()); //upward pitch.
		
	}
	else if (viewYawLocked || viewPitchLocked)
	{
		if ( viewYawLocked )
		{
			viewAngles.yaw = ClampViewArc( viewYawLockAngle, viewYawLockArcsize );
		}

		if ( viewPitchLocked )
		{
			viewAngles.pitch = Min( viewAngles.pitch, viewPitchLockAngle + viewPitchLockArcsize / 2.0f );
			viewAngles.pitch = Max( viewAngles.pitch, viewPitchLockAngle - viewPitchLockArcsize / 2.0f );
		}
		else
		{
			viewAngles.pitch = Min(viewAngles.pitch, pm_maxviewpitch.GetFloat()); //downward pitch.		
			viewAngles.pitch = Max(viewAngles.pitch, pm_minviewpitch.GetFloat()); //upward pitch.
		}
	}
	else if (physicsObj.GetFallState() == FALLEN_HEADONGROUND || physicsObj.GetFallState() == FALLEN_RISING)
	{
		viewAngles.yaw = viewYawLockAngle;
	}
	else if ((physicsObj.GetFallState() == FALLEN_IDLE) && mechTransitionState == MECHTRANSITION_PILOTING)
	{
		viewAngles.pitch = Min(viewAngles.pitch, -45.0f); //downward pitch.		
		viewAngles.pitch = Max(viewAngles.pitch, -89.0f); //upward pitch.
	}
	else
	{
		if ( viewAngles.pitch > pm_maxviewpitch.GetFloat() ) {
			// don't let the player look down enough to see the shadow of his (non-existant) feet
			viewAngles.pitch = pm_maxviewpitch.GetFloat();
		} else if ( viewAngles.pitch < pm_minviewpitch.GetFloat() ) {
			// don't let the player look up more than 89 degrees
			viewAngles.pitch = pm_minviewpitch.GetFloat();
		}
	}

	UpdateDeltaViewAngles( viewAngles );

	// orient the model towards the direction we're looking	
	SetAngles(idAngles(0, viewAngles.yaw, 0));
	

	// save in the log for analyzing weapon angle offsets
	loggedViewAngles[ gameLocal.framenum & (NUM_LOGGED_VIEW_ANGLES-1) ] = viewAngles;
}

float idPlayer::ClampViewArc(float baseAngle, float arcSize, bool playSounds)
{
	float inputYaw; //original yaw
	float workYaw; //the value we do calculations on

	inputYaw = viewAngles.yaw;
	arcSize /= 2.0f;
	workYaw = idMath::AngleNormalize180(inputYaw - baseAngle);

	if (workYaw < -arcSize)
	{
		workYaw = -arcSize;


		if (playSounds && gameLocal.time > confinedlimitsoundTimer && !iteminspectActive && !zoominspect_LabelmodeActive)
		{
			hud->HandleNamedEvent("confinedLimitRight");
			StartSound("snd_confinedlimit", SND_CHANNEL_ANY, SSF_PRIVATE_SOUND, false, NULL);
			confinedlimitsoundTimer = gameLocal.time + 500;
		}
	}
	else if (workYaw > arcSize)
	{
		workYaw = arcSize;

		if (playSounds && gameLocal.time > confinedlimitsoundTimer && !iteminspectActive && !zoominspect_LabelmodeActive)
		{
			hud->HandleNamedEvent("confinedLimitLeft");			
			StartSound("snd_confinedlimit", SND_CHANNEL_ANY, SSF_PRIVATE_SOUND, false, NULL);
			confinedlimitsoundTimer = gameLocal.time + 500;
		}
	}

	return workYaw + baseAngle;
}

/*
==============
idPlayer::AdjustHeartRate

Player heartrate works as follows

DEF_HEARTRATE is resting heartrate

Taking damage when health is above 75 adjusts heart rate by 1 beat per second
Taking damage when health is below 75 adjusts heart rate by 5 beats per second
Maximum heartrate from damage is MAX_HEARTRATE

Firing a weapon adds 1 beat per second up to a maximum of COMBAT_HEARTRATE

Being at less than 25% stamina adds 5 beats per second up to ZEROSTAMINA_HEARTRATE

All heartrates are target rates.. the heart rate will start falling as soon as there have been no adjustments for 5 seconds
Once it starts falling it always tries to get to DEF_HEARTRATE

The exception to the above rule is upon death at which point the rate is set to DYING_HEARTRATE and starts falling
immediately to zero

Heart rate volumes go from zero ( -40 db for DEF_HEARTRATE to 5 db for MAX_HEARTRATE ) the volume is
scaled linearly based on the actual rate

Exception to the above rule is once the player is dead, the dying heart rate starts at either the current volume if
it is audible or -10db and scales to 8db on the last few beats
==============
*/
void idPlayer::AdjustHeartRate( int target, float timeInSecs, float delay, bool force ) {

	if ( heartInfo.GetEndValue() == target ) {
		return;
	}

	if ( AI_DEAD && !force ) {
		return;
	}

	lastHeartAdjust = gameLocal.time;

	heartInfo.Init( gameLocal.time + delay * 1000, timeInSecs * 1000, heartRate, target );
}


/*
==============
idPlayer::GetBaseHeartRate
==============
*/
int idPlayer::GetBaseHeartRate( void )
{
	/*
	int base = idMath::FtoiFast( ( BASE_HEARTRATE + LOWHEALTH_HEARTRATE_ADJ ) - ( (float)health / 100.0f ) * LOWHEALTH_HEARTRATE_ADJ );

	//int rate = idMath::FtoiFast( base + ( ZEROSTAMINA_HEARTRATE - base ) * ( 1.0f - stamina / pm_stamina.GetFloat() ) );
	int rate = idMath::FtoiFast(base + (ZEROSTAMINA_HEARTRATE - base) * (1.0f - health / 100.0f));
	int diff = ( lastDmgTime ) ? gameLocal.time - lastDmgTime : 99999;

	rate += ( diff < 5000 ) ? ( diff < 2500 ) ? ( diff < 1000 ) ? 15 : 10 : 5 : 0;	

	return rate;*/

	
	
	//BC get target heart rate. Target heartrate is based on current health.
	

	if (health <= HEARTRATE_LOWHEALTH || inDownedState)
		return HEARTRATE_FASTEST;
	else if (health >= HEARTRATE_HIGHHEALTH)
		return HEARTRATE_SLOWEST;
	else
	{
		//return a lerped value.
		float adjustedHealth = health;

		adjustedHealth -= HEARTRATE_LOWHEALTH;
		adjustedHealth /= (float)(HEARTRATE_HIGHHEALTH - HEARTRATE_LOWHEALTH);

		//common->Printf("%d   %f\n", health, adjustedHealth);
		return idMath::FtoiFast(idMath::Lerp(HEARTRATE_FASTEST, HEARTRATE_SLOWEST, adjustedHealth));
	}	
	
		
}

/*
==============
idPlayer::SetCurrentHeartRate
==============
*/
void idPlayer::SetCurrentHeartRate( void )
{
	//400 = fast.
	//1200 = slow.

	if (lastHeartBeat > gameLocal.time || health <= 0)
	{
		return;
	}
	else
	{
		int targetHeartrate = GetBaseHeartRate();

		if (targetHeartrate > lastTargetHeartRate)
		{
			//heartrate is SLOWING DOWN. Make it gradual.

			if (gameLocal.time > lastHeartAdjust)
			{
				targetHeartrate = Min(lastTargetHeartRate + 100, targetHeartrate);
				lastHeartAdjust = gameLocal.time + 2500;
			}
			else
			{
				targetHeartrate = lastTargetHeartRate;
			}
		}
		

		lastHeartBeat = gameLocal.time + targetHeartrate;
		lastTargetHeartRate = targetHeartrate;


		if (gameLocal.time > lastHeartVolumeAdjust && heartVolume > -40 && health > 20)
		{
			lastHeartVolumeAdjust = gameLocal.time + 1000;

			if (heartVolume > -20)
				heartVolume -= 1;
			else
				heartVolume -= 4; //at low volumes, fade out faster.
		}

		// SW 11th Feb 2025: adding heartbeatEnabled toggle for scripted sequences so we can turn it off at will
		if (heartVolume > -40 && defibState == DEFIB_NONE && heartbeatEnabled)
		{
			soundShaderParms_t	parms;

			StartSound("snd_heartbeat", SND_CHANNEL_HEART, SSF_PRIVATE_SOUND, false, NULL);
			
			memset(&parms, 0, sizeof(parms));
			parms.volume = heartVolume;
			refSound.referenceSound->ModifySound(SND_CHANNEL_HEART, &parms);
		}
	}

	/*

	int base = idMath::FtoiFast( ( BASE_HEARTRATE + LOWHEALTH_HEARTRATE_ADJ ) - ( (float) health / 100.0f ) * LOWHEALTH_HEARTRATE_ADJ );

	if ( PowerUpActive( ADRENALINE )) {
		heartRate = 135;
	} else {
		heartRate = idMath::FtoiFast( heartInfo.GetCurrentValue( gameLocal.time ) );
		int currentRate = GetBaseHeartRate();
		if ( health >= 0 && gameLocal.time > lastHeartAdjust + 2500 ) {
			AdjustHeartRate( currentRate, 2.5f, 0.0f, false );
		}
	}

	//common->Printf("heartrate %d\n", heartRate);

	int bps = idMath::FtoiFast( 60.0f / heartRate * 1000.0f );
	if ( gameLocal.time - lastHeartBeat > bps ) {
		int dmgVol = DMG_VOLUME;
		int deathVol = DEATH_VOLUME;
		int zeroVol = ZERO_VOLUME;
		float pct = 0.0;

		if ( heartRate > BASE_HEARTRATE && health > 0 )
		{
			pct = (float)(heartRate - base) / (MAX_HEARTRATE - base);
			pct *= ((float)dmgVol - (float)zeroVol);
		}
		else if ( health <= 0 )
		{
			pct = (float)(heartRate - DYING_HEARTRATE) / (BASE_HEARTRATE - DYING_HEARTRATE);
			if ( pct > 1.0f ) {
				pct = 1.0f;
			} else if (pct < 0.0f) {
				pct = 0.0f;
			}
			pct *= ((float)deathVol - (float)zeroVol);
		}

		pct += (float)zeroVol;

		
		//BC heartbeat sound.
		if ( pct != zeroVol )
		{
			StartSound( "snd_heartbeat", SND_CHANNEL_HEART, SSF_PRIVATE_SOUND, false, NULL );
			// modify just this channel to a custom volume
			soundShaderParms_t	parms;
			memset( &parms, 0, sizeof( parms ) );
			parms.volume = pct;
			refSound.referenceSound->ModifySound( SND_CHANNEL_HEART, &parms );
		}

		lastHeartBeat = gameLocal.time;
	}*/
}

/*
==============
idPlayer::UpdateAir
==============
*/
void idPlayer::UpdateAir( void ) {
	if ( health <= 0 )
	{
		return;
	}

	if (gameLocal.time <= 200)//BC crash
	{
		return;
	}

	// see if the player is connected to the info_vacuum
	bool	newAirless = false;

	if ( gameLocal.vacuumAreaNum != -1 )
	{
		int	num = GetNumPVSAreas();
		if ( num > 0 )
		{
			int		areaNum;

			// if the player box spans multiple areas, get the area from the origin point instead,
			// otherwise a rotating player box may poke into an outside area
			if ( num == 1 )
			{
				const int	*pvsAreas = GetPVSAreas();
				areaNum = pvsAreas[0];
			}
			else
			{
				areaNum = gameRenderWorld->PointInArea( this->GetPhysics()->GetOrigin() );
			}

			newAirless = gameRenderWorld->AreasAreConnected( gameLocal.vacuumAreaNum, areaNum, PS_BLOCK_AIR );
		}
	}

	hud->SetStateBool("airless", newAirless);

#ifdef _D3XP
	if ( PowerUpActive( ENVIROTIME ) ) {
		newAirless = false;
	}
#endif

	if ( newAirless && !spectating)
	{
		float lastAirtic = airTics;

		if ( !airless )
		{
			//BC this gets called whenever player enters Zero-g state.
			StartSound( "snd_decompress", SND_CHANNEL_ANY, SSF_GLOBAL, false, NULL );

			if (!noclip) //Only do breathing sound if noclip is off.
			{
				StartSound("snd_airtank", SND_CHANNEL_BODY2, 0, false, NULL); //Breathing noise from the airtank.
			}

			gameSoundWorld->SetEnviroSuit(true);

			
			//BC if player is touching ground, gently float them upward.
			if (this->GetPhysics()->HasGroundContacts())
			{
				idVec3 impulseForce = idVec3(0, 0, 10000);
				GetPhysics()->ApplyImpulse(0, GetPhysics()->GetAbsBounds().GetCenter(), impulseForce);
			}
		}

		
		if (!noclip)
		{
			//BC DISABLE OXYGEN. Trying out a change where we disable the oxygen system.

			//if (!g_stopTime.GetBool())
			//{
			//	if (oxygenFreezeTimer < gameLocal.time)
			//	{
			//		//Decrease air supply.
			//		airTics += (MS2SEC(gameLocal.msec) * AIR_ZEROG_DECREASE_PER_SECOND) * g_oxygenscale.GetFloat();
			//	}
			//}

			//if (lastAirtic >= pm_airTics.GetInteger())
			//{
			//	oxygenmeterIsFaded = false;
			//	hud->HandleNamedEvent("oxygenmeter_show");
			//}
		}
		else
		{
			airTics = pm_airTics.GetInteger(); //If noclip, then air tank is always full.
		}

		
		//If no oxygen....
		if ( airTics <= 0 )
		{
			if (lastAirtic > 0.0f)
			{
				StartSound("snd_noair", SND_CHANNEL_BODY2, 0, false, NULL);
			}

			airTics = 0.0f;
			// check for damage
			const idDict *damageDef = gameLocal.FindEntityDefDict( "damage_noair_player", false );
			int dmgTiming = 1000 * ((damageDef) ? damageDef->GetFloat( "delay", "3.0" ) : 3.0f ); //delay between damage pangs.
			if ( gameLocal.time > lastAirDamage + dmgTiming )
			{
				Damage( NULL, NULL, vec3_origin, "damage_noair_player", 1.0f, 0 );
				lastAirDamage = gameLocal.time;

				//if (hud)
				//{
				//	hud->HandleNamedEvent("noair");
				//}
			}
		}

	}
	else
	{
		//AIR RECHARGE

		if ( airless && !spectating)
		{
			//stepping into an oxygen area. Regain oxygen.
			StopSound(SND_CHANNEL_BODY2, false); //Stop the suffocation breathing sound.
			StartSound( "snd_recompress", SND_CHANNEL_ANY, SSF_GLOBAL, false, NULL );			
			if ( hud )
			{
				hud->HandleNamedEvent( "Air" );
			}
		
			gameSoundWorld->SetEnviroSuit(false); 
		}

		//BC always give the player one airtic, so that the logic for air sounds still works.		
		if (airTics < AIR_DEFAULTAMOUNT)
		{
			if (!g_stopTime.GetBool())
			{
				airTics += MS2SEC(gameLocal.msec) * AIR_FILL_PER_SECOND;	// when in oxygen area, refill oxygen tank at this rate.		
			}

			if (airTics > AIR_DEFAULTAMOUNT)
			{
				airTics = AIR_DEFAULTAMOUNT;
			}
		}

		

		//airTics+=64;	// when in oxygen area, refill oxygen tank at this rate.
		//
		//if ( airTics > pm_airTics.GetInteger() )
		//{
		//	airTics = pm_airTics.GetInteger();
		//}
	}

	airless = newAirless;

	if ( hud )
	{
		//So, because airTics are ticked down every frame, and Doom updates
		//the game 60 times every second, we're multiplying the airTics value
		//by 16.666666666666 in order to get the amount of milliseconds left.
		float secondsLeft = (airTics * 16.666666666f) / 1000.0f;
		//hud->SetStateString("player_airsec", va("%.1f", secondsLeft));
		hud->SetStateString("player_airsec", va("%d", (int)secondsLeft));

		//this is for the meter.
		hud->SetStateInt( "player_air", 100 * airTics / pm_airTics.GetInteger() );
	}
}

void idPlayer::UpdatePowerupHud() {

	if ( health <= 0 ) {
		return;
	}

	if(lastHudPowerup != hudPowerup) {

		if(hudPowerup == -1) {
			//The powerup hud should be turned off
			if ( hud ) {
				hud->HandleNamedEvent( "noPowerup" );
			}
		} else {
			//Turn the pwoerup hud on
			if ( hud ) {
				hud->HandleNamedEvent( "Powerup" );
			}
		}

		lastHudPowerup = hudPowerup;
	}

	if(hudPowerup != -1) {
		if(PowerUpActive(hudPowerup)) {
			int remaining = inventory.powerupEndTime[ hudPowerup ] - gameLocal.time;
			int filledbar = idMath::ClampInt( 0, hudPowerupDuration, remaining );

			if ( hud ) {
				hud->SetStateInt( "player_powerup", 100 * filledbar / hudPowerupDuration );
				hud->SetStateInt( "player_poweruptime", remaining / 1000 );
			}
		}
	}
}

/*
==============
idPlayer::AddGuiPDAData
==============
 */
int idPlayer::AddGuiPDAData( const declType_t dataType, const char *listName, const idDeclPDA *src, idUserInterface *gui ) {
	int c, i;
	idStr work;
	if ( dataType == DECL_EMAIL ) {
		c = src->GetNumEmails();
		for ( i = 0; i < c; i++ ) {
			const idDeclEmail *email = src->GetEmailByIndex( i );
			if ( email == NULL ) {
				work = va( "-\tEmail %d not found\t-", i );
			} else
			{
				//BC This is the list of emails from a specific person.

				work = "";
				if (email->IsCritical() && ((!src->IsEmailReplied(email->GetName()) && email->HasReplies())
					|| !src->IsEmailRead(email->GetName())))
				{
					work = "mtr_critical";
				}
				else if (!src->IsEmailRead(email->GetName()))
				{
					work = "mtr_unread";
				}
				work += "\t";

				work += common->GetLanguageDict()->GetString(email->GetFrom());
				work += "\t";
				work += common->GetLanguageDict()->GetString(email->GetSubject());
				//work += "\t";
				//work += email->GetDate();
			}
			gui->SetStateString( va( "%s_item_%i", listName, i ), work );
		}
		return c;
	} else if ( dataType == DECL_AUDIO ) {
		c = src->GetNumAudios();
		for ( i = 0; i < c; i++ ) {
			const idDeclAudio *audio = src->GetAudioByIndex( i );
			if ( audio == NULL ) {
				work = va( "Audio Log %d not found", i );
			} else {
				work = audio->GetAudioName();
			}
			gui->SetStateString( va( "%s_item_%i", listName, i ), work );
		}
		return c;
	} else if ( dataType == DECL_VIDEO ) {
		c = inventory.videos.Num();
		for ( i = 0; i < c; i++ ) {
			const idDeclVideo *video = GetVideo( i );
			if ( video == NULL ) {
				work = va( "Video CD %s not found", inventory.videos[i].c_str() );
			} else {
				work = video->GetVideoName();
			}
			gui->SetStateString( va( "%s_item_%i", listName, i ), work );
		}
		return c;
	}
	return 0;
}

/*
==============
idPlayer::GetPDA
==============
 */
const idDeclPDA *idPlayer::GetPDA( void ) const
{
	if ( inventory.pdas.Num() )
	{
		return static_cast< const idDeclPDA* >( declManager->FindType( DECL_PDA, inventory.pdas[ 0 ] ) );
	}
	else
	{
		return NULL;
	}
}

const idDeclPDA* idPlayer::GetPDAViaTalker(idStr talkerName) const
{
	if (inventory.pdas.Num())
	{
		for (int i = 0; i < inventory.pdas.Num(); i++)
		{
			if (idStr::Icmp(talkerName, inventory.pdas[i]) == 0)
			{
				return static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[i]));
			}
		}
	}

	return NULL;
}


/*
==============
idPlayer::GetVideo
==============
*/
const idDeclVideo *idPlayer::GetVideo( int index ) {
	if ( index >= 0 && index < inventory.videos.Num() ) {
		return static_cast< const idDeclVideo* >( declManager->FindType( DECL_VIDEO, inventory.videos[index], false ) );
	}
	return NULL;
}


/*
==============
idPlayer::UpdatePDAInfo
==============
*/
void idPlayer::UpdatePDAInfo( bool updatePDASel ) {
	int j, sel;

	emailInboxCheckActive = true;

	if ( objectiveSystem == NULL ) {
		return;
	}

	assert( hud );

	int currentPDA = objectiveSystem->State().GetInt( "listPDA_sel_0", "0" );
	currentlyActiveEmailInbox = currentPDA; //BC keep track of which email inbox is currently active.
	if ( currentPDA == -1 ) {
		currentPDA = 0;
	}

	if ( updatePDASel && inventory.pdas.Num() > currentPDA) {
		objectiveSystem->SetStateInt( "listPDAVideo_sel_0", 0 );
		objectiveSystem->SetStateInt( "listPDAEmail_sel_0", 0 );
		objectiveSystem->SetStateInt( "listPDAAudio_sel_0", 0 );

		// Select the newest read email
		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[currentPDA], false));
		if (pda)
		{
			int selectIndex = 0;
			for (int i = 0; i < pda->GetNumEmails(); i++)
			{
				if (pda->IsEmailRead(pda->GetEmailByIndex(i)->GetName()))
				{
					selectIndex = i;
				}
			}
			objectiveSystem->SetStateInt("listPDAEmail_sel_0", selectIndex);
			objectiveSystem->SetStateInt("listPDAEmail_scroll_0", selectIndex);
		}
	}

	// SM: Just show PDAs in the order given to fix autoselect problems where the pda number changes
// 	if ( currentPDA > 0 ) {
// 		currentPDA = inventory.pdas.Num() - currentPDA;
// 	}

	// Mark in the bit array that this pda has been read
	if ( currentPDA < 128 ) {
		inventory.pdasViewed[currentPDA >> 5] |= 1 << (currentPDA & 31);
	}

	pdaAudio = "";
	pdaVideo = "";
	pdaVideoWave = "";
	idStr pdaName, name, data, preview, info, wave, reply1, reply2, fromName, toName, fromAddress, senderModel;
	for ( j = 0; j < MAX_PDAS; j++ ) {
		objectiveSystem->SetStateString( va( "listPDA_item_%i", j ), "" );
	}
	for ( j = 0; j < MAX_PDA_ITEMS; j++ ) {
		objectiveSystem->SetStateString( va( "listPDAVideo_item_%i", j ), "" );
		objectiveSystem->SetStateString( va( "listPDAAudio_item_%i", j ), "" );
		objectiveSystem->SetStateString( va( "listPDAEmail_item_%i", j ), "" );
		objectiveSystem->SetStateString( va( "listPDASecurity_item_%i", j ), "" );
	}
	for ( j = 0; j < inventory.pdas.Num(); j++ ) {

		const idDeclPDA *pda = static_cast< const idDeclPDA* >( declManager->FindType( DECL_PDA, inventory.pdas[j], false ) );

		if ( pda == NULL ) {
			continue;
		}

		// SM: Just show PDAs in the order given to fix autoselect problems where the pda number changes
		int index = j;
// 		int index = inventory.pdas.Num() - j;
// 		if ( j == 0 ) {
// 			// Special case for the first PDA
// 			index = 0;
// 		}

// 		if ( j != currentPDA && j < 128 && inventory.pdasViewed[j >> 5] & (1 << (j & 31)) )
// 		{
// 			// This pda has been read already, mark in gray
// 			objectiveSystem->SetStateString( va( "listPDA_item_%i", index), va(S_COLOR_GRAY "%s", common->GetLanguageDict()->GetString(pda->GetPdaName())) );
// 		}
// 		else
// 		{
// 			// This pda has not been read yet
// 			objectiveSystem->SetStateString( va( "listPDA_item_%i", index), common->GetLanguageDict()->GetString(pda->GetPdaName()) );
// 		}

		const char *security = pda->GetSecurity();
		if ( j == currentPDA || (currentPDA == 0 && security && *security ) ) {
			if ( *security == 0 ) {
				security = common->GetLanguageDict()->GetString( "#str_loc_unknown_00104" ); //bc general email access, this might be safe to delete
			}
			objectiveSystem->SetStateString( "PDASecurityClearance", security );
		}

		if ( j == currentPDA ) {

			objectiveSystem->SetStateString( "pda_icon", pda->GetIcon() );
			objectiveSystem->SetStateString( "pda_id", pda->GetID() );
			objectiveSystem->SetStateString( "pda_title", pda->GetTitle() );

			//if ( j == 0 )
			//{
			//	// Selected, personal pda
			//	// Add videos
			//	if ( updatePDASel || !inventory.pdaOpened ) {
			//	objectiveSystem->HandleNamedEvent( "playerPDAActive" );
			//	objectiveSystem->SetStateString( "pda_personal", "1" );
			//		inventory.pdaOpened = true;
			//	}
			//	objectiveSystem->SetStateString( "pda_location", hud->State().GetString("location") );
			//	objectiveSystem->SetStateString( "pda_name", cvarSystem->GetCVarString( "ui_name") );
			//	AddGuiPDAData( DECL_VIDEO, "listPDAVideo", pda, objectiveSystem );
			//	sel = objectiveSystem->State().GetInt( "listPDAVideo_sel_0", "0" );
			//	const idDeclVideo *vid = NULL;
			//	if ( sel >= 0 && sel < inventory.videos.Num() ) {
			//		vid = static_cast< const idDeclVideo * >( declManager->FindType( DECL_VIDEO, inventory.videos[ sel ], false ) );
			//	}
			//	if ( vid ) {
			//		pdaVideo = vid->GetRoq();
			//		pdaVideoWave = vid->GetWave();
			//		objectiveSystem->SetStateString( "PDAVideoTitle", vid->GetVideoName() );
			//		objectiveSystem->SetStateString( "PDAVideoVid", vid->GetRoq() );
			//		objectiveSystem->SetStateString( "PDAVideoIcon", vid->GetPreview() );
			//		objectiveSystem->SetStateString( "PDAVideoInfo", vid->GetInfo() );
			//	} else {
			//		//FIXME: need to precache these in the player def
			//		objectiveSystem->SetStateString( "PDAVideoVid", "sound/vo/video/welcome.tga" );
			//		objectiveSystem->SetStateString( "PDAVideoIcon", "sound/vo/video/welcome.tga" );
			//		objectiveSystem->SetStateString( "PDAVideoTitle", "" );
			//		objectiveSystem->SetStateString( "PDAVideoInfo", "" );
			//	}
			//}
			//else
			{
				// Selected, non-personal pda
				// Add audio logs
				if ( updatePDASel ) {
				objectiveSystem->HandleNamedEvent( "playerPDANotActive" );
				objectiveSystem->SetStateString( "pda_personal", "0" );
					inventory.pdaOpened = true;
				}
				objectiveSystem->SetStateString( "pda_location", pda->GetPost() );
				objectiveSystem->SetStateString("pda_charactername", common->GetLanguageDict()->GetString(pda->GetPdaName())); //character name.
				objectiveSystem->SetStateString( "pda_name", common->GetLanguageDict()->GetString(pda->GetFullName()) ); //email address.
				int audioCount = AddGuiPDAData( DECL_AUDIO, "listPDAAudio", pda, objectiveSystem );
				objectiveSystem->SetStateInt( "audioLogCount", audioCount );
				sel = objectiveSystem->State().GetInt( "listPDAAudio_sel_0", "0" );
				const idDeclAudio *aud = NULL;
				if ( sel >= 0 ) {
					aud = pda->GetAudioByIndex( sel );
				}
				if ( aud ) {
					pdaAudio = aud->GetWave();
					objectiveSystem->SetStateString( "PDAAudioTitle", aud->GetAudioName() );
					objectiveSystem->SetStateString( "PDAAudioIcon", aud->GetPreview() );
					objectiveSystem->SetStateString( "PDAAudioInfo", aud->GetInfo() );
				} else {
					objectiveSystem->SetStateString( "PDAAudioIcon", "sound/vo/video/welcome.tga" );
					objectiveSystem->SetStateString( "PDAAutioTitle", "" );
					objectiveSystem->SetStateString( "PDAAudioInfo", "" );
				}
			}
			// add emails
			name = "";
			data = "";
			reply1 = "";
			reply2 = "";
			fromName = "";
			toName = "";
			fromAddress = "";
			senderModel = "";
			emailReplyFunc1 = "";
			emailReplyFunc2 = "";
			int numEmails = pda->GetNumEmails();
			if ( numEmails > 0 ) {
				sel = objectiveSystem->State().GetInt( "listPDAEmail_sel_0", "-1" );
				if ( sel >= 0 && sel < numEmails ) {
					const idDeclEmail *email = pda->GetEmailByIndex( sel );
					name = email->GetSubject();
					data = email->GetBody();

					//BC from/to info.
					fromName = email->GetFrom();
					toName = email->GetTo();


					if (idStr::Icmp(fromName, pda->GetPdaName()) == 0)
					{
						//Current email is from the inbox owner.
						fromAddress = pda->GetFullName();
						emailFullscreenMenu->SetStateBool("emailfromcat", true);
						objectiveSystem->SetStateString("PDAEmailDescription", common->GetLanguageDict()->GetString(pda->GetDescription()));
					}
					else
					{
						//Current email is from not inbox owner, so it must be Nina.
						fromAddress = "#str_emailfullname_nina";
						emailFullscreenMenu->SetStateBool("emailfromcat", false);
						objectiveSystem->SetStateString("PDAEmailDescription", common->GetLanguageDict()->GetString("#str_emaildescription_nina"));
					}

					senderModel = pda->GetSenderModel();


					if (!pda->IsEmailReplied(email->GetName()))
					{
						reply1 = email->GetReply1();
						reply2 = email->GetReply2();
						emailReplyFunc1 = email->GetReplyFunc1();
						emailReplyFunc2 = email->GetReplyFunc2();
					}
					
					if (pda->AddEmailRead(email->GetName()))
					{
						idStr inventoryName = pda->GetName();
						inventoryName += ";";
						inventoryName += email->GetName();
						inventory.emailsRead.AddUnique(inventoryName);

						//Email was read just now.
						idStr readFunc = email->GetReadFunc();
						if (readFunc.Length() > 0)
						{
							if (g_debugEmailScript.GetBool())
							{
								common->Printf("Email '%s': calling READFUNC '%s'\n", email->GetName(), readFunc.c_str());
							}

							gameLocal.RunMapScript(readFunc.c_str()); //BC call the script function when email is read.
						}
					}
				}
				AddGuiPDAData(DECL_EMAIL, "listPDAEmail", pda, objectiveSystem);
			}
			objectiveSystem->SetStateString( "PDAEmailTitle", common->GetLanguageDict()->GetString(name) );
			objectiveSystem->SetStateString( "PDAEmailText", common->GetLanguageDict()->GetString(data) );

			//BC set the from/to info.
			objectiveSystem->SetStateString("PDAEmailFrom", common->GetLanguageDict()->GetString(fromName));			
			objectiveSystem->SetStateString("PDAEmailTo", common->GetLanguageDict()->GetString(toName));
			objectiveSystem->SetStateString("PDAEmailFromAddress", common->GetLanguageDict()->GetString(fromAddress));
			
			objectiveSystem->SetStateString("replybutton1", common->GetLanguageDict()->GetString(reply1));
			objectiveSystem->SetStateBool("replybuttonvisible1", !reply1.IsEmpty());

			objectiveSystem->SetStateString("replybutton2", common->GetLanguageDict()->GetString(reply2));
			objectiveSystem->SetStateBool("replybuttonvisible2", !reply2.IsEmpty());


			// set model of the sender.
			if (senderModel.Length() > 0)
			{
				objectiveSystem->SetStateString("sendermodel", senderModel.c_str());
			}				
		}

		// Update the pda name (and flags) after the emails are checked in case we read the last one
		pdaName = "\t";
		if (pda->HasCriticalUnrepliedEmails())
		{
			pdaName = "mtr_critical\t";
		}
		else if (pda->HasUnreadEmails())
		{
			pdaName = "mtr_unread\t";
		}
		pdaName += common->GetLanguageDict()->GetString(pda->GetPdaName());

		objectiveSystem->SetStateString(va("listPDA_item_%i", index), pdaName);
	}

	if ( objectiveSystem->State().GetInt( "listPDA_sel_0", "-1" ) == -1 ) {
		objectiveSystem->SetStateInt( "listPDA_sel_0", 0 );
	}
	objectiveSystem->StateChanged( gameLocal.time );
}

void idPlayer::Event_HasEmailsCritical()
{
	bool hasCriticalEmails = HasEmailsCritical();

	if (hasCriticalEmails)
		idThread::ReturnInt(1);
	else
		idThread::ReturnInt(0);
}

//For the email flag entity.
//Return true if player has any emails that are critical.
bool idPlayer::HasEmailsCritical()
{
	for (int j = 0; j < inventory.pdas.Num(); j++)
	{
		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[j], false));

		if (pda == NULL)		
			continue;

		//TODO: doesn't work in vig_hub?
		if (pda->HasCriticalUnrepliedEmails())
		{			
			return true;
		}
	}
	
	return false;
}

//For the email flag entity.
//Return true if player has any emails that are unread.
bool idPlayer::HasEmailsUnread()
{
	for (int j = 0; j < inventory.pdas.Num(); j++)
	{
		const idDeclPDA* pda = static_cast<const idDeclPDA*>(declManager->FindType(DECL_PDA, inventory.pdas[j], false));

		if (pda == NULL)
			continue;

		//TODO: doesn't work in vig_hub?
		if (pda->HasUnreadEmails())
			return true;
	}

	return false;
}

/*
==============
idPlayer::TogglePDA
==============
*/
void idPlayer::TogglePDA( void ) {
	if ( objectiveSystem == NULL ) {
		return;
	}

	if ( inventory.pdas.Num() == 0 ) {
		ShowTip( spawnArgs.GetString( "text_infoTitle" ), spawnArgs.GetString( "text_noPDA" ), true );
		return;
	}

	assert( hud );

	if ( !objectiveSystemOpen ) {
		int j, c = inventory.items.Num();
		objectiveSystem->SetStateInt( "inv_count", c );
		for ( j = 0; j < MAX_INVENTORY_ITEMS; j++ ) {
			objectiveSystem->SetStateString( va( "inv_name_%i", j ), "" );
			objectiveSystem->SetStateString( va( "inv_icon_%i", j ), "" );
			objectiveSystem->SetStateString( va( "inv_text_%i", j ), "" );
		}
		for ( j = 0; j < c; j++ ) {
			idDict *item = inventory.items[j];
			if ( !item->GetBool( "inv_pda" ) ) {
				const char *iname = item->GetString( "inv_name" );
				const char *iicon = item->GetString( "inv_icon" );
				const char *itext = item->GetString( "inv_text" );
				objectiveSystem->SetStateString( va( "inv_name_%i", j ), iname );
				objectiveSystem->SetStateString( va( "inv_icon_%i", j ), iicon );
				objectiveSystem->SetStateString( va( "inv_text_%i", j ), itext );
				const idKeyValue *kv = item->MatchPrefix( "inv_id", NULL );
				if ( kv ) {
					objectiveSystem->SetStateString( va( "inv_id_%i", j ), kv->GetValue() );
				}
			}
		}

		// SM: Don't think this weapon tracking is relevant the way we use hotbar slots
// 		for ( j = 0; j < MAX_WEAPONS; j++ ) {
// 			const char *weapnum = va( "def_weapon%d", j );
// 			const char *hudWeap = va( "weapon%d", j );
// 			int weapstate = 0;
// 			if ( inventory.weapons & ( 1 << j ) ) {
// 				const char *weap = spawnArgs.GetString( weapnum );
// 				if ( weap && *weap ) {
// 					weapstate++;
// 				}
// 			}
// 			objectiveSystem->SetStateInt( hudWeap, weapstate );
// 		}

		objectiveSystem->SetStateInt( "listPDA_sel_0", inventory.selPDA );
		objectiveSystem->SetStateInt( "listPDAVideo_sel_0", inventory.selVideo );
		objectiveSystem->SetStateInt( "listPDAAudio_sel_0", inventory.selAudio );
		objectiveSystem->SetStateInt( "listPDAEmail_sel_0", inventory.selEMail );
		UpdatePDAInfo( false );
		UpdateObjectiveInfo();
		objectiveSystem->Activate( true, gameLocal.time );
		hud->HandleNamedEvent( "pdaPickupHide" );
		hud->HandleNamedEvent( "videoPickupHide" );
	} else {
		inventory.selPDA = objectiveSystem->State().GetInt( "listPDA_sel_0" );
		inventory.selVideo = objectiveSystem->State().GetInt( "listPDAVideo_sel_0" );
		inventory.selAudio = objectiveSystem->State().GetInt( "listPDAAudio_sel_0" );
		inventory.selEMail = objectiveSystem->State().GetInt( "listPDAEmail_sel_0" );
		objectiveSystem->Activate( false, gameLocal.time );
	}
	objectiveSystemOpen ^= 1;
}

/*
==============
idPlayer::ToggleScoreboard
==============
*/
void idPlayer::ToggleScoreboard( void ) {
	scoreBoardOpen ^= 1;
}

/*
==============
idPlayer::Spectate
==============
*/
void idPlayer::Spectate( bool spectate ) {
	idBitMsg	msg;
	byte		msgBuf[MAX_EVENT_PARAM_SIZE];

	// track invisible player bug
	// all hiding and showing should be performed through Spectate calls
	// except for the private camera view, which is used for teleports
	assert( ( teleportEntity.GetEntity() != NULL ) || ( IsHidden() == spectating ) );

	if ( spectating == spectate ) {
		return;
	}

	spectating = spectate;

	if ( gameLocal.isServer ) {
		msg.Init( msgBuf, sizeof( msgBuf ) );
		msg.WriteBits( spectating, 1 );
		ServerSendEvent( EVENT_SPECTATE, &msg, false, -1 );
	}

	if ( spectating )
	{
		// join the spectators
		ClearPowerUps();
		spectator = this->entityNumber;
		Init();
		StopRagdoll();
		SetPhysics( &physicsObj );
		physicsObj.DisableClip();
		Hide();
		Event_DisableWeapon();
		if ( hud )
		{
			hud->HandleNamedEvent( "aim_clear" );
			MPAimFadeTime = 0;
		}

		//BC reset the spectate UI stuff.
		spectateUIActive = true;
		spectateStatsActive = true;

		//Spawn the spectate timeline entity. TODO: make this into a .def entry...
		idDict args;
		args.Clear();
		spectateTimelineEnt = gameLocal.SpawnEntityType(idSpectateTimeline::Type, &args);
	}
	else
	{
		// put everything back together again
		currentWeaponSlot = -1;	// to make sure the def will be loaded if necessary
		Show();
		Event_EnableWeapon();
	}
	SetClipModel();
}

/*
==============
idPlayer::SetClipModel
==============
*/
void idPlayer::SetClipModel( void ) {
	idBounds bounds;

	if ( spectating ) {
		bounds = idBounds( vec3_origin ).Expand( pm_spectatebbox.GetFloat() * 0.5f );
	}
	else if (mechTransitionState == MECHTRANSITION_PILOTING)
	{
		//BC This makes the clipmodel huge so that player-mechs cannot fit through doorways.
		int mechRadius = 35;
		int mechHeight = 120;
		bounds[0].Set(-mechRadius, -mechRadius, 0);
		bounds[1].Set(mechRadius, mechRadius, mechHeight);
	}
	else
	{
		//Normal bounding box.
		bounds[0].Set( -pm_bboxwidth.GetFloat() * 0.5f, -pm_bboxwidth.GetFloat() * 0.5f, 0 );
		bounds[1].Set( pm_bboxwidth.GetFloat() * 0.5f, pm_bboxwidth.GetFloat() * 0.5f, pm_normalheight.GetFloat() );
	}

	// the origin of the clip model needs to be set before calling SetClipModel
	// otherwise our physics object's current origin value gets reset to 0
	idClipModel *newClip;
	if ( pm_usecylinder.GetBool() ) {
		newClip = new idClipModel( idTraceModel( bounds, 8 ) );
		newClip->Translate( physicsObj.PlayerGetOrigin() );
		physicsObj.SetClipModel( newClip, 1.0f );
	} else {
		newClip = new idClipModel( idTraceModel( bounds ) );
		newClip->Translate( physicsObj.PlayerGetOrigin() );
		physicsObj.SetClipModel( newClip, 1.0f );
	}
}

/*
==============
idPlayer::UseVehicle
==============
*/
void idPlayer::UseVehicle( void ) {
	trace_t	trace;
	idVec3 start, end;
	idEntity *ent;

	if ( GetBindMaster() && GetBindMaster()->IsType( idAFEntity_Vehicle::Type ) ) {
		Show();
		static_cast<idAFEntity_Vehicle*>(GetBindMaster())->Use( this );
	} else {
		start = GetEyePosition();
		end = start + viewAngles.ToForward() * 80.0f;
		gameLocal.clip.TracePoint( trace, start, end, MASK_SHOT_RENDERMODEL, this );
		if ( trace.fraction < 1.0f ) {
			ent = gameLocal.entities[ trace.c.entityNum ];
			if ( ent && ent->IsType( idAFEntity_Vehicle::Type ) ) {
				Hide();
				static_cast<idAFEntity_Vehicle*>(ent)->Use( this );
			}
		}
	}
}

// SW: For cleanliness and preventing wacky edge-cases, 
// there are conditions under which we want to prevent the player entering the context menu,
// usually during quick state-change animations.
// This is just a convenience method for grouping those conditions.
bool idPlayer::CanEnterContextMenu(void)
{
	if (/*clambering*/
		physicsObj.GetClamberState() == CLAMBERSTATE_RAISING ||
		physicsObj.GetClamberState() == CLAMBERSTATE_SETTLING ||

		/*mech stuff*/
		mechTransitionState == MECHTRANSITION_ENTERING ||
		mechTransitionState == MECHTRANSITION_MOVINGTOBEHIND ||

		/*entering vent*/
		physicsObj.GetZippingState() ||

		/*zipcord*/
		GetSwoopState() ||

		mechTransitionState != MECHTRANSITION_NONE

		|| zoommodeActive

		|| isInVignette
		)
	{
		return false;
	}

	if (weapon.IsValid())
	{
		if (weapon.GetEntity()->IsInspectingChamber() || weapon.GetEntity()->IsInspectingMagazine() || iteminspectActive)
		{
			return false;
		}
	}

	return true;
}

// Stops sound from continuing to play while the player is in the context menu. Time is frozen, so sounds shouldn't keep playing!
//
// This has a known issue where long non-looping sounds (e.g. PA system announcements) will stop completely if we stay in the menu too long.
void idPlayer::UpdateContextMenuSound(void)
{
	if (contextMenuState == CONTEXTMENU_ACTIVE)
	{
		// Enter slowmo audio and quickly ramp down to zero speed
		if (!soundSlowmoActive)
		{
			soundSlowmoHandle = gameSoundWorld->EnterSlowmo();
			soundSlowmoActive = true;
		}

		if (contextMenuSoundSpeed > 0.0f)
		{
			contextMenuSoundSpeed -= 0.05f;
			gameSoundWorld->SetSlowmoSpeed(contextMenuSoundSpeed, soundSlowmoHandle);
		}
		else if (!gameSoundWorld->IsPaused())
		{
			gameSoundWorld->SetSlowmoSpeed( 0.0f, soundSlowmoHandle );
			gameSoundWorld->Pause();
		}
	}
	else
	{
		// Don't ramp back up, just snap to real-time to minimize lag (there's no actual slow-motion being done, so the sound is now lagging behind reality)
		if (soundSlowmoActive)
		{
			if (gameSoundWorld->IsPaused())
			{
				gameSoundWorld->UnPause();
			}
			gameSoundWorld->ExitSlowmo(soundSlowmoHandle);
			contextMenuSoundSpeed = 1.0f;
			soundSlowmoActive = false;
		}
	}
	
}

//Gets called when context menu is toggled on/off
void idPlayer::contextMenuToggle()
{
	if (peekObject.IsValid() || spectating || eventlogMenuActive || IsLeaning() || jockeyState == JCK_ATTACHED)
		return;

	if (armstatsActive)
	{
		SetArmStatsActive(false);
		//make armstats go away immediately.
		//armstatsModel->Hide();
		return;
	}

	//Light editor.
	//if (g_editEntityMode.GetInteger() > 0)
	//{
	//	//Open/close the editmenu.
	//	gameEdit->editmenuActive = !gameEdit->editmenuActive;
	//	nextContextMenuAvailableTime = gameLocal.time + 400;
	//
	//	if (gameEdit->editmenuActive)
	//	{
	//		//Edit menu has been OPENED. This gets fired ONCE whenever editmenu is opened.
	//		gameEdit->lighteditMenu->SetCursor(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2); //Center mouse cursor.
	//		oldMouseX = usercmd.mx;
	//		oldMouseY = usercmd.my;
	//
	//		gameEdit->lighteditMenu->HandleNamedEvent("openEditmenu");
	//	}
	//	else
	//	{
	//		//Edit menu has been CLOSED.
	//		gameEdit->lighteditMenu->HandleNamedEvent("closeEditmenu");
	//	}
	//
	//	return;
	//}


	//Cancel any grenade throws.
	if (weapon.GetEntity() != NULL)
	{		
		if (GetThrowArcVisible())
		{
			SetThrowArcVisible(false);
			grenadeThrowState = GRENADETHROW_NOTREADY;
			grenadeButtonTimer = 0;
			nextContextMenuAvailableTime = gameLocal.time + 300; //Prevent the contextmenu from popping up when you cancel out of aim mode.
			return;
		}
	}


	if (contextMenu == NULL || contextMenuActive || health <= 0)
	{
		return;
	}

	//center the mouse.
	contextMenu->SetCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	oldMouseX = usercmd.mx;
	oldMouseY = usercmd.my;

	//activate the menu. Set the initial state of conditions before we open the menu.
	UpdateContextConditions();

	contextMenu->Activate(true, gameLocal.time);
	contextMenuActive = true;
	contextMenuState = CONTEXTMENU_ACTIVE;
	session->SetGUI(contextMenu, NULL);	

	gameLocal.menuPause = true;

	contextmenuStartTime = gameLocal.hudTime;


    //force healthbar to display.
    gameLocal.GetLocalPlayer()->ForceShowHealthbar(0);
	
}

void idPlayer::CloseContextMenu()
{
	contextMenuState = CONTEXTMENU_OFF;
	contextMenuActive = false;
	session->SetGUI(NULL, NULL);
}

//Lerp the player view position.
void idPlayer::SetViewPosActive(bool activate, idVec3 _offset)
{
	if (activate)
	{
		viewposState = LERPSTATE_TRANSITIONON;
		viewposTargetOffset = _offset;
	}
	else
	{
		viewposState = LERPSTATE_TRANSITIONOFF;		
	}

	viewposStarttime = gameLocal.time;
}

void idPlayer::SetViewYawLerp(float targetYaw, int transitiontime)
{
	viewyawState = LERPSTATE_TRANSITIONON;
	viewyawStarttime = gameLocal.time;
	viewyawStartAngle = viewAngles.yaw;
	viewyawTargetAngle = targetYaw;	
	viewyawMovetime = transitiontime;
}

void idPlayer::SetViewPitchLerp(float targetPitch, int transitiontime)
{
	viewpitchState = LERPSTATE_TRANSITIONON;
	viewpitchStarttime = gameLocal.time;
	viewpitchStartAngle = viewAngles.pitch;
	viewpitchTargetAngle = targetPitch;
	viewpitchTransitionTime = transitiontime;
}

void idPlayer::SetViewRollLerp(float targetRoll, int transitionTime)
{
	viewrollState = LERPSTATE_TRANSITIONON;
	viewrollStarttime = gameLocal.time;
	viewrollStartAngle = viewAngles.roll;
	viewrollTargetAngle = targetRoll;
	viewrollMovetime = transitionTime;
}

//Make the player camera angle lerp toward a specific XYZ in the world.
void idPlayer::SetViewLerp(const idVec3 &targetPosition, int moveTime)
{
	idAngles lerpviewInitialPosition = this->viewAngles;
	lerpviewInitialPosition.Normalize180();

	idVec3 diff = targetPosition - GetEyePosition();
	idAngles lerpviewFinalPosition = diff.ToAngles();
	lerpviewFinalPosition.Normalize180();

	if (lerpviewInitialPosition.yaw < -90 && lerpviewFinalPosition.yaw > 0)
		lerpviewFinalPosition.yaw -= 360;

	if (lerpviewInitialPosition.yaw > 90 && lerpviewFinalPosition.yaw < 0)
		lerpviewInitialPosition.yaw -= 360;

	SetViewYawLerp(lerpviewFinalPosition.yaw, moveTime);
	SetViewPitchLerp(lerpviewFinalPosition.pitch, moveTime);
}

// Just lerp to the provided angle
void idPlayer::SetViewLerpAngles(idAngles angles, int moveTime)
{
	SetViewYawLerp(angles.yaw, moveTime);
	SetViewPitchLerp(angles.pitch, moveTime);
}

void idPlayer::SetStaminaDelta(float deltaValue)
{
	stamina += deltaValue;

	if (deltaValue < 0)
	{
		staminaChargeDelayTimer = gameLocal.time;
	}

	staminaHideDelayMode = STAMBAR_VISIBLE;
	//hud->SetStateBool("showstamina", true);
	hud->HandleNamedEvent("stamina_show");
}

//It feels weird when you're out of stamina and then it recharges immediately after a failed dash.
//So after a failed dash (due to insufficient stamina) have a short delay, to avoid this issue
void idPlayer::SetStaminaRechargeDelay()
{
	#define STAMINADELAYTIME 900

	int deltaBeforeStaminarecharge = gameLocal.time - (staminaChargeDelayTimer + pm_staminachargedelay.GetFloat());

	if (deltaBeforeStaminarecharge < STAMINADELAYTIME)
	{
		staminaChargeDelayTimer = gameLocal.time - pm_staminachargedelay.GetFloat() + STAMINADELAYTIME;
	}
}

//TODO: make confined icon pulse when player turns head too far in any direction.
//Called whenever player is inside a confined state trigger.
void idPlayer::SetConfinedState(float baseAngle, float sneezeMultiplier, bool isConfined)
{

	if (!inConfinedState)
	{
		confinedstateTimer = gameLocal.time;
	}

	inConfinedState = true; //This activates the confined system.



	//Sneeze logic.
	//if (sneezeState == SNEEZESTATE_ACCUMULATING)
	//{		
	//	float distMoved = 0;
	//
	//	distMoved = (GetPhysics()->GetOrigin() - lastPlayerPosition).LengthFast();
	//	lastPlayerPosition = GetPhysics()->GetOrigin();		
	//
	//	if (distMoved <= 0)
	//	{
	//		//if player hasn't moved, then do a random chance that the sneeze meter rises up.
	//		if (gameLocal.random.RandomInt(SNEEZE_RANDOMCHANCE) <= 0)
	//		{
	//			sneezeValue += Max(1, (int)sneezeMultiplier);
	//		}
	//	}
	//	else if (!physicsObj.GetZippingState()) //ignore player movement if they're Zipping.
	//	{
	//		sneezeValue += Max( 1, (int)(((distMoved) * SNEEZE_GROWRATE_MULTIPLIER) * sneezeMultiplier));
	//	}
	//
	//	if (sneezeValue >= SNEEZE_MAXVALUE)
	//	{
	//		//sneezeValue has reached max value. Do the sneeze. Achoooo!!
	//		DoSneeze(0);
	//	}
	//}
	//else if (sneezeState == SNEEZESTATE_LOWERING)
	//{
	//	sneezeState = SNEEZESTATE_ACCUMULATING;
	//}
}

//Call this to set the sneeze meter to a value. i.e. for walking through a black pepper cloud.
void idPlayer::SetSneezeDelta(bool movementBased, float multiplier)
{
	if (sneezeState == SNEEZESTATE_ACCUMULATING || sneezeState == SNEEZESTATE_LOWERING)
	{
	}
	else
	{
		//if in middle of sneeze, or if sneeze is resetting back to zero, then do nothing.
		return;
	}

	sneezeState = SNEEZESTATE_ACCUMULATING;

	nextSneezeTimer = gameLocal.time + 350;


	if (movementBased)
	{
		//for moving through vent shafts.
		float distMoved = 0;

		distMoved = (GetPhysics()->GetOrigin() - lastPlayerPosition).LengthFast();
		lastPlayerPosition = GetPhysics()->GetOrigin();		
		
		if (distMoved <= 0)
		{
			//Not moving. Slowly increase the sneeze timer.
			if (gameLocal.random.RandomInt(SNEEZE_RANDOMCHANCE) <= 0)
			{
				sneezeValue += 1;
			}
		}
		else if (!physicsObj.GetZippingState()) //ignore player movement if they're Zipping.
		{
			//Increase the sneeze value.
			distMoved = Min(distMoved, 128.0f); //Clamp the max move distance, as teleports (i.e. the cryo pod) sometimes makes a huge move distance.
			sneezeValue += Max(1, (int)(((distMoved)* SNEEZE_GROWRATE_MULTIPLIER) ));
		}
	}
	else
	{
		//for things like pepper dust clouds, etc
		sneezeValue += Max(1, (int)((SNEEZE_PEPPER_RATE * SNEEZE_GROWRATE_MULTIPLIER) * multiplier));
	}



	if (sneezeValue >= SNEEZE_MAXVALUE)
	{
		//sneezeValue has reached max value. Do the sneeze. Achoooo!!
		DoSneeze(0);
	}

}

void idPlayer::ClearMeleeTarget()
{
	if (meleeTarget.IsValid())
	{
		meleeTarget.GetEntity()->SetPostFlag(POST_OUTLINE_ENEMY, false);
	}
	meleeTarget = NULL;
}

void idPlayer::UpdateMeleeTarget(void)
{
	if (jockeyState == JCK_ATTACHED)
		return; //Currently riding someone. Do not update the melee target.

	if (inDownedState)
	{
		ClearMeleeTarget();
		return;
	}

	//Check if player is looking at a melee target.
	idVec3 startTr, endTr;
	trace_t targetTr;
	int cm;
	//idVec2 itemScreenpos;
	//idVec3 attackPos;

	cm = CONTENTS_SOLID | CONTENTS_OPAQUE | CONTENTS_BODY | CONTENTS_CORPSE | CONTENTS_RENDERMODEL;

	startTr = GetEyePosition();
	endTr = startTr + (viewAngles.ToForward() * MELEETARGET_DISTANCE);
	gameLocal.clip.TracePoint(targetTr, startTr, endTr, cm, this);

	if (targetTr.fraction >= 1 || !gameLocal.entities[targetTr.c.entityNum]->IsType(idAI::Type))
	{
		ClearMeleeTarget();
		return;
	}

	//if (gameLocal.entities[targetTr.c.entityNum]->health <= 0 || static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->team != TEAM_ENEMY) //debug for testing jockey system
	if (gameLocal.entities[targetTr.c.entityNum]->health <= 0 || static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->team != TEAM_ENEMY 
		|| static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->aiState != AISTATE_STUNNED)
	{
		ClearMeleeTarget();
		return;
	}



	//found target.
	//attackPos = static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->GetEyePosition() + idVec3(0,0,-32);
	//itemScreenpos = GetWorldToScreen(attackPos);

	//do dotproduct stuff to see if we're looking at back.
	//idVec3 enemyPos = idVec3(gameLocal.entities[targetTr.c.entityNum]->GetPhysics()->GetOrigin().x, gameLocal.entities[targetTr.c.entityNum]->GetPhysics()->GetOrigin().y, this->GetPhysics()->GetOrigin().z);
	//idVec3 dirToPlayer = enemyPos - this->GetPhysics()->GetOrigin();
	//dirToPlayer.Normalize();
	//idVec3 enemyDir = static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->viewAxis.ToAngles().ToForward();
	//float facingResult = DotProduct(dirToPlayer, enemyDir);
	//
	////facingresult -1 = player is right in front of ai. +1 = player behind the ai.
	//if (facingResult >= -.4f)
	//{
	//	meleeTarget = static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum]);
	//	static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->IsBeingMeleeTargeted();
	//	return;
	//}
	//else
	//{
	//	meleeTarget = NULL;
	//	return;
	//}

	meleeTarget = static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum]);
	gameLocal.entities[targetTr.c.entityNum]->SetPostFlag(POST_OUTLINE_ENEMY, true);
	//static_cast<idAI *>(gameLocal.entities[targetTr.c.entityNum])->IsBeingMeleeTargeted();
}

#define LONGBUTTON_WIDTH 30
#define SHORTBUTTON_WIDTH 16
#define KEYBUTTON_HEIGHT 20

void idPlayer::DrawMeleeCursor(void)
{
	if (!meleeTarget.IsValid() || jockeyState == JCK_ATTACHED)
	{
		hud->SetStateBool("showtakedownprompt", false);
		return;
	}

	idVec2 spriteScreenPos;
	idStr frobkey;
	//bool longButton = false;
	jointHandle_t meleeJoint;
	idVec3 meleePos;
	idMat3 meleeAxis;

	meleeJoint = static_cast<idAI *>(meleeTarget.GetEntity())->GetAnimator()->GetJointHandle("neck");
	if (!static_cast<idAI *>(meleeTarget.GetEntity())->GetJointWorldTransform(meleeJoint, gameLocal.time, meleePos, meleeAxis))
		return;

	spriteScreenPos = GetWorldToScreen(meleePos);

	int promptXpos = spriteScreenPos.x + 35;
	promptXpos = Min(promptXpos, 640 - 200); //give a margin for the right side of screen so that text doesnt disappear off screen edge

	hud->SetStateFloat("takedownbutton_x", promptXpos); //offset a bit so it doesn't block enemy's silhouette
	hud->SetStateFloat("takedownbutton_y", spriteScreenPos.y);
	hud->SetStateBool("showtakedownprompt", true);


	
	hud->SetStateBool("unjockeyable", meleeTarget.GetEntity()->spawnArgs.GetBool("jockeyable", "1") == 0);



	


	//frobkey = gameLocal.GetKeyFromBinding("_bash");
	//
	//renderSystem->DrawStretchPic(
	//	spriteScreenPos.x - (SHORTBUTTON_WIDTH / 2),
	//	spriteScreenPos.y,
	//	SHORTBUTTON_WIDTH,
	//	KEYBUTTON_HEIGHT,
	//	0, 0, 1, 1,
	//	longButton ? declManager->FindMaterial("guis/assets/buttonprompt") : declManager->FindMaterial("guis/assets/buttonprompt2"));
	//
	//renderSystem->DrawSmallStringExt(spriteScreenPos.x - ((frobkey.Length() * SMALLCHAR_WIDTH) / 2.0f), spriteScreenPos.y + 3, frobkey, idVec4(0, 0, 0, 1), true, declManager->FindMaterial("textures/bigchars"));
	//
	//renderSystem->DrawSmallStringExt(spriteScreenPos.x + (SHORTBUTTON_WIDTH / 2), spriteScreenPos.y + 3, "TAKEDOWN", idVec4(1, 1, 1, 1), true, declManager->FindMaterial("textures/bigchars"));


	/*
	if (frobkey.Length() > 1)
		longButton = true;

	lerp = static_cast<idAI *>(meleeTarget.GetEntity())->meleeAttackCharge / (float)MELEE_MAXCHARGE;	

	//Chargeup sprite.
	if (lerp < 1.0f)
	{
		renderSystem->DrawStretchPic(
			spriteScreenPos.x - (longButton ? ((LONGBUTTON_WIDTH + 4) / 2) : ((SHORTBUTTON_WIDTH + 4) / 2)),
			spriteScreenPos.y - 4,
			(longButton ? LONGBUTTON_WIDTH : SHORTBUTTON_WIDTH) + 4,
			(KEYBUTTON_HEIGHT + 8),
			0, 0, 1, 1,
			declManager->FindMaterial("melee_charge_black"));
	}

	renderSystem->DrawStretchPic(
		spriteScreenPos.x - (longButton ? ((LONGBUTTON_WIDTH+4) / 2) : ((SHORTBUTTON_WIDTH+4) / 2)),
		spriteScreenPos.y - 4 + ((KEYBUTTON_HEIGHT + 8) * (1.0f - lerp)),
		(longButton ? LONGBUTTON_WIDTH : SHORTBUTTON_WIDTH) + 4 ,
		(KEYBUTTON_HEIGHT + 8) * lerp,
		0, 0, 1, 1,
		(lerp >= 1.0f) ? declManager->FindMaterial("melee_active_fg") : declManager->FindMaterial("melee_charge_fg"));	


	//The prompt.
	renderSystem->DrawStretchPic(
		spriteScreenPos.x - (longButton ? (LONGBUTTON_WIDTH/2) : (SHORTBUTTON_WIDTH/2)),
		spriteScreenPos.y,
		longButton ? LONGBUTTON_WIDTH : SHORTBUTTON_WIDTH,
		KEYBUTTON_HEIGHT,
		0, 0, 1, 1,
		longButton ? declManager->FindMaterial("guis/assets/buttonprompt") : declManager->FindMaterial("guis/assets/buttonprompt2"));
	
	renderSystem->DrawSmallStringExt(spriteScreenPos.x - ((frobkey.Length() * SMALLCHAR_WIDTH) / 2.0f), spriteScreenPos.y + 3, frobkey, idVec4(0, 0, 0, 1), true, declManager->FindMaterial("textures/bigchars"));


	if (lerp >= 1.0f)
	{
		int displaynameLength = 7;
		renderSystem->DrawStretchPic(spriteScreenPos.x - 4 + (LONGBUTTON_WIDTH / 2), spriteScreenPos.y,
			(displaynameLength * SMALLCHAR_WIDTH) + 8, SMALLCHAR_HEIGHT+4,
			0, 0, 1, 1, declManager->FindMaterial("melee_redbox"));
	}

	if (lerp < 1.0f)
		renderSystem->DrawSmallStringExt(spriteScreenPos.x + (LONGBUTTON_WIDTH / 2) + 1, spriteScreenPos.y + 3 + 1,(lerp >= 1.0f) ? "STUN" : "", idVec4(0, 0, 0, 1), true, declManager->FindMaterial("textures/bigchars"));

	renderSystem->DrawSmallStringExt(spriteScreenPos.x  + (LONGBUTTON_WIDTH/2), spriteScreenPos.y + 3, (lerp >= 1.0f) ? "STUN" : "", idVec4(1, 1, 1, 1), true, declManager->FindMaterial("textures/bigchars"));	
	*/
}

//This determines what is currently highlighted as the frobbable object.
void idPlayer::UpdateFrobCursor(void)
{
	idVec3 startTr, endTr;
	trace_t frobTr;
	idEntity *ent;
	int cm;
	idStr frobName;
	idVec3 initialTraceEnd;
	bool foundSomething = false;
	bool eyeballInsideFrobbable = false;

	//if (contextMenuActive || bodyDragger.isDragging || carryableItem.IsValid() || peekObject.IsValid())
	if (iteminspectActive || contextMenuActive || peekObject.IsValid() || armstatsActive || !playerCanFrob || zoommodeActive || (grenadeThrowState != GRENADETHROW_IDLE) || meleeTarget.IsValid() || zoominspect_LabelmodeActive || mechTransitionState == MECHTRANSITION_PILOTING)
	{
		DeselectFrobItem();
		return;
	}

	//If inspecting weapon, then don't allow frobbing.
	if (weapon.IsValid())
	{
		if (weapon.GetEntity()->IsInspectingChamber() || weapon.GetEntity()->IsInspectingMagazine())
		{
			DeselectFrobItem();
			return;
		}
	}


	cm = CONTENTS_SOLID | CONTENTS_OPAQUE | CONTENTS_BODY | CONTENTS_CORPSE | CONTENTS_RENDERMODEL;

	startTr = GetEyePosition();
	endTr = startTr + (viewAngles.ToForward() * FROB_DISTANCE);

	gameLocal.clip.TracePoint(frobTr, startTr, endTr, cm, this);
	initialTraceEnd = frobTr.endpos;

	//Do a straight tracepoint
	if (frobTr.fraction < 1 && !gameLocal.entities[frobTr.c.entityNum]->IsType(idWorldspawn::Type))
	{
		//Trace hit an object.
		if (gameLocal.entities[frobTr.c.entityNum]->isFrobbable && !gameLocal.entities[frobTr.c.entityNum]->IsHidden() && IsItemValidFrobbable(gameLocal.entities[frobTr.c.entityNum]))
		{
			//Check if object has custom frob range.
			foundSomething = true;
		}
	}


	//Do a radius check at the trace endposition.	Does a radius check at the end of the tracepoint.
	if (!foundSomething)
	{		
		idEntity		*entityList[MAX_GENTITIES];
		int				nodeList, i;
		int				closestDistance = 9999;
		int				closestIndex = -1;

		#define FROB_RADIUS_CHECKDISTANCE 8
		nodeList = gameLocal.EntitiesWithinRadius(initialTraceEnd, FROB_RADIUS_CHECKDISTANCE, entityList, MAX_GENTITIES);

		for (i = 0; i < nodeList; i++)
		{
			idEntity		*curEnt = entityList[i];
			float			curDist;
			idVec2			itemScreenpos;

			if (!curEnt)
				continue;

			if (!IsItemValidFrobbable(curEnt))
				continue;

			if (carryableItem.IsValid()) //Do not select item that is currently being carried.
			{
				if (carryableItem.GetEntity()->entityNumber == curEnt->entityNumber)
				{
					continue;
				}
			}

			if (!curEnt->isFrobbable || curEnt->IsHidden() || curEnt->IsType(idWorldspawn::Type))
				continue;

			if (curEnt->spawnArgs.GetBool("frob_only_front", "0"))
			{
				//this ent can only be frobbed from the front (i.e. VentPeek). Do a check.
				idVec3 entForwardDir;
				curEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(&entForwardDir, NULL, NULL);
				idVec3 toPlayer = curEnt->GetPhysics()->GetOrigin() - gameLocal.GetLocalPlayer()->GetEyePosition();
				float facingResult = DotProduct(toPlayer, entForwardDir);

				if (facingResult >= 0)
					continue; //player is facing the back of the ent. Skip....
			}

			//Do a distance check. The distance check is based on SCREENSPACE, not 3D space.
			itemScreenpos = GetWorldToScreen(curEnt->GetPhysics()->GetOrigin());
			curDist = (itemScreenpos - idVec2(320, 240)).Length();

			if (curDist > closestDistance)
				continue;

			//Do a traceline check. To make sure the object isn't behind geometry.
			idVec3 entForward;
			trace_t tr;
			curEnt->GetPhysics()->GetAxis().ToAngles().ToVectors(&entForward, NULL, NULL); //we extrude forward a bit just in case the object is placed directly on a wall.
			gameLocal.clip.TracePoint(tr, GetEyePosition(), curEnt->GetPhysics()->GetOrigin() + (entForward * .3f), MASK_SOLID, curEnt);
			if (tr.fraction < 1.0f)
			{
				//failed. try again. This time, move the origin point slightly up, just in case the item is on the ground.
				gameLocal.clip.TracePoint(tr, GetEyePosition(), curEnt->GetPhysics()->GetOrigin() + idVec3(0,0,.5f), MASK_SOLID, curEnt);

				if (tr.fraction < 1.0f)
				{
					continue;
				}
			}
			
			closestIndex = curEnt->entityNumber;
			closestDistance = curDist;			
		}

		if (closestIndex >= 0)
		{
			foundSomething = true;
			frobTr.c.entityNum = closestIndex;
		}
	}

	//Is the player INSIDE the bounding box of a frobbable? i.e. for zipcord.
	const float FROB_VIEW_MAX_ANGLE = 0.349066f;
	if (!foundSomething)
	{		
		idEntity		*entityList[MAX_GENTITIES];
		int				nodeList, i;

		nodeList = gameLocal.EntitiesWithinRadius(GetEyePosition(), 8, entityList, MAX_GENTITIES);

		for (i = 0; i < nodeList; i++)
		{
			idEntity		*curEnt = entityList[i];
			idVec2			itemScreenpos;

			if (!curEnt)
				continue;

			if (carryableItem.IsValid()) //Do not select item that is currently being carried.
			{
				if (carryableItem.GetEntity()->entityNumber == curEnt->entityNumber)
				{
					continue;
				}
			}

			if (!curEnt->isFrobbable || curEnt->IsHidden() || curEnt->IsType(idWorldspawn::Type))
				continue;
			
			float vdot;
			idVec3 entPos = idVec3(curEnt->GetPhysics()->GetOrigin().x, curEnt->GetPhysics()->GetOrigin().y, 0);
			idVec3 eyePos = idVec3(firstPersonViewOrigin.x, firstPersonViewOrigin.y, 0);
			idVec3 dirToEnt = entPos - eyePos;
			dirToEnt.Normalize();

			vdot = DotProduct(dirToEnt, firstPersonViewAxis.ToAngles().ToForward());

			if (idMath::ACos(vdot) < FROB_VIEW_MAX_ANGLE)
			{
				foundSomething = true;
				frobTr.c.entityNum = curEnt->entityNumber;
				eyeballInsideFrobbable = true;
			}			
		}
	}

	if (!foundSomething)
	{
		//special case for acro points. We extend the trace longer.
		startTr = GetEyePosition();
		endTr = startTr + (viewAngles.ToForward() * FROB_DISTANCE_ACROPOINT);

		gameLocal.clip.TracePoint(frobTr, startTr, endTr, cm, this);
		initialTraceEnd = frobTr.endpos;

		if (frobTr.fraction < 1 && gameLocal.entities[frobTr.c.entityNum]->IsType(idAcroPoint::Type))
		{
			foundSomething = true;
		}
	}


	if (!foundSomething && airless)
	{
		//Special frob check for outer space.

		idBounds frobBounds;
		frobBounds = idBounds(idVec3(-FROB_TRACESIZE_AIRLESS, -FROB_TRACESIZE_AIRLESS, -FROB_TRACESIZE_AIRLESS), idVec3(FROB_TRACESIZE_AIRLESS, FROB_TRACESIZE_AIRLESS, FROB_TRACESIZE_AIRLESS));
		
		gameLocal.clip.TraceBounds(frobTr, startTr, endTr, frobBounds, cm, this);
		
		if (frobTr.fraction < 1 && !gameLocal.entities[frobTr.c.entityNum]->IsType(idWorldspawn::Type) && gameLocal.entities[frobTr.c.entityNum]->isFrobbable && !gameLocal.entities[frobTr.c.entityNum]->IsHidden())
		{
			//Trace hit something.
			foundSomething = true;
		}
	}


	if (!foundSomething)
	{
		//Trace hit nothing.	
		//do a broader check.
		//Try trace again, this time with a bounding box.		
		idBounds frobBounds = idBounds(idVec3(-FROB_TRACESIZE, -FROB_TRACESIZE, -FROB_TRACESIZE), idVec3(FROB_TRACESIZE, FROB_TRACESIZE, FROB_TRACESIZE));
		gameLocal.clip.TraceBounds(frobTr, startTr, endTr, frobBounds, cm, this);

		if (frobTr.fraction >= 1 || gameLocal.entities[frobTr.c.entityNum]->IsType(idWorldspawn::Type)
			|| !gameLocal.entities[frobTr.c.entityNum]->isFrobbable || gameLocal.entities[frobTr.c.entityNum]->IsHidden())
		{
			//fail.
		}
		else
		{
			//Trace hit something.

			//4/17/2023 frob - todo: need to find a better fix for this. ideally, the held item should not be frobbable...
			if (carryableItem.IsValid()) //if player is carrying the item , ignore it.
			{
				//Player is carrying an item. Make sure we're ignoring it.
				if (carryableItem.GetEntityNum() != frobTr.c.entityNum)
				{
					foundSomething = true;
				}
			}
			else
			{
				//No carryable. 
				foundSomething = true;
			}
		}
	}



	//special memory palace frob logic.
	if (memorypalaceState == MEMP_ACTIVE && !foundSomething)
	{
		idEntity *memoryEnt = UpdateMemoryPalaceFrobCursor();
		if (memoryEnt != NULL)
		{
			frobTr.c.entityNum = memoryEnt->entityNumber;
			foundSomething = true;
		}
	}

	if (!foundSomething)
	{
		//Get all items within range of player, and do a check to see if it's within valid parameters.
		//This is largely for the use case where an objects is near a ledge, and the player is looking just past over the ledge.

		int nodeList;
		idEntity* entityList[MAX_GENTITIES];
		nodeList = gameLocal.EntitiesWithinRadius(firstPersonViewOrigin, FROB_DISTANCE, entityList, MAX_GENTITIES);

		float bestDotproduct = -1;
		int bestEntityIndex = -1;
		for (int i = 0; i < nodeList; i++)
		{
			idEntity* ent = entityList[i];

			if (!ent)
				continue;

			if (ent->IsHidden() || !ent->isFrobbable || !IsItemValidFrobbable(ent))
				continue;

			
			idVec3 toPlayer = ent->GetPhysics()->GetOrigin() - firstPersonViewOrigin;
			toPlayer.Normalize();
			float facingResult = DotProduct(toPlayer, viewAngles.ToForward());
			//gameRenderWorld->DrawTextA(idStr::Format("%f", facingResult), ent->GetPhysics()->GetOrigin(), 0.3f, colorGreen, viewAxis, 1, 100);

			if (facingResult > bestDotproduct && facingResult >= .99f)
			{
				//traceline check.
				trace_t tr;
				gameLocal.clip.TracePoint(tr, firstPersonViewOrigin, ent->GetPhysics()->GetOrigin(), MASK_SOLID, NULL);
				if (tr.fraction >= 1)
				{
					bestDotproduct = facingResult;
					bestEntityIndex = i;
				}
			}
		}

		if (bestEntityIndex > 0)
		{
			frobTr.c.entityNum = entityList[bestEntityIndex]->entityNumber;
			foundSomething = true;
		}
	}

	if (!foundSomething)
	{
		DeselectFrobItem();
		return;
	}	

	if (gameLocal.entities[frobTr.c.entityNum]->spawnArgs.GetBool("frobboundcheck"))
	{
		//frobboundcheck is for things like the laundry machine or cargo hide, where we want to ignore the nooks and crannies and instead treat it like a big cube.
		//Do a bounding box check.
		trace_t losTr;
		idBounds losBound = idBounds(idVec3(-5, -5, -5), idVec3(5, 5, 5));

		idStr nam = gameLocal.entities[frobTr.c.entityNum]->GetName();

		gameLocal.clip.TraceBounds(losTr, startTr, endTr, losBound, cm, this);

		if (losTr.c.entityNum != frobTr.c.entityNum)
		{
			DeselectFrobItem();
			return;
		}
	}

	ent = gameLocal.entities[frobTr.c.entityNum];
	

	if (!ent->isFrobbable || ent->IsHidden() || !IsItemValidFrobbable(ent))
	{
		//Is NOT frobbable. This thing cannot be frobbed. Exit.
		DeselectFrobItem();
		return;
	}

	//check if the entity can only be frobbed from the front.
	if (ent->spawnArgs.GetBool("frob_only_front", "0"))
	{
		//this ent can only be frobbed from the front (i.e. VentPeek). Do a check.
		idVec3 entForwardDir;
		ent->GetPhysics()->GetAxis().ToAngles().ToVectors(&entForwardDir, NULL, NULL);
		idVec3 toPlayer = ent->GetPhysics()->GetOrigin() - gameLocal.GetLocalPlayer()->GetEyePosition();
		float facingResult = DotProduct(toPlayer, entForwardDir);

		if (facingResult >= 0)
		{
			DeselectFrobItem();
			return;
		}
	}

	if (ent->IsType(idDoor::Type))
	{
		if (!ent->IsAtRest())
		{
			DeselectFrobItem();
			return;
		}
	}

	// SW: If we're in an acropoint or hiding place, don't let the player pick up moveable items (chairs, gas canisters, etc)
	if (lastAcroState != ACROTYPE_NONE && ent->IsType(idMoveableItem::Type))
	{
		DeselectFrobItem();
		return;
	}

	//for ventdoors, we want their frob distance to be shorter on the Exit side.
	int specialFrobDistance = gameLocal.entities[frobTr.c.entityNum]->spawnArgs.GetInt("frobdistance", "0");
	if (specialFrobDistance > 0)
	{
		if (gameLocal.entities[frobTr.c.entityNum]->IsType(idVentdoor::Type))
		{
			idVec3 machineUpDir;
			idVec3 frontOfMachinePos;
			idVec3 toPlayer;
			float facingResult;

			gameLocal.entities[frobTr.c.entityNum]->GetPhysics()->GetAxis().ToAngles().ToVectors(&machineUpDir, NULL, NULL);
			frontOfMachinePos = gameLocal.entities[frobTr.c.entityNum]->GetPhysics()->GetOrigin();
			toPlayer = frontOfMachinePos - GetEyePosition();
			facingResult = DotProduct(toPlayer, machineUpDir);

			machineUpDir.FixDegenerateNormal();

			//Only do this custom frob distance when player is facing the EXIT side of the ventdoor.
			if (facingResult < 0 && machineUpDir != idVec3(0, 0, -1) || !gameLocal.entities[frobTr.c.entityNum]->spawnArgs.GetBool("zipdoor", "1"))
			{
				//we are on the EXIT side of the ventdoor.
				//float dist = (frobTr.endpos - idVec3(this->GetPhysics()->GetOrigin().x, this->GetPhysics()->GetOrigin().y, frobTr.endpos.z)).LengthFast();

				//use scalar projection to get a distance that is not dependent on view angle
				toPlayer.Normalize();
				idVec3 playerToTrace = frobTr.endpos - GetEyePosition();
				float dist = idMath::Abs( DotProduct( machineUpDir, playerToTrace ) );

				if (dist > specialFrobDistance)
				{
					//Too far.
					DeselectFrobItem();
					return;
				}


				//check whether player wants to ZIP or PEEK through the ventdoor. We do this by checking if player is looking at the "bottom" of the door. Because I unfortunately made the ventdoor with a funky orientation, we need to do some funky stuff...
				//idVec3 doorForwarddir;
				//gameLocal.entities[frobTr.c.entityNum]->GetPhysics()->GetAxis().ToAngles().ToVectors(&doorForwarddir, NULL, NULL);
				//
				//idBounds doorBounds = gameLocal.entities[frobTr.c.entityNum]->GetPhysics()->GetBounds();
				//idVec3 peekSpot = gameLocal.entities[frobTr.c.entityNum]->GetPhysics()->GetOrigin() + doorForwarddir * doorBounds[0].x;
				//
				////Now have a spot for peeking under the ventdoor. Check to see if player is aiming at this spot.
				//float distToPeekSpot = (frobTr.endpos - peekSpot).LengthFast();
				//
				//if (distToPeekSpot < 4)
				//{
				//	//player is aiming at the peek spot.
				//}
			}
		}
		else
		{
			//Do specialfrobdistance check for non-vent entities. Example: landmine.
			//float dist = (frobTr.endpos - idVec3(this->GetPhysics()->GetOrigin().x, this->GetPhysics()->GetOrigin().y, frobTr.endpos.z)).LengthFast();
			float dist = (ent->GetPhysics()->GetOrigin() - idVec3(this->GetPhysics()->GetOrigin().x, this->GetPhysics()->GetOrigin().y, ent->GetPhysics()->GetOrigin().z)).LengthFast();
			if (dist > specialFrobDistance)
			{
				DeselectFrobItem();
				return;
			}
		}
	}
	

	if (!eyeballInsideFrobbable)
		frobHitpos = frobTr.endpos;
	else
	{
		//When player is inside a frobbable, make cursor appear in front of player eyes.
		frobHitpos = firstPersonViewOrigin + firstPersonViewAxis.ToAngles().ToForward() * 16;
	}

	// Don't draw the cursor for entities with guis, as we only want the on-screen cursor
	// the exception to this is the fullscreenzoom entity (for the email computer)
	bool isGui = false;
	if (ent->GetRenderEntity()->gui[0] && !ent->spawnArgs.GetBool("fullscreenzoom"))
	{
		if (ent->GetRenderEntity()->gui[0]->IsInteractive())
		{
			cursor->SetStateInt("frobcursor", 0);
			isGui = true;
		}
	}
	
	if (!isGui)
	{
		cursor->SetStateInt("frobcursor", 1);  //finger icon.
	}

	
	
	if (frobState != FROBSTATE_HOLDING)
	{
		if (frobState != FROBSTATE_HOVERCURSOR)
		{
			frobFlashTimer = gameLocal.hudTime + FROB_FLASHTIME;
		}

		if (frobEnt != NULL)
		{
			if (frobEnt->entityNumber != lastFrobNumber)
			{
				lastFrobNumber = frobEnt->entityNumber;
				frobFlashTimer = gameLocal.hudTime + FROB_FLASHTIME;
			}
		}

		frobState = FROBSTATE_HOVERCURSOR;
		SetFrobEnt(ent);
	}





	//idVec3 viewAng = viewAngles.ToForward();
	//viewAng.x *= -1.0f;
	//gameRenderWorld->DebugCircle(colorWhite, frobEnt->GetPhysics()->GetOrigin(), viewAng, 2, 9);

	


	

	

	//gameRenderWorld->DebugLine(colorWhite, GetEyePosition() + ( viewAngles.ToForward() * 4 ), frobEnt->GetPhysics()->GetOrigin());	

}

//Depending on the context, we sometimes want to filter out specific objects for frobbability.
//Example: during memory palace, we only want notes to be frobbable.
bool idPlayer::IsItemValidFrobbable(idEntity* ent)
{
	if (ent == NULL)
		return false;

	if (memorypalaceState == MEMP_NONE)
	{
		//in normal gameplay.

		//Check if it's a pickpocket item. If so, ensure player has to be BEHIND the enemy.
		idAI* frobMaster = ent && ent->GetBindMaster() && ent->GetBindMaster()->IsType(idAI::Type) ? static_cast<idAI*>(ent->GetBindMaster()) : nullptr;
		if (frobMaster && ent->spawnArgs.GetBool("pickpocketable", "1"))
		{
			#if 1 // this disables pickpocket item being interacted/highlighted if npc is stunned
			if (frobMaster->aiState == AISTATE_STUNNED)
				return false;
			#endif

			idAngles enemyAngle = idAngles(0, static_cast<idAI*>(ent->GetBindMaster())->viewAxis.ToAngles().yaw, 0);
			idAngles playerAngle = idAngles(0, viewAngles.yaw, 0);

			float vdot = DotProduct(enemyAngle.ToForward(), playerAngle.ToForward());

			if (vdot > 0)
				return true;
			else
				return false;
		}

		return true;
	}
	else
	{
		//in memory palace.

		if (!ent->IsType(idNoteWall::Type))
			return false;

		if (!static_cast<idNoteWall*>(ent)->IsMemorypalaceClone())
			return false;
	}

	return true;
}

//We do a special frob for the memory palace, because the note may technically be inside a wall
idEntity* idPlayer::UpdateMemoryPalaceFrobCursor()
{
	#define DOTTHRESHOLD .98f

	float bestDotProduct = -999;
	idEntity* bestNote = NULL;

	for (idEntity* ent = gameLocal.memorypalaceEntities.Next(); ent != NULL; ent = ent->memorypalaceNode.Next())
	{
		if (!ent)
			continue;

		if (!ent->IsType(idNoteWall::Type))
			continue;

		if (!static_cast<idNoteWall*>(ent)->IsMemorypalaceClone())
			continue;

		//see if player is looking at note.
		idVec3 vecToNote = ent->GetPhysics()->GetOrigin() - firstPersonViewOrigin;
		vecToNote.Normalize();

		float vdot = DotProduct(vecToNote, viewAngles.ToForward());
		if (vdot > bestDotProduct)
		{
			bestDotProduct = vdot;
			bestNote = ent;
		}
	}

	return bestNote;
}

void idPlayer::DeselectFrobItem(void)
{
	SetFrobEnt(NULL);
	frobState = FROBSTATE_NONE;
	cursor->SetStateInt("frobcursor", 0);
}

//Updaet logic of pressing frob button.
void idPlayer::UpdateFrob(void)
{
	if (armstatsActive && (usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB))
	{
		//if map is up, frob will lower the map.
		SetArmStatsActive(false);
		return;
	}

	if (bodyDragger.isDragging && (usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB) && !contextMenuActive && frobEnt == NULL)
	{
		//If frob while holding body, then drop the body.
		bodyDragger.StopDrag(false);
		return;
	}

	if (peekObject.IsValid() && (usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB))
	{
		if (peekObject.GetEntity()->IsType(idVentpeek::Type))
		{
			idVentpeek* ventpeek = static_cast<idVentpeek*>(peekObject.GetEntity());
			if (ventpeek->peekEnt.IsValid())
			{
				// SW: We can lock players into ventpeeks for the purposes of vignettes
				if (ventpeek->CanFrobExit())
				{
					//Handle the case where the frob keypress to exit inspectzoom will inadvertently also kick player out of ventpeek.
					//if we just exited an inspect zoom, then stay in vent peek mode.
					if (gameLocal.hudTime > zoominspect_lerptimer + 300)
					{
						ventpeek->StopPeek();
						return;
					}
				}
			}
		}
	}


	//if (carryableItem.IsValid() && (usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB) && !contextMenuActive && frobEnt == NULL)
	//{
	//	//Drop the carryableitem.
	//	DropCurrentCarryable(true);		
	//	return;
	//}
	
	if (meleeTarget.IsValid() && !inDownedState && (usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB))
	{
		if (meleeTarget.GetEntity()->IsType(idAI::Type))
		{			
			SetJockeyMode(true);			
		}
		return;
	}

	if (spectating)
		return;

	if (jockeyState == JCK_ATTACHED)
		return;

	if (zoominspect_LabelmodeActive)
		return;

	if (frobState == FROBSTATE_NONE && mechTransitionState == MECHTRANSITION_NONE)
		return;	

	if ((usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB))
	{
		//player frobbing a thing.	
		
		if (mechTransitionState == MECHTRANSITION_NONE)
		{
			
			//Normal frob of frob object.
			if (frobEnt && !frobEnt->IsFrobHoldable())
			{
				bool doPickpocket = false;
				idAI * frobMaster = frobEnt->GetBindMaster() && frobEnt->GetBindMaster()->IsType(idAI::Type) ? static_cast<idAI*>(frobEnt->GetBindMaster()) : static_cast<idAI*>(nullptr);
				if (frobMaster && frobEnt->spawnArgs.GetBool("pickpocketable", "1"))
				{
					//Start the pickpocket sequence.

					//Check if player is frobbing entity that they're already currently pickpocketing.
					bool startNewPickpocket = true;
					if (frobMaster->aiState == AISTATE_STUNNED) // break pickpocket if npc is stunned
					{
						startNewPickpocket = false;
					}
					else if (pickpocketEnt.IsValid())
					{
						if (pickpocketEnt.GetEntityNum() == frobEnt->entityNumber && pickpocketState != PP_NONE)
						{
							startNewPickpocket = false;								
						}
					}

					if (startNewPickpocket)
					{
						//Start pickpocketing!!!

						idAI *aiEnt = static_cast<idAI *>(frobEnt->GetBindMaster());
						bool acceptsStimulus = aiEnt->CanAcceptStimulus(); 

						pickpocketPipCount = 0;
						pickpocketPipTimer = 0;
						pickpocketGoodRange = true;
						lastPickpocketGoodRange = true;
							
						pickpocketState = PP_PICKING;
						pickpocketEnt = frobEnt;

						//Start sound effect.
						pickpocketEnt.GetEntity()->StartSoundShader(declManager->FindSound(acceptsStimulus ? "pickpocket_7s" : "pickpocket_1s"), SND_CHANNEL_PDA, 0, false, NULL);							

						statsPickpocketAttempts++;
					}
						
					doPickpocket = true;
				}

				if (!doPickpocket)
				{
					//Frob something in the world. This is the default frob when player frobs something.
					frobEnt->DoFrob(0, this); 
				}
			}
			else
			{
				// If it's frob-holdable, we have to time the duration of the hold
				frobState = FROBSTATE_HOLDING;
				frobHoldTimer = gameLocal.time + FROB_HOLD_TIME;
			}
		}
		else if (mountedMech.GetEntity() != NULL && !mechStartupstate)
		{
			//Player frobbed while inside mech. Player wants to exit mech.
			ExitMech(false);
		}
		

		/*
		if (frobEnt->IsType(idItem::Type))
		{
			//Frob an idItem.
			((idItem *)frobEnt)->Pickup(this);
		}*/		
	}
	else if ( frobState == FROBSTATE_HOLDING )
	{
		// Did we hold for long enough?
		if ( gameLocal.time >= frobHoldTimer )
		{
			frobHoldTimer = -1.0f;
			frobEnt->DoFrobHold( 0, this ); //Frob Hold interaction.
			frobState = FROBSTATE_NONE;
		}
		// Did we release?
		else if ( !( usercmd.buttons & BUTTON_FROB ) )
		{
			frobHoldTimer = -1.0f;
			frobEnt->DoFrob( 0, this ); //Frob held item.
			frobState = FROBSTATE_NONE;
		}
	}
}



void idPlayer::ExitMech(bool flashWhite)
{
	if (mountedMech.GetEntity() == NULL)
		return;

	//Exit the mech.
	int i;
	trace_t mechTr;
	idVec3 rightDir;
	idBounds playerBounds = GetPhysics()->GetClipModel()->GetBounds();
	idVec3 mechPos = mountedMech.GetEntity()->GetPhysics()->GetOrigin();
	idVec3 mechDir = idAngles(0, mountedMech.GetEntity()->viewAxis.ToAngles().yaw, 0).ToForward();
	bool mechexitSuccess = false;
	viewAngles.ToVectors(NULL, &rightDir, NULL);

	//Check a bunch of spots near the mech. Make the "nicer looking" spots early so they have priority, and put the "less-nice" spots at bottom so they have least priority.
	#define CANDIDATESPOTS_AMOUNT 17
	idVec3 candidateSpots[] =
	{
		mechPos + (mechDir * -64), //behind
		mechPos + (mechDir * 64), //forward
		mechPos + (rightDir * -64), //left
		mechPos + (rightDir * 64), //right		

		mechPos + (mechDir * 64) + (rightDir * -64), //forward-left
		mechPos + (mechDir * 64) + (rightDir * 64), //forward-right
		mechPos + (mechDir * -64) +(rightDir * -64), //rear-left
		mechPos + (mechDir * -64) +(rightDir * 64), //rear-right

		mechPos + idVec3(0,0,130), //above

		mechPos + (mechDir * -96), //behind
		mechPos + (mechDir * 96), //forward
		mechPos + (rightDir * -96), //left
		mechPos + (rightDir * 96), //right

		mechPos + (mechDir * -128), //behind
		mechPos + (mechDir * 128), //forward
		mechPos + (rightDir * -128), //left
		mechPos + (rightDir * 128), //right
	};


	for (i = 0; i < CANDIDATESPOTS_AMOUNT; i++)
	{
		gameLocal.clip.TraceBounds(mechTr, candidateSpots[i], candidateSpots[i], playerBounds, MASK_SOLID, this);

		if (mechTr.fraction >= 1)
		{
			//area is clear!!! Exit the mech
			mechTransitionState = MECHTRANSITION_NONE;
			((idMech *)mountedMech.GetEntity())->Dismount();
			SetOrigin(candidateSpots[i]);
			mechexitSuccess = true;

			if (flashWhite)
				playerView.Fade(idVec4(255, 255, 255, 0.0f), 500);
			else
				playerView.Fade(idVec4(0, 0, 0, 0.0f), 300);

			Show();
			hiddenWeapon = false;
			for ( int i = 0; i < MAX_HOTBARSLOTS; i++ )
			{
				hud->SetStateBool( va( "hotbarvisible%d", i ), ( i <= inventory.hotbarUnlockedSlots - 1 ) ? true : false ); //Set hotbar visibility.
			}

			hud->HandleNamedEvent("onExitMech");


			//REMOVE THE MECHCANNON FROM PLAYER INVENTORY.
// 			int newweap = currentWeaponSlot;
// 			if (newweap == -1)
// 			{
// 				return;
// 			}
// 			else
// 			{
// 				//Remove the mech cannon.
// 				inventory.Drop( currentWeaponSlot );
// 				weapon.GetEntity()->ResetAmmoClip();
// 				Event_SelectWeapon("weapon_unarmed"); //BC go to unarmed.
// 				weapon.GetEntity()->WeaponStolen();
// 				weaponGone = true;
// 			}

			break;
		}
	}

	if (!mechexitSuccess)
	{
		hud->HandleNamedEvent("mech_noexit");
	}
	else
	{
		//Successful exit of mech.
		mechCockpit->Hide();
		SetClipModel(); //Resize the collisionbox to be human-sized instead of mech-sized.
	}
}

// =================================== END BC ===================================



/*
==============
idPlayer::PerformImpulse
==============
*/
void idPlayer::PerformImpulse( int impulse ) {

	if ( gameLocal.isClient )
	{
		idBitMsg	msg;
		byte		msgBuf[MAX_EVENT_PARAM_SIZE];

		assert( entityNumber == gameLocal.localClientNum );
		msg.Init( msgBuf, sizeof( msgBuf ) );
		msg.BeginWriting();
		msg.WriteBits( impulse, 6 );
		ClientSendEvent( EVENT_IMPULSE, &msg );
	}

	//Impulse 0 - 12 are weapon selection.
	if ( impulse >= IMPULSE_0 && impulse <= IMPULSE_12 )
	{
		//BC
		//SelectWeapon( impulse, false );

		SelectHotbarslot(impulse);

		return;
	}

	switch( impulse )
	{
		
		case IMPULSE_13:
		{
			//debug.
			SetFallState(true, true);			
			break;
		}

		//Next weapon. Mwheeldown.
		case IMPULSE_14:
		{
			NextWeapon();
			break;
		}

		//Prev weapon. Mwheelup.
		case IMPULSE_15:
		{
			PrevWeapon();
			break;
		}

		//BC Throw currently-held item.
		case IMPULSE_16:
		{
			//ThrowCurrentWeapon();
			break;
		}

		case IMPULSE_17:
		{
			//if ( gameLocal.isClient || entityNumber == gameLocal.localClientNum ) {
			//	gameLocal.mpGame.ToggleReady();
			//}
			break;
		}

		case IMPULSE_18:
		{
			centerView.Init(gameLocal.time, 200, viewAngles.pitch, 0);
			break;
		}
		case IMPULSE_19: {
			// when we're not in single player, IMPULSE_19 is used for showScores
			// otherwise it opens the pda
			//if ( !gameLocal.isMultiplayer ) {
			//	if ( objectiveSystemOpen ) {
			//		TogglePDA();
			//	} else if ( weapon_pda >= 0 ) {
			//		SelectWeapon( currentWeaponSlot, weapon_pda, true );
			//	}
			//}

			TogglePDA();

			break;
		}

		case IMPULSE_20:
		{
			int amountLockedDown = 0;

			for (idEntity* airlockEnt = gameLocal.airlockEntities.Next(); airlockEnt != NULL; airlockEnt = airlockEnt->airlockNode.Next())
			{
				if (!airlockEnt)
					continue;

				if (!airlockEnt->IsType(idAirlock::Type))
					continue;

				if (static_cast<idAirlock *>(airlockEnt)->IsAirlockLockdownActive())
					amountLockedDown++;
			}


			bool doLockdown = amountLockedDown <= 0;
			for (idEntity* airlockEnt = gameLocal.airlockEntities.Next(); airlockEnt != NULL; airlockEnt = airlockEnt->airlockNode.Next())
			{
				if (!airlockEnt)
					continue;

				if (!airlockEnt->IsType(idAirlock::Type))
					continue;

				//if (!static_cast<idAirlock *>(airlockEnt)->IsAirlockLockdownActive())
				//	continue;
				//
				//static_cast<idAirlock *>(airlockEnt)->DoAirlockLockdown(false);

				common->Printf("airlock lockdown: impulse 20.\n");
				static_cast<idAirlock *>(airlockEnt)->DoAirlockLockdown(doLockdown);
			}

			break;
		}

		case IMPULSE_21:
		{
			//Jockey.

			if (IsJockeying())
			{
				//end current jockey.
				stamina = 0;
				break;
			}

			trace_t jockeyTr;
			gameLocal.clip.TracePoint(jockeyTr, firstPersonViewOrigin, firstPersonViewOrigin + viewAngles.ToForward() * 512, MASK_SHOT_RENDERMODEL, NULL);
			if (jockeyTr.c.entityNum <= MAX_GENTITIES - 2 && jockeyTr.c.entityNum >= 0)
			{
				if (gameLocal.entities[jockeyTr.c.entityNum]->IsType(idGunnerMonster::Type))
				{
					meleeTarget = static_cast<idAI *>(gameLocal.entities[jockeyTr.c.entityNum]);
					SetJockeyMode(true);
				}
			}

			break;
		}

		case IMPULSE_22: {
			//BC show stats on your arm.

			armstatsActive = !armstatsActive;
			SetArmStatsActive(armstatsActive);
			
			break;
		}

		case IMPULSE_23:
		{
			//debug ventpurge.
			static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->StartVentPurge();			
			break;
		}

        case IMPULSE_24:
        {
			//Fast forward the current world state.

            //do escalation debug.
			idMeta *metaEnt = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity());
            //if (!metaEnt->IsEscalationMaxed())
            //{
            //    //increase escalation level.
            //    static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->IncreaseEscalationLevel();
            //}
            //else
            //{
			//	//Fast forward FTL countdown.
            //    idFTL *ftlEnt = static_cast<idFTL *>(metaEnt->GetFTLDrive.GetEntity());
            //    if (ftlEnt)
            //    {
            //        ftlEnt->FastforwardCountdown();
			//		return;
            //    }
			//
			//	if (metaEnt->GetCombatState() == COMBATSTATE_SEARCH)
			//	{
			//		metaEnt->GotoCombatIdleState();
			//		return;
			//	}
            //}

			idFTL *ftlEnt = static_cast<idFTL *>(metaEnt->GetFTLDrive.GetEntity());
			if (ftlEnt)
			{
			    ftlEnt->FastforwardCountdown();
				return;
			}

			static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->OnEnemyStoredLifeboat();

            break;
        }

		case IMPULSE_25: {

			//debug: mission victory

			if (isInVignette)
			{
				//Vignette.
				gameLocal.RunMapScript("_OnVictory");
			}
			else
			{
				//Normal level.
				cmdSystem->BufferCommandText(CMD_EXEC_APPEND, "killmonsters\n");
				gameLocal.RunMapScript("_OnVictory");
				//static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->OnEnemyStoredLifeboat();
			}



			//static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->IncreaseEscalationLevel();

			//if ( gameLocal.isServer && gameLocal.mpGame.IsGametypeFlagBased() && (gameLocal.serverInfo.GetInt( "si_midnight" ) == 2) ) {
			//	if ( enviroSuitLight.IsValid() ) {
			//		enviroSuitLight.GetEntity()->PostEventMS( &EV_Remove, 0 );
			//		enviroSuitLight = NULL;
			//	} else {
			//		const idDict *lightDef = gameLocal.FindEntityDefDict( "envirosuit_light", false );
			//		if ( lightDef ) {
			//			idEntity *temp = static_cast<idEntity *>(enviroSuitLight.GetEntity());
			//			idAngles lightAng = firstPersonViewAxis.ToAngles();
			//			idVec3 lightOrg = firstPersonViewOrigin;
			//
			//			idVec3 enviroOffset = lightDef->GetVector( "enviro_offset" );
			//			idVec3 enviroAngleOffset = lightDef->GetVector( "enviro_angle_offset" );
			//
			//			gameLocal.SpawnEntityDef( *lightDef, &temp, false );
			//			enviroSuitLight = static_cast<idLight *>(temp);
			//
			//			enviroSuitLight.GetEntity()->fl.networkSync = true;
			//
			//			lightOrg += (enviroOffset.x * firstPersonViewAxis[0]);
			//			lightOrg += (enviroOffset.y * firstPersonViewAxis[1]);
			//			lightOrg += (enviroOffset.z * firstPersonViewAxis[2]);
			//			lightAng.pitch += enviroAngleOffset.x;
			//			lightAng.yaw += enviroAngleOffset.y;
			//			lightAng.roll += enviroAngleOffset.z;
			//
			//			enviroSuitLight.GetEntity()->GetPhysics()->SetOrigin( lightOrg );
			//			enviroSuitLight.GetEntity()->GetPhysics()->SetAxis( lightAng.ToMat3() );
			//
			//			enviroSuitLight.GetEntity()->UpdateVisuals();
			//			enviroSuitLight.GetEntity()->Present();
			//		}
			//	}
			//}
			break;
		}

		case IMPULSE_26: {
			gameLocal.sessionCommand = "died"; //BC the restart screen.
			break;
		}

#ifdef _D3XP
		//Hack so the chainsaw will work in MP
		case IMPULSE_27: {
			//SelectWeapon(currentWeaponSlot, 18, false);

			//static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->StartFTLRescueSequence();

			SetViewYawLock(false, 0, 0);
			viewPitchLocked = false;
			Event_setPlayerFrozen(0);
			Unbind();

			break;
		}
#endif

		case IMPULSE_28: {
			//if ( gameLocal.isClient || entityNumber == gameLocal.localClientNum ) {
			//	gameLocal.mpGame.CastVote( gameLocal.localClientNum, true );
			//}

			eventlogMenuActive = !eventlogMenuActive;



			break;
		}
		case IMPULSE_29: {

			gameLocal.TestEventLogFeed();
			break;
		}


		case IMPULSE_30:
		{
			DebugPrintInventory(-1);
			
			break;
		}
		case IMPULSE_31:
		{
			//Hotbar slot 1.
			//SelectHotbarslot(1);

			SetHotbarslotsUnlockDelta(1);

			break;
		}
		case IMPULSE_32:
		{
			//Hotbar slot 2.
			//SelectHotbarslot(2);

			static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->radioCheckinEnt->StartCheckin(GetEyePosition());

			break;
		}
		case IMPULSE_33:
		{
			//Hotbar slot 3.
			//SelectHotbarslot(3);

			gameLocal.RunMapScript("_SplineTest");

			break;
		}

		case IMPULSE_34:
		{
			//Hotbar slot 3.
			//SelectHotbarslot(3);

			//Debug test - test playerConnectedArea


			DebugPlayerConnectedArea();



			break;
		}

		case IMPULSE_35:
		{
			static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->SetPlayerEnterCatpod();
			break;
		}

		case IMPULSE_36:
		{			
			//levelselectMenuActive = !levelselectMenuActive;

			Event_GetLocationLocID();

			break;
		}

		case IMPULSE_37:
		{
			//gameLocal.GetLocalPlayer()->SetROQVideoState(1);
			
			Event_ResetMaterialTimer("textures/fx/video_bokeh_a");

			break;
		}


		case IMPULSE_40: {
			UseVehicle();
			break;
		}	
						 

	}
}



bool idPlayer::HandleESC( void ) {
	if ( gameLocal.inCinematic ) {
		//return SkipCinematic();
		return false;
	}

	if (emailFullscreenState == EFS_ACTIVE && !emailInSubMenu)
	{
		//Exit the email interface.

		//horrible kludge: assume we're in the hub level, grab the email monitor
		//Note: this doesn't work...
		//idEntity* ent = gameLocal.FindEntity("prop_emailmonitor"); //bc ugh this is a kludge.......
		//if (ent)
		//{
		//	ent->Event_GuiNamedEvent(1, "resetEmail");
		//}

		SetEmailFullscreen(false);
		escapedFullScreenMenu = true;
		return true;
	}

	if (levelselectMenuActive)
	{
		LevelselectMenuOpen(0);
		escapedFullScreenMenu = true;
		return true;
	}

	if (eventlogMenuActive)
	{
		EventlogMenuOpen(false);
		return true;
	}

	if (contextMenuActive)
	{
		//Exit contextmenu if press esc.
		ContextmenuConfirm(false);
		escapedFullScreenMenu = true;
		return true;
	}	

	if ( objectiveSystemOpen ) {
		TogglePDA();
		return true;
	}

	if (zoominspect_LabelmodeActive)
	{
		ExitLabelinspectMode();
		return true;
	}

	if (iteminspectActive)
	{
		ExitIteminspectMode();
		return true;
	}

	if (armstatsActive)
	{
		SetArmStatsActive(false);
		return true;
	}

	if (zoommodeActive)
	{
		DoExitZoomMode();
		return true;
	}

	//exit highlighter.
	if (static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->GetHightlighterActive())
	{
		static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->SkipHighlighter();
		return true;
	}

	if (memorypalaceState == MEMP_ACTIVE)
	{
		ExitMemoryPalace();
		return true;
	}


	return false;
}

bool idPlayer::SkipCinematic( void ) {
	StartSound( "snd_skipcinematic", SND_CHANNEL_ANY, 0, false, NULL );
	return gameLocal.SkipCinematic();
}

/*
==============
idPlayer::EvaluateControls
==============
*/
void idPlayer::EvaluateControls( void )
{
	// check for respawning
	if ( health <= 0 )
	{
		if ( ( gameLocal.time > deathTimer + 1500 )  && ( usercmd.buttons & BUTTON_ATTACK ) ) //BC If you are dead and press attack, then do endgame screen.
		{
			forceRespawn = true;
		}
		/* BC do not automatically respawn the player.
		else if ( gameLocal.time > maxRespawnTime )
		{
			forceRespawn = true;
		}*/
	}

	// in MP, idMultiplayerGame decides spawns
	//if ( forceRespawn && !gameLocal.isMultiplayer && !g_testDeath.GetBool() )
	if (forceRespawn && !gameLocal.isMultiplayer && !spectating)
	{
		// in single player, we let the session handle restarting the level or loading a game
		//gameLocal.sessionCommand = "died";

		//BC death: when player clicks button, go to spectate cam
		hud->HandleNamedEvent("playerdeathhide"); //hide the death UI
		Show();
		ServerSpectate(true);
		SetOrigin( renderView->vieworg );
		SetAxis( renderView->viewaxis );
		physicsObj.SetLinearVelocity( idVec3( 0.0f, 0.0f, 0.0f ) );
		eyeOffset = idVec3(0.0f, 0.0f, 0.0f);
		gameLocal.spectatePause = true; //Pause the world.

		spectatorMenu->HandleNamedEvent("defeat"); //make the restart/load UI show up in the post-game ui screen (spectate.gui).
	}

	if ( ( usercmd.flags & UCF_IMPULSE_SEQUENCE ) != ( oldFlags & UCF_IMPULSE_SEQUENCE ) ) {
		PerformImpulse( usercmd.impulse );
	}	

	oldFlags = usercmd.flags;

	AdjustSpeed();

	// update the viewangles
	UpdateViewAngles();
}

/*
==============
idPlayer::AdjustSpeed
==============
*/
void idPlayer::AdjustSpeed( void ) {
	float speed;
	float rate;

	if ( spectating ) {
		speed = pm_spectatespeed.GetFloat();
		bobFrac = 0.0f;
	} else if ( noclip ) {

		speed = usercmd.buttons & BUTTON_RUN ? pm_noclipspeed.GetFloat() * 3.0f /*noclip speed multiplier*/ : pm_noclipspeed.GetFloat(); //BC noclip now understands run button
		bobFrac = 0.0f;

	}
#if _DEBUG
	else if ( !physicsObj.OnLadder() && ( usercmd.buttons & BUTTON_RUN ) && ( usercmd.forwardmove || usercmd.rightmove ) && ( usercmd.upmove >= 0 ) )
	{
		if ( !gameLocal.isMultiplayer && !physicsObj.IsCrouching() && !PowerUpActive( ADRENALINE ) ) {
			stamina -= MS2SEC( gameLocal.msec );
		}
		if ( stamina < 0 ) {
			stamina = 0;
		}
		if ( ( !pm_stamina.GetFloat() ) || ( stamina > pm_staminathreshold.GetFloat() ) ) {
			bobFrac = 1.0f;
		} else if ( pm_staminathreshold.GetFloat() <= 0.0001f ) {
			bobFrac = 0.0f;
		} else {
			bobFrac = stamina / pm_staminathreshold.GetFloat();
		}
		speed = pm_walkspeed.GetFloat() * ( 1.0f - bobFrac ) + pm_runspeed.GetFloat() * bobFrac;
	}
#endif
	else
	{
		if (gameLocal.time > staminaChargeDelayTimer + pm_staminachargedelay.GetFloat() && grenadeThrowState != GRENADETHROW_AIMING && jockeyState != JCK_ATTACHED)
		{
            //Handle stamina recharge here.

			rate = pm_staminarate.GetFloat();

			// increase 25% faster when not moving
			/*
			if ( ( usercmd.forwardmove == 0 ) && ( usercmd.rightmove == 0 ) && ( !physicsObj.OnLadder() || ( usercmd.upmove == 0 ) ) )
			{
				 rate *= 1.25f;
			}*/

			stamina += rate * MS2SEC(gameLocal.msec);
			if (stamina > pm_stamina.GetFloat())
			{
				stamina = pm_stamina.GetFloat();
			}
		}

		speed = pm_walkspeed.GetFloat();
		bobFrac = 0.0f;		
	}

	speed *= PowerUpModifier(SPEED);

	if ( influenceActive == INFLUENCE_LEVEL3 ) {
		speed *= 0.33f;
	}

	if (zoommodeActive)
	{
		//When in zoom inspect mode, scale down movement speed to discourage playing the entire game in this mode.
		speed *= ZOOMINSPECT_MOVEMENTSPEED_MULTIPLIER;
	}


	if (!noclip)
	{
        //bool ftlSpeedAdjust = false;
		//idEntity *ftlEnt = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetFTLDrive.GetEntity();
		//if (ftlEnt)
		//{
		//	if (static_cast<idFTL *>(ftlEnt)->IsJumpActive(false))
		//	{
		//		speed *= FTL_MOVESPEED_MULTIPLIER;
        //        ftlSpeedAdjust = true;
		//	}
		//}
		
        //if (IsInHealState() && !ftlSpeedAdjust)
		if (IsInHealState())
		{
			//speed *= HEALING_MOVESPEED_MULTIPLIER;
            speed = HEALING_MOVESPEED;
		}
		
	}

	//BC in space, clamp to walk speed.
	if (airless && !noclip)
	{
		physicsObj.SetSpeed(pm_spacespeed.GetFloat(), pm_spacespeed.GetFloat());
		return;
	}

	if (physicsObj.GetFallState() == FALLEN_IDLE && !inDownedState)
	{
		speed = (usercmd.rightmove != 0 && usercmd.forwardmove == 0) ? KNOCKDOWN_ROLLSPEED : KNOCKDOWN_FORWARDSPEED;

		//We need to zero out the velocity between forward/strafe direction changes, or else speed is inherited between the different move directions.
		if (speed != knockeddownLastSpeed)
		{
			knockeddownLastSpeed = speed;
			physicsObj.SetLinearVelocity(vec3_zero);
		}
		
		physicsObj.SetSpeed(speed, speed);
		return;
	}

	physicsObj.SetSpeed(speed, pm_crouchspeed.GetFloat());
}

/*
==============
idPlayer::AdjustBodyAngles
==============
*/
void idPlayer::AdjustBodyAngles( void ) {
	idMat3	lookAxis;
	idMat3	legsAxis;
	bool	blend;
	float	diff;
	float	frac;
	float	upBlend;
	float	forwardBlend;
	float	downBlend;

	if ( health < 0 || contextMenuActive) {
		return;
	}

	blend = true;

	if (AI_ACRO_CEILINGHIDE || AI_ACRO_SPLITS || AI_ACRO_SPLITS_DOWN)
	{
		//if in ceiling, then do nothing. the Body mesh angle is controlled in this function, some further lines below here.

		
	}
	else if ( !physicsObj.HasGroundContacts() )
	{
		//airborne.
		idealLegsYaw = 0.0f;
		legsForward = true;
	}
	else if ( usercmd.forwardmove < 0 )
	{
		//any permutation of backwards.
		idealLegsYaw = idMath::AngleNormalize180( idVec3( -usercmd.forwardmove, usercmd.rightmove, 0.0f ).ToYaw() );
		legsForward = false;
	}
	else if ( usercmd.forwardmove > 0 )
	{
		//any permutation of forward.
		idealLegsYaw = idMath::AngleNormalize180( idVec3( usercmd.forwardmove, -usercmd.rightmove, 0.0f ).ToYaw() );
		legsForward = true;
	}
	else if ( ( usercmd.rightmove != 0 ) && physicsObj.IsCrouching() )
	{
		//strafing while crouched.
		if ( !legsForward ) {
			idealLegsYaw = idMath::AngleNormalize180( idVec3( idMath::Abs( usercmd.rightmove ), usercmd.rightmove, 0.0f ).ToYaw() );
		} else {
			idealLegsYaw = idMath::AngleNormalize180( idVec3( idMath::Abs( usercmd.rightmove ), -usercmd.rightmove, 0.0f ).ToYaw() );
		}
	} else if ( usercmd.rightmove != 0 )
	{
		//strafing.
		//idealLegsYaw = 0.0f;
		idealLegsYaw = usercmd.rightmove > 0 ? -45 : 45;
		legsForward = true;
	}
	else
	{
		//standing still.
		legsForward = true;
		diff = idMath::Fabs( idealLegsYaw - legsYaw );
		idealLegsYaw = idealLegsYaw - idMath::AngleNormalize180( viewAngles.yaw - oldViewYaw );
		if ( diff < 0.1f ) {
			legsYaw = idealLegsYaw;
			blend = false;
		}
	}

	if ( !physicsObj.IsCrouching() ) {
		legsForward = true;
	}

	oldViewYaw = viewAngles.yaw;

	AI_TURN_LEFT = false;
	AI_TURN_RIGHT = false;

	
	if (!bodyAngleLocked)
	{
		if (idealLegsYaw < -45.0f) {
			idealLegsYaw = 0;
			AI_TURN_LEFT = true;
			blend = true;
		}
		else if (idealLegsYaw > 45.0f) {
			idealLegsYaw = 0;
			AI_TURN_RIGHT = true;
			blend = true;
		}
	}

	if ( blend ) {
		legsYaw = legsYaw * 0.9f + idealLegsYaw * 0.1f;
	}

	if (AI_ACRO_CEILINGHIDE || AI_ACRO_SPLITS )
	{
		//Lock body angle. We get the difference between the viewangle and the AcroAngle, and then force the body to face that direction.
		jointHandle_t originJoint = animator.GetJointHandle("body");
		float diff = idMath::AngleNormalize180(physicsObj.GetAcroAngle() - viewAngles.yaw);
		legsAxis = idAngles( 0.0f, diff, 0.0f).ToMat3();
		animator.SetJointAxis(originJoint, JOINTMOD_WORLD, legsAxis);
	}
	else if (jockeyState == JCK_ATTACHED)
	{
		//jockey riding a baddie. Lock body angle. Make player body be locked to same angle as the jockey target.
		if (meleeTarget.IsValid())
		{
			//const float JOCKEY_FWD_OFFSET = 8.0f;
			//const float JOCKEY_RIGHT_OFFSET = 0.0f;

			float meleetargetYaw = meleeTarget.GetEntity()->viewAxis.ToAngles().yaw;
			jointHandle_t originJoint = meleeTarget.GetEntity()->GetAnimator()->GetJointHandle("neck");
			legsAxis = idAngles(0.0f, meleetargetYaw, 0.0f).ToMat3();
			SetAxis( legsAxis );
			idVec3 pounceAttachPos;
			idMat3 pounceAttachMat;
			meleeTarget.GetEntity()->GetAnimator()->GetJointTransform( originJoint, gameLocal.time, pounceAttachPos, pounceAttachMat );
			//idVec3 forward, right, up;
			//legsAxis.ToAngles().ToVectors( &forward, &right, nullptr );
			//idVec3 offset = (( JOCKEY_FWD_OFFSET + pounceAttachPos.x) * forward) + ((pounceAttachPos.y + JOCKEY_RIGHT_OFFSET) * right);

			//common->Printf("offset %.1f %.1f %.1f  \n", offset.x, offset.y, offset.z);

			//SetOrigin(meleeTarget.GetEntity()->GetPhysics()->GetOrigin() + offset);
			SetOrigin(meleeTarget.GetEntity()->GetPhysics()->GetOrigin());

			//common->Printf("baddie %.1f %.1f %.1f   player %.1f %.1f %.1f\n",
			//	meleeTarget.GetEntity()->GetPhysics()->GetOrigin().x, meleeTarget.GetEntity()->GetPhysics()->GetOrigin().y, meleeTarget.GetEntity()->GetPhysics()->GetOrigin().z,
			//	GetPhysics()->GetOrigin().x, GetPhysics()->GetOrigin().y, GetPhysics()->GetOrigin().z);
		}
	}
	//else if (AI_ACRO_SPLITS)
	//{
	//	Lock body angle.
	//	int i;
	//	for (i = 0; i < 2; i++)
	//	{
	//		jointHandle_t originJoint = animator.GetJointHandle(i <= 0 ? "lhip" : "rhip");
	//		float diff = idMath::AngleNormalize180(physicsObj.GetAcroAngle() - viewAngles.yaw);
	//		legsAxis = idAngles(0.0f, diff, 0.0f).ToMat3();
	//		animator.SetJointAxis(originJoint, JOINTMOD_WORLD, legsAxis);
	//	}
	//}
	else
	{
		//Normal state.
		legsAxis = idAngles(0.0f, legsYaw, 0.0f).ToMat3();
		animator.SetJointAxis(hipJoint, JOINTMOD_WORLD, legsAxis);
	}

	// calculate the blending between down, straight, and up
	frac = viewAngles.pitch / 90.0f;
	if ( frac > 0.0f ) {
		downBlend		= frac;
		forwardBlend	= 1.0f - frac;
		upBlend			= 0.0f;
	} else {
		downBlend		= 0.0f;
		forwardBlend	= 1.0f + frac;
		upBlend			= -frac;
	}

	animator.CurrentAnim( ANIMCHANNEL_TORSO )->SetSyncedAnimWeight( 0, downBlend );
	animator.CurrentAnim( ANIMCHANNEL_TORSO )->SetSyncedAnimWeight( 1, forwardBlend );
	animator.CurrentAnim( ANIMCHANNEL_TORSO )->SetSyncedAnimWeight( 2, upBlend );

	animator.CurrentAnim( ANIMCHANNEL_LEGS )->SetSyncedAnimWeight( 0, downBlend );
	animator.CurrentAnim( ANIMCHANNEL_LEGS )->SetSyncedAnimWeight( 1, forwardBlend );
	animator.CurrentAnim( ANIMCHANNEL_LEGS )->SetSyncedAnimWeight( 2, upBlend );
}

/*
==============
idPlayer::InitAASLocation
==============
*/
void idPlayer::InitAASLocation( void ) {
	int		i;
	int		num;
	idVec3	size;
	idBounds bounds;
	idAAS	*aas;
	idVec3	origin;

	GetFloorPos( 64.0f, origin );

	num = gameLocal.NumAAS();
	aasLocation.SetGranularity( 1 );
	aasLocation.SetNum( num );
	for( i = 0; i < aasLocation.Num(); i++ ) {
		aasLocation[ i ].areaNum = 0;
		aasLocation[ i ].pos = origin;
		aas = gameLocal.GetAAS( i );
		if ( aas && aas->GetSettings() ) {
			size = aas->GetSettings()->boundingBoxes[0][1];
			bounds[0] = -size;
			size.z = 32.0f;
			bounds[1] = size;

			aasLocation[ i ].areaNum = aas->PointReachableAreaNum( origin, bounds, AREA_REACHABLE_WALK );
		}
	}
}

/*
==============
idPlayer::SetAASLocation
==============
*/
void idPlayer::SetAASLocation( void ) {
	int		i;
	int		areaNum;
	idVec3	size;
	idBounds bounds;
	idAAS	*aas;
	idVec3	origin;

	if ( !GetFloorPos( 64.0f, origin ) ) {
		return;
	}

	for( i = 0; i < aasLocation.Num(); i++ ) {
		aas = gameLocal.GetAAS( i );
		if ( !aas ) {
			continue;
		}

		size = aas->GetSettings()->boundingBoxes[0][1];
		bounds[0] = -size;
		size.z = 32.0f;
		bounds[1] = size;

		areaNum = aas->PointReachableAreaNum( origin, bounds, AREA_REACHABLE_WALK );
		if ( areaNum ) {
			aasLocation[ i ].pos = origin;
			aasLocation[ i ].areaNum = areaNum;
		}
	}
}

/*
==============
idPlayer::GetAASLocation
==============
*/
void idPlayer::GetAASLocation( idAAS *aas, idVec3 &pos, int &areaNum ) const {
	int i;

	if ( aas != NULL ) {
		for( i = 0; i < aasLocation.Num(); i++ ) {
			if ( aas == gameLocal.GetAAS( i ) ) {
				areaNum = aasLocation[ i ].areaNum;
				pos = aasLocation[ i ].pos;
				return;
			}
		}
	}

	areaNum = 0;
	pos = physicsObj.GetOrigin();
}

/*
==============
idPlayer::Move
==============
*/
void idPlayer::Move( void ) {
	float newEyeOffset;
	idVec3 oldOrigin;
	idVec3 oldVelocity;
	idVec3 pushVelocity;

	// save old origin and velocity for crashlanding
	oldOrigin = physicsObj.GetOrigin();
	oldVelocity = physicsObj.GetLinearVelocity();
	pushVelocity = physicsObj.GetPushedLinearVelocity();

	// set physics variables
	physicsObj.SetMaxStepHeight( pm_stepsize.GetFloat() );
	physicsObj.SetMaxJumpHeight( pm_jumpheight.GetFloat() );

	if ( noclip ) {
		physicsObj.SetContents( 0 );
		physicsObj.SetMovementType( PM_NOCLIP );
	} else if ( spectating ) {
		physicsObj.SetContents( 0 );
		physicsObj.SetMovementType( PM_SPECTATOR );
	} else if ( health <= 0 ) {
		physicsObj.SetContents( CONTENTS_CORPSE | CONTENTS_MONSTERCLIP );
		physicsObj.SetMovementType( PM_DEAD );
	} else if ( gameLocal.inCinematic || gameLocal.GetCamera() || privateCameraView || ( influenceActive == INFLUENCE_LEVEL2 ) ) {
		physicsObj.SetContents( CONTENTS_BODY );
		physicsObj.SetMovementType( PM_FREEZE );
#ifdef _D3XP
	} else if ( mountedObject ) {
		physicsObj.SetContents( 0 );
		physicsObj.SetMovementType( PM_FREEZE );
#endif
	}
	else if (viewposAbsActive)
	{
		//if camera lerp is active, then ignore movement.
		physicsObj.SetContents(CONTENTS_BODY);
		physicsObj.SetMovementType(PM_FREEZE);
	}
	else if (peekObject.IsValid())
	{
		//don't let player move during peeking.
		physicsObj.SetContents(CONTENTS_BODY);
		physicsObj.SetMovementType(PM_FREEZE);
		
		
		if (usercmd.forwardmove < 0 || usercmd.rightmove != 0)
		{
			if (peekObject.GetEntity()->IsType(idVentpeek::Type))
			{
				if (static_cast<idVentpeek *>(peekObject.GetEntity())->peekEnt.IsValid())
				{
					if (static_cast<idVentpeek*>(peekObject.GetEntity())->CanFrobExit()) // SW: Player cannot exit ventpeeks during certain vignettes
					{
						static_cast<idVentpeek*>(peekObject.GetEntity())->StopPeek();
					}
				}
			}
		}
		else if (usercmd.forwardmove > 0)
		{
			//Player move FORWARD while in peek view.
			if (peekObject.GetEntity()->IsType(idVentpeek::Type))
			{
				if (static_cast<idVentpeek *>(peekObject.GetEntity())->peekEnt.IsValid())
				{
					if (static_cast<idVentpeek *>(peekObject.GetEntity())->ownerEnt.IsValid())
					{
						idEntity *ownerEnt = static_cast<idVentpeek *>(peekObject.GetEntity())->ownerEnt.GetEntity();						

						static_cast<idVentpeek *>(peekObject.GetEntity())->StopPeek(); //Stop peek.
						ownerEnt->DoFrob(PEEKFROB_INDEX, this); //Open the door/object this peek associated with.
					}
				}
			}
		}

		//Ventpeek noises when you turn head quickly.
		if (peekObject.IsValid() && gameLocal.time > ventpeekRustleTimer)
		{
			float turningSoundThreshold = VENTPEEK_TURNING_SOUNDTHRESHOLD;
			int turningSoundDelay = VENTPEEK_TURNING_SOUNDDELAY;

			if (peekObject.GetEntity()->IsType(idVentpeek::Type))
			{
				turningSoundThreshold = static_cast<idVentpeek*>(peekObject.GetEntity())->GetTurningSoundThreshold();
				turningSoundDelay = static_cast<idVentpeek*>(peekObject.GetEntity())->GetTurningSoundDelay();
			}

			idAngles lastAngles = loggedViewAngles[(gameLocal.framenum - 1) & (NUM_LOGGED_VIEW_ANGLES - 1)];

			if (fabs(viewAngles.yaw - lastAngles.yaw) >= turningSoundThreshold ||
				fabs(viewAngles.pitch - lastAngles.pitch) >= turningSoundThreshold)
			{
				peekObject.GetEntity()->StartSound("snd_turnhead", SND_CHANNEL_ANY, SSF_GLOBAL, false, NULL);
				ventpeekRustleTimer = gameLocal.time + turningSoundDelay;
			}
		}
	}
	else if (jockeyState == JCK_ATTACHED)
	{
		physicsObj.SetContents(0);
	}
	else
	{
		physicsObj.SetContents( CONTENTS_BODY );
		physicsObj.SetMovementType( PM_NORMAL );
	}

	if ( spectating ) {
		physicsObj.SetClipMask( MASK_DEADSOLID );
	} else if ( health <= 0 ) {
		physicsObj.SetClipMask( MASK_DEADSOLID );
	} else {
		physicsObj.SetClipMask( MASK_PLAYERSOLID );
	}

	physicsObj.SetDebugLevel( g_debugMove.GetBool() );
	physicsObj.SetPlayerInput( usercmd, viewAngles );

	// FIXME: physics gets disabled somehow
	BecomeActive( TH_PHYSICS );
	RunPhysics();

	// update our last valid AAS location for the AI
	SetAASLocation();

	if ( spectating )
	{
		newEyeOffset = 0.0f;
	}
	else if ( health <= 0 )
	{
		newEyeOffset = pm_deadviewheight.GetFloat();
	}
	else if ( physicsObj.IsCrouching() && !IsInMech())
	{
		newEyeOffset = pm_crouchviewheight.GetFloat();
	}
	else if ( GetBindMaster() && GetBindMaster()->IsType( idAFEntity_Vehicle::Type ) )
	{
		newEyeOffset = 0.0f;
	}
	else
	{
		newEyeOffset = pm_normalviewheight.GetFloat();
	}

	if ( EyeHeight() != newEyeOffset ) {
		if ( spectating || noclip || (teleportCrouchTime + TELEPORTCROUCH_EASE_TIME > gameLocal.time) ) {
			SetEyeHeight( newEyeOffset );
		} else {
			// smooth out duck height changes
			// Where are we right now, between the max and minimum eye height?
			float crouchLerp = (EyeHeight() - pm_crouchviewheight.GetFloat()) / (pm_normalviewheight.GetFloat() - pm_crouchviewheight.GetFloat()); 
			float crouchLerpChange = pm_crouchrate.GetFloat() * (gameLocal.msec / 16.0f); // How much should we change on this frame? (Scale appropriately for slowdown)
			// Are we going up or down?
			if (newEyeOffset < EyeHeight())
			{
				// Multiply our change by the current crouchlerp to ensure a nice smooth ease out
				// (i.e. the smaller crouchLerp is, the smaller the change is)
				crouchLerp -= crouchLerpChange * crouchLerp; 
			}
			else
			{
				// Same as above, but inverted
				crouchLerp += crouchLerpChange * (1 - crouchLerp); 
			}

			// Because of the maths above, crouchLerp will tend towards 0 but never actually reach it.
			// When we're close enough, we just snap for sanity
			if (crouchLerp < 0.01)
				crouchLerp = 0;

			float targetEyeHeight = idMath::Lerp(pm_crouchviewheight.GetFloat(), pm_normalviewheight.GetFloat(), idMath::ClampFloat(0, 1, crouchLerp));

			if (targetEyeHeight == pm_crouchviewheight.GetFloat())
			{
				// We're there -- don't bother with a trace
				SetEyeHeight(targetEyeHeight);
			}
			else
			{	
				
				if (this->GetPhysics()->GetBounds().zMax() < targetEyeHeight)
				{
					// SW: Our eyes extend up above the top of our collision box, uh oh.
					// Trace up from the top of the collision box to our eye height so we don't clip into the ceiling
					// (This can happen if the player suddenly crouches while jumping/clambering in a space with a low ceiling)
					trace_t tr;
					gameLocal.clip.TracePoint(
						tr,
						this->GetPhysics()->GetOrigin() + idVec3::Up() * this->GetPhysics()->GetBounds().zMax(),
						this->GetPhysics()->GetOrigin() + idVec3::Up() * targetEyeHeight,
						this->GetPhysics()->GetClipMask(),
						NULL
					);

					if (tr.fraction < 1.0f)
					{
						// We bumped our head on the ceiling
						SetEyeHeight((tr.endpos - this->GetPhysics()->GetOrigin()).LengthFast() - 4.0f); // Subtract a little bit to prevent the camera clipping
					}
					else
					{
						SetEyeHeight(targetEyeHeight);
					}
				}
				else
				{
					SetEyeHeight(targetEyeHeight);
				}
				
			}
			
		}
	}

	if ( noclip || gameLocal.inCinematic || ( influenceActive == INFLUENCE_LEVEL2 ) )
	{
		AI_CROUCH	= false;
		AI_ONGROUND	= ( influenceActive == INFLUENCE_LEVEL2 );
		AI_ONLADDER	= false;
		AI_JUMP		= false;
	}
	else
	{
		//in normal state.
		AI_CROUCH	= physicsObj.IsCrouching();
		AI_ONGROUND	= physicsObj.HasGroundContacts();
		AI_ONLADDER	= physicsObj.OnLadder();
		AI_JUMP		= physicsObj.HasJumped();

		AI_ACRO_CEILINGHIDE = (physicsObj.GetAcroType() == ACROTYPE_CEILINGHIDE);
		AI_ACRO_SPLITS = (physicsObj.GetAcroType() == ACROTYPE_SPLITS);
		AI_ACRO_SPLITS_DOWN = (physicsObj.GetAcroType() == ACROTYPE_SPLITS_DOWN);

		if (lastAcroState != physicsObj.GetAcroType())
		{
			lastAcroState = physicsObj.GetAcroType();

			if (physicsObj.GetAcroType() == ACROTYPE_CEILINGHIDE)
			{
				//Player has just entered the acro ceiling hide.
				SetArmVisibility(true);
				SetBodyAngleLock(true);

			}
			else if (physicsObj.GetAcroType() == ACROTYPE_SPLITS)
			{
				//Player has just entered splits. Call this.
				//SetBodyAngleLock(true);
				SetViewPitchLerp(70);
			}
			else if (physicsObj.GetAcroType() == ACROTYPE_SPLITS_DOWN)
			{
				SetViewPitchLerp(170);
				SetViewPosActive(true, idVec3(0, 0, -16));
			}
		}

		// check if we're standing on top of a monster and give a push if we are
		idEntity *groundEnt = physicsObj.GetGroundEntity();
		if ( groundEnt && groundEnt->IsType( idAI::Type ) ) {
			idVec3 vel = physicsObj.GetLinearVelocity();
			if ( vel.ToVec2().LengthSqr() < 0.1f ) {
				vel.ToVec2() = physicsObj.GetOrigin().ToVec2() - groundEnt->GetPhysics()->GetAbsBounds().GetCenter().ToVec2();
				vel.ToVec2().NormalizeFast();
				vel.ToVec2() *= pm_walkspeed.GetFloat();
			} else {
				// give em a push in the direction they're going
				vel *= 1.1f;
			}
			physicsObj.SetLinearVelocity( vel );
		}
	}

	if ( AI_JUMP ) {
		// bounce the view weapon
		loggedAccel_t	*acc = &loggedAccel[currentLoggedAccel&(NUM_LOGGED_ACCELS-1)];
		currentLoggedAccel++;
		acc->time = gameLocal.time;
		acc->dir[2] = 200;
		acc->dir[0] = acc->dir[1] = 0;

		StartSound("snd_jump", SND_CHANNEL_BODY3, 0, false, NULL);

		//BC jump
		//GivePowerUp(HASTE, 30000);

		//if (gameLocal.random.RandomInt(10) < 5)
		//	gameLocal.AddSubtitle(va("text %d", gameLocal.time * 2), 1500);
		//else
		//	gameLocal.AddSubtitle(va("text text text %d", gameLocal.time * 2), 3000);


		//bc jump debug
		//gameLocal.GetLocalPlayer()->hud->SetStateString("elimination_name", "baboo");
		//gameLocal.GetLocalPlayer()->SetHudNamedEvent("eliminationEvent");


        
	}

	if ( AI_ONLADDER ) {
		int old_rung = oldOrigin.z / LADDER_RUNG_DISTANCE;
		int new_rung = physicsObj.GetOrigin().z / LADDER_RUNG_DISTANCE;

		if ( old_rung != new_rung ) {
			StartSound( "snd_stepladder", SND_CHANNEL_ANY, 0, false, NULL );
		}
	}

	if (mechTransitionState == MECHTRANSITION_NONE && !peekObject.IsValid())
	{
		BobCycle(pushVelocity);
	}

	CrashLand( oldOrigin, oldVelocity );
}

/*
==============
idPlayer::UpdateHud
==============
*/
void idPlayer::UpdateHud( void ) {
	idPlayer *aimed;

	if ( !hud ) {
		return;
	}

	if ( entityNumber != gameLocal.localClientNum ) {
		return;
	}

	if ( gameLocal.realClientTime == lastMPAimTime ) {
		if ( MPAim != -1 && gameLocal.mpGame.IsGametypeTeamBased() /* CTF */
			&& gameLocal.entities[ MPAim ] && gameLocal.entities[ MPAim ]->IsType( idPlayer::Type )
			&& static_cast< idPlayer * >( gameLocal.entities[ MPAim ] )->team == team ) {
				aimed = static_cast< idPlayer * >( gameLocal.entities[ MPAim ] );
				hud->SetStateString( "aim_text", gameLocal.userInfo[ MPAim ].GetString( "ui_name" ) );
				hud->SetStateFloat( "aim_color", aimed->colorBarIndex );
				hud->HandleNamedEvent( "aim_flash" );
				MPAimHighlight = true;
				MPAimFadeTime = 0;	// no fade till loosing focus
		} else if ( MPAimHighlight ) {
			hud->HandleNamedEvent( "aim_fade" );
			MPAimFadeTime = gameLocal.realClientTime;
			MPAimHighlight = false;
		}
	}
	if ( MPAimFadeTime ) {
		assert( !MPAimHighlight );
		if ( gameLocal.realClientTime - MPAimFadeTime > 2000 ) {
			MPAimFadeTime = 0;
		}
	}

	hud->SetStateInt( "g_showProjectilePct", g_showProjectilePct.GetInteger() );
	if ( numProjectilesFired ) {
		hud->SetStateString( "projectilepct", va( "Hit %% %.1f", ( (float) numProjectileHits / numProjectilesFired ) * 100 ) );
	} else {
		hud->SetStateString( "projectilepct", "Hit % 0.0" );
	}

	if ( isLagged && gameLocal.isMultiplayer && gameLocal.localClientNum == entityNumber ) {
		hud->SetStateString( "hudLag", "1" );
	} else {
		hud->SetStateString( "hudLag", "0" );
	}

	//Do not draw healthbar if in downed state.
	if (!inDownedState)
	{
		//Player is NOT in downed state.
		hud->SetStateInt("showhealthbar", 1);
	}
	else
	{
		//Player in downed state.
		hud->SetStateInt("showhealthbar", 0);

		if (bloodbagState == BLOODBAGSTATE_TRANSFUSING && bloodbagHealth < HEALTH_BLOODBAG_DEFAULTHEALTH)
		{
			hud->SetStateBool("bloodbagactive", true);
		}
		else
		{
			hud->SetStateBool("bloodbagactive", false);
		}
	}

	hud->SetStateBool("frobavailable", (frobEnt != NULL));



	//keys.
	if (HasInventoryItem("redkey"))
	{
		hud->SetStateBool("hasredkey", true);
		armstatsModel->Event_SetGuiInt("hasredkey", 1);
		contextMenu->SetStateInt("hasredkey", 1);
	}

	if (HasInventoryItem("bluekey"))
	{
		hud->SetStateBool("hasbluekey", true);
		armstatsModel->Event_SetGuiInt("hasbluekey", 1);
		contextMenu->SetStateInt("hasbluekey", 1);
	}


	if (isInVignette)
	{
		hud->SetStateInt("showhealthbar", -1); //BC this has to be -1 in order for the vignettes to hide both healthbar and downed button.
	}
}

/*
==============
idPlayer::UpdateDeathSkin
==============
*/
void idPlayer::UpdateDeathSkin( bool state_hitch ) {
	if ( !( gameLocal.isMultiplayer || g_testDeath.GetBool() ) ) {
		return;
	}
	if ( health <= 0 ) {
		if ( !doingDeathSkin ) {
			deathClearContentsTime = spawnArgs.GetInt( "deathSkinTime" );
			doingDeathSkin = true;
			renderEntity.noShadow = true;
			if ( state_hitch ) {
				renderEntity.shaderParms[ SHADERPARM_TIME_OF_DEATH ] = gameLocal.time * 0.001f - 2.0f;
			} else {
				renderEntity.shaderParms[ SHADERPARM_TIME_OF_DEATH ] = gameLocal.time * 0.001f;
			}
			UpdateVisuals();
		}

		// wait a bit before switching off the content
		if ( deathClearContentsTime && gameLocal.time > deathClearContentsTime ) {
			SetCombatContents( false );
			deathClearContentsTime = 0;
		}
	} else {
		renderEntity.noShadow = false;
		renderEntity.shaderParms[ SHADERPARM_TIME_OF_DEATH ] = 0.0f;
		UpdateVisuals();
		doingDeathSkin = false;
	}
}

/*
==============
idPlayer::StartFxOnBone
==============
*/
void idPlayer::StartFxOnBone( const char *fx, const char *bone ) {
	idVec3 offset;
	idMat3 axis;
	jointHandle_t jointHandle = GetAnimator()->GetJointHandle( bone );

	if ( jointHandle == INVALID_JOINT ) {
		gameLocal.Printf( "Cannot find bone %s\n", bone );
		return;
	}

	if ( GetAnimator()->GetJointTransform( jointHandle, gameLocal.time, offset, axis ) ) {
		offset = GetPhysics()->GetOrigin() + offset * GetPhysics()->GetAxis();
		axis = axis * GetPhysics()->GetAxis();
	}

	idEntityFx::StartFx( fx, &offset, &axis, this, true );
}

/*
==============
idPlayer::Think

Called every tic for each player
==============
*/
void idPlayer::Think( void ) {
	renderEntity_t *headRenderEnt;
	int isBaffled = 0;

	//debug draw player velocity
	if (g_showPlayerSpeed.GetBool())
	{
		float spd = GetPhysics()->GetLinearVelocity().Length();
		if (spd != 0)
		{
			common->Printf("Player speed: %0.2f\n", spd);
		}
	}

	//debug
	//gameRenderWorld->DebugLine(idVec4(1, .7f, 0, 1), GetPhysics()->GetOrigin() + idVec3(0,-64,68), GetPhysics()->GetOrigin() + idVec3(0, 64, 68), 100, true);




	//DOOM BFG
	if (weapon.GetEntity() != NULL && !hiddenWeapon && !carryableItem.IsValid())
	{
		if (weapon.GetEntity()->autoaimEnabled)
		{
			this->UpdateAutoAim();
		}
	}

	UpdatePlayerIcons();

	// latch button actions
	oldButtons = usercmd.buttons;

	// grab out usercmd
	usercmd_t oldCmd = usercmd;
	usercmd = gameLocal.usercmds[ entityNumber ];
	buttonMask &= usercmd.buttons;
	usercmd.buttons &= ~buttonMask;

	if ( gameLocal.inCinematic && gameLocal.skipCinematic ) {
		return;
	}

	// SM: Disable movement when in certain menus
	if ( eventlogMenuActive || levelselectMenuActive || emailFullscreenState != EFS_OFF || contextMenuActive || escapedFullScreenMenu ) {
		usercmd.forwardmove = 0;
		usercmd.rightmove = 0;
		usercmd.upmove = 0;
		usercmd.buttonState[UB_DOWN] = 0;
		usercmd.buttonState[UB_UP] = 0;
		escapedFullScreenMenu = false;
	}

	if(!airless && !noclip && !spectating && !zoominspect_LabelmodeActive)
	{
		bool crouchPressed = usercmd.buttonState && usercmd.prevButtonState[UB_DOWN] <= 0 && usercmd.buttonState[UB_DOWN] > 0 && !common->IsConsoleActive();
		bool jumpPressed = usercmd.buttonState && usercmd.prevButtonState[UB_UP] <= 0 && usercmd.buttonState[UB_UP] > 0 && !common->IsConsoleActive();
		// SM: Handle toggle crouch
		if ( in_toggleCrouch.GetBool() && usercmd.buttonState) {
			// Should we enter/exit on crouch
			if ((crouchPressed || jumpPressed ) && toggleCrouch && !physicsObj.CheckUnduckOverheadClear()) {
				// try to clamber out of cubby and stand if there's a nearby opening
				if( physicsObj.TryClamberOutOfCubby(false) ) {
					UnsetToggleCrouch();
				} else {
					// keep player in crouch toggle if unable to uncrouch
					if (crouchPressed ) {
						gameLocal.GetLocalPlayer()->SetCenterMessage("#str_def_gameplay_cantstand");
					}

					gameLocal.GetLocalPlayer()->StartSound("snd_impactcrouch", SND_CHANNEL_ANY);
					//gameLocal.voManager.SayVO(gameLocal.GetLocalPlayer(), "snd_pain", VO_CATEGORY_GRUNT); //very low priority player sound
				
					idAngles viewForward = gameLocal.GetLocalPlayer()->viewAngles;
					viewForward.pitch = 0;
					viewForward.roll = 0;
					gameLocal.DoParticle(gameLocal.GetLocalPlayer()->spawnArgs.GetString("model_impactcrouch"),
						gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin() + idVec3(0, 0, 40) + viewForward.ToForward() * 8, idVec3(90,0,0));
				}
			} else if (crouchPressed) {
				toggleCrouch = !toggleCrouch;
			} // Should we exit toggle crouch on jump?
			else if (toggleCrouch && jumpPressed && !physicsObj.TryClamber(true, 2)) {
				UnsetToggleCrouch();
			}

			if ( toggleCrouch ) {
				usercmd.upmove = 0;
			}
			usercmd.upmove -= toggleCrouch * KEY_MOVESPEED;
		} else if (physicsObj.IsCrouching() && usercmd.upmove > 0) {
			// If we aren't in toggle crouch but stuck crouching and trying to jump, see if we can clamber
			if( jumpPressed && physicsObj.TryClamberOutOfCubby(true) )
			{
				UnsetToggleCrouch();
			}
			else if( physicsObj.TryClamber(true, 2) ) {
			}
		}
	}

	// clear the ik before we do anything else so the skeleton doesn't get updated twice
	walkIK.ClearJointMods();

	// if this is the very first frame of the map, set the delta view angles
	// based on the usercmd angles
	if ( !spawnAnglesSet && ( gameLocal.GameState() != GAMESTATE_STARTUP ) ) {
		spawnAnglesSet = true;
		SetViewAngles( spawnAngles );
		oldFlags = usercmd.flags;
	}


	// set rolling state to lock character into anim
	if (physicsObj.GetFallState() == FALLEN_IDLE)
	{
		if (!AI_FALLEN_ROLL && usercmd.rightmove != 0 && usercmd.upmove == 0)
		{
			// start roll
			fallenRollTimer = gameLocal.time + FALLEN_ROLL_TIME;
			AI_FALLEN_ROLL = true;
			usercmd.forwardmove = 0;
			usercmd.upmove = 0;
		}
		else if( AI_FALLEN_ROLL )
		{
			// keep moving until state finishes
			usercmd.rightmove = oldCmd.rightmove;
			usercmd.forwardmove = 0;
			usercmd.upmove = 0;
		}
	}

	if (this->isFrozen != FROZ_NONE || mountedObject || (physicsObj.GetFallState() == FALLEN_HEADONGROUND || physicsObj.GetFallState() == FALLEN_RISING) || mechStartupstate || mechTransitionState == MECHTRANSITION_ENTERING || mechTransitionState == MECHTRANSITION_MOVINGTOBEHIND)
	{
		usercmd.forwardmove = 0;
		usercmd.rightmove = 0;
		usercmd.upmove = 0;
	}
	


	if (impactslowmoActive && gameLocal.time > impactslowmoTimer)
	{
		//Logic for exiting the slow mo state.
		SetImpactSlowmo(false);
	}


	if (mechTransitionState == MECHTRANSITION_MOVINGTOBEHIND)
	{
		if (mountedMech.GetEntity() != NULL)
		{
			idVec3 mechPos = mountedMech.GetEntity()->GetPhysics()->GetOrigin();
			idVec3 mechDir = idAngles(0, mountedMech.GetEntity()->viewAxis.ToAngles().yaw, 0).ToForward();
			idVec3 behindPos = mechPos + (mechDir * -48);

			float mechLerp = idMath::ClampFloat(0, 1.0f, (gameLocal.time - mechTransitionTimer) / (float)MECH_MOVETOBEHIND_TIME);			
			
			idVec3 lerpedPos;
			lerpedPos.x = idMath::Lerp(mechplayerStartPos.x, behindPos.x, mechLerp);
			lerpedPos.y = idMath::Lerp(mechplayerStartPos.y, behindPos.y, mechLerp);
			lerpedPos.z = idMath::Lerp(mechplayerStartPos.z, behindPos.z, mechLerp);

			SetOrigin(lerpedPos);
			
			if (mechLerp >= 1)
			{
				mechTransitionTimer = gameLocal.time;
				mechplayerStartPos = GetPhysics()->GetOrigin();
				mechTransitionState = MECHTRANSITION_ENTERING;
			}
		}
	}
	else if (mechTransitionState == MECHTRANSITION_ENTERING)
	{
		if (mountedMech.GetEntity() != NULL)
		{
			idVec3 mechPos = mountedMech.GetEntity()->GetPhysics()->GetOrigin();
			idVec3 mechDir = idAngles(0, mountedMech.GetEntity()->viewAxis.ToAngles().yaw, 0).ToForward();
			idVec3 behindPos = mechPos + (mechDir * -24);

			float mechLerp = idMath::ClampFloat(0, 1.0f, (gameLocal.time - mechTransitionTimer) / (float)MECH_ENTERING_TIME);			

			idVec3 lerpedPos;
			lerpedPos.x = idMath::Lerp(mechplayerStartPos.x, behindPos.x, mechLerp);
			lerpedPos.y = idMath::Lerp(mechplayerStartPos.y, behindPos.y, mechLerp);
			lerpedPos.z = idMath::Lerp(mechplayerStartPos.z, behindPos.z, mechLerp);

			SetOrigin(lerpedPos);

			if (mechLerp >= 1)
			{
				//Attach player to the mech.
				SetOrigin(mechPos);
				mechTransitionState = MECHTRANSITION_PILOTING;
				SetClipModel(); //Use mech big collision box.

				playerView.Fade(idVec4(0, 0, 0, 0.0f), 200); //fade up.
				
				mountedMech.GetEntity()->SetDrawBall(false);
				mountedMech.GetEntity()->Bind(this, true);

				mechCockpit->Show();
				mechCockpit->Event_PlayAnim("startup", 1);
				mechStartupTimer = gameLocal.time;
				hiddenWeapon = true;

				//Switch to Mech Cannon weapon.
				//Give("weapon", "weapon_mechcannon", 0); // TODO: What health should this be set to?
				//ammo_t ammo_i = inventory.AmmoIndexForWeaponClass("weapon_mechcannon", NULL);
				//idealWeapon = newweap;
				//inventory.ammo[ammo_i] += ammoavailable;
				//Event_SelectWeapon("weapon_mechcannon");

				mechCockpit->StartSound("snd_mechenter", SND_CHANNEL_VOICE);
			}
		}
	}
	else if (mechTransitionState == MECHTRANSITION_PILOTING)
	{
		if (mechStartupstate && mechStartupTimer + MECH_STARTUPTIME < gameLocal.time)
		{
			mechStartupstate = false;
		}
	}

	

	if (bodyAngleLocked)
	{
		usercmd.forwardmove = 0;
		usercmd.rightmove = 0;

		if (!AI_ACRO_CEILINGHIDE && !AI_ACRO_SPLITS) //allow jumping while in acro modes.
		{
			usercmd.upmove = 0;
		}
	}



	if ( objectiveSystemOpen || gameLocal.inCinematic || influenceActive ) {
		if ( objectiveSystemOpen && AI_PAIN ) {
			TogglePDA();
		}
		usercmd.forwardmove = 0;
		usercmd.rightmove = 0;
		usercmd.upmove = 0;
	}

	// log movement changes for weapon bobbing effects
	if ( usercmd.forwardmove != oldCmd.forwardmove ) {
		loggedAccel_t	*acc = &loggedAccel[currentLoggedAccel&(NUM_LOGGED_ACCELS-1)];
		currentLoggedAccel++;
		acc->time = gameLocal.time;
		acc->dir[0] = usercmd.forwardmove - oldCmd.forwardmove;
		acc->dir[1] = acc->dir[2] = 0;
	}

	if ( usercmd.rightmove != oldCmd.rightmove ) {
		loggedAccel_t	*acc = &loggedAccel[currentLoggedAccel&(NUM_LOGGED_ACCELS-1)];
		currentLoggedAccel++;
		acc->time = gameLocal.time;
		acc->dir[1] = usercmd.rightmove - oldCmd.rightmove;
		acc->dir[0] = acc->dir[2] = 0;
	}

	// freelook centering
	//centerView.Init( gameLocal.time, 200, viewAngles.pitch, 0 );
	
	

	if ((usercmd.buttons & BUTTON_ZOOM) && !iteminspectActive && zoombuttonTimer + ZOOM_HOLDTIME_THRESHOLD < gameLocal.time && zoomWaitingForInitialRelease)
	{
		//player held zoom button for a while. enter item inspect mode.
		zoomWaitingForInitialRelease = false;
		DoInspectCurrentItem();
	}

	bool exitZoomMode = false;

	// zooming. Called when the state of the zoom button changes
	if ( ( usercmd.buttons ^ oldCmd.buttons ) & BUTTON_ZOOM)
	{	
		// This is a press of the zoom button
		if (usercmd.buttons & BUTTON_ZOOM)
		{
			// If we're already in zoom mode, exit
			if (zoommodeActive)
			{
				if (!zoominspect_LabelmodeActive)
				{
					exitZoomMode = true;
				}
			}
			else if (iteminspectActive) // Exiting inspect
			{
				ExitIteminspectMode();
			}
			else
			{
				// start the timer
				zoombuttonTimer = gameLocal.time;
				zoomWaitingForInitialRelease = true;
			}
		}
		else // this is the release of the zoom button
		{
			zoomWaitingForInitialRelease = false;
			hud->SetStateFloat("zoomhold", 0);
			// This is a tap, enter zoom mode if we can
			if (zoombuttonTimer + ZOOM_HOLDTIME_THRESHOLD > gameLocal.time)
			{
				if (CanZoom())
				{
					zoommodeActive = true;

					int currentTime = gameLocal.spectatePause ? gameLocal.hudTime : gameLocal.time;
					zoomFov.Init(currentTime, ZOOM_LERPTIME, CalcFov(false), this->zoomCurrentFOV); //Activate the zoom fov.
					StartSound("snd_zoomin", SND_CHANNEL_ANY, 0, false, NULL);
					hud->HandleNamedEvent("startzoom");
					hud->SetStateBool("showzoomcontrols", true);

					hud->HandleNamedEvent("noteAlreadyRead");
				}
			}
		}
	}

	// If we're in zoom mode and jump, exit zoom mode also
	if (zoommodeActive && usercmd.upmove > 0)
	{
		exitZoomMode = true;
	}

	if (zoommodeActive && ((usercmd.buttons & BUTTON_QUICKTHROW) && !(oldButtons & BUTTON_QUICKTHROW)) && !zoominspect_LabelmodeActive)
	{
		exitZoomMode = true;
	}

	if (exitZoomMode)
	{
		DoExitZoomMode();
	}

	if ((usercmd.buttons & BUTTON_ZOOM) && !zoommodeActive && CanZoom() && !exitZoomMode)
	{
		float lerp = ((zoombuttonTimer + ZOOM_HOLDTIME_THRESHOLD) - gameLocal.time) / (float)ZOOM_HOLDTIME_THRESHOLD;
		lerp = 1.0f - lerp;
		lerp = idMath::ClampFloat(0, 1, lerp);

		hud->SetStateFloat("zoomhold", lerp);		
	}

	//Buttons to exit label inspect. We allow both zoom + frob + attack, because both buttons are used in different contexts to activate this zoom.
	if (((usercmd.buttons & BUTTON_ZOOM) && !(oldButtons & BUTTON_ZOOM))
		||
		((usercmd.buttons & BUTTON_FROB) && !(oldButtons & BUTTON_FROB))
		||
		((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
		||
		((usercmd.buttons & BUTTON_QUICKTHROW) && !(oldButtons & BUTTON_QUICKTHROW)))
	{
		if (zoominspect_LabelmodeActive)
		{
			ExitLabelinspectMode();
		}
		else if (iteminspectActive)
		{
			// to prevent immediately firing
			nextAttackTime = gameLocal.time + 50;
			ExitIteminspectMode();
		}
	}


	int zoommodeValue;
	if (memorypalaceState == MEMP_SPAWNDELAY || memorypalaceState == MEMP_ACTIVE)
	{
		//memory palace.
		zoommodeValue = 2;
	}
	else if (zoommodeActive || iteminspectActive || zoominspect_LabelmodeActive)
	{
		//zoom mode.
		zoommodeValue = 1;
	}
	else
	{
		//normal.
		zoommodeValue = 0;
	}

	hud->SetStateInt("zoommode", zoommodeValue);


	// if we have an active gui, we will unrotate the view angles as
	// we turn the mouse movements into gui events
	idUserInterface *gui = ActiveGui();
	if ( gui && gui != focusUI ) {
		RouteGuiMouse( gui );
	}

	// set the push velocity on the weapon before running the physics
	if ( weapon.GetEntity() ) {
		weapon.GetEntity()->SetPushVelocity( physicsObj.GetPushedLinearVelocity() );
	}

	EvaluateControls();

	if ( !af.IsActive() )
	{
		AdjustBodyAngles();
		CopyJointsFromBodyToHead();		
	}


	if (!gameLocal.menuPause || gameLocal.spectatePause)
		Move();

	if ( !g_stopTime.GetBool() )
	{
		if ( !noclip && !spectating && ( health > 0 ) && !IsHidden() ) {
			TouchTriggers();
		}

		// not done on clients for various reasons. don't do it on server and save the sound channel for other things
		if ( !gameLocal.isMultiplayer ) {
			SetCurrentHeartRate();
#ifdef _D3XP
			float scale = new_g_damageScale;
#else
			float scale = g_damageScale.GetFloat();
#endif
			if ( g_useDynamicProtection.GetBool() && scale < 1.0f && gameLocal.time - lastDmgTime > 500 ) {
				if ( scale < 1.0f ) {
					scale += 0.05f;
				}
				if ( scale > 1.0f ) {
					scale = 1.0f;
				}
#ifdef _D3XP
				new_g_damageScale = scale;
#else
				g_damageScale.SetFloat( scale );
#endif
			}
		}

		// update GUIs, Items, and character interactions
		UpdateFocus();

		UpdateLocation();

		// update player script
		UpdateScript();

		// service animations
		if ( !spectating && !af.IsActive() && !gameLocal.inCinematic ) {
			UpdateConditions();
			UpdateAnimState();
			CheckBlink();
		}

		// clear out our pain flag so we can tell if we recieve any damage between now and the next time we think
		AI_PAIN = false;
	}

	// calculate the exact bobbed view position, which is used to
	// position the view weapon, among other things
	CalculateFirstPersonView();

	// this may use firstPersonView, or a thirdPeroson / camera view
	CalculateRenderView();

	inventory.UpdateArmor();

	if ( spectating )
	{
		bool didLevelChange = UpdateSpectating();
		if (didLevelChange) // SM: Fix for crash on level change
			return;
	}
	else if ( health > 0 )
	{
		UpdateWeapon();
	}

	//Melee bash.
	if (meleeTarget.IsValid() && (usercmd.buttons & BUTTON_BASH))
	{
		if (inputReadyForTakedown)
		{
			StartBashAttack();
		}
	}
	else if ((usercmd.buttons & BUTTON_BASH) && !(oldButtons & BUTTON_BASH))
	{
		if (IsLeaning())
		{
			StartSound("snd_error", SND_CHANNEL_ANY);
		}
		else
		{
			StartBashAttack();
		}

		inputReadyForTakedown = false;
	}
	else
	{
		if (carryableBashActive && (carryableBashTimer < gameLocal.time))
		{
			carryableBashActive = false;
		}
	}

	if (!inputReadyForTakedown)
	{
		if (!(usercmd.buttons & BUTTON_BASH))
		{
			inputReadyForTakedown = true;
		}
	}
	

	//BC
	UpdateFrob();
	UpdatePlacerSticky();
	UpdateDefib();

	UpdateAir();

#ifdef _D3XP
	UpdatePowerupHud();
#endif

	UpdateHud();

	UpdatePowerUps();

	UpdateDeathSkin( false );

	if ( gameLocal.isMultiplayer ) {
		DrawPlayerIcons();

#ifdef _D3XP
		if ( enviroSuitLight.IsValid() ) {
			idAngles lightAng = firstPersonViewAxis.ToAngles();
			idVec3 lightOrg = firstPersonViewOrigin;
			const idDict *lightDef = gameLocal.FindEntityDefDict( "envirosuit_light", false );

			idVec3 enviroOffset = lightDef->GetVector( "enviro_offset" );
			idVec3 enviroAngleOffset = lightDef->GetVector( "enviro_angle_offset" );

			lightOrg += (enviroOffset.x * firstPersonViewAxis[0]);
			lightOrg += (enviroOffset.y * firstPersonViewAxis[1]);
			lightOrg += (enviroOffset.z * firstPersonViewAxis[2]);
			lightAng.pitch += enviroAngleOffset.x;
			lightAng.yaw += enviroAngleOffset.y;
			lightAng.roll += enviroAngleOffset.z;

			enviroSuitLight.GetEntity()->GetPhysics()->SetOrigin( lightOrg );
			enviroSuitLight.GetEntity()->GetPhysics()->SetAxis( lightAng.ToMat3() );
			enviroSuitLight.GetEntity()->UpdateVisuals();
			enviroSuitLight.GetEntity()->Present();
		}
#endif
	}

	if ( head.GetEntity() ) {
		headRenderEnt = head.GetEntity()->GetRenderEntity();
	} else {
		headRenderEnt = NULL;
	}

	if ( headRenderEnt ) {
		if ( influenceSkin ) {
			headRenderEnt->customSkin = influenceSkin;
		} else {
			headRenderEnt->customSkin = NULL;
		}
	}

	if ( gameLocal.isMultiplayer || g_showPlayerShadow.GetBool() ) {
		renderEntity.suppressShadowInViewID	= 0;
		if ( headRenderEnt ) {
			headRenderEnt->suppressShadowInViewID = 0;
		}
	} else {
		renderEntity.suppressShadowInViewID	= entityNumber+1;
		if ( headRenderEnt ) {
			headRenderEnt->suppressShadowInViewID = entityNumber+1;
		}
	}
	// never cast shadows from our first-person muzzle flashes
	renderEntity.suppressShadowInLightID = LIGHTID_VIEW_MUZZLE_FLASH + entityNumber;
	if ( headRenderEnt ) {
		headRenderEnt->suppressShadowInLightID = LIGHTID_VIEW_MUZZLE_FLASH + entityNumber;
	}

	// SM: Option for lights to not cast a player shadow
	renderEntity.isPlayer = true;
	if ( headRenderEnt ) {
		headRenderEnt->isPlayer = true;
	}

	if ( !g_stopTime.GetBool() ) {
		UpdateAnimation();

		Present();

		UpdateDamageEffects();

		LinkCombat();


		if (!zoominspect_LabelmodeActive) //don't do screenshake during zoom mode, as it's kinda nauseating.
		{
			playerView.CalculateShake();
		}
	}

	if ( !( thinkFlags & TH_THINK ) ) {
		gameLocal.Printf( "player %d not thinking?\n", entityNumber );
	}

	if ( g_showEnemies.GetBool() ) {
		idActor *ent;
		int num = 0;
		for( ent = enemyList.Next(); ent != NULL; ent = ent->enemyNode.Next() ) {
			gameLocal.Printf( "enemy (%d)'%s'\n", ent->entityNumber, ent->name.c_str() );
			gameRenderWorld->DebugBounds( colorRed, ent->GetPhysics()->GetBounds().Expand( 2 ), ent->GetPhysics()->GetOrigin() );
			num++;
		}
		gameLocal.Printf( "%d: enemies\n", num );
	}

#ifdef _D3XP
	inventory.RechargeAmmo(this);

	

	// determine if portal sky is in pvs
	gameLocal.portalSkyActive = gameLocal.pvs.CheckAreasForPortalSky( gameLocal.GetPlayerPVS(), GetPhysics()->GetOrigin() );
#endif



	//BC FROBBING
	if (health > 0)
	{
		UpdateFrobCursor();
		UpdateMeleeTarget();
	}

	if (zoommodeActive)
	{
		weapon.GetEntity()->LowerWeapon(); //in zoom mode, lower the weapon
	}

	//BC LEANING
	if (usercmd.buttons & BUTTON_LEAN && !peekObject.IsValid() && !IsInMech() &&  !zoominspect_LabelmodeActive && !iteminspectActive ) // SW: Don't let the player lean inside a ventpeek!
	{
		if (leanState == LEANSTATE_OFF)
		{
			trace_t handTrace = GetWallCorner();

			//Activate the lean.
			leanState = LEANSTATE_TRANSITIONON;

			leanAmountX = 0;
			leanAmountY = 0;

			lastLeanMouseX = usercmd.mx * m_leanSensitivity.GetFloat() / LEAN_SENSITIVITY_SCALAR;
			lastLeanMouseY = usercmd.my * m_leanSensitivity.GetFloat() / LEAN_SENSITIVITY_SCALAR;

			if (usercmdGen->IsUsingJoystick())
			{
				lastLeanMouseX = usercmdGen->JoystickAxisState(AXIS_RIGHT_X) * LEAN_MAX_X;
				lastLeanMouseX = usercmdGen->JoystickAxisState(AXIS_RIGHT_Y) * LEAN_MAX_Y;
			}

			lastLeanOffset = idVec3(0, 0, 0);

			if (handTrace.endpos != vec3_zero)
			{
				//Put hand on wall.
				//gameRenderWorld->DebugCircle(colorYellow, handTrace.endpos, handTrace.c.normal, 8, 9, 2000);
			}

			if (armstatsActive)
				SetArmStatsActive(false); //is leaning. get out of armstats.
		}

		//Lower weapon when leaning.
		StopFiring();
		weapon.GetEntity()->LowerWeapon();


		//int currentHotbarslotIndex = inventory.GetHotbarSelection();
		//if (currentHotbarslotIndex >= 0)
		//{
		//	int weaponIndex = inventory.hotbarSlots[currentHotbarslotIndex];
		//	if (weaponIndex > 0)
		//	{
		//		//player is equipped with SOMETHING right now.				
		//		if (inventory.carryPtrs[weaponIndex].IsValid() && carryableItem.IsValid())
		//		{
		//			if (inventory.carryPtrs[weaponIndex].GetEntityNum() == carryableItem.GetEntity()->entityNumber)
		//			{
		//				//player is currently equipped with a carryable. Hide it. We don't want the carryable to look active/useable during the lean (players can't use items during lean state).
		//				//TODO: do a quick hide animation instead...
		//				carryableItem.GetEntity()->Hide();
		//			}
		//		}				
		//	}
		//}		
	}
	else if (leanState == LEANSTATE_ACTIVE || leanState == LEANSTATE_TRANSITIONON)
	{
		if (leanState != LEANSTATE_TRANSITIONOFF)
		{
			//stop leaning.
			leanState = LEANSTATE_TRANSITIONOFF;
			lastLeanTime = gameLocal.time;
			lastLeanRoll = viewAngles.roll;

			SetListenModeActive(false);
		}
	}


	

	 


	//BC UPDATE VIEWPOS LERPING
	if (viewposState == LERPSTATE_TRANSITIONON || viewposState == LERPSTATE_TRANSITIONOFF)
	{
		float lerp = (gameLocal.time - viewposStarttime) / (float)VIEWPOS_OFFSET_MOVETIME;

		if (lerp >= 1.0f)
		{
			lerp = 1.0f;
		}

		if (viewposState == LERPSTATE_TRANSITIONON)
		{
			viewposOffset.x = idMath::Lerp(0.0f, viewposTargetOffset.x, lerp);
			viewposOffset.y = idMath::Lerp(0.0f, viewposTargetOffset.y, lerp);
			viewposOffset.z = idMath::Lerp(0.0f, viewposTargetOffset.z, lerp);
		}
		else if (viewposState == LERPSTATE_TRANSITIONOFF)
		{
			viewposOffset.x = idMath::Lerp(viewposTargetOffset.x, 0.0f, lerp);
			viewposOffset.y = idMath::Lerp(viewposTargetOffset.y, 0.0f, lerp);
			viewposOffset.z = idMath::Lerp(viewposTargetOffset.z, 0.0f, lerp);
		}


		if (gameLocal.time >= viewposStarttime + VIEWPOS_OFFSET_MOVETIME)
		{
			if (viewposState == LERPSTATE_TRANSITIONON)
			{
				viewposState = LERPSTATE_ON;
				viewposOffset.x = viewposTargetOffset.x;
				viewposOffset.y = viewposTargetOffset.y;
				viewposOffset.z = viewposTargetOffset.z;
			}
			else if (viewposState == LERPSTATE_TRANSITIONOFF)
			{
				viewposState = LERPSTATE_OFF;
			}
		}
	}


	//light editor.
	if ((usercmd.buttons & BUTTON_QUICKTHROW) && !(oldButtons & BUTTON_QUICKTHROW) && g_editEntityMode.GetInteger() > 0)
	{		
		//Open/close the editmenu.
		gameEdit->editmenuActive = !gameEdit->editmenuActive;

		LightEdit_OpenMenu(gameEdit->editmenuActive);

		return;		
	}

	UpdateMemoryPalace(); //need to call this before context menu toggle. To handle case where TAB to exit memorypalace would immediately activate contextmenu.

	//BC CONTEXT MENU. When player presses tab. Only called on the first frame that the tab button gets pressed.
	if (gameLocal.time > nextContextMenuAvailableTime && ((usercmd.buttons & BUTTON_CONTEXTMENU)  && !(oldButtons & BUTTON_CONTEXTMENU)) && !contextMenuActive)
	{
		if (CanEnterContextMenu() && contextMenuState != CONTEXTMENU_WAITFORBUTTONRELEASE)
		{
			contextMenuState = CONTEXTMENU_WAITFORINITIALRELEASE;
			contextmenuStartTime = gameLocal.hudTime;
		}
		else
		{
			// Player is in a state where context menu is unavailable. Try to give sufficient audiovisual feedback (but only when they press down the button)
			if (gameLocal.time > contextMenuForbiddenAlertTimer && (oldButtons ^ usercmd.buttons) & BUTTON_CONTEXTMENU)
			{
				//hud->HandleNamedEvent("contextMenuForbidden");
				StartSoundShader(declManager->FindSound("cancel2"), SND_CHANNEL_PDA, 0, false, NULL);
				contextMenuForbiddenAlertTimer = gameLocal.time + 100;
			}			
		}		
	}	
	else if (contextMenuState == CONTEXTMENU_WAITFORINITIALRELEASE)
	{
		//If player releases contextbutton and the press timer is below the threshold time
		if (!(usercmd.buttons & BUTTON_CONTEXTMENU) && contextmenuStartTime < gameLocal.hudTime)
		{			
			contextMenuState = CONTEXTMENU_OFF;

			// SW 6th Feb 2025: We need to confirm that the player is still in a state where they can enter the context menu,
			// otherwise they could potentially perform an action between pressing and releasing the button that would allow them to enter a forbidden state
			if (!armstatsActive && CanEnterContextMenu()) 
			{
				//open map.
				SetArmStatsActive(true);
			}
			else
			{
				//map was open; close map.
				SetArmStatsActive(false);
			}			
		}

		if ((usercmd.buttons & BUTTON_CONTEXTMENU) && contextmenuStartTime + MAP_HOLDTIME_THRESHOLD  < gameLocal.hudTime)
		{
			contextMenuToggle();
		}
	}
	




	if (gameLocal.time > nextContextMenuCloseTime && contextMenuActive && contextMenuState == CONTEXTMENU_DEACTIVATING)
	{
		CloseContextMenu();
	}

	if (contextMenuState == CONTEXTMENU_WAITFORBUTTONRELEASE && !(usercmd.buttons & BUTTON_CONTEXTMENU))
	{
		contextMenuState = CONTEXTMENU_OFF;
	}

	if ((((usercmd.buttons & BUTTON_CONTEXTMENU) && !(oldButtons & BUTTON_CONTEXTMENU)) 
			|| ((usercmd.buttons & BUTTON_QUICKTHROW) && !(oldButtons & BUTTON_QUICKTHROW)))
		&& contextMenuActive && gameLocal.hudTime > contextmenuStartTime + 100)
	{
		if (eventlogMenuActive)
		{
			EventlogMenuOpen(false); //close eventmenu, if it's up.
		}
		else
		{
			//Context menu close button. This gets called when the player presses tab to EXIT the contextmenu.
			ContextmenuConfirm(false); //Cancel out the contextmenu.
			StartSound("snd_cancel", SND_CHANNEL_ANY);
			contextMenuState = CONTEXTMENU_WAITFORBUTTONRELEASE;
		}
	}


	UpdateContextMenuSound();

	//BC WEAPON RELOAD
	if (usercmd.buttons & BUTTON_RELOAD && mechTransitionState == MECHTRANSITION_NONE)
	{
		//Player is pressing the reload button.
		if (((oldButtons ^ usercmd.buttons) & BUTTON_RELOAD))
		{
			reloadButtonTimer = gameLocal.time;
		}
		
		if (gameLocal.time > reloadButtonTimer + RELOADBUTTON_THRESHOLDTIME)
		{
			//Button held. Player wants to check the magazine count.
			InspectMagazine(true);
		}

		//kill the button prompt.
		buttonpromptType = -1;
	}
	else if (reloadButtonTimer > 0)
	{
		//Player has released the reload button.
		if (gameLocal.time <= reloadButtonTimer + RELOADBUTTON_THRESHOLDTIME)
		{
			//Quick tap. Reload gun.
			Reload();
		}
		else
		{
			//End the magazine check.
			InspectMagazine(false);
		}

		reloadButtonTimer = 0;
	}

	if (usercmd.buttons & BUTTON_RACKSLIDE && mechTransitionState == MECHTRANSITION_NONE )
	{
		if (((oldButtons ^ usercmd.buttons) & BUTTON_RACKSLIDE))
		{
			rackslideButtonTimer = gameLocal.time;
		}

		if (gameLocal.time > rackslideButtonTimer + RELOADBUTTON_THRESHOLDTIME)
		{
			//Button held. Inspect the chamber.
			InspectChamber(true);
		}

		//kill the button prompt.
		buttonpromptType = -1;
	}
	else if (rackslideButtonTimer > 0)
	{
		//Player has released rackslide button.

		if (gameLocal.time <= rackslideButtonTimer + RELOADBUTTON_THRESHOLDTIME)
		{
			//Quick tap. Rack the slide.

			if (weapon.IsValid())
			{
				if (weapon.GetEntity()->spawnArgs.GetBool("rackable", "1"))
				{
					RackTheSlide();
				}
			}
		}
		else
		{
			//Button hold. End the chamber inspection.
			InspectChamber(false);
		}

		rackslideButtonTimer = 0;
	}


	//BC HEALTH RECHARGE.
	UpdateHealthRecharge();
	


	//BC UPDATE DOWNED STATE LOGIC.
	if (inDownedState)
	{
		//Downed meter logic.
		if (gameLocal.time > downedTickTimer && health > 0)
		{
			if (bloodbagState == BLOODBAGSTATE_TRANSFUSING)
			{
				downedTickTimer = gameLocal.time + HEALTH_BLOODBAG_RECHARGERATE;
				health = Min(health + HEALTH_BLOODBAG_RECHARGEPERTICK, 100);

				if (health >= 100)
				{
					//bloodbag has filled player full of blood. Exit the bloodbag state.

					const idDeclEntityDef *debrisDef;
					idEntity *bloodbagRagdoll;

					inDownedState = false;
					viewAngles.roll = 0;
					SetViewAngles(idAngles(0, viewAngles.yaw, 0));
					bloodbagState = BLOODBAGSTATE_EXITING;

					//activate health recharge.
					health = maxHealth - (GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK); //max health.
					healthrechargeTimer = gameLocal.time;
					savingthrowState = SAVINGTHROW_AVAILABLE; //make saving throw immediately available again.

					hud->HandleNamedEvent("fullofblood");

					bloodbagMesh->Event_PlayAnim("lower", 1);
					bloodbagTimer = gameLocal.time;
					bloodbagMesh->StopSound(SND_CHANNEL_BODY3, false);

					//Spawn the ragdoll.
					debrisDef = gameLocal.FindEntityDef("env_bloodbag_ragdoll", false);
					if (debrisDef)
					{
						gameLocal.SpawnEntityDef(debrisDef->dict, &bloodbagRagdoll, false);
						if (bloodbagRagdoll)
						{
							idVec3 right;
							viewAngles.ToVectors(NULL, &right, NULL);

							bloodbagRagdoll->SetOrigin(GetPhysics()->GetOrigin() + idVec3(0, 0, 16) + (right * -20));
							bloodbagRagdoll->GetPhysics()->SetLinearVelocity( idVec3( 0, 0, 64));
							bloodbagRagdoll->PostEventMS(&EV_Remove, 60000);
						}
					}

					//Force healthbar to appear after bloodbag sequence.
					ForceShowHealthbar(0);

					SayVO_WithIntervalDelay_msDelayed("snd_vo_bloodfill", 300);
				}
			}
			else
			{
				//Update the blood bleedout.
				

				int scaledBleedoutRate = DOWNED_TICKTIME;

				//Bleedout rate dramatically decreases when you're down to low blood.
				if (health <= 10)
					scaledBleedoutRate *= DOWNED_TICKTIME_MULTIPLIER_CRITICALHEALTH;
				else if (health <= 30)
					scaledBleedoutRate *= DOWNED_TICKTIME_MULTIPLIER_LOWHEALTH;
					

				//int scaledBleedoutRate = 200; uncomment this if you want bleedout to be constant.


				downedTickTimer = gameLocal.time + scaledBleedoutRate;

				//ignore bleedout damage if player is currently attaching bloodbag to self.
				if (bloodbagState == BLOODBAGSTATE_ACTIVATING /*&& health <= 10*/)
				{
					//If putting on bloodbag, then be nice and ignore damage.
				}
				else
				{
					//Normal DOT blood loss damage.
					Damage(NULL, NULL, vec3_zero, "damage_downed_dot", 1.0f, INVALID_JOINT);
				}
			}
		}

		//Create bloody mess when losing blood. Leave a huge blood trail.
		if (gameLocal.time > downedDecalTimer && bloodbagState != BLOODBAGSTATE_TRANSFUSING)  //don't do bloodtrail if currently using bloodbag.
		{
			float distToLastPos;

			downedDecalTimer = gameLocal.time + 600;

			distToLastPos = (lastDownedPlayerPosition - GetPhysics()->GetOrigin()).Length();

			if (distToLastPos >= 30 && g_bloodEffects.GetBool()) //only do blood decal if position has changed. We don't want to just pile on decals if player is standing still.
			{
				//Project blood decal.
				trace_t floorPos;

				idVec3 bloodStartPos = this->GetPhysics()->GetOrigin() + viewAxis[0].ToAngles().ToForward() * 16;

				gameLocal.clip.TracePoint(floorPos, bloodStartPos + idVec3(0, 0, 8), bloodStartPos + idVec3(0, 0, -32), MASK_SOLID, this);
				gameLocal.ProjectDecal(floorPos.endpos, -floorPos.c.normal, 8.0f, true, 32 + (gameLocal.random.RandomFloat() * 64.0f), "textures/decals/bloodsplat02");
			}

			lastDownedPlayerPosition = GetPhysics()->GetOrigin();

			SayVO_WithIntervalDelay("snd_vo_idledowned");
		}

		if (defibAvailable)
		{
			if (gameLocal.time > defibButtonTimer)
			{
				defibButtonTimer = gameLocal.time + DF_BUTTONTICKINTERVAL;

				if (usercmd.upmove > 0)
				{
					defibButtonCount += 2;

					if (!defibButtonState)
					{
						defibButtonState = true;
						StartSound("snd_defibbutton", SND_CHANNEL_RADIO);
					}
				}
				else
				{
					defibButtonCount--;
					
					if (defibButtonState)
					{
						defibButtonState = false;
						StopSound(SND_CHANNEL_RADIO);
					}
				}

				defibButtonCount = idMath::ClampInt(0, DF_BUTTONPIPS, defibButtonCount);
				
				float defibbuttonLerp = defibButtonCount / (float)DF_BUTTONPIPS;
				hud->SetStateFloat("defibbuttonlerp", defibbuttonLerp);

				if (defibButtonCount >= DF_BUTTONPIPS)
				{
					//Activate the defib.
					ActivateDefib();
				}
			}

			
		}
	}


	//BC UPDATE CONDITIONS.
	UpdatePlayerConditions();


	//BC HUD HEALTHBAR RED-TAKEDAMAGE FEEDBACK
	UpdateHealthbarAnimation();


	//update sneezing.
	//detect if player is done being in confined tunnel. In which case, enter sneeze lower state.
	//if ((gameLocal.time > confinedstateTimer + SNEEZETRIGGER_UPDATERATE + 100) && (sneezeState != SNEEZESTATE_LOWERING && sneezeState != SNEEZESTATE_RESETTING))
	//{
	//	if (sneezeState == SNEEZESTATE_SNEEZING)
	//		sneezeState = SNEEZESTATE_RESETTING;
	//	else
	//		sneezeState = SNEEZESTATE_LOWERING;
	//
	//	nextSneezeTimer = gameLocal.time;
	//}


	if (sneezeState == SNEEZESTATE_ACCUMULATING)
	{
		//Player is in the dusty zone.
		
		if (gameLocal.time  > confinedstateTimer + SNEEZETRIGGER_UPDATERATE + 300 && gameLocal.time > nextSneezeTimer)
		{
			//Player has exited the dusty zone.
			sneezeState = SNEEZESTATE_LOWERING;
			nextSneezeTimer = gameLocal.time + 10;
		}

		if (gameLocal.time > confinedstateTimer  && sneezeValue >= 50 && gameLocal.time > sneezeVOTimer)
		{
			idStr voLineToPlay = "";

			if (sneezeValue >= 90)
				voLineToPlay = "snd_sneeze90";				
			else if (sneezeValue >= 75)
				voLineToPlay = "snd_sneeze75";
			else if (sneezeValue >= 50)
				voLineToPlay = "snd_sneeze50";

			if (voLineToPlay.Length() > 0)
			{
				if (gameLocal.voManager.SayVO(this, voLineToPlay.c_str(), VO_CATEGORY_BARK) > 0)
				{
					//line was played. Set the cooldown timer.
					#define SNEEZEVO_INTERVALMIN 11000
					#define SNEEZEVO_INTERVALMAX 14000


					#define SNEEZEVO_INTERVALMIN_UNCONFINED 3000
					#define SNEEZEVO_INTERVALMAX_UNCONFINED 5000

					int sneezeVoDelay = (inConfinedState) ? gameLocal.random.RandomInt(SNEEZEVO_INTERVALMIN, SNEEZEVO_INTERVALMAX) : gameLocal.random.RandomInt(SNEEZEVO_INTERVALMIN_UNCONFINED, SNEEZEVO_INTERVALMAX_UNCONFINED);
					sneezeVOTimer = gameLocal.time + sneezeVoDelay;
				}
			}
		}
	}
	else if (sneezeState == SNEEZESTATE_RESETTING)
	{
		//TODO: render the sneeze meter differently when resetting.
		if (gameLocal.time > nextSneezeTimer)
		{
			sneezeValue -= 3;
			nextSneezeTimer = gameLocal.time + 10;

			if (sneezeValue <= 1)
			{
				sneezeValue = 0;
				sneezeState = SNEEZESTATE_ACCUMULATING;
			}
		}
	}
	else if (sneezeState == SNEEZESTATE_LOWERING)
	{
		if (gameLocal.time > nextSneezeTimer)
		{
			sneezeValue -= 1;
			nextSneezeTimer = gameLocal.time + 100;

			//If player re-enters a dusty zone.
			if (confinedstateTimer >= gameLocal.time)
			{
				sneezeState = SNEEZESTATE_ACCUMULATING;
			}

			if (sneezeValue <= 1)
			{
				sneezeValue = 0;
				sneezeState = SNEEZESTATE_ACCUMULATING;
			}
		}
	}
	else if (sneezeState == SNEEZESTATE_SNEEZING)
	{
		if (gameLocal.time > nextSneezeTimer)
		{
			sneezeState = SNEEZESTATE_RESETTING;
			nextSneezeTimer = gameLocal.time + 10;
		}
	}



	//SAVING THROWS

	if (savingthrowState == SAVINGTHROW_ACTIVE)
	{
		if (gameLocal.time - lastSavingThrowTime > SAVINGTHROW_SAVETIME)
		{
			savingthrowState = SAVINGTHROW_COOLDOWN;
			lastSavingThrowTime = gameLocal.time;
		}
	}
	else if (savingthrowState == SAVINGTHROW_COOLDOWN)
	{
		if (gameLocal.time - lastSavingThrowTime > SAVINGTHROW_RESETTIME)
		{
			savingthrowState = SAVINGTHROW_AVAILABLE;
		}
	}

	//Baffle sound bubble.
	isBaffled = gameLocal.IsBaffled(GetEyePosition());

	if (isBaffled > 0)
	{
		//Enter the baffled state.

		if (isBaffled == BAFFLE_CAMOUFLAGED && lastBaffleState != BAFFLE_CAMOUFLAGED)
		{
			lastBaffleState = BAFFLE_CAMOUFLAGED;
			gameSoundWorld->FadeSoundClasses(0, -60, .6f); //soundclass, fade to DB, fadetime.
			gameSoundWorld->FadeSoundClasses(1, 0, .1f);
		}
		else if (isBaffled == BAFFLE_MUTE && lastBaffleState != BAFFLE_MUTE)
		{
			lastBaffleState = BAFFLE_MUTE;
			gameSoundWorld->FadeSoundClasses(0, -60, .6f); //soundclass, fade to DB, fadetime.
			gameSoundWorld->FadeSoundClasses(1, -60, .6f); //soundclass, fade to DB, fadetime.
			StartSound("snd_enterbubble", SND_CHANNEL_HEART, 0, false, NULL);
		}
	}
	else if (!isBaffled && lastBaffleState)
	{
		//Exit the baffled state.		
		gameSoundWorld->FadeSoundClasses(0, 0, .1f);
		gameSoundWorld->FadeSoundClasses(1, 0, .1f);

		if (lastBaffleState == BAFFLE_MUTE)
		{
			StartSound("snd_exitbubble", SND_CHANNEL_HEART, 0, false, NULL);
		}

		lastBaffleState = 0;
	}
	

	hud->SetStateInt("baffled", isBaffled);

	if (lastConfinedState != inConfinedState)
	{
		if (inConfinedState)
		{
			//player is ENTERING a confined/hiding state. Check if any AI can see player...			
			StartSound("snd_confinedenter", 0, SND_CHANNEL_ANY, false, NULL);			

			if (gameLocal.GetAmountEnemiesSeePlayer(true) > 0)
			{
				gameLocal.GetLocalPlayer()->confinedStealthActive = false; //AI saw player enter confined/hiding state. Turn off confined stealth.
			}
		}

		lastConfinedState = inConfinedState;


        //update the status effect on the hud.
		//BC disable this, as it kinda stomps on the lightmeter system...
        //hud->SetStateBool("cond_confinedstealth", (inConfinedState && confinedStealthActive));
        
	}

	if (inConfinedState)
	{
		bool touchingConfinedTrigger = false;
		
		int amountAngleLocks = 0;
		int amountAngleNoLock = 0;
		int currentBaseAngle = 0;
		

		
		//Handle sound fx.
		if (AI_ONGROUND && gameLocal.time > confinedRustlesoundTimer && this->physicsObj.IsCrouching() && !peekObject.IsValid())
		{
			

			idVec3 currentPos = idVec3((int)GetPhysics()->GetOrigin().x, (int)GetPhysics()->GetOrigin().y, (int)GetPhysics()->GetOrigin().z);

			//If position has changed OR player has turned head quickly.
			if ((currentPos != confinedRustlesoundLastPos && (usercmd.forwardmove != 0 || usercmd.rightmove != 0)) || (fabs(currentYawDelta) >= TURNINGDELTA_SOUNDTHRESHOLD))
			{
				bool tarpSound = false;

				confinedRustlesoundLastPos = currentPos;

				if (!confinedAngleLock)
				{
					trace_t confinedTr;

					gameLocal.clip.TracePoint(confinedTr, this->GetPhysics()->GetOrigin() + idVec3(0, 0, 1), this->GetPhysics()->GetOrigin() + idVec3(0, 0, -4), MASK_SOLID, this);

					if (confinedTr.fraction < 1)
					{
						const idMaterial *material;
						material = confinedTr.c.material;

						if (material != NULL)
						{
							if (material->GetSurfaceType() == SURFTYPE_FABRIC)
							{
								tarpSound = true;
							}
						}
					}					
				}
				
				StartSound(tarpSound ? "snd_confinedtarp" : "snd_confinedmove", SND_CHANNEL_ANY, 0, false, NULL);
			}

			confinedRustlesoundTimer = gameLocal.time + 400; //plays less often than the normal shuffle sounds.
		}
		



		//Handle the confined trigger system.
		if (gameLocal.time > confinedstateTimer)
		{
			bool updateSneeze = false;
			int amountPurgeTriggers = 0;

			//Determine if player is/isn't touching a confined trigger. We only care if player eyeball is in confined space.
			confinedstateTimer = gameLocal.time + CONFINED_UPDATETIME;

			for (idEntity* entity = gameLocal.confinedEntities.Next(); entity != NULL; entity = entity->confinedNode.Next())
			{
				if (!entity)
					continue;

				if (entity == NULL)
					continue;

				if (entity->IsHidden() || entity->entityNumber <= 0 || entity->entityNumber >= MAX_GENTITIES - 1 || entity->entityDefNumber < -1 || !entity->name || !entity->GetPhysics())
					continue;

				if (!entity->IsType(idTrigger_confinedarea::Type))
					continue;

				if (!entity->GetPhysics()->GetAbsBounds().ContainsPoint(GetEyePosition()))
					continue;

				touchingConfinedTrigger = true;
				
				if (entity->spawnArgs.GetBool("confined"))
				{
					amountAngleLocks++;
				
					//Get the angle to lock at.
					currentBaseAngle = static_cast<idTrigger_confinedarea*>(entity)->adjustedBaseAngle;
				}
				else
				{
					amountAngleNoLock++;
				}

				if (!updateSneeze && entity->spawnArgs.GetFloat("sneezemultiplier") > 0)
				{
					updateSneeze = true;
				}

				if (entity->spawnArgs.GetBool("purge"))
				{
					amountPurgeTriggers++;
				}
			}

			confinedType = (amountPurgeTriggers > 0) ? CONF_VENT : CONF_HIDETRIGGER;

			if (touchingConfinedTrigger)
			{
				if (amountAngleNoLock > 0)
				{
					if (confinedAngleLock)
					{
						StartSound("snd_confinedexit", 0, SND_CHANNEL_ANY, false, NULL);
					}

					//The no-angle lock confined trigger overrides the angle-lock trigger.
					hud->SetStateInt("confined", 0);
					confinedAngleLock = false;
				}
				else if (amountAngleLocks > 0)
				{
					//if (!confinedAngleLock)
					//{
					//	StartSound("snd_confinedenter", 0, SND_CHANNEL_ANY, false, NULL);
					//}

					//We're locking the confined angle.
					hud->SetStateInt("confined", 1);
					// Don't update the confined angle if we're peeking as this can flip it
					if ( !peekObject.IsValid() ) {
						confinedAngle = currentBaseAngle;
					}
					confinedAngleLock = true;


				}
			}
			else
			{
				//Player isn't touching a confined trigger. Deactivate the confined system.
				inConfinedState = false;
				confinedAngleLock = false;
				hud->SetStateInt("confined", 0);
			}


			if (gameLocal.time > sneezeUpdateTimer)
			{
				if (touchingConfinedTrigger)
				{
					sneezeUpdateTimer = gameLocal.time + 300;

					if (updateSneeze)
					{
						SetSneezeDelta(true);
					}
				}
				else
				{
					if (sneezeValue > 0)
					{
						sneezeValue -= 1;
					}

					nextSneezeTimer = gameLocal.time + 100;
				}
			}
		}

		if (confinedAngleLock)
		{
			//Update the hud angle ui.
			float absYaw = viewAngles.yaw;
			float absConfine = confinedAngle;
			if (absYaw + 180.0f < absConfine) {
				absYaw += 360.0f;
			}
			else if (absConfine + 180.0f < absYaw) {
				absConfine += 360.0f;
			}
			float arcSign = absYaw < absConfine ? -1.0f : 1.0f;
			float deltaFromCenter = idMath::Fabs(absYaw - absConfine);

			float arcRadius = CONFINED_VIEWARC / 2.0f;
			float arcLerp = deltaFromCenter / arcRadius;

			float arcValue = idMath::Lerp(0, 90, arcLerp)*arcSign;

			hud->SetStateFloat("confinedAngle", arcValue);
		}


		//Spawn confined dust.
		if (amountAngleLocks > 0 || confinedType == CONF_VENT)
		{
			UpdateConfinedDust();
		}

		hud->SetStateBool("in_dust", true);
	}
    else
    {
        hud->SetStateBool("in_dust", false);
    }

	//Confined UI.
	hud->SetStateBool("drawConfinedUI", (confinedAngleLock && !peekObject.IsValid()));

    //Particles when in zero g.
    if ((airless && !r_skipspaceparticles.GetBool()) || forceSpaceParticles)
    {
		const char* spaceParticleName = forceSpaceParticles ? "spaceparticles64_forcezerog.prt" : "spaceparticles64.prt";

        if (gameLocal.time > spaceparticleTimer && !peekObject.IsValid())
        {
            spaceparticleTimer = gameLocal.time + 300;

			trace_t spacedustTr;
			gameLocal.clip.TracePoint(spacedustTr, firstPersonViewOrigin, firstPersonViewOrigin + viewAngles.ToForward() * 192, MASK_SOLID, this);
			if (spacedustTr.fraction >= 1)
			{
				//only spawn spacedust if area is completely clear.
				idVec3 frontOfEyes = firstPersonViewOrigin + viewAngles.ToForward() * (80 + gameLocal.random.RandomInt(128));
				gameLocal.DoParticle(spaceParticleName, frontOfEyes, idVec3(gameLocal.random.RandomInt(359), gameLocal.random.RandomInt(359), gameLocal.random.RandomInt(359)), true, true);

				// Spawn additional particles randomly in the sphere around the player
				for ( int i = 0; i < 6; i++ ) {
					idVec3 spacedustPos = gameLocal.random.RandomPointInSphere( firstPersonViewOrigin, 150.0f );
					if ( gameLocal.GetAirlessAtPoint( spacedustPos ) ) {
						gameLocal.DoParticle( spaceParticleName, spacedustPos,
							idVec3( gameLocal.random.RandomInt( 359 ), gameLocal.random.RandomInt( 359 ), gameLocal.random.RandomInt( 359 ) ), true, true );
					}
				}
			}

			//always spawn 1 particle directly on player eyeball.
			gameLocal.DoParticle(spaceParticleName, firstPersonViewOrigin, idVec3(gameLocal.random.RandomInt(359), gameLocal.random.RandomInt(359), gameLocal.random.RandomInt(359)), true, true);
        }
    }

	UpdateZoomMode();

	if (g_ruler.GetInteger() > 0)
	{
		if (!lastRulerState)
		{
			lastRulerState = true;
			ruler.SetStartingPoint(this);
		}

		ruler.Update(this);
	}
	else if (lastRulerState)
	{
		lastRulerState = false;
	}

	//BC disable trash chute prompt.
	//trashchuteFocus = IsPlayerLookingATrashchute();

	//uncomment this for the weapon select pause.
	//if (isWeaponselectPaused && gameLocal.hudTime > weaponselectPauseTimer)
	//{
	//	isWeaponselectPaused = false;
	//	gameLocal.menuPause = false;
	//}

	if (healthcloudActive && gameLocal.time >= healthcloudTimer)
	{
		healthcloudActive = false;
	}

	if (armstatsState != ARMST_DORMANT)
	{
		// Slightly adjust position of arm when zoomed in so it centers
		const idVec3 ARM_ZOOM_OFFSET( -0.1f, 0.0f, 0.7f );
		idVec3 armStatsPos = firstPersonViewOrigin;
		int currentTime = gameLocal.spectatePause ? gameLocal.hudTime : gameLocal.time;
		float adjustPct = zoomFov.GetCurrentPct( currentTime );
		adjustPct = zoommodeActive ? adjustPct : 1.0f - adjustPct;
		idVec3 forward, up;
		viewAngles.ToVectors( &forward, NULL, &up );
		armStatsPos += (forward * ARM_ZOOM_OFFSET.x * adjustPct) + (up * ARM_ZOOM_OFFSET.z * adjustPct);

		armstatsModel->SetOrigin( armStatsPos );
		armstatsModel->SetAxis(viewAngles.ToMat3());
	}

	if (armstatsState == ARMST_RAISING)
	{
		if (gameLocal.time >= armstatsTimer + ARMSTAT_RAISETIME)
		{
			armstatsState = ARMST_ACTIVE;
			armstatsTimer = gameLocal.time;
			armstatsModel->Event_PlayAnim("idle", 4, true);
		}
	}
	else if (armstatsState == ARMST_LOWERING)
	{
		if (gameLocal.time >= armstatsTimer + ARMSTAT_LOWERTIME)
		{
			armstatsModel->Hide();
			armstatsState = ARMST_DORMANT;
		}
	}

	if (!oxygenmeterIsFaded && gameLocal.time >= oxygenmeterFadeTimer && airTics >= pm_airTics.GetInteger())
	{
		oxygenmeterIsFaded = true;
		hud->HandleNamedEvent("oxygenmeter_fadeout");
	}

	if (jockeyState == JCK_ATTACHED && meleeTarget.IsValid())
	{
		idVec3 playerDesiredDir = gameLocal.GetLocalPlayer()->GetCameraRelativeDesiredMovement();

		if (playerDesiredDir == vec3_zero)
		{
			//no direction on jockey. don't render it.
			jockeyArrow->SetColor(0, 0, 0);
		}
		else
		{
			//#define JOCKEYARROW_HEIGHT 48
			//idAngles arrowdir = idAngles(0, playerDesiredDir.ToYaw(), 0);
			//jockeyArrow->SetOrigin(meleeTarget.GetEntity()->GetPhysics()->GetOrigin() + idVec3(0, 0, JOCKEYARROW_HEIGHT));
			//jockeyArrow->SetAxis(arrowdir.ToMat3());
			//jockeyArrow->SetColor(idVec4(1, 1, 1, 1));

			jockeyArrow->SetColor(0, 0, 0); //BC 3/23/2023 don't draw the jockey arrow.
		}		
	}


	if (cond_gascloud)
	{
		if (gameLocal.time >= gascloud_coughtimer)
		{
			gascloud_coughtimer = gameLocal.time + 500;
			
			//player is doing gascloud cough. spawn interestpoint.
			gameLocal.SpawnInterestPoint(this, this->GetEyePosition(), "interest_gascough");
		}

		if (gameLocal.time >= gascloud_timer)
		{
			SetGascloudState(false); //end gas cloud state.
		}
	}


	if (listenmodeActive)
	{
		//update the meter.
		float lerp = (gameLocal.time - listenmodeVisualizerTime) / (float)LISTENMODE_METERTIME;		
		hud->SetStateFloat("listenmeter", lerp);

		if (lerp >= 1 && !listenProbemodeActive)
		{
			hud->SetStateBool("listenfull", true);
			listenProbemodeActive = true;

			hud->HandleNamedEvent("listenboxflash"); //make the 'enemies in next room' ui do a little flash animation
		}

		if (listenProbemodeActive)
		{
			if (gameLocal.time > listenProbeTimer)
			{
				listenProbeTimer = gameLocal.time + LISTENMODE_PROBEUPDATETIME;

				int enemyCount = 0;
				idLocationEntity *locEnt = gameLocal.LocationForPoint(listenmodePos);
				if (locEnt)
				{
					for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
					{
						if (!entity || entity->team == this->team || entity->health <= 0)
							continue;

						idLocationEntity *enemyLoc = gameLocal.LocationForEntity(entity);

						if (enemyLoc == NULL)
							continue;

						if (enemyLoc->entityNumber == locEnt->entityNumber)
						{
							enemyCount++;
						}
					}
				}

				hud->SetStateInt("listenprobenumber", enemyCount);
			}
		}
	}

	if (fovLerpState == FOVLERP_LERPING)
	{
		float lerp = (gameLocal.time - fovLerpStartTime) / (float)(fovLerpTimer);
		lerp = idMath::CubicEaseInOut(lerp);

		if (gameLocal.time >= fovLerpStartTime + fovLerpTimer) //check if lerp is done.
		{
			if (fovLerpEnd == 0)
			{
				fovLerpState = FOVLERP_NONE; //Fov has returned back to zero. Turn off the fov lerp system.
			}
			else
				fovLerpState = FOVLERP_LOCKED; //Fov lerp is done, but the final fov is NOT zero. So, leave the fov lerp system on. It just remains at fovlerpCurrent and doesn't do anything.

			lerp = 1.0f;
		}

		fovLerpCurrent = idMath::Lerp(fovLerpStart, fovLerpEnd, lerp);
	}

	UpdatePlayerLookTriggers();
	UpdatePlayerLocboxTriggers();

	DebugUnassignedLocations();

	if (airless && GetFallenState())
	{
		SetFallState(false, false);
		physicsObj.SetImmediateExitFallState();
	}

	hud->SetStateInt("catkeys", inventory.catkeys);

	if (contextMenu != NULL)
		contextMenu->SetStateInt("catkeys", inventory.catkeys);


	if (contextMenu != NULL && contextMenuActive)
	{
		contextMenu->SetStateInt("sakkeys", HasInventoryItem("shipkey"));
	}



	//weapon inspect Vo.
	if (weapon.IsValid() && !hasSaidChambercheckVO)
	{
		if (weapon.GetEntity()->IsInspectingChamber() && currentWeaponSlot >= 0 && weapon.GetEntity()->ClipSize() > 0)
		{
			if (gameLocal.time > vo_chamberchecktimer)
			{
				hasSaidChambercheckVO = true;

				bool chambered = weapon.GetEntity()->Event_RoundIsChambered();
				gameLocal.GetLocalPlayer()->SayVO_WithIntervalDelay(chambered ? "snd_vo_chamber_loaded" : "snd_vo_chamber_empty");
			}
		}
	}

	if (weapon.IsValid() && !hasSaidReloadcheckVO)
	{
		if (weapon.GetEntity()->IsInspectingMagazine() && currentWeaponSlot >= 0 && weapon.GetEntity()->ClipSize() > 0)
		{
			if (gameLocal.time > vo_reloadchecktimer)
			{
				hasSaidReloadcheckVO = true;

				idStr ammoStr = "";
				int roundsLeft = weapon.GetEntity()->AmmoInClip();
				
				if (roundsLeft <= 0)
					ammoStr = "snd_vo_ammo_none";
				else if (roundsLeft <= 3)
					ammoStr = "snd_vo_ammo_few";
				else if (roundsLeft <= 7)
					ammoStr = "snd_vo_ammo_several";
				else
					ammoStr = "snd_vo_ammo_lot";
				

				if (ammoStr.Length() > 0)
				{
					gameLocal.GetLocalPlayer()->SayVO_WithIntervalDelay(ammoStr.c_str());
				}
			}
		}
	}

	//Update pickpocket logic.
	if (pickpocketState == PP_PICKING)
	{
		bool someoneSuspicious = false;
		for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
		{
			if (!entity->IsActive() || entity->IsHidden() || entity == this || entity->health <= 0 || entity->team != TEAM_ENEMY)
				continue;
			
			if (!entity->IsType(idAI::Type))
				continue;

			//See if this entity is valid to draw suspicion stuff for.
			if (entity->IsType(idGunnerMonster::Type))
			{
				if (static_cast<idGunnerMonster *>(entity)->lastEnemySeen.IsValid() && static_cast<idGunnerMonster *>(entity)->CanAcceptStimulus() && static_cast<idGunnerMonster *>(entity)->GetSuspicionCounter() > 0)
				{
					if (static_cast<idGunnerMonster *>(entity)->lastEnemySeen.GetEntity() == this)
					{						
						someoneSuspicious = true;
						break;						
					}
				}
			}
		}

		//do range check.
		bool isInRange = true;
		if (pickpocketEnt.IsValid())
		{
			float dist = GetPickpocketDistance();

			if (dist > PICKPOCKET_RANGE)
			{
				isInRange = false;
			}
		}

		if (someoneSuspicious || !isInRange)
		{
			DoPickpocketFail();
			pickpocketState = PP_NONE;
		}
		else if (pickpocketPipCount >= PICKPOCKET_PIPMAX)
		{
			pickpocketState = PP_NONE;

			//pickpocket successful. Player stole the thing.
			if (pickpocketEnt.IsValid())
			{
				DoPickpocketSuccess(pickpocketEnt.GetEntity());
			}
		}

		if (gameLocal.time > pickpocketPipTimer)
		{
			pickpocketPipTimer = gameLocal.time + PICKPOCKET_PIPINTERVAL;

			if (pickpocketGoodRange)
			{
				pickpocketPipCount++;

				if (pickpocketPipCount > PICKPOCKET_PIPMAX)
				{
					pickpocketPipCount = PICKPOCKET_PIPMAX;
				}
			}
		}		
	}
	
	
	UpdateArmstats();

	if (armstatDoorlockNeedsUpdate && gameLocal.time > armstatDoorlockUpdateTimer)
	{
		armstatDoorlockNeedsUpdate = false;
		UpdateArmstatsDoorlocks();
	}

	if (armstatFuseboxNeedsUpdate && gameLocal.time > armstatFuseboxUpdateTimer)
	{
		armstatFuseboxNeedsUpdate = false;
		UpdateArmstatsFuseboxes();
	}

	

	if (staminaHideDelayMode == STAMBAR_VISIBLE && stamina >= pm_stamina.GetFloat())
	{
		//If stamina is MAXED OUT
		staminaHideTimer = gameLocal.time + STAMINABAR_HIDEDELAYTIME;
		staminaHideDelayMode = STAMBAR_HIDEDELAY;
		StartSound("snd_staminarecharge", SND_CHANNEL_ANY);
	}
	else if (staminaHideDelayMode == STAMBAR_HIDEDELAY)
	{
		if (gameLocal.time >= staminaHideTimer)
		{
			staminaHideDelayMode = STAMBAR_HIDDEN;
			//hud->SetStateBool("showstamina", false);
			hud->HandleNamedEvent("stamina_hide");
		}
	}


	if (g_luminance_showvalue.GetBool())
	{
		common->Printf("%f\n", luminance);
	}

	if (gameLocal.menuPause && static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->GetHightlighterActive())
	{
		//This allows the highlighter to think regardless of whether the world is paused.
		static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->DoHightlighterThink();
	}

	UpdateEmailFullscreen();
	UpdateEmailInboxCheck();

	
	//DebugPrintInventory(1);

	if (isInZoomMode())
	{
		bool playerIsMoving = GetPhysics()->GetLinearVelocity().Length() > 0;
		hud->SetStateBool("playermoving", playerIsMoving);
	}

	if (particlestreamTimer > gameLocal.time && particleStreamEnt != nullptr)
	{
		idVec3 down;
		viewAngles.ToVectors(NULL, NULL, &down);
		idVec3 particlePos = GetEyePosition() + (down * -16);

		idVec3 particleDir = particleStreamDestination - particlePos;
		idAngles particleAng = particleDir.ToAngles();
		particleAng.pitch += 90;

		particleStreamEnt->SetOrigin(particlePos);
		particleStreamEnt->SetAxis(particleAng.ToMat3());
	}
	

	

	//BC Think End
}

void idPlayer::UpdateEmailInboxCheck()
{
	if (!emailInboxCheckActive)
		return;

	if (gameLocal.time < activeEmailInboxTimer)
		return;

	activeEmailInboxTimer = gameLocal.time + 200;

	//Check if any email inboxes have unread emails, that are NOT in the currently-active email inbox.
	bool hasUnreadEmail = HasUnreadEmail_ExceptSpecifiedInbox(currentlyActiveEmailInbox);
	emailFullscreenMenu->SetStateBool("unread_back", hasUnreadEmail);
}

void idPlayer::SetEmailFullscreen(bool active)
{
	if (active)
	{
		//turn on email fullscreen.
		ClearFocus();
		emailFullscreenState = EFS_TRANSITIONON;
		emailFullscreenTimer = gameLocal.time;
		emailFullscreenOriginalPlayerViewangle = viewAngles;

		if (emailFullscreenEnt.IsValid())
		{
			//Lerp camera into the monitor.
			idVec3 forward;
			emailFullscreenEnt.GetEntity()->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, NULL, NULL);
			idVec3 monitorViewPos = emailFullscreenEnt.GetEntity()->GetPhysics()->GetOrigin() + forward * 12;

			idAngles lerpAngle = emailFullscreenEnt.GetEntity()->GetPhysics()->GetAxis().ToAngles();
			lerpAngle.yaw += 180;

			SetViewLerpAngles(lerpAngle, EMAILFULLSCREEN_LERPTIME + 10);
			SetViewposAbsLerp(monitorViewPos, EMAILFULLSCREEN_LERPTIME + 10);
		}
	}
	else
	{
		//turn off email fullscreen.
		emailFullscreenState = EFS_TRANSITIONOFF;
		emailFullscreenTimer = gameLocal.time;

		if (emailFullscreenEnt.IsValid())
		{
			idUserInterfaceLocal* emailUI = static_cast<idUserInterfaceLocal*>(emailFullscreenEnt.GetEntity()->GetRenderEntity()->gui[0]);
			emailUI->GetDesktop()->SetFlag(WIN_NOCURSOR);
			session->SetGUI(NULL, NULL);
			//Lerp camera back to player eyeball.
			idVec3 forward;
			emailFullscreenEnt.GetEntity()->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, NULL, NULL);
			idVec3 monitorViewPos = emailFullscreenEnt.GetEntity()->GetPhysics()->GetOrigin() + forward * 12;

			SetViewLerpAngles(emailFullscreenOriginalPlayerViewangle, EMAILFULLSCREEN_LERPTIME);
			SetViewposAbsLerp2(monitorViewPos, EMAILFULLSCREEN_LERPTIME);
		}
	}
}

void idPlayer::UpdateEmailFullscreen()
{
	if (emailFullscreenState == EFS_OFF)
		return;

	if (emailFullscreenState == EFS_TRANSITIONON)
	{
		if (gameLocal.time >= emailFullscreenTimer + EMAILFULLSCREEN_LERPTIME)
		{
			idUserInterfaceLocal* emailUI = static_cast<idUserInterfaceLocal*>(emailFullscreenEnt.GetEntity()->GetRenderEntity()->gui[0]);
			emailUI->GetDesktop()->ClearFlag(WIN_NOCURSOR);
			emailUI->SetCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //move mouse to screen center.
			oldMouseX = usercmd.mx;
			oldMouseY = usercmd.my;
			session->SetGUI(emailUI, NULL);

			emailFullscreenState = EFS_ACTIVE;
		}
	}
	else if (emailFullscreenState == EFS_TRANSITIONOFF)
	{
		if (gameLocal.time >= emailFullscreenTimer + EMAILFULLSCREEN_LERPTIME)
		{
			emailFullscreenState = EFS_OFF;
		}
	}
}

void idPlayer::UpdateMemoryPalace()
{
	if (memorypalaceState == MEMP_SPAWNDELAY)
	{
		if (!static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->GetPlayerExitedCryopod())
		{
			//if player hasn't exited cryo pod yet, the logic gets weird, so we circumvent that here:
			memorypalaceState = MEMP_NONE;
			DoMemoryPalace();
			return;
		}

		//Do a short delay before entering memory palace, as it's jarring when it immediately appears on button press
		if (gameLocal.time > memorypalaceTimer && GetPhysics()->HasGroundContacts())
		{
			memorypalaceState = MEMP_ACTIVE;
			DoMemoryPalace();
		}
	}
	else if (memorypalaceState == MEMP_ACTIVE)
	{
		//Distance check.
		//idVec3 playerPos = firstPersonViewOrigin;
		//float dist = (playerPos - memorypalacePlayerPos).Length();

		//Dotproduct check.
		#define MEMORYPALACE_DOTPRODUCT_THRESHOLD -.5f
		idAngles playerView = viewAngles;
		playerView.pitch = 0;
		playerView.roll = 0;
		float vdot = DotProduct(memorypalaceForwardView, playerView.ToForward());

		//Turn OFF the memory palace
		if (usercmd.upmove > 0 || usercmd.forwardmove != 0 || usercmd.rightmove != 0 || ((usercmd.buttons & BUTTON_CONTEXTMENU) && !(oldButtons & BUTTON_CONTEXTMENU)) || vdot < MEMORYPALACE_DOTPRODUCT_THRESHOLD)
		{
			ExitMemoryPalace();
		}

		//handle the hud.
		hud->SetStateBool("memp_overview", (zoominspect_LabelmodeActive == false)); //am I in overview, or viewing a single note


		if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
		{
			if (zoominspect_LabelmodeActive)
			{
				//Inspecting an individual note.
				//MarkMemorypalacenoteDone();
				if (zoominspectEntityPtr.IsValid())
				{
					MarkMemorypalacenoteDone(zoominspectEntityPtr.GetEntity());
					return;
				}
			}
			else
			{
				//in overview view.
				if (frobEnt != NULL)
				{
					MarkMemorypalacenoteDone(frobEnt);
					return;
				}
			}
		}
	}

	
	

		
}

void idPlayer::MarkMemorypalacenoteDone(idEntity *ent)
{
	if (!ent->IsType(idNoteWall::Type))
		return;

	static_cast<idNoteWall*>(ent)->SetMarkDoneToggle();
}

void idPlayer::ExitMemoryPalace()
{
	memorypalaceState = MEMP_NONE;
	StartSound("snd_memorypalace_off", SND_CHANNEL_ANY);

	for (idEntity* ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	{
		if (!ent)
			continue;

		if (ent->IsType(idNoteWall::Type))
		{
			if (static_cast<idNoteWall*>(ent)->IsMemorypalaceClone())
			{
				static_cast<idNoteWall*>(ent)->ShowMemoryPalace(false);
			}
		}
	}

	if (memoryLight)
	{
		memoryLight->Off();
	}

	gameLocal.menuPause = false;
	if (gameSoundWorld->IsPaused())
	{
		gameSoundWorld->UnPause();
	}

	zoominspect_LabelmodeActive = false;
	nextContextMenuAvailableTime = gameLocal.time + 300;
}

void idPlayer::ExitLabelinspectMode()
{
	// Don't exit zoom mode unless was a manual trigger
	if (zoomManualInspect)
	{
		zoommodeActive = false;
		zoomCurrentFOV = ZOOM_MAX;
		StartSound("snd_zoomout", SND_CHANNEL_ANY, 0, false, NULL);
		zoomManualInspect = false;
	}
	hud->SetStateBool("showzoomcontrols", true);

	zoominspectEntityPtr.GetEntity()->SetPostFlag(POST_INSPECT_LUMINANCE, false);
	zoominspectEntityPtr = nullptr;
	hud->SetStateBool("zoominspect_draw", false);
	hud->SetStateBool("zoomdesc_draw", false);

	zoominspect_LabelmodeActive = false;

	//Unpause the game.
	if (gameLocal.menuPause && memorypalaceState == MEMP_NONE)
	{
		gameLocal.menuPause = false;
		if (gameSoundWorld->IsPaused())
		{
			gameSoundWorld->UnPause();
		}
	}
	
	if (viewYawLocked || viewPitchLocked)
	{
		SetViewYawLock(false, 0, 0);
		SetViewPitchLock(false, 0, 0);
	}
	
	//Reset viewangles to what they originally were.
	// SM: Don't reset delta view angles here or the first use has bad results
	//deltaViewAngles.roll = 0;
	//deltaViewAngles.yaw = 0;
	//deltaViewAngles.pitch = 0;

	//bool hasRoll = (viewAngles.roll != 0);

	viewAngles.roll = 0;
	viewAngles.yaw = zoominspect_lerpStartAngle.yaw;
	viewAngles.pitch = zoominspect_lerpStartAngle.pitch;

	//if (hasRoll)
	UpdateDeltaViewAngles(viewAngles);
	
	//BC make it look at the last object we inspected
	//unfortunately this isn't working...
	//idVec3 desiredLookDir = zoominspect_LabelmodePosition - GetEyePosition();
	//desiredLookDir.Normalize();
	//gameRenderWorld->DebugArrow(colorGreen, GetEyePosition(), GetEyePosition() + desiredLookDir * 128, 4, 900000);
	//idAngles desiredLookAngle = desiredLookDir.ToAngles();
	//viewAngles.yaw = desiredLookAngle.yaw;
	//viewAngles.pitch = desiredLookAngle.pitch;

	DisplayLocbox("");

}

void idPlayer::ExitIteminspectMode()
{
	zoommodeActive = false;
	zoomCurrentFOV = ZOOM_MAX;

	iteminspectActive = false;
	InspectWeapon(false);

	//Unpause the game.
	gameLocal.menuPause = false;
	if (gameSoundWorld->IsPaused())
	{
		gameSoundWorld->UnPause();
	}

	SetViewYawLock(false, 0, 0);
	SetViewPitchLock(false, 0, 0);

	StartSound("snd_zoomout", SND_CHANNEL_ANY, 0, false, NULL);

	DisplayLocbox("");
}


float idPlayer::GetPickpocketDistance()
{
	if (!pickpocketEnt.IsValid())
		return -1;

	return (pickpocketEnt.GetEntity()->GetPhysics()->GetOrigin() - (GetPhysics()->GetOrigin() + idVec3(0, 0, 36))).Length();
}

void idPlayer::DoPickpocketFail()
{
	if (!pickpocketEnt.IsValid())
		return;

	pickpocketEnt.GetEntity()->StopSound(SND_CHANNEL_PDA);

	idVec3 pickpocketPos = pickpocketEnt.GetEntity()->GetPhysics()->GetOrigin();
	idEntityFx::StartFx(spawnArgs.GetString("fx_pickpocket_fail"), &pickpocketPos, &mat3_identity, NULL, false);	

	gameLocal.GetLocalPlayer()->SetCenterMessage("#str_def_gameplay_pickpocket_fail");
}

void idPlayer::DoPickpocketSuccess(idEntity* ent)
{
	idEntity* bindMaster = ent->GetBindMaster();
	if (bindMaster != NULL)
	{
		//We now know who the player pickpocketed.
		gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_player_pickpocket"), bindMaster->displayName.c_str()), bindMaster->GetPhysics()->GetOrigin());
		statsPickpocketSuccesses++;

		//spawn an interestpoint at player location.
		if (bindMaster->IsType(idGunnerMonster::Type))
		{
			static_cast<idGunnerMonster*>(bindMaster)->DoPickpocketReaction(GetPhysics()->GetOrigin() + idVec3(0, 0, 48));
		}
	}

	idEntityFx::StartFx(spawnArgs.GetString("fx_pickpocket_success"), &ent->GetPhysics()->GetOrigin(), &mat3_identity, NULL, false); //Twinkle particle fx.
	ent->StopSound(SND_CHANNEL_PDA);
	ent->DoFrob(0, this);
}


bool idPlayer::IsFullscreenUIActive() const
{
	return levelselectMenuActive || emailFullscreenState == EFS_ACTIVE || contextMenuActive || eventlogMenuActive;
}

//Make sure to call this AFTER all health values have been calculated.
void idPlayer::UpdateHealthbarAnimation(void)
{

	//do the fade logic
	if (health >= inventory.maxHealth && !healthFadeMaxedBool)
	{
		healthFadeMaxedBool = true;
		healthFadeTimer = gameLocal.time + HEALTHBAR_FADE_DELAYTIME;
	}

	if (healthFadeMaxedBool && gameLocal.time >= healthFadeTimer && !healthbarIsFaded && GetWoundCount() <= 0)
	{
		//Do the healthbar fade.
		healthbarIsFaded = true;
		hud->HandleNamedEvent("healthbar_fadeout");
	}


	if (lastHealthValue != health && (lastHealthState == LASTHEALTH_OFF || lastHealthState == LASTHEALTH_ACTIVE))
	{
		lastHealthTimer = gameLocal.time + 1000;
		lastHealthState = LASTHEALTH_ACTIVE;
		//hud->SetStateInt("player_lasthealth", lastHealthValue);

		float lastHealthPercent = float(lastHealthValue / float(maxHealth));
		lastHealthPercent = Min(lastHealthPercent, 1.0f);
		hud->SetStateFloat("player_lasthealthpercent", lastHealthPercent);

		lastHealthDisplayvalue = lastHealthValue;
		lastHealthValue = health;		
	}

	if (lastHealthState == LASTHEALTH_ACTIVE)
	{
		//Just show the static bar. Wait for timer to expire.
		if (gameLocal.time >= lastHealthTimer)
		{
			lastHealthState = LASTHEALTH_TRANSITIONOFF;
		}
	}
	else if (lastHealthState == LASTHEALTH_TRANSITIONOFF)
	{
		//do animation of bar draining.
		if (gameLocal.time >= lastHealthTimer)
		{
			#define HEALTHDAMAGE_ANIMSPEED 15

			lastHealthTimer = gameLocal.time + HEALTHDAMAGE_ANIMSPEED;
			//hud->SetStateInt("player_lasthealth", lastHealthDisplayvalue);

			float lastHealthPercent = float(lastHealthDisplayvalue / float(maxHealth));
			lastHealthPercent = Min(lastHealthPercent, 1.0f);
			hud->SetStateFloat("player_lasthealthpercent", lastHealthPercent);

			lastHealthDisplayvalue -= .3f;

			if (lastHealthDisplayvalue <= health)
			{
				lastHealthState = LASTHEALTH_OFF;
				//hud->SetStateInt("player_lasthealth", 0); //Hide red bar.

				hud->SetStateFloat("player_lasthealthpercent", 0); //Hide the lasthealth red bar.
			}
		}
	}

	if (bloodbagState == BLOODBAGSTATE_ACTIVATING || bloodbagState == BLOODBAGSTATE_TRANSFUSING || bloodbagState == BLOODBAGSTATE_EXITING || bloodbagState == BLOODBAGSTATE_EXPLODING)
	{
		idVec3 bloodbagPos;
		idAngles viewAng;
		idVec3 particlePos;
		idMat3 particleAxis;

		viewAng = idAngles(viewAngles.pitch, viewAngles.yaw, 0);
		bloodbagPos = GetEyePosition() + (viewAng.ToForward() * 8);

		bloodbagMesh->SetOrigin(bloodbagPos);
		bloodbagMesh->SetAxis(idAngles(-viewAngles.pitch, viewAngles.yaw + 180, 0).ToMat3());
		bloodbagMesh->Show();		

		//Acts weird if we bind it. So we're just going to reposition it every frame.
		bloodbagMesh->GetJointWorldTransform(bloodbagJoint, gameLocal.time, particlePos, particleAxis);		
		bloodbagEmitter->SetAxis(idAngles(110, viewAngles.yaw - 90, 0).ToMat3());
		bloodbagEmitter->SetOrigin(particlePos + idVec3(0, 0, .1f));
		bloodbagEmitter->Show();

		if (weapon.GetEntity() && bloodbagState == BLOODBAGSTATE_ACTIVATING)
		{
			weapon.GetEntity()->LowerWeapon();
		}

		if (bloodbagState == BLOODBAGSTATE_ACTIVATING)
		{
			if (gameLocal.time > bloodbagTimer + HEALTH_BLOODBAG_ANIMATION_ACTIVATIONTIME /*how many seconds is the bloodbag activation sequence. ((Frames / 24 FPS) * 1000.0f)  */)
			{
				bloodbagTimer = gameLocal.time;
				bloodbagState = BLOODBAGSTATE_TRANSFUSING;
				hud->HandleNamedEvent("startBloodrefill");
			
				//Generate data for how long to play the bloodbag drain shader effect.
				bloodbagMaxTime = ((HEALTH_BLOODBAG_RECHARGERATE * HEALTH_BLOODBAG_RECHARGEPERTICK) * (100 - health));
				bloodbagMesh->StartSound("snd_transfuse", SND_CHANNEL_BODY3, 0, false, NULL);

				bloodbagHealth = HEALTH_BLOODBAG_DEFAULTHEALTH;
				hud->SetStateString("bloodbaghealth", "PRISTINE"); //Reset bloodbag health gui.				
			}
		}
		else if (bloodbagState == BLOODBAGSTATE_EXITING)
		{
			float tubelerp = (gameLocal.time - bloodbagTimer) / 1000.0f;
			tubelerp = idMath::ClampFloat(0, 1.0f, tubelerp);
			bloodbagMesh->SetShaderParm(4, idMath::Lerp(-.2f, -1, tubelerp));

			if (gameLocal.time > bloodbagTimer + 1600)
			{
				HideBloodbag();
			}
		}
		else if (bloodbagState == BLOODBAGSTATE_TRANSFUSING)
		{
			//bloodbag: 0 = full,   -.5f = empty.
			float bloodlerp, tubelerp;
			idMat3 bloodbagaxis;
			idVec3 bloodbagBodyPos;
			idAngles viewRight;
			
			bloodlerp = (gameLocal.time - bloodbagTimer) / (float)bloodbagMaxTime;
			bloodlerp = idMath::ClampFloat(0, 1.0f, bloodlerp);
			bloodbagMesh->SetShaderParm(5, idMath::Lerp(-.05f, -.5f, bloodlerp));

			tubelerp = (gameLocal.time - bloodbagTimer) / 3000.0f;
			tubelerp = idMath::ClampFloat(0, 1.0f, tubelerp);
			bloodbagMesh->SetShaderParm(4, idMath::Lerp(0, -.4f, tubelerp));
		}
		else if (bloodbagState == BLOODBAGSTATE_EXPLODING)
		{
			if (gameLocal.time >= bloodbagTimer + 1000)
			{
				HideBloodbag();
			}
		}
	}

	if (mechTransitionState == MECHTRANSITION_PILOTING)
	{
		UpdateMechCockpit();
	}
}

void idPlayer::UpdatePlayerConditions(void)
{
	if (burningTimer > 0 && !AI_HEAL_BURNING)
	{
		//Do the burning damage-over-time to self.
		if (gameLocal.time >= burningDOTTimer)
		{
			burningDOTTimer = gameLocal.time + 500;

			Damage(NULL, NULL, vec3_origin, "damage_fire_dot", 1.0f, 0);
			hud->HandleNamedEvent("cond_firedamage");
		}

		//Check if burn has ended.
		if (gameLocal.time >= burningTimer || airless) //Or, if enter an airless environment.
		{
			//Burn timer has expired, inflict a burn wound.
			SetOnFire(false);
			cond_burnwound++;
			AddToWoundArray(WOUNDIDX_BURN);
		}
	}

	if (cond_glasswound > 0 && !airless && !IsJockeying()) //ignore glasswounds when in zero-g.
	{
		//Glass wound. Take damage when player moves.
		if (glasswoundMoveTimer <= gameLocal.time && (usercmd.forwardmove != 0 || usercmd.rightmove != 0) && AI_ONGROUND)
		{
			idVec3 right;
			trace_t floorPos;
			float decalAngle = (3.14159f / 180.0f) * viewAngles.yaw;

			viewAngles.ToVectors(NULL, &right, NULL);
			gameLocal.clip.TracePoint(floorPos, this->GetPhysics()->GetOrigin() + idVec3(0,0,8) + (right * (glasswoundFoot ? 6 : -6)),
				this->GetPhysics()->GetOrigin() + idVec3(0, 0, -16) + (right * (glasswoundFoot ? 6 : -6)), MASK_SOLID, this);

			glasswoundMoveTimer = gameLocal.time + CONDITION_GLASSWOUND_DAMAGEINTERVAL;

			StartSound("snd_bloodyfootstep", SND_CHANNEL_BODY3, 0, false, NULL);

			//inflict glass wound.
			if (!this->physicsObj.IsCrouching())
			{
				//Clamp the health to be below the max wound count. This is so the player doesn't regen health that is currently being blocked-out by the glasswound.
				int woundcount = GetWoundCount();
				if (health > maxHealth - (woundcount * HEALTH_PER_HEALTHBARBLOCK))
				{
					health = maxHealth - (woundcount * HEALTH_PER_HEALTHBARBLOCK);
				}

				Damage(NULL, NULL, vec3_origin, "damage_glasswound", 1 + gameLocal.random.RandomInt(cond_glasswound), 0);
				hud->HandleNamedEvent("cond_glassdamage");
			}
			
			gameLocal.ProjectDecal(floorPos.endpos, -floorPos.c.normal, 8.0f, true, 16.0f, glasswoundFoot == 0 ? spawnArgs.GetString("mtr_bloodfoot1") : spawnArgs.GetString("mtr_bloodfoot2") , -decalAngle + 1.57f);

			glasswoundFoot = !glasswoundFoot;
		}
	}

	if (deafenState == DEAFEN_INITIALDELAY)
	{
		if (gameLocal.time >= deafenTimer + 1500)
		{
			deafenState = DEAFEN_FADINGTONORMAL;
			deafenTimer = gameLocal.time;
			gameSoundWorld->FadeSoundClasses(0, 0, 6.0f);
		}		
	}
	else if (deafenState == DEAFEN_FADINGTONORMAL)
	{
		if (deafenTimer >= deafenTimer + 6000)
		{
			deafenState = DEAFEN_NONE;
		}
	}
	
	if (gameLocal.time > lastChemDamageTime + 600 && playerInChemTimer > 0)
	{
		playerInChemTimer = 0;
	}


	if (healState != HEALSTATE_NONE)
	{
		if (!AI_HEAL_BULLETPLUCK && !AI_HEAL_SHRAPNEL && !AI_HEAL_BURNING && !AI_HEAL_GLASSWOUND)
		{
			healState = HEALSTATE_NONE; //If not in any heal state, then revert to healstate_none.
		}
	}

	if (cond_smelly > 0 && !airless)
	{
		//player is smelly. and is in an indoor / non-zero-G space.

		if (gameLocal.time > smellyTimer)
		{
			idVec3 smellPosition;
			float distToLastSmellPosition;

			smellyTimer = gameLocal.time + SMELLY_SPAWNTIME;

			//Spawn a smelly cloud at the player position.
			smellPosition = GetPhysics()->GetAbsBounds().GetCenter();

			bool playerInVent = inConfinedState && confinedType == CONF_VENT;
			
			gameLocal.SpawnInterestPoint(this, smellPosition,
				(playerInVent) ?
				spawnArgs.GetString("def_smellyinterest_vent", "interest_smelly_vent")
				: spawnArgs.GetString("def_smellyinterest", "interest_smelly"));

			distToLastSmellPosition = (lastSmellPosition - smellPosition).LengthFast();
			
			if (distToLastSmellPosition > 16) //Only spawn particle effect if the player has moved a distance. This is to prevent a ton of particle fx stacking on top of each other, if the player doesn't move.
			{
				idEntityFx::StartFx(spawnArgs.GetString("fx_smellcloud"), &smellPosition, &mat3_identity, NULL, false);
			}

			lastSmellPosition = smellPosition;
		}
	}
}


void idPlayer::UpdateHealthRecharge(void)
{
	int adjustedMaxHealth = inventory.maxHealth;

	if (health <= 0 || defibState != DEFIB_NONE || inDownedState)
		return;

	if (healthcloudActive)
	{
		//This regenerates health to the maximum.
		adjustedMaxHealth -= GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK; //HEALTH_PER_HEALTHBARBLOCK = maxhealth / number of health blocks (5)
	}
	else
	{
		adjustedMaxHealth = (health + 9) / 10 * 10; //This regenerates health up to the current 'block' of health, 10,20,30,40,50
		adjustedMaxHealth = Min(adjustedMaxHealth, inventory.maxHealth);
	}

	if (health < adjustedMaxHealth)
	{
		if (gameLocal.time >= healthrechargeTimer) //do the health recharge.
		{
			if (readyForHealthrechargeSound)
			{
				StartSound("snd_healthrecharge", SND_CHANNEL_ITEM, 0, false, NULL);
				readyForHealthrechargeSound = false;
			}

			healthrechargeTimer = gameLocal.time + HEALTH_RECHARGE_TICKTIME;
			health = Min(health + HEALTH_RECHARGE_HEALTHPERTICK, adjustedMaxHealth);
		}
		else
		{
			//the delay before health regen kicks in.

			float chargeDelta;
			
			if (cond_shrapnel > 0)
				chargeDelta = (healthrechargeTimer - gameLocal.time) / (float)HEALTH_RECHARGE_INITIALDELAY_SHRAPNELWOUND;
			else
				chargeDelta = (healthrechargeTimer - gameLocal.time) / (float)HEALTH_RECHARGE_INITIALDELAY;

			chargeDelta = 1.0f - chargeDelta;						

			hud->SetStateFloat("healthcharge", chargeDelta);
		}
	}
	else if (health > adjustedMaxHealth) //if player has MORE health than the current max, then decline the health value.
	{
		if (gameLocal.time >= healthDeclineTimer)
		{
			healthDeclineTimer = gameLocal.time + 30;
			health = Max(health - 1, adjustedMaxHealth);
		}
	}
	else if (health == adjustedMaxHealth)
	{
		if (hud->GetStateFloat("healthcharge") < 1)
			hud->SetStateFloat("healthcharge", 1);
	}

	if (healthcloudActive && health >= adjustedMaxHealth)
	{
		healthcloudActive = false;
	}
}






int idPlayer::GetWoundCount(void)
{
	int woundCount = 0;

	//if (cond_burnwound > 0)
	//	woundCount++;
	//
	//if (cond_glasswound > 0)
	//	woundCount++;
	//
	//if (cond_bulletwound > 0)
	//	woundCount++;
	//
	//if (cond_shrapnel > 0)
	//	woundCount++;
	//
	//if (cond_spearwound > 0)
	//	woundCount++;

	//New damage model. An X'd out health pip wound will persist even after a quick-heal.
	for (int i = 0; i < WOUNDCOUNT_MAX; i++)
	{
		if (woundArray[i])
		{
			woundCount++;
		}
	}

	return woundCount;
}

void idPlayer::AddToWoundArray(int woundType)
{
	if (woundType < 0 || woundType >= WOUNDCOUNT_MAX)
	{
		gameLocal.Warning("AddToWoundArray: value is out of bounds.\n");
		return;
	}

	woundArray[woundType] = true;
}



#ifdef _D3XP


/*
=================
idPlayer::GetCurrentWeapon
=================
*/
idStr idPlayer::GetCurrentWeapon() {
	const char *weapon;

	if ( currentWeaponSlot >= 0 ) {
		weapon = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[currentWeaponSlot].weaponType ) );
		return weapon;
	} else {
		return "";
	}
}

/*
=================
idPlayer::CanGive
=================
*/
bool idPlayer::CanGive( const char *statname, const char *value ) {
	if ( AI_DEAD ) {
		return false;
	}

	if ( !idStr::Icmp( statname, "health" ) ) {
		if ( health >= inventory.maxHealth ) {
			return false;
		}
		return true;
	} else if ( !idStr::Icmp( statname, "stamina" ) ) {
		if ( stamina >= 100 ) {
			return false;
		}
		return true;

	} else if ( !idStr::Icmp( statname, "heartRate" ) ) {
		return true;

	} else if ( !idStr::Icmp( statname, "air" ) ) {
		if ( airTics >= pm_airTics.GetInteger() ) {
			return false;
		}
		return true;
	}

	return inventory.CanGive( this, spawnArgs, statname, value );
}

/*
=================
idPlayer::StopHelltime

provides a quick non-ramping way of stopping helltime
=================
*/
void idPlayer::StopHelltime( bool quick ) {
	if ( !PowerUpActive( HELLTIME ) ) {
		return;
	}

	// take away the powerups
	if ( PowerUpActive( INVULNERABILITY ) ) {
		ClearPowerup( INVULNERABILITY );
	}

	if ( PowerUpActive( BERSERK ) ) {
		ClearPowerup( BERSERK );
	}

	if ( PowerUpActive( HELLTIME ) ) {
		ClearPowerup( HELLTIME );
	}

	// stop the looping sound
	StopSound( SND_CHANNEL_DEMONIC, false );

	// reset the game vars
	if ( quick ) {
		gameLocal.QuickSlowmoReset();
	}
}

/*
=================
idPlayer::Event_ToggleBloom
=================
*/
void idPlayer::Event_ToggleBloom( int on ) {
	if ( on ) {
		bloomEnabled = true;
	}
	else {
		bloomEnabled = false;
	}
}

/*
=================
idPlayer::Event_SetBloomParms
=================
*/
void idPlayer::Event_SetBloomParms( float speed, float intensity ) {
	bloomSpeed = speed;
	bloomIntensity = intensity;
}

/*
=================
idPlayer::PlayHelltimeStopSound
=================
*/
void idPlayer::PlayHelltimeStopSound() {
	const char* sound;

	if ( spawnArgs.GetString( "snd_helltime_stop", "", &sound ) ) {
		PostEventMS( &EV_StartSoundShader, 0, sound, SND_CHANNEL_ANY );
	}
}
#endif

/*
=================
idPlayer::RouteGuiMouse
=================
*/
void idPlayer::RouteGuiMouse( idUserInterface *gui ) {
	sysEvent_t ev;

	if ( usercmd.mx != oldMouseX || usercmd.my != oldMouseY ) {
		ev = sys->GenerateMouseMoveEvent( usercmd.mx - oldMouseX, usercmd.my - oldMouseY );
		gui->HandleEvent( &ev, gameLocal.time );
		oldMouseX = usercmd.mx;
		oldMouseY = usercmd.my;
	}
}

/*
==================
idPlayer::LookAtKiller
==================
*/
void idPlayer::LookAtKiller( idEntity *inflictor, idEntity *attacker ) {
	idVec3 dir;

	if ( attacker && attacker != this ) {
		dir = attacker->GetPhysics()->GetOrigin() - GetPhysics()->GetOrigin();
	} else if ( inflictor && inflictor != this ) {
		dir = inflictor->GetPhysics()->GetOrigin() - GetPhysics()->GetOrigin();
	} else {
		dir = viewAxis[ 0 ];
	}

	idAngles ang( 0, dir.ToYaw(), 0 );
	SetViewAngles( ang );
}

/*
==============
idPlayer::Kill
==============
*/
void idPlayer::Kill( bool delayRespawn, bool nodamage ) {

	if (IsJockeying())
	{
		SetJockeyMode(false);
	}

	if ( spectating ) {
		SpectateFreeFly( false );
	} else if ( health > 0 )
	{
		godmode = false;

		if ( nodamage )
		{
			ServerSpectate( true );
			forceRespawn = true;
		}
		else
		{
			defibButtonCount = 0;
			inDownedState = true;
			defibButtonTimer = 0;
			Damage( this, this, vec3_origin, "damage_suicide", 1.0f, INVALID_JOINT );

			if ( delayRespawn ) {
				forceRespawn = false;
				int delay = spawnArgs.GetFloat( "respawn_delay" );
				minRespawnTime = gameLocal.time + SEC2MS( delay );
				maxRespawnTime = minRespawnTime + MAX_RESPAWN_TIME;
			}
		}
	}
}

/*
==================
idPlayer::Killed
==================
*/
void idPlayer::Killed( idEntity *inflictor, idEntity *attacker, int damage, const idVec3 &dir, int location ) {
	float delay;

	assert( !gameLocal.isClient );

	// stop taking knockback once dead
	fl.noknockback = true;
	if ( health < -999 ) {
		health = -999;
	}

	if ( AI_DEAD ) {
		AI_PAIN = true;
		return;
	}

	heartInfo.Init( 0, 0, 0, BASE_HEARTRATE );
	AdjustHeartRate( DEAD_HEARTRATE, 10.0f, 0.0f, true );

	/*
	//BC don't fade to black.
	if ( !g_testDeath.GetBool() )
	{
		playerView.Fade( colorBlack, 12000 );
	}*/

	deathTimer = gameLocal.time;

	AI_DEAD = true;

	SetJockeyMode(false);

	// SM: Spawn a separate ragdoll actor if the flag is set
	idActor* newActor = NULL;
	if ( cvarSystem->GetCVarBool( "pm_spawnRagdollOnDeath" ) ) {
		idDict args;
		args.Set( "classname", "player_doommarine_ragdoll" );
		idEntity* newEnt = NULL;
		gameLocal.SpawnEntityDef( args, &newEnt );
		if ( newEnt && newEnt->IsType( idActor::Type ) ) {
			newActor = static_cast< idActor* >( newEnt );
			newActor->SetOrigin( GetPhysics()->GetOrigin() );
			newActor->SetAxis( GetPhysics()->GetAxis() );
			
			newActor->SetSkin( declManager->FindSkin( "skins/player/skin_armsboth_feetbare.skin" ) );
			
			newActor->GetAF().SetOverrideCurrent(this);
			newActor->GetPhysics()->SetContents( CONTENTS_CORPSE | CONTENTS_MONSTERCLIP );
			newActor->GetPhysics()->SetAngularVelocity( vec3_zero );
			newActor->GetPhysics()->SetLinearVelocity( vec3_zero );
			newActor->health = 0;
			
			SetAnimState( ANIMCHANNEL_LEGS, "Legs_Death", 4 );
			SetAnimState( ANIMCHANNEL_TORSO, "Torso_Death", 4 );
			SetWaitState( "" );
			GetAnimator()->ClearAllJoints();
			
			Hide();
		}
	}

	if ( !newActor ) {
		newActor = this;
	}

	newActor->SetAnimState( ANIMCHANNEL_LEGS, "Legs_Death", 4 );
	newActor->SetAnimState( ANIMCHANNEL_TORSO, "Torso_Death", 4 );
	newActor->SetWaitState( "" );

	newActor->GetAnimator()->ClearAllJoints();

	if ( newActor->StartRagdoll() ) {
		pm_modelView.SetInteger( 0 );
		minRespawnTime = gameLocal.time + RAGDOLL_DEATH_TIME;
		maxRespawnTime = minRespawnTime + MAX_RESPAWN_TIME;
	} else {
		// don't allow respawn until the death anim is done
		// g_forcerespawn may force spawning at some later time
		delay = spawnArgs.GetFloat( "respawn_delay" );
		minRespawnTime = gameLocal.time + SEC2MS( delay );
		maxRespawnTime = minRespawnTime + MAX_RESPAWN_TIME;
	}

	physicsObj.SetMovementType( PM_DEAD );
	StartSound( "snd_death", SND_CHANNEL_VOICE, 0, false, NULL );
	StopSound( SND_CHANNEL_BODY2, false );

	fl.takedamage = true;		// can still be gibbed

	// get rid of weapon
	weapon.GetEntity()->OwnerDied();

	// drop the weapon as an item
	DropWeapon( true );

#ifdef CTF
	// drop the flag if player was carrying it
	if ( gameLocal.isMultiplayer && gameLocal.mpGame.IsGametypeFlagBased() &&
		 carryingFlag )
	{
		DropFlag();
	}
#endif

	if ( !g_testDeath.GetBool() )
	{
		LookAtKiller( inflictor, attacker );
	}

	if ( gameLocal.isMultiplayer || g_testDeath.GetBool() ) {
		idPlayer *killer = NULL;
		// no gibbing in MP. Event_Gib will early out in MP
		if ( attacker->IsType( idPlayer::Type ) )
		{
			killer = static_cast<idPlayer*>(attacker);
			if ( health < -20 || killer->PowerUpActive( BERSERK ) ) {
				gibDeath = true;
				gibsDir = dir;
				gibsLaunched = false;
			}
		}
		gameLocal.mpGame.PlayerDeath( this, killer, isTelefragged );
	}
	else
	{
		physicsObj.SetContents( CONTENTS_CORPSE | CONTENTS_MONSTERCLIP );
	}

	ClearPowerUps();

	UpdateVisuals();

	isChatting = false;

	//BC close context menu.
	CloseContextMenu();

	
	if (airless)
	{
		//If die in zero G, then turn off player gravity and push body in direction of last blow.
		this->GetPhysics()->SetGravity(vec3_zero);
	}

	//Give player push in whatever direction the attack came from.
	/* TODO: Fix this
	if (lastAttackDir.x != 0 || lastAttackDir.y != 0 || lastAttackDir.z != 0)
	{
		if (location >= 0)
		{
			idVec3 jointOffset;
			idMat3 jointAngle;

			animator.GetJointTransform((jointHandle_t)location, gameLocal.time, jointOffset, jointAngle);

			//af.GetPhysics()->ApplyImpulse(0, this->GetPhysics()->GetOrigin() + jointOffset, (lastAttackDir + idVec3(0, 0, .125f)) * this->GetPhysics()->GetMass() * 4096);
			af.GetPhysics()->ApplyImpulse(0, this->GetPhysics()->GetAbsBounds().GetCenter(), (lastAttackDir + idVec3(0, 0, .125f)) * this->GetPhysics()->GetMass() * 4096);

		}

		//af.GetPhysics()->SetLinearVelocity((lastAttackDir + idVec3(0, 0, .125f)) * 4096);
		//	
	}*/

	//Show arms.
	SetArmVisibility(true);

	//slo mo.
	//Event_SetPowerupTime(HELLTIME, 1000);	

	//bc Remove the downed state so that we don't do the downed fullscreen fx.
	inDownedState = false;
	viewAngles.roll = 0;

	hud->HandleNamedEvent("playerdeath");
	//hud->SetStateBool("playerdead", true);

	//Play the death music.
	gameSoundWorld->PlayShaderDirectly(spawnArgs.GetString("snd_deathmusic"), SND_CHANNEL_MUSIC);
	
}

/*
=====================
idPlayer::GetAIAimTargets

Returns positions for the AI to aim at.
=====================
*/
void idPlayer::GetAIAimTargets( const idVec3 &lastSightPos, idVec3 &headPos, idVec3 &chestPos ) {
	idVec3 offset;
	idMat3 axis;
	idVec3 origin;

	origin = lastSightPos - physicsObj.GetOrigin();

	GetJointWorldTransform( chestJoint, gameLocal.time, offset, axis );
	headPos = offset + origin;

	GetJointWorldTransform( headJoint, gameLocal.time, offset, axis );
	chestPos = offset + origin;
}

/*
================
idPlayer::DamageFeedback

callback function for when another entity received damage from this entity.  damage can be adjusted and returned to the caller.
================
*/
void idPlayer::DamageFeedback( idEntity *victim, idEntity *inflictor, int &damage ) {
	assert( !gameLocal.isClient );
	damage *= PowerUpModifier( BERSERK );
	if ( damage && ( victim != this ) && ( victim->IsType( idActor::Type ) || victim->IsType( idDamagable::Type ) ) ) {

		idPlayer *victimPlayer = NULL;

		/* No damage feedback sound for hitting friendlies in CTF */
		if ( victim->IsType( idPlayer::Type ) ) {
			victimPlayer = static_cast<idPlayer*>(victim);
		}

		if ( gameLocal.mpGame.IsGametypeFlagBased() && victimPlayer && this->team == victimPlayer->team ) {
			/* Do nothing ... */
		}
		else {
			SetLastHitTime( gameLocal.time );
		}
	}
}



/*
=================
idPlayer::CalcDamagePoints

Calculates how many health and armor points will be inflicted, but
doesn't actually do anything with them.  This is used to tell when an attack
would have killed the player, possibly allowing a "saving throw"
=================
*/
void idPlayer::CalcDamagePoints( idEntity *inflictor, idEntity *attacker, const idDict *damageDef, const float damageScale, const int location, int *health, int *armor ) {
	int		damage;
	int		armorSave;

	damageDef->GetInt( "damage", "20", damage );
	damage = GetDamageForLocation( damage, location );

	//idPlayer *player = attacker->IsType( idPlayer::Type ) ? static_cast<idPlayer*>(attacker) : NULL;
	if ( !gameLocal.isMultiplayer ) {
		if ( inflictor != gameLocal.world ) {
			switch ( g_skill.GetInteger() ) {
				case 0:
					damage *= 0.80f;
					if ( damage < 1 ) {
						damage = 1;
					}
					break;
				case 2:
					damage *= 1.70f;
					break;
				case 3:
					damage *= 3.5f;
					break;
				default:
					break;
			}
		}
	}

	damage *= damageScale;

	// always give half damage if hurting self
	if ( attacker == this ) {
		if ( gameLocal.isMultiplayer ) {
			// only do this in mp so single player plasma and rocket splash is very dangerous in close quarters
			damage *= damageDef->GetFloat( "selfDamageScale", "0.5" );
		} else {
			damage *= damageDef->GetFloat( "selfDamageScale", "1" );
		}
	}

	// check for completely getting out of the damage
	if ( !damageDef->GetBool( "noGod" ) ) {
		// check for godmode
		if ( godmode ) {
			damage = 0;
		}
#ifdef _D3XP
		//Invulnerability is just like god mode
		if( PowerUpActive( INVULNERABILITY ) ) {
			damage = 0;
		}
#endif
	}

	// inform the attacker that they hit someone
	attacker->DamageFeedback( this, inflictor, damage );

	// armor absorb some damage.
	if ( damageDef->GetBool( "armoraffect", "1" ) )
	{
		float armor_protection;

		armor_protection = g_armorProtection.GetFloat();

		armorSave = ceil( damage * armor_protection ); //how much damage does the armor absorb.
		if ( armorSave >= inventory.armor )
		{
			armorSave = inventory.armor;
		}

		//BC we tweak how armor works a bit to work with our small-numbers system.

		//Calculate damage & calculate how much armor remains afterward. armorSave = how much to subtract from armor.

		if ( !damage )
		{
			//There was no damage done.
			armorSave = 0;
		}
		else if ( armorSave >= damage )
		{
			//The armor absorbed all the damage.
			armorSave = damage;
			damage = 0; //take zero damage, since the armor absorbed it all.
		}
		else
		{
			damage -= armorSave;
		}

		if (armorSave > 0)
		{			
			if (inventory.armor > 1)
				hud->HandleNamedEvent("armor_takedamage"); //armor absorbed damage.
			else
				hud->HandleNamedEvent("armor_finaldamage"); //final piece of armor is now gone.			
		}
	}
	else
	{
		armorSave = 0;
	}

	// check for team damage
	/*
	if ( gameLocal.mpGame.IsGametypeTeamBased() 
		&& !gameLocal.serverInfo.GetBool( "si_teamDamage" )
		&& !damageDef->GetBool( "noTeam" )
		&& player
		&& player != this		// you get self damage no matter what
		&& player->team == team ) {
			damage = 0;
	}*/




	//BC
	//Determine if we need to round upward, to inflict 1+ blocks of health damage.
	if (damageDef->GetBool("damage_roundup", "0") && damage > 0)
	{
		//Ok, round up the damage. Increase the amount of damage to be ONE health block.

		int healthPerSegment = maxHealth / HEALTHBAR_SEGMENTS;
		int damageToRoundDown = this->health % healthPerSegment;

		if (damageToRoundDown > 0)
		{
			damage = damageToRoundDown; //Knock health down to the next health segment.
		}
		else
		{
			damage = healthPerSegment; //Player had a full health segment, so just delete one health segment.
		}

		//Handle if damage definition wants to inflict damage greater than 1 block.
		int damageBlocksToInflict = damageDef->GetInt("damage");
		if (damageBlocksToInflict > 1)
		{
			damage += (damageBlocksToInflict - 1) * healthPerSegment;
		}
	}



	//BC SAVING THROW
	if (this->health - damage <= 0)//killing blow.
	{
		if (savingthrowState == SAVINGTHROW_ACTIVE)
		{
			//Saving throw is active right now; ignore damage.
			damage = 0;
		}
		else if (savingthrowState == SAVINGTHROW_AVAILABLE &&  IsSavingthrowAvailable(damageDef, attacker))
		{
			//Saving throw was activated on this frame.
			this->lastSavingThrowTime = gameLocal.time;
			damage = this->health - 1;
			savingthrowState = SAVINGTHROW_ACTIVE;
		}
	}

	damageTaken += damage;
	

	*health = damage;
	*armor = armorSave;
}

//Check saving throw, rescue player from death.
//If it is damage-over-time, saving throw does not save you.
bool idPlayer::IsSavingthrowAvailable(const idDict* damageDef, idEntity* attacker)
{
	if (damageDef->GetBool("isdotdamage") || !g_savingthrows.GetBool() || damageDef->GetBool("noGod"))
		return false;

	//If the attacker is in LOS, then force damage to happen.
	if (attacker != nullptr)
	{
		idVec3 attackerPos = (attacker->IsType(idActor::Type)) ? static_cast<idActor*>(attacker)->GetEyePosition() : attacker->GetPhysics()->GetOrigin();
		
		idVec3 attackDir = attackerPos - firstPersonViewOrigin;
		attackDir.Normalize();

		float vdot = DotProduct(attackDir, viewAngles.ToForward());
		if (vdot > SAVINGTHROW_ANGLETHRESHOLD)
		{
			//The attacker is in player's LOS. So, ignore saving throw and force damage to happen.
			return false;
		}
	}

	return true;
}




void idPlayer::Event_SetDownedState(int toggle)
{
	if (toggle != 0)
	{
		EnterDownedState(NULL);
	}
	else
	{
		CancelDownedState();
	}
}

// SW: Force-exit downed state. Silent, no bloodbag FX
void idPlayer::CancelDownedState(void)
{
	inDownedState = false;
	viewAngles.roll = 0;
	SetViewAngles(idAngles(0, viewAngles.yaw, 0));

	//activate health recharge.
	health = maxHealth - (GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK); //max health.
	healthrechargeTimer = gameLocal.time;
	savingthrowState = SAVINGTHROW_AVAILABLE; //make saving throw immediately available again.

	bloodbagTimer = gameLocal.time;
	HideBloodbag();
}

void idPlayer::EnterDownedState(const idDeclEntityDef* damageDef)
{
	//Enter downed state.
	if (IsJockeying())
	{
		SetJockeyMode(false);
		SetImpactSlowmo(true);
	}

	if (!damageDef || damageDef->dict.GetBool("cankillplayer", "1"))
	{
		//If lying down, then kick them out of lying down state.
		AI_FALLEN = false;
		AI_FALLEN_GETUP = false;
		physicsObj.SetImmediateExitFallState();

		defibButtonCount = 0;
		inDownedState = true;
		health = 100;
		downedTickTimer = gameLocal.time + DOWNED_TICKTIME;
		hud->HandleNamedEvent("startBleedingout");

		defibButtonTimer = 0;
	}
}

/*
============
Damage

this		entity that is being damaged
inflictor	entity that is causing the damage
attacker	entity that caused the inflictor to damage targ
	example: this=monster, inflictor=rocket, attacker=player

dir			direction of the attack for knockback in global space

damageDef	an idDict with all the options for damage effects

inflictor, attacker, dir, and point can be NULL for environmental effects
============
*/
void idPlayer::Damage( idEntity *inflictor, idEntity *attacker, const idVec3 &dir, const char *damageDefName, const float damageScale, const int location, const int materialType ) {
	idVec3		kick;
	int			damage;
	int			armorSave;
	int			knockback;
	idVec3		damage_from;
	idVec3		localDamageVector;
	float		attackerPushScale;
#ifdef _D3XP
	SetTimeState ts( timeGroup );
#endif

	// damage is only processed on server
	if ( gameLocal.isClient ) {
		return;
	}

	if ( !fl.takedamage || noclip || spectating || gameLocal.inCinematic ) {
		return;
	}




	if ( !inflictor ) {
		inflictor = gameLocal.world;
	}
	if ( !attacker ) {
		attacker = gameLocal.world;
	}

	if ( attacker->IsType( idAI::Type ) ) {
#ifndef _D3XP
		if ( PowerUpActive( BERSERK ) ) {
			return;
		}
#endif
		// don't take damage from monsters during influences
		if ( influenceActive != 0 ) {
			return;
		}
	}

	const idDeclEntityDef *damageDef = gameLocal.FindEntityDef( damageDefName, false );
	if ( !damageDef ) {
		gameLocal.Warning( "Unknown damageDef '%s'", damageDefName );
		return;
	}

	//Limit how much burn damage can be inflicted on player.
	if (damageDef->dict.GetBool("isfire") && gameLocal.time < lastBurnwoundTime + CONDITION_BURNING_WOUNDS_PER_TIME)
		return;

	if ( damageDef->dict.GetBool( "ignore_player" ) ) {
		return;
	}



	CalcDamagePoints( inflictor, attacker, &damageDef->dict, damageScale, location, &damage, &armorSave );

	//If we want something to inflict zero damage on enemies but some damage to player (i.e. electric jet)
	if (damage <= 0)
	{
		int playerDamage = damageDef->dict.GetInt("damage_player");
		if (playerDamage > 0)
		{
			damage = playerDamage;
		}
	}

	// determine knockback
	damageDef->dict.GetInt( "knockback", "20", knockback );

/*#ifdef _D3XP
	idPlayer *player = attacker->IsType( idPlayer::Type ) ? static_cast<idPlayer*>(attacker) : NULL;

	if ( gameLocal.mpGame.IsGametypeTeamBased()
		&& !gameLocal.serverInfo.GetBool( "si_teamDamage" )
		&& !damageDef->dict.GetBool( "noTeam" )
		&& player
		&& player != this		// you get self damage no matter what
		&& player->team == team ) {
			knockback = 0;
		}
#endif*/

	if ( knockback != 0 && !fl.noknockback )
	{
		if ( attacker == this ) {
			damageDef->dict.GetFloat( "attackerPushScale", "0", attackerPushScale );
		} else {
			attackerPushScale = 1.0f;
		}

		kick = dir;
		kick.Normalize();
		kick *= g_knockback.GetFloat() * knockback * attackerPushScale / 200.0f;
		physicsObj.SetLinearVelocity( physicsObj.GetLinearVelocity() + kick );

		// set the timer so that the player can't cancel out the movement immediately
		physicsObj.SetKnockBack( idMath::ClampInt( 50, 200, knockback * 2 ) );
	}


	// give feedback on the player view and audibly when armor is helping
	if ( armorSave ) {
		inventory.armor -= armorSave;

		if ( gameLocal.time > lastArmorPulse + 200) {
			
			StartSound((inventory.armor > 0) ? "snd_hitArmor" : "snd_armorbreak", SND_CHANNEL_ITEM, 0, false, NULL );

		}
		lastArmorPulse = gameLocal.fast.time;
	}

	if ( damageDef->dict.GetBool( "burn" ) ) {
		StartSound( "snd_burn", SND_CHANNEL_BODY3, 0, false, NULL );
	} else if ( damageDef->dict.GetBool( "no_air" ) ) {
		if ( !armorSave && health > 0 ) {
			StartSound( "snd_airGasp", SND_CHANNEL_ITEM, 0, false, NULL );
		}
	}

	if ( g_debugDamage.GetInteger() ) {
		gameLocal.Printf( "client:%i health:%i damage:%i armor:%i\n",
			entityNumber, health, damage, armorSave );
	}

	// move the world direction vector to local coordinates
	damage_from = dir;
	damage_from.Normalize();

	viewAxis.ProjectVector( damage_from, localDamageVector );

	// add to the damage inflicted on a player this frame
	// the total will be turned into screen blends and view angle kicks
	// at the end of the frame
	if ( health > 0 )
	{
		playerView.DamageImpulse( localDamageVector, &damageDef->dict );
	}

	

	if (damageDef->dict.GetBool("ischem") && damage > 0)
	{
		if (gameLocal.time >= lastChemDamageTime + 300)
		{
			if (gameLocal.time - lastChemDamageTime < 400)
			{
				playerInChemTimer += gameLocal.time - lastChemDamageTime;
			}

			lastChemDamageTime = gameLocal.time;

			if (playerInChemTimer > CHEM_LOWDAMAGE_TIME)
			{
				//common->Printf("BIG OUCH\n");
				damage *= CHEM_HIGHDAMAGE_MULTIPLIER;
			}
			else
			{
				//common->Printf("small OUCH\n");
			}
		}
		else
		{
			damage = 0;
		}
	}

	if (damageDef->dict.GetBool("smelly"))
	{
		SetSmelly(true);
	}

	if (damageDef->dict.GetBool("impalement"))
	{
		SetSpearwound();
	}



	if (damage > 0 && jockeyState == JCK_ATTACHED)
	{
		//If I'm jockeying someone and receive damage, check to see if damage should be ignored or not.
		if (!AcceptJockeyDamage(inflictor, attacker, dir, damageDefName))
		{
			//I am jockeying AND I my jockey target should absorb all the damage.

			if (meleeTarget.IsValid())
			{
				//Damage is instead transferred to the jockee.
				meleeTarget.GetEntity()->Damage(inflictor, attacker, dir, damageDefName, damageScale, location, materialType);
			}			

			damage = 0;
		}
	}
	

	// do the damage
	if ( damage > 0 )
	{


		//BC this is some sort of dynamic damage scaling thing..... disabling it now.
//		if ( !gameLocal.isMultiplayer ) {
//#ifdef _D3XP
//			float scale = new_g_damageScale;
//#else
//			float scale = g_damageScale.GetFloat();
//#endif
//			if ( g_useDynamicProtection.GetBool() && g_skill.GetInteger() < 2 ) {
//				if ( gameLocal.time > lastDmgTime + 500 && scale > 0.25f ) {
//					scale -= 0.05f;
//#ifdef _D3XP
//					new_g_damageScale = scale;
//#else
//					g_damageScale.SetFloat( scale );
//#endif
//				}
//			}
//
//			if ( scale > 0.0f ) {
//				damage *= scale;
//			}
//		}

		

		if ( damage < 1 ) {
			damage = 1;
		}


		//damage scaling.
		float dmgScale = g_damageScale.GetFloat();
		if (dmgScale <= 0)
		{
			damage = 0;
		}
		else
		{
			damage *= dmgScale;
			damage = Max(damage, 1);
		}


		health -= damage;

		gameLocal.AddEventlogDamage(this, damage, inflictor, attacker, damageDefName);

		if ( health <= 0 )
		{
			if ( health < -999 ) {
				health = -999;
			}

			isTelefragged = damageDef->dict.GetBool( "telefrag" );

			lastDmgTime = gameLocal.time;

			

			HideBloodbag();

			//BC Downed state logic.

			if (!inDownedState)
			{
				EnterDownedState(damageDef);
			}
			else
			{
				//Player was in downed state and has completely bled out.

				if (!AI_DEAD || defibAvailable)
					StartSound("snd_death_fanfare", SND_CHANNEL_ANY, 0, false, NULL);

				if (defibAvailable)
				{
					//Auto-defib is available. Do defib.
					ActivateDefib();
				}
				else
				{
					if (inventory.bloodbags > 0)
					{
						//If player has bloodbag AND is about to die, just use the bloodbag automatically.
						if (healState != HEALSTATE_BLEEDOUT)
						{
							health = 1;
							StartHealState(HEALSTATE_BLEEDOUT);
						}
						return;
					}

					//Kill the player now, for reals.

					if (damageDef->dict.GetBool("cankillplayer", "1")) //we can flag damage types to NEVER be able to actually kill a player. This is for stuff like the hyperspace damage, which is intended to rescue the player, not kill them.
					{
						Killed(inflictor, attacker, damage, dir, location);
					}
				}
			}
		}
		else
		{
			// force a blink
			blink_time = 0;

			// let the anim script know we took damage
			AI_PAIN = Pain( inflictor, attacker, damage, dir, location, damageDef->dict.GetBool("playpainsound", "1") );
			if ( !g_testDeath.GetBool() ) {
				lastDmgTime = gameLocal.time;
			}

			//BC heart logic.
			if (health < 60)
			{
				heartVolume = 0;
				lastHeartVolumeAdjust = gameLocal.time + 2000;
			}
		}

		//Do the hud stuff for the fading healthbar.
		hud->HandleNamedEvent("takedamage");
		healthFadeMaxedBool = false;
		healthbarIsFaded = false;


		healthDamageFlashTimer = gameLocal.time + HEALTHBAR_DAMAGE_FLASHTIME;

		//weapon bloodsplat
		if (weapon.GetEntity())
		{
			weapon.GetEntity()->BloodSplat( 16 );
		}

		if (bloodbagState == BLOODBAGSTATE_TRANSFUSING && gameLocal.time > bloodbagDamageTimer)
		{
			int adjustedBloodbaghealth;

			bloodbagHealth -= damage;
			bloodbagDamageTimer = gameLocal.time + 1000; //Limit bloodbag damage to every XX milliseconds.
			adjustedBloodbaghealth = (int)((bloodbagHealth / (float)HEALTH_BLOODBAG_DEFAULTHEALTH) * 100.0f);


			if (adjustedBloodbaghealth < 33)
				hud->SetStateString("bloodbaghealth", "HEAVILY DAMAGED");
			else if (adjustedBloodbaghealth < 66)
				hud->SetStateString("bloodbaghealth", "MODERATE DAMAGE");
			else if (bloodbagHealth < HEALTH_BLOODBAG_DEFAULTHEALTH)
				hud->SetStateString("bloodbaghealth", "LIGHTLY DAMAGED");
			else
				hud->SetStateString("bloodbaghealth", "PRISTINE");

			if (bloodbagHealthFXState == 0)
			{
				//if off, then activate bloodbag damage fx.
				bloodbagEmitter->SetModel("bloodbag_damage_1.prt");
				bloodbagEmitter->SetActive(true);
				bloodbagHealthFXState = 1;
			}
			
			if (bloodbagHealthFXState == 1 && adjustedBloodbaghealth < 66)
			{
				//if in medium or heavy damage, then do the heavy bloodbag damage fx.
				bloodbagEmitter->SetModel("bloodbag_damage_2.prt");
				bloodbagHealthFXState = 2;
			}

			if (bloodbagHealth <= 0)
			{
				idVec3 bagPos;
				idMat3 bagAxis;

				//Blood bag explode.
				bloodbagState = BLOODBAGSTATE_EXPLODING;
				bloodbagTimer = gameLocal.time;

				bloodbagMesh->GetRenderEntity()->shaderParms[SHADERPARM_TIME_OF_DEATH] = gameLocal.time * 0.001f; //Burn away the bloodbag.
				hud->HandleNamedEvent("startBleedingout");
				hud->HandleNamedEvent("bloodbagdestroyed");				
				bloodbagEmitter->SetActive(false); //Turn off blood fountain.

				bloodbagMesh->StopSound(SND_CHANNEL_BODY3, false);
				bloodbagMesh->StartSound("snd_pop", SND_CHANNEL_ANY, 0, false, NULL);


				bloodbagMesh->GetJointWorldTransform(bloodbagJoint, gameLocal.time, bagPos, bagAxis);
				bagPos.z += 2.0f;
				idEntityFx::StartFx("fx/bloodbag_explosion", &bagPos, &mat3_identity, bloodbagMesh, true);
				playerView.SetBloodbagOverlay();				
			}
		}
	}
	else
	{
		// don't accumulate impulses
		if ( af.IsLoaded() ) {
			// clear impacts
			af.Rest();

			// physics is turned off by calling af.Rest()
			BecomeActive( TH_PHYSICS );
		}
	}


	//BC Damage Conditions
	if (damageDef->dict.GetBool("isshrapnel") && damage > 0)
	{
		//Got hit by shrapnel.
		cond_shrapnel++;
		AddToWoundArray(WOUNDIDX_SHRAPNEL);
	}

	if (damageDef->dict.GetBool("deafens"))
	{
		gameSoundWorld->FadeSoundClasses(0, -60, 1.0f);
		StartSound("snd_earringing", SND_CHANNEL_ANY, 0, false, NULL);
		
		deafenState = DEAFEN_INITIALDELAY;
		deafenTimer = gameLocal.time;
	}

	if (damageDef->dict.GetBool("isfire") && gameLocal.time >= lastBurnwoundTime + CONDITION_BURNING_WOUNDS_PER_TIME)
	{
		lastBurnwoundTime = gameLocal.time;

		SetOnFire(true);		
	}

	if (damageDef->dict.GetBool("isburnwound"))
	{
		cond_burnwound++;
		AddToWoundArray(WOUNDIDX_BURN);
	}

	if (damageDef->dict.GetBool("isbullet") && gameLocal.time >= lastBulletwoundTimer && cond_bulletwound < CONDITION_BULLETWOUND_MAXWOUNDS && damage > 0)
	{
		lastBulletwoundTimer = gameLocal.time + CONDITION_BULLETWOUND_PER_TIME;
		
		cond_bulletwound++;
		AddToWoundArray(WOUNDIDX_BULLET);
	}

	if (damageDef->dict.GetBool("knockdown") && !inDownedState)
	{
		//do knockdown state.
		SetFallState(true, true);
	}


	
	//Health recharge timer.
	healthrechargeTimer = gameLocal.time + (cond_shrapnel > 0 ? HEALTH_RECHARGE_INITIALDELAY_SHRAPNELWOUND : HEALTH_RECHARGE_INITIALDELAY);
	readyForHealthrechargeSound = true;

	

	lastDamageDef = damageDef->Index();
	lastDamageDir = damage_from;
	lastDamageLocation = location;


	//Damage arrows.
	if (attacker && attacker != this && !attacker->IsType(idWorldspawn::Type))
	{
		DoDamageArrow(attacker->GetPhysics()->GetOrigin());
	}
	else if (inflictor && inflictor != this && !inflictor->IsType(idWorldspawn::Type))
	{
		DoDamageArrow(inflictor->GetPhysics()->GetOrigin());
	}

	if (dir.x != 0 || dir.y != 0 || dir.z != 0)
	{
		lastAttackDir = dir;
	}

	//gamepad rumble when taking damage.
	GamePadFXSystem::GetSys().AddRumble(1, 200);
}



void idPlayer::DoDamageArrow(idVec3 worldPosition)
{
	int i;

	for (i = 0; i < DAMAGEARROW_COUNT; i++)
	{
		if (damageArrowTimers[i] < gameLocal.time)
		{
			damageArrowTimers[i] = gameLocal.time + DAMAGEARROW_MAXTIME;
			damageArrowPosition[i] = worldPosition;
			return;
		}
	}

	
}

/*
===========
idPlayer::Teleport
============
*/
void idPlayer::Teleport( const idVec3 &origin, const idAngles &angles, idEntity *destination, bool forceDuck, bool killbox ) {
	idVec3 org;

	if ( weapon.GetEntity() ) {
		weapon.GetEntity()->LowerWeapon();
	}

	SetOrigin( origin + idVec3( 0, 0, CM_CLIP_EPSILON ) );
	if ( !gameLocal.isMultiplayer && GetFloorPos( 16.0f, org ) ) {
		SetOrigin( org );
	}

	// clear the ik heights so model doesn't appear in the wrong place
	walkIK.EnableAll();

	GetPhysics()->SetLinearVelocity( vec3_origin );

	if (forceDuck)
	{
		physicsObj.ForceDuck(100);
	}

	SetViewAngles( angles );

	legsYaw = 0.0f;
	idealLegsYaw = 0.0f;
	oldViewYaw = viewAngles.yaw;

	//if ( gameLocal.isMultiplayer )
	{
		//playerView.Flash( colorYellow, 500 );
	}

	UpdateVisuals();

	teleportEntity = destination;

	if ( !gameLocal.isClient && !noclip && killbox) {
		if ( gameLocal.isMultiplayer ) {
			// kill anything at the new position or mark for kill depending on immediate or delayed teleport
			gameLocal.KillBox( this, destination != NULL );
		} else {
			// kill anything at the new position
			gameLocal.KillBox( this, true );
		}
	}

#ifdef _D3XP
	if ( PowerUpActive( HELLTIME ) ) {
		StopHelltime();
	}
#endif
}

/*
====================
idPlayer::SetPrivateCameraView
====================
*/
void idPlayer::SetPrivateCameraView( idCamera *camView ) {
	privateCameraView = camView;
	if ( camView ) {
		StopFiring();
		Hide();
	} else {
		if ( !spectating ) {
			Show();
		}
	}
}

/*
====================
idPlayer::DefaultFov

Returns the base FOV
====================
*/
float idPlayer::DefaultFov( void ) const {
	float fov;

	fov = g_fov.GetFloat();
	if ( gameLocal.isMultiplayer ) {
		if ( fov < 90.0f ) {
			return 90.0f;
		} else if ( fov > 110.0f ) {
			return 110.0f;
		}
	}

	return fov;
}

/*
====================
idPlayer::CalcFov

Fixed fov at intermissions, otherwise account for fov variable and zooms.
====================
*/
float idPlayer::CalcFov( bool honorZoom ) {
	float fov;

	int currentTime = gameLocal.spectatePause ? gameLocal.hudTime : gameLocal.time;

	if ( fxFov ) {
		return DefaultFov() + 10.0f + cos( ( currentTime + 2000 ) * 0.01 ) * 10.0f;
	}

	if (fovLerpState == FOVLERP_LERPING || fovLerpState == FOVLERP_LOCKED)
	{
		float newFov = DefaultFov() + fovLerpCurrent;
		return Max(newFov, 1.0f);
	}

	if ( influenceFov ) {
		return influenceFov;
	}

	//Vignette telescope zoom
	if (peekObject.IsValid() && static_cast<idVentpeek*>(peekObject.GetEntity())->forTelescope)
	{
		//If player is in telescope, do the telescope fov.
		fov = static_cast<idVentpeekTelescope*>(peekObject.GetEntity())->GetCurrentFOV();
	}
	else
	{
		//Normal gameplay. Not in telescope.

		// Normal player eyeball 'Z' zoom
		if (iteminspectActive && inspectLerpState == INSP_INSPECTING)
		{			

			fov = iteminspectFOV;
		}
		else if (zoominspect_LabelmodeActive)
		{
			//when in world label inspection mode, use the zoomfov setting
			fov = zoomFov.GetCurrentValue(currentTime);
		}
		else if (zoomFov.IsDone(currentTime))
		{
			//This is normal FOV for during normal non-zoom AND in normal zoom mode.
			fov = (CanZoom() && honorZoom && zoommodeActive) && weapon.GetEntity() ? zoomCurrentFOV : DefaultFov();
		}
		else
		{
			//Fov is doing its activation lerp in/out
			fov = zoomFov.GetCurrentValue(currentTime);
		}
	}

	// bound normal viewsize
	if ( fov < 1 ) {
		fov = 1;
	} else if ( fov > 179 ) {
		fov = 179;
	}

	return fov;
}

/*
==============
idPlayer::GunTurningOffset

generate a rotational offset for the gun based on the view angle
history in loggedViewAngles
==============
*/
idAngles idPlayer::GunTurningOffset( void ) {
	idAngles	a;

	a.Zero();

	if ( gameLocal.framenum < NUM_LOGGED_VIEW_ANGLES ) {
		return a;
	}

	idAngles current = loggedViewAngles[ gameLocal.framenum & (NUM_LOGGED_VIEW_ANGLES-1) ];

	idAngles	av, base;
	int weaponAngleOffsetAverages;
	float weaponAngleOffsetScale, weaponAngleOffsetMax;

	weapon.GetEntity()->GetWeaponAngleOffsets( &weaponAngleOffsetAverages, &weaponAngleOffsetScale, &weaponAngleOffsetMax );

	av = current;

	// calcualte this so the wrap arounds work properly
	for ( int j = 1 ; j < weaponAngleOffsetAverages ; j++ ) {
		idAngles a2 = loggedViewAngles[ ( gameLocal.framenum - j ) & (NUM_LOGGED_VIEW_ANGLES-1) ];

		idAngles delta = a2 - current;

		if ( delta[1] > 180 ) {
			delta[1] -= 360;
		} else if ( delta[1] < -180 ) {
			delta[1] += 360;
		}

		av += delta * ( 1.0f / weaponAngleOffsetAverages );
	}

	a = ( av - current ) * weaponAngleOffsetScale;

	for ( int i = 0 ; i < 3 ; i++ ) {
		if ( a[i] < -weaponAngleOffsetMax ) {
			a[i] = -weaponAngleOffsetMax;
		} else if ( a[i] > weaponAngleOffsetMax ) {
			a[i] = weaponAngleOffsetMax;
		}
	}

	
	//BC weapon jiggle detection, for liquids, jiggle parts, etc.
	weapon.GetEntity()->isJiggling = (a.pitch != 0 || a.yaw != 0 || xyspeed > 0);



	currentYawDelta = a.yaw;

	return a;
}

/*
==============
idPlayer::GunAcceleratingOffset

generate a positional offset for the gun based on the movement
history in loggedAccelerations
==============
*/
idVec3	idPlayer::GunAcceleratingOffset( void ) {
	idVec3	ofs;

	float weaponOffsetTime, weaponOffsetScale;

	ofs.Zero();
	
	weapon.GetEntity()->GetWeaponTimeOffsets( &weaponOffsetTime, &weaponOffsetScale );

	int stop = currentLoggedAccel - NUM_LOGGED_ACCELS;
	if ( stop < 0 ) {
		stop = 0;
	}
	for ( int i = currentLoggedAccel-1 ; i > stop ; i-- ) {
		loggedAccel_t	*acc = &loggedAccel[i&(NUM_LOGGED_ACCELS-1)];

		float	f;
		float	t = gameLocal.time - acc->time;
		if ( t >= weaponOffsetTime ) {
			break;	// remainder are too old to care about
		}

		f = t / weaponOffsetTime;
		f = ( cos( f * 2.0f * idMath::PI ) - 1.0f ) * 0.5f;
		ofs += f * weaponOffsetScale * acc->dir;
	}

	return ofs;
}

/*
==============
idPlayer::CalculateViewWeaponPos

Calculate the bobbing position of the view weapon
==============
*/
void idPlayer::CalculateViewWeaponPos( idVec3 &origin, idMat3 &axis ) {
	float		scale;
	float		fracsin;
	idAngles	angles;
	int			delta;


	// CalculateRenderView must have been called first
	const idVec3 &viewOrigin = firstPersonViewOrigin;
	const idMat3 &viewAxis = firstPersonViewAxis;

	// these cvars are just for hand tweaking before moving a value to the weapon def
	idVec3	gunpos( g_gun_x.GetFloat(), g_gun_y.GetFloat(), g_gun_z.GetFloat() );

	// as the player changes direction, the gun will take a small lag
	idVec3	gunOfs = GunAcceleratingOffset();
	origin = viewOrigin + ( gunpos + gunOfs ) * viewAxis;

	// on odd legs, invert some angles
	if ( bobCycle & 128 ) {
		scale = -xyspeed;
	} else {
		scale = xyspeed;
	}

	// gun angles from bobbing
	angles.roll		= scale * bobfracsin * 0.005f;
	angles.yaw		= scale * bobfracsin * 0.01f;
	angles.pitch	= xyspeed * bobfracsin * 0.005f;



	// gun angles from turning
	if ( gameLocal.isMultiplayer ) {
		idAngles offset = GunTurningOffset();
		offset *= g_mpWeaponAngleScale.GetFloat();
		angles += offset;
	} else {
		angles += GunTurningOffset();
	}

	idVec3 gravity = physicsObj.GetGravityNormal();

	// drop the weapon when landing after a jump / fall
	delta = gameLocal.time - landTime;
	if ( delta < LAND_DEFLECT_TIME ) {
		origin -= gravity * ( landChange*0.25f * delta / LAND_DEFLECT_TIME );
	} else if ( delta < LAND_DEFLECT_TIME + LAND_RETURN_TIME ) {
		origin -= gravity * ( landChange*0.25f * (LAND_DEFLECT_TIME + LAND_RETURN_TIME - delta) / LAND_RETURN_TIME );
	}

	if (iteminspectActive) //don't rotate the weapon during iteminspect
		return;

	// speed sensitive idle drift
	scale = xyspeed + 40.0f;
	fracsin = scale * sin( MS2SEC( gameLocal.time ) ) * 0.01f;
	angles.roll		+= fracsin;
	angles.yaw		+= fracsin;
	angles.pitch	+= fracsin;

	axis = angles.ToMat3() * viewAxis;


	//BC make the weapon do a bash lerp anim.
	if (carryableBashActive)
	{
		idVec3 forward;
		viewAngles.ToVectors(&forward, NULL, NULL);

		float lerp = Min(1.0f, 1.0f - ((carryableBashTimer - gameLocal.time) / (float)CARRYABLE_MELEE_ANIMATIONTIME));
		lerp = idMath::CubicEaseOut(lerp);

		idVec3 bashTargetPosition = firstPersonViewOrigin + (forward * 8);
		bashTargetPosition.Lerp(origin, bashTargetPosition, 0.3f); //Find where the bash apex position is.

		origin.Lerp(bashTargetPosition, origin, lerp); //Lerp it to do the bash animation.
	}
}

/*
===============
idPlayer::OffsetThirdPersonView
===============
*/
void idPlayer::OffsetThirdPersonView( float angle, float range, float height, bool clip ) {
	idVec3			view;
	idVec3			focusAngles;
	trace_t			trace;
	idVec3			focusPoint;
	float			focusDist;
	float			forwardScale, sideScale;
	idVec3			origin;
	idAngles		angles;
	idMat3			axis;
	idBounds		bounds;

	angles = viewAngles;
	GetViewPos( origin, axis );

	if ( angle ) {
		angles.pitch = 0.0f;
	}

	if ( angles.pitch > 45.0f ) {
		angles.pitch = 45.0f;		// don't go too far overhead
	}

	focusPoint = origin + angles.ToForward() * THIRD_PERSON_FOCUS_DISTANCE;
	focusPoint.z += height;
	view = origin;
	view.z += 8 + height;

	angles.pitch *= 0.5f;
	renderView->viewaxis = angles.ToMat3() * physicsObj.GetGravityAxis();

	idMath::SinCos( DEG2RAD( angle ), sideScale, forwardScale );
	view -= range * forwardScale * renderView->viewaxis[ 0 ];
	
	//view += range * sideScale * renderView->viewaxis[ 1 ];
	//BC offset thirdperson cam laterally. So that the body doesn't block stuff directly in front of player body model.
	#define	THIRDPERSON_LATERALOFFSET .2f
	view += range * (sideScale - THIRDPERSON_LATERALOFFSET) * renderView->viewaxis[1];

	if ( clip ) {
		// trace a ray from the origin to the viewpoint to make sure the view isn't
		// in a solid block.  Use an 8 by 8 block to prevent the view from near clipping anything
		bounds = idBounds( idVec3( -4, -4, -4 ), idVec3( 4, 4, 4 ) );
		gameLocal.clip.TraceBounds( trace, origin, view, bounds, MASK_SOLID, this );
		if ( trace.fraction != 1.0f ) {
			view = trace.endpos;
			view.z += ( 1.0f - trace.fraction ) * 32.0f;

			// try another trace to this position, because a tunnel may have the ceiling
			// close enough that this is poking out
			gameLocal.clip.TraceBounds( trace, origin, view, bounds, MASK_SOLID, this );
			view = trace.endpos;
		}
	}

	// select pitch to look at focus point from vieword
	focusPoint -= view;
	focusDist = idMath::Sqrt( focusPoint[0] * focusPoint[0] + focusPoint[1] * focusPoint[1] );
	if ( focusDist < 1.0f ) {
		focusDist = 1.0f;	// should never happen
	}

	angles.pitch = - RAD2DEG( atan2( focusPoint.z, focusDist ) );
	angles.yaw -= angle;

	renderView->vieworg = view;
	renderView->viewaxis = angles.ToMat3() * physicsObj.GetGravityAxis();
	renderView->viewID = 0;
}

/*
===============
idPlayer::GetEyePosition
===============
*/
idVec3 idPlayer::GetEyePosition( void ) const {
	idVec3 org;

	// use the smoothed origin if spectating another player in multiplayer
	if ( gameLocal.isClient && entityNumber != gameLocal.localClientNum ) {
		org = smoothedOrigin;
	} else {
		org = GetPhysics()->GetOrigin();
	}
	return org + ( GetPhysics()->GetGravityNormal() * -eyeOffset.z );
}

/*
===============
idPlayer::GetViewPos
===============
*/
void idPlayer::GetViewPos( idVec3 &origin, idMat3 &axis ) const {
	idAngles angles;

	// if dead, fix the angle and don't add any kick
	if ( health <= 0 && !IsInMech() )
	{
		angles.yaw = viewAngles.yaw;
		angles.roll = 40;
		angles.pitch = -15;
		axis = angles.ToMat3();
		origin = GetEyePosition();
	}
	else
	{
		origin = GetEyePosition() + viewBob;
		angles = viewAngles + viewBobAngles + playerView.AngleOffset();

		axis = angles.ToMat3() * physicsObj.GetGravityAxis();

		// adjust the origin based on the camera nodal distance (eye distance from neck)
		origin += physicsObj.GetGravityNormal() * g_viewNodalZ.GetFloat();
		origin += axis[0] * g_viewNodalX.GetFloat() + axis[2] * g_viewNodalZ.GetFloat();
	}
}

/*
===============
idPlayer::CalculateFirstPersonView
===============
*/
void idPlayer::CalculateFirstPersonView( void ) {
	if ( ( pm_modelView.GetInteger() == 1 ) || ( ( pm_modelView.GetInteger() == 2 ) && ( health <= 0 ) ) )
	{
		//	Displays the view from the point of view of the "camera" joint in the player model

		idMat3 axis;
		idVec3 origin;
		idAngles ang;

		ang = viewBobAngles + playerView.AngleOffset();
		ang.yaw += viewAxis[ 0 ].ToYaw() + 90;

		jointHandle_t joint = animator.GetJointHandle( "camera" );
		animator.GetJointTransform( joint, gameLocal.time, origin, axis );
		firstPersonViewOrigin = ( origin + modelOffset ) * ( viewAxis * physicsObj.GetGravityAxis() ) + physicsObj.GetOrigin() + viewBob;
		firstPersonViewAxis = axis * ang.ToMat3() * physicsObj.GetGravityAxis();
	}
	else
	{

		// offset for local bobbing and kicks
		GetViewPos(firstPersonViewOrigin, firstPersonViewAxis);

		//Handle camera when doing splits.
		if (physicsObj.GetAcroType() == ACROTYPE_SPLITS  && physicsObj.GetClamberState() == CLAMBERSTATE_ACRO)
		{
			idVec3 forwardLookDir;
		
			forwardLookDir = idAngles(0, physicsObj.GetAcroAngle(), 0).ToForward();
			forwardLookDir.Normalize();

			//Place camera directly over neck stem.
			firstPersonViewOrigin += forwardLookDir * -8;

			#define ACRO_LOOKDOWNTHRESHOLD 10
			#define ACRO_LOOKDOWN_CAMOFFSET 12

			//If looking down, then lerp camera position forward. So that we're just not lookin down our own neck hole.
			if (viewAngles.pitch > ACRO_LOOKDOWNTHRESHOLD)
			{
				float lerpAmt = (viewAngles.pitch - ACRO_LOOKDOWNTHRESHOLD) / (float)(90 - ACRO_LOOKDOWNTHRESHOLD);
				idVec3 eyeDir;

				eyeDir = idAngles(0, viewAxis[0].ToYaw(), 0).ToForward();
				eyeDir.Normalize();
				
				firstPersonViewOrigin += eyeDir * (lerpAmt * ACRO_LOOKDOWN_CAMOFFSET);
			}
		}
		

		if (mechTransitionState == MECHTRANSITION_PILOTING)
		{
			idVec3 eyeDir = idAngles(0, viewAxis[0].ToYaw(), 0).ToForward();
			firstPersonViewOrigin += eyeDir * MECH_VIEW_OFFSET;
		}


		//do a viewposition offset if we're in a lerp state.
		if (viewposState != LERPSTATE_OFF)
		{
			firstPersonViewOrigin += viewposOffset;
		}


		if (viewposAbsActive)
		{
			idVec3 lerpedPos;
			float lerp = (gameLocal.time - viewposAbsTimer) / (float)viewposAbsDuration;

			lerpedPos.x = idMath::Lerp(viewposAbsStart.x, viewposAbsTarget.x, lerp);
			lerpedPos.y = idMath::Lerp(viewposAbsStart.y, viewposAbsTarget.y, lerp);
			lerpedPos.z = idMath::Lerp(viewposAbsStart.z, viewposAbsTarget.z, lerp);

			firstPersonViewOrigin = lerpedPos;

			if (gameLocal.time >= viewposAbsTimer + viewposAbsDuration)
			{
				viewposAbsActive = false;
			}
		}

		if (peekObject.IsValid())
		{
			//Ventpeek.	

			//position player camera during peeking.
			if (peekObject.GetEntity()->IsType(idVentpeek::Type))
			{
				idVentpeek* ventpeek = static_cast<idVentpeek*>(peekObject.GetEntity());
				if (ventpeek->peekEnt.IsValid())
				{
					firstPersonViewOrigin = ventpeek->peekEnt.GetEntity()->GetPhysics()->GetOrigin();
				}
			}
		}


		if (zoominspect_LabelmodeActive)
		{
			//player is in zoominspect label mode.

			if (gameLocal.hudTime >= zoominspect_lerptimer)
			{
				//fully lerped.
				firstPersonViewOrigin = zoominspect_LabelmodePosition;
			}
			else
			{
				//currently lerping to the zoominspect position.
				float lerp =  1.0f - ((zoominspect_lerptimer - gameLocal.hudTime) / (float)ZOOMINSPECT_LERPTIME);
				lerp = idMath::ClampFloat(0, 1, lerp);
				lerp = idMath::CubicEaseOut(lerp);

				if (zoominspectEntityPtr.IsValid())
				{
					if (zoominspectEntityPtr.GetEntity()->IsType(idAI::Type))
					{
						//Because the AI might be moving around, we need to adjust where the head IS, since the AI might move from where it was.
						idVec3 headPos = static_cast<idAI *>(zoominspectEntityPtr.GetEntity())->GetEyePosition();
						zoominspect_LabelmodePosition = headPos + (zoominspect_LabelmodeAngle.ToForward() * -32) + idVec3(0, 0, -4); //position camera close to baddie, but push away a little via playerview angle
					}
					else
					{
						zoominspect_LabelmodePosition = GetAdjustedLabelInspectionPosition(zoominspectEntityPtr);

						if (g_zoominspectShowCameraPosition.GetBool())
						{
							gameRenderWorld->DebugArrowSimple(zoominspect_LabelmodePosition);
						}
					}
				}				

				firstPersonViewOrigin.Lerp(zoominspect_lerpStartPos, zoominspect_LabelmodePosition, lerp);
			}
		}



		if (leanState == LEANSTATE_ACTIVE || leanState == LEANSTATE_TRANSITIONON)
		{
			//lean logic.
			idVec3 right;
			float leanRoll;

			trace_t headTrace;
			idBounds headBounds;

			int aimDeltaX = 0;
			int aimDeltaY = 0;

			bool movedX = false;
			bool movedY = false;

			float candidateLeanAmountx = leanAmountX;
			float candidateLeanAmounty = leanAmountY;
			
			idVec3 upDir;
			float scaledMx = usercmd.mx * m_leanSensitivity.GetFloat() / LEAN_SENSITIVITY_SCALAR;
			float scaledMy = usercmd.my * m_leanSensitivity.GetFloat() / LEAN_SENSITIVITY_SCALAR;

			if (usercmdGen->IsUsingJoystick())
			{
				scaledMx = usercmdGen->JoystickAxisState(AXIS_RIGHT_X) * LEAN_MAX_X;
				scaledMy = usercmdGen->JoystickAxisState(AXIS_RIGHT_Y) * LEAN_MAX_Y;
			}

			static idVec3 lastViewPos = firstPersonViewOrigin;
			bool viewPosChanged = lastViewPos != firstPersonViewOrigin;
			if (viewPosChanged)
			{
				lastViewPos = firstPersonViewOrigin;
			}
			
			if (lastLeanMouseX != scaledMx || viewPosChanged)
			{
				aimDeltaX = (lastLeanMouseX - scaledMx) * -1;
				lastLeanMouseX = scaledMx;
				movedX = true;
			}

			if (lastLeanMouseY != scaledMy || viewPosChanged)
			{
				aimDeltaY = lastLeanMouseY - scaledMy;
				lastLeanMouseY = scaledMy;
				movedY = true;
			}

			viewAngles.ToVectors(NULL, &right, NULL);

			idAngles forwardAng = viewAngles;
			forwardAng.pitch = 0;
			forwardAng.roll = 0;
			forwardAng.ToVectors(&upDir, NULL, NULL);
			
			//gameRenderWorld->DrawTextA(va("%f", rightTrace.fraction), GetEyePosition() + idVec3(0, 12, 0), .1f, colorWhite, gameLocal.GetLocalPlayer()->viewAngles.ToMat3(), 1, 100);
			if (movedX)
				candidateLeanAmountx += aimDeltaX;
			if (movedY)
				candidateLeanAmounty += aimDeltaY; //BC move mouse forward = ALWAYS move head forward.
			
			//BC disable the lean up/down.
			//if (idMath::Fabs(viewAngles.pitch) < LEAN_LEANFORWARD_THRESHOLD)
			//{
			//	//player looking forward-ish.
			//	upDir = idVec3(0, 0, 1);
			//
			//	if (movedY)
			//	{
			//		candidateLeanAmounty = leanAmountY + aimDeltaY;
			//
			//		headBounds = idBounds(idVec3(-LEAN_HEAD_RADIUS, -LEAN_HEAD_RADIUS, -LEAN_HEAD_RADIUS), idVec3(LEAN_HEAD_RADIUS, LEAN_HEAD_RADIUS, LEAN_HEAD_RADIUS));
			//		gameLocal.clip.TraceBounds(traceHead,
			//			firstPersonViewOrigin + (upDir * candidateLeanAmounty),
			//			firstPersonViewOrigin + (upDir * candidateLeanAmounty),
			//			headBounds, MASK_SOLID, this);
			//
			//		if (candidateLeanAmounty < -LEAN_MAX_Y || candidateLeanAmounty > LEAN_MAX_Y || traceHead.fraction < 1)
			//		{
			//			//invalid
			//		}
			//		else
			//		{
			//			leanAmountY = candidateLeanAmounty;
			//		}
			//	}
			//}

			//if (movedX || movedY)
			if (movedX)
			{
				// Clamp within max lean values
				candidateLeanAmountx = idMath::ClampFloat(-LEAN_MAX_X, LEAN_MAX_X, candidateLeanAmountx);
				//candidateLeanAmounty = idMath::ClampFloat(0, LEAN_MAX_Y_LEANFORWARD, candidateLeanAmounty);
				candidateLeanAmounty = 0;

				//If the player moves mouse very quickly, they can smash their head straight through walls or models or doors.
				//So, we do a trace check to verify the head isn't doing anything illegal like this.
				headBounds = idBounds(idVec3(-LEAN_HEAD_RADIUS, -LEAN_HEAD_RADIUS, -LEAN_HEAD_RADIUS), idVec3(LEAN_HEAD_RADIUS, LEAN_HEAD_RADIUS, LEAN_HEAD_RADIUS));
				gameLocal.clip.TraceBounds(
					headTrace,
					firstPersonViewOrigin,
					firstPersonViewOrigin + (right * candidateLeanAmountx) + (upDir * candidateLeanAmounty),
					headBounds,
					MASK_SOLID,
					this);

				if (headTrace.fraction < 1)
				{
					// Offset based on wherever our head bumped into
					lastLeanOffset = headTrace.endpos - firstPersonViewOrigin;

					// We need to reverse-engineer leanAmountX and leanAmountY because they will be used as reference on the next frame!
					// We know that the offset must consist of some amount of 'right' and 'up', and we know that right and up will be at right-angles to each other.
					// This lets us build a right-angled triangle and solve quickly with trig
					float angleWithRight = idMath::ACos(DotProduct(lastLeanOffset.Normalized(), right));
					leanAmountX = idMath::Cos(angleWithRight) * lastLeanOffset.LengthFast();
					leanAmountY = (lastLeanOffset - (right * leanAmountX)).LengthFast();
				}
				else
				{
					leanAmountX = candidateLeanAmountx;
					leanAmountY = candidateLeanAmounty;
					lastLeanOffset = (right * leanAmountX) + (upDir * leanAmountY);
				}
			}
			//do camera roll.
			leanRoll = (float)(idMath::Abs(leanAmountX) / (float)LEAN_MAX_X) * -LEAN_MAXROLL;
			if (leanAmountX > 0) { leanRoll *= -1.0f; }
			viewAngles.roll = leanRoll;		

			//check status of listen mode.
			SetListenModeActive(UpdateListenStatus(firstPersonViewOrigin + lastLeanOffset));

			firstPersonViewOrigin += lastLeanOffset;
		}
		else if (leanState == LEANSTATE_TRANSITIONOFF)
		{
			if (gameLocal.time >= lastLeanTime + LEAN_RESETTIME)
			{
				//done with lean reset.
				leanState = LEANSTATE_OFF;
				viewAngles.roll = 0;
				leanAmountX = 0;
				leanAmountY = 0;
				lastLeanOffset = idVec3(0, 0, 0);

				SetListenModeActive(false);
			}
			else
			{
				//do the lean reset lerp.
				idAngles resetAng;
				float lerp;
				idVec3 newOffset;

				lerp = (gameLocal.time - lastLeanTime) / (float)LEAN_RESETTIME;				

				if (lerp > 1.0f) { lerp = 1.0f; }

				lerp = idMath::CubicEaseOut(lerp);

				resetAng.yaw = viewAngles.yaw;
				resetAng.roll = idMath::Lerp(lastLeanRoll, 0.0f, lerp);
				resetAng.pitch = viewAngles.pitch;


				newOffset.Lerp(lastLeanOffset, vec3_zero, lerp);
				firstPersonViewOrigin += newOffset;

				SetViewAngles(resetAng);
			}
		}

#if 0
		// shakefrom sound stuff only happens in first person
		firstPersonViewAxis = firstPersonViewAxis * playerView.ShakeAxis();
#endif
	}


}

bool idPlayer::UpdateListenStatus(idVec3 headPosition)
{
	trace_t trUp, trDown, trLeft, trRight;
	idAngles viewNormalized;
	idVec3 right, up;
	int entNum = -1;
	bool value = false;

	viewNormalized = viewAngles; //zero out the pitch and roll.
	viewNormalized.pitch = 0;
	viewNormalized.roll = 0;
	viewNormalized.ToVectors(NULL, &right, &up);

	gameLocal.clip.TracePoint(trUp, headPosition, headPosition + (up * LISTENMODE_HEAD_RADIUS), MASK_SOLID, this);
	gameLocal.clip.TracePoint(trDown, headPosition, headPosition + (up * -LISTENMODE_HEAD_RADIUS), MASK_SOLID, this);
	gameLocal.clip.TracePoint(trLeft, headPosition, headPosition + (right * -LISTENMODE_HEAD_RADIUS), MASK_SOLID, this);
	gameLocal.clip.TracePoint(trRight, headPosition, headPosition + (right * LISTENMODE_HEAD_RADIUS), MASK_SOLID, this);

	if (trUp.fraction < 1)
		entNum = trUp.c.entityNum;
	else if (trDown.fraction < 1)
		entNum = trDown.c.entityNum;
	else if (trLeft.fraction < 1)
		entNum = trLeft.c.entityNum;
	else if (trRight.fraction < 1)
		entNum = trRight.c.entityNum;

	if (entNum >= 0)
	{
		//If lean on door or wall, then activate listen mode.
		//if (gameLocal.entities[entNum]->IsType(idWorldspawn::Type) || gameLocal.entities[entNum]->IsType(idDoor::Type))
        if (gameLocal.entities[entNum]->IsType(idDoor::Type))
		{
			value = true;
		}
	}

	if (lastListenmodeActive != value)
	{
		if (value)
		{
			//listenmode is turning ON.

			if (gameLocal.entities[entNum]->IsType(idDoor::Type))
			{
				//listen through the door.
				idVec3 forward, candidatePos1, candidatePos2;
				gameLocal.entities[entNum]->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, NULL, NULL);

				//get positions on both sides of the door.
				candidatePos1 = gameLocal.entities[entNum]->GetPhysics()->GetOrigin() + (forward * 16) + idVec3(0,0,8);
				candidatePos2 = gameLocal.entities[entNum]->GetPhysics()->GetOrigin() + (forward * -16) + idVec3(0, 0, 8);

				//figure out which side is farther from player.
				if ((firstPersonViewOrigin - candidatePos1).LengthFast() > (firstPersonViewOrigin - candidatePos2).LengthFast())
				{
					listenmodePos = candidatePos1;
				}
				else
				{
					listenmodePos = candidatePos2;
				}
			}
			else
			{
				//my eyeball is my ear.
				listenmodePos = firstPersonViewOrigin;
			}

			gameSoundWorld->FadeSoundClasses(SOUNDCLASS_ALL, LISTENMODE_AUDIOMUFFLE, 2.0f);
			gameSoundWorld->FadeSoundClasses(SOUNDCLASS_FOOTSTEPS, LISTENMODE_FOOTSTEPVOLUME, 1.0f);

			//For the 'xx enemies in next room' ui.
			listenmodeVisualizerTime = gameLocal.time; //Start the listemmode meter.
			hud->SetStateBool("listenfull", false);
			listenProbemodeActive = false;

			//Determine whether the player is leaning left or right. move the 'enemies in next room' ui accordingly.
			hud->HandleNamedEvent((viewAngles.roll < 0) ? "listenboxLeft" : "listenboxRight");
		}
		else
		{
			//listenmode is turning OFF.
			gameSoundWorld->FadeSoundClasses(SOUNDCLASS_ALL, 0, .1f);
			gameSoundWorld->FadeSoundClasses(SOUNDCLASS_FOOTSTEPS, 0, .1f);
		}

		lastListenmodeActive = value;
	}

	

	return value;
}

trace_t idPlayer::GetWallCorner(void)
{
	idVec3 right, forward, up;
	idAngles flatAngle;

	flatAngle = viewAngles; //zero out the pitch and roll.
	flatAngle.pitch = 0;
	flatAngle.roll = 0;
	flatAngle.ToVectors(&forward, &right, &up);

	trace_t rightPos = GetWallCornerTrace(4, right, forward, up);
	trace_t leftPos = GetWallCornerTrace(-4, right, forward, up);

	if (rightPos.endpos != vec3_zero && leftPos.endpos != vec3_zero)
	{
		return trace_t();
	}
	else if (rightPos.endpos != vec3_zero)
	{
		return rightPos;
	}
	else
	{
		return leftPos;
	}
}

//creep the traceline along the wall until we find the edge of it; the edge of the wall's corner.
trace_t idPlayer::GetWallCornerTrace(int deltaDistance, idVec3 right, idVec3 forward, idVec3 up)
{
	const int WALLCHECK_MAX_RIGHT = 48;
	const int WALLCHECK_HAND_RAISE_AMOUNT = -8;
	const int WALLCHECK_FORWARD_TRACEAMOUNT = 48;
	const float WALLCHECK_SMALL_DELTA_AMOUNT = .2f;
	const float WALLCHECK_DOT_THRESHOLD = -.8f;

	int i;
	//bool isCorner = false;
	trace_t lastTrace;
	
	trace_t trDummy;

	idAngles playerAng = viewAngles;
	playerAng.roll = 0;
	playerAng.pitch = 0;

	trDummy.endpos = vec3_zero;


	for (i = 0; idMath::Abs(i) < WALLCHECK_MAX_RIGHT; i += deltaDistance)
	{
		float vdot;
		trace_t tr;
		idVec3 startTrace = GetEyePosition() + (right * i) + (up * WALLCHECK_HAND_RAISE_AMOUNT);
		idVec3 endTrace = startTrace + (forward * WALLCHECK_FORWARD_TRACEAMOUNT);
		gameLocal.clip.TracePoint(tr, startTrace, endTrace, MASK_SOLID, this);
		
		

		//gameRenderWorld->DebugArrow(colorYellow, startTrace, tr.endpos, 4, 2000);

		vdot = DotProduct(tr.c.normal, playerAng.ToForward());

		if (tr.fraction >= 1 || (tr.fraction < 1 && vdot > WALLCHECK_DOT_THRESHOLD))
		{
			float k, smallDeltaValue;
			//traceline hit nothing. Therefore we have reason to believe there's a corner exists near here!

			if (deltaDistance > 0)
				smallDeltaValue = WALLCHECK_SMALL_DELTA_AMOUNT;
			else
				smallDeltaValue = -WALLCHECK_SMALL_DELTA_AMOUNT;

			//do a more detailed trace check with a smaller delta.
			for (k = 0; idMath::Abs(k) < 8.0f; k += smallDeltaValue)
			{
				idVec3 detailedStartTrace = GetEyePosition() + (right * (i - (deltaDistance))) + (up * (WALLCHECK_HAND_RAISE_AMOUNT -.1f)) +(right * k);
				idVec3 detailedEndTrace = detailedStartTrace + (forward * WALLCHECK_FORWARD_TRACEAMOUNT);
				gameLocal.clip.TracePoint(tr, detailedStartTrace, detailedEndTrace, MASK_SOLID, this);


				//gameRenderWorld->DebugArrow(colorOrange, detailedStartTrace, tr.endpos, 4, 2000);

				vdot = DotProduct(tr.c.normal, playerAng.ToForward());

				if (tr.fraction >= 1 || (tr.fraction < 1 && vdot > WALLCHECK_DOT_THRESHOLD))
				{
					//found the detailed spot.
					

					//do a check to make sure the hand is in a position that correctly faces the player.
					
					vdot = DotProduct(lastTrace.c.normal, playerAng.ToForward());

					//common->Printf("%f\n", vdot);

					if (vdot < WALLCHECK_DOT_THRESHOLD)
					{
						return lastTrace;
					}

					return trDummy;
				}

				lastTrace = tr;
			}
		}
	}

	return trDummy;
}


void idPlayer::SetListenModeActive(bool value)
{
	hud->SetStateBool("listenmode", value);

	this->listenmodeActive = value;

	if (lastListenmodeActive != listenmodeActive)
	{
		if (!value)
		{
			//listenmode is turning OFF.
			gameSoundWorld->FadeSoundClasses(0, 0, .1f);
			gameSoundWorld->FadeSoundClasses(2, 0, .1f);
		}

		lastListenmodeActive = value;
	}
}



/*
==================
idPlayer::GetRenderView

Returns the renderView that was calculated for this tic
==================
*/
renderView_t *idPlayer::GetRenderView( void ) {
	return renderView;
}

/*
==================
idPlayer::CalculateRenderView

create the renderView for the current tic
==================
*/
void idPlayer::CalculateRenderView( void ) {
	int i;
	

	if ( !renderView ) {
		renderView = new renderView_t;
	}
	memset( renderView, 0, sizeof( *renderView ) );

	// copy global shader parms
	for( i = 0; i < MAX_GLOBAL_SHADER_PARMS; i++ ) {
		renderView->shaderParms[ i ] = gameLocal.globalShaderParms[ i ];
	}
	renderView->globalMaterial = gameLocal.GetGlobalMaterial();

#ifdef _D3XP
	renderView->time = gameLocal.slow.time;
#endif

	// calculate size of 3D view
	renderView->x = 0;
	renderView->y = 0;
	renderView->width = SCREEN_WIDTH;
	renderView->height = SCREEN_HEIGHT;
	renderView->viewID = 0;

	// check if we should be drawing from a camera's POV
	if ( !noclip && (gameLocal.GetCamera() || privateCameraView) ) {
		// get origin, axis, and fov
		if ( privateCameraView ) {
			privateCameraView->GetViewParms( renderView );
		} else {
			gameLocal.GetCamera()->GetViewParms( renderView );
		}
	} else {
		if ( g_stopTime.GetBool() ) {
			renderView->vieworg = firstPersonViewOrigin;
			renderView->viewaxis = firstPersonViewAxis;

			if ( !pm_thirdPerson.GetBool() ) {
				// set the viewID to the clientNum + 1, so we can suppress the right player bodies and
				// allow the right player view weapons
				renderView->viewID = entityNumber + 1;
			}
		}
		else if ( pm_thirdPerson.GetBool() || jockeyState == JCK_ATTACHED) //BC this forces camera to be thirdperson when in jockey mode.
		{
			OffsetThirdPersonView( pm_thirdPersonAngle.GetFloat(), pm_thirdPersonRange.GetFloat(), pm_thirdPersonHeight.GetFloat(), pm_thirdPersonClip.GetBool() );
		}
		else if ( pm_thirdPersonDeath.GetBool() && health <= 0)
		{
			//BC Do a little camera dolly when player dies.
			float lerp;
			float range;
			float camHeight;

			lerp = Min(1.0f, (gameLocal.time - deathTimer) / 3000.0f);
			lerp = idMath::CubicEaseOut(lerp);
		
			range = idMath::Lerp(160, 70, lerp);
			camHeight = idMath::Lerp(32, 2, lerp);

			OffsetThirdPersonView( 0.0f, range, camHeight, true );
		}
		else
		{
			renderView->vieworg = firstPersonViewOrigin;
			renderView->viewaxis = firstPersonViewAxis;

			// set the viewID to the clientNum + 1, so we can suppress the right player bodies and
			// allow the right player view weapons
			renderView->viewID = entityNumber + 1;

			if ( g_showPlayerBody.GetBool() && showPlayerBody_Scripted)
			{
				renderEntity.suppressSurfaceInViewID = 0;
			}
			else
			{
				renderEntity.suppressSurfaceInViewID = entityNumber + 1;
			}
		}

		// field of view
		gameLocal.CalcFov( CalcFov( true ), renderView->fov_x, renderView->fov_y );
	}

	if ( renderView->fov_y == 0 ) {
		common->Error( "renderView->fov_y == 0" );
	}

	if ( g_showviewpos.GetBool() ) {
		gameLocal.Printf( "%s : %s\n", renderView->vieworg.ToString(), renderView->viewaxis.ToAngles().ToString() );
	}
}

/*
=============
idPlayer::AddAIKill
=============
*/
void idPlayer::AddAIKill( void ) {

#ifndef _D3XP

	int max_souls;
	int ammo_souls;

	if ( ( weapon_soulcube < 0 ) || ( inventory.weapons & ( 1 << weapon_soulcube ) ) == 0 ) {
		return;
	}

	assert( hud );


	ammo_souls = idWeapon::GetAmmoNumForName( "ammo_souls" );
	max_souls = inventory.MaxAmmoForAmmoClass( this, "ammo_souls" );
	if ( inventory.ammo[ ammo_souls ] < max_souls ) {
		inventory.ammo[ ammo_souls ]++;
		if ( inventory.ammo[ ammo_souls ] >= max_souls ) {
			hud->HandleNamedEvent( "soulCubeReady" );
			StartSound( "snd_soulcube_ready", SND_CHANNEL_ANY, 0, false, NULL );
		}
	}
#endif
}

/*
=============
idPlayer::SetSoulCubeProjectile
=============
*/
void idPlayer::SetSoulCubeProjectile( idProjectile *projectile ) {
	soulCubeProjectile = projectile;
}

/*
=============
idPlayer::AddProjectilesFired
=============
*/
void idPlayer::AddProjectilesFired( int count ) {
	numProjectilesFired += count;
}

/*
=============
idPlayer::AddProjectileHites
=============
*/
void idPlayer::AddProjectileHits( int count ) {
	numProjectileHits += count;
}

/*
=============
idPlayer::SetLastHitTime
=============
*/
void idPlayer::SetLastHitTime( int time ) {
	idPlayer *aimed = NULL;

	if ( time && lastHitTime != time ) {
		lastHitToggle ^= 1;
	}
	lastHitTime = time;
	if ( !time ) {
		// level start and inits
		return;
	}
	if ( gameLocal.isMultiplayer && ( time - lastSndHitTime ) > 10 ) {
		lastSndHitTime = time;
		StartSound( "snd_hit_feedback", SND_CHANNEL_ANY, SSF_PRIVATE_SOUND, false, NULL );
	}

	if ( cursor && mechTransitionState == MECHTRANSITION_PILOTING) //BC only if in mech.
	{
		cursor->HandleNamedEvent( "mechHitTime" );
	}
	else if (cursor) //BC hitmarker for on-foot; not in mech
	{
		cursor->HandleNamedEvent("hitTime");
	}

	if ( hud ) {
		if ( MPAim != -1 ) {
			if ( gameLocal.entities[ MPAim ] && gameLocal.entities[ MPAim ]->IsType( idPlayer::Type ) ) {
				aimed = static_cast< idPlayer * >( gameLocal.entities[ MPAim ] );
			}
			assert( aimed );
			// full highlight, no fade till loosing aim
			hud->SetStateString( "aim_text", gameLocal.userInfo[ MPAim ].GetString( "ui_name" ) );
			if ( aimed ) {
				hud->SetStateFloat( "aim_color", aimed->colorBarIndex );
			}
			hud->HandleNamedEvent( "aim_flash" );
			MPAimHighlight = true;
			MPAimFadeTime = 0;
		} else if ( lastMPAim != -1 ) {
			if ( gameLocal.entities[ lastMPAim ] && gameLocal.entities[ lastMPAim ]->IsType( idPlayer::Type ) ) {
				aimed = static_cast< idPlayer * >( gameLocal.entities[ lastMPAim ] );
			}
			assert( aimed );
			// start fading right away
			hud->SetStateString( "aim_text", gameLocal.userInfo[ lastMPAim ].GetString( "ui_name" ) );
			if ( aimed ) {
				hud->SetStateFloat( "aim_color", aimed->colorBarIndex );
			}
			hud->HandleNamedEvent( "aim_flash" );
			hud->HandleNamedEvent( "aim_fade" );
			MPAimHighlight = false;
			MPAimFadeTime = gameLocal.realClientTime;
		}
	}
}

/*
=============
idPlayer::SetInfluenceLevel
=============
*/
void idPlayer::SetInfluenceLevel( int level ) {
	if ( level != influenceActive ) {
		if ( level ) {
			for ( idEntity *ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next() ) {
				if ( ent->IsType( idProjectile::Type ) ) {
					// remove all projectiles
					ent->PostEventMS( &EV_Remove, 0 );
				}
			}
			if ( weaponEnabled && weapon.GetEntity() ) {
				weapon.GetEntity()->EnterCinematic();
			}
		} else {
			physicsObj.SetLinearVelocity( vec3_origin );
			if ( weaponEnabled && weapon.GetEntity() ) {
				weapon.GetEntity()->ExitCinematic();
			}
		}
		influenceActive = level;
	}
}

/*
=============
idPlayer::SetInfluenceView
=============
*/
void idPlayer::SetInfluenceView( const char *mtr, const char *skinname, float radius, idEntity *ent ) {
	influenceMaterial = NULL;
	influenceEntity = NULL;
	influenceSkin = NULL;
	if ( mtr && *mtr ) {
		influenceMaterial = declManager->FindMaterial( mtr );
	}
	if ( skinname && *skinname ) {
		influenceSkin = declManager->FindSkin( skinname );
		if ( head.GetEntity() ) {
			head.GetEntity()->GetRenderEntity()->shaderParms[ SHADERPARM_TIMEOFFSET ] = -MS2SEC( gameLocal.time );
		}
		UpdateVisuals();
	}
	influenceRadius = radius;
	if ( radius > 0.0f ) {
		influenceEntity = ent;
	}
}

/*
=============
idPlayer::SetInfluenceFov
=============
*/
void idPlayer::SetInfluenceFov( float fov ) {
	influenceFov = fov;
}

/*
================
idPlayer::OnLadder
================
*/
bool idPlayer::OnLadder( void ) const {
	return physicsObj.OnLadder();
}

/*
==================
idPlayer::Event_GetButtons
==================
*/
void idPlayer::Event_GetButtons( void ) {
	idThread::ReturnInt( usercmd.buttons );
}

/*
==================
idPlayer::Event_GetMove
==================
*/
void idPlayer::Event_GetMove( void ) {
	idVec3 move( usercmd.forwardmove, usercmd.rightmove, usercmd.upmove );
	idThread::ReturnVector( move );
}

/*
================
idPlayer::Event_GetViewAngles
================
*/
void idPlayer::Event_GetViewAngles( void ) {
	idThread::ReturnVector( idVec3( viewAngles[0], viewAngles[1], viewAngles[2] ) );
}

/*
==================
idPlayer::Event_StopFxFov
==================
*/
void idPlayer::Event_StopFxFov( void ) {
	fxFov = false;
}

/*
==================
idPlayer::StartFxFov
==================
*/
void idPlayer::StartFxFov( float duration ) {
	fxFov = true;
	PostEventSec( &EV_Player_StopFxFov, duration );
}

/*
==================
idPlayer::Event_EnableWeapon
==================
*/
void idPlayer::Event_EnableWeapon( void ) {
	hiddenWeapon = gameLocal.world->spawnArgs.GetBool( "no_Weapons" );
	weaponEnabled = true;
	if ( weapon.GetEntity() ) {
		weapon.GetEntity()->ExitCinematic();
	}
}

/*
==================
idPlayer::Event_DisableWeapon
==================
*/
void idPlayer::Event_DisableWeapon( void ) {
	hiddenWeapon = gameLocal.world->spawnArgs.GetBool( "no_Weapons" );
	weaponEnabled = false;
	
	if ( weapon.GetEntity() )
	{
		weapon.GetEntity()->EnterCinematic();
	}
}

#ifdef _D3XP
/*
==================
idPlayer::Event_GiveInventoryItem
==================
*/
void idPlayer::Event_GiveInventoryItem( const char* name ) {
	GiveInventoryItem(name);
}

/*
==================
idPlayer::Event_RemoveInventoryItem
==================
*/
void idPlayer::Event_RemoveInventoryItem( const char* name ) {
	RemoveInventoryItem(name);
}

/*
==================
idPlayer::Event_GetIdealWeapon
==================
*/
void idPlayer::Event_GetIdealWeapon( void ) {
	const char *weapon;

	if ( idealWeaponSlot >= 0 ) {
		weapon = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[idealWeaponSlot] ) );
		idThread::ReturnString( weapon );
	} else {
		idThread::ReturnString( "" );
	}
}

/*
==================
idPlayer::Event_SetPowerupTime
==================
*/
void idPlayer::Event_SetPowerupTime( int powerup, int time ) {
	if ( time > 0 ) {
		GivePowerUp( powerup, time );
	} else {
		ClearPowerup( powerup );
	}
}

/*
==================
idPlayer::Event_IsPowerupActive
==================
*/
void idPlayer::Event_IsPowerupActive( int powerup ) {
	idThread::ReturnInt(this->PowerUpActive(powerup) ? 1 : 0);
}

/*
==================
idPlayer::Event_StartWarp
==================
*/
void idPlayer::Event_StartWarp()
{
	playerView.AddWarp( idVec3( 0, 0, 0 ), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100, 1000 );
}

/*
==================
idPlayer::Event_StopHelltime
==================
*/
void idPlayer::Event_StopHelltime( int mode ) {
	if ( mode == 1 ) {
		StopHelltime( true );
	}
	else {
		StopHelltime( false );
	}
}

/*
==================
idPlayer::Event_WeaponAvailable
==================
*/
void idPlayer::Event_WeaponAvailable( const char* name ) {

	idThread::ReturnInt( WeaponAvailable(name) ? 1 : 0 );
}

bool idPlayer::WeaponAvailable( const char* name ) {
	for( int i = 0; i < MAX_HOTBARSLOTS; i++ ) {
		int weaponType = inventory.hotbarSlots[i].weaponType;
		if ( weaponType != -1 ) {
			const char *weap = spawnArgs.GetString( va( "def_weapon%d", weaponType ) );
			if ( !idStr::Cmp( weap, name ) ) {
				return true;
			}
		}
	}
	return false;
}

#endif

/*
==================
idPlayer::Event_GetCurrentWeapon
==================
*/
void idPlayer::Event_GetCurrentWeapon( void ) {
	const char *weapon;
	int weaponType = inventory.hotbarSlots[currentWeaponSlot].weaponType;
	if ( weaponType >= 0 ) {
		weapon = spawnArgs.GetString( va( "def_weapon%d", weaponType ) );
		idThread::ReturnString( weapon );
	} else {
		idThread::ReturnString( "" );
	}
}

/*
==================
idPlayer::Event_GetPreviousWeapon
==================
*/
void idPlayer::Event_GetPreviousWeapon( void ) {
	const char *weapon;
	int weaponType = previousWeaponSlot >= 0 ? inventory.hotbarSlots[previousWeaponSlot].weaponType : -1;
	if ( weaponType >= 0 ) {
		int pw = ( gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) ) ? 0 : weaponType;
		weapon = spawnArgs.GetString( va( "def_weapon%d", pw) );
		idThread::ReturnString( weapon );
	} else {
		idThread::ReturnString( spawnArgs.GetString( "def_weapon0" ) );
	}
}

/*
==================
idPlayer::Event_SelectWeapon
==================
*/
void idPlayer::Event_SelectWeapon( const char *weaponName ) {
	int i;

	if ( gameLocal.isClient ) {
		gameLocal.Warning( "Cannot switch weapons from script in multiplayer" );
		return;
	}

	if ( hiddenWeapon && gameLocal.world->spawnArgs.GetBool( "no_Weapons" ) ) {
		idealWeaponSlot = -1;
		weapon.GetEntity()->HideWeapon();
		return;
	}

	int hotbarSlot = -1;
	for( i = 0; i < MAX_HOTBARSLOTS; i++ ) {
		if ( inventory.hotbarSlots[i].weaponType >= 0 ) {
			const char *weap = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[i].weaponType ) );
			if ( !idStr::Cmp( weap, weaponName ) ) {
				hotbarSlot = i;
				break;
			}
		}
	}

	if ( hotbarSlot < 0 ) {
		gameLocal.Warning( "%s is not carrying weapon '%s'", name.c_str(), weaponName );
		return;
	}

	hiddenWeapon = false;
	idealWeaponSlot = hotbarSlot;

	UpdateHudWeapon();
}

/*
==================
idPlayer::Event_GetWeaponEntity
==================
*/
void idPlayer::Event_GetWeaponEntity( void ) {
	idThread::ReturnEntity( weapon.GetEntity() );
}

/*
==================
idPlayer::Event_OpenPDA
==================
*/
void idPlayer::Event_OpenPDA( void ) {
	if ( !gameLocal.isMultiplayer ) {
		TogglePDA();
	}
}

/*
==================
idPlayer::Event_InPDA
==================
*/
void idPlayer::Event_InPDA( void ) {
	idThread::ReturnInt( objectiveSystemOpen );
}

/*
==================
idPlayer::TeleportDeath
==================
*/
void idPlayer::TeleportDeath( int killer ) {
	teleportKiller = killer;
}

/*
==================
idPlayer::Event_ExitTeleporter
==================
*/
void idPlayer::Event_ExitTeleporter( void ) {
	idEntity	*exitEnt;
	float		pushVel;

	// verify and setup
	exitEnt = teleportEntity.GetEntity();
	if ( !exitEnt ) {
		common->DPrintf( "Event_ExitTeleporter player %d while not being teleported\n", entityNumber );
		return;
	}

	pushVel = exitEnt->spawnArgs.GetFloat( "push", "300" );

	if ( gameLocal.isServer ) {
		ServerSendEvent( EVENT_EXIT_TELEPORTER, NULL, false, -1 );
	}

	SetPrivateCameraView( NULL );
	// setup origin and push according to the exit target
	SetOrigin( exitEnt->GetPhysics()->GetOrigin() + idVec3( 0, 0, CM_CLIP_EPSILON ) );
	SetViewAngles( exitEnt->GetPhysics()->GetAxis().ToAngles() );
	physicsObj.SetLinearVelocity( exitEnt->GetPhysics()->GetAxis()[ 0 ] * pushVel );
	physicsObj.ClearPushedVelocity();
	// teleport fx
	playerView.Flash( colorWhite, 120 );

	// clear the ik heights so model doesn't appear in the wrong place
	walkIK.EnableAll();

	UpdateVisuals();

	StartSound( "snd_teleport_exit", SND_CHANNEL_ANY, 0, false, NULL );

	if ( teleportKiller != -1 ) {
		// we got killed while being teleported
		Damage( gameLocal.entities[ teleportKiller ], gameLocal.entities[ teleportKiller ], vec3_origin, "damage_telefrag", 1.0f, INVALID_JOINT );
		teleportKiller = -1;
	} else {
		// kill anything that would have waited at teleport exit
		gameLocal.KillBox( this );
	}
	teleportEntity = NULL;
}

/*
================
idPlayer::ClientPredictionThink
================
*/
void idPlayer::ClientPredictionThink( void ) {
	renderEntity_t *headRenderEnt;

	oldFlags = usercmd.flags;
	oldButtons = usercmd.buttons;

	usercmd = gameLocal.usercmds[ entityNumber ];

	if ( entityNumber != gameLocal.localClientNum ) {
		// ignore attack button of other clients. that's no good for predictions
		usercmd.buttons &= ~BUTTON_ATTACK;
	}

	buttonMask &= usercmd.buttons;
	usercmd.buttons &= ~buttonMask;

#ifdef _D3XP
	if ( mountedObject)
	{
		usercmd.forwardmove = 0;
		usercmd.rightmove = 0;
		usercmd.upmove = 0;
	}
#endif

	if ( objectiveSystemOpen ) {
		usercmd.forwardmove = 0;
		usercmd.rightmove = 0;
		usercmd.upmove = 0;
	}

	// clear the ik before we do anything else so the skeleton doesn't get updated twice
	walkIK.ClearJointMods();

	if ( gameLocal.isNewFrame ) {
		if ( ( usercmd.flags & UCF_IMPULSE_SEQUENCE ) != ( oldFlags & UCF_IMPULSE_SEQUENCE ) ) {
			PerformImpulse( usercmd.impulse );
		}
	}

	

	AdjustSpeed();

	UpdateViewAngles();

	// update the smoothed view angles
	if ( gameLocal.framenum >= smoothedFrame && entityNumber != gameLocal.localClientNum ) {
		idAngles anglesDiff = viewAngles - smoothedAngles;
		anglesDiff.Normalize180();
		if ( idMath::Fabs( anglesDiff.yaw ) < 90.0f && idMath::Fabs( anglesDiff.pitch ) < 90.0f ) {
			// smoothen by pushing back to the previous angles
			viewAngles -= gameLocal.clientSmoothing * anglesDiff;
			viewAngles.Normalize180();
		}
		smoothedAngles = viewAngles;
	}
	smoothedOriginUpdated = false;

	if ( !af.IsActive() ) {
		AdjustBodyAngles();
	}

	if ( !isLagged ) {
		// don't allow client to move when lagged
		Move();
	}

	// update GUIs, Items, and character interactions
	UpdateFocus();

	// service animations
	if ( !spectating && !af.IsActive() ) {
		UpdateConditions();
		UpdateAnimState();
		CheckBlink();
	}

	// clear out our pain flag so we can tell if we recieve any damage between now and the next time we think
	AI_PAIN = false;

	// calculate the exact bobbed view position, which is used to
	// position the view weapon, among other things
	CalculateFirstPersonView();

	// this may use firstPersonView, or a thirdPerson / camera view
	CalculateRenderView();

	if ( !gameLocal.inCinematic && weapon.GetEntity() && ( health > 0 ) && !( gameLocal.isMultiplayer && spectating ) ) {
		UpdateWeapon();
	}

	UpdateHud();

	if ( gameLocal.isNewFrame ) {
		UpdatePowerUps();
	}

	UpdateDeathSkin( false );

	if ( head.GetEntity() ) {
		headRenderEnt = head.GetEntity()->GetRenderEntity();
	} else {
		headRenderEnt = NULL;
	}

	if ( headRenderEnt ) {
		if ( influenceSkin ) {
			headRenderEnt->customSkin = influenceSkin;
		} else {
			headRenderEnt->customSkin = NULL;
		}
	}

	if ( gameLocal.isMultiplayer || g_showPlayerShadow.GetBool() ) {
		renderEntity.suppressShadowInViewID	= 0;
		if ( headRenderEnt ) {
			headRenderEnt->suppressShadowInViewID = 0;
		}
	} else {
		renderEntity.suppressShadowInViewID	= entityNumber+1;
		if ( headRenderEnt ) {
			headRenderEnt->suppressShadowInViewID = entityNumber+1;
		}
	}
	// never cast shadows from our first-person muzzle flashes
	renderEntity.suppressShadowInLightID = LIGHTID_VIEW_MUZZLE_FLASH + entityNumber;
	if ( headRenderEnt ) {
		headRenderEnt->suppressShadowInLightID = LIGHTID_VIEW_MUZZLE_FLASH + entityNumber;
	}

	if ( !gameLocal.inCinematic ) {
		UpdateAnimation();
	}

#ifdef _D3XP
	if ( enviroSuitLight.IsValid() ) {
		idAngles lightAng = firstPersonViewAxis.ToAngles();
		idVec3 lightOrg = firstPersonViewOrigin;
		const idDict *lightDef = gameLocal.FindEntityDefDict( "envirosuit_light", false );

		idVec3 enviroOffset = lightDef->GetVector( "enviro_offset" );
		idVec3 enviroAngleOffset = lightDef->GetVector( "enviro_angle_offset" );

		lightOrg += (enviroOffset.x * firstPersonViewAxis[0]);
		lightOrg += (enviroOffset.y * firstPersonViewAxis[1]);
		lightOrg += (enviroOffset.z * firstPersonViewAxis[2]);
		lightAng.pitch += enviroAngleOffset.x;
		lightAng.yaw += enviroAngleOffset.y;
		lightAng.roll += enviroAngleOffset.z;

		enviroSuitLight.GetEntity()->GetPhysics()->SetOrigin( lightOrg );
		enviroSuitLight.GetEntity()->GetPhysics()->SetAxis( lightAng.ToMat3() );
		enviroSuitLight.GetEntity()->UpdateVisuals();
		enviroSuitLight.GetEntity()->Present();
	}
#endif

	if ( gameLocal.isMultiplayer ) {
		DrawPlayerIcons();
	}

	Present();

	UpdateDamageEffects();

	LinkCombat();

	if ( gameLocal.isNewFrame && entityNumber == gameLocal.localClientNum ) {
		playerView.CalculateShake();
	}

#ifdef _D3XP
	// determine if portal sky is in pvs
	pvsHandle_t	clientPVS = gameLocal.pvs.SetupCurrentPVS( GetPVSAreas(), GetNumPVSAreas() );
	gameLocal.portalSkyActive = gameLocal.pvs.CheckAreasForPortalSky( clientPVS, GetPhysics()->GetOrigin() );
	gameLocal.pvs.FreeCurrentPVS( clientPVS );
#endif
}

/*
================
idPlayer::GetPhysicsToVisualTransform
================
*/
bool idPlayer::GetPhysicsToVisualTransform( idVec3 &origin, idMat3 &axis ) {
	if ( af.IsActive() ) {
		af.GetPhysicsToVisualTransform( origin, axis );
		return true;
	}

	// smoothen the rendered origin and angles of other clients
	// smooth self origin if snapshots are telling us prediction is off
	if ( gameLocal.isClient && gameLocal.framenum >= smoothedFrame && ( entityNumber != gameLocal.localClientNum || selfSmooth ) ) {
		// render origin and axis
		idMat3 renderAxis = viewAxis * GetPhysics()->GetAxis();

		idVec3 renderOrigin = GetPhysics()->GetOrigin() + modelOffset * renderAxis;


		// update the smoothed origin
		if ( !smoothedOriginUpdated ) {
			idVec2 originDiff = renderOrigin.ToVec2() - smoothedOrigin.ToVec2();
			if ( originDiff.LengthSqr() < Square( 100.0f ) ) {
				// smoothen by pushing back to the previous position
				if ( selfSmooth ) {
					assert( entityNumber == gameLocal.localClientNum );
					renderOrigin.ToVec2() -= net_clientSelfSmoothing.GetFloat() * originDiff;
				} else {
					renderOrigin.ToVec2() -= gameLocal.clientSmoothing * originDiff;
				}
			}
			smoothedOrigin = renderOrigin;

			smoothedFrame = gameLocal.framenum;
			smoothedOriginUpdated = true;
		}

		axis = idAngles( 0.0f, smoothedAngles.yaw, 0.0f ).ToMat3();
		origin = ( smoothedOrigin - GetPhysics()->GetOrigin() ) * axis.Transpose();

	} else {

		axis = viewAxis;
		origin = modelOffset;
	}
	return true;
}

/*
================
idPlayer::GetPhysicsToSoundTransform
================
*/
bool idPlayer::GetPhysicsToSoundTransform( idVec3 &origin, idMat3 &axis ) {
	idCamera *camera;

	if ( privateCameraView ) {
		camera = privateCameraView;
	} else {
		camera = gameLocal.GetCamera();
	}

	if ( camera ) {
		renderView_t view;

		memset( &view, 0, sizeof( view ) );
		camera->GetViewParms( &view );
		origin = view.vieworg;
		axis = view.viewaxis;
		return true;
	} else {
		return idActor::GetPhysicsToSoundTransform( origin, axis );
	}
}

/*
================
idPlayer::WriteToSnapshot
================
*/
void idPlayer::WriteToSnapshot( idBitMsgDelta &msg ) const {
	physicsObj.WriteToSnapshot( msg );
	WriteBindToSnapshot( msg );
	msg.WriteDeltaFloat( 0.0f, deltaViewAngles[0] );
	msg.WriteDeltaFloat( 0.0f, deltaViewAngles[1] );
	msg.WriteDeltaFloat( 0.0f, deltaViewAngles[2] );
	msg.WriteShort( health );
	msg.WriteBits( gameLocal.ServerRemapDecl( -1, DECL_ENTITYDEF, lastDamageDef ), gameLocal.entityDefBits );
	msg.WriteDir( lastDamageDir, 9 );
	msg.WriteShort( lastDamageLocation );
	msg.WriteBits( idealWeaponSlot, idMath::BitsForInteger( MAX_WEAPONS ) );
	msg.WriteBits( weapon.GetSpawnId(), 32 );
	msg.WriteBits( spectator, idMath::BitsForInteger( MAX_CLIENTS ) );
	msg.WriteBits( lastHitToggle, 1 );
	msg.WriteBits( weaponGone, 1 );
	msg.WriteBits( isLagged, 1 );
	msg.WriteBits( isChatting, 1 );
#ifdef CTF
	/* Needed for the scoreboard */
	msg.WriteBits( carryingFlag, 1 );
#endif
#ifdef _D3XP
	msg.WriteBits( enviroSuitLight.GetSpawnId(), 32 );
#endif
}

/*
================
idPlayer::ReadFromSnapshot
================
*/
void idPlayer::ReadFromSnapshot( const idBitMsgDelta &msg ) {
	int		i, oldHealth, newIdealWeapon, weaponSpawnId;
	bool	newHitToggle, stateHitch;

	if ( snapshotSequence - lastSnapshotSequence > 1 ) {
		stateHitch = true;
	} else {
		stateHitch = false;
	}
	lastSnapshotSequence = snapshotSequence;

	oldHealth = health;

	physicsObj.ReadFromSnapshot( msg );
	ReadBindFromSnapshot( msg );
	deltaViewAngles[0] = msg.ReadDeltaFloat( 0.0f );
	deltaViewAngles[1] = msg.ReadDeltaFloat( 0.0f );
	deltaViewAngles[2] = msg.ReadDeltaFloat( 0.0f );
	health = msg.ReadShort();
	lastDamageDef = gameLocal.ClientRemapDecl( DECL_ENTITYDEF, msg.ReadBits( gameLocal.entityDefBits ) );
	lastDamageDir = msg.ReadDir( 9 );
	lastDamageLocation = msg.ReadShort();
	newIdealWeapon = msg.ReadBits( idMath::BitsForInteger( MAX_WEAPONS ) );
	weaponSpawnId = msg.ReadBits( 32 );
	spectator = msg.ReadBits( idMath::BitsForInteger( MAX_CLIENTS ) );
	newHitToggle = msg.ReadBits( 1 ) != 0;
	weaponGone = msg.ReadBits( 1 ) != 0;
	isLagged = msg.ReadBits( 1 ) != 0;
	isChatting = msg.ReadBits( 1 ) != 0;
#ifdef CTF
	carryingFlag = msg.ReadBits( 1 ) != 0;
#endif
#ifdef _D3XP
	int enviroSpawnId;
	enviroSpawnId = msg.ReadBits( 32 );
	enviroSuitLight.SetSpawnId( enviroSpawnId );
#endif

	// no msg reading below this

	if ( weapon.SetSpawnId( weaponSpawnId ) ) {
		if ( weapon.GetEntity() ) {
			// maintain ownership locally
			weapon.GetEntity()->SetOwner( this );
		}
		currentWeaponSlot = -1;
	}
	// if not a local client assume the client has all ammo types
	if ( entityNumber != gameLocal.localClientNum ) {
		for( i = 0; i < AMMO_NUMTYPES; i++ ) {
			inventory.ammo[ i ] = 999;
		}
	}

	if ( oldHealth > 0 && health <= 0 ) {
		if ( stateHitch ) {
			// so we just hide and don't show a death skin
			UpdateDeathSkin( true );
		}
		// die
		AI_DEAD = true;
		ClearPowerUps();
		SetAnimState( ANIMCHANNEL_LEGS, "Legs_Death", 4 );
		SetAnimState( ANIMCHANNEL_TORSO, "Torso_Death", 4 );
		SetWaitState( "" );
		animator.ClearAllJoints();
		if ( entityNumber == gameLocal.localClientNum ) {
			playerView.Fade( colorBlack, 12000 );
		}
		StartRagdoll();
		physicsObj.SetMovementType( PM_DEAD );
		if ( !stateHitch ) {
			StartSound( "snd_death", SND_CHANNEL_VOICE, 0, false, NULL );
		}
		if ( weapon.GetEntity() ) {
			weapon.GetEntity()->OwnerDied();
		}
	} else if ( oldHealth <= 0 && health > 0 ) {
		// respawn
		Init();
		StopRagdoll();
		SetPhysics( &physicsObj );
		physicsObj.EnableClip();
		SetCombatContents( true );
	} else if ( health < oldHealth && health > 0 ) {
		if ( stateHitch ) {
			lastDmgTime = gameLocal.time;
		} else {
			// damage feedback
			const idDeclEntityDef *def = static_cast<const idDeclEntityDef *>( declManager->DeclByIndex( DECL_ENTITYDEF, lastDamageDef, false ) );
			if ( def ) {
				playerView.DamageImpulse( lastDamageDir * viewAxis.Transpose(), &def->dict );
				AI_PAIN = Pain( NULL, NULL, oldHealth - health, lastDamageDir, lastDamageLocation );
				lastDmgTime = gameLocal.time;
			} else {
				common->Warning( "NET: no damage def for damage feedback '%d'\n", lastDamageDef );
			}
		}
	} else if ( health > oldHealth && PowerUpActive( MEGAHEALTH ) && !stateHitch ) {
		// just pulse, for any health raise
		healthPulse = true;
	}

#ifdef _D3XP
	// If the player is alive, restore proper physics object
	if ( health > 0 && IsActiveAF() ) {
		StopRagdoll();
		SetPhysics( &physicsObj );
		physicsObj.EnableClip();
		SetCombatContents( true );
	}
#endif

	if ( idealWeaponSlot != newIdealWeapon ) {
		if ( stateHitch ) {
			weaponCatchup = true;
		}
		idealWeaponSlot = newIdealWeapon;
		UpdateHudWeapon();
	}

	if ( lastHitToggle != newHitToggle ) {
		SetLastHitTime( gameLocal.realClientTime );
	}

	if ( msg.HasChanged() ) {
		UpdateVisuals();
	}
}

/*
================
idPlayer::WritePlayerStateToSnapshot
================
*/
void idPlayer::WritePlayerStateToSnapshot( idBitMsgDelta &msg ) const {
	int i;

	msg.WriteByte( bobCycle );
	msg.WriteInt( stepUpTime );
	msg.WriteFloat( stepUpDelta );
	msg.WriteByte( inventory.armor );

	for( i = 0; i < AMMO_NUMTYPES; i++ ) {
		msg.WriteBits( inventory.ammo[i], ASYNC_PLAYER_INV_AMMO_BITS );
	}
}

/*
================
idPlayer::ReadPlayerStateFromSnapshot
================
*/
void idPlayer::ReadPlayerStateFromSnapshot( const idBitMsgDelta &msg ) {
	int i, ammo;

	bobCycle = msg.ReadByte();
	stepUpTime = msg.ReadInt();
	stepUpDelta = msg.ReadFloat();
	inventory.armor = msg.ReadByte();

	for( i = 0; i < AMMO_NUMTYPES; i++ ) {
		ammo = msg.ReadBits( ASYNC_PLAYER_INV_AMMO_BITS );
		if ( gameLocal.time >= inventory.ammoPredictTime ) {
			inventory.ammo[ i ] = ammo;
		}
	}
}

/*
================
idPlayer::ServerReceiveEvent
================
*/
bool idPlayer::ServerReceiveEvent( int event, int time, const idBitMsg &msg ) {

	if ( idEntity::ServerReceiveEvent( event, time, msg ) ) {
		return true;
	}

	// client->server events
	switch( event ) {
		case EVENT_IMPULSE: {
			PerformImpulse( msg.ReadBits( 6 ) );
			return true;
		}
		default: {
			return false;
		}
	}
}

/*
================
idPlayer::ClientReceiveEvent
================
*/
bool idPlayer::ClientReceiveEvent( int event, int time, const idBitMsg &msg ) {
	int powerup;
	bool start;

	switch ( event ) {
		case EVENT_EXIT_TELEPORTER:
			Event_ExitTeleporter();
			return true;
		case EVENT_ABORT_TELEPORTER:
			SetPrivateCameraView( NULL );
			return true;
		case EVENT_POWERUP: {
			powerup = msg.ReadShort();
			start = msg.ReadBits( 1 ) != 0;
			if ( start ) {
				GivePowerUp( powerup, 0 );
			} else {
				ClearPowerup( powerup );
			}
			return true;
		}
#ifdef _D3XP
		case EVENT_PICKUPNAME: {
			char buf[MAX_EVENT_PARAM_SIZE];
			msg.ReadString(buf, MAX_EVENT_PARAM_SIZE);
			inventory.AddPickupName(buf, "", this); //_D3XP
			return true;
		}
#endif
		case EVENT_SPECTATE: {
			bool spectate = ( msg.ReadBits( 1 ) != 0 );
			Spectate( spectate );
			return true;
		}
		case EVENT_ADD_DAMAGE_EFFECT: {
			if ( spectating ) {
				// if we're spectating, ignore
				// happens if the event and the spectate change are written on the server during the same frame (fraglimit)
				return true;
			}
			break;
		}
		default:
			break;
	}

	return idActor::ClientReceiveEvent( event, time, msg );
}

/*
================
idPlayer::Hide
================
*/
void idPlayer::Hide( void ) {
	idWeapon *weap;

	idActor::Hide();
	weap = weapon.GetEntity();
	if ( weap ) {
		weap->HideWorldModel();
	}
}

/*
================
idPlayer::Show
================
*/
void idPlayer::Show( void ) {
	idWeapon *weap;

	idActor::Show();
	weap = weapon.GetEntity();
	if ( weap ) {
		weap->ShowWorldModel();
	}
}

/*
===============
idPlayer::StartAudioLog
===============
*/
void idPlayer::StartAudioLog( void ) {
	if ( hud ) {
		hud->HandleNamedEvent( "audioLogUp" );
	}
}

/*
===============
idPlayer::StopAudioLog
===============
*/
void idPlayer::StopAudioLog( void ) {
	if ( hud ) {
		hud->HandleNamedEvent( "audioLogDown" );
	}
}

/*
===============
idPlayer::ShowTip
===============
*/
void idPlayer::ShowTip( const char *title, const char *tip, bool autoHide ) {
	if ( tipUp ) {
		return;
	}
	hud->SetStateString( "tip", tip );
	hud->SetStateString( "tiptitle", title );
	hud->HandleNamedEvent( "tipWindowUp" );
	if ( autoHide ) {
		PostEventSec( &EV_Player_HideTip, 5.0f );
	}
	tipUp = true;
}

/*
===============
idPlayer::HideTip
===============
*/
void idPlayer::HideTip( void ) {
	hud->HandleNamedEvent( "tipWindowDown" );
	tipUp = false;
}

/*
===============
idPlayer::Event_HideTip
===============
*/
void idPlayer::Event_HideTip( void ) {
	HideTip();
}

/*
===============
idPlayer::ShowObjective
===============
*/
void idPlayer::ShowObjective( const char *obj ) {
	hud->HandleNamedEvent( obj );
	objectiveUp = true;
}

/*
===============
idPlayer::HideObjective
===============
*/
void idPlayer::HideObjective( void ) {
	hud->HandleNamedEvent( "closeObjective" );
	objectiveUp = false;
}

/*
===============
idPlayer::Event_StopAudioLog
===============
*/
void idPlayer::Event_StopAudioLog( void ) {
	StopAudioLog();
}

/*
===============
idPlayer::SetSpectateOrigin
===============
*/
void idPlayer::SetSpectateOrigin( void ) {
	idVec3 neworig = GetEyePosition();
	SetOrigin( neworig );
}

/*
===============
idPlayer::RemoveWeapon
===============
*/
void idPlayer::RemoveWeapon( const char *weap ) {
	if ( weap && *weap ) {
		int weaponIndex = inventory.GetWeaponIndex( this, weap );
		int weaponSlot = inventory.GetHotbarslotViaWeaponIndex( weaponIndex );
		inventory.Drop( weaponSlot );
	}
}

/*
===============
idPlayer::CanShowWeaponViewmodel
===============
*/
bool idPlayer::CanShowWeaponViewmodel( void ) const {
	return showWeaponViewModel;
}

/*
===============
idPlayer::SetLevelTrigger
===============
*/
void idPlayer::SetLevelTrigger( const char *levelName, const char *triggerName ) {
	if ( levelName && *levelName && triggerName && *triggerName ) {
		idLevelTriggerInfo lti;
		lti.levelName = levelName;
		lti.triggerName = triggerName;
		inventory.levelTriggers.Append( lti );
	}
}

/*
===============
idPlayer::Event_LevelTrigger
===============
*/
void idPlayer::Event_LevelTrigger( void ) {
	idStr mapName = gameLocal.GetMapName();
	mapName.StripPath();
	mapName.StripFileExtension();
	for ( int i = inventory.levelTriggers.Num() - 1; i >= 0; i-- ) {
		if ( idStr::Icmp( mapName, inventory.levelTriggers[i].levelName) == 0 ){
			idEntity *ent = gameLocal.FindEntity( inventory.levelTriggers[i].triggerName );
			if ( ent ) {
				ent->PostEventMS( &EV_Activate, 1, this );
			}
		}
	}
}

/*
===============
idPlayer::Event_Gibbed
===============
*/
void idPlayer::Event_Gibbed( void ) {
	// do nothing
	common->Printf("Player gibbed.\n");
}

/*
===============
idPlayer::UpdatePlayerIcons
===============
*/
void idPlayer::UpdatePlayerIcons( void ) {
	int time = networkSystem->ServerGetClientTimeSinceLastPacket( entityNumber );
	if ( time > cvarSystem->GetCVarInteger( "net_clientMaxPrediction" ) ) {
		isLagged = true;
	} else {
		isLagged = false;
	}

}

/*
===============
idPlayer::DrawPlayerIcons
===============
*/
void idPlayer::DrawPlayerIcons( void ) {
	if ( !NeedsIcon() ) {
		playerIcon.FreeIcon();
		return;
	}

#ifdef CTF
	// Never draw icons for hidden players.
	if ( this->IsHidden() )
		return;
#endif

	playerIcon.Draw( this, headJoint );
}

/*
===============
idPlayer::HidePlayerIcons
===============
*/
void idPlayer::HidePlayerIcons( void ) {
	playerIcon.FreeIcon();
}

/*
===============
idPlayer::NeedsIcon
==============
*/
bool idPlayer::NeedsIcon( void ) {
	// local clients don't render their own icons... they're only info for other clients
#ifdef CTF
	// always draw icons in CTF games
	return entityNumber != gameLocal.localClientNum && ( ( g_CTFArrows.GetBool() && gameLocal.mpGame.IsGametypeFlagBased() && !IsHidden() && !AI_DEAD ) || ( isLagged || isChatting ) );
#else
	return entityNumber != gameLocal.localClientNum && ( isLagged || isChatting );
#endif
}

#ifdef CTF
/*
===============
idPlayer::DropFlag()
==============
*/
void idPlayer::DropFlag( void ) {
	if ( !carryingFlag || !gameLocal.isMultiplayer || !gameLocal.mpGame.IsGametypeFlagBased() ) /* CTF */
		return;

	idEntity * entity = gameLocal.mpGame.GetTeamFlag( 1 - this->latchedTeam );
	if ( entity ) {
		idItemTeam * item = static_cast<idItemTeam*>(entity);

		if ( item->carried && !item->dropped ) {
			item->Drop( health <= 0 );
			carryingFlag = false;
		}
	}

}

void idPlayer::ReturnFlag() {

	if ( !carryingFlag || !gameLocal.isMultiplayer || !gameLocal.mpGame.IsGametypeFlagBased() ) /* CTF */
		return;

	idEntity * entity = gameLocal.mpGame.GetTeamFlag( 1 - this->latchedTeam );
	if ( entity ) {
		idItemTeam * item = static_cast<idItemTeam*>(entity);

		if ( item->carried && !item->dropped ) {
			item->Return();
			carryingFlag = false;
		}
	}
}

void idPlayer::FreeModelDef( void ) {
	idAFEntity_Base::FreeModelDef();
	if ( gameLocal.isMultiplayer && gameLocal.mpGame.IsGametypeFlagBased() )
		playerIcon.FreeIcon();
}


idEntity *idPlayer::UpdateAutoAim(void)
{
	idVec3 targetPos;
	idEntity* entity = FindAimAssistTarget(targetPos);
	
	if (entity == NULL)
	{
		//No target.
		if (autoaimDotState == AUTOAIMDOTSTATE_MOVING_TO_LOCK || autoaimDotState == AUTOAIMDOTSTATE_LOCKED)
		{
			lastAutoaimDotState = autoaimDotState;

			//Move dots to idle positions.
			autoaimDotState = AUTOAIMDOTSTATE_MOVING_TO_IDLE;
			autoaimDotTimer = gameLocal.time;

			autoaimDotStartPos = autoaimDotPosition;
			autoaimDotEndPos = autoaimDefaultPosition;

			StartSound("snd_lockoff", SND_CHANNEL_ANY, 0, false, NULL);

		}

		autoaimPos = vec3_zero;

		lastAutoaimEntNum = -1;
	}
	else
	{
		if (autoaimDotState == AUTOAIMDOTSTATE_IDLE || autoaimDotState == AUTOAIMDOTSTATE_MOVING_TO_IDLE || lastAutoaimEntNum != entity->entityNumber)
		{
			lastAutoaimDotState = autoaimDotState;

			//Move aimdots to locked state.
			//idVec2 dotScreenPos = GetWorldToScreen(targetPos);
			autoaimDotState = AUTOAIMDOTSTATE_MOVING_TO_LOCK;
			autoaimDotTimer = gameLocal.time;

			autoaimDotStartPos = autoaimDotPosition;

			StartSound("snd_lockon", SND_CHANNEL_ANY, 0, false, NULL);
		}

		autoaimPos = targetPos;

		lastAutoaimEntNum = entity->entityNumber;		
	}	

	return entity;

	//debug
	/*
	idVec3 circleAng;
	circleAng = targetPos - GetEyePosition();	
	circleAng.Normalize();
	gameRenderWorld->DebugCircle(colorRed, targetPos, circleAng, 8, 9, 50);*/
}




//From DOOM BFG
idEntity* idPlayer::FindAimAssistTarget(idVec3& targetPos)
{
	const idVec3 DEBUGARROWOFFSET = idVec3(0, 0, -1);
	const int MASK_AIMASSIST = CONTENTS_RENDERMODEL | CONTENTS_SOLID | CONTENTS_MONSTERCLIP | CONTENTS_BODY;
	const int MASK_AIMASSIST_IGNORE = CONTENTS_TRANSLUCENT;
	idVec3 cameraPos = firstPersonViewOrigin;
	idMat3 cameraAxis = firstPersonViewAxis;

	float currentBestScore = 0;
	float maxDistanceSquared = Square(AUTOAIM_MAXDISTANCE);
	idEntity* optimalTarget = NULL;

	idBounds traceBounds(idVec3(-1.0f, -1.0f, -1.0f), idVec3(1.0f, 1.0f, 1.0f));

	//Iterate through all aimAssistNode entities.
	for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	{
		idVec3 primaryTargetPos, secondaryTargetPos, dirToTarget, forward;
		float  distanceToTargetSquared, computedScore, ViewDirDotTargetDir;

		if (!entity->IsActive() || entity->IsHidden() || entity == this)
		{
			continue;
		}

		//Do not target friendlies.
		//if (entity->IsType(idActor::Type))
		//{
		//	idActor* actor = static_cast<idActor*>(entity);
		//	if (actor->team == this->team || actor->team == TEAM_NEUTRAL)
		//	{
		//		continue;
		//	}
		//}

		if (entity->team != TEAM_ENEMY)
			continue;

		if (entity->IsType(idGunnerMonster::Type))
		{
			if (entity->health <= 0)
				continue;
		}

		if (!ComputeTargetPos(entity, primaryTargetPos, secondaryTargetPos))
		{
			continue;
		}

#if 0 // eric's wacky tracepoint test
		{
			auto timeoff = gameLocal.time*0.001f;
			auto otherPos = primaryTargetPos + idVec3(sin(timeoff),cos(timeoff),0.0f)*30.0f;
			trace_t tr;
			gameLocal.clip.TracePoint(tr, otherPos, primaryTargetPos, MASK_AIMASSIST, this, MASK_AIMASSIST_IGNORE);

			bool invalidTrace = ((tr.fraction < 1.0f) && (tr.c.entityNum != entity->entityNumber));

			if (g_showAimAssistTrace.GetBool())
			{
				gameRenderWorld->DebugArrow(invalidTrace ? colorRed : colorGreen, otherPos + DEBUGARROWOFFSET, (primaryTargetPos - otherPos)* tr.fraction + otherPos, 4, 100);
				if ((tr.c.entityNum == entity->entityNumber))
				{
					gameRenderWorld->DebugArrow(colorMdGrey, tr.endpos, tr.endpos + tr.c.normal*10.0f, 4, 100);
				}
			}
		}
#endif

		//Do a distance check.
		dirToTarget = primaryTargetPos - cameraPos;
		distanceToTargetSquared = dirToTarget.LengthSqr();
		if (distanceToTargetSquared > maxDistanceSquared)
		{
			continue;
		}
		
		
		//Verify the target is in our fov.
		forward = cameraAxis[0];
		forward.Normalize();
		dirToTarget.Normalize();
		ViewDirDotTargetDir = idMath::ClampFloat(-1.0f, 1.0f, forward * dirToTarget);

		if (ViewDirDotTargetDir < 0.0f)
		{
			continue;
		}

		//Do the autoaim score calculation.
		computedScore = GetAutoaimScore(primaryTargetPos, cameraPos, cameraAxis);

		//Score threshold.
		if (computedScore < AUTOAIM_SCORE_THRESHOLD)
			continue;

		if (computedScore > currentBestScore)
		{
			trace_t tr;
			gameLocal.clip.TraceBounds(tr, cameraPos, primaryTargetPos, traceBounds, MASK_AIMASSIST, this, MASK_AIMASSIST_IGNORE);

			bool invalidTrace = ((tr.fraction < 1.0f) && (tr.c.entityNum != entity->entityNumber));

			if (g_showAimAssistTrace.GetBool())
			{
				gameRenderWorld->DebugArrow(invalidTrace ? colorRed :colorGreen, cameraPos + DEBUGARROWOFFSET, (primaryTargetPos - cameraPos)* tr.fraction + cameraPos, 4, 100);
				if ((tr.c.entityNum == entity->entityNumber))
				{
					gameRenderWorld->DebugArrow(colorMdGrey, tr.endpos, tr.endpos+tr.c.normal*10.0f, 4, 100);
				}
			}

			if (invalidTrace)
			{
				//Trace failed.
				//Try the seconary position.
				trace_t tr2;
				gameLocal.clip.TraceBounds(tr2, cameraPos, secondaryTargetPos, traceBounds, MASK_AIMASSIST, this, MASK_AIMASSIST_IGNORE);
				
				if (g_showAimAssistTrace.GetBool())
				{
					gameRenderWorld->DebugArrow(invalidTrace ? colorRed : colorGreen, cameraPos + DEBUGARROWOFFSET, (secondaryTargetPos - cameraPos)* tr.fraction + cameraPos, 4, 100);
					if ((tr.c.entityNum == entity->entityNumber))
					{
						gameRenderWorld->DebugArrow(colorMdGrey, tr.endpos, tr.endpos + tr.c.normal*10.0f, 4, 100);
					}
				}

				invalidTrace = ((tr2.fraction < 1.0f) && (tr2.c.entityNum != entity->entityNumber));

				if (invalidTrace)
				{
					//Secondary trace ALSO failed. Skip.........
					continue;
				}

				//Got a valid target!
				targetPos = secondaryTargetPos;
			}
			else
			{
				//Got a valid target!
				targetPos = primaryTargetPos;
			}

			optimalTarget = entity;
			currentBestScore = computedScore;
		}
	}

	autoaimEnt = optimalTarget;
	return optimalTarget;
}

//From DOOM BFG
//Get the aimpoints: on the enemy's HEAD (primary) or TORSO (secondary).
bool idPlayer::ComputeTargetPos(idEntity* entity, idVec3& primaryTargetPos, idVec3& secondaryTargetPos)
{
	idVec3 headPos;
	idMat3 headAxis;
	jointHandle_t headJoint;


	primaryTargetPos = vec3_zero;
	secondaryTargetPos = vec3_zero;

	if (entity == NULL)
	{
		return false;
	}
	
	idActor* actor = NULL;
	if (!entity->IsType(idActor::Type))
	{
		primaryTargetPos = entity->GetPhysics()->GetOrigin();
		secondaryTargetPos = entity->GetPhysics()->GetOrigin();
		return true;
	}

	actor = (idActor*)entity;

	headJoint = actor->GetAnimator()->GetJointHandle(actor->spawnArgs.GetString("lockon_joint", "camera"));

	if (headJoint == INVALID_JOINT)
	{
		gameLocal.Error("Actor '%s' has invalid lockon_joint.", actor->GetName());
		return false;
	}

	actor->GetAnimator()->GetJointTransform(headJoint, gameLocal.time, headPos, headAxis);
	primaryTargetPos = actor->GetRenderEntity()->origin + headPos * actor->GetRenderEntity()->axis;
	//gameRenderWorld->DebugSphere(colorRed, idSphere(primaryTargetPos, 2), 50);

	if (actor->GetHeadEntity() != NULL)
	{
		secondaryTargetPos = actor->GetHeadEntity()->GetPhysics()->GetOrigin();
	}
	else
	{
		secondaryTargetPos = actor->GetPhysics()->GetAbsBounds().GetCenter(); //IF targeting fails, then aim for center of mass.
	}

	return true;	
}

//From DOOM BFG. Returns value 0-1000 on how much to prioritize a given target.
float idPlayer::GetAutoaimScore(const idVec3& targetPos, const idVec3& cameraPos, const idMat3& cameraAxis)
{
	float ViewDirDotTargetDir;
	float score = 0.0f;
	idVec3 dirToTarget = targetPos - cameraPos;
	float distanceToTarget = dirToTarget.Length();
	idVec3 forward = cameraAxis[0];

	forward.Normalize();
	dirToTarget.Normalize();
	ViewDirDotTargetDir = idMath::ClampFloat(0.0f, 1.0f, forward * dirToTarget);
	score = ViewDirDotTargetDir;

	// weigh the score from the view angle higher than the distance score
	static float aimWeight = 0.9f;
	score *= aimWeight;

	// Add a score of 0...1 for how close the target is to the player
	if (distanceToTarget < AUTOAIM_MAXDISTANCE)
	{
		float distanceScore = 1.0f - (distanceToTarget / AUTOAIM_MAXDISTANCE);
		float distanceWeight = 1.0f - aimWeight;
		score += (distanceScore * distanceWeight);
	}

	//gameRenderWorld->DrawTextA(va("%f", score), targetPos + idVec3(0, 15, 0), .3f, colorRed, gameLocal.GetLocalPlayer()->viewAngles.ToMat3(), 1);

	return score * 1000.0f;
}


void idPlayer::StartBashAttack()
{
	if (iteminspectActive || armstatsActive || GuiActive() || weapon.GetEntity()->IsInspectingChamber() || zoommodeActive) //don't allow bash attack if item is being inspected.
		return;

	if (gameLocal.time < nextAttackTime)
		return; //Cooldown hasn't expired yet.

	nextAttackTime = gameLocal.time + CARRYABLE_MELEE_TIME;

	if (carryableItem.IsValid())
	{
		//Carryable bash attack.

		if (carryableItem.GetEntity()->health <= 0)
		{
			//if durability is zero, don't allow bash attack. This is largely for things that use 'canbreak 0' (i.e. skullsaver)
			SetCenterMessage("#str_def_gameplay_cannotattack");
			hud->HandleNamedEvent("durabilityFlash");
			return;
		}
	}
	else
	{
		//Weapon bash attack.

		if (!weapon.IsValid())
			return;

		if (!weapon.GetEntity()->IsReadyToBash())
			return; //exit here if weapon is currently NOT in idle state.
	}

	carryableBashActive = true;
	carryableBashTimer = gameLocal.time + CARRYABLE_MELEE_ANIMATIONTIME;


	//check if unarmed.
	int currentWeapon = inventory.hotbarSlots[currentWeaponSlot].weaponType;
	if (currentWeapon <= 0)
	{
		StartSound("snd_error", SND_CHANNEL_ANY);
		return;
	}


	//BASH ATTACK.
	DoPhysicalMelee();
	StartSound("snd_bash", SND_CHANNEL_ANY, 0, false, NULL);
}



idEntity *idPlayer::FindBashTarget(trace_t& tr)
{
	//If player is moving forward, give a bonus length to melee strike range.	
	float bashDistance = CARRYABLE_MELEE_DISTANCE;
	if (usercmd.forwardmove > 0 && GetPhysics()->GetLinearVelocity().LengthFast() > 32)
		bashDistance = CARRYABLE_MELEE_DISTANCE_MOVING;

	//If I'm directly looking at something...
	idEntity *ent = NULL;
	gameLocal.clip.TracePoint(tr, GetEyePosition(), GetEyePosition() + (viewAngles.ToForward() * bashDistance), MASK_SHOT_RENDERMODEL, this);
	if (tr.fraction < 1.0f)
	{
		ent = gameLocal.GetTraceEntity(tr);
		if (ent->fl.takedamage)
			return ent;

		if (!ent->fl.takedamage && ent->entityNumber == ENTITYNUM_WORLD)
			return ent;

		if (ent->isFrobbable)
			return ent;
	}

	//Failed.
	//Do a wider search.
	int nodeList;
	idEntity *entityList[MAX_GENTITIES];
	nodeList = gameLocal.EntitiesWithinRadius(firstPersonViewOrigin, bashDistance, entityList, MAX_GENTITIES);

	int bestIndex = -1;
	float bestScore = 0;
	for (int i = 0; i < nodeList; i++)
	{
		idEntity *ent = entityList[i];
		if (!ent)
			continue;

		if (ent->IsHidden())
			continue;

		if (!ent->fl.takedamage)		
		{
			continue;
		}

		if (carryableItem.IsValid())
		{
			if (carryableItem.GetEntityNum() == ent->entityNumber)
			{
				continue;
			}
		}

		if (ent->GetBindMaster() != NULL)
		{
			if (ent->GetBindMaster() == this)
			{
				continue;
			}
		}

		if (ent == this)
		{
			continue;
		}

		idVec3 entPos = ent->GetPhysics()->GetOrigin();		
		float distance = (entPos - firstPersonViewOrigin).Length();
		if (distance > bashDistance)
			continue;

		//dotproduct check. make sure item is mostly in center of screen.
		//how centered does ent need to be to pass dotproduct check. 1.0  = dead center, 0.0 = wide 180 degree cone in front of player.We want to keep this relatively
		//tight or else the player will accidentally bash items that are sometimes offscreen.
		#define BASH_DOTPRODUCT_THRESHOLD .8f 

		idVec3 dirToEnt = entPos - this->firstPersonViewOrigin;
		dirToEnt.Normalize();
		float facingResult = DotProduct(dirToEnt, viewAngles.ToForward());
		if (facingResult < BASH_DOTPRODUCT_THRESHOLD)
			continue;

		//Piggyback onto the autoaim system to find the best target.
		float computedScore = GetAutoaimScore(entPos, firstPersonViewOrigin, firstPersonViewAxis);
		if (computedScore > bestScore)
		{
			//Ensure we have LOS to the entity.
			gameLocal.clip.TracePoint(tr, firstPersonViewOrigin, entPos, MASK_SOLID, this);
			if (tr.c.entityNum == ent->entityNumber || tr.fraction >= 1)
			{
				//success
			}
			else
			{
				//invalid.
				continue;
			}

			bestScore = computedScore;
			bestIndex = i;
		}		
	}

	if (bestIndex < 0)
		return NULL;

	return entityList[bestIndex];
}

//Code is from Event_Melee
bool idPlayer::DoPhysicalMelee()
{
	if (armstatsActive)
		return false;
	
	trace_t tr;
	idEntity	*ent = FindBashTarget(tr);
	
	if (ent == NULL) //No target found.
	{
		//Try again. This time, piggyback on the autotarget system and see if it can find an actor target.
		idEntity *possibleTarget = UpdateAutoAim();

		if (possibleTarget != NULL)
		{
			float distanceToTarget = (GetEyePosition() - possibleTarget->GetPhysics()->GetAbsBounds().GetCenter()).LengthFast();
			if (distanceToTarget <= CARRYABLE_MELEE_DISTANCE) //Check if target is close enough.
			{
				ent = possibleTarget;
			}
		}
	}

	if (ent)
	{
		if (ent->fl.takedamage)
		{
			//const idDeclEntityDef *	meleeDef;
			//meleeDef = gameLocal.FindEntityDef(weaponDef->dict.GetString("def_melee")
			//TODO: get melee def from held weapon?

			idEntity *attackerEnt = NULL; //the actual object that is inflicting damage. i.e. teapot, knife, etc.

			idStr damagedefToApply = "";
			if (carryableItem.IsValid())
			{
				damagedefToApply = carryableItem.GetEntity()->spawnArgs.GetString("def_damage", "damage_throwable");
			}
			else if (weapon.IsValid())
			{
				damagedefToApply = weapon.GetEntity()->spawnArgs.GetString("def_damage", "damage_throwable");
			}

			if (damagedefToApply.Length() <= 0)
				damagedefToApply = "damage_throwable";

			if (ent->health > 0)
			{
				//successful hit. Update the weapon durability.

				bool doItemBreak = false;
				if (carryableItem.IsValid())
				{
					float damageScale = 1.0f;
					
					if (ent->IsType(idActor::Type))
					{
						//we want items to destroy themselves in one hit when hitting an actor. So we scale the self-damage up a ton.
						damageScale = 1000.0f;
					}

					carryableItem.GetEntity()->Damage(NULL, NULL, vec3_zero, "damage_durabilitybash", damageScale, 0); //apply damage to the carryable.

					hud->HandleNamedEvent("durabilityFlash");

					if (carryableItem.IsValid())
					{
						attackerEnt = carryableItem.GetEntity();
						if (carryableItem.GetEntity()->health <= 0 && carryableItem.GetEntity()->spawnArgs.GetBool("canbreak", "1"))
						{
							//player BROKE the carryable.
							//Snap the carryable to the melee hit position, to make it a little clearer that the carryable item is getting destroyed.

							idStr destroyMessage = idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_itemdestroyed"), carryableItem.GetEntity()->displayName.c_str());
							gameLocal.AddEventLog(destroyMessage.c_str(), GetPhysics()->GetOrigin());
							SetCenterMessage(destroyMessage.c_str());

							carryableItem.GetEntity()->GetPhysics()->SetContents(0);
							carryableItem.GetEntity()->SetOrigin(tr.endpos);
							doItemBreak = true;
						}
					}
				}
				else
				{
					int equippedSlot = inventory.GetHotbarSelection();
					if (weapon.IsValid() && inventory.hotbarSlots[equippedSlot].weaponType > 0) //Ignore unarmed weapon.
					{
						//common->Printf("weapon health %d\n", inventory.weaponHealth[currentWeapon]);

						inventory.hotbarSlots[equippedSlot].health--; //update weapon durability.
						hud->HandleNamedEvent("durabilityFlash");

						attackerEnt = weapon.GetEntity();

						if (inventory.hotbarSlots[equippedSlot].health <= 0)
						{
							//Weapon durability is ZERO. Shatter the weapon.
							const char *bashSelfdamage = weapon.GetEntity()->spawnArgs.GetString("def_bash_selfdamage");
							if (bashSelfdamage[0] != '\0')
							{
								//do a local damage when this thing gets durability-destroyed.
								gameLocal.RadiusDamage(tr.endpos, NULL, NULL, NULL, NULL, bashSelfdamage);
							}

							const char *bashSelfFX = weapon.GetEntity()->spawnArgs.GetString("fx_bash_selfdamage");
							if (bashSelfFX[0] != '\0')
							{
								//do fx when this thing gets durability-destroyed.
								idEntityFx::StartFx(bashSelfFX, &tr.endpos, &mat3_default, NULL, false);
							}
							
							//Make weapon disappear.


							idStr destroyMessage = idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_itemdestroyed"), common->GetLanguageDict()->GetString(weapon.GetEntity()->displayName.c_str()));
							gameLocal.AddEventLog(destroyMessage, GetPhysics()->GetOrigin());
							SetCenterMessage(destroyMessage.c_str());

							inventory.Drop( equippedSlot );
							SetHotbarSlot(equippedSlot, 0, "", 0, NULL); //set unarmed.
							weapon.GetEntity()->ResetAmmoClip();
							Event_SelectWeapon("weapon_unarmed"); //BC go to unarmed.
							weapon.GetEntity()->WeaponStolen();
							weaponGone = true;
							
							doItemBreak = true;
						}
					}
				}

				if (doItemBreak)
				{
					//Item destruction FX.
					idAngles fxAng;
					fxAng = tr.c.normal.ToAngles();
					fxAng.pitch += 90;
					idEntityFx::StartFx("fx/explosion_item_carried", tr.endpos, fxAng.ToMat3());

					//spawn some generic gib pieces.						
					gameLocal.SetDebrisBurst("moveable_metalgib4", tr.endpos, 8, 2, 128.0f, vec3_zero);

					SetImpactSlowmo(true);

					this->RemoveCarryableFromHotbar(inventory.GetHotbarSelection());

					playerView.DoDurabilityFlash();
				}
			}

			ent->Damage(this, attackerEnt, viewAngles.ToForward(), damagedefToApply.c_str(), 1.0f, CLIPMODEL_ID_TO_JOINT_HANDLE(tr.c.id));
			ent->lastDamageTime = gameLocal.time;

			if (ent->IsType(idMoveableItem::Type))
			{
				//Jostle it a little.
				idAngles jostleDir = (ent->GetPhysics()->GetOrigin() - tr.endpos).ToAngles();			
				jostleDir.pitch = 0;
				jostleDir.roll = 0;				

				idVec3 impulseForce = ((jostleDir.ToForward() * 32.0f) + idVec3(0,0,48)) * ent->GetPhysics()->GetMass();				
				ent->GetPhysics()->ApplyImpulse(0, tr.endpos, impulseForce);
			}

			if (ent->spawnArgs.GetBool("bleed"))
			{
				ent->AddDamageEffect(tr, tr.c.normal, damagedefToApply.c_str()); //TODO: This is not working right on FractureGlass breakables -- the fracture doesn't happen at the melee attack position.
			}


			if (ent->isFrobbable && ent->health > 0 && carryableItem.IsValid())
			{
				//if you bash something, it gets frobbed.
				ent->DoFrob(0, carryableItem.GetEntity());
			}

			
		}
		else
		{
			if (tr.c.material->GetSurfaceFlags() >= 256)
			{
				//hit sky. Do nothing.
			}
			else
			{
				if (ent->isFrobbable)
				{
					//if you bash something, it gets frobbed.
					ent->DoFrob(0, this);
				}
			}
		}


		//Spawn a decal at the hit position.
		gameLocal.ProjectDecal(tr.c.point, -tr.c.normal, 8.0f, true, 7 + gameLocal.random.RandomInt(4), "textures/decals/melee_scorch");

		//Do a particle effect.
		idAngles particleAng;
		particleAng = tr.c.normal.ToAngles();
		particleAng.pitch -= 90;
		gameLocal.DoParticle("melee_smoke.prt", tr.c.point, particleAng.ToForward());




		//Impact sound.
		const char *impactSound;
		int surfaceType = tr.c.material != NULL ? tr.c.material->GetSurfaceType() : SURFTYPE_METAL;
		switch (surfaceType)
		{
		case SURFTYPE_METAL:
			impactSound = "impact_metal4";
			break;
		case SURFTYPE_WOOD:
			impactSound = "impact_wood";
			break;
		case SURFTYPE_FABRIC:
			impactSound = "impact_fabric04";
			break;
		case SURFTYPE_FLESH:
			impactSound = "impact_flesh";
			break;
		case SURFTYPE_TILE:
			impactSound = "impact_tile";
			break;
		default:
			impactSound = "melee";
			break;
		}
		StartSoundShader(declManager->FindSound(impactSound), SND_CHANNEL_ANY, 0, false, NULL);



		// SW: When we punch a pane of glass, the impulse needs to come *after* the damage,
		// as the impulse is what actually shatters the glass once it hits zero health.
		idVec3 impulse = -16 * tr.c.normal;
		ent->ApplyImpulse(this, tr.c.id, tr.c.point, impulse);
	}
	else
	{
		//hit the world.
	}



	if (carryableItem.IsValid())
	{
		//Call the carryable's bash function, if it exists
		if (carryableItem.GetEntity()->IsType(idMoveableItem::Type))
		{
			static_cast<idMoveableItem *>(carryableItem.GetEntity())->JustBashed(tr);
		}
	}



	if (tr.fraction < 1.0f)
	{
		//create interestpoint of melee hitting something.

		gameLocal.SpawnInterestPoint(this, tr.endpos, "interest_meleeworld");

		if (carryableItem.IsValid())
		{
			if (carryableItem.GetEntity()->health > 0 && carryableItem.GetEntity()->spawnArgs.GetBool("bashspark"))
			{
				//this is an electric item, and it bashed something (or bashed the worldspawn), so now we want the item to shoot out sparks for a while.
				if (carryableItem.GetEntity()->IsType(idMoveableItem::Type))
				{
					static_cast<idMoveableItem *>(carryableItem.GetEntity())->SetSparking();
				}
			}
		}
	}


	return (ent != NULL);
}

bool idPlayer::DoThrowItemAttack(int physicalAttackType)
{
	int				nodeList, i;
	idEntity		*entityList[MAX_GENTITIES];
	idVec3			traceStart;

	this->UpdateAutoAim();

	if (autoaimPos == vec3_zero)
		return false;

	if (physicalAttackType == PHYSICALATTACKTYPE_HANDS)
	{
		//hands
		traceStart = GetEyePosition();
	}
	else
	{
		//feet.
		traceStart = GetPhysics()->GetOrigin() + idVec3(0, 0, 4);
	}

	//Find a throwable/kickable object near the player.
	nodeList = gameLocal.EntitiesWithinRadius(traceStart, 64, entityList, MAX_GENTITIES);

	for (i = 0; i < nodeList; i++)
	{
		idEntity		*ent = entityList[i];
		trace_t			tr;
		idVec3			throwDir;

		if (!ent)
		{
			continue;
		}

		if (!ent->IsType(idMoveableItem::Type))
		{
			continue;
		}


		//Verify LOS between player and throwable object.
		gameLocal.clip.TracePoint(tr, traceStart, ent->GetPhysics()->GetOrigin() + idVec3(0,0,1), MASK_OPAQUE, this);

		//If blocked, then abort.
		if (tr.fraction < 1)
		{
			continue;
		}

		//Chuck it at an enemy's face.
		/*
		idVec3 throwVelocity;
		idVec3 throwDir = autoaimPos - ent->GetPhysics()->GetOrigin();

		throwDir.Normalize();
		throwVelocity = throwDir * 1536.0f;
		ent->GetPhysics()->SetLinearVelocity(throwVelocity);
		*/

		//throwDir = autoaimPos - ent->GetPhysics()->GetOrigin();
		//throwDir.Normalize();

		bool throwResult = idAI::PredictTrajectory(ent->GetPhysics()->GetOrigin() + idVec3(0,0,.1f),
			autoaimPos, 1024, ent->GetPhysics()->GetGravity(), ent->GetPhysics()->GetClipModel(), ent->GetPhysics()->GetClipMask(),
			MAX_WORLD_SIZE, this, gameLocal.entities[lastAutoaimEntNum], 0, throwDir);

		if (!throwResult)
			continue;

		ent->GetPhysics()->SetLinearVelocity(throwDir * 1024);		

		autoaimPos = vec3_zero;
		return true;

	}

	autoaimPos = vec3_zero;
	return false;
}


void idPlayer::RackTheSlide(void)
{
	if (gameLocal.isClient)
	{
		return;
	}

	if (spectating || gameLocal.inCinematic || influenceActive)
	{
		return;
	}

	if (weapon.GetEntity() && weapon.GetEntity()->IsLinked())
	{
		//Rack the slide.
		weapon.GetEntity()->RackTheSlide();
	}
}

void idPlayer::InspectMagazine(bool active)
{
	if (gameLocal.isClient)
	{
		return;
	}

	if (spectating || gameLocal.inCinematic || influenceActive)
	{
		return;
	}

	if (weapon.GetEntity() && weapon.GetEntity()->IsLinked())
	{
		if (!weapon.GetEntity()->IsInspectingMagazine())
		{
			vo_reloadchecktimer = gameLocal.time + MAGINSPECT_VO_DELAYTIME; //say VO after this time passes.
			hasSaidReloadcheckVO = false;
		}

		weapon.GetEntity()->InspectMagazine(active);
	}
}

void idPlayer::InspectChamber(bool active)
{
	if (gameLocal.isClient)
	{
		return;
	}

	if (weapon.GetEntity() && weapon.GetEntity()->IsLinked())
	{
		if (!weapon.GetEntity()->IsInspectingChamber())
		{
			vo_chamberchecktimer = gameLocal.time + CHAMBERINSPECT_VO_DELAYTIME; //say VO after this time passes.
			hasSaidChambercheckVO = false;
		}

		weapon.GetEntity()->InspectChamber(active);
	}
}

void idPlayer::InspectWeapon(bool active)
{
	if (gameLocal.isClient)
	{
		return;
	}

	if (weapon.GetEntity() && weapon.GetEntity()->IsLinked())
	{
		//Do the weapon inspection.
		weapon.GetEntity()->InspectWeapon(active);

		if (active)
		{
			//Tell the game to pause.
			inspectLerpState = INSP_LERPON;
			inspectLerpTimer = gameLocal.time + INSPECTION_LERPTIME_WEAPON; //NOTE: This lerp time is DIFFERENT from the carryable lerp time (INSPECTION_LERPTIME), in order to give enough time for the weapon animation to complete.
		}
	}

	idEntity* carryableEnt = carryableItem.GetEntity();
	if (carryableEnt)
	{
		carryableEnt->SetPostFlag(POST_INSPECT_LUMINANCE, active);
	}
}

int idPlayer::GetLastGlasswoundTime()
{
	return lastGlasswoundTime;
}

void idPlayer::SetSpearwound()
{
	cond_spearwound++;
	AddToWoundArray(WOUNDIDX_SPEAR);
}

void idPlayer::Event_AddGlassWound(void)
{
	SetGlasswound(1);
}

void idPlayer::SetGlasswound(int delta)
{
	lastGlasswoundTime = gameLocal.time;

	// place a wound overlay on the model.
	if (footBloodDecalCount < 2)
	{
		const char  *decal;	
		decal = spawnArgs.RandomPrefix("mtr_wound_flesh", gameLocal.random);
		if (*decal != '\0')
		{
			int i;

			for (i = 0; i < 2; i++)
			{
				//apply the decal.
				const char			*jointname;
				jointHandle_t		leftFootJoint;
				idVec3				jointpos;
				idMat3				axis;
				idVec3				forward;
				idVec3				rayStart, rayEnd, rayDir;

				viewAngles.ToVectors(&forward, NULL, NULL);
				jointname = spawnArgs.GetString(i <= 0 ? "bone_lankle" : "bone_rankle");
				leftFootJoint = animator.GetJointHandle(jointname);
				animator.GetJointTransform(leftFootJoint, gameLocal.time, jointpos, axis);

				rayStart = GetPhysics()->GetOrigin() + idVec3(0, 0, 16) + (forward * 16);
				rayEnd = GetPhysics()->GetOrigin() + jointpos;
				rayDir = rayEnd - rayStart;
				rayDir.Normalize();

				ProjectOverlay(rayStart, rayDir, 24, decal);
			}

			footBloodDecalCount++;
		}
	}

	if (cond_glasswound + delta <= CONDITION_GLASSWOUND_MAXWOUNDS)
	{
		cond_glasswound += delta;

		AddToWoundArray(WOUNDIDX_GLASS);
	}
}

void idPlayer::UpdateContextConditions(void)
{
	bool guiAutoaim = false;

	contextMenu->SetStateBool("cond_burning", burningTimer > gameLocal.time);
	contextMenu->SetStateInt("cond_glasswoundcount", cond_glasswound);
	contextMenu->SetStateInt("cond_burnwoundcount", cond_burnwound);
	contextMenu->SetStateInt("cond_woundcount", GetWoundCount());
	contextMenu->SetStateInt("cond_bulletwoundcount", cond_bulletwound);
	contextMenu->SetStateInt("cond_shrapnelcount", cond_shrapnel);
	contextMenu->SetStateInt("cond_spearcount", cond_spearwound);
	contextMenu->SetStateInt("cond_smelly", cond_smelly);
	contextMenu->SetStateInt("bloodbagCount", inventory.bloodbags);
	contextMenu->SetStateInt("cond_hushed", gameLocal.IsBaffled(GetEyePosition()));

	if (!inDownedState)
	{
		contextMenu->SetStateInt("showhealthbar", 1);
	}
	else
	{
		contextMenu->SetStateInt("showhealthbar", 0);
	}

	//If I am not wounded, then spit.
	if (GetWoundCount() <= 0)
		contextMenu->SetStateString("context_spit", "spit");
	else
		contextMenu->SetStateString("context_spit", "cough blood"); //If I am wounded, then cough blood.

	//Whether to draw the autoaim button.
	if (weapon.GetEntity() != NULL)
	{
		if (weapon.GetEntity()->spawnArgs.GetBool("autoaimenabled", "false"))
		{
			//gui::autoaimenabled 0 = deactivated, 1 = activated
			contextMenu->SetStateInt("autoaimenabled", weapon.GetEntity()->autoaimEnabled ? 1 : 0);
			guiAutoaim = true;
		}
	}

	if (!guiAutoaim)
	{
		contextMenu->SetStateInt("autoaimenabled", -1);
	}


	//Update ammo counts for the weapon selector.
	// First set everything as not available
	for ( int i = 0; i < MAX_WEAPONS; i++ ) {
		contextMenu->SetStateBool( va( "weap_avail%d", i ), false );
	}

	// Figure out what we're using
	for ( int i = 0; i < MAX_HOTBARSLOTS; i++ )
	{
		int weaponType = inventory.hotbarSlots[i].weaponType;
		if ( weaponType  > -1)
		{
			const char *weapnum = va("def_weapon%d", weaponType);
			const char *weap = spawnArgs.GetString(weapnum);
			if (weap && *weap)
			{
				ammo_t ammo_i = inventory.AmmoIndexForWeaponClass(weap, NULL);
				if (ammo_i)
				{
					contextMenu->SetStateInt(va("ammo_inv%d", weaponType ), inventory.ammo[ammo_i]);
				}

				//Set value for whether weapon should appear in the weapon selector.
				contextMenu->SetStateBool(va("weap_avail%d", weaponType), true);
			}
		}
	}

	//int ammoamount = weapon.GetEntity()->AmmoAvailable();
}

//This gets called when the player starts healing a major wound, likely via the context menu.
void idPlayer::StartHealState(int healstateIndex)
{
	switch (healstateIndex)
	{
		case HEALSTATE_SPEARPLUCK:
			AI_HEAL_SPEARPLUCK = true;
			healState = HEALSTATE_SPEARPLUCK;

			cond_spearwound--;
			if (cond_spearwound < 0)
				cond_spearwound = 0;

			if (cond_spearwound <= 0)
			{				
				WoundRegenerateHealthblock();				
			}

			//Remove the spear attachment, and give spear weapon to player. Iterates through all world entities.... this isn't the most efficient way of doing this
			for (int i = 0; i < gameLocal.num_entities; i++)
			{
				if (gameLocal.entities[i] && gameLocal.entities[i]->IsType(idSpearprojectile::Type) && gameLocal.entities[i]->GetBindMaster() == this)
				{
					idDict splashArgs;
					idFuncEmitter *splashEnt;
					idVec3 bloodPos;
					idAngles particleDir;

					static_cast<idSpearprojectile *>(gameLocal.entities[i])->DoFrob(DEIMPALE_FROBINDEX);

					//Blood fx.
					bloodPos = GetEyePosition() + idVec3(0, 0, -24);
					particleDir.yaw = viewAngles.yaw ;
					particleDir.pitch = 60;
					splashArgs.Set("model", "spearbot_blood.prt");
					splashArgs.Set("start_off", "1");
					splashEnt = static_cast<idFuncEmitter *>(gameLocal.SpawnEntityType(idFuncEmitter::Type, &splashArgs));
					splashEnt->GetPhysics()->SetOrigin(bloodPos);
					splashEnt->GetPhysics()->SetAxis(particleDir.ToMat3());
					splashEnt->PostEventMS(&EV_Activate, 0, this);
					splashEnt->PostEventMS(&EV_Remove, 3000);
					splashEnt->Bind(this, true);

					i = gameLocal.num_entities + 1; //break out of loop.
				}
			}

			hud->HandleNamedEvent("onHealImpalement");

			break;
		case HEALSTATE_BULLETPLUCK:
			#define	BULLETPLUCK_ANIMATIONTIME_MS 1666
			healbarStartTime = gameLocal.time;
			healbarTotalTime = BULLETPLUCK_ANIMATIONTIME_MS * cond_bulletwound;
			AI_HEAL_BULLETPLUCK = true;
			SetArmVisibility(true);
			weapon.GetEntity()->HideWorldModel();
			SetViewPitchLerp(20);
			healState = HEALSTATE_BULLETPLUCK;
			hud->HandleNamedEvent("onHealBulletwound");
			break;

		case HEALSTATE_SHRAPNEL:

			#define	SHRAPNELPLUCK_ANIMATIONTIME_MS 2000
			healbarStartTime = gameLocal.time;
			healbarTotalTime = SHRAPNELPLUCK_ANIMATIONTIME_MS * cond_shrapnel;

			AI_HEAL_SHRAPNEL = true;
			SetArmVisibility(true);
			weapon.GetEntity()->HideWorldModel();
			SetViewPitchLerp(20);
			healState = HEALSTATE_SHRAPNEL;

			hud->HandleNamedEvent("onHealShrapnel");
			break;

		case HEALSTATE_BURNING:

			AI_HEAL_BURNING = true;
			SetArmVisibility(true);
			weapon.GetEntity()->HideWorldModel();
			SetViewPitchLerp(30);
			healState = HEALSTATE_BURNING;
			hud->HandleNamedEvent("onHealBurning");

			#define	FIREHEAL_ANIMATIONTIME_MS 1200
			healbarStartTime = gameLocal.time;
			healbarTotalTime = FIREHEAL_ANIMATIONTIME_MS;

			break;

		case HEALSTATE_GLASSPULL:

			//Cannot heal glass wound while crouched.... your arms aren't long enough to reach....
			if (this->physicsObj.IsCrouching())
			{
				hud->HandleNamedEvent("cantheal");
				return;
			}

			//Start glass wound heal.			
			AI_HEAL_GLASSWOUND = true;
			healState = HEALSTATE_GLASSPULL;
			SetArmVisibility(true);
			SetViewPitchLerp(80);
			SetViewYawLerp(viewAngles.yaw - 20);
			weapon.GetEntity()->HideWorldModel();
			SetViewYawLock(true, viewAngles.yaw, 90);	
			SetBodyAngleLock(true);

			//Heal progress bar.
			#define	GLASSPLUCK_INITIALIZETIMETIME_MS 833
			#define	GLASSPLUCK_ANIMATIONTIME_MS 1000
			healbarStartTime = gameLocal.time;
			healbarTotalTime = GLASSPLUCK_INITIALIZETIMETIME_MS + (GLASSPLUCK_ANIMATIONTIME_MS * cond_glasswound);

			hud->HandleNamedEvent("onHealGlasswound");

			break;

		case HEALSTATE_BLEEDOUT:
			
			//START BLOODBAG SEQUENCE.
			AI_HEAL_BLEEDOUT = true;
			healState = HEALSTATE_BLEEDOUT;
			SetViewPitchLerp(10, 500);
			//SetArmVisibility(true);
			//weapon.GetEntity()->HideWorldModel();
			bloodbagState = BLOODBAGSTATE_ACTIVATING;
			bloodbagMesh->Event_PlayAnim("raise", 1);
			bloodbagTimer = gameLocal.time;
			bloodbagHealth = HEALTH_BLOODBAG_DEFAULTHEALTH;
			bloodbagMesh->SetShaderParm(5, -.05f); //fill bag full of blood.		
			bloodbagHealthFXState = 0;

			inventory.bloodbags = Max(inventory.bloodbags - 1, 0);
			

			break;
	}
}

void idPlayer::SetArmVisibility(bool visibility)
{
	if (visibility)
	{
		//show arms.
		skin = declManager->FindSkin("skins/player/skin_armsboth_feetbare.skin");
		hiddenWeapon = true;
	}
	else
	{
		//hide arms.
		skin = declManager->FindSkin("skins/player/skin_armsnone_feetbare.skin");
		hiddenWeapon = false;
	}

	if (skin)
	{
		SetSkin(skin);
	}
}

void idPlayer::Event_SetGlasswoundHeal()
{
	cond_glasswound--;

	if (cond_glasswound <= 0)
	{
		WoundRegenerateHealthblock();
	}
}

void idPlayer::Event_SetBurningHeal()
{
	SetOnFire(false);
}

void idPlayer::Event_GetGlasswounds()
{
	idThread::ReturnInt(cond_glasswound);
}

void idPlayer::Event_GetBulletwounds()
{
	idThread::ReturnInt(cond_bulletwound);
}

void idPlayer::Event_GetShrapnelwounds()
{
	idThread::ReturnInt(cond_shrapnel);
}

void idPlayer::SetViewYawLock(bool activate, float baseYaw, float arcSize)
{
	viewYawLocked = activate;
	viewYawLockAngle = baseYaw;
	viewYawLockArcsize = arcSize;
}

void idPlayer::SetViewPitchLock( bool activate, float basePitch, float arcSize )
{
	viewPitchLocked = activate;
	viewPitchLockAngle = basePitch;
	viewPitchLockArcsize = arcSize;
}

void idPlayer::SetBodyAngleLock(bool activate)
{
	bodyAngleLocked = activate;
}



void idPlayer::DoHealPluck(const char *defName)
{
	idVec3 handPos;
	idMat3 handAxis;
	jointHandle_t handJoint;

	handJoint = animator.GetJointHandle(spawnArgs.GetString("bone_bulletpluck"));
	GetJointWorldTransform(handJoint, gameLocal.time, handPos, handAxis);

	EjectBodyDebris(defName, handPos);
}

void idPlayer::EjectBodyDebris(const char *defName, idVec3 spawnPosition)
{
	idDict	brassDict;
	const idDeclEntityDef *brassDef;

	brassDef = gameLocal.FindEntityDef(spawnArgs.GetString(defName), false);
	if (!brassDef)
		return;
	
	idEntity *brassEnt;
	brassDict = brassDef->dict;
	gameLocal.SpawnEntityDef(brassDict, &brassEnt, false);

	if (!brassEnt)
		return;	

	brassEnt->SetOrigin(spawnPosition);

	idAngles ejectDir;	
	idAngles spurtDir;

	ejectDir = viewAngles.ToForward().ToAngles();
	ejectDir.pitch -= 80;
	ejectDir.roll = 0;

	spurtDir = viewAngles.ToForward().ToAngles();
	spurtDir.pitch += 80;
	spurtDir.roll = 0;

	if (brassEnt->IsType(idDebris::Type))
	{
		idDebris *debris = static_cast<idDebris *>(brassEnt);
		debris->Create(this, spawnPosition, mat3_identity);
		debris->Launch();
	}
	//else if (brassEnt->IsType(idMoveableItem::Type))
	//{
	//	static_cast<idMoveableItem *>(brassEnt)->SetJustDropped(true);
	//}

	//Spin brass.
	brassEnt->GetPhysics()->SetAngularVelocity(idVec3(400 * gameLocal.random.CRandomFloat(), 10 * gameLocal.random.CRandomFloat(), 10 * gameLocal.random.CRandomFloat()));

	//Spit out brass.
	ejectDir.yaw += gameLocal.random.CRandomFloat() * 10;
	brassEnt->GetPhysics()->SetLinearVelocity(ejectDir.ToForward() * (96 + gameLocal.random.RandomFloat() * 16));

	idEntityFx::StartFx(spawnArgs.GetString("fx_bulletpluck"), spawnPosition, spurtDir.ToMat3());
}



void idPlayer::DoGlassYankShard(void)
{
	jointHandle_t			leftFootJoint;	
	idVec3					origin;
	idMat3					axis;
	idDict					brassDict;
	idEntity				*ent;
	idDebris				*debris;
	idVec3					right;
	idVec3					footPosition;
	const idDeclEntityDef	*brassDef = gameLocal.FindEntityDef("debris_footshard", false);

	if (brassDef)
		brassDict = brassDef->dict;
	else
		return;

	leftFootJoint = animator.GetJointHandle(spawnArgs.GetString("bone_glassyank"));

	if (!animator.GetJointTransform(leftFootJoint, gameLocal.time, origin, axis))
		return;

	gameLocal.SpawnEntityDef(brassDict, &ent, false);
	if (!ent || !ent->IsType(idDebris::Type))
	{
		return;
	}
	
	footPosition = renderEntity.origin + origin * renderEntity.axis;

	debris = static_cast<idDebris *>(ent);
	debris->Create(this, footPosition, axis);
	debris->Launch();

	//gameRenderWorld->DebugArrow(idVec4(1, .7f, 0, 1), footPosition + idVec3(0,0,32), footPosition , 10000, true);	

	viewAngles.ToVectors(NULL, &right, NULL);
	debris->GetPhysics()->SetLinearVelocity(idVec3(0,0, 60 + (gameLocal.random.RandomFloat() * 45)) + (right * (20 + (gameLocal.random.RandomFloat() * 70)))
		+ idVec3(gameLocal.random.CRandomFloat() * 8, gameLocal.random.CRandomFloat() * 8, 0));
	debris->GetPhysics()->SetAngularVelocity(idVec3(60 * gameLocal.random.CRandomFloat(), 10 * gameLocal.random.CRandomFloat(), 10 * gameLocal.random.CRandomFloat()));
}

void idPlayer::DoSneeze(int sneezeType)
{
	idFuncEmitter *splashEnt;
	idDict splashArgs;
	idAngles sprayAngle;
	idDict args;
	idVec3 up;
	idVec3 forward;

	trace_t sneezeTr;

	viewAngles.ToVectors(&forward, NULL, &up);
	splashArgs.Set("model", sneezeType <= 0 ?  spawnArgs.GetString("model_sneezeparticle") : spawnArgs.GetString("model_coughbloodparticle") );
	splashArgs.Set("start_off", "1");
	splashEnt = static_cast<idFuncEmitter *>(gameLocal.SpawnEntityType(idFuncEmitter::Type, &splashArgs));
	sprayAngle = viewAngles;
	sprayAngle.pitch += 90;
	splashEnt->GetPhysics()->SetOrigin(GetEyePosition() + (up * -4) + (forward * 8));
	splashEnt->GetPhysics()->SetAxis(sprayAngle.ToMat3());
	splashEnt->PostEventMS(&EV_Activate, 0, this);
	splashEnt->PostEventMS(&EV_Remove, 1000);

	//sneeze decal.
	if (gameLocal.clip.TracePoint(sneezeTr, GetEyePosition() + (up * -4), GetEyePosition() + (up * -4) + (forward * 128), MASK_SOLID, this))
	{
		gameLocal.ProjectDecal(sneezeTr.endpos, -sneezeTr.c.normal, 8.0f, true, 16.0f, sneezeType <= 0 ? spawnArgs.GetString("mtr_sneezesplat") : spawnArgs.GetString("mtr_sneezesplat_blood"));
	}

	//TODO: FIX the spit decal so that it doesn't glow.

	
	


	if (sneezeType == 0)
	{
		//push player backward.
		GetPhysics()->SetLinearVelocity(physicsObj.GetLinearVelocity() + (viewAngles.ToForward() * -256));
		StartSound("snd_sneeze", SND_CHANNEL_VOICE, 0, false, NULL);
		sneezeValue = SNEEZE_MAXVALUE;

		gameLocal.SpawnInterestPoint(this, this->GetEyePosition(), spawnArgs.GetString("def_sneezeinterest"));
	}
	else
	{
		//cough blood.
		gameLocal.SpawnInterestPoint(this, this->GetEyePosition(), spawnArgs.GetString("def_coughinterest"));
	}
	
	sneezeState = SNEEZESTATE_SNEEZING;
	nextSneezeTimer = gameLocal.time + SNEEZETRIGGER_SNEEZEFREEZETIME;
}

//0 = normal, 1 = bloody
void idPlayer::DoSpit(int spitType)
{
	idProjectile	*spitProjectile;
	idEntity *		spitEnt;
	idVec3			forward, up, spawnPos, right;
	idVec3			launchDir;
	int				spitspeed;


	viewAngles.ToVectors(&forward, &right, &up);
	spawnPos = GetEyePosition() + (forward * 8) + (up * -2);
	
	if (spitType <= 0)
	{
		gameLocal.SpawnEntityDef(*spitDef, &spitEnt, false);
		spitspeed = spitDef->GetVector("velocity")[0];

		gameLocal.voManager.SayVO(this, "snd_vo_spit", VO_CATEGORY_BARK);
	}
	else
	{
		//blood cough.

		DoSneeze(1); //Do bloody sneeze.
		gameLocal.voManager.SayVO(this, "snd_vo_spit_blood", VO_CATEGORY_BARK);

		gameLocal.SpawnEntityDef(*bloodspitDef, &spitEnt, false);
		spitspeed = bloodspitDef->GetVector("velocity")[0];
	}

	spitProjectile = (idProjectile *)spitEnt;
	spitProjectile->Create(this, spawnPos, idVec3(0,0,1));
	
	launchDir = (viewAngles.ToForward() * spitspeed) + (right * (gameLocal.random.CRandomFloat() * 16));
	spitProjectile->Launch(spawnPos, viewAngles.ToForward(), launchDir);


}

void idPlayer::SetNoiseEvent(idVec3 position, int noiseType)
{
	int i;
	for (i = 0; i < NOISEEVENT_COUNT; i++)
	{
		if (noiseEventTimer[i] < gameLocal.time)
		{
			noiseEventTimer[i] = gameLocal.time + 1000;
			noiseEventPos[i] = position;
			noiseEventType[i] = noiseType;
			return;
		}
	}

	common->Warning("Unable to allocate a free noiseevent index. Max: %d\n", NOISEEVENT_COUNT);
}


//The difference with this one is it turns the player toward the yaw of the entity.
void idPlayer::Event_TeleportToEnt(idEntity *ent)
{
	Event_Teleport(ent->GetPhysics()->GetOrigin());

	float prevYaw = viewAngles.yaw;
	idVec3 prevVelocity = GetPhysics()->GetLinearVelocity();

	//snap yaw.
	float entityYaw = ent->GetPhysics()->GetAxis().ToAngles().yaw;	
	oldViewYaw = entityYaw;
	SetViewAngles(idAngles(0, entityYaw, 0));

	// Rotate linear velocity by difference in yaw to preserve relative velocity through the teleport
	GetPhysics()->SetLinearVelocity( prevVelocity * idAngles( 0, entityYaw - prevYaw, 0 ).ToMat3() );
}

void idPlayer::Event_Teleport(idVec3 destination)
{
	idVec3 org;

	if (weapon.GetEntity())
	{
		weapon.GetEntity()->LowerWeapon();
	}

	//BC in case we teleport player to/from a confined space, reset the confined variables.
	inConfinedState = false;
	confinedAngleLock = false; 
	confinedstateTimer = -100;

	
	//BC exit inspect mode.
	zoommodeActive = false;
	zoomCurrentFOV = ZOOM_MAX;

	


	SetOrigin(destination + idVec3(0, 0, CM_CLIP_EPSILON));

	if (GetFloorPos(16.0f, org))
	{
		SetOrigin(org);
	}

	// clear the ik heights so model doesn't appear in the wrong place
	walkIK.EnableAll();

	//GetPhysics()->SetLinearVelocity(vec3_origin);
	//SetViewAngles(angles);

	legsYaw = 0.0f;
	idealLegsYaw = 0.0f;
	oldViewYaw = viewAngles.yaw;

	//playerView.Flash(colorYellow, 300);	

	UpdateVisuals();

	// kill anything at the new position
	gameLocal.KillBox(this, false);
}

void idPlayer::SetAmmoDelta(const char *ammoName, int delta)
{
	int max_ammo;
	int ammo_current;
	int resultValue;

	ammo_current = idWeapon::GetAmmoNumForName(ammoName);
	max_ammo = inventory.MaxAmmoForAmmoClass(this, ammoName);

	resultValue = inventory.ammo[ammo_current] + delta;

	if (resultValue < 0)
		resultValue = 0;
	else if (resultValue > max_ammo)
		resultValue = max_ammo;
	
	inventory.ammo[ammo_current] = resultValue;
}

//  P L A C E R    C A L L S
void idPlayer::Event_getPlacerPos(void)
{
	idThread::ReturnVector(this->placerEnt->GetPhysics()->GetOrigin());
}


void idPlayer::Event_getPlacerValid(void)
{
	idThread::ReturnInt(this->placerClearance);
}


void idPlayer::Event_getPlacerRotation(void)
{
	idMat3 returnAng = placerEnt->GetPhysics()->GetAxis();

	idThread::ReturnString(returnAng.ToString());
}

void idPlayer::Event_getPlacerAngle(void)
{
	idVec3 returnAng = placerEnt->GetPhysics()->GetAxis().ToAngles().ToForward();	

	//returnAng.x = this->placerEnt->GetPhysics()->GetAxis().ToAngles().pitch;
	//returnAng.y = this->placerEnt->GetPhysics()->GetAxis().ToAngles().yaw;
	//returnAng.z = this->placerEnt->GetPhysics()->GetAxis().ToAngles().roll;

	idThread::ReturnVector(returnAng);
}

void idPlayer::UpdatePlacerSticky(void)
{	
	bool showPlacer = false;
	idEntity* selectedEnt = nullptr;
	float downwardTraceDist;
	bool doPlacerWalls;
	bool showArrow;
	if ( GetCarryable() != nullptr )
	{
		selectedEnt = GetCarryable();
		const idDeclEntityDef* weaponDef = gameLocal.FindEntityDef( selectedEnt->spawnArgs.GetString("weapon"), false );
		showPlacer = weaponDef->dict.GetBool( "showplacer" );

		downwardTraceDist = weaponDef->dict.GetFloat("placer_downdist");
		if (downwardTraceDist <= 0)
			downwardTraceDist = PLACER_DISTANCE_DOWNWARD;

		doPlacerWalls = weaponDef->dict.GetBool("placer_allowwall", "1");
		showArrow = weaponDef->dict.GetBool("placer_showarrow", "0");
	}
	else if ( weapon.IsValid() )
	{
		idWeapon* weaponEnt = weapon.GetEntity();
		selectedEnt = weaponEnt;
		showPlacer = selectedEnt->spawnArgs.GetBool( "showplacer" ) && weaponEnt->IsReady();

		downwardTraceDist = selectedEnt->spawnArgs.GetFloat("placer_downdist");
		if (downwardTraceDist <= 0)
			downwardTraceDist = PLACER_DISTANCE_DOWNWARD;

		doPlacerWalls = selectedEnt->spawnArgs.GetBool("placer_allowwall", "1");
		showArrow = selectedEnt->spawnArgs.GetBool("placer_showarrow", "0");
	}
	else
	{
		placerClearance = false;
		return;
	}

	int currentHotbarslotIndex = inventory.GetHotbarSelection();
	if (inventory.hotbarSlots[currentHotbarslotIndex].weaponType <= 0)
	{
		showPlacer = false;
	}
	
	if (!showPlacer || frobEnt != NULL || peekObject.IsValid() || viewyawState != LERPSTATE_OFF || IsLeaning())
	{
		if (!placerEnt->IsHidden())
		{
			placerEnt->Hide();
		}

		if (!placerEntLine->IsHidden())
		{
			placerEntLine->Hide();
		}

		if (!placerEntArrow->IsHidden())
		{
			placerEntArrow->Hide();
		}

		placerClearance = false;
		return;
	}

	idVec3 start, end, finalpos;
	trace_t trace;
	idAngles finalAng;
	idVec3 upAng, rightAng;
	bool hitWall = false;

	//Do the tracepoint for the placer.
	start = GetEyePosition();	
	end = start + (this->viewAngles.ToForward() * ((viewAngles.pitch > 0) ? downwardTraceDist : PLACER_DISTANCE_UPWARD));	
	gameLocal.clip.TracePoint(trace, start, end, MASK_SHOT_RENDERMODEL, this);
	
	//Hit nothing.
	if (trace.fraction >= 1)
	{
		placerEnt->Hide();
		placerEntLine->Hide();
		placerEntArrow->Hide();
		placerClearance = false;
		return;
	}	

	//hit something.
	//check if we allow walls.
	if (!doPlacerWalls)
	{
		if (trace.c.normal.z < .89f)
		{
			//only allow on flat (flattish) floor. Still allows placement on ramps.
			placerEnt->Hide();
			placerEntLine->Hide();
			placerEntArrow->Hide();
			placerClearance = false;
			return;
		}
	}

	int i;
	if (placerEnt->IsHidden())
	{
		placerEnt->Show();

		if (showArrow)
		{
			placerEntArrow->Show();
		}
	}

	if ( selectedEnt->spawnArgs.GetBool("showplacerline"))
	{
        //This is for the wiregrenade tripwire visualization.
		placerEntLine->Show();
	}

	finalAng.pitch = trace.c.normal.ToAngles().pitch;
	finalAng.yaw = trace.c.normal.ToAngles().yaw;
	finalAng.roll = trace.c.normal.ToAngles().roll;

	if (trace.c.normal.z > .45f || trace.c.normal.z < -.45f)
	{
		//if on floor or ceiling.
		finalAng.roll = viewAngles.yaw + 180;
	}

	placerEnt->SetAngles(finalAng);

	finalpos.x = trace.endpos.x;
	finalpos.y = trace.endpos.y;
	finalpos.z = trace.endpos.z;
	finalpos += trace.c.normal.ToAngles().ToForward() * .1f; //move it away from wall a little.
	placerEnt->SetOrigin(finalpos);
	finalAng.ToVectors(NULL, &rightAng, &upAng);


	if (showArrow)
	{
		//Placer arrow angle
		idAngles arrowAngle = idAngles( -90.0f - finalAng.pitch, viewAngles.yaw, 0 );
		placerEntArrow->SetAxis(arrowAngle.ToMat3());
		idVec3 arrowOrigin = placerEnt->GetPhysics()->GetOrigin();
		arrowOrigin.z += 1.0f;
		placerEntArrow->SetOrigin( arrowOrigin );
	}


	//If it's a monster, then it's always true.
	if (trace.c.entityNum >= 0 && trace.c.entityNum <= MAX_GENTITIES - 2)
	{
		if (gameLocal.entities[trace.c.entityNum]->IsType(idAI::Type))
		{
			//For sticky placement, keep track of where to attach to this monster.
			placerEntityNumber = trace.c.entityNum;
			placerEntityCollisionID = trace.c.id;

			placerEnt->SetSkin(declManager->FindSkin("skins/objects/ui_throwdisc/skin_slow"));			
			placerClearance = true;
			return;
		}
		else if (gameLocal.entities[trace.c.entityNum]->IsType(idWorldspawn::Type)
			|| gameLocal.entities[trace.c.entityNum]->IsType(idDoor::Type)
			|| gameLocal.entities[trace.c.entityNum]->IsType(idStaticEntity::Type)
			|| gameLocal.entities[trace.c.entityNum]->IsType(idMover::Type)
			|| gameLocal.entities[trace.c.entityNum]->IsType(idDamagable::Type))
		{
			//Whitelist. Allow placerEnt placement on these things.
		}
		else
		{
			placerClearance = false;
			placerEnt->SetSkin(declManager->FindSkin("skins/objects/ui_throwdisc/skin_red"));			
			return;
		}
	}

	//gameRenderWorld->DebugArrow(colorGreen, finalpos, finalpos + rightAng * PLACER_BOUNDSIZE, 1, 100);
	//gameRenderWorld->DebugArrow(colorRed, finalpos, finalpos + upAng * PLACER_BOUNDSIZE, 1, 100);

	//See if walls intersect with any part of the placer.
	for (i = 0; i < 4; i++)
	{
		trace_t trWall, trLedge;
		idVec3 endPos;

		if (i == 0)
			endPos = finalpos + rightAng * PLACER_BOUNDSIZE;
		else if (i == 1)
			endPos = finalpos + rightAng * -PLACER_BOUNDSIZE;
		else if (i == 2)
			endPos = finalpos + upAng * PLACER_BOUNDSIZE;
		else
			endPos = finalpos + upAng * -PLACER_BOUNDSIZE;

		gameLocal.clip.TracePoint(trWall, finalpos, endPos, MASK_SHOT_RENDERMODEL, this);

		if (trWall.fraction < 1.0f)
		{
			hitWall = true;
			break;
		}

		//See if it's half-off a ledge.
		gameLocal.clip.TracePoint(trLedge, trWall.endpos, trWall.endpos + (trace.c.normal * -4.0f), MASK_SHOT_RENDERMODEL, this);

		if (trLedge.fraction >= 1.0f)
		{
			hitWall = true;
			break;
		}
	}

	if (hitWall)
	{
		placerEnt->SetSkin(declManager->FindSkin("skins/objects/ui_throwdisc/skin_red"));
		placerEntLine->SetColor(colorRed);
		placerClearance = false;
		return;
	}

	trace.c.entityNum = -1;
	placerEnt->SetSkin(declManager->FindSkin("skins/objects/ui_throwdisc/skin_slow"));
	placerEntLine->SetColor(colorWhite);
	placerClearance = true;
}

void idPlayer::BindStickyItem(idEntity *stickyItem)
{
	idEntity* hitEnt;
	jointHandle_t monsterJoint;
	idMat3 _axis;
	idVec3 _pos;

	//gameRenderWorld->DebugArrow(colorGreen, placerEnt->GetPhysics()->GetOrigin(), placerEnt->GetPhysics()->GetOrigin() + placerEnt->GetPhysics()->GetAxis().ToAngles().ToForward() * 64, 2, 10000);

	if (!placerClearance)
		return;
	
	if (placerEntityNumber < 0 || placerEntityNumber >= MAX_GENTITIES - 2)
		return;

	hitEnt = gameLocal.entities[placerEntityNumber];

	if (!hitEnt)
		return;

	if (!hitEnt->IsType(idAI::Type)) //idAFEntity_Base::Type
		return;
	
	monsterJoint = CLIPMODEL_ID_TO_JOINT_HANDLE(placerEntityCollisionID);

	if (monsterJoint == INVALID_JOINT)
	{
		return;
	}

	//((idAFEntity_Base *)hitEnt)->GetJointWorldTransform(monsterJoint, gameLocal.time, _pos, _axis);

	stickyItem->BindToJoint(hitEnt, monsterJoint, true);
}

//Knock player down. value = fall or get up. hardFall = did I fall down, or am I voluntarily lying down.
void idPlayer::SetFallState(bool value, bool hardFall)
{
	if (value && !noclip)
	{
		if (airless)
			return; //cannot get knocked down when in space.

		if (mechTransitionState != MECHTRANSITION_NONE)
		{
			return; // player cannot be knocked down while inside the mech
		}

		//Enter fall state.
		AI_FALLEN = true;
		physicsObj.SetFallState(hardFall);

		if (hardFall)
			SetViewPitchLerp(FALLENSTATE_INITIALPITCH, 100);

		viewYawLockAngle = viewAngles.yaw;
		// Set initial knockeddownLastSpeed so the velocity isn't cleared on the first frame
		knockeddownLastSpeed = ( usercmd.rightmove != 0 && usercmd.forwardmove == 0 ) ? KNOCKDOWN_ROLLSPEED : KNOCKDOWN_FORWARDSPEED;
		//SetArmVisibility(true);
	}
	else
	{
		//Exit fall state.
		AI_FALLEN = false;
		AI_FALLEN_GETUP = false;
	}
}

//WARNING: THIS DOESN'T WORK. USE INSTEAD: Event_SetFallState(false, false, false);
void idPlayer::SetFallGetupState()
{
	AI_FALLEN_GETUP = true;
}

bool idPlayer::GetFallenState()
{
	if (AI_FALLEN)
		return true;

	return false;
}

void idPlayer::Event_GetFallState()
{
	idThread::ReturnFloat((float)AI_FALLEN);
}

// SW: There's some funkiness around exiting the fall state that necessitates this extra layer of interpretation when making script calls.
void idPlayer::Event_SetFallState(bool enable, bool hardFall, bool immediateExit)
{
	if (enable)
	{
		SetFallState(enable, hardFall);
	}
	else if (immediateExit)
	{
		// Exit fallen state with no animation, no anything
		this->physicsObj.SetImmediateExitFallState();
	}
	else
	{
		// Begin kick-up
		this->physicsObj.BeginGetUp();
	}
}

void idPlayer::Event_SetButtonPrompt(int prompttype)
{
	if (mechTransitionState == MECHTRANSITION_PILOTING)
		return;

	buttonpromptType = prompttype;
	buttonpromptTimer = gameLocal.time + BUTTONPROMPT_DISPLAYTIME;

	if (prompttype == BUTTONPROMPT_RACKSLIDE)
		hud->HandleNamedEvent("showRackButton");
	else
		hud->HandleNamedEvent("showReloadButton");
}


void idPlayer::SetCameraGuiEvent(const char* eventName)
{
	if (!hud)
		return;

	if (entityNumber != gameLocal.localClientNum)
		return;

	cameraGuiMenu->HandleNamedEvent(eventName);
}

void idPlayer::SetHudEvent(const char *eventName)
{
	if (!hud)
		return;

	if (entityNumber != gameLocal.localClientNum)
		return;	

	hud->HandleNamedEvent(eventName);
}


void idPlayer::ZippingTo(idVec3 destination, idWinding* aperture, float forceDuckDuration)
{
	physicsObj.ZippingTo(destination, aperture, forceDuckDuration);
}

void idPlayer::Cableswoop(idEntity * startPoint, idEntity * endPoint)
{
	physicsObj.CableswoopTo(startPoint, endPoint);
}

void idPlayer::SpaceCableswoop(idEntity * startPoint, idEntity * endPoint)
{
	physicsObj.SpaceCableswoopTo(startPoint, endPoint);
}

void idPlayer::Event_HasDefib(void)
{
	idThread::ReturnFloat((float)defibAvailable);
}

void idPlayer::ActivateDefib()
{
	SetDefibAvailable(false);
	defibState = DEFIB_SETUP;
	inDownedState = false;
	health = 1;
	fl.takedamage = false;

	//If in mech, kick player out of mech when defib starts.
	if (IsInMech())
	{
		ExitMech(false);
	}
}

void idPlayer::UpdateDefib()
{
	if (defibState == DEFIB_NONE)
		return;

	if (defibState == DEFIB_SETUP)
	{
		//if doing the oxygen suffocation breathing, stop the audio for it
		StopSound(SND_CHANNEL_BODY2, false);

		//Spawn all the stuff for the defib sequence.
		idDict args;
		trace_t camTr;
		idAngles facingDir;
		idVec3 camSpawnPos;
		idVec3 camDestination;


		defibYaw = viewAngles.yaw;
		viewAngles.pitch = 0; //lock pitch to straight forward.
		SetArmVisibility(true);
		SetState("Defib_Fall", true);

		args.Clear();
		args.Set("classname", "func_mover");
		args.SetBool("solid", false);
		args.SetBool("cinematic", true);
		gameLocal.SpawnEntityDef(args, &defibCameraTarget);
		defibCameraTarget->SetOrigin(GetPhysics()->GetOrigin());
		
		idAngles cameraAngle = idAngles(89, viewAngles.yaw, 0);

		args.Clear();
		args.Set("classname", "func_cameraview");
		args.SetInt("fov", DF_CAMERA_FOV);
		//args.Set("attachedView", defibCameraTarget->GetName());
		args.SetMatrix("rotation", cameraAngle.ToMat3());
		gameLocal.SpawnEntityDef(args, &defibCamera);

		if (!defibCamera || !defibCamera->IsType(idCameraView::Type))
		{
			common->Error("Defib camera setup had a fatal error.\n");
			return;
		}

		//Decide where to place camera. Shoot traceline upward.
		gameLocal.clip.TracePoint(camTr, gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin(), gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin() + idVec3(0,0, DF_MAXHEIGHT), MASK_SOLID, this);

		facingDir = idAngles(0, defibYaw, 0);
		camSpawnPos = camTr.endpos + (facingDir.ToForward() * -4);

		defibCamera->GetPhysics()->SetOrigin(camSpawnPos);

		//Spawn the mover.
		args.Clear();
		args.Set("classname", "func_mover");
		args.SetFloat("move_time", (DF_ZOOMINTIME / (float)1000.0f) );
		args.SetBool("solid", false);
		args.SetBool("cinematic", true);
		gameLocal.SpawnEntityDef(args, &defibMover);

		if (!defibMover || !defibMover->IsType(idMover::Type))
		{
			common->Error("Defib mover setup had a fatal error.\n");
			return;
		}

		#define DEFIB_CAMERA_HEIGHTABOVEPLAYER 32
		camDestination = GetPhysics()->GetOrigin() + idVec3(0,0, DEFIB_CAMERA_HEIGHTABOVEPLAYER);

		defibMover->SetOrigin(camSpawnPos);
		defibCamera->Bind(defibMover, false);
		((idMover*)defibMover)->Event_SetAccellerationTime(400.0f);
		((idMover*)defibMover)->Event_SetDecelerationTime(400.0f);
		((idMover *)defibMover)->Event_MoveToPos(camDestination);
		((idCameraView *)defibCamera)->SetActive(true);

		defibTimer = gameLocal.time + DF_ZOOMINTIME;
		defibState = DEFIB_ZOOMIN;


		StartSound("snd_defib", SND_CHANNEL_ANY);

		
	}
	else if (defibState == DEFIB_ZOOMIN)
	{
		//Camera is above player, zooming in to player.

		if (gameLocal.time > defibTimer)
		{
			//has zoomed into player.
			defibState = DEFIB_HEARTANIM;
			defibTimer = gameLocal.time + 1500;


			defibParticleDone = false;
			defibParticleTimer = gameLocal.time + 700; //how long in animation before the defib activates



			//nina organs setup.
			ninaOrgansTimer = gameLocal.time + DF_ORGANS_MOVETIME;

			jointHandle_t chestJoint = GetAnimator()->GetJointHandle(spawnArgs.GetString("bone_chest"));
			if (chestJoint == INVALID_JOINT)
			{
				gameLocal.Error("defib: invalid chest joint.");
			}
			idVec3 chestAttachPos;
			idMat3 chestAttachMat;
			GetJointWorldTransform(chestJoint, gameLocal.time, chestAttachPos, chestAttachMat);
			ninaOrgansPosStart = chestAttachPos;

			ninaOrgansModel->GetPhysics()->SetOrigin(ninaOrgansPosStart);

			idAngles organAngle = defibCamera->GetPhysics()->GetAxis().ToAngles();
			ninaOrgansModel->GetPhysics()->SetAxis(organAngle.ToMat3());

			idVec3 up;
			defibCamera->GetPhysics()->GetAxis().ToAngles().ToVectors(NULL, NULL, &up);
			ninaOrgansPosEnd = defibCamera->GetPhysics()->GetOrigin() + idVec3(0, 0, -14) + (up * -7);

			//ninaOrgansModel->SetDepthHack(true);
			ninaOrgansModel->Event_PlayAnim("defib", 0);
			ninaOrgansModel->SetDepthHack(true);
			ninaOrgansModel->Show();			
		}
	}
	else if (defibState == DEFIB_HEARTANIM)
	{
		//lerp the organ position.
		float lerp = (ninaOrgansTimer - gameLocal.time) / (float)DF_ORGANS_MOVETIME;
		lerp = idMath::ClampFloat(0, 1, 1 - lerp);
		lerp = idMath::CubicEaseOut(lerp);

		idVec3 organPos;
		organPos.Lerp(ninaOrgansPosStart, ninaOrgansPosEnd, lerp);
		ninaOrgansModel->GetPhysics()->SetOrigin(organPos);


		if (!defibParticleDone && gameLocal.time > defibParticleTimer)
		{
			gameLocal.AddEventLog("#str_def_gameplay_defib_blast", GetPhysics()->GetOrigin());

			defibParticleDone = true;

			idAngles electricParticleAngle = idAngles(0, 0, 90);
			gameLocal.DoParticle(spawnArgs.GetString("model_defibparticle"), GetPhysics()->GetOrigin(), electricParticleAngle.ToForward());

			//Do electric blast on the world.
			//Do electric shock stun on nearby enemies. Only affects actors.
			for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
			{
				if (!entity)
					continue;

				if (!entity->IsType(idActor::Type) || entity->team == this->team || entity == this)
					continue;

				float distanceToPlayer = (entity->GetPhysics()->GetOrigin() - this->GetPhysics()->GetOrigin()).LengthFast();
				if (distanceToPlayer > DEFIB_ELECTROBLAST_RADIUS)
					continue;

				entity->Damage(this, this, vec3_zero, "damage_defibblast", 1.0f, 0);
			}



			//EMP blast will kill the lights in the room.
			for (idEntity* ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
			{
				if (!ent)
					continue;

				if (!ent->IsType(idElectricalBox::Type))
					continue;

				idLocationEntity* boxLocation = gameLocal.LocationForEntity(ent);
				idLocationEntity* playerLocation = gameLocal.LocationForEntity(this);
				if (boxLocation->entityNumber == playerLocation->entityNumber)
				{
					//Electrical box and player are in the same room. Kill the electrical box to kill the power in the room.

					//note this is a different damage type than damage_defibblast. This is because
					//defib does zero damage, but we need to apply actual damage to the electrical box
					//in order to blow it up.
					static_cast<idElectricalBox*>(ent)->Damage(this, this, vec3_zero, "damage_empblast", 1.0f, 0);
					break;
				}
			}



			//when the electricity blast happens, make the camera do an fov lerp.
			if (defibCamera->IsType(idCameraView::Type))
			{
				static_cast<idCameraView*>(defibCamera)->SetFOVLerp(
					static_cast<idCameraView*>(defibCamera)->GetCurrentFOV(),
					120,
					300,
					2); //LERPTYPE_CUBIC_EASE_OUT
			}

		}


		if (gameLocal.time > defibTimer)
		{
			ninaOrgansModel->Hide();

			//Defib anim is done.
			idAngles camMoveDir;
			idVec3 desiredPos;
			trace_t zoomoutTr;

			defibState = DEFIB_ZOOMOUT;
			defibTimer = gameLocal.time + DF_ZOOMOUTTIME;


			camMoveDir = idAngles(0, defibYaw, 0);
			desiredPos = GetPhysics()->GetOrigin() + (camMoveDir.ToForward() * -80) + idVec3(0, 0, pm_normalviewheight.GetFloat() - 8);

			gameLocal.clip.TracePoint(zoomoutTr, gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin(), desiredPos, MASK_SOLID, this);

			((idMover *)defibMover)->Event_SetMoveTime(DF_ZOOMOUTTIME / (float)1000.0f);
			((idMover *)defibMover)->Event_SetAccellerationTime(0);
			((idMover *)defibMover)->Event_SetDecelerationTime(DF_ZOOMOUTTIME  / (float)1000.0f);
			((idMover *)defibMover)->Event_MoveToPos(zoomoutTr.endpos);

			((idMover *)defibCameraTarget)->Event_SetMoveTime((DF_ZOOMOUTTIME + DF_ZOOMOUTTIME) / (float)1000.0f);
			((idMover *)defibCameraTarget)->Event_SetAccellerationTime((DF_ZOOMOUTTIME / 2.0f) / (float)1000.0f);
			((idMover *)defibCameraTarget)->Event_SetDecelerationTime((DF_ZOOMOUTTIME / 2.0f)  / (float)1000.0f);
			idVec3 moveToPos = GetPhysics()->GetOrigin() + (camMoveDir.ToForward() * 32)  + idVec3(0, 0, pm_normalviewheight.GetFloat());
			((idMover *)defibCameraTarget)->Event_MoveToPos(moveToPos);

			SetState("Defib_Getup", true);


			

			bool canStandHere = CanPlayerStandHere(GetPhysics()->GetOrigin() + idVec3(0, 0, 1));
			if (!canStandHere || airless)
			{
				//In a crouch/tight space, or in zero-g. Bypass the camera stuff, skip straight to completion.
				defibState = DEFIB_ZOOMTOHEAD;
				defibTimer = 0;
				StartSound("snd_defibgasp", SND_CHANNEL_ANY);
				return;
			}
		}		
	}
	else if (defibState == DEFIB_ZOOMOUT)
	{
		float zoomoutLerp = (defibTimer - gameLocal.time ) / (float)DF_ZOOMOUTTIME;
		zoomoutLerp = 1.0f - zoomoutLerp;
		zoomoutLerp = idMath::ClampFloat(0, 1, zoomoutLerp);
		
		//Move the camera angle.
		float cameraPitch = idMath::Lerp(89, DF_CAMERAPITCH_ZOOMOUTMIDPOINT, zoomoutLerp);
		defibCamera->SetAngles(idAngles(cameraPitch, defibYaw, 0));

		if (gameLocal.time > defibTimer)
		{
			idAngles camMoveDir;
			camMoveDir = idAngles(0, defibYaw, 0);
			defibState = DEFIB_ZOOMTOHEAD;
			defibTimer = gameLocal.time + DF_ZOOMOUTTIME;

			((idMover *)defibMover)->Event_SetMoveTime(DF_ZOOMOUTTIME / (float)1000.0f);
			((idMover *)defibMover)->Event_SetDecelerationTime(0);
			((idMover *)defibMover)->Event_SetAccellerationTime(DF_ZOOMOUTTIME  / (float)1000.0f);
			idVec3 moveToPos = GetPhysics()->GetOrigin() + (camMoveDir.ToForward() * -20) + idVec3(0, 0, pm_normalviewheight.GetFloat());
			((idMover *)defibMover)->Event_MoveToPos(moveToPos);
		}
	}
	else if (defibState == DEFIB_ZOOMTOHEAD)
	{
		//Is currently zooming into player head.

		float zoomoutLerp = (defibTimer - gameLocal.time) / (float)DF_ZOOMOUTTIME;
		zoomoutLerp = 1.0f - zoomoutLerp;
		zoomoutLerp = idMath::ClampFloat(0, 1, zoomoutLerp);

		//Move the camera angle.
		float cameraPitch = idMath::Lerp(DF_CAMERAPITCH_ZOOMOUTMIDPOINT, 0, zoomoutLerp);
		defibCamera->SetAngles(idAngles(cameraPitch, defibYaw, 0));


		if (gameLocal.time > defibTimer)
		{
			//Defib all done.
			defibState = DEFIB_CLEANUP;			
			((idCameraView *)defibCamera)->SetActive(false);
			inDownedState = false;
			viewAngles.roll = 0;			
		}
	}
	else if (defibState == DEFIB_CLEANUP)
	{
		defibState = DEFIB_NONE;
		hud->HandleNamedEvent("defib");
		SetArmVisibility(false);

		inDownedState = false;
		viewAngles.roll = 0;
		SetViewAngles(idAngles(0, defibYaw, 0));

		//manually re-enable saving throw here.
		health = maxHealth - (GetWoundCount() * HEALTH_PER_HEALTHBARBLOCK);
		healthrechargeTimer = gameLocal.time;
		savingthrowState = SAVINGTHROW_AVAILABLE;

		airTics = pm_airTics.GetInteger(); //Replenish air tank.

		fl.takedamage = true;


		//Remove any afflictions.
		HealAllWounds();

	}
}

bool idPlayer::GetSwoopState()
{
	return physicsObj.GetSwoopState();
}

void idPlayer::GetYawDelta()
{
	idThread::ReturnFloat(currentYawDelta);
}

bool idPlayer::GetDefibState()
{
	if (defibState == DEFIB_NONE)
	{
		idThread::ReturnFloat(0);
		return false;
	}
		
	idThread::ReturnFloat(1);

	return true;
}

void idPlayer::HideBloodbag()
{
	bloodbagMesh->StopSound(SND_CHANNEL_BODY3, false);
	bloodbagState = BLOODBAGSTATE_NONE;
	bloodbagMesh->Hide();
	bloodbagEmitter->Hide();

	bloodbagMesh->GetRenderEntity()->shaderParms[SHADERPARM_TIME_OF_DEATH] = 0.0f;
}

//This is what gets called via animation events (search for "healwound" in player.def)
void idPlayer::HealWound(const char *woundName)
{
	if (!idStr::Icmp(woundName, "bullet"))
	{
		if (cond_bulletwound > 0)
		{
			DoHealPluck("def_bulletpluck");
			cond_bulletwound--;

			if (cond_bulletwound <= 0)
			{
				WoundRegenerateHealthblock();
			}
		}
	}
	else if (!idStr::Icmp(woundName, "shrapnel"))
	{
		if (cond_shrapnel > 0)
		{
			DoHealPluck("def_shrapnelpluck");
			cond_shrapnel--;

			if (cond_shrapnel <= 0)
			{
				WoundRegenerateHealthblock();
			}
		}
	}
}

void idPlayer::Event_ClearWounds(int silent)
{
	HealAllWounds(silent);
}

// Heals all wounds & conditions.
// If 'silent', do this without any fanfare or effects
void idPlayer::HealAllWounds(bool silent)
{
	if (!silent)
	{
		//If I have bulletwounds, then make the bullets pop out of my body
		if (cond_bulletwound > 0)
		{
			HealAllWoundEjectDebris("def_bulletpluck", cond_bulletwound);
		}

		if (cond_shrapnel > 0) //spew out all shrapnel pieces
		{
			HealAllWoundEjectDebris("def_shrapnelpluck", cond_shrapnel);
		}

		if (cond_glasswound > 0) //spew out all glass pieces
		{
			HealAllWoundEjectDebris("def_glasspluck", cond_glasswound);
		}
	}

	cond_burnwound = 0;
	burningTimer = 0;
	cond_glasswound = 0;
	cond_bulletwound = 0;
	cond_shrapnel = 0;
	//cond_spearwound = 0;
	SetSmelly(false, false);

	for (int i = 0; i < WOUNDCOUNT_MAX; i++)
	{
		woundArray[i] = false;
	}

	WoundRegenerateHealthblock();
}

void idPlayer::HealAllWoundEjectDebris(const char *defName, int count)
{
	for (int i = 0; i < count; i++)
	{
		idVec3 bodydebrisSpawnPos = GetEyePosition() + idVec3(0, 0, -4);
		bodydebrisSpawnPos.x += gameLocal.random.CRandomFloat() * 3;
		bodydebrisSpawnPos.y += gameLocal.random.CRandomFloat() * 3;
		bodydebrisSpawnPos.z += gameLocal.random.CRandomFloat() * 3;
		EjectBodyDebris(defName, bodydebrisSpawnPos);
	}
}

void idPlayer::FlashScreen()
{
	playerView.Flash(colorWhite, 2000);
}

void idPlayer::FlashScreenCustom(idVec4 color, int time)
{
	playerView.Flash(color, time);
}

void idPlayer::SetHideState(idEntity * hideEnt, int hideType)
{
	//if (GetCarryable() != NULL)
	//{
	//	DropCurrentCarryable(true);
	//}
	physicsObj.SetHideState(hideEnt, hideType);
}

void idPlayer::SetAcroHide(idEntity * hideEnt)
{
	//if (GetCarryable() != NULL)
	//{
	//	DropCurrentCarryable(true);
	//}
	physicsObj.SetAcroState(hideEnt);
}

int idPlayer::GetAcroType()
{
	return physicsObj.GetAcroType();
}

void idPlayer::EnterMech(idEntity * mechEnt)
{
	mountedMech = (idMech *)frobEnt;

	viewAngles.roll = 0;
	SetViewAngles(idAngles(0, viewAngles.yaw, 0));
	
	SetViewYawLerp(mountedMech.GetEntity()->viewAxis.ToAngles().yaw, MECH_MOVETOBEHIND_TIME);

	mechplayerStartPos = GetPhysics()->GetOrigin();
	mechTransitionTimer = gameLocal.time;
	mechTransitionState = MECHTRANSITION_MOVINGTOBEHIND;

	mechStartupstate = true;

	if (AI_FALLEN || AI_FALLEN_GETUP)
	{
		this->physicsObj.SetImmediateExitFallState();
	}

	Hide(); //hide player.

	// Hide hotbar slots
	for ( int i = 0; i < MAX_HOTBARSLOTS; i++ )
	{
		hud->SetStateBool( va( "hotbarvisible%d", i ), false ); //Set hotbar visibility.
	}

	hud->HandleNamedEvent("onEnterMech");
}

void idPlayer::UpdateMechCockpit()
{
	idVec3 cockpitPos;
	idAngles cockpitAng;
	float tiltLerp;

	cockpitAng = idAngles(viewAngles.pitch, viewAngles.yaw, 0);
	cockpitPos = GetEyePosition() + (idAngles(0, viewAngles.yaw, 0).ToForward() * MECH_VIEW_OFFSET) + (cockpitAng.ToForward() * 7);

	//Tweak the cockpit position a little depending on camera tilt.
	tiltLerp = (viewAngles.pitch + 90) / 180.0f;
	cockpitPos.Lerp(cockpitPos + idVec3(0, 0, 1), cockpitPos + idVec3(0, 0, -1), tiltLerp);

	mechCockpit->SetOrigin(cockpitPos);
	mechCockpit->SetAxis(idAngles(cockpitAng.pitch, cockpitAng.yaw, 0).ToMat3());

	//Update mech hud.
	hud->SetStateInt("mechhealth", Max( mountedMech.GetEntity()->health, 0));

	float healthbarAmount = mountedMech.GetEntity()->health / (float)mountedMech.GetEntity()->maxHealth;
	healthbarAmount = idMath::ClampFloat(0, 1, healthbarAmount);

	hud->SetStateFloat("mechhealthbar", healthbarAmount);
}

bool idPlayer::IsInMech() const
{
	return (mechTransitionState == MECHTRANSITION_PILOTING);
}

bool idPlayer::IsInMechEvent()
{
	idThread::ReturnInt(IsInMech() ? 1 : 0);

	return IsInMech();
}

void idPlayer::RemovePlayerWeapon(int switchToEmptyWeapon)
{
	SetHotbarSlot( currentWeaponSlot, 0, "", 0, NULL ); //set unarmed.
	weapon.GetEntity()->ResetAmmoClip();
	weapon.GetEntity()->WeaponStolen();
	weaponGone = true;

	if (switchToEmptyWeapon)
	{
		Event_SelectWeapon("weapon_unarmed"); //BC go to unarmed.
	}
}

//Set alpha (a) to 1.0 to fade to a color. Set alpha to 0.0 to fade from a color.
void idPlayer::SetViewFade(float r, float g, float b, float a, int time)
{
	playerView.Fade(idVec4(r, g, b, a), time);
}


void idPlayer::Lightedit_reset()
{
	idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();

	if (selectedLight)
	{
		idLight	*lightEnt = static_cast<idLight*>(selectedLight);
		if (lightEnt)
		{
			idVec3 origin = lightEnt->spawnArgs.GetVector("origin");
			lightEnt->SetOrigin(origin);
			lightEnt->UpdateChangeableSpawnArgs(nullptr);
			bool start_off;
			lightEnt->spawnArgs.GetBool("start_off", "0", start_off);
			if (start_off == lightEnt->Event_IsOn())
			{
				if (start_off)
				{
					lightEnt->Off();
				}
				else
				{
					lightEnt->On();
				}
			}

			if (lightEnt->GetNoShadow())
				gameEdit->lighteditMenu->HandleNamedEvent("init_shadowsIsOff");
			else
				gameEdit->lighteditMenu->HandleNamedEvent("init_shadowsIsOn");

			if (lightEnt->Event_IsOn())
				gameEdit->lighteditMenu->HandleNamedEvent("init_lightIsOn");
			else
				gameEdit->lighteditMenu->HandleNamedEvent("init_lightIsOff");

			if (lightEnt->Event_IsAmbient())
				gameEdit->lighteditMenu->HandleNamedEvent("init_ambientIsOn");
			else
				gameEdit->lighteditMenu->HandleNamedEvent("init_ambientIsOff");

			idVec3 currentRadius = lightEnt->GetRadius();
			gameEdit->lighteditMenu->SetStateInt("lightsize_x", currentRadius.x);
			gameEdit->lighteditMenu->SetStateInt("lightsize_y", currentRadius.y);
			gameEdit->lighteditMenu->SetStateInt("lightsize_z", currentRadius.z);

			idVec4 lightCurrentcolor; 
			lightEnt->GetColor(lightCurrentcolor);
			lightEnt->SetColor(lightCurrentcolor);
			//set sliders.
			gameLocal.editEntities->SetRGBSliders(lightCurrentcolor.ToVec3());

			//set preview.
			gameEdit->lighteditMenu->SetStateFloat("preview_r", lightCurrentcolor.x);
			gameEdit->lighteditMenu->SetStateFloat("preview_g", lightCurrentcolor.y);
			gameEdit->lighteditMenu->SetStateFloat("preview_b", lightCurrentcolor.z);
		}
	}
}

void idPlayer::Lightedit_resize(idVec3 value)
{
	idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();

	if (selectedLight)
	{
		idLight	*lightEnt = static_cast<idLight*>(selectedLight);
		if (lightEnt)
		{
			idVec3 currentRadius = lightEnt->GetRadius();

			currentRadius += value;
			lightEnt->SetRadiusXYZ(currentRadius.x, currentRadius.y, currentRadius.z);

			gameEdit->lighteditMenu->SetStateInt("lightsize_x", currentRadius.x);
			gameEdit->lighteditMenu->SetStateInt("lightsize_y", currentRadius.y);
			gameEdit->lighteditMenu->SetStateInt("lightsize_z", currentRadius.z);
		}
	}
}

void idPlayer::Lightedit_reposition(idVec3 delta)
{
	idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();

	if (selectedLight)
	{
		idLight	*lightEnt = static_cast<idLight*>(selectedLight);
		if (lightEnt)
		{
			idVec3 currentPos = lightEnt->GetPhysics()->GetOrigin();
			lightEnt->SetOrigin(currentPos + delta);
		}
	}
}

void idPlayer::Lightedit_colordelta(float value)
{
	idEntity * selectedLight = gameEdit->GetFirstSelectedEntity();

	if (selectedLight)
	{
		idLight	*lightEnt = static_cast<idLight*>(selectedLight);

		if (lightEnt)
		{
			int i;

			idVec3 lightCurrentcolor = lightEnt->GetBaseColor();

			lightCurrentcolor += idVec3(value, value, value);
			for (i = 0; i < 3; i++)
			{
				if (lightCurrentcolor[i] < 0)
					lightCurrentcolor[i] = 0;
				else if (lightCurrentcolor[i] > 1)
					lightCurrentcolor[i] = 1;
			}


			//set sliders.
			gameLocal.editEntities->SetRGBSliders(lightCurrentcolor);

			//set preview.
			gameEdit->lighteditMenu->SetStateFloat("preview_r", lightCurrentcolor.x);
			gameEdit->lighteditMenu->SetStateFloat("preview_g", lightCurrentcolor.y);
			gameEdit->lighteditMenu->SetStateFloat("preview_b", lightCurrentcolor.z);
		}
	}
}

void idPlayer::LightEdit_OpenMenu(bool value)
{
	gameEdit->editmenuActive = value;

	if (gameEdit->editmenuActive)
	{
		//Edit menu has been OPENED. This gets fired ONCE whenever editmenu is opened.
		gameEdit->lighteditMenu->SetCursor(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2); //Center mouse cursor.
		oldMouseX = usercmd.mx;
		oldMouseY = usercmd.my;

		gameEdit->lighteditMenu->HandleNamedEvent("openEditmenu");
	}
	else
	{
		//Edit menu has been CLOSED.
		gameEdit->lighteditMenu->HandleNamedEvent("closeEditmenu");
	}
}

void idPlayer::StartMovelerp(idVec3 destination, int moveTime)
{
	physicsObj.StartMovelerp(destination, moveTime);
}

void idPlayer::KillFeedback()
{
	if (cursor) //BC hitmarker for on-foot; not in mech
	{
		cursor->HandleNamedEvent("killTime");
	}
}

bool idPlayer::IsInHealState()
{
	if (healState != HEALSTATE_NONE)
		return true;

	return false;
}


void idPlayer::SetHudNamedEvent(const char * eventName)
{
	if (!hud)
		return;

	hud->HandleNamedEvent(eventName);
}

void idPlayer::SetHudParmInt(const char * parmName, int value)
{
	if (!hud)
		return;

	hud->SetStateInt(parmName, value);
}

//lerp from player eyeball to somewhere.
void idPlayer::SetViewposAbsLerp(const idVec3 &_target, int _duration)
{
	viewposAbsStart = GetEyePosition();
	viewposAbsTarget = _target;

	viewposAbsActive = true;
	viewposAbsTimer = gameLocal.time;
	viewposAbsDuration = _duration;
}

//lerp from somewhere to player eyeball
void idPlayer::SetViewposAbsLerp2(const idVec3 &_target, int _duration)
{
	viewposAbsStart = _target;
	viewposAbsTarget = GetEyePosition();

	viewposAbsActive = true;
	viewposAbsTimer = gameLocal.time;
	viewposAbsDuration = _duration;
}

bool idPlayer::GetSmelly()
{
	return (cond_smelly > 0 ? true : false);
}

void idPlayer::Event_SetSmelly(int value)
{
	if (value > 0)
		SetSmelly(true, false);
	else
		SetSmelly(false, false);
}

void idPlayer::SetSmelly(bool value, bool showMessage)
{
	if (!gameLocal.world->spawnArgs.GetBool("meta_smelly", "1"))
		return;

	if (value)
	{
		if (cond_smelly <= 0 && showMessage)
		{
			hud->HandleNamedEvent("smellstart");
		}

		cond_smelly = 1;
	}
	else
	{
		if (cond_smelly > 0)
		{
			int			listedEntities;
			idEntity	*entityList[MAX_GENTITIES];

			//Remove the smell.

			if (showMessage)
			{
				hud->HandleNamedEvent("smellgone");
			}

			idEntityFx::StartFx(spawnArgs.GetString("fx_smellpurge"), GetPhysics()->GetOrigin() + idVec3(0,0,32), mat3_identity);

			listedEntities = gameLocal.EntitiesWithinRadius(GetPhysics()->GetOrigin(), SMELLY_PURGERADIUS, entityList, MAX_GENTITIES);

			//Remove smell clouds that are near the player. This is to make it crystal clear that the smell is gone.
			for (int i = 0; i < listedEntities; i++)
			{
				idEntity *ent = entityList[i];

				if (!ent)
					continue;

				if (ent->IsType(idEntityFx::Type))
				{
					const char * fxName = static_cast<idEntityFx *>(ent)->EffectName();
					
					if (fxName != nullptr)
					{
						if (idStr::FindText(fxName, "smell_trashcloud", false) >= 0)
						{
							//Found a smell cloud.
							ent->PostEventMS(&EV_Remove, 0);
						}
					}
				}
			}
		}

		cond_smelly = 0;

		//if affected by gas cloud, wash out the gas cloud status.
		if (cond_gascloud)
		{
			SetGascloudState(false);
		}
	}

	hud->SetStateInt("smelly", cond_smelly);
	contextMenu->SetStateInt("smelly", cond_smelly);
}

bool idPlayer::GetOnFire()
{
	return (burningTimer > gameLocal.time);
}

bool idPlayer::SetOnFire(bool value)
{
	if (value)
	{
		if (burningTimer <= 0)
		{
			//Start the burn.			
			burningTimer = gameLocal.time + CONDITION_BURNING_TIME;
		}
		else
		{
			//Player is already burning, and got hit by another burn. Accelerate the existing burn.
			burningTimer -= (CONDITION_BURNING_TIME * .125f);
		}
	}
	else
	{
		bool firePutOut = (burningTimer > gameLocal.time); //is player currently on fire?

		burningTimer = 0; //Douse the fire.

		return firePutOut;
	}

	return true;
}


idEntity * idPlayer::GetCarryable()
{
	if (carryableItem.IsValid())
	{
		if (carryableItem.GetEntity() != NULL)
		{
			return carryableItem.GetEntity();
		}
	}

	return NULL;
}

void idPlayer::SetCarryable(idEntity * ent, bool value, bool gentleDrop)
{
	//Set item to carry around.

	if (ent == nullptr && value)
		return;

	if (value)
	{
		//if currently already carrying something, then drop it.
		//DropCurrentCarryable(false);

		//if dragging body, then drop the body.
		bodyDragger.StopDrag(false);

		//Pick it up. Apply these properties to whatever carryable we pick up.
		carryableItem = ent;

		ent->Unbind();
		ent->GetPhysics()->SetGravity(vec3_origin);
		//carryableItem.GetEntity()->fl.grabbed = true;
		ent->GetRenderEntity()->weaponDepthHack = true;
		StartSound("snd_grab", SND_CHANNEL_ANY, 0, false, NULL);
		ent->GetPhysics()->SetClipMask(0); //turn off collision.

		ent->GetPhysics()->GetClipModel()->SetOwner(this); //set owner to player, to prevent object-player collision.

		
		//hud->HandleNamedEvent("carryableFanfare"); //do a fanfare animation to make the carryable pickup event more prominent
		//hud->SetStateString("equippedCarryable", carryableItem.GetEntity()->displayName.c_str());


		//hud->SetStateBool("carryableBoxVisible", true);
		UpdateHotbarHighlight(true);

		const char *grabsound = ent->spawnArgs.GetString("snd_acquire", "");
		if (grabsound[0] != '\0')
		{
			ent->StartSound("snd_acquire", SND_CHANNEL_ANY, 0, false, NULL);
		}
	}
	else
	{
		//Drop it.

		if (carryableItem.GetEntity()->IsType(idSkullsaver::Type))
		{
			static_cast<idSkullsaver *>(carryableItem.GetEntity())->ResetConveyTime();
		}


        //Re-enable the item line if necessary.
        if (carryableItem.GetEntity()->spawnArgs.GetBool("frobhighlight", "0") && carryableItem.GetEntity()->isFrobbable && carryableItem.GetEntity()->IsType(idMoveableItem::Type))
        {
            static_cast<idMoveableItem *>(carryableItem.GetEntity())->SetItemlineActive(true);
        }

		carryableItem.GetEntity()->GetRenderEntity()->weaponDepthHack = false;
		carryableItem.GetEntity()->GetPhysics()->SetClipMask(MASK_SOLID | CONTENTS_RENDERMODEL); //re-enable collision.

		if (!gameLocal.GetAirlessAtPoint(carryableItem.GetEntity()->GetPhysics()->GetOrigin())) //If in place that has gravity, then return gravity to item.
		{
			carryableItem.GetEntity()->GetPhysics()->SetGravity(gameLocal.GetGravity());
		}

		StartSound("snd_ungrab", SND_CHANNEL_ANY, 0, false, NULL);		

		static_cast<idMoveableItem *>(carryableItem.GetEntity())->SetJustDropped(gentleDrop);

		//Nudge the item a little to prevent it from awkwardly perfectly balancing itself.
		carryableItem.GetEntity()->GetPhysics()->SetAngularVelocity(idVec3((gameLocal.random.RandomInt(2) > 0) ? 6 : -6, 0, 0));
		carryableItem.GetEntity()->GetPhysics()->SetLinearVelocity(idVec3(0, 0, 2));

		//Remove it from the hotbar and inventory.
		this->RemoveCarryableFromHotbar(inventory.GetHotbarSelection());

		carryableItem = NULL;

		//make the hud revert back to displaying weapon name.
		UpdateHudWeapon();
		//hud->SetStateBool("carryableBoxVisible", false);
		UpdateHotbarHighlight(true);
	}
}


//Update carryableitem's position. make sure it doesn't penetrate into walls
void idPlayer::UpdateCarryableItem()
{
	idVec3 carrytargetPosition;
	//idVec3 carrystartPosition;
	idVec3 forward, right, up;	
	idVec3 carryOffset;
	trace_t carryTr;
	idVec3 angleOffset;

	if (!carryableItem.IsValid())
	{
		carryableItem = NULL;
		return;
	}

	if (peekObject.IsValid())
	{
		//is looking through ventpeek.
		return;
	}

	idEntity* carryableEnt = carryableItem.GetEntity();

	//Set object angle. We get the player viewangle, and then tweak it with the carryangle spawnarg values.
	angleOffset = carryableEnt->spawnArgs.GetVector("carryangle", "0 0 0");
	const idMat3 &viewAxis = firstPersonViewAxis;
	idAngles itemAngle;
	itemAngle.pitch = angleOffset.x;
	itemAngle.yaw = angleOffset.y;
	itemAngle.roll = angleOffset.z;
	idMat3 axis = itemAngle.ToMat3() * viewAxis;
	carryableEnt->SetAxis(axis);

	//Do the logic of where to float the item.	We keep it a certain amount of units away from player body.
	viewAngles.ToVectors(&forward, &right, &up);


	//the desired position.
	carryOffset = GetCarryableOffset();
	carrytargetPosition = firstPersonViewOrigin + (forward * carryOffset.x) + (right * carryOffset.y) + (up * carryOffset.z);

	//Check if the item inspection mode is on.
	if (weapon.IsValid())
	{
		idVec3 inspectPos = carryableEnt->spawnArgs.GetVector("inspect_offset");

		if (g_inspectDebug.GetString()[0] != '\0')
		{
			//debug test an inspection XYZ. try to parse the value.
			idStr xyz = g_inspectDebug.GetString();
			idStrList xyzList = xyz.Split(' ', true);
			
			if (xyzList.Num() >= 3)
			{				
				float x = atof(xyzList[0]);
				float y = atof(xyzList[1]);
				float z = atof(xyzList[2]);
				inspectPos = idVec3(x, y, z);
				inspectLerpState = INSP_LERPON;				
			}
		}

		if (inspectPos != vec3_zero)
		{
			if (inspectLerpState == INSP_NONE)
			{
				if (iteminspectActive)
				{
					inspectLerpState = INSP_LERPON;
					inspectLerpTimer = gameLocal.time + INSPECTION_LERPTIME;
				}
			}
			else if (inspectLerpState == INSP_LERPON || inspectLerpState == INSP_INSPECTING)
			{
				if (!iteminspectActive)
				{
					inspectLerpState = INSP_LERPOFF;
					inspectLerpTimer = gameLocal.time + INSPECTION_LERPTIME;
				}
			}
			else if (inspectLerpState == INSP_LERPOFF)
			{
				if (gameLocal.time >= inspectLerpTimer)
				{
					inspectLerpState = INSP_NONE;
				}
			}

			if (inspectLerpState == INSP_LERPON || inspectLerpState == INSP_INSPECTING || inspectLerpState == INSP_LERPOFF)
			{
				//inspecting a held item.
				float lerp = (inspectLerpTimer - gameLocal.time) / (float)INSPECTION_LERPTIME;
				lerp = (inspectLerpState == INSP_LERPON) ? idMath::ClampFloat(0, 1, 1.0f - lerp) : idMath::ClampFloat(0, 1, lerp);				

				if (inspectLerpState == INSP_INSPECTING)
					lerp = 1;

				inspectPos = firstPersonViewOrigin + (forward * inspectPos.x) + (right * inspectPos.y) + (up * inspectPos.z);
				idVec3 lerpedInspectionPosition;
				lerpedInspectionPosition.Lerp(carrytargetPosition, inspectPos, lerp);

				carrytargetPosition = lerpedInspectionPosition;
			}
		}
	}

	
	//Bash animation.
	if (carryableBashActive)
	{
		float lerp = Min(1.0f, 1.0f - ((carryableBashTimer - gameLocal.time) / (float)CARRYABLE_MELEE_ANIMATIONTIME));
		lerp = idMath::CubicEaseOut(lerp);
		
		idVec3 bashTargetPosition = firstPersonViewOrigin + (forward * 24);
		bashTargetPosition.Lerp(carrytargetPosition, bashTargetPosition, 0.3f); //Find where the bash apex position is.

		carrytargetPosition.Lerp(bashTargetPosition, carrytargetPosition, lerp); //Lerp it to do the bash animation.
	}

	//If hit wall/geometry, then move item back toward player center.
	//gameLocal.clip.TraceBounds(carryTr, carrystartPosition, carrytargetPosition, carryableItem.GetEntity()->GetPhysics()->GetBounds(), MASK_SOLID, this);
	//carryableItem.GetEntity()->SetOrigin(carryTr.endpos);


	if (IsLeaning() || physicsObj.GetAcroType() != ACROTYPE_NONE)
	{
		//player is doing an action that should lower the weapon. make the item move downward out of view, so that the item doesn't look active/useable. (players can't use items during lean state).

		if (lastLeanState <= 0)
		{
			lastLeanState = 1;
			leanCarryableTimer = gameLocal.time + LEAN_CARRYABLE_HIDETIME;
			StartSound("snd_carryable_lean", SND_CHANNEL_BODY);
		}

		float hideDistance = 0;
		if (leanCarryableTimer > gameLocal.time)
		{
			//do the lerp animation.
			float lerp = (leanCarryableTimer - gameLocal.time) / (float)LEAN_CARRYABLE_HIDETIME;
			lerp = idMath::ClampFloat(0, 1, 1.0f - lerp);
			hideDistance = idMath::Lerp(0, LEAN_CARRYABLE_DISTANCE, lerp);
		}
		else
		{
			hideDistance = LEAN_CARRYABLE_DISTANCE; //fully hide it.
		}

		carrytargetPosition += up * hideDistance;
	}
	else
	{
		if (lastLeanState >= 1)
		{
			//Lean has ended.
			lastLeanState = 0;
		}
	}

	if (armstatsActive)
	{
		carrytargetPosition += up * LEAN_CARRYABLE_DISTANCE; //hide carryable if player is in armstats mode.
	}

	carryableEnt->SetOrigin(carrytargetPosition);
	carryableEnt->GetPhysics()->PutToRest();

	idVec3 diff = GetPhysics()->GetOrigin() - carryableEnt->GetPhysics()->GetOrigin();
	if ( diff.Length() > 100.0f )
	{
		common->Warning( "Player's carrying an item but it's far away from the player!" );
	}

	// If the carryable has team members bound to it, need to manually evaluate their positions also
	idEntity* next = nullptr;
	for ( idEntity* ent = carryableEnt->GetNextTeamEntity(); ent != NULL; ent = next ) {
		next = ent->GetNextTeamEntity();
		ent->GetPhysics()->Evaluate( 0.0f, 0.0f );
		ent->UpdateVisuals();
	}
}

idVec3 idPlayer::GetCarryableOffset()
{
	//Default positions for carry position. These are tweaked in .def files via the 'carryoffset' keyvalue.
	const float DEFAULT_CARRYFORWARD = 19.0f;
	const float DEFAULT_CARRYRIGHT = 7.0f;
	const float DEFAULT_CARRYUP = -8.0f;
	idVec3 carryOffset = carryableItem.GetEntity()->spawnArgs.GetVector( "carryoffset", "0 0 0" ); //Forward, Right, Up

	if (g_carryDebug.GetString()[0] != '\0')
	{
		//debug test an inspection XYZ. try to parse the value.
		idStr xyz = g_carryDebug.GetString();
		idStrList xyzList = xyz.Split(' ', true);

		if (xyzList.Num() >= 3)
		{
			float x = atof(xyzList[0]);
			float y = atof(xyzList[1]);
			float z = atof(xyzList[2]);

			carryOffset = idVec3(x, y, z);
		}
	}

	carryOffset.x += DEFAULT_CARRYFORWARD;
	carryOffset.y += DEFAULT_CARRYRIGHT;
	carryOffset.z += DEFAULT_CARRYUP;
	
	return carryOffset;
}


//Player frobbed a carryable item that was in the world. Return TRUE if item was successfully acquired.
bool idPlayer::PlayerFrobbedCarryable(idEntity *itemEnt)
{
	const char *itemWeaponName = itemEnt->spawnArgs.GetString("weapon");
	if (itemWeaponName[0] == '\0')
	{
		gameLocal.Warning("carryable '%s' is missing weapon definition.\n", itemEnt->GetName());
		return false;
	}

	//Determine whether the player's current hotbar slot is empty or filled. This determines whether we immediately arm the carryable or not.
	bool currenthobarslotIsEmpty = false;
	int currentHotbarslotIndex = inventory.GetHotbarSelection();
	if (currentHotbarslotIndex >= 0)
	{
		currenthobarslotIsEmpty = inventory.hotbarSlots[currentHotbarslotIndex].weaponType <= 0;
	}


	//Attempt to give it to the player.
	int isEmptyHotbarslotAvailable = inventory.GetEmptyHotbarSlot(); //We need to check how many slots are available BEFORE the slot gets filled, so we know whether the hotbar had availability or whether the hotbar was already full before the player frobbed the item.
	bool hasGiven = Give("weapon", itemWeaponName, itemEnt->health, itemEnt->displayName.c_str(), itemEnt);
	if (hasGiven)
	{
		//Successfully given to player.

		// SW 6th Feb 2025: wake up physics on moveable objects the item is near
		// so we don't end up with 'hovering' stacks of items
		if (itemEnt->IsType(idMoveableItem::Type))
		{
			static_cast<idMoveableItem*>(itemEnt)->WakeNearbyMoveablePhysics();
		}

		// Check if this is bound to another idActor, meaning we're taking it from someone else
		idEntity* owner = itemEnt->GetBindMaster();
		if ( owner && owner->IsType( idActor::Type ))
		{
			static_cast< idActor* >( owner )->PlayerTookCarryable( itemEnt );
		}

		//Get the weapon index number of the carryable item.
		int weaponIndex = inventory.GetWeaponIndex(this, itemWeaponName);

		//Check if this weapon is in the player inventory.
		int hotbarCurrentItem = inventory.hotbarSlots[inventory.GetHotbarSelection()].weaponType;
		if (currenthobarslotIsEmpty || (inventory.GetEmptyHotbarSlot() < 0 && hotbarCurrentItem == weaponIndex && isEmptyHotbarslotAvailable < 0)) //if the current slot is empty OR all slots are filled up, then equip immediately.
		{
			//Equip it immediately.
			SetCarryable(itemEnt, true);
		}
		else
		{
			//Jam it into player pocket for later use. Just make the item disappear from the world.
			itemEnt->Hide();
		}

		//item was just picked up. Let the item know.
		if (itemEnt->IsType(idMoveableItem::Type))
		{
			static_cast<idMoveableItem *>(itemEnt)->JustPickedUp();
		}

		return true;
	}
	
	//Player probably already has this item, exit here.
	return false;
}



//If player uses last bit of ammo for weapon, check whether we need to drop the weapon or not. This gets called at the end of every player attack.
void idPlayer::weaponDropCheck()
{
	int ammoavailable;

	if (!weapon.IsValid())
		return;

	
	ammoavailable = weapon.GetEntity()->AmmoAvailable();
	int equippedSlot = inventory.GetHotbarSelection();
	if (!carryableItem.IsValid() && ammoavailable <= 0 && !spawnArgs.GetBool(va("weapon%d_allowempty", inventory.hotbarSlots[equippedSlot].weaponType)) && (weapon.GetEntity()->AmmoRequired() > 0))
	{
		//Update the hotbar. Clear out the slot.
		
		inventory.Drop( equippedSlot );
		SetHotbarSlot(equippedSlot, 0, "", 0, NULL); //set unarmed.
	}
}



bool idPlayer::DoCryoSpawnLogic()
{
	if (!gameLocal.world->spawnArgs.GetBool("cryospawn", "1") || !g_cryospawn.GetBool())
	{
		if (!gameLocal.world->spawnArgs.GetBool("cryospawn", "1"))
			gameLocal.Warning("DoCryoSpawnLogic() bypassed due to worldspawn cryospawn=0");

		if (!g_cryospawn.GetBool())
			gameLocal.Warning("DoCryoSpawnLogic() bypassed due to cvar g_cryospawn=0");

		return false;
	}

	//Attempt to do a cryospawn.
	int cryoInteriorEntNum = -1;
	idList<int> cryospawnCandidates;

	//First, try to find the cryoInterior entity.
	for (int i = 0; i < gameLocal.num_entities; i++)
	{
		if (!gameLocal.entities[i])
			continue;

		if (gameLocal.entities[i]->IsType(idCryointerior::Type))
		{
			cryoInteriorEntNum = i;
		}

		if (gameLocal.entities[i]->IsType(idCryospawn::Type))
		{
			cryospawnCandidates.Append(i);
		}
	}

	if (cryoInteriorEntNum < 0 || cryospawnCandidates.Num() <= 0)
	{
		//Bad cryospawn setup.		
		common->Printf("No cryospawn entities found.\n");
		return false;
	}

	if (cryospawnCandidates.Num() > 1)
	{
		//Ok, we have multiple cryospawn exit entities. We randomly pick one, and delete all the other ones.
		idRandom newRandom(time(NULL));
		int randomIndex = newRandom.RandomInt(cryospawnCandidates.Num());
		for (int i = 0; i < cryospawnCandidates.Num(); i++)
		{
			if (i == randomIndex) //Are you the chosen one? If so, skip it.
				continue;

			//Not the chosen one.... Delete it.
			int entNum = cryospawnCandidates[i];
			gameLocal.entities[entNum]->PostEventMS(&EV_Remove, 0);
		}

		//Make the interior face same yaw as the exit. This is to make the player's compass behave consistently inside the cryo interior.
		int cryoExitYaw = gameLocal.entities[cryospawnCandidates[randomIndex]]->GetPhysics()->GetAxis().ToAngles().yaw ;
		idAngles interiorNewAngle = idAngles(0, cryoExitYaw, 0);
		gameLocal.entities[cryoInteriorEntNum]->SetAngles(interiorNewAngle);
		gameLocal.entities[cryoInteriorEntNum]->UpdateVisuals();

		//Assign the cryo-exit to the cryo-interior.
		static_cast<idCryointerior *>(gameLocal.entities[cryoInteriorEntNum])->SetExitPoint( gameLocal.entities[cryospawnCandidates[randomIndex]]);
		cryoexitEntNum = cryospawnCandidates[randomIndex];
	}
	else
	{	
		//There's only one candidate.

		//Make the interior face same yaw as the exit. This is to make the player's compass behave consistently inside the cryo interior.
		int cryoExitYaw = gameLocal.entities[cryospawnCandidates[0]]->GetPhysics()->GetAxis().ToAngles().yaw ;
		idAngles interiorNewAngle = idAngles(0, cryoExitYaw, 0);
		gameLocal.entities[cryoInteriorEntNum]->SetAngles(interiorNewAngle);
		gameLocal.entities[cryoInteriorEntNum]->UpdateVisuals();
		
		static_cast<idCryointerior *>(gameLocal.entities[cryoInteriorEntNum])->SetExitPoint( gameLocal.entities[cryospawnCandidates[0]]);		
		cryoexitEntNum = gameLocal.entities[cryospawnCandidates[0]]->entityNumber;
	}

	
	

	//Spawn the player in the cryo interior.
	idVec3 spawnOrigin;
	idAngles spawnAngles;
	idVec3 forward;
	gameLocal.entities[cryoInteriorEntNum]->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, NULL, NULL); //move player backwards a bit, so the player has more context of the space
	spawnOrigin = gameLocal.entities[cryoInteriorEntNum]->GetPhysics()->GetOrigin() + idVec3(0, 0, 2) + (forward * -7); //Raise it up a bit so that the player's feet don't spawn inside the model's floor surface.
	spawnAngles = gameLocal.entities[cryoInteriorEntNum]->GetPhysics()->GetAxis().ToAngles();
	SpawnToPoint(spawnOrigin, spawnAngles);

	return true;
}

void idPlayer::Event_SetDropAmmoMsg(int value)
{
	//Player has ejected live rounds during a reload/rack. Do hud message.

	if (weapon.GetEntity() == NULL)
		return;

	const char *ammoName = inventory.AmmoPickupNameForIndex(weapon.GetEntity()->GetAmmoType());

	hud->SetStateString("centermessage", va("Dropped %d %s", value, ammoName));
	hud->HandleNamedEvent("droppedAmmo");
}

void idPlayer::AssignHotbarSlot(const char *weaponName, const char *displayname, int health, bool autoSwitch, idEntity *ent)
{
	//What is the weapon index of new weapon.
	int itemWeaponIndex = inventory.GetWeaponIndex(this, weaponName);
	const idDeclEntityDef *weaponDecl = gameLocal.FindEntityDef( weaponName, false );

	//Check if this item index is already in a hotbar slot.
	int alreadyEquippedSlot = inventory.GetHotbarslotViaWeaponIndex(itemWeaponIndex);
	if ( alreadyEquippedSlot >= 0 && !weaponDecl->dict.GetBool( "multiCarry" ) )
	{
		//Player already has this item in a slot. Do nothing.
	}
	else
	{
		//This item is NOT in hotbar.

		//First: we see if the player's currently-selected hotbar slot is empty.
		int freeSlotIndex = -1;

		if (inventory.GetHotbarSelection() >= 0 && inventory.GetHotbarSelection() <= inventory.hotbarUnlockedSlots - 1)
		{
			if (inventory.hotbarSlots[inventory.GetHotbarSelection()].weaponType <= 0)
			{
				//Slot is empty. So, place the weapon here.
				freeSlotIndex = inventory.GetHotbarSelection();
			}
		}

		if (freeSlotIndex < 0)
			freeSlotIndex = inventory.GetEmptyHotbarSlot(); //Ok, now we fall back to finding ANY free slot in our hotbar.

		if (freeSlotIndex >= 0)
		{
			//Great, there was an available/empty slot. Put the item into the slot.
			this->SetHotbarSlot(freeSlotIndex, itemWeaponIndex, displayname, health, ent); //Assign weapon to slot.
			if ( autoSwitch ) {
				idealWeaponSlot = freeSlotIndex;
				currentWeaponSlot = -1;
			}
		}
		else
		{
			//There are NO free hotbar slots.
			//Swap it out with what player's currently active slot.

			int equippedSlot = inventory.GetHotbarSelection(); //Get the slot that the player CURRENTLY has equipped.

			if (equippedSlot >= 0 && equippedSlot <= inventory.hotbarUnlockedSlots - 1)
			{
				idealWeaponSlot = equippedSlot;

				SwapDropWeapon(equippedSlot, weaponName, ent); //Drop current weapon.

				this->SetHotbarSlot(equippedSlot, itemWeaponIndex, displayname, health, ent);
				currentWeaponSlot = -1;
				SelectWeapon( equippedSlot, itemWeaponIndex, false );
			}
		}
	}
}

int	idPlayer::GetCurrentWeaponType()
{
	return currentWeaponSlot >= 0 ? inventory.hotbarSlots[currentWeaponSlot].weaponType : -1;
}

// SW: This is where we actually process the latest light interaction info from the renderer, and adjust our known luminance level accordingly.
void idPlayer::UpdateTrackedInteractions(renderEntity_s* renderEnt, idList<trackedInteraction_t>* interactions)
{
	idPlayer* player = gameLocal.GetLocalPlayer();

	if (g_luminance_enabled.GetBool() && !player->isInVignette)
	{		
		player->trackedInteractions = interactions;

		// Clamp rate of updates since this stuff is pretty trace-heavy
		if (gameLocal.time - player->GetLastLuminanceUpdate() > g_luminance_updateRate.GetInteger())
		{
			// TODO: Evaluate light shaders (for flickering, sirens, etc)

			float occlusionModifier = 0.0f;
			trace_t traceResult;
			float totalLuminance = 0.0f;
			idBounds bounds;
			idVec3 start;
			GLenum glError;
			bool tracePoint;

			bool centerlightCheck = false;//bc

			if (interactions->Num() > 0)
			{
				if (g_luminance_occlusionTestType.GetInteger() == 0)
				{
					// Type 0: detection is performed from the player's head, and can feature multiple levels of 'occlusion modifier'
					idEntity* playerHead = player->GetHeadEntity();
					bounds = playerHead->GetPhysics()->GetClipModel()->GetBounds();
					start = player->firstPersonViewOrigin;
					tracePoint = false;
				}
				else
				{
					// Type 1: detection is performed from the player's feet, and has no occlusion modifier
					bounds = idBounds(vec3_zero, vec3_zero);
					start = player->GetPhysics()->GetOrigin() + idVec3(0, 0, 8); // slight offset to keep us off the floor
					tracePoint = true;
				}

				for (int i = 0; i < player->trackedInteractions->Num(); i++)
				{
					trackedInteraction_t* interaction = &(player->trackedInteractions->Ptr()[i]);

					if (interaction->lightCastsShadows)
					{
						idVec3 shadowTraceVec = interaction->lightCenter * interaction->lightAxis; // Account for light rotation;
						if (interaction->lightIsParallel)
						{
							// Here's a problem: parallel lights more or less work by just offsetting the shadow origin to a ludicrously far distance away.
							// We obviously don't want to be tracing all the way out there -- the performance impact would be absolutely dire,
							// and the trace would likely trigger a 'huge translation' error.
							// Instead, we cap out the trace length at the corner-to-corner distance across the volume
							// (We also have a cap of 2048 to account for giant volumes like the exterior sunlight)

							// For a regular parallel light, our shadow direction is dictated simply by the lightCenter offset.
							// For a parallel projected light (i.e. a spotlight of constant width) it is represented by the light_target vector, which should always be pointing straight down
							if (interaction->lightIsProjected)
							{
								shadowTraceVec = idVec3(0, 0, -interaction->lightRadius.z);
							}
							else
							{
								shadowTraceVec = interaction->lightCenter;
							}
							shadowTraceVec *= interaction->lightAxis;

							// Collision model traces have a max distance that they can go without triggering the 'huge translation' warning.
							// However, point traces do not have this limitation, so we don't have to cap them.
							shadowTraceVec = shadowTraceVec.Normalized() * (tracePoint
								? interaction->lightRadius.LengthFast() * 2.0f
								: Min(interaction->lightRadius.LengthFast() * 2.0f, CM_MAX_TRACE_DIST));

							shadowTraceVec += start;
						}
						else
						{
							// For point lights, add the vector to the light's origin to get the shadow origin
							// This also works for regular projected lights, since we just add 0 to the light's origin.
							shadowTraceVec += interaction->lightOrigin;
						}

						// SW: The renderer's light interaction code does not 'know' about the state of stencil shadows -- 
						// it fills out the buffer and then just tries to draw the interactions with the stencil test active.
						// Rather than trying to pull the data out of the stencil buffer and make sense of it (very very hard, as far as I can tell), 
						// we do some traces to roughly estimate how occluded the object is.
						// If we're tracing a volume, we shrink it gradually to try and get a more accurate occlusion value.
						// If we're tracing a point, occlusion is a binary state (either we can see it, or we can't).
						for (int j = (tracePoint ? 1 : 5); j >= 0; j--)
						{
							// Try to trace to the point that shadows are being casted from
							occlusionModifier = (float)j / (tracePoint ? 1.0f : 5.0f);
							if (occlusionModifier > 0)
							{
								if (tracePoint)
								{
									gameLocal.clip.TracePoint(traceResult, start, shadowTraceVec, MASK_OPAQUE, player);
								}
								else
								{
									idBounds scaledBounds = idBounds(bounds.Min() * occlusionModifier, bounds.Max() * occlusionModifier);
									gameLocal.clip.TraceBounds(traceResult, start, shadowTraceVec, scaledBounds, MASK_OPAQUE, player);
								}

								if (traceResult.fraction == 1.0 ||
									traceResult.c.material && traceResult.c.material->GetNumStages() && (
										traceResult.c.material->GetStage(0)->texture.texgen == TG_WOBBLESKY_CUBE || // If we traced all the way to something that looks like a skybox, just assume we're in the right place
										traceResult.c.material->GetStage(0)->texture.texgen == TG_SKYBOX_CUBE))
								{
									// The light is visible for the given scaled bounds, break out with the current occlusion modifier
									// (after potentially drawing debug stuff)
									if (developer.GetInteger() > 0)
									{
										gameRenderWorld->DebugLine(idVec4(0, 1, 0, 1), start, traceResult.endpos, 1000);
									}

									// Break out here. Now that we know there's an unobstructed path to the light,
									// we can look at other factors like falloff and colouration.
									break;
								}
								else
								{
									if (developer.GetInteger() > 0)
									{
										gameRenderWorld->DebugLine(idVec4(1, 0, 0, 1), start, traceResult.endpos, 1000);
									}
								}
							}
						}
					}
					else
					{
						// Shadowless lights cannot be occluded, set the value to 'fully visible'
						occlusionModifier = 1.0f;
					}

					// Only bother with lights that are not fully occluded. An occlusion modifier of 0 essentially means 'we shrunk the bounding box down to zero and we still couldn't reach it'
					if (occlusionModifier > 0.0f)
					{
						// SW: Figure out where we are relative to the light, and what the light projection should look like at that point.
						// I'm not a huge fan of sampling a single point rather than an area, but it's the best solution that won't take 10x as much effort.
						// 
						// A point light's attenuation is essentially controlled by the light material in the X and Y axes, and the light *FALLOFF* material in the Z axis.
						idVec3 toOrigin = start - interaction->lightOrigin;

						// Rotate the vector to account for the light's own rotation, if applicable
						toOrigin *= interaction->lightAxis;

						idVec3 sampleVector3D;
						if (interaction->lightShader->ShouldSampleFromCentre())
						{
							// SW: Special case for guard spotlights: always sample the light source as if we are in the middle of it.
							// Because the light beam is relatively narrow and horizontal-facing, it doesn't work quite as nicely when sampling the light source from our feet.
							sampleVector3D = idVec3(0, 0, 0);							

							centerlightCheck = true;
						}
						else
						{
							if (interaction->lightIsProjected)
							{
								// Spotlight:
								if (!interaction->lightIsParallel)
								{
									// Spotlights are a little trickier to figure out our location in the volume. 
									// We shrink the light's perceived right/up vectors (stored in lightRadius.x and lightRadius.y respectively)
									// according to our perpendicular distance from the origin,
									// since the light's 'width' and 'height' shrink linearly as we move from the base to the origin.
									float zRatio = toOrigin.z / interaction->lightRadius.z;
									sampleVector3D = idVec3(
										idMath::ClampFloat(-1.0f, 1.0f, toOrigin.x / (interaction->lightRadius.x * zRatio)),
										idMath::ClampFloat(-1.0f, 1.0f, toOrigin.y / (interaction->lightRadius.y * zRatio)),
										idMath::ClampFloat(0.0f, 1.0f, zRatio)
									);
								}
								else
								{
									// Lights can be parallel and projected. This results in a spotlight that is as wide at its origin as it is at its base.
									// We treat it more or less the same as above, without shrinking along the up/right vectors
									sampleVector3D = idVec3(
										idMath::ClampFloat(-1.0f, 1.0f, toOrigin.x / interaction->lightRadius.x),
										idMath::ClampFloat(-1.0f, 1.0f, toOrigin.y / interaction->lightRadius.y),
										idMath::ClampFloat(0.0f, 1.0f, toOrigin.z / interaction->lightRadius.z)
									);
								}
							}
							else
							{
								// Point/parallel light:
								// Get a vector where each component ranges from -1.0 to 1.0 based on the object's location inside the light radius 
								// (clamp it just to be safe, since we'll be using this to address the raw bytes in the light textures)
								sampleVector3D = idVec3(
									idMath::ClampFloat(-1.0f, 1.0f, toOrigin.x / interaction->lightRadius.x),
									idMath::ClampFloat(-1.0f, 1.0f, toOrigin.y / interaction->lightRadius.y),
									idMath::ClampFloat(-1.0f, 1.0f, toOrigin.z / interaction->lightRadius.z)
								);
							}
						}



						idImage* lightImage = interaction->lightShader->GetStage(0)->texture.image;

						if (lightImage->uploadWidth <= 0 || lightImage->uploadHeight <= 0)
						{
							gameLocal.Warning("idPlayer::UpdateTrackedInteractions: one or more dimensions of image %s were <= 0. Skipping...\n", lightImage->imgName.c_str());
							continue;
						}

						// load the bytes into an array.


						byte* imgPixels;
						if (g_useBlendoImageCache.GetBool())
						{
							imgPixels = lightImage->GetImageCache(false);
						}
						else
						{
							imgPixels = new byte[lightImage->uploadWidth * lightImage->uploadHeight * 4];
							glError = renderSystem->GetImageBytes(lightImage, &imgPixels);

							if (glError != GL_NO_ERROR)
							{
								gameLocal.Warning("idPlayer::UpdateTrackedInteractions: encountered GL error code %i while getting bytes on image %s. Skipping...\n", (int)glError, lightImage->imgName.c_str());
								continue;
							}
						}

						// Convert our 3D vector into a 2D vector in the texture's dimensions, for sampling the light texture
						idVec2 sampleVector2D = idVec2(
							(sampleVector3D.x + 1.0f) / 2.0f * (lightImage->uploadWidth - 1),
							(sampleVector3D.y + 1.0f) / 2.0f * (lightImage->uploadHeight - 1)
						);

						// Actually sample the light texture
						byte* pixelStart = &imgPixels[((int)(sampleVector2D.x) + lightImage->uploadWidth * (int)(sampleVector2D.y)) * 4];
						byte sample2DPixel[] = { pixelStart[0], pixelStart[1], pixelStart[2] };


						if (!g_useBlendoImageCache.GetBool())
						{
							delete[] imgPixels;
						}

						// Now we do something similar for the light falloff. 
						idImage* falloffImage = interaction->lightFalloff;
						float falloffMultiplier;

						if (falloffImage->imgName == "_noFalloff")
						{
							// Special case -- don't try to sample it just fullbright it
							falloffMultiplier = 1.0f;
						}
						else
						{
							if (falloffImage->uploadWidth <= 0 || falloffImage->uploadHeight <= 0)
							{
								gameLocal.Warning("idPlayer::UpdateTrackedInteractions: one or more dimensions of image %s were <= 0. Skipping...\n", falloffImage->imgName.c_str());
								continue;
							}
							byte* falloffPixels;
							if (g_useBlendoImageCache.GetBool())
							{
								falloffPixels = falloffImage->GetImageCache(false);
							}
							else
							{
								// Load the falloff image bytes
								falloffPixels = new byte[falloffImage->uploadWidth * falloffImage->uploadHeight * 4];
								glError = renderSystem->GetImageBytes(falloffImage, &falloffPixels);
								if (glError != GL_NO_ERROR)
								{
									gameLocal.Warning("idPlayer::UpdateTrackedInteractions: encountered GL error code %i while getting bytes on image %s. Skipping...\n", (int)glError, lightImage->imgName.c_str());
									continue;
								}
							}

							int sampleZ = (int)((sampleVector3D.z + 1.0f) / 2.0f * (falloffImage->uploadWidth - 1));

							// Sample the falloff image (we don't care about the Y axis, so we just sample the first row -- have a look at a falloff image, you'll see what I mean)
							pixelStart = &falloffPixels[sampleZ * 4];
							byte sampleZPixel[] = { pixelStart[0], pixelStart[1], pixelStart[2] };

							if (!g_useBlendoImageCache.GetBool())
							{
								delete[] falloffPixels;
							}

							// We've sampled the light texture and the falloff texture. To correctly get the lighting level at our location, we need to combine them.
							// If we put the falloff value in the range 0.0 to 1.0 instead of 0 to 255, we can just multiply the light texture values by it.
							falloffMultiplier = (float)(sampleZPixel[0]) / 255.0f;
						}

						// Now we can combine them together, and also factor in the light's colour values!
						float lightAtLocation[] = {
							(float)(sample2DPixel[0]) * falloffMultiplier * interaction->colour[0],
							(float)(sample2DPixel[1]) * falloffMultiplier * interaction->colour[1],
							(float)(sample2DPixel[2]) * falloffMultiplier * interaction->colour[2]
						};

						// SW: We need to convert our light values to grayscale (we only care about 'raw' illumination),
						// but the method by which we convert to grayscale is actually not as simple as averaging the channels.
						float luminance;
						if (g_luminance_greyscaleConversion.GetInteger() == 0)
						{
							// The below conversion is 'perceptual luminance-preserving', 
							// meaning that it roughly mirrors how human eyes perceive certain colours to be brighter than others.
							luminance = (float)lightAtLocation[0] * 0.2126 + (float)lightAtLocation[1] * 0.7152 + (float)lightAtLocation[2] * 0.0722;
						}
						else
						{
							// A less 'human' method, wherein each channel is equally weighted. Most graphics/image applications will not do this.
							luminance = (float)lightAtLocation[0] * 0.3333333 + (float)lightAtLocation[1] * 0.3333333 + (float)lightAtLocation[2] * 0.3333333;
						}

						// Multiply this luminance by the occlusion modifier, to roughly account for being partially obscured from the light
						luminance *= occlusionModifier;

						// Finally, add it to our cumulative luminance level. Multiple lights falling on the player will combine to create a larger overall luminance.
						totalLuminance += luminance;

						if (totalLuminance > 255.0f)
						{
							// We're saturated -- we literally couldn't be any brighter. Stop checking lights.
							totalLuminance = 255.0f;
							break;
						}
					}
				}
			}

			player->playerTouchedByCenterLight = centerlightCheck;

			player->SetLastLuminanceUpdate(gameLocal.time);
			//player->SetLuminance(totalLuminance / 255.0f);

			#define MAX_LUMINENCE 64.0f
			player->SetLuminance(Min(totalLuminance, MAX_LUMINENCE) / MAX_LUMINENCE); //BC Clamp luminance to the first half of values. Because at luminance MAX_LUMINENCE, the player is already very brightly-lit.
																   //SW: Experimenting with clamping this further to the lower quarter of values -- I think it makes for a better range when designing for stealth
		}
	}
	else
	{
		idPlayer* player = gameLocal.GetLocalPlayer();
		player->SetLuminance(1);
	}
}

void idPlayer::SetLastLuminanceUpdate(int gameTime)
{
	if (gameTime < gameLocal.time)
	{
		gameLocal.Warning("idPlayer::SetLastLuminanceUpdate: Supplied game time value was in the past");
	}
	lastLuminanceUpdate = gameTime;
}

int idPlayer::GetLastLuminanceUpdate(void)
{
	return lastLuminanceUpdate;
}



void idPlayer::SetLuminance(float lum)
{
	//bool isInAcro = physicsObj.GetClamberState() == CLAMBERSTATE_ACRO;
	bool isInAcro = (physicsObj.GetAcroType() != ACROTYPE_NONE);	
	if (isInAcro)
	{
		//If player is in acro, then just make the light be zero.
		lum = 0;
	}

	if (lum > 1.0f) { lum = 1.0f; }
	else if (lum < 0.0f) { lum = 0.0f; }
	luminance = lum;

	//BC Send info to the gui.	
	float guiValue;
	if (lum <= .5f)
	{
		//handle meter left hemisphere.
		float adjustedLerp = lum * 2.0f;
		if (adjustedLerp < 0)
			adjustedLerp = 0;
		else if (adjustedLerp > 1.0f)
			adjustedLerp = 1.0f;

		guiValue = idMath::Lerp(0.37f, 0, adjustedLerp);
	}
	else
	{
		//handle right hemisphere of lightmeter.
		float adjustedLerp = lum - .5f;
		adjustedLerp *= 2.0f;

		if (adjustedLerp < 0)
			adjustedLerp = 0;
		else if (adjustedLerp > 1.0f)
			adjustedLerp = 1.0f;

		guiValue = idMath::Lerp(0, -0.37f, adjustedLerp);
	}

	//TODO: Make this lerp nicely.
	hud->SetStateFloat("lightvalue", guiValue);
	
	//Crosshair gui for light value.
	if (1)
	{
		//float crosshairLuminance = Max(0, lum - LIGHTMETER_DARKTHRESHOLD);
		//crosshairLuminance = crosshairLuminance / (float)(1.0f - LIGHTMETER_DARKTHRESHOLD);
		//crosshairLuminance = idMath::Lerp(.5f, 1, crosshairLuminance); //Clamp it because the UI looks weird when resized to really small values.
		//cursor->SetStateFloat("lighthairvalue", crosshairLuminance);

		float crosshairLuminance = Max(0.0f, lum - LIGHTMETER_DARKTHRESHOLD);
		crosshairLuminance = crosshairLuminance / (float)(1.0f - LIGHTMETER_DARKTHRESHOLD);
		hud->SetStateFloat("lighthairvalue", crosshairLuminance);
	}

	//Crosshair gui for darkness value.
	if (1)
	{
		float crosshairLuminance = Min(LIGHTMETER_DARKTHRESHOLD, lum);
		crosshairLuminance = crosshairLuminance / (float)(LIGHTMETER_DARKTHRESHOLD);
		crosshairLuminance = idMath::Lerp(0, 1, crosshairLuminance);
		//cursor->SetStateFloat("darkhairvalue", crosshairLuminance);

		hud->SetStateFloat("darkhairvalue", crosshairLuminance);
	}
	


	if (lum <= LIGHTMETER_DARKTHRESHOLD)
	{
		cursor->SetStateBool("lightvisible", false);
		cursor->SetStateBool("darkvisible", true);
		//hud->SetStateBool("darkvisible", true); //4/19/2023 hide the stealth meter stuff
		contextMenu->SetStateBool("darkvisible", true);
		

		luminanceState = 0;
	}
	else if (lum > LIGHTMETER_DARKTHRESHOLD)
	{		
		cursor->SetStateBool("lightvisible", true);
		cursor->SetStateBool("darkvisible", false);
		//hud->SetStateBool("darkvisible", false); //4/19/2023 hide the stealth meter stuff
		contextMenu->SetStateBool("darkvisible", false);

		luminanceState = 1;
	}


	if (lastLuminanceState != luminanceState)
	{
		lastLuminanceState = luminanceState;

		if (luminanceState <= 0)
		{
			//Player has entered conceal state.
			//cursor->HandleNamedEvent("onEnterConceal");
			hud->HandleNamedEvent("onEnterStealth");
		}
		else
		{
			//Player has entered light state.
			//cursor->HandleNamedEvent("onEnterLit");
			hud->HandleNamedEvent("onEnterVisible");
		}
	}


	int hiddenStatus = GetHiddenStatus();
	hud->SetStateInt("darkvisible", hiddenStatus);
	contextMenu->SetStateInt("darkvisible", hiddenStatus);
	
}

//LIGHTMETER_NONE = normal seen status.
//LIGHTMETER_UNSEEN = special unseen status, cannot be seen by enemy.
int idPlayer::GetHiddenStatus()
{
	

	//Hide trigger.
	if (inConfinedState /*&& confinedType == CONF_HIDETRIGGER*/ && !playerTouchedByCenterLight)
	{
		if (luminance < 1)
			return LIGHTMETER_UNSEEN;
	}

	//Cargo hide.
	if ((physicsObj.GetAcroType() == ACROTYPE_CARGOHIDE) && (physicsObj.GetClamberState() == CLAMBERSTATE_ACRO))
	{
		if (wasCaughtEnteringCargoHide)
			return LIGHTMETER_NONE;
		else
			return LIGHTMETER_UNSEEN;
	}

	//In luminance zero.
	if (luminance <= 0)
	{
		//If the room has its electricity OFF, then luminance zero makes player unseen.
		idLocationEntity* locationEntity = gameLocal.LocationForPoint(GetEyePosition());
		if (locationEntity)
		{
			bool isElectricityInRoomActive = IsElectricityOnInLocation(locationEntity);			
			if (!isElectricityInRoomActive)
			{
				return LIGHTMETER_UNSEEN;
			}
		}
		else
		{
			return LIGHTMETER_NONE;
		}
	}

	//In normal light.
	return LIGHTMETER_NONE;
}

bool idPlayer::IsElectricityOnInLocation(idLocationEntity* locationEnt)
{
	for (idEntity* ent = gameLocal.electricalboxEntities.Next(); ent != NULL; ent = ent->electricalboxNode.Next())
	{
		if (!ent)
			continue;
		
		idLocationEntity* electricalboxLocation = gameLocal.LocationForEntity(ent);
		if (electricalboxLocation)
		{
			if (electricalboxLocation->entityNumber == locationEnt->entityNumber && ent->IsType(idElectricalBox::Type))
			{
				return static_cast<idElectricalBox*>(ent)->IsElectricalboxAlive();
			}
		}
	}

	return true;
}


int idPlayer::GetDarknessValue()
{
	if (luminance <= LIGHTMETER_DARKTHRESHOLD)
		return 0;
	else if (luminance >= LIGHTMETER_LIGHTTHRESHOLD)
		return 2;
	
	return 1;
}

float idPlayer::GetLuminance(void)
{
	return luminance;
}


void idPlayer::UpdateZoomMode()
{
	if (!zoommodeActive || zoominspect_LabelmodeActive)
	{
		return;
	}

	//idVec3 targetPos;
	//idEntity* entity = FindAimAssistTarget(targetPos);
	//if (entity == NULL)
	//{
	//	return;
	//}

	//show info here...
	
	UpdateZoomInspect();

	if (zoominspectEntityPtr.IsValid())
	{
		//whether to draw LMB inspect button.
		idVec3 positionOffset = zoominspectEntityPtr.GetEntity()->spawnArgs.GetVector("zoominspect_campos");
		hud->SetStateBool("zoomlmb_draw", (positionOffset != vec3_zero));		
	}
}


//update the zoom inspection stuff. Handles what entity is currently considered to be hovered-over by the zoominspect system.
void idPlayer::UpdateZoomInspect()
{
	const idVec2 CENTER_SCREEN(320.0f, 240.0f);
	const idVec2 CENTER_THRESHOLD(50.0f, 50.0f);
	float closestDistance = 999999999;
	idEntity *zoominspectEnt = NULL;
	for (idEntity *ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	{
		if (!ent || !ent->spawnArgs.GetBool("zoominspect") || ent->IsHidden())
			continue;

		idVec3 cameraPos = firstPersonViewOrigin;
		idMat3 cameraAxis = firstPersonViewAxis;

		//check if it's in front or behind. We only care if the object is in front of player's viewangle.
		idVec3  dirToTarget, forward;
		float ViewDirDotTargetDir;
		forward = cameraAxis[0];
		forward.Normalize();
		dirToTarget = ent->GetPhysics()->GetOrigin() - cameraPos;
		dirToTarget.Normalize();
		ViewDirDotTargetDir = idMath::ClampFloat(-1.0f, 1.0f, forward * dirToTarget);
		if (ViewDirDotTargetDir < 0.0f)
		{
			continue;
		}

        //check if we're directly hitting the object.
        bool hitsModel = false;
        trace_t modelTr;
        gameLocal.clip.TracePoint(modelTr, cameraPos, cameraPos + cameraAxis[0] * 1024, MASK_OPAQUE, this);
        if (modelTr.c.entityNum == ent->entityNumber)
        {
            hitsModel = true;
        }

		if (ent->spawnArgs.GetBool("zoominspect_brush") && !hitsModel)
		{
			//if it's a brush model and we're not directly looking at the model, then skip.
			continue;
		}

        //else
        //{
        //      //todo: if bound to a person, then handle that situation.
        //    if (gameLocal.entities[modelTr.c.entityNum]->IsBound())
        //    {
        //        
        //    }
        //}

		//Check if it's in center-ish of screen or hits model.
		idVec3 entityWorldPos = GetZoominspectAdjustedPosition(ent);
		idVec2 screenPos = GetWorldToScreen(entityWorldPos);
		if ((screenPos.x > CENTER_SCREEN.x - CENTER_THRESHOLD.x && screenPos.x < CENTER_SCREEN.x + CENTER_THRESHOLD.x
			&& screenPos.y > CENTER_SCREEN.y - CENTER_THRESHOLD.y && screenPos.y < CENTER_SCREEN.y + CENTER_THRESHOLD.y) || hitsModel)
		{
			//success
		}
        else
        {
            continue;
        }


		if (hitsModel)
		{
			//Hit it directly. Just use it.
			zoominspectEnt = ent;
			break;
		}

		if (!IsZoominspectEntInLOS(ent))
			continue;
		
		idVec2 entScreenPos = GetWorldToScreen(entityWorldPos);
		float dist = (CENTER_SCREEN - entScreenPos).LengthSqr();
		if (dist < closestDistance)
		{
			closestDistance = dist;
			zoominspectEnt = ent;
		}
	}

	if (zoominspectEnt == NULL)
	{
		//second check. Use autoaim system.
		//This is primarily for objects that are very close to the player.
		float bestScore = 0;
		for (idEntity *ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
		{
			if (!ent || !ent->spawnArgs.GetBool("zoominspect") || ent->IsHidden())
				continue;

			idVec3 cameraPos = firstPersonViewOrigin;
			idMat3 cameraAxis = firstPersonViewAxis;

			//do a dotproduct check to make sure object is mostly in center-ish of screen
			#define CENTERSCREEN_DOTTHRESHOLD .85f //the higher this number, the tighter the position needs to be in screen center. .99f = very tight, 0 = object can be very far off to sides of screen
			idVec3  dirToTarget, forward;
			float ViewDirDotTargetDir;
			forward = cameraAxis[0];
			forward.Normalize();
			dirToTarget = ent->GetPhysics()->GetOrigin() - cameraPos;
			dirToTarget.Normalize();
			ViewDirDotTargetDir = idMath::ClampFloat(-1.0f, 1.0f, forward * dirToTarget);
			//common->Printf("%f\n", ViewDirDotTargetDir);
			if (ViewDirDotTargetDir < CENTERSCREEN_DOTTHRESHOLD)
			{
				continue;
			}

			if (ent->spawnArgs.GetBool("zoominspect_brush"))
			{
				//skip brush models.
				continue;
			}

			if (!IsZoominspectEntInLOS(ent))
				continue;

			//we only want objects that are pretty close to player.
			idVec3 entityWorldPos = GetZoominspectAdjustedPosition(ent);
			float dist = (entityWorldPos - firstPersonViewOrigin).Length();			
			if (dist > 64)
				continue;

			
			float computedScore = GetAutoaimScore(entityWorldPos, firstPersonViewOrigin, firstPersonViewAxis);
			if (computedScore > bestScore)
			{
				//Ensure we have LOS to the entity.
				bestScore = computedScore;
				zoominspectEnt = ent;
			}
		}
	}

	//assign ent to zoominspectEntityPtr so that the ui knows what to draw.
	//Note: this will be NULL if there is no valid zoom inspect entity.
	zoominspectEntityPtr = zoominspectEnt;

	if (zoominspectEnt == NULL)
	{
		if (zoominspect_previousEntNum != -1)
		{
			zoominspect_previousEntNum = -1;
		}
	}
	else
	{
		if (zoominspectEnt->entityNumber != zoominspect_previousEntNum)
		{
			zoominspect_previousEntNum = zoominspectEnt->entityNumber;
			StartSound("snd_guienter", SND_CHANNEL_ANY);
			hud->HandleNamedEvent("newZoomInspect");
		}
	}
}

bool idPlayer::HasWeaponInInventory(const char *weaponName, bool ignoreMultiCarry)
{
	int frobitemIndex = inventory.GetWeaponIndex(this, weaponName);
	if ( ignoreMultiCarry ) {
		const idDeclEntityDef *weaponDef = gameLocal.FindEntityDef( spawnArgs.GetString( va( "def_weapon%d", frobitemIndex ) ), false );
		if ( weaponDef->dict.GetBool( "multiCarry" ) ) {
			return false;
		}
	}
	return (inventory.GetHotbarslotViaWeaponIndex(frobitemIndex) >= 0);
}


void idPlayer::RemoveCarryableFromHotbar(int hotbarIndex)
{
	if (hotbarIndex < 0 || hotbarIndex >= inventory.hotbarUnlockedSlots)
	{
		gameLocal.Warning("RemoveCarryableFromHotbar: index is out of bounds (%d)", hotbarIndex);
		return;
	}
	
	idEntityPtr<idEntity> carryPtr = inventory.hotbarSlots[hotbarIndex].carryPtr;
	if ( carryPtr.IsValid() )
	{
		//Remove carryable item.
		if (carryableItem.IsValid())
		{
			if ( carryPtr.GetEntityNum() == carryableItem.GetEntity()->entityNumber)
			{
				carryableItem = NULL;
			}
		}

		carryPtr.GetEntity()->UpdateGravity(true);
		carryPtr.GetEntity()->Show();
		carryPtr.GetEntity()->SetDepthHack(false);
		inventory.Drop( hotbarIndex ); //Remove the carryable weapon from inventory weapon list.
	}
	else
	{
		//Remove weapon from inventory.

		int equippedSlot = inventory.GetHotbarSelection();
		if (equippedSlot >= 0)
		{
			inventory.Drop(equippedSlot);
			weapon.GetEntity()->ResetAmmoClip();
			weapon.GetEntity()->WeaponStolen();
			currentWeaponSlot = -1;
			weaponGone = true;
		}

		//int weaponIndex = inventory.GetWeaponIndex(this, weap);
		//int weaponSlot = inventory.GetHotbarslotViaWeaponIndex(weaponIndex);
		//inventory.Drop(weaponSlot);

	}

	SetHotbarSlot(hotbarIndex, 0, "", 0, NULL);

// 	if (hotbarIndex == inventory.GetHotbarSelection())
// 	{
// 		//If it's the current active hotbar slot, then make idealweapon become unarmed.
// 		idealWeaponSlot = -1;
// 	}
}

bool idPlayer::RemoveCarryableFromInventory(idEntity *ent)
{
	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		if (!inventory.hotbarSlots[i].carryPtr.IsValid())
			continue;

		if (!inventory.hotbarSlots[i].carryPtr.GetEntity())
			continue;

		if (inventory.hotbarSlots[i].carryPtr.GetEntityNum() == ent->entityNumber)
		{
			//Found the entity. Remove it from inventory.
			RemoveCarryableFromHotbar(i);
			return true;
		}
	}

	return false;
}

bool idPlayer::RemoveCarryableFromInventory(const char *weaponName)
{
	if (!HasWeaponInInventory(weaponName))
		return false; //Sanity check. If player doesn't even have this carryable, then get out of here.

	int weaponIndex = inventory.GetWeaponIndex(this, weaponName);
	if (weaponIndex < 0)
		return false;

	int equippedSlot = inventory.GetHotbarslotViaWeaponIndex(weaponIndex);
	if (equippedSlot < 0)
		return false;

	RemoveCarryableFromHotbar(equippedSlot);
	return true;
}

idEntity *idPlayer::GetCarryableFromInventory(const char *weaponName)
{
	if (!HasWeaponInInventory(weaponName))
		return NULL;

	int weaponIndex = inventory.GetWeaponIndex(this, weaponName);
	if (weaponIndex < 0)
		return NULL;

	int equippedSlot = inventory.GetHotbarSelection();
	// Prioritize the current slot as the first slot to try
	if ( inventory.hotbarSlots[equippedSlot].weaponType != weaponIndex ) {
		equippedSlot = inventory.GetHotbarslotViaWeaponIndex( weaponIndex );
	}
	if (equippedSlot < 0)
		return NULL;
	
	if (inventory.hotbarSlots[equippedSlot].carryPtr.IsValid())
	{
		return inventory.hotbarSlots[equippedSlot].carryPtr.GetEntity();
	}	

	return NULL;
}

//Returns true if player has object in inventory. Uses the CLASSNAME of item.
bool idPlayer::HasItemViaClassname(const char *itemClassname)
{
	idStr strClassname = itemClassname;
	int subIndex = strClassname.Find("*", false, 0, -1);

	for (int i = 0; i < Min(MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots); i++)
	{
		if (inventory.hotbarSlots[i].carryPtr.IsValid())
		{
			idStr hotbarclassname = inventory.hotbarSlots[i].carryPtr.GetEntity()->spawnArgs.GetString("classname");

			if (subIndex >= 0)
			{
				//Has a wildcard.
				idStr classnameChunk = strClassname.Mid(0, subIndex);

				if (idStr::Icmpn(classnameChunk, hotbarclassname, subIndex) == 0)
				{
					return true;
				}
			}
			else if (idStr::Icmp(strClassname, hotbarclassname) == 0) //No wildcard. Do normal check.
			{
				return true;
			}
		}
	}

	return false;
}

void idPlayer::Event_HasItemViaClassname(const char *itemClassname)
{
	idThread::ReturnInt(HasItemViaClassname(itemClassname) ? 1 : 0);
}

bool idPlayer::RemoveItemViaClassname(const char *itemClassname)
{
	for (int i = 0; i < Min(MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots); i++)
	{
		if (inventory.hotbarSlots[i].carryPtr.IsValid())
		{
			idStr hotbarclassname = inventory.hotbarSlots[i].carryPtr.GetEntity()->spawnArgs.GetString("classname");
			if (!idStr::Icmp(hotbarclassname, itemClassname))
			{
				//Match.		

				//Remove item.
				idEntityPtr<idEntity>	itemPtr = inventory.hotbarSlots[i].carryPtr;
				RemoveCarryableFromHotbar(i);

				if (itemPtr.IsValid())
				{
					itemPtr.GetEntity()->PostEventMS(&EV_Remove, 0);
				}

				return true;
			}
		}
	}

	return false;
}

void idPlayer::Event_RemoveItemViaClassname(const char *itemClassname)
{
	idThread::ReturnInt(RemoveItemViaClassname(itemClassname) ? 1 : 0);
}

void idPlayer::Event_RemoveItemViaEntity(idEntity *ent)
{
	for (int i = 0; i < Min(MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots); i++)
	{
		if (inventory.hotbarSlots[i].carryPtr.IsValid())
		{
			if (inventory.hotbarSlots[i].carryPtr.GetEntityNum() == ent->entityNumber)
			{
				idEntity *ent = inventory.hotbarSlots[i].carryPtr.GetEntity();
				RemoveCarryableFromHotbar(i);
				ent->Hide();
				ent->PostEventMS(&EV_Remove, 0);				

				idThread::ReturnInt(1);
				return;
			}
		}
	}

	idThread::ReturnInt(0);
}

void idPlayer::Event_GetItemViaClassname(const char *itemClassname)
{
	for (int i = 0; i < Min(MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots); i++)
	{
		if (inventory.hotbarSlots[i].carryPtr.IsValid())
		{
			idStr hotbarclassname = inventory.hotbarSlots[i].carryPtr.GetEntity()->spawnArgs.GetString("classname");
			if (!idStr::Icmp(hotbarclassname, itemClassname))
			{
				//Found match.
				idThread::ReturnEntity(inventory.hotbarSlots[i].carryPtr.GetEntity());
				return;
			}
		}
	}

	idThread::ReturnEntity(NULL);
}



void idPlayer::DropCurrentCarryableOrWeapon()
{
	int currentHotbarIndex = inventory.GetHotbarSelection();
	if (currentHotbarIndex < 0)
		return;

	if (inventory.hotbarSlots[currentHotbarIndex].carryPtr.IsValid())
	{
		//Has a carryable selected.
		DropCurrentCarryable();
		return;
	}

	//Has a weapon selected.
	DropCurrentWeapon();
}


//This gets called when player interacts with an oxygen station. Gives air; clamps at max air. Returns the amount of air left inside the machine.
int idPlayer::GiveAirtics(int airticsToGive)
{
	if (airTics >= pm_airTics.GetInteger())
	{
		//If air tank is already maxed out, then we have nothing to do. Exit here.
		return -1;
	}

	//If player was suffocating, update the audio of the player breathing.
	if (airTics <= 0 && airless && !noclip)
	{
		StopSound(SND_CHANNEL_BODY2, false); //Stop the suffocation breathing sound.	
		StartSound("snd_airtank", SND_CHANNEL_BODY2, 0, false, NULL); //Breathing noise from the airtank.		
	}

	StartSound("snd_recompress", SND_CHANNEL_ANY);

	if (airTics + airticsToGive > pm_airTics.GetInteger())
	{
		//the player will NOT deplete the oxygen station. There is some leftover oxygen in the station.
		int remainderInOxygenstation = ((airTics + airticsToGive) - pm_airTics.GetInteger());
		airTics = pm_airTics.GetInteger(); //Replenish the player's airtank to max.

		if (airTics >= pm_airTics.GetInteger())
		{
			oxygenmeterFadeTimer = gameLocal.time + OXYGENMETER_FADEDELAY; //fade out after this amount of time.
			oxygenmeterIsFaded = false;
			lastArmorPulse = gameLocal.fast.time; //make a little animation on the hud. uuuhh  we are just gonna hijack the armor pulse animation...

			oxygenFreezeTimer = gameLocal.time + OXYGENMETER_PAUSETIME;
		}

		return remainderInOxygenstation; //Return the amount remaining in the oxygen station.
	}

	airTics += airticsToGive;

	if (airTics >= pm_airTics.GetInteger())
	{
		//The player's air tank is full. Start the oxygenmeter fade-out sequence.
		oxygenmeterFadeTimer = gameLocal.time + OXYGENMETER_FADEDELAY; //fade out after this amount of time.
		oxygenmeterIsFaded = false;
		lastArmorPulse = gameLocal.fast.time; //make a little animation on the hud. uuuhh  we are just gonna hijack the armor pulse animation...

		oxygenFreezeTimer = gameLocal.time + OXYGENMETER_PAUSETIME;
	}

	return 0;
}

int idPlayer::GetAirtics()
{
	return airTics;
}

bool idPlayer::HasEntityInCarryableInventory(idEntity *ent)
{
	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		if (!inventory.hotbarSlots[i].carryPtr.IsValid())
			continue;

		if (!inventory.hotbarSlots[i].carryPtr.GetEntity())
			continue;

		if (inventory.hotbarSlots[i].carryPtr.GetEntityNum() == ent->entityNumber)
			return true;
	}

	return false;
}

idEntity* idPlayer::HasEntityInCarryableInventory_ViaInvName(idStr invName)
{
	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		if (!inventory.hotbarSlots[i].carryPtr.IsValid())
			continue;

		if (!inventory.hotbarSlots[i].carryPtr.GetEntity())
			continue;

		if (idStr::Icmp(inventory.hotbarSlots[i].carryPtr.GetEntity()->spawnArgs.GetString("inv_name"), invName.c_str()) == 0)
			return inventory.hotbarSlots[i].carryPtr.GetEntity(); //Found a match.
	}

	return NULL;
}

//how many empty inventory slots does player have right now.
int idPlayer::GetEmptyInventorySlots()
{
	//how many inventory slots are empty.
	int count = 0;
	for (int i = 0; i < Min(MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots); i++)
	{
		if (inventory.hotbarSlots[i].weaponType <= 0)
			count++;
	}

	return count;
}

int idPlayer::GetBloodbagCount()
{
	return inventory.bloodbags;
}

int idPlayer::GetMushroomCount()
{
	return inventory.mushrooms;
}

void idPlayer::AddBloodMushroom(int value, idVec3 _pos)
{
	inventory.mushrooms += value;

	if (inventory.mushrooms >= HEALTH_MUSHROOMMAXCOUNT)
	{
		inventory.mushrooms = 0;
		inventory.bloodbags++;		
		//("Bloodbag filled");
		StartSound("snd_notification", SND_CHANNEL_ANY);
	}
	else if (value > 0)
	{
		int remainingMushroomsNeeded = HEALTH_MUSHROOMMAXCOUNT - inventory.mushrooms;

		const char *txt = va("NEED %d MORE...", remainingMushroomsNeeded);
		SetFlytextEvent(_pos, txt, idDeviceContext::ALIGN_CENTER);
	}	
}

//int idPlayer::GetCatkeyCount()
//{
//	return inventory.catkeys;
//}

//void idPlayer::SetCatkeyDelta(int value)
//{
//	inventory.catkeys += value;
//
//	if (inventory.catkeys < 0)
//		inventory.catkeys = 0;
//}


//This is the small message in the center of the screen.
void idPlayer::SetCenterMessage(const char *text)
{
	hud->SetStateString("centermessage", common->GetLanguageDict()->GetString(text));
	hud->HandleNamedEvent("droppedAmmo");
	gameLocal.GetLocalPlayer()->StartSound("snd_cancel", SND_CHANNEL_ANY);
}

//This is the very large message in the center of the screen.
void idPlayer::SetFanfareMessage(const char *text)
{
	hud->SetStateString("fanfaremessage", common->GetLanguageDict()->GetString(text));
	hud->HandleNamedEvent("fanfaremessage");
}

//This is the message that appears when someone is eliminated.
void idPlayer::DoEliminationMessage(const char *enemyName, bool extendedTime)
{
	idStr eliminationStr = idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_enemyeliminated"), enemyName);
	gameLocal.AddEventLog(eliminationStr, GetPhysics()->GetOrigin());
	//gameLocal.GetLocalPlayer()->hud->SetStateString("elimination_name", eliminationStr.c_str());

	SetFanfareMessage(eliminationStr.c_str());

	//if (extendedTime)
	//{
	//	gameLocal.GetLocalPlayer()->SetHudNamedEvent("eliminationEvent");		
	//}
	//else
	//{
	//	gameLocal.GetLocalPlayer()->SetHudNamedEvent("eliminationEvent_escapepod");
	//}

	eliminationCounter++;
}



idEntity *idPlayer::IsPlayerLookingATrashchute()
{
	trace_t trashbinTr;
	gameLocal.clip.TracePoint(trashbinTr, GetEyePosition(), GetEyePosition() + viewAngles.ToForward() * 96, MASK_SHOT_RENDERMODEL, this);
	if (trashbinTr.fraction >= 1)
	{
		return NULL;
	}	

	if (trashbinTr.c.entityNum >= 0 && trashbinTr.c.entityNum <= MAX_GENTITIES - 2 && trashbinTr.c.normal.x == 0 && trashbinTr.c.normal.y == 0 && trashbinTr.c.normal.z == 1)
	{		
		if (gameLocal.entities[trashbinTr.c.entityNum]->IsType(idMover::Type) && gameLocal.entities[trashbinTr.c.entityNum]->GetPhysics()->GetClipModel()->GetOwner() != NULL)
		{
			if (gameLocal.entities[trashbinTr.c.entityNum]->GetPhysics()->GetClipModel()->GetOwner()->IsType(idTrashchute::Type))
			{
				//this is a trash chute platform.
				return gameLocal.entities[trashbinTr.c.entityNum];
			}
		}
	}
	
	return NULL;
}

void idPlayer::SetDefibAvailable(bool value)
{
	defibAvailable = value;
}

bool idPlayer::GetDefibAvailable()
{
	return defibAvailable;
}

void idPlayer::SetCamSpurt(const char *particleName)
{
	if (particleName[0] == '\0')
		return;

	//Position particle just below player eye.
	idVec3 down, right;
	viewAngles.ToVectors(NULL, &right, &down);
	idVec3 particlePos = GetEyePosition() + (down * -5) + (right * -.7f);

	//Angle it to spurt away from player.
	idAngles particleAngle = viewAngles;
	particleAngle.pitch += 60;
	
	gameLocal.DoParticle(particleName, particlePos, particleAngle.ToForward());
}

//default length of slowmo time is IMPACT_SLOWMO_TIME
void idPlayer::SetImpactSlowmo(bool value, int extraTimeToAdd)
{
	impactslowmoActive = value;
	gameLocal.SetSlowmo(value);

	if (value)
	{
		impactslowmoTimer = gameLocal.time + IMPACT_SLOWMO_TIME + extraTimeToAdd;
	}
}

idVec3 idPlayer::GetPlacerNormal()
{
	if (placerEnt == NULL)
		return vec3_zero;

	return placerEnt->GetPhysics()->GetAxis().ToAngles().ToForward();
}

int idPlayer::GetShrapnelCount()
{
	return cond_shrapnel;
}

int idPlayer::GetBulletwoundCount()
{
	return cond_bulletwound;
}

bool idPlayer::IsLeaning()
{
	return (leanState == LEANSTATE_TRANSITIONON || leanState == LEANSTATE_ACTIVE);
}

bool idPlayer::IsEntityEnemyTarget(idEntity *ent)
{
	for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	{
		if (!entity)
			continue;

		if (entity->team == this->team || ent->entityNumber != entity->entityNumber)
			continue;

		return true;
	}

	return false;
}

//textAlign values:
//idDeviceContext::ALIGN_LEFT
//idDeviceContext::ALIGN_CENTER
//idDeviceContext::ALIGN_RIGHT
void idPlayer::SetFlytextEvent(idVec3 position, const char *text, int textAlign /*= 0*/ )
{
	int i;
	for (i = 0; i < FLYTEXT_COUNT; i++)
	{
		if (flytext[i].timer < gameLocal.time)
		{
			flytext[i].timer = gameLocal.time + FLYTEXT_FLYTIME;
			flytext[i].pos = position;
			flytext[i].text = text;
			flytext[i].textAlign = textAlign;
			return;
		}
	}

	common->Warning("Unable to allocate a free flytext index. Max: %d\n", FLYTEXT_COUNT);
}

void idPlayer::Event_flytext(const idVec3 &position, const char *text)
{
	SetFlytextEvent(position, text, idDeviceContext::ALIGN_CENTER);
}

void idPlayer::UpdateFlytext()
{
	for (int i = 0; i < FLYTEXT_COUNT; i++)
	{
		if (flytext[i].timer < gameLocal.time)
			continue;

		flytext[i].pos.z += .05f; //make it float up a bit.

		#define	FADE_INTERVAL 16 //what 'percentage' of time we spend on the text lerping out of existence. It's 100 divided by value. For example, 2 = spend 50% of the time lerping out. 4 = spend 25% of time lerping out.
		#define TEXTSIZEMAX .6f
		float textsize = TEXTSIZEMAX;
		if (flytext[i].timer - gameLocal.time < (FLYTEXT_FLYTIME / 16))
		{
			//start the fadeout.
			float lerp = ((flytext[i].timer - gameLocal.time)) / (float)(FLYTEXT_FLYTIME/16);
			lerp = idMath::ClampFloat(0, 1, 1 - lerp);
			textsize = idMath::Lerp(TEXTSIZEMAX, 0, lerp);
		}

		idVec3 dirToText = flytext[i].pos - this->firstPersonViewOrigin;
		float facingResult = DotProduct(dirToText, viewAngles.ToForward());
		if (facingResult <= 0)
			continue; //If text is behind me, then exit here.

		//Render it.
		idVec2 screenPos;
		screenPos = GetWorldToScreen(flytext[i].pos); //get screen coordinates.
		hud->DrawArbitraryText(flytext[i].text, textsize, idVec4(1, 1, 1, 1), screenPos.x, screenPos.y, "sofia", idVec4(0, 0, 0, 1), flytext[i].textAlign);
	}
}

void idPlayer::SetArmStatsActive( bool value)
{
	if (!gameLocal.world->spawnArgs.GetBool("meta_infowatch", "1"))
	{
		// SW: Fail silently (we haven't introduced the infowatch yet)
		armstatsActive = false;
		return;
	}

	if (peekObject.IsValid() || mechTransitionState != MECHTRANSITION_NONE || isInVignette)
	{
		StartSound("snd_error", SND_CHANNEL_ANY);
		armstatsActive = false;
		return;
	}

	armstatsActive = value;
	if (value)
	{
		armstatsModel->Show();
		armstatsModel->Event_PlayAnim("raiseup", 1);
		armstatsState = ARMST_RAISING;
		armstatsTimer = gameLocal.time;

		//Set the default page for the wrist display.
		armstatsModel->Event_GuiNamedEvent(1, "gotoMap"); //Default to map mode.
		armstatMode = AMOD_MAP;
		hud->SetStateInt("wristmode", 0);

		//Update the gui.
		SetupSpectatorMilestones(armstatsModel->GetRenderEntity()->gui[0]);
	}
	else
	{
		armstatsState = ARMST_LOWERING;
		armstatsTimer = gameLocal.time;
		armstatsModel->Event_PlayAnim("putaway", 4);

		armstatsModel->Event_SetGui(1, "guis/armstatsmenu.gui");

		cameraspliceActive = false;
	}

	armstatsModel->StartSound("snd_rustle", SND_CHANNEL_BODY);
}


//This gets called when a camerasplice in the world is frobbed.
bool idPlayer::StartCameraSplice(idEntity *cameraEnt, bool isNewUnlock)
{
	cameraspliceActive = true;
	
	armstatsModel->Show();
	armstatsModel->Present(); //setgui gets cranky if the model is invisible. So, be sure to show() and present() before doing setgui().

	if (cameraEnt == NULL)
	{
		//Try to use the last-used camera.
		cameraEnt = GetSecurityCameraViaIndex(cameraspliceChannel);

		if (cameraEnt == NULL)
		{
			//Last-used camera is down, deleted, etc. Just use any available camera.
			cameraEnt = GetAnyAvailableCamera();
		}
	}

	int channelToSwitchTo = 0;
	if (cameraEnt != NULL)
	{
		if (cameraEnt->IsType(idSecurityCamera::Type))
		{
			//A new channel was (probably) unlocked; go to the new channel directly
			channelToSwitchTo = static_cast<idSecurityCamera *>(cameraEnt)->cameraIndex;
		}
	}

	//armstatsModel->spawnArgs.Set("cameratarget", cameraEnt == NULL ? "" : cameraEnt->name.c_str());
	armstatsModel->Event_SetGui(1, "guis/game/armcamera.gui");
	SwitchCameraSpliceChannel(channelToSwitchTo);

	SetArmStatsActive(true); //make arm raise up.

	if (isNewUnlock && cameraEnt != NULL)
	{
		idLocationEntity *locationEnt = gameLocal.LocationForEntity(cameraEnt);
		if (locationEnt)
		{
			armstatsModel->Event_SetGuiParm("cameraname", locationEnt->GetLocation());
			armstatsModel->Event_GuiNamedEvent(1, "channelfanfare");
		}
	}

	return true;
}

bool idPlayer::IsCameraSpliceActive( idEntity* cameraEnt )
{
	return cameraEnt && cameraspliceActive && cameraEnt->IsType( idSecurityCamera::Type ) && static_cast< idSecurityCamera * >( cameraEnt )->cameraIndex == cameraspliceChannel;
}

void idPlayer::SwitchCameraSpliceChannel(int index)
{
	if (gameLocal.time < nextCameraspliceChannelTime)
		return;

	nextCameraspliceChannelTime = gameLocal.time + 200; //limit how fast the player can switch channels.

	int totalCameras = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->totalSecuritycamerasAtGameStart;
	if (index >= totalCameras)
	{
		index = 0;
	}
	else if (index < 0)
	{
		index = totalCameras - 1;
	}

	cameraspliceChannel = index; //switch to new channel.
	
	armstatsModel->Event_GuiNamedEvent(1, "channelSwitch");
	armstatsModel->StartSound("snd_cameraswitch", SND_CHANNEL_ANY);	
	armstatsModel->Event_SetGuiParm("channelstring", va("%d/%d", index + 1, totalCameras));

	bool doColorBars = false;
	idEntity * activeCamera = GetSecurityCameraViaIndex(cameraspliceChannel);
	if (activeCamera == NULL)
	{
		doColorBars = true;
	}
	else if (activeCamera->IsType(idSecurityCamera::Type))
	{
		if (!static_cast<idSecurityCamera *>(activeCamera)->IsSpliced)
		{
			doColorBars = true;
		}
	}

	if (doColorBars || activeCamera == NULL)
	{
		armstatsModel->Event_SetGuiParm("roomname", "#str_loc_unknown_00104"); /*unknown*/
		armstatsModel->Event_SetGuiInt("colorbars", 1);
		// SM: If there's no valid camera target, we need to also tell the arm there's no target
		armstatsModel->cameraTarget = NULL;
		renderEntity_t* armRender = armstatsModel->GetRenderEntity();
		armRender->remoteRenderView = NULL;
		armRender->suppressSurfaceInViewID = 0;
		armRender->suppressShadowInViewID = 0;

		armstatsModel->Event_SetGuiInt("hacked", 0);
	}
	else if (activeCamera != NULL)
	{		
		idLocationEntity *locationEnt = gameLocal.LocationForEntity(activeCamera);
		armstatsModel->Event_SetGuiParm("roomname", locationEnt == NULL ? "#str_loc_unknown_00104" /*unknown*/ : locationEnt->GetLocation());

		armstatsModel->Event_SetGuiInt("colorbars", 0);
		armstatsModel->spawnArgs.Set("cameratarget", activeCamera->GetName());
		armstatsModel->Event_UpdateCameraTarget();
		// SM: Make sure we hide the arm in the active camera view (otherwise we see a floating arm)
		armstatsModel->GetRenderEntity()->suppressSurfaceInViewID = activeCamera->entityNumber + 1;
		armstatsModel->GetRenderEntity()->suppressShadowInViewID = activeCamera->entityNumber + 1;


		//Draw whether the camera is hacked or not.
		bool isHacked = activeCamera->team == TEAM_FRIENDLY;
		armstatsModel->Event_SetGuiInt("hacked", isHacked);
	}
}

idEntity * idPlayer::GetAnyAvailableCamera()
{
	for (idEntity* secCamEnt = gameLocal.securitycameraEntities.Next(); secCamEnt != NULL; secCamEnt = secCamEnt->securitycameraNode.Next())
	{
		if (secCamEnt == NULL)
			continue;

		if (!secCamEnt->IsType(idSecurityCamera::Type))
			continue;

		if (static_cast<idSecurityCamera *>(secCamEnt)->IsSpliced)
			return secCamEnt;
	}

	return NULL;
}

idEntity * idPlayer::GetSecurityCameraViaIndex(int index)
{
	for (idEntity* secCamEnt = gameLocal.securitycameraEntities.Next(); secCamEnt != NULL; secCamEnt = secCamEnt->securitycameraNode.Next())
	{
		if (secCamEnt == NULL)
			continue;

		if (!secCamEnt->IsType(idSecurityCamera::Type))
			continue;

		if (static_cast<idSecurityCamera *>(secCamEnt)->cameraIndex == index)
			return secCamEnt;
	}

	return NULL;
}



idEntity * idPlayer::GetFocusedGUI()
{
	if (focusGUIent == NULL)
		return NULL;

	return focusGUIent;
}

bool idPlayer::IsContextmenuActive()
{
	return contextMenuActive;
}

// Allows us to override blur via scripting, if need be
void idPlayer::Event_EnableBlur()
{
	scriptedBlur = true;
}

// Allows us to override blur via scripting, if need be
void idPlayer::Event_DisableBlur()
{
	scriptedBlur = false;
}

//What things make the blur turn on.
bool idPlayer::IsBlurActive()
{
	return (IsContextmenuActive() || iteminspectActive || g_blur_testEnable.GetBool() || scriptedBlur || zoominspect_LabelmodeActive || gameLocal.slowmoState == SLOWMO_STATE_ON || gameLocal.slowmoState == SLOWMO_STATE_RAMPUP);
}

bool idPlayer::IsJockeying()
{
	return (jockeyState == JCK_ATTACHED);
}

void idPlayer::ResetJockeyTimer()
{
	stamina = pm_stamina.GetFloat();
}

void idPlayer::SetJockeyMode(bool value)
{
	if (value)
	{
		//Attach.

		if (!meleeTarget.IsValid())
			return;

		//if try to jockey someone who is un-jockeyable.
		if (!meleeTarget.GetEntity()->spawnArgs.GetBool("jockeyable", "1"))
		{
			StartSound("snd_error", SND_CHANNEL_ANY); //prompt is up but cannot be jockeyed, so play error sound.
			hud->HandleNamedEvent("unjockeyFlash");
			return;
		}

		if (jockeyState != JCK_ATTACHED)
		{
			gameLocal.AddEventLog(idStr::Format(common->GetLanguageDict()->GetString("#str_def_gameplay_player_pounce"), meleeTarget.GetEntity()->displayName.c_str()), GetPhysics()->GetOrigin());
		}

		meleeTarget.GetEntity()->SetJockeyState(true);
		SetArmVisibility(true);

		//jointHandle_t pounceJoint = meleeTarget.GetEntity()->GetAnimator()->GetJointHandle("shoulders"); //Joint player attaches to.
		//if (pounceJoint == INVALID_JOINT)
		//{
		//	gameLocal.Error("SetJockeyMode: '%s' has invalid shoulders joint.", meleeTarget.GetEntity()->GetName());
		//}
		//idVec3 pounceAttachPos;
		//idMat3 pounceAttachMat;
		//meleeTarget.GetEntity()->GetJointWorldTransform(pounceJoint, gameLocal.time, pounceAttachPos, pounceAttachMat);
		//SetOrigin(idVec3(pounceAttachPos.x, pounceAttachPos.y, meleeTarget.GetEntity()->GetPhysics()->GetOrigin().z));
		//BindToJoint(meleeTarget.GetEntity(), pounceJoint, true);

		AI_JOCKEYRIDE = true;
		jockeyState = JCK_ATTACHED;
		AdjustBodyAngles();

		jockeyArrow->Show();

		//Be lenient and replenish some stamina if player has very low stamina.
		float minimumStamina = pm_stamina.GetFloat() * JOCKEY_STAMINA_FREEAMOUNT;
		if (stamina < minimumStamina)
			stamina = minimumStamina;

		jockeyTimer = gameLocal.time + JOCKEY_PIPINTERVAL;

		physicsObj.ForceUnduck(); //force player to exit duck state.

		enemiesPounced++;

		SayVO_WithIntervalDelay_msDelayed("snd_vo_pounce", 1000);
	}
	else
	{
		//Detach.
		AI_JOCKEYRIDE = false;
		jockeyState = JCK_INACTIVE;
		Unbind();
		SetArmVisibility(false);

		//Find a position to place the player.
		idVec3 dismountLocation = GetJockeyDismountLocation();
		if (dismountLocation != vec3_zero && meleeTarget.IsValid())
		{
			idVec3 directionToEnemy = meleeTarget.GetEntity()->GetPhysics()->GetOrigin() - idVec3(dismountLocation.x, dismountLocation.y, meleeTarget.GetEntity()->GetPhysics()->GetOrigin().z);
			Teleport(dismountLocation, directionToEnemy.ToAngles(), NULL);
		}

		if (meleeTarget.IsValid())
		{
			meleeTarget.GetEntity()->SetJockeyState(false);
		}

		jockeyArrow->Hide();

		hud->SetStateBool("showjockeyattackprompt", false);
	}
}

idVec3 idPlayer::GetJockeyDismountLocation()
{
	#define DISMOUNTDISTANCE 48
	idVec3 originPoint;
	if (meleeTarget.IsValid())
		originPoint = meleeTarget.GetEntity()->GetPhysics()->GetOrigin();
	else
		originPoint = GetPhysics()->GetOrigin();

	//First, try the current viewAngle. This makes for the cleanest transition and makes for smoothest experience for player.
	idVec3 viewPosition = originPoint + viewAngles.ToForward() * -DISMOUNTDISTANCE;
	if (CheckDismountViability(viewPosition))
		return viewPosition;

	//Try the viewAngle + 180 degrees.
	idVec3 reverseviewPosition = originPoint + viewAngles.ToForward() * DISMOUNTDISTANCE;
	if (CheckDismountViability(reverseviewPosition))
		return reverseviewPosition;

	//Try behind the melee target.
	if (meleeTarget.IsValid())
	{
		idVec3 behindEnemyPos = meleeTarget.GetEntity()->GetPhysics()->GetOrigin() + meleeTarget.GetEntity()->viewAxis.ToAngles().ToForward() * -DISMOUNTDISTANCE;
		if (CheckDismountViability(behindEnemyPos))
			return behindEnemyPos;
	}

	return vec3_zero;
}

bool idPlayer::CheckDismountViability(idVec3 _position)
{
	//Check for bounding box clearance.
	trace_t viewTr;
	idBounds playerBounds = GetPhysics()->GetClipModel()->GetBounds();
	gameLocal.clip.TraceBounds(viewTr, _position, _position, playerBounds, MASK_SOLID, this);
	if (viewTr.fraction < 1)
		return false;

	//Check if there's a floor.
	trace_t floorTr;
	gameLocal.clip.TracePoint(floorTr, _position + idVec3(0, 0, 1), _position + idVec3(0, 0, -16), MASK_SOLID, this);
	if (floorTr.fraction >= 1)
		return false;

	return true;

}



//This looks at what direction keys the player is pressing, and then determines what
//camera-relative direction it's pointing toward.
//Returns idVec3 of screen-relative direction player is pressing WASD toward.
idVec3 idPlayer::GetCameraRelativeDesiredMovement()
{
	if (abs(usercmd.forwardmove) > 16)
	{
		//player pressing forward.
		float forwardAmount = usercmd.forwardmove > 0 ? 1 : -1;
		if (abs(usercmd.rightmove) > 16)
		{
			//Forward AND left/right.
			idVec3 rightDir;
			viewAngles.ToVectors(NULL, &rightDir, NULL);
			idVec3 newAngle;
			newAngle = (viewAngles.ToForward() * forwardAmount) + rightDir * (usercmd.rightmove > 0 ? 1 : -1);
			newAngle.NormalizeFast();
			return newAngle;
		}
		else
		{
			//Just forward.
			return (viewAngles.ToForward() * forwardAmount);
		}
	}
	else if (abs(usercmd.rightmove) > 16)
	{
		idVec3 rightDir;
		viewAngles.ToVectors(NULL, &rightDir, NULL);
		return rightDir * (usercmd.rightmove > 0 ? 1 : -1);
	}	

	return vec3_zero;	
}



//When we want spectatormode to display victory fanfare stuff, call this first.
void idPlayer::SetSpectateVictoryFanfare()
{
	spectateState = SPC_FANFAREREADY;
}

int idPlayer::GetCatsAvailable()
{
	int amount = 0;
	for (idEntity* catEnt = gameLocal.catfriendsEntities.Next(); catEnt != NULL; catEnt = catEnt->catfriendNode.Next())
	{
		if (!catEnt)
			continue;

		if (!catEnt->IsType(idCat::Type))
			continue;

		if (static_cast<idCat *>(catEnt)->IsAvailable())
			amount++;
	}

	return amount;
}

//Get total amount of cat friends who have been rescued.
int idPlayer::GetCatsRescued()
{
	int amount = 0;
	for (idEntity* catEnt = gameLocal.catfriendsEntities.Next(); catEnt != NULL; catEnt = catEnt->catfriendNode.Next())
	{
		if (!catEnt)
			continue;

		if (catEnt->IsType(idCat::Type))
			continue;

		if (static_cast<idCat *>(catEnt)->IsRescued())
			amount++;
	}

	return amount;
}

//Get total amount of cat friends
int idPlayer::GetCatsTotal()
{
	int amount = 0;
	for (idEntity* catEnt = gameLocal.catfriendsEntities.Next(); catEnt != NULL; catEnt = catEnt->catfriendNode.Next())
	{
		if (!catEnt)
			continue;

		if (catEnt->IsType(idCat::Type))
			continue;

		amount++;
	}

	return amount;
}

void idPlayer::ForceShowHealthbar(int extraDisplayTime)
{
	hud->HandleNamedEvent("takedamage");
	hud->SetStateFloat("player_lasthealthpercent", 0);
	hud->SetStateInt("showhealthbar", 1);
	healthFadeMaxedBool = true;
	healthbarIsFaded = false;
	healthFadeTimer = gameLocal.time + HEALTHBAR_FADE_DELAYTIME + extraDisplayTime;
	lastHealthValue = 0;
	lastHealthDisplayvalue = 0;
}

void idPlayer::ForceShowOxygenbar()
{
	if (airTics >= pm_airTics.GetInteger())
	{
		//player oxygenmeter is 100% full. Force it to reappear.
		oxygenmeterIsFaded = false;
		hud->HandleNamedEvent("oxygenmeter_show");
		oxygenmeterFadeTimer = gameLocal.time + OXYGENMETER_FADEDELAY;
	}
}

bool idPlayer::IsCrouching()
{
	return physicsObj.IsCrouching();
}



void idPlayer::SetGascloudState(bool value)
{
	cond_gascloud = value;

	if (value)
	{
		if (gameLocal.time > gascloud_timer)
		{
			//Turn ON gascloud effect.
			StartSound("snd_cough_gas", SND_CHANNEL_VOICE);
			gascloud_timer = gameLocal.time + GASCLOUD_DURATION_TIME;
			gascloud_coughtimer = 0;
		}
	}
	else
	{
		//Turn OFF gascloud effect.
		StopSound(SND_CHANNEL_VOICE);
		cond_gascloud = false;
	}
}

int idPlayer::GetWoundcount_Burn()
{
	return cond_burnwound;
}

void idPlayer::HealWound_Burn()
{
	cond_burnwound = 0;

	if (cond_burnwound <= 0)
	{
		WoundRegenerateHealthblock();
	}
}

bool idPlayer::CanPlayerStandHere(idVec3 _pos)
{
	trace_t tr;
	idBounds playerBounds = idBounds(idVec3(-8, -8, 0), idVec3(8, 8, pm_normalheight.GetFloat()));
	gameLocal.clip.TraceBounds(tr, _pos, _pos, playerBounds, MASK_SOLID, this);
	
	if (tr.fraction >= 1)
		return true;

	return false;
}



void idPlayer::Event_setPlayerFrozen(int value)
{
	this->isFrozen = value;
}

idVec3 idPlayer::GetClosestPointOnLine(idVec3 observerPoint, idVec3 lineStart, idVec3 lineEnd)
{
	idVec3 lineVec = lineEnd - lineStart;
	float dot = DotProduct(observerPoint - lineStart, lineVec) / DotProduct(lineVec, lineVec);	
	
	idVec3 finalPosition;
	finalPosition.Lerp(lineStart, lineEnd, idMath::ClampFloat(0, 1, dot));	
	return finalPosition;
}

bool idPlayer::SetHotbarslotsUnlockDelta(int delta)
{
	int currentAmount = inventory.hotbarUnlockedSlots;
	int newAmount = inventory.hotbarUnlockedSlots + delta;

	if (newAmount > MAX_HOTBARSLOTS || newAmount < 0)
		return false; //exceed max hotbar slot min/max amounts.

	inventory.hotbarUnlockedSlots = newAmount;

	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		//this->hud->SetStateString(va("hotbarname%d", i), ""); //Reset hotbar.
		this->hud->SetStateBool(va("hotbarvisible%d", i), (i <= inventory.hotbarUnlockedSlots - 1) ? true : false); //Set hotbar visibility.
		
		//Do a flash animation.
		if (i >= currentAmount)
		{
			this->hud->HandleNamedEvent(va("hotbarflash%d", i));
		}
	}

	return true;
}

//Script call. Can adjust the player's FOV.
void idPlayer::Event_SetFOVLerp(float amount, int timeMS)
{
	fovLerpStart = fovLerpEnd;
	fovLerpEnd = amount;
	fovLerpTimer = timeMS;
	fovLerpState = FOVLERP_LERPING;
	fovLerpStartTime = gameLocal.time;
}

void idPlayer::SetCanFrob(int value)
{
	playerCanFrob = (value > 0) ? true : false;
}

void idPlayer::StartGrabringGrab(idVec3 destination, idEntity *grabring)
{
	physicsObj.StartGrabRing(destination, grabring);
}

int idPlayer::GetCoinCount()
{
    return coins;
}

void idPlayer::SetCoinDelta(int delta)
{
    coins += delta;

    hud->SetStateInt("coins", coins);
    hud->HandleNamedEvent("coinFlash");
}

void idPlayer::Weapon_Jockey()
{
	if (!meleeTarget.IsValid())
		return;

	//player pressed LMB while jockeying.
	if ((usercmd.buttons & BUTTON_ATTACK) && !(oldButtons & BUTTON_ATTACK))
	{
		meleeTarget.GetEntity()->DoJockeyBrutalSlam();
		brutalslams++;
	}

	bool canExpireTime = true;

	if (meleeTarget.GetEntity()->IsType(idGunnerMonster::Type))
	{
		if (static_cast<idGunnerMonster *>(meleeTarget.GetEntity())->IsJockeyBeingAttacked()) //If jockee is currently in the process of getting slammed against a wall, wait for that to finish first.
		{
			canExpireTime = false;
		}
	}

	//Check for jockey expiration time.
	if (gameLocal.time > jockeyTimer && canExpireTime)
	{
		jockeyTimer = gameLocal.time + JOCKEY_PIPINTERVAL;
		SetStaminaDelta(meleeTarget.GetEntity()->spawnArgs.GetFloat("jockeyStaminaDrain", JOCKEY_DEFAULTSTAMINADRAIN));

		if (stamina <= 0)
		{
			//Jockey timer expired.
			SetJockeyMode(false);
			staminaChargeDelayTimer = gameLocal.time;

			SetCenterMessage("#str_def_gameplay_jockey_kickoff");
			//Damage(NULL, NULL, vec3_zero, "damage_jockey_playerfail", 1.0f, 0);		
			SetImpactSlowmo(true, 200);

			//do player knockdown.
			//Damage(NULL, NULL, vec3_zero, spawnArgs.GetString("def_jockeyfaildamage"), 1.0f, 0);
			SetFallState(true, false);

			//push player away.
			if (meleeTarget.IsValid())
			{
				//Push player in the direction away from enemy's forward direction.
				idAngles enemyAngle = meleeTarget.GetEntity()->viewAxis.ToAngles(); //enemy forward direction.
				enemyAngle.pitch = 0;
				enemyAngle.yaw += 180; //turn it backwards.

				//gameRenderWorld->DebugArrow(colorGreen, meleeTarget.GetEntity()->GetPhysics()->GetOrigin(), meleeTarget.GetEntity()->GetPhysics()->GetOrigin() + enemyAngle.ToForward() * 32, 4, 60000);

				idVec3 pushForce = enemyAngle.ToForward() * JOCKEY_KICKPLAYEROFF_FORCE;
				physicsObj.SetLinearVelocity(pushForce);
			}
		}
	}
}

void idPlayer::UpdateThrowableAIDodge(idVec3 _throwOrigin, bool doAIDodge)
{
	//Check if any AI should be informed to dodge the thrown object.
	//This gets called on the frame that the player throws an object.

	for (idEntity* entity = gameLocal.aimAssistEntities.Next(); entity != NULL; entity = entity->aimAssistNode.Next())
	{
		if (!entity || !entity->IsActive() || entity->IsHidden() || entity == this || entity->team == TEAM_FRIENDLY || entity->health <= 0 || !gameLocal.InPlayerConnectedArea(entity))
			continue;

		if (!entity->IsType(idGunnerMonster::Type))
			continue;

		if (!static_cast<idGunnerMonster *>(entity)->CanAcceptStimulus())
			continue;

		bool dodges = false;

		//Check AI's dotproduct. We only care about AI that are facing toward the throwOrigin.
		idVec3 dirToAI = (entity->GetPhysics()->GetOrigin() - _throwOrigin);
		dirToAI.Normalize();
		idVec3 AI_forwardDir = static_cast<idGunnerMonster *>(entity)->viewAxis[0];
		float dotFacing = DotProduct(dirToAI, AI_forwardDir);		
		if (dotFacing < DODGE_DOTTHRESHOLD)
		{
			idVec3 nearestPos;
			if (CheckThrowableArcHitOnAI(_throwOrigin, entity, nearestPos))
			{
				dodges = true;

				if (doAIDodge)
				{
					//AI is in trajectory. distance. Tell AI to dodge.
					static_cast<idGunnerMonster *>(entity)->StartDodge(nearestPos);
				}
			}
		}

		static_cast<idGunnerMonster *>(entity)->drawDodgeUI = dodges;
	}
}

bool idPlayer::CheckThrowableArcHitOnAI(idVec3 _throwOrigin, idEntity *aiEnt, idVec3 &nearestPos)
{
	//Determine if the throwing arc trajectory is near any AI.
	int shortestDistance = 999999;
	nearestPos = vec3_zero;

	for (int i = 0; i < THROWARC_BEAMCOUNT; i++)
	{
		if (!throwBeamOrigin[i]->IsHidden())
		{
			if (throwBeamOrigin[i]->targets[0].IsValid())
			{
				idVec3 targetPos = throwBeamOrigin[i]->targets[0].GetEntity()->GetPhysics()->GetOrigin();

				float distanceToAI = ((aiEnt->GetPhysics()->GetOrigin() + idVec3(0, 0, 48)) - targetPos).Length();

				if (distanceToAI < shortestDistance)
				{
					shortestDistance = distanceToAI;
					nearestPos = targetPos;
				}
			}
		}
	}

	if (shortestDistance < AI_THROWABLEDODGE_DISTANCETHRESHOLD)
	{
		//this trajectory is pretty close to the AI. Tell the AI to dodge.
		return true;
	}

	return false;
}

//Check if damage is coming from the front or back. If front, then jockee absorbs the damage.
bool idPlayer::AcceptJockeyDamage(idEntity *inflictor, idEntity *attacker, const idVec3 &dir, const char *damageDefName)
{
	//gameRenderWorld->DebugArrow(colorGreen, attacker->GetPhysics()->GetOrigin(), attacker->GetPhysics()->GetOrigin() + dir * 128, 4, 10000);

	if (!meleeTarget.IsValid())
		return true;

	if (dir == vec3_zero)
		return true;

	//what direction is attack coming from.
	idVec3 jockeeDir = meleeTarget.GetEntity()->viewAxis.ToAngles().ToForward();
	float dotResult = DotProduct(dir, jockeeDir);	

	if (dotResult > JOCKEY_REAR_DAMAGE_DOTTHRESHOLD) //attack is coming from BEHIND player. accept the damage.
		return true;

	return false; //attack is coming from front of player. ignore the damage.
}

void idPlayer::Event_SetBloodRage(float value, float seconds)
{
	int timeMS = SEC2MS(seconds);

    playerView.DoBloodrageLerp(value, timeMS);
}

void idPlayer::Event_ForceSpaceParticles(int enable)
{
	forceSpaceParticles = (bool)enable;
}





void idPlayer::ForceDuck(int duration)
{
	physicsObj.ForceDuck(duration);
}

//Handles placement of carryable items. This is for things like attaching TNT to the wall, etc.
//Returns TRUE if an item was successfully placed.
bool idPlayer::DoCarryablePlacerLogic()
{
	//First, see if this carryable is a placer
	idEntity* selectedEnt = nullptr;
	if (GetCarryable() == nullptr)
		return false;

	selectedEnt = GetCarryable();
	const idDeclEntityDef* weaponDef = gameLocal.FindEntityDef(selectedEnt->spawnArgs.GetString("weapon"), false);
	if (!weaponDef->dict.GetBool("showplacer"))
		return false;

	if (!placerEnt->IsHidden() && placerClearance)
	{
		//plop it down.
		for (int i = 0; i < MAX_HOTBARSLOTS; i++)
		{
			if (!inventory.hotbarSlots[i].carryPtr.IsValid())
				continue;

			if (!inventory.hotbarSlots[i].carryPtr.GetEntity())
				continue;

			if (inventory.hotbarSlots[i].carryPtr.GetEntityNum() == selectedEnt->entityNumber)
			{
				//Place banana on floor.
				idEntity *item;

				float playerYaw = viewAngles.yaw;
				idAngles placementAngle = idAngles(0, playerYaw, 0);

				item = carryableItem.GetEntity();
				SetCarryable(NULL, false);

				item->GetPhysics()->SetOrigin(placerEnt->GetPhysics()->GetOrigin() + idVec3(0, 0, 12));
				item->GetPhysics()->SetAxis(placementAngle.ToMat3());
				item->GetPhysics()->SetLinearVelocity(idVec3(0,0,8));
				item->GetPhysics()->SetAngularVelocity(vec3_zero);
				item->throwTime = gameLocal.time;

				//if (item->IsType(idMoveableItem::Type))
				//{
				//	static_cast<idMoveableItem*>(item)->JustThrown();
				//}

				return true;
			}
		}
	}

	return false;
}

void idPlayer::UpdatePlayerLocboxTriggers()
{
	if (!ShouldShowLocBox())
	{
		return;
	}

	idVec3 startTr, endTr;
	trace_t frobTr;
	if (peekObject.IsValid() && static_cast<idVentpeek*>(peekObject.GetEntity())->peekEnt.IsValid())
	{
		startTr = static_cast<idVentpeek*>(peekObject.GetEntity())->peekEnt.GetEntity()->GetPhysics()->GetOrigin();
	}
	else
	{
		startTr = GetEyePosition();
	}
	
	endTr = startTr + viewAngles.ToForward() * PLAYERLOOK_TRIGGER_DIST;

	gameLocal.clip.TracePoint(frobTr, startTr, endTr, CONTENTS_SOLID | CONTENTS_PLAYERLOOK_TRIGGER, this);

	idEntity* ent = frobTr.fraction < 1 ? gameLocal.entities[frobTr.c.entityNum] : nullptr;


	bool locboxtriggerThisFrame = false;
	idStr locString = "";

	//Do a straight tracepoint
	if (ent && ent->IsType(idTrigger_Multi::Type) && !ent->IsHidden())
	{
		locboxtriggerThisFrame = true;
		locString = ent->spawnArgs.GetString("text");
	}
	else
	{
		locboxtriggerThisFrame = false;
	}

	if (locboxtriggerThisFrame && !lastLocboxtriggerState)
	{
		//turn on loc box
		DisplayLocbox(locString.c_str());
	}
	else if (!locboxtriggerThisFrame && lastLocboxtriggerState)
	{
		//turn off loc box
		DisplayLocbox("");
	}

	lastLocboxtriggerState = locboxtriggerThisFrame;
}

void idPlayer::UpdatePlayerLookTriggers()
{
	if ( lastPlayerLookTrigger.IsValid() && lastPlayerLookTrigger.GetEntity()->IsHidden() )
	{
		lastPlayerLookTrigger = nullptr;
	}

	idVec3 startTr, endTr;
	trace_t frobTr;
	
	startTr = GetEyePosition();
	endTr = startTr + viewAngles.ToForward() * PLAYERLOOK_TRIGGER_DIST;

	gameLocal.clip.TracePoint( frobTr, startTr, endTr, CONTENTS_SOLID | CONTENTS_PLAYERLOOK_TRIGGER, this );

	idEntity* ent = frobTr.fraction < 1 ? gameLocal.entities[frobTr.c.entityNum] : nullptr;
	
	//Do a straight tracepoint
	if ( ent  && ent->IsType( idTrigger_Multi::Type ) && !ent->IsHidden() )
	{
		idTrigger_Multi* trigger = static_cast< idTrigger_Multi* >( ent );
		float range = trigger->GetPlayerLookRange();
		float dist = frobTr.fraction * PLAYERLOOK_TRIGGER_DIST;
		bool isInRange = range == 0.0f || range >= dist;
		
		if ( lastPlayerLookTrigger.IsValid() && ( lastPlayerLookTrigger.GetEntity() != ent || !isInRange) )
		{
			lastPlayerLookTrigger.GetEntity()->PostEventMS( &EV_PlayerLookExit, 0 );
			lastPlayerLookTrigger = nullptr;
		}

		if ( lastPlayerLookTrigger.GetEntity() != ent && isInRange )
		{
			lastPlayerLookTrigger = ent;
			lastPlayerLookTrigger.GetEntity()->PostEventMS( &EV_PlayerLookEnter, 0 );
		}
	}
	else if ( lastPlayerLookTrigger.IsValid() )
	{
		lastPlayerLookTrigger.GetEntity()->PostEventMS( &EV_PlayerLookExit, 0 );
		lastPlayerLookTrigger = nullptr;
	}
}

void idPlayer::DebugUnassignedLocations()
{
	// SM: Debug arrow draws to draw arrows from player to unassigned locations
	if ( cvarSystem->GetCVarBool( "g_showUnassignedLocations" ) )
	{
		int unassignedCount = 0;

		int	numAreas = gameRenderWorld->NumAreas();
		idLocationEntity** locations = gameLocal.GetLocationEntities();
		idVec3 playerLocation = gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin();
		for ( int i = 0; i < numAreas; i++ )
		{
			if ( locations[i] == nullptr )
			{
				idVec3 areaCenter = gameRenderWorld->GetAreaCenter( i );
				//gameRenderWorld->DebugArrow( colorRed, playerLocation, areaCenter, 10.0f, 0 );

				gameRenderWorld->DebugArrow( colorRed, areaCenter + idVec3( 0, 0, 128 ), areaCenter, 32, 0 );
				gameRenderWorld->DrawText( "NO LOCATION", areaCenter + idVec3( 0, 0, 128 ), 1.5f, colorRed, gameLocal.GetLocalPlayer()->viewAxis );

				unassignedCount++;
			}
		}

		if ( unassignedCount > 0 )
		{
			common->Printf( "Unassigned location count: %d\n", unassignedCount );
		}
	}
}




//Fired when player presses LMB while zoomed.
void idPlayer::HandleZoomInspectPressFire()
{
	if (!zoominspectEntityPtr.IsValid() || zoominspect_LabelmodeActive)
		return;
	
	//player is inspecting a valid object.
	
	//if (inventory.maintbooks <= 0)
	//{
	//	//player doesn't have ship manual.
	//	hud->HandleNamedEvent("onNoBookZoomInspect");
	//	return;
	//}	
	//
	////Player DOES have ship manual.
	//if (zoominspectEntityPtr.GetEntity()->IsType(idSecurityCamera::Type))
	//{
	//	//if it's a security camera, draw the control box position.
	//	for (idEntity* ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	//	{
	//		if (!ent || !ent->IsType(idCameraSplice::Type))
	//			continue;
	//
	//		if (!static_cast<idCameraSplice *>(ent)->assignedCamera.IsValid())
	//			continue;
	//
	//		if (static_cast<idCameraSplice *>(ent)->assignedCamera.GetEntityNum() != zoominspectEntityPtr.GetEntity()->entityNumber)
	//			continue;
	//
	//		//temp lines. todo: make better
	//		gameRenderWorld->DebugArrow(colorWhite, zoominspectEntityPtr.GetEntity()->GetPhysics()->GetOrigin(), ent->GetPhysics()->GetOrigin(), 8, 60000);
	//		gameRenderWorld->DebugBox(colorWhite, idBox(idBounds(idVec3(-4, -4, -4), idVec3(4, 4, 4)), ent->GetPhysics()->GetOrigin(), mat3_identity), 60000);
	//	}
	//}


	idVec3 positionOffset = zoominspectEntityPtr.GetEntity()->spawnArgs.GetVector("zoominspect_campos");

	if (positionOffset == vec3_zero)
		return; //cannot inspect the object.
    

	//get the zoominspect label info.	
	idAngles angleOffset;
	angleOffset.pitch = zoominspectEntityPtr.GetEntity()->spawnArgs.GetVector("zoominspect_angle")[0];
	angleOffset.yaw = zoominspectEntityPtr.GetEntity()->spawnArgs.GetVector("zoominspect_angle")[1];
	angleOffset.roll = zoominspectEntityPtr.GetEntity()->spawnArgs.GetVector("zoominspect_angle")[2];

	StartSound("snd_zoomin", SND_CHANNEL_ANY, 0, false, NULL);

	bool doForwardOffset = false;
	if (zoominspectEntityPtr.GetEntity()->spawnArgs.GetBool("zoominspect_viewforward"))
	{
		float facingResult = DotProduct(zoominspectEntityPtr.GetEntity()->GetPhysics()->GetAxis().ToAngles().ToForward(), viewAngles.ToForward());
		if (facingResult > 0)
		{
			doForwardOffset = true;
		}
	}

	//position of camera.
	zoominspect_LabelmodePosition = GetAdjustedLabelInspectionPosition(zoominspectEntityPtr);
	zoominspect_LabelmodeActive = true;
	zoominspectEntityPtr.GetEntity()->SetPostFlag(POST_INSPECT_LUMINANCE, true);
	hud->SetStateBool("showzoomcontrols", false);
	zoominspect_lerpDone = false;

	hud->SetStateBool("playermoving", false);

	

	//angle of camera.
	idMat3 currentAxis = zoominspectEntityPtr.GetEntity()->GetPhysics()->GetAxis();
	idMat3 rotate = angleOffset.ToMat3();
	idMat3 newAxis = rotate * currentAxis;
	idAngles finalAngle = newAxis.ToAngles();
	
	int rolltype = zoominspectEntityPtr.GetEntity()->spawnArgs.GetInt("zoominspect_doroll", "1");
	if (rolltype <= 0)
	{
		//we sometimes want to lock camera roll to zero.
		finalAngle.roll = 0;
	}
	else if (rolltype == 1)
	{
		//Do the roll.
	}
	else if (rolltype == 2)
	{
		//Do an automatic roll check. Only do roll if note is not on wall surface.		
		if (idMath::Fabs(finalAngle.pitch) < 5)
		{
			finalAngle.roll = 0;
		}
	}

	if (doForwardOffset)
	{
		finalAngle.yaw += 180; //camera is reversed for viewforward'd entities.
	}

	zoominspect_LabelmodeAngle = finalAngle;	

	this->zoomCurrentFOV = ZOOM_MAX; //furthest zoom level	

	zoominspect_lerpStartPos = firstPersonViewOrigin;
	zoominspect_lerptimer = gameLocal.hudTime + ZOOMINSPECT_LERPTIME;
	zoominspect_lerpStartAngle = viewAngles;

	//Handle the 180 wraparound, so that the camera rotates the shortest distance possible.
	zoominspect_lerpStartAngle.Normalize180();
	zoominspect_LabelmodeAngle.Normalize180();

	if (zoominspect_lerpStartAngle.yaw < -90 && zoominspect_LabelmodeAngle.yaw > 0)
		zoominspect_LabelmodeAngle.yaw -= 360;

	if (zoominspect_lerpStartAngle.yaw > 90 && zoominspect_LabelmodeAngle.yaw < 0)
		zoominspect_LabelmodeAngle.yaw -= 360;

	// renormalize 2nd time
	zoominspect_LabelmodeAngle.Normalize180();

	hud->SetStateBool("zoominspect_draw", false);


	//If applicable, add note to the event log.
	if (zoominspectEntityPtr.GetEntity()->spawnArgs.GetBool("is_note"))
	{
		//add to event log.
		idStr noteText = zoominspectEntityPtr.GetEntity()->spawnArgs.GetString("gui_parm0");
		if (noteText.Length() > 0)
		{
			idVec3 notePos = zoominspectEntityPtr.GetEntity()->GetPhysics()->GetOrigin();
			gameLocal.AddEventLog("#str_def_gameplay_readnote", notePos, false);

			if (zoominspectEntityPtr.GetEntity()->IsType(idNoteWall::Type))
			{
				if (!static_cast<idNoteWall*>(zoominspectEntityPtr.GetEntity())->GetRead())
				{
					static_cast<idNoteWall*>(zoominspectEntityPtr.GetEntity())->SetRead();
				}
				else
				{
					//is already read.
					hud->HandleNamedEvent("noteAlreadyRead");
				}
			}
		}
	}


	//if you want a dynatip to disappear when you inspect it: give the entity that's associated with the dynatip a spawnarg of "dyna_inspectable 1"
	if (zoominspectEntityPtr.GetEntity()->spawnArgs.GetInt("dyna_inspectable") == 1)
	{
		zoominspectEntityPtr.GetEntity()->spawnArgs.SetInt("dyna_inspectable", 2); //tell dynatip to disappear.
	}

	//Special behavior for inspecting an AI.
	if (zoominspectEntityPtr.GetEntity()->IsType(idAI::Type))
	{
		//Zoom into the AI's head.
		zoominspect_LabelmodeAngle = idAngles(viewAngles.pitch, viewAngles.yaw, 0);
		idVec3 headPos = static_cast<idAI *>(zoominspectEntityPtr.GetEntity())->GetEyePosition();
		zoominspect_LabelmodePosition = headPos + (zoominspect_LabelmodeAngle.ToForward() * -32) + idVec3(0,0,-4); //position camera close to baddie, but push away a little via playerview angle

		//Generate the textstring of inventory items.
		hud->SetStateBool("zoomdesc_draw", true);

		hud->SetStateString("zoom_rolename", zoominspectEntityPtr.GetEntity()->spawnArgs.GetString("rolename"));

		hud->SetStateString("zoom_title", zoominspectEntityPtr.GetEntity()->displayName.c_str());
		idStr inventoryString = "";

		//Helmet check
		if (static_cast<idAI *>(zoominspectEntityPtr.GetEntity())->hasHelmet)
		{
			inventoryString = idStr::Format("%s- %s\n", inventoryString.c_str(), "Helmet");
		}

		//What are the drops.
		const idKeyValue *kv = zoominspectEntityPtr.GetEntity()->spawnArgs.MatchPrefix("def_dropDeathItem", NULL);
		while (kv)
		{
			idStr value = kv->GetValue();
			if (value.Length() > 0)
			{
				const idDeclEntityDef *entDef = gameLocal.FindEntityDef(value.c_str(), false);
				if (entDef)
				{
					idStr entName = entDef->dict.GetString("displayname");
					if (entName.Length() > 0)
					{
						inventoryString = idStr::Format("%s- %s\n", inventoryString.c_str(), common->GetLanguageDict()->GetString(entName.c_str()));
					}
				}
			}

			kv = zoominspectEntityPtr.GetEntity()->spawnArgs.MatchPrefix("def_dropDeathItem", kv);
		}

		//What objects are attached to belt.
		int attachmentCount = static_cast<idAI *>(zoominspectEntityPtr.GetEntity())->attachmentsToDrop.Num();
		if (attachmentCount > 0)
		{
			for (int i = 0; i < attachmentCount; i++)
			{
				if (static_cast<idAI *>(zoominspectEntityPtr.GetEntity())->attachmentsToDrop[i].ent.IsValid())
				{
					idStr entName = static_cast<idAI *>(zoominspectEntityPtr.GetEntity())->attachmentsToDrop[i].ent.GetEntity()->displayName;
					if (entName.Length() > 0)
					{
						inventoryString = idStr::Format("%s- %s\n", inventoryString.c_str(), entName.c_str());
					}
				}
			}
		}

		hud->SetStateString("zoom_desc", inventoryString.c_str());
	}
	else
	{
		hud->SetStateBool("zoomdesc_draw", false);
	}

	if (memorypalaceState == MEMP_ACTIVE)
	{
		hud->HandleNamedEvent("onMemorypalaceInspect");
	}

	hud->SetStateBool("playermoving", false);

	HandleItemLocboxInspect(zoominspectEntityPtr.GetEntity()->spawnArgs);

	idStr scriptname = zoominspectEntityPtr.GetEntity()->spawnArgs.GetString("zoominspect_callscript");
	if (scriptname.Length() > 0)
	{
		gameLocal.RunMapScript(scriptname.c_str());
	}
}

idVec3 idPlayer::GetAdjustedLabelInspectionPosition(idEntityPtr<idEntity> entPtr)
{
	if (!entPtr.IsValid())
		return vec3_zero;

	idVec3 positionOffset = entPtr.GetEntity()->spawnArgs.GetVector("zoominspect_campos");

	//Debug.
	if (g_zoominspectDebug.GetString()[0] != '\0')
	{
		//debug test an inspection XYZ. try to parse the value.
		idStr xyz = g_zoominspectDebug.GetString();
		idStrList xyzList = xyz.Split(' ', true);

		if (xyzList.Num() >= 3)
		{
			float x = atof(xyzList[0]);
			float y = atof(xyzList[1]);
			float z = atof(xyzList[2]);

			positionOffset = idVec3(x, y, z);
		}
	}

	idVec3 forward, right, up;
	entPtr.GetEntity()->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);

	//-------------------------- VIEWFORWARD --------------------------	
	bool doForwardOffset = false;
	if (entPtr.GetEntity()->spawnArgs.GetBool("zoominspect_viewforward"))
	{
		float facingResult = DotProduct(entPtr.GetEntity()->GetPhysics()->GetAxis().ToAngles().ToForward(), viewAngles.ToForward());
		if (facingResult > 0)
		{
			doForwardOffset = true;
		}
	}

	if (doForwardOffset)
	{
		positionOffset[0] = -positionOffset[0];
		positionOffset[1] = -positionOffset[1];
	}

	return zoominspectEntityPtr.GetEntity()->GetPhysics()->GetOrigin() + (forward * positionOffset[0]) + (right * positionOffset[1]) + (up * positionOffset[2]);
}



void idPlayer::DebugPrintInventory(int index)
{
	//inventory debug. We have a problem where items sometimes disappear. Try to figure this out.

	//index = if we only want info on a specific hotbar index slot.

	idVec3 pos = GetPhysics()->GetOrigin();

	if (index <= -1)
	{
		common->Printf("\n");		
		common->Printf("Player position=(%f, %f, %f)\n", pos.x, pos.y, pos.z);
	}

	for ( int i = 0; i < Min( MAX_HOTBARSLOTS, inventory.hotbarUnlockedSlots ); i++ )
	{
		if (index >= 0 && i != index)
			continue;

		const char *slotName = "???";
		const char *carryableName = "NULL";
		idEntity* carryPtr = nullptr;
		if ( inventory.hotbarSlots[i].weaponType >= 0 )
		{
			slotName = spawnArgs.GetString( va( "def_weapon%d", inventory.hotbarSlots[i].weaponType ) );
			if ( inventory.hotbarSlots[i].carryPtr.IsValid() )
			{
				carryPtr = inventory.hotbarSlots[i].carryPtr.GetEntity();
				carryableName = carryPtr->GetName();
			}
		}

		common->Printf( "slot %d:\n", i + 1 );
		common->Printf( "\tweapon='%s'\n", slotName );
		common->Printf( "\titem='%s'\n", carryableName );

		if ( carryPtr )
		{
			pos = carryPtr->GetPhysics()->GetOrigin();
			common->Printf( "\tposition=(%f, %f, %f)\n", pos.x, pos.y, pos.z );
			common->Printf( "\thidden=%s\n", carryPtr->IsHidden() ? "YES" : "NO" );
		}
	}
}

void idPlayer::AddLostInSpace( int lostEntityDefNum )
{
	lostInSpaceEntityDefNums.Append( lostEntityDefNum );
}

void idPlayer::RemoveLostInSpace( int foundEntityDefNum )
{
	lostInSpaceEntityDefNums.Remove( foundEntityDefNum );
}

bool idPlayer::IsEntityLostInSpace(const idStr& entityDefName)
{
	const idDecl* decl = declManager->FindDeclWithoutParsing(DECL_ENTITYDEF, entityDefName.c_str(), false);
	if (decl)
	{
		return lostInSpaceEntityDefNums.Find(decl->Index()) != NULL;
	}

	return false;
}

bool idPlayer::HasInventoryItem(idStr invname)
{	
	if (invname.Length() <= 0)
		return false;
	
	idDict *item = FindInventoryItem(invname);
	if (item)
	{
		return true;
	}

	return false;
}

//Script call.
void idPlayer::Event_HasInventoryItem(const char *itemname)
{
	idThread::ReturnInt(HasInventoryItem(itemname) ? 1 : 0);
}

bool idPlayer::IsThrowarcAtDropPosition()
{
	#define FLOORANGLE_THRESHOLD 63
	float distanceToThrowdisc = (firstPersonViewOrigin - throwdisc->GetPhysics()->GetOrigin()).Length();

	idAngles discAngle = throwdisc->GetPhysics()->GetAxis().ToAngles();
	bool isFloor = idMath::Fabs(discAngle.pitch) > FLOORANGLE_THRESHOLD;
	
	return (isFloor && distanceToThrowdisc <= DROP_ITEM_THROWARC_DISTANCE && discAngle.pitch < 0);
}



void idPlayer::EventlogMenuOpen(bool value)
{
	if (value)
	{
		//opening event log.
		eventlogMenu->SetCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //move mouse to screen center.
		oldMouseX = usercmd.mx;
		oldMouseY = usercmd.my;
		session->SetGUI(eventlogMenu, NULL);
	}
	else
	{
		contextMenu->SetCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //move mouse to screen center.
		oldMouseX = usercmd.mx;
		oldMouseY = usercmd.my;

		session->SetGUI(contextMenuActive ? contextMenu : NULL, NULL);
	}

	eventlogMenuActive = value;
}

void idPlayer::UpdateArmstats()
{
	if (!armstatsActive)
		return;

	//Player position.
	idVec2 playerNormalizedPos = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetMapguiNormalizedPosition(gameLocal.GetLocalPlayer()->GetPhysics()->GetOrigin());


	//Handle the cryopod position if needed.
	if (!static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->GetPlayerExitedCryopod())
	{
		//Player is in the cryopod and is looking at info watch.
		if (cryoexitEntNum > 0)
		{
			if (gameLocal.entities[cryoexitEntNum] != NULL)
			{
				idVec3 exitOrigin = gameLocal.entities[cryoexitEntNum]->GetPhysics()->GetOrigin();
				playerNormalizedPos = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetMapguiNormalizedPosition(exitOrigin);
			}
		}
	}
	


	//clamp it so the sprite doesn't get truncated if it's near the edge of map.
	playerNormalizedPos.x = idMath::ClampFloat(0.01f, .99f, playerNormalizedPos.x);
	playerNormalizedPos.y = idMath::ClampFloat(0.01f, .99f, playerNormalizedPos.y);

	armstatsModel->Event_SetGuiFloat("playerx", playerNormalizedPos.x);
	armstatsModel->Event_SetGuiFloat("playery", playerNormalizedPos.y);

	//player icon yaw.
	float playerYaw = gameLocal.GetLocalPlayer()->viewAngles.yaw;
	armstatsModel->Event_SetGuiFloat("playeryaw", playerYaw);


	//tally up cat stats
	int totalcages = 0;
	int rescuedCats = 0;
	for (idEntity* cageEnt = gameLocal.catcageEntities.Next(); cageEnt != NULL; cageEnt = cageEnt->catcageNode.Next())
	{
		if (!cageEnt)
			continue;

		if (!cageEnt->IsType(idCatcage::Type))
			continue;

		totalcages++;

		if (static_cast<idCatcage *>(cageEnt)->IsOpened())
		{
			rescuedCats++;
		}
	}

	armstatsModel->Event_SetGuiInt("cats_rescued", rescuedCats);
	armstatsModel->Event_SetGuiInt("cats_total", totalcages);
}

void idPlayer::SetArmstatsFuseboxNeedUpdate()
{
	armstatFuseboxNeedsUpdate = true;
	armstatFuseboxUpdateTimer = gameLocal.time + 300; //We have a little delay so that the system has some time to get its flags flipped, etc
}

void idPlayer::UpdateArmstatsFuseboxes()
{

	bool windowsLocked = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->IsFuseboxLocked(SYS_WINDOWS);
	bool airlocksLocked = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->IsFuseboxLocked(SYS_AIRLOCKS);
	bool ventsLocked = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->IsFuseboxLocked(SYS_VENTS);
	bool trashLocked = static_cast<idMeta*>(gameLocal.metaEnt.GetEntity())->IsFuseboxLocked(SYS_TRASHCHUTES);

	armstatsModel->Event_SetGuiInt("windows_locked",	windowsLocked		);
	armstatsModel->Event_SetGuiInt("airlocks_locked", airlocksLocked		);
	armstatsModel->Event_SetGuiInt("vents_locked",	ventsLocked			);
	armstatsModel->Event_SetGuiInt("trash_locked",	trashLocked			);	
}

void idPlayer::UpdateArmstatsDoorlocks()
{	
	//Update the display of locked doors.

	int markedDoors = 0;

	//Iterate through doors.
	for (idEntity* ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next())
	{
		if (!ent)
			continue;

		if (ent->IsHidden() || !ent->IsType(idDoor::Type) || ent->IsType(idVentdoor::Type))
			continue;

		if (!static_cast<idDoor *>(ent)->IsBarricaded())
			continue;

		//found a locked door.
		idVec2 normalizedPos = static_cast<idMeta *>(gameLocal.metaEnt.GetEntity())->GetMapguiNormalizedPositionViaEnt(ent);
		armstatsModel->Event_SetGuiFloat(idStr::Format("doorlock%d_x", markedDoors), normalizedPos.x);
		armstatsModel->Event_SetGuiFloat(idStr::Format("doorlock%d_y", markedDoors), normalizedPos.y);
		armstatsModel->Event_SetGuiInt(idStr::Format("doorlock%d_vis", markedDoors), 1); //make the marker visible.

																		  //Figure out what color to draw.
		idVec3 barricadeColor = static_cast<idDoor *>(ent)->GetBarricadeColor();
		armstatsModel->Event_SetGuiFloat(idStr::Format("doorlock%d_r", markedDoors), barricadeColor.x);
		armstatsModel->Event_SetGuiFloat(idStr::Format("doorlock%d_g", markedDoors), barricadeColor.y);
		armstatsModel->Event_SetGuiFloat(idStr::Format("doorlock%d_b", markedDoors), barricadeColor.z);

		markedDoors++;

		if (markedDoors > MAX_DOORLOCKMARKERS)
		{
			//Uh oh. too many elements for the map gui to handle.
			gameLocal.Warning("diagnostic: too many door lock markers in map (max is %d).\n", MAX_DOORLOCKMARKERS);
			break;
		}
	}

	if (markedDoors < MAX_DOORLOCKMARKERS)
	{
		for (int i = markedDoors; i < MAX_DOORLOCKMARKERS; i++)
		{
			armstatsModel->Event_SetGuiInt(idStr::Format("doorlock%d_vis", i), 0); //make the marker hidden.
		}
	}
	
}

void idPlayer::DoDoorlockDelayedUpdate()
{
	armstatDoorlockNeedsUpdate = true;
	armstatDoorlockUpdateTimer = gameLocal.time + 300;
}


//This is the location of the inspection selection UI when the player is holding down Z.
idVec3 idPlayer::GetZoominspectAdjustedPosition(idEntity *ent)
{
	idVec3 entityWorldPos = ent->GetPhysics()->GetOrigin();

	idStr jointname = ent->spawnArgs.GetString("zoominspect_joint");
	if (jointname.Length() > 0 && ent->IsType(idAI::Type))
	{
		//'bind' the selector box to the model's joint.
		jointHandle_t jointHandle;
		idVec3 jointPos;
		idMat3 jointAxis;
		jointHandle = static_cast<idAI *>(ent)->GetAnimator()->GetJointHandle(jointname);
		if (static_cast<idAI *>(ent)->GetJointWorldTransform(jointHandle, gameLocal.time, jointPos, jointAxis))
		{
			entityWorldPos = jointPos;
		}
	}

	idVec3 inspectOffset = ent->spawnArgs.GetVector("zoominspect_selpos");
	if (inspectOffset.x != 0 || inspectOffset.y != 0 || inspectOffset.z != 0)
	{
		idVec3 forward, right, up;
		ent->GetPhysics()->GetAxis().ToAngles().ToVectors(&forward, &right, &up);

		//-------------------------- VIEWFORWARD --------------------------				
		//this is for things like barricades. Where they can be inspected from either side of the object.
		if (ent->spawnArgs.GetBool("zoominspect_viewforward"))
		{
			float facingResult = DotProduct(ent->GetPhysics()->GetAxis().ToAngles().ToForward(), viewAngles.ToForward());
			if (facingResult > 0)
			{
				inspectOffset[0] = -inspectOffset[0];
				inspectOffset[1] = -inspectOffset[1];
			}
		}
		//-----------------------------------------------------------------

		entityWorldPos += (forward * inspectOffset[0]) + (right * inspectOffset[1]) + (up * inspectOffset[2]);
	}

	return entityWorldPos;
}

bool idPlayer::IsPlayerNearSpacenudgeEnt()
{
	if (!gameLocal.world->spawnArgs.GetBool("doSpacenudge", "1"))
		return true;

	for (idEntity* ent = gameLocal.spacenudgeEntities.Next(); ent != NULL; ent = ent->spacenudgeNode.Next())
	{
		if (!ent)
			continue;

		//Do distance check. We only do spacenudge halt if player is within close radius.
		idVec3 podPos = ent->GetPhysics()->GetOrigin();
		float dist = (podPos - firstPersonViewOrigin).Length();		
		if (dist > NUDGEENT_PROXIMITYRADIUS)
		{
			continue;
		}

		//Do dotproduct check. We only halt spacenudge if player is actively facing toward the entity.
		idVec3 dirToEnt = podPos - this->firstPersonViewOrigin;
		dirToEnt.Normalize();
		float facingResult = DotProduct(dirToEnt, viewAngles.ToForward());		
		if (facingResult > 0)
		{
			return true; //player is facing the ent. So we do want to freeze the player movement.
		}
	}

	return false;
}


void idPlayer::SetObjectiveText(const char *text, bool newObjective)
{
	hud->SetStateString("objectivetext", common->GetLanguageDict()->GetString(text));

	if (newObjective)
	{
		hud->HandleNamedEvent("newObjective");
	}

	armstatsModel->Event_SetGuiParm("objectivetext", common->GetLanguageDict()->GetString(text));

	if (text[0] == '\0')
	{
		//If text is empty, then hide the objective button prompt.
		hud->HandleNamedEvent("hideObjectiveButton");
	}
	else if (!newObjective && gameLocal.world->spawnArgs.GetBool("meta_infowatch", "1"))
	{
		//Not doing the new objective fanfare, so force the objective button prompt to activate (in case it was off for some reason, like custom scripting in tutorial)
		hud->HandleNamedEvent("showObjectiveButton");		
	}
}

int idPlayer::GetThrowPower(idEntity *ent)
{
	if (airless)
		return QUICKTHROW_POWER_ZEROG; //if in zero g, always use zero g throw power

	//if (ent != NULL)
	//{
	//	if (ent->health <= 0)
	//	{
	//		return QUICKTHROW_POWER_BROKENITEM;
	//	}
	//}

	return QUICKTHROW_POWER;
}

void idPlayer::StartMemoryPalace()
{
	memorypalaceState = MEMP_SPAWNDELAY;
	memorypalaceTimer = gameLocal.time + 150;
}

//Player view notes from contextmenu.
void idPlayer::DoMemoryPalace()
{
	#define ANGLE_INTERVALDELTA 26	//angle distance between columns.
	#define NOTES_PER_ROW 5			//how many notes per row.
	#define FORWARD_DISTANCE 30		//position in front of player
	#define ROWHEIGHT 19			//distance between rows of notes.

	//Get note count.
	int noteCount = 0;
	for (idEntity* ent = gameLocal.memorypalaceEntities.Next(); ent != NULL; ent = ent->memorypalaceNode.Next())
	{
		if (!ent)
			continue;

		if (!ent->IsType(idNoteWall::Type))
			continue;

		if (static_cast<idNoteWall *>(ent)->IsMemorypalaceClone())
		{
			noteCount++;
		}
	}

	//If player has no notes....
	if (noteCount <= 0)
	{
		memorypalaceState = MEMP_NONE;
		SetCenterMessage("#str_def_gameplay_memoryempty");
		return;
	}

	gameLocal.menuPause = true;
	if (!gameSoundWorld->IsPaused())
	{
		gameSoundWorld->Pause();
	}

	//Fade in the light. Note: this light is a special spectrum that only affects memory notes.
	if (memoryLight)
	{
		//memoryLight->On();
		memoryLight->SetOrigin(firstPersonViewOrigin);
		memoryLight->On();
	}
	

	StartSound("snd_memorypalace_on", SND_CHANNEL_ANY);
	memorypalacePlayerPos = firstPersonViewOrigin;

	idAngles playerView = viewAngles;
	playerView.pitch = 0;
	playerView.roll = 0;
	memorypalaceForwardView = playerView.ToForward();
	
	int rowCount = (int)ceil(noteCount / (float)NOTES_PER_ROW);

	idAngles startAngle = idAngles(0, viewAngles.yaw, 0);	

	if (noteCount > NOTES_PER_ROW)
	{
		//multiple rows.
		startAngle.yaw += (NOTES_PER_ROW / 2.0f) * ANGLE_INTERVALDELTA;
		startAngle.yaw -= ANGLE_INTERVALDELTA / 2.0f;
	}
	else
	{
		//just one row. We can center it.
		startAngle.yaw += (Max(1, noteCount - 1) / 2.0f) * ANGLE_INTERVALDELTA;
	}

	idAngles currentAngle = startAngle;

	//This is the starting height. This depends on how many rows of notes there are.
	idVec3 currentHeight = firstPersonViewOrigin + idVec3(0, 0, (ROWHEIGHT * rowCount) / 2.0f) + idVec3(0,0,ROWHEIGHT/-2);

	int noteIndex = 0;
	for (idEntity* ent = gameLocal.memorypalaceEntities.Next(); ent != NULL; ent = ent->memorypalaceNode.Next())
	{
		if (!ent)
			continue;

		if (!ent->IsType(idNoteWall::Type))
			continue;

		if (!static_cast<idNoteWall *>(ent)->IsMemorypalaceClone())
			continue;

		idVec3 notePos = currentHeight + (currentAngle.ToForward() * FORWARD_DISTANCE);
		ent->SetOrigin(notePos);

		idVec3 noteAngle = firstPersonViewOrigin - notePos;
		noteAngle.Normalize();
		ent->SetAxis(noteAngle.ToMat3());

		static_cast<idNoteWall *>(ent)->ShowMemoryPalace(true);		
		noteIndex++;

		if (noteIndex < NOTES_PER_ROW)
		{
			//continue current row.
			currentAngle.yaw -= ANGLE_INTERVALDELTA;
		}
		else
		{
			//new row.
			currentAngle = startAngle;
			currentHeight += idVec3(0, 0, -ROWHEIGHT);
			noteIndex = 0;
		}
	}
}


//This is so that we can manually trigger a zoom inspect elsewhere (not via zoominspect). Example: frobbing a tablet
void idPlayer::DoZoominspectEntity(idEntity *ent)
{
	if (ent == NULL)
		return;

	int currentTime = gameLocal.spectatePause ? gameLocal.hudTime : gameLocal.time;
	zoomFov.Init(currentTime, ZOOM_LERPTIME, CalcFov(false), this->zoomCurrentFOV);

	zoommodeActive = true;
	zoominspectEntityPtr = ent;
	zoomManualInspect = true;
	HandleZoomInspectPressFire();
}

bool idPlayer::DoInspectCurrentItem()
{
	//Check if we have a item selected.
	int currentWeapon = inventory.hotbarSlots[currentWeaponSlot].weaponType;
	if (currentWeapon <= 0)
	{
		if (!isInVignette)
		{
			StartSound("snd_error", SND_CHANNEL_ANY);
			SetCenterMessage("#str_def_gameplay_zoomlens_tap"); //display message to TAP the button, in the case that the player is holding it down with no weapon equipped
		}

		return false;
	}

	hud->SetStateBool("zoominspect_draw", false);

	iteminspectActive = true;
	InspectWeapon(true);

	zoommodeActive = false;
	zoomCurrentFOV = ZOOM_MAX;
	StartSound("snd_zoomin", SND_CHANNEL_ANY, 0, false, NULL);

	hud->SetStateBool("showzoomcontrols", false);
	hud->SetStateBool("playermoving", false); //don't draw teh static effect

	//Limit the view angles.
	SetViewYawLock(true, viewAngles.yaw, ITEMINSPECT_YAW_MAXDISTANCE);
	SetViewPitchLock(true, viewAngles.pitch, ITEMINSPECT_PITCH_MAXDISTANCE);

	// SW: vignette/scripting support
	idEntity* carryableEnt = carryableItem.GetEntity();
	if (carryableEnt)
	{
		idStr inspectFunc;
		if (carryableEnt->spawnArgs.GetString("callOnInspect", "", inspectFunc) && !inspectFunc.IsEmpty())
		{
			gameLocal.RunMapScript(inspectFunc);
		}

		//BC check if item inspect wants a custom FOV
		int customFOV = carryableEnt->spawnArgs.GetInt("inspect_fov");
		if (customFOV > 0)
		{
			iteminspectFOV = customFOV;
		}
		else
		{
			iteminspectFOV = DefaultFov();
		}

		HandleItemLocboxInspect(carryableEnt->spawnArgs);		
	}
	else if (weapon.GetEntity())
	{
		//BC check if item inspect wants a custom FOV
		int customFOV = weapon.GetEntity()->spawnArgs.GetInt("inspect_fov");
		if (customFOV > 0)
		{
			iteminspectFOV = customFOV;
		}
		else
		{
			iteminspectFOV = DefaultFov();
		}

		HandleItemLocboxInspect(weapon.GetEntity()->spawnArgs);
	}
	

	return true;
}

bool idPlayer::ShouldShowLocBox()
{
	if (g_locbox.GetInteger() <= 0)
	{
		//g_locbox cvar is set to ALWAYS OFF
		return false;
	}

	if (g_locbox.GetInteger() >= 2)
	{
		//g_locbox cvar is set to ALWAYS ON
		return true;
	}

	idStr langName = cvarSystem->GetCVarString("sys_lang");
	if (g_locbox.GetInteger() == 1 && langName == "english")
	{
		//g_locbox is set to AUTOMATIC but the language is english.
		return false;
	}

	//Set to automatic but language is NOT english.
	return true;
}

//Displays text in the localization box in the hud.
//Send it an empty string "" to make box disappear.
void idPlayer::DisplayLocbox(idStr _text)
{
	if (_text.Length() <= 0)
	{
		//hide the box.
		hud->SetStateInt("locboxvisible", 0);
		return;
	}

	//Do language check.	
	if (!ShouldShowLocBox())
	{
		return;
	}

	hud->SetStateInt("locboxvisible", 1);
	hud->SetStateString("locboxtext", common->GetLanguageDict()->GetString(_text.c_str()));
}

void idPlayer::HandleItemLocboxInspect(idDict& spawnargs)
{
	//Localization of object inspect.
	idStr inspectionText = spawnargs.GetString("loc_inspectiontext");
	if (inspectionText.Length() > 0)
	{
		//Found loc text for this object.
		DisplayLocbox(inspectionText);
	}
	else
	{
		//No loc text to display.
		DisplayLocbox("");
	}
}

void idPlayer::Event_DisplayCatBox(const char* name, const char* title, const char* blurb)
{
	this->DisplayCatBox(idStr(name), idStr(title), idStr(blurb));
}

void idPlayer::DisplayCatBox(idStr name, idStr title, idStr blurb)
{
	if (name.Length() <= 0 || title.Length() <= 0 || blurb.Length() <= 0)
	{
		//hide the box.
		hud->HandleNamedEvent("hideCatBox");
	}
	else
	{
		hud->SetStateString("catboxname", common->GetLanguageDict()->GetString(name.c_str()));
		hud->SetStateString("catboxtitle", common->GetLanguageDict()->GetString(title.c_str()));
		hud->SetStateString("catboxblurb", common->GetLanguageDict()->GetString(blurb.c_str()));
		hud->HandleNamedEvent("showCatBox");
	}
}

bool idPlayer::UpdateConfinedDust()
{
	if (gameLocal.time > confinedDustTimer && !peekObject.IsValid())
	{
		trace_t dustTr;
		idVec3 dustPos;
		bool isInTrigger;
		int attempts;

		attempts = 0;
		isInTrigger = false;
		#define DUST_PARTICLE_SPAWNINTERVAL 400
		confinedDustTimer = gameLocal.time + DUST_PARTICLE_SPAWNINTERVAL;

		//Attempt to spawn dust in front of player camera.

		//Find a candidate position.
		gameLocal.clip.TracePoint(dustTr, firstPersonViewOrigin, firstPersonViewOrigin + firstPersonViewAxis.ToAngles().ToForward() * 128, MASK_SOLID, this);

		#define MAX_DUST_PARTICLES 3
		for (int i = 0; i < MAX_DUST_PARTICLES; i++)
		{
			dustPos = dustTr.endpos;
			dustPos += idVec3(gameLocal.random.CRandomFloat() * 32, gameLocal.random.CRandomFloat() * 32, gameLocal.random.CRandomFloat() * 32);

			//Check if candidate position is inside a confined trigger.
			if (gameLocal.GetPositionIsInsideConfinedspace(dustPos))
			{
				isInTrigger = true;
			}

			if (isInTrigger)
				break;
		}

		if (isInTrigger)
		{
			gameLocal.DoParticle("dust_cloud32.prt", dustPos);
		}
		else
		{
			//Failed to find a spawn position for the dust.
			//Just spawn it directly in front of eyeballs.
			idVec3 frontOfEyes = firstPersonViewOrigin + firstPersonViewAxis.ToAngles().ToForward() * 16;

			for (idEntity* entity = gameLocal.confinedEntities.Next(); entity != NULL; entity = entity->confinedNode.Next())
			{
				if (!entity)
					continue;

				if (entity->GetPhysics()->GetAbsBounds().ContainsPoint(dustPos))
				{
					gameLocal.DoParticle("dust_cloud32.prt", frontOfEyes);
					break;
				}
			}
		}
	}	

	return true;
}

bool idPlayer::IsCurrentlySeenByAI()
{
	for (idEntity *actor = gameLocal.aimAssistEntities.Next(); actor != NULL; actor = actor->aimAssistNode.Next())
	{
		if (!actor)
			continue;

		if (actor->IsHidden() || actor->health <= 0 || !actor->IsType(idAI::Type))
			continue;

		if (static_cast<idAI*>(actor)->team != TEAM_ENEMY)
			continue;

		if (!static_cast<idAI *>(actor)->CanAcceptStimulus())
			continue;

		//Ignore if ai is in non-combat state with zero suspicion
		if (static_cast<idAI*>(actor)->aiState == AISTATE_IDLE || static_cast<idAI*>(actor)->aiState == AISTATE_SUSPICIOUS)
		{
			if (actor->IsType(idGunnerMonster::Type))
			{
				if (static_cast<idGunnerMonster*>(actor)->GetSuspicionCounter() <= 0)
					continue;
			}
		}

		if (static_cast<idAI *>(actor)->CanSee(gameLocal.GetLocalPlayer(), true))
		{
			//ai sees player.
			return true;
		}
	}

	return false;
}

bool idPlayer::isInZoomMode()
{
	return (zoommodeActive && !zoominspect_LabelmodeActive && !iteminspectActive);
}

bool idPlayer::isInLabelInspectMode()
{
	return (zoominspect_LabelmodeActive == true);
}

void idPlayer::SetDrawIngressPoints(bool value)
{
	ingresspointsDrawActive = value;


}

#endif

bool idPlayer::Event_IsAirless(void)
{
	idThread::ReturnInt(airless);
	return airless;
}

void idPlayer::UpdateGrenadethrowStamina()
{
    if (grenadeThrowState == GRENADETHROW_AIMING && gameLocal.hudTime > staminaThrowTimer && grenadeButtonTimer > 0 && (gameLocal.time - grenadeButtonTimer) > GRENADE_THROW_HOLDTIME)
    {
        staminaThrowTimer = gameLocal.hudTime + STAMINABAR_THROW_TIMEINTERVAL;

        if (stamina > 0)
        {
			//Use up some stamina.
            SetStaminaDelta(-1);
        }
        else
        {
			//All stamina depleted.

            staminaChargeDelayTimer = gameLocal.time;

            if (gameLocal.slowmoState == SLOWMO_STATE_ON || gameLocal.slowmoState == SLOWMO_STATE_RAMPUP)
            {
                //kick out of slow mo.
                gameLocal.SetSlowmo(false);
                hud->HandleNamedEvent("no_stamina");
            }
        }
    }
}

void idPlayer::PlayerLanded()
{
	//player landed from a stepping off a ledge, etc

	if (cond_bulletwound <= 0)
		return; //no wound. exit here.

	//player has wound. Do yelp.
	StartSound("snd_pain", SND_CHANNEL_VOICE, 0, false, NULL);
	hud->HandleNamedEvent("cond_bulletdamage"); //make the bulletwound icon do a flash.
	gameLocal.SpawnInterestPoint(this, this->GetEyePosition() + idVec3(0,0,-4), "interest_playerpain");	
}

void idPlayer::DebugPlayerConnectedArea()
{
	trace_t tr;
	gameLocal.clip.TracePoint(tr, firstPersonViewOrigin, firstPersonViewOrigin + viewAngles.ToForward() * 512, MASK_SHOT_RENDERMODEL, NULL);
	if (tr.c.entityNum <= MAX_GENTITIES - 2 && tr.c.entityNum >= 0)
	{
		idEntity* ent = gameLocal.entities[tr.c.entityNum];
		bool result = gameLocal.InPlayerAreasRecalculated(ent);
		common->Printf("InPlayerConnectedArea: '%s' = %s\n", gameLocal.entities[tr.c.entityNum]->GetName(), result ? "true" : "false");

		gameRenderWorld->DebugBounds(result ? colorGreen : colorRed, ent->GetPhysics()->GetBounds(), ent->GetPhysics()->GetOrigin(), 1000);
	}

}

//We want the player to say VO, but we don't want the event to happen every single time.
//So we have a hash table that maintains a record of when a soundcue was last played.
bool idPlayer::SayVO_WithIntervalDelay(const char *sndName)
{
	if (sndName == NULL)
		return false;

	if (sndName[0] == '\0')
		return false;

	//TODO: time intervals are hardcoded, this should be data driven
	#define VO_DELAYINTERVALMIN 15000
	#define VO_DELAYINTERVALMAX 20000

	int* lastValPtr = nullptr;
	if (!voIntervalTable.Get(sndName, &lastValPtr))
	{
		//key doesn't exist. Create it.
		voIntervalTable.Set(sndName, gameLocal.time);
	}
	else
	{
		//The key does exist. See if it's a valid time to play it.
		int lastSpeakTime = lastValPtr[0];

		if (gameLocal.time < lastSpeakTime)
			return false; //Cooldown timer hasn't expired yet. Exit here.
	}
	
	bool playedVO = gameLocal.voManager.SayVO(this, sndName, VO_CATEGORY_BARK);
	if (playedVO)
	{
		int nextSpeakTime = gameLocal.time + gameLocal.random.RandomInt(VO_DELAYINTERVALMIN, VO_DELAYINTERVALMAX);
		voIntervalTable.Set(sndName, nextSpeakTime); //reset the cooldown timer for this soundcue.
		return true; //successfully played VO.
	}

	return false; //Didn't play VO.
}

void idPlayer::SayVO_WithIntervalDelay_msDelayed(const char *sndName, int msDelay)
{
	PostEventMS(&EV_Player_DelayedVO_WithInterval, msDelay, sndName);
}

//Handle vo when player picks up an item.
void idPlayer::JustPickedupItem(idEntity* ent)
{
	idStr voName = "snd_vo_pickup";

	idStr customVo = ent->spawnArgs.GetString("vo_playerpickup"); //if an entity has a keyvalue 'vo_playerpickup', then use it for a custom pickup sound.
	if (customVo.Length() > 0)
	{
		voName = customVo;
	}

	gameLocal.GetLocalPlayer()->SayVO_WithIntervalDelay_msDelayed(voName.c_str(), 200);
}

//This returns the DISPLAY NAME of the map (not filename)
void idPlayer::Event_GetNextMapName()
{
	int num = declManager->GetNumDecls(DECL_MAPDEF);
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (mapDef && mapDef->dict.GetInt("levelindex") == (levelProgressIndex + 1))
		{
			//Found it.
			idStr output = common->GetLanguageDict()->GetString(mapDef->dict.GetString("name"));
			idThread::ReturnString(output.c_str());
			return;
		}
	}

	idThread::ReturnString(""); //error........
}

void idPlayer::Event_GetIsNextmapShip()
{
	idStr nextmapfilename = GetNextMap();

	if (nextmapfilename.Length() <= 0)
	{
		idThread::ReturnInt(0);
		return;
	}

	nextmapfilename.StripPath();
	if (nextmapfilename.Find("sh_", false) == 0)
	{
		idThread::ReturnInt(1); //is a ship.
		return;
	}

	idThread::ReturnInt(0);
}

//This returns the maps.def DESCRIPTION of the map
void idPlayer::Event_GetNextMapDesc()
{
	int num = declManager->GetNumDecls(DECL_MAPDEF);
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (mapDef && mapDef->dict.GetInt("levelindex") == (levelProgressIndex + 1))
		{
			//Found it.
			idStr output = common->GetLanguageDict()->GetString(mapDef->dict.GetString("description"));
			idThread::ReturnString(output.c_str());
			return;
		}
	}

	idThread::ReturnString(""); //error........
}

//This is for level progression. When in the hub, we need to know what gameplay level do we load up next. This returns the string name of the next map to load.
idStr idPlayer::GetNextMap()
{
	//Search the mapdefs.
	int num = declManager->GetNumDecls(DECL_MAPDEF);
	for (int i = 0; i < num; i++)
	{
		const idDeclEntityDef* mapDef = static_cast<const idDeclEntityDef*>(declManager->DeclByIndex(DECL_MAPDEF, i));
		if (mapDef && mapDef->dict.GetInt("levelindex") == (levelProgressIndex + 1))
		{
			//Found it.
			return mapDef->GetName();
		}
	}

	gameLocal.Warning("GetNextMap: unable to find map with correct levelindex (%d)\n", levelProgressIndex + 1);
	return "";
}

void idPlayer::Event_GetNextMap()
{
	idThread::ReturnString(GetNextMap().c_str());
}

void idPlayer::Event_GetMapIndex()
{
	idThread::ReturnInt(levelProgressIndex);
}

bool idPlayer::CanZoom()
{
	//When is zoom allowed.

	//don't allow shift-inspectzoom during telescope
	if (peekObject.IsValid())
	{
		if (static_cast<idVentpeek*>(peekObject.GetEntity())->forTelescope)
		{
			return false;
		}
	}

	return (jockeyState == JCK_INACTIVE && !contextMenuActive && !zoominspect_LabelmodeActive && !iteminspectActive && (memorypalaceState == MEMP_NONE) && !isInVignette && !spectating && grenadeThrowState == GRENADETHROW_IDLE && mechTransitionState == MECHTRANSITION_NONE && armstatsState == ARMST_DORMANT);
}

void idPlayer::Event_SetFallDamageImmune(int status)
{
	isFallDamageImmune = (bool)status;
}

void idPlayer::Event_IsBurning(void)
{
	idThread::ReturnFloat(GetOnFire());
}

void idPlayer::Event_IsDowned(void)
{
	idThread::ReturnFloat(inDownedState);
}

void idPlayer::EnemyHasRespawned()
{
	enemyrespawns++;
}

void idPlayer::Event_SetJockeyMode(float toggle, idEntity* target)
{
	if (toggle)
	{
		if (target && target->IsType(idAI::Type))
		{
			meleeTarget = static_cast<idAI*>(target);
			SetJockeyMode(true);
		}
		else
		{
			gameLocal.Warning("Script event setJockeyMode attempted to jockey something that is not an AI (%s)", target ? target->GetName() : "NULL");
			SetJockeyMode(false);
		}
	}
	else
	{
		SetJockeyMode(false);
	}
}

void idPlayer::Event_GetLocationLocID()
{
	idLocationEntity* locationEntity = gameLocal.LocationForPoint(GetEyePosition());

	if (locationEntity == nullptr)
	{
		idThread::ReturnString("");
		return;
	}	

	idStr _locID = locationEntity->locID;

	if (_locID.Length() <= 0)
	{
		gameLocal.Warning("Event_GetLocationLocID: no location ID found. String not localized? (%s).", locationEntity->GetName());
	}

	idThread::ReturnString(_locID.c_str());
}

void idPlayer::Event_ForceDuck(int value)
{
	if (health <= 0)
		return;

	if (value)
	{
		//Force duck.
		physicsObj.ForceDuck(0);
		teleportCrouchTime = gameLocal.time;

		// play crouch animation immediately to prevent animation flicker
		//AI_CROUCH = true;
		SetAnimState(ANIMCHANNEL_TORSO,"Torso_Crouch", 0);
		SetAnimState(ANIMCHANNEL_LEGS,"Legs_Crouch", 0);

		if (in_toggleCrouch.GetBool())
		{
			toggleCrouch = true;
		}
	}
	else
	{
		//Force unduck.
		physicsObj.ForceUnduck();

		if (in_toggleCrouch.GetBool())
		{
			toggleCrouch = false;
		}
	}
		
}

void idPlayer::Event_IsEntityLostInSpace(const char* entityDefName)
{
	idThread::ReturnInt(IsEntityLostInSpace(entityDefName));
}


void idPlayer::SetROQVideoState(int value)
{
	roqVideoStateActive = (value > 0) ? true : false;
}

bool idPlayer::GetROQVideoStateActive()
{
	return roqVideoStateActive;
}

// SW: Enables/disables the player's "vignette" state. This disables various HUD elements and systems that are present in the ship levels.
// Normally you could just enable this with the 'vignette' worldspawn arg, but in some cases (i.e. VR missions in the hub) we need to enable/disable it on the fly.
void idPlayer::Event_SetVignetteMode(int value)
{
	isInVignette = (bool)value;
	UpdateHudVignetteState(isInVignette);
}

void idPlayer::Event_GetVignetteMode()
{
	idThread::ReturnFloat(isInVignette);
}

// Enables/disables HUD elements based on whether we are in a vignette or not
void idPlayer::UpdateHudVignetteState(bool isVignette)
{
	//during vignette, make the crosshair behave differently (turn off stealth info)
	if (isVignette) 
	{
		hud->HandleNamedEvent("onEnterVignette");
	}
	else 
	{
		hud->HandleNamedEvent("onExitVignette");
	}
	

	for (int i = 0; i < MAX_HOTBARSLOTS; i++)
	{
		hud->SetStateBool(va("hotbarvisible%d", i), isVignette ? 0 : 1); //in vignette, hide inventory.
	}
}

void idPlayer::Event_DropInventoryItem(const char* inventoryItemName)
{
	//stub for dropping an item in the player inventory.
	common->Printf("drop... %s\n", inventoryItemName);
}

bool idPlayer::IsReadableRead(idEntity* ent)
{
	if (ent->IsType(idNoteWall::Type))
	{
		if (static_cast<idNoteWall*>(ent)->GetRead())
		{
			return true;
		}
	}

	if (ent->IsType(idTablet::Type))
	{
		if (static_cast<idTablet*>(ent)->GetRead())
		{
			return true;
		}
	}

	return false;
}

//Play a sound wave that's attached to the front of the player. This is used to communicate the player is making a sound.
void idPlayer::DoLocalSoundwave(idStr particlename)
{
	idVec3 forward, up;
	viewAngles.ToVectors(&forward, NULL, &up);
	idVec3 particlePos = firstPersonViewOrigin + (forward * 4) + (up * -4);
	idEntity* particle = gameLocal.DoParticle(particlename.c_str(), particlePos);
	if (particle)
	{
		jointHandle_t headjoint = animator.GetJointHandle("camera");
		if (headjoint != INVALID_JOINT)
		{
			particle->BindToJoint(this, headjoint, false);
		}
	}
}

//This is whether we consider the player "injured" or not.
bool idPlayer::GetInjured()
{
	return (GetWoundCount() > 0);
}

void idPlayer::DoExitZoomMode()
{
	//Exit zoom mode.
	zoomFov.Init(gameLocal.time, ZOOM_LERPTIME, zoomFov.GetCurrentValue(gameLocal.time), DefaultFov()); //Reset fov to default.
	zoommodeActive = false;
	StartSound("snd_zoomout", SND_CHANNEL_ANY, 0, false, NULL);
}

void idPlayer::Event_SetTitleFlyMode(int value)
{
	if (value >= 1)
		isTitleFlyMode = true;
	else
		isTitleFlyMode = false;
}

void idPlayer::Event_ResetMaterialTimer(const char* materialName)
{
	const idMaterial* material;
	material = declManager->FindMaterial(materialName);
	material->ResetCinematicTime(0);
}

void idPlayer::Event_ParticleStream(const char* particlename, const idVec3 &destination, int duration)
{
	particleStreamDestination = destination;
	particlestreamTimer = gameLocal.time + duration;

	particleStreamEnt = gameLocal.DoParticle(particlename, vec3_origin);
}

void idPlayer::Event_SetPlayerBody(int value)
{
	showPlayerBody_Scripted = (value > 0) ? true : false;
}

void idPlayer::Event_ForceSpatterFx(int enable, float amount)
{
	doForceSpatter = (bool)enable;
	forceSpatterAmount = idMath::ClampFloat(0, 1, amount);
}

void idPlayer::UnsetToggleCrouch()
{
	if(toggleCrouch)
	{
		toggleCrouch = false;
		usercmd.buttonState[UB_DOWN] = 0;
		usercmd.buttonState[UB_UP] = 0;
		usercmd.upmove = 0;
	}
}

void idPlayer::PickupTape(int tapeNumber)
{
	tapesCollected.AddUnique(tapeNumber);
}

void idPlayer::Event_IsFullscreenUIActive(void)
{
	idThread::ReturnFloat( (float) (IsFullscreenUIActive()) );
}

void idPlayer::Event_SetDefibAvailable(int value)
{
	this->SetDefibAvailable((bool)value);
}

void idPlayer::Event_SetCinematicHUD(int value)
{
	this->drawCinematicHUD = value;
}

// SW 11th Feb 2025: turns heartbeat audio effect on/off
void idPlayer::Event_EnableHeartBeat(int value)
{
	heartbeatEnabled = (bool)value;
}
