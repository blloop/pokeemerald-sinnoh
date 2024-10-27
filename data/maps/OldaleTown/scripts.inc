.set LOCALID_HELPER, 1
.set LOCALID_RIVAL, 2

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

	@ State descriptions for VAR_OLDALE_TOWN_STATE
	@ 1: Entered initial lab scene

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	end

OldaleTown_EventScript_HelperLab1::
	lock
	special SpawnCameraObject
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper6
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player1
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player1
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab2::
	lock
	special SpawnCameraObject
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper2
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper7
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player2
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player2
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab3::
	lock
	special SpawnCameraObject
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper3
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper8
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player3
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player3
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab4::
	lock
	special SpawnCameraObject
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper9
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player4
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player4
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab5::
	lock
	special SpawnCameraObject
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper10
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player5
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player5
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_Movement_Helper1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_up
	step_end

OldaleTown_Movement_Helper2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

OldaleTown_Movement_Helper3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OldaleTown_Movement_Helper4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

OldaleTown_Movement_Helper5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_down
	step_end

OldaleTown_Movement_Helper6:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper7:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper8:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
OldaleTown_Movement_Helper9:
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper10:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player3:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player4:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player5:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_EventScript_HelperExclaim::
	playse SE_PIN
	applymovement LOCALID_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

OldaleTown_EventScript_HelperTalk1::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_HelperSay1
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_HelperSay2
	return

OldaleTown_EventScript_HelperSay1::
	msgbox OldaleTown_Text_HelperSay1, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperSay2::
	msgbox OldaleTown_Text_HelperSay2, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperToLab::
	special RemoveCameraObject
	release
	end

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_Text_HelperSay1:
	.string "Dawn: Oh! There you are!\n"
	.string "Please, come with me!\l"
	.string "The professor is waiting!$"

OldaleTown_Text_HelperSay2:
	.string "Lucas: $"

OldaleTown_Text_TownSign:
	.string "OLDALE TOWN\n"
	.string "“Where things start off scarce.”$"

OldaleTown_Text_SavingMyProgress:
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"
