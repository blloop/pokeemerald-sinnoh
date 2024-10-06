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
	msgbox LakeVerity_Text_IntroScene1, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan1
	waitmovement 0
	delay 30
	msgbox LakeVerity_Text_IntroScene2, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_FaceRight
	waitmovement 0
	@ TODO: Add prof helper gender logic
	msgbox LakeVerity_Text_HelperDawn1, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan2
	waitmovement 0
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

LakeVerity_Text_IntroScene1:
	.string "{RIVAL}: What's going on...?$"

LakeVerity_Text_IntroScene2:
	.string "Professor, there isn't anything out\n"
	.string "of the ordinary on the other side,\l"
	.string "either!\p"
	.string "Professor: Hmm...\n"
	.string "I may have been mistaken...\p"
	.string "Something appears to be different\n"
	.string "than it was before, but...\p"
	.string "Fine! It's enough that we have\n"
	.string "seen the lake.$"

LakeVerity_Text_HelperDawn1:
	.string "Dawn, we're leaving.$"
