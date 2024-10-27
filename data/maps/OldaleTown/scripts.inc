.set LOCALID_RIVAL, 1

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
	@ Move left 6
	end

OldaleTown_EventScript_HelperLab2::
	@ Move left 6
	end

OldaleTown_EventScript_HelperLab3::
	@ Move left 5
	end

OldaleTown_EventScript_HelperLab4::
	@ Move left 6
	end

OldaleTown_EventScript_HelperLab5::
	@ Move left 6
	end

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_Text_SavingMyProgress:
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

OldaleTown_Text_TownSign:
	.string "OLDALE TOWN\n"
	.string "“Where things start off scarce.”$"

