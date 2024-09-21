.set LOCALID_MOM, 1
.set LOCALID_RIVAL, 7

LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnTransition:
	end

LittlerootTown_MaysHouse_1F_OnFrame:
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_Mom::
	msgbox LittlerootTown_MaysHouse_1F_MomMessage
	end

LittlerootTown_MaysHouse_1F_MomMessage:
	.string "{RIVAL}'s mom: Oh, hi,\n"
	.string "{PLAYER}.\p"
	.string "Are you looking for {RIVAL}?\p"
	.string "He was gone for a second, but then\n"
	.string "he came running right back home.\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"
