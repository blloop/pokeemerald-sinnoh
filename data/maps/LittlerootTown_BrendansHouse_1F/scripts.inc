.set LOCALID_MOM, 1

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomMessage
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox LittlerootTown_BrendansHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_Mom::
	lock
	faceplayer
	msgbox LittlerootTown_BrendansHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	goto LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty::
	msgbox LittlerootTown_BrendansHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox LittlerootTown_BrendansHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
	release
	end

@ LittlerootTown_BrendansHouse_1F_EventScript_SeeYouHoney::
@ msgbox LittlerootTown_BrendansHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT

PlayerHouse_1F_EventScript_RunningShoesManual::
	msgbox LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual, MSGBOX_DEFAULT
	release
	end

LittlerootTown_BrendansHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

LittlerootTown_BrendansHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

LittlerootTown_BrendansHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

LittlerootTown_BrendansHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

LittlerootTown_BrendansHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

LittlerootTown_BrendansHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

LittlerootTown_BrendansHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

LittlerootTown_BrendansHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

@ -----------------------------------------
@ -----------------------------------------
@ -----------------------------------------
@ -----------------------------------------
@ -----------------------------------------
@ -----------------------------------------
@ -----------------------------------------
@ -----------------------------------------

LittlerootTown_BrendansHouse_1F_EventScript_MomMessage::
	lockall
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	applymovement LOCALID_MOM, MomTalk_A
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_EventScript_Mom_Text
	applymovement LOCALID_MOM, MomTalk_B
	waitmovement 0
	releaseall
	return

LittlerootTown_BrendansHouse_1F_Trigger_Exit::
	lockall
	applymovement LOCALID_MOM, FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Trigger_Mom_Text
	releaseall
	return

MomTalk_A:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

MomTalk_B:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	face_up
	step_end

FaceDown:
	face_down
	step_end

FaceUp:
	face_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_Mom_Text:
	.string "Mom: {PLAYER}!\p"
	.string "{RIVAL} came calling for you a little\n"
	.string "while ago.\p"
	.string "I don't know what it was about, but he\n"
	.string "said it was an emergency.$"

LittlerootTown_BrendansHouse_1F_Trigger_Mom_Text:
	.string "Mom: Oh yes! {PLAYER}!\p"
	.string "Don't go into the tall grass. Wild\n"
	.string "Pokemon might attack you.\p"
	.string "It would be OK if you had your own\n"
	.string "Pokemon, but you don't so...$"
