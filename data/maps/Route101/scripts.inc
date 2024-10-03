.set LOCALID_RIVAL, 1

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	end

Route101_OnFrame:
	.2byte 0

Route101_EventScript_RivalSee1::
	setvar VAR_0x8004, 1
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee2::
	setvar VAR_0x8004, 2
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee3::
	setvar VAR_0x8004, 3
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee4::
	setvar VAR_0x8004, 4
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee::
	lock
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8004, 1, Route101_EventScript_RivalShift1
	call_if_eq VAR_0x8004, 2, Route101_EventScript_RivalShift2
	call_if_eq VAR_0x8004, 4, Route101_EventScript_RivalShift4
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	msgbox Route101_Text_RivalMeet, MSGBOX_DEFAULT
	closemessage
	loadword 0 Route101_EventScript_Rival
	setfollower LOCALID_RIVAL 0x100
	release
	end

Route101_EventScript_RivalShift1::
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	return

Route101_EventScript_RivalShift2::
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	return

Route101_EventScript_RivalShift4::
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	return

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_Rival::
	msgbox Route101_Text_RivalTalk, MSGBOX_SIGN
	end

Route101_Text_RouteSign:
	.string "{DOWN_ARROW} R.201\n"
	.string "     Twinleaf Town$"

Route101_Text_RivalMeet:
	.string "{RIVAL}: Hey you saw that news\n"
	.string "report that was on TV, right?\p"
	.string "You know, 'Search for the Red\n"
	.string "GYARADOS! The mysterious appearance\l"
	.string "of the furious Pokemon in a lake!'\p"
	.string "That show got me to thinking.\p"
	.string "I'll bet our local lake has a Pokemon\n"
	.string "like that in it, too!\p"
	.string "So that's what we're gonna do.\n"
	.string "We'll go find a Pokemon like that!$"

Route101_Text_RivalTalk:
	.string "Hey! I'm following you$"
