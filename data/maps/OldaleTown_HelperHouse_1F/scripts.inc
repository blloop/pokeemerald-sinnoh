OldaleTown_HelperHouse_1F_MapScripts::
	.byte 0

OldaleTown_HelperHouse_1F_EventScript_Woman::
	msgbox OldaleTown_HelperHouse_1F_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_HelperHouse_1F_EventScript_Man::
	msgbox OldaleTown_HelperHouse_1F_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_HelperHouse_1F_Text_PokemonLevelUp:
	.string "When POKéMON battle, they eventually\n"
	.string "level up and become stronger.$"

OldaleTown_HelperHouse_1F_Text_YoullGoFurtherWithStrongPokemon:
	.string "If the POKéMON with you become\n"
	.string "stronger, you'll be able to go farther\l"
	.string "away from here.$"

