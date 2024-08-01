Route102_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route102_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ROUTE102_OnLoad
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_OnTransition::
	setflag FLAG_ROUTE102_HIDE_POOCHYENA
	compare VAR_GRUNT_AQUA, 2
	goto_if_ne Route102_OnTransition_2
	clearflag FLAG_ROUTE102_HIDE_GRUNT2
Route102_OnTransition_1:
	end

Route102_OnTransition_2:
	setflag FLAG_ROUTE102_HIDE_GRUNT2
	goto Route102_OnTransition_1


ROUTE102_OnLoad::
	compare VAR_ROUTE102_WATERFALL, 1
	goto_if_eq ROUTE102_OnLoad_2
ROUTE102_OnLoad_1:
	compare VAR_ROUTE102_STATE, 0
	goto_if_eq ROUTE102_OnLoad_5
ROUTE102_OnLoad_4:
	end

ROUTE102_OnLoad_2:
	call Route102_Waterfall_SecretPassageOpened
	goto ROUTE102_OnLoad_1

ROUTE102_OnLoad_5:
	call Route102_DoorLocked
	goto ROUTE102_OnLoad_4


Route102_Eventscript_Trigger_Poochyena::
	compare VAR_WILD_POOCHYENA, 2
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_1
	return

Route102_Eventscript_Trigger_Poochyena_1:
	lockall
	playse SE_EXIT
	clearflag FLAG_ROUTE102_HIDE_POOCHYENA
	addobject 10
	waitse
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	compare VAR_TEMP_1, 4
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_13
Route102_Eventscript_Trigger_Poochyena_11:
	compare VAR_TEMP_1, 3
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_10
Route102_Eventscript_Trigger_Poochyena_8:
	compare VAR_TEMP_1, 2
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_7
Route102_Eventscript_Trigger_Poochyena_3:
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	waitmoncry
	waitmovement 10
	setvar VAR_WILD_POOCHYENA, 3
	setflag FLAG_ROUTE102_HIDE_POOCHYENA
	setwildbattle SPECIES_POOCHYENA, 10, ITEM_BLACK_GLASSES
	dowildbattle
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_17
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_18
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_19
Route102_Eventscript_Trigger_Poochyena_16:
	waitmessage
	releaseall
	return

Route102_Eventscript_Trigger_Poochyena_4:
	applymovement 10, Route102_Poochyena_Attack_right
	goto Route102_Eventscript_Trigger_Poochyena_3

Route102_Eventscript_Trigger_Poochyena_5:
	applymovement 10, Route102_Poochyena_Attack_middle
	goto Route102_Eventscript_Trigger_Poochyena_3

Route102_Eventscript_Trigger_Poochyena_6:
	applymovement 10, Route102_Poochyena_Attack_left
	goto Route102_Eventscript_Trigger_Poochyena_3

Route102_Eventscript_Trigger_Poochyena_7:
	compare VAR_TEMP_2, 19
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_6
	goto Route102_Eventscript_Trigger_Poochyena_3

Route102_Eventscript_Trigger_Poochyena_10:
	compare VAR_TEMP_2, 19
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_5
	goto Route102_Eventscript_Trigger_Poochyena_8

Route102_Eventscript_Trigger_Poochyena_13:
	compare VAR_TEMP_2, 19
	goto_if_eq Route102_Eventscript_Trigger_Poochyena_4
	goto Route102_Eventscript_Trigger_Poochyena_11

Route102_Eventscript_Trigger_Poochyena_17:
	call Route102_Poochyena_Caught
	goto Route102_Eventscript_Trigger_Poochyena_16

Route102_Eventscript_Trigger_Poochyena_18:
	call Route102_Poochyena_Won_or_RanAway
	goto Route102_Eventscript_Trigger_Poochyena_16

Route102_Eventscript_Trigger_Poochyena_19:
	call Route102_Poochyena_Won_or_RanAway
	goto Route102_Eventscript_Trigger_Poochyena_16


Route102_Poochyena_Caught::
	lockall
	fadescreen FADE_TO_BLACK
	removeobject 10
	fadescreen FADE_FROM_BLACK
	return


Route102_Poochyena_Won_or_RanAway::
	playse SE_PIN
	delay 20
	applymovement 10, Route102_Poochyena_Exclamation
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	msgbox Route102_Poochyena_Won_or_RanAway_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	compare VAR_TEMP_1, 4
	goto_if_eq Route102_Poochyena_Won_or_RanAway_11
Route102_Poochyena_Won_or_RanAway_9:
	compare VAR_TEMP_1, 3
	goto_if_eq Route102_Poochyena_Won_or_RanAway_8
Route102_Poochyena_Won_or_RanAway_6:
	compare VAR_TEMP_1, 2
	goto_if_eq Route102_Poochyena_Won_or_RanAway_5
Route102_Poochyena_Won_or_RanAway_1:
	waitmovement 0
	playse SE_EXIT
	delay 10
	removeobject 10
	waitse
	return

Route102_Poochyena_Won_or_RanAway_2:
	applymovement 10, Route102_Poochyena_Escape_right
	goto Route102_Poochyena_Won_or_RanAway_1

Route102_Poochyena_Won_or_RanAway_3:
	applymovement 10, Route102_Poochyena_Escape_middle
	goto Route102_Poochyena_Won_or_RanAway_1

Route102_Poochyena_Won_or_RanAway_4:
	applymovement 10, Route102_Poochyena_Escape_left
	goto Route102_Poochyena_Won_or_RanAway_1

Route102_Poochyena_Won_or_RanAway_5:
	compare VAR_TEMP_2, 19
	goto_if_eq Route102_Poochyena_Won_or_RanAway_4
	goto Route102_Poochyena_Won_or_RanAway_1

Route102_Poochyena_Won_or_RanAway_8:
	compare VAR_TEMP_2, 19
	goto_if_eq Route102_Poochyena_Won_or_RanAway_3
	goto Route102_Poochyena_Won_or_RanAway_6

Route102_Poochyena_Won_or_RanAway_11:
	compare VAR_TEMP_2, 19
	goto_if_eq Route102_Poochyena_Won_or_RanAway_2
	goto Route102_Poochyena_Won_or_RanAway_9


Route102_SignPost_PoochyenaHole::
	msgbox Route102_SignPost_PoochyenaHole_Text_0, MSGBOX_AUTOCLOSE
	end


Route102_SignPost_Waterfall::
	compare VAR_ROUTE102_WATERFALL, 0
	goto_if_eq Route102_SignPost_Waterfall_2
	msgbox Route102_SignPost_Waterfall_Text_2, MSGBOX_AUTOCLOSE
Route102_SignPost_Waterfall_1:
	end

Route102_SignPost_Waterfall_2:
	msgbox Route102_SignPost_Waterfall_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route102_SignPost_Waterfall_5
	msgbox Route102_SignPost_Waterfall_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	goto Route102_SignPost_Waterfall_1

Route102_SignPost_Waterfall_5:
	closemessage
	call Route102_FallingStoneAnimation
	goto Route102_SignPost_Waterfall_1


Route102_FallingStoneAnimation::
	playse SE_FALL
	delay 35
	setmetatile 29, 1, 0x1A2, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 1, 0x06C, TRUE
	setmetatile 29, 2, 0x1A2, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 2, 0x093, TRUE
	setmetatile 29, 3, 0x1A2, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 3, 0x09B, TRUE
	setmetatile 29, 4, 0x1A2, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 4, 0x07C, TRUE
	setmetatile 29, 5, 0x13F, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 5, 0x180, TRUE
	setmetatile 29, 6, 0x13F, TRUE
	special DrawWholeMapView
	playse SE_M_WATERFALL
	delay 5
	setmetatile 29, 7, 0x09F, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 8, 0x0A7, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 9, 0x071, FALSE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 10, 0x07C, TRUE
	special DrawWholeMapView
	delay 5
	setmetatile 29, 11, 0x189, FALSE
	special DrawWholeMapView
	setvar VAR_ROUTE102_WATERFALL, 1
	return


Route102_Waterfall_SecretPassageOpened::
	setmetatile 29, 6, 0x13F, TRUE
	setmetatile 29, 7, 0x09F, TRUE
	setmetatile 29, 8, 0x0A7, TRUE
	setmetatile 29, 9, 0x071, FALSE
	setmetatile 29, 10, 0x07C, TRUE
	setmetatile 29, 11, 0x189, TRUE
	special DrawWholeMapView
	return


Route102_EventScript_Grunt1::
	lockall
	compare VAR_GRUNT_AQUA, 0
	goto_if_eq Route102_EventScript_Grunt1_2
Route102_EventScript_Grunt1_1:
	faceplayer
	trainerbattle_single TRAINER_GRUNT_ROUTE102, Grunt_Route102_Intro, Grunt_Route102_Outro, Route102_EventScript_GruntBeaten
	call Route102_EventScript_GruntBeaten
	waitmessage
	releaseall
	end

Route102_EventScript_Grunt1_2:
	msgbox Grunt_Route102_Prebattle, MSGBOX_AUTOCLOSE
	delay 20
	faceplayer
	playse SE_PIN
	applymovement 11, Route102_Grunt_Exclamation
	goto Route102_EventScript_Grunt1_1


Route102_EventScript_GruntBeaten::
	msgbox Grunt_Route102_PostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement 11, Route102_Grunt1_TurnAround
	setvar VAR_GRUNT_AQUA, 1
	return


Route102_EventScript_TriggerGrunts::
	lockall
	applymovement 11, Route102_Trigger_Grunt1_TurnLeft
	applymovement 12, Route102_Trigger_Grunt2_TurnRight
	delay 20
	applymovement 12, Route102_Trigger_Grunt2_WalkInPlaceRight
	waitmovement 12
	msgbox Route102_Trigger_Grunt2_talk, MSGBOX_AUTOCLOSE
	applymovement 11, Route102_Trigger_Grunt1_WalkInPlaceLeft
	waitmovement 11
	msgbox Route102_Trigger_Grunt1_talk, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 11, Route102_Trigger_Grunts_TurnAround
	applymovement 12, Route102_Trigger_Grunts_TurnAround
	playse SE_PIN
	delay 20
	applymovement 11, Route102_Grunt_Exclamation
	applymovement 12, Route102_Grunt_Exclamation
	waitmovement 11
	waitmovement 12
	msgbox Route102_Trigger_Grunts_talk, MSGBOX_AUTOCLOSE
	applymovement 11, Route102_Trigger_Grunt1_EscapePart1
	applymovement 12, Route102_Trigger_Grunt2_EscapePart1
	waitmovement 11
	waitmovement 12
	applymovement OBJ_EVENT_ID_PLAYER, Route102_Player_BackUp
	applymovement 11, Route102_Trigger_Grunt1_EscapePart2
	applymovement 12, Route102_Trigger_Grunt2_EscapePart2
	waitmovement 11
	waitmovement 12
	setvar VAR_GRUNT_AQUA, 3
	setflag FLAG_ROUTE102_HIDE_GRUNT1
	setflag FLAG_ROUTE102_HIDE_GRUNT2
	removeobject 11
	removeobject 12
	delay 20
	releaseall
	end


Route102_EventScript_LockedDoor::
	lockall
	checkitem ITEM_LOCKPICK, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_LockedDoor_2
	msgbox LockedDoor
Route102_EventScript_LockedDoor_1:
	releaseall
	end

Route102_EventScript_LockedDoor_2:
	compare VAR_ROUTE102_STATE, 0
	goto_if_eq Route102_EventScript_LockedDoor_5
	msgbox Route102_EventScript_LockedDoor_Text_1
	goto Route102_EventScript_LockedDoor_1

Route102_EventScript_LockedDoor_5:
	msgbox LockedDoor
	msgbox Route102_EventScript_LockedDoor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route102_EventScript_LockedDoor_8
	goto Route102_EventScript_LockedDoor_1

Route102_EventScript_LockedDoor_8:
	call Route102_PickLock
	goto Route102_EventScript_LockedDoor_1


Route102_PickLock::
	setvar VAR_ROUTE102_STATE, 1
	playse SE_CLICK
	waitse
	msgbox Route102_PickLock_Text_0
	waitmessage
	call Route102_DoorOpened
	return


Route102_DoorLocked::
	setmetatile 43, 20, 0x290, TRUE
	special DrawWholeMapView
	return


Route102_DoorOpened::
	setmetatile 43, 20, 0x021, FALSE
	special DrawWholeMapView
	return


Route102_Poochyena_Exclamation:
	emote_exclamation_mark
	step_end

Route102_Poochyena_Attack_right:
	walk_down
	walk_down
	walk_down
	step_end

Route102_Poochyena_Attack_middle:
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

Route102_Poochyena_Attack_left:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route102_Poochyena_Escape_right:
	walk_in_place_fast_up
	walk_up
	walk_up
	walk_up
	step_end

Route102_Poochyena_Escape_middle:
	walk_in_place_fast_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

Route102_Poochyena_Escape_left:
	walk_in_place_fast_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

Route102_Grunt_Exclamation:
	emote_exclamation_mark
	step_end

Route102_Trigger_Grunt1_TurnLeft:
	face_left
	step_end

Route102_Trigger_Grunt2_TurnRight:
	face_right
	step_end

Route102_Trigger_Grunt2_WalkInPlaceRight:
	walk_in_place_right
	step_end

Route102_Trigger_Grunt1_WalkInPlaceLeft:
	walk_in_place_left
	step_end

Route102_Grunt1_TurnAround:
	face_up
	step_end

Route102_Trigger_Grunts_TurnAround:
	face_down
	step_end

Route102_Trigger_Grunt1_EscapePart1:
	walk_fast_down
	walk_fast_down
	step_end

Route102_Trigger_Grunt2_EscapePart1:
	walk_fast_right
	walk_fast_down
	step_end

Route102_Player_BackUp:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

Route102_Trigger_Grunt1_EscapePart2:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route102_Trigger_Grunt2_EscapePart2:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route102_Poochyena_Won_or_RanAway_Text_0:
	.string "POOOOCH!$"

Route102_SignPost_PoochyenaHole_Text_0:
	.string "This is a Poochyena hole.$"

Route102_SignPost_Waterfall_Text_0:
	.string "There is a hole in the wall.\nWanna stick your hand inside?$"

Route102_SignPost_Waterfall_Text_1:
	.string "Didn't stick your hand inside.$"

Route102_SignPost_Waterfall_Text_2:
	.string "You must have activated a\nhidden machanism.$"

Route102_EventScript_LockedDoor_Text_0:
	.string "Wanna try to pick the lock?$"

Route102_EventScript_LockedDoor_Text_1:
	.string "The door got picked.$"

Route102_PickLock_Text_0:
	.string "The lock gave in.$"

Grunt_Route102_Prebattle::
	.string "Mhh, this might be the ideal\nplace...$"

Grunt_Route102_Intro::
	.string "Hey! what are you snooping\naround here?\pYou are gonna suffer kid!$"

Grunt_Route102_Outro::
	.string "WTF?! What kinda kid are you?$"

Grunt_Route102_PostBattle::
	.string "Piss off, I got things to do here.$"

Route102_Trigger_Grunt2_talk::
	.string "Is everything set up?$"

Route102_Trigger_Grunt1_talk::
	.string "Yes, I am done here.$"

Route102_Trigger_Grunts_talk::
	.string "Ohhh no! Not this kid again!\nLet's get out of here!$"
