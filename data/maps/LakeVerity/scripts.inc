LakeVerity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeVerity_OnFrame
	.byte 0

	@ State descriptions for VAR_VERITY_STATE
	@ 1: Entered First Lake Scene

LakeVerity_OnFrame:
	map_script_2 VAR_VERITY_STATE, 0, LakeVerity_EventScript_FirstScene
	.2byte 0

LakeVerity_EventScript_FirstScene::
	lock
	setvar VAR_VERITY_STATE, 1
	msgbox LakeVerity_Text_FirstScene, MSGBOX_SIGN
	release
	end

LakeVerity_Text_FirstScene:
	.string "What's going on?$"
