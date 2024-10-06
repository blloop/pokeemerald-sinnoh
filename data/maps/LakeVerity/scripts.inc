.set LOCALID_RIVAL, 1
.set LOCALID_PROF, 2
.set LOCALID_DAWN, 3
.set LOCALID_LUCAS, 4

LakeVerity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeVerity_OnFrame
	.byte 0

	@ State descriptions for VAR_VERITY_STATE
	@ 1: Entered First Lake Scene

LakeVerity_OnFrame:
	map_script_2 VAR_VERITY_STATE, 0, LakeVerity_EventScript_IntroScene
	.2byte 0

LakeVerity_EventScript_IntroScene::
	lock
	special SpawnCameraObject
	setvar VAR_VERITY_STATE, 1
	msgbox LakeVerity_Text_Rival1, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan1
	waitmovement 0
	delay 30
	msgbox LakeVerity_Text_Professor1, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_FaceRight
	waitmovement 0
	@ TODO: Add prof helper gender logic
	msgbox LakeVerity_Text_HelperDawn1, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_DAWN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LakeVerity_Text_HelperDawn2, MSGBOX_SIGN
	delay 48
	delay 48
	@ TODO: Spawn briefcase
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan2
	applymovement LOCALID_PROF, LakeVerity_Movement_ProfessorLeave1
	applymovement LOCALID_DAWN, LakeVerity_Movement_HelperLeave1
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LakeVerity_Text_Professor2, MSGBOX_SIGN
	applymovement LOCALID_PROF, LakeVerity_Movement_ProfessorLeave2
	waitmovement 0
	removeobject LOCALID_PROF
	applymovement LOCALID_DAWN, LakeVerity_Movement_HelperLeave2
	waitmovement 0
	msgbox LakeVerity_Text_HelperDawn3, MSGBOX_SIGN
	applymovement LOCALID_DAWN, LakeVerity_Movement_ProfessorLeave2
	waitmovement 0
	removeobject LOCALID_DAWN
	delay 48
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox LakeVerity_Text_Rival2, MSGBOX_SIGN
	delay 30
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	delay 30
	msgbox LakeVerity_Text_Rival3, MSGBOX_SIGN



	special RemoveCameraObject
	release
	end

LakeVerity_Movement_CameraPan1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_CameraPan2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_ProfessorLeave1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_ProfessorLeave2:
	walk_down
	walk_down
	step_end

LakeVerity_Movement_HelperLeave1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_HelperLeave2:
	walk_down
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_8
	walk_in_place_left
	delay_16
	walk_in_place_down
	delay_16
	step_end

LakeVerity_Text_Rival1:
	.string "{RIVAL}: What's going on...?$"

LakeVerity_Text_Rival2:
	.string "{RIVAL}: What was that about?\n"
	.string "Those two...$"

LakeVerity_Text_Rival3:
	.string "Huh? {PLAYER}!\n"
	.string "Let's go check this out!$"

LakeVerity_Text_Professor1:
	.string "Professor, there isn't anything out\n"
	.string "of the ordinary on the other side,\l"
	.string "either!\p"
	.string "Professor: Hmm...\n"
	.string "I may have been mistaken...\p"
	.string "Something appears to be different\n"
	.string "than it was before, but...\p"
	.string "Fine! It's enough that we have\n"
	.string "seen the lake.$"

LakeVerity_Text_Professor2:
	.string "Professor: Excuse me.\n"
	.string "Let us pass, please.$"

LakeVerity_Text_HelperDawn1:
	.string "Dawn, we're leaving.$"

LakeVerity_Text_HelperDawn2:
	.string "Dawn: Professor, how are you enjoying\n"
	.string "being back in Sinnoh?\p"
	.string "After being away for four years,\n"
	.string "it must be exciting again?\p"
	.string "Professor: ...Hm.\n"
	.string "There is one thing I can say.\p"
	.string "There are many rare kinds of Pokemon\n"
	.string "in Sinnoh.\p"
	.string "The region should serve us very well\n"
	.string "in regard to our studies.$"

LakeVerity_Text_HelperDawn3:
	.string "Dawn: I beg your pardon...\n"
	.string "We'll be on our way.$"
