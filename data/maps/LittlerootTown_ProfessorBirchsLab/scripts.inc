.set LOCALID_AIDE, 1
.set LOCALID_PROF, 2
.set LOCALID_HELPER, 3

LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 0, LittlerootTown_ProfessorBirchsLab_EventScript_ShowStarter
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_ShowStarter::
	lockall
	setvar VAR_BIRCH_LAB_STATE, 1
	special SpawnCameraObject
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_Player1
	applymovement OBJ_EVENT_ID_CAMERA, LittlerootTown_ProfessorBirchsLab_Movement_Player1
	applymovement LOCALID_HELPER, LittlerootTown_ProfessorBirchsLab_Movement_Helper1
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor1
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	closemessage
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor2
	bufferleadmonspeciesname STR_VAR_1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor4, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Helper1, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	delay 16
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor5
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AskHelp

LittlerootTown_ProfessorBirchsLab_EventScript_AskHelp::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor6, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DenyHelp
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex

LittlerootTown_ProfessorBirchsLab_EventScript_DenyHelp::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor7
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AskHelp

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Professor8
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 16
	setflag FLAG_ADVENTURE_STARTED
	special RemoveCameraObject
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	return

LittlerootTown_ProfessorBirchsLab_Movement_Player1:
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

LittlerootTown_ProfessorBirchsLab_Movement_Helper1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_left
	step_end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PC, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf1::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf1, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf2::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf2, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf3::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf3, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf4::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf4, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Fridge::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Fridge, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_Text_Professor1:
	.string "Professor: ...\p"
	.string "Finally, you've come.\n"
	.string "{PLAYER}, was it?\p"
	.string "Let me see your Pokémon again.$"

LittlerootTown_ProfessorBirchsLab_Text_Professor2:
	.string "...\p"
	.string "Hmm...\n"
	.string "I see...\p"
	.string "This Pokémon seems to be rather\n"
	.string "happy.\p"
	.string "All righty then!\p"
	.string "I'll give that {STR_VAR_1} to you as\n"
	.string "a gift.$"

LittlerootTown_ProfessorBirchsLab_Text_Professor3:
	.string "Professor: Now that it's yours, would\n"
	.string "you like to give it a nickname?$"
	
LittlerootTown_ProfessorBirchsLab_Text_Professor4:
	.string "Professor: Your friend {RIVAL}\n"
	.string "told me what happened at the lake.\p"
	.string "I heard you battled very well,\n"
	.string "despite it being your first time.\p"
	.string "And, from what I can see, there is\n"
	.string "a growing bond between you and that\l"
	.string "Pokémon, though it is still young.\p"
	.string "That's why I would like to entrust\n"
	.string "you with {STR_VAR_1}.$"

LittlerootTown_ProfessorBirchsLab_Text_Professor5:
	.string "Professor: Er-hem!\n"
	.string "Let's move on to the main topic.\p"
	.string "There is something I want you\n"
	.string "to do for me.\p"
	.string "My name is Rowan.\n"
	.string "I study Pokémon.\p"
	.string "First of all, I want to know exactly\n"
	.string "what kinds of Pokémon live in the\l"
	.string "Sinnoh region.\p"
	.string "To do so, it is necessary to collect\n"
	.string "data using the Pokédex\p"
	.string "This is what I wish to ask of you.$"

LittlerootTown_ProfessorBirchsLab_Text_Professor6:
	.string "Will you use it to record data on all\n"
	.string "the Pokémon in Sinnoh for me?\p"
	.string "I want to entrust you with this\n"
	.string "Pokédex.$"

LittlerootTown_ProfessorBirchsLab_Text_Professor7:
	.string "Rowan: ...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "I can stand here without speaking for\n"
	.string "hours. I'm a very patient man.\p"
	.string "Let me ask you again, {PLAYER}.$"

LittlerootTown_ProfessorBirchsLab_Text_Professor8:
	.string "Rowan: Hm!/p"
	.string "Good answer!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{PLAYER} obtained\n"
	.string "the Pokédex!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
	.string "Rowan: That Pokédex is a very\n"
	.string "high-tech device\p"
	.string "It will automatically record data on\n"
	.string "every kind of Pokémon you encounter.\p"
	.string "{PLAYER}, I ask that you go\n"
	.string "everywhere and meet every kind of\l"
	.string "Pokémon in this region!$"

LittlerootTown_ProfessorBirchsLab_Text_Helper1:
	.string "Dawn: I'm so glad that you're kind\n"
	.string "toward Pokémon!\p"
	.string "If you weren't, I'd have to...\n"
	.string "Oh, I just can't say it...$"

LittlerootTown_ProfessorBirchsLab_Text_PC:
	.string "{PLAYER} checked the PC.\p"
	.string "The screen is filled with special terms\n"
	.string "and academic writing that is impossible\l"
	.string "to figure out.$"

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
	.string "It's a book that's too hard to read.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf1:
	.string "Adventure Rule No. 1\n"
	.string "The X Button opens the menu.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf2:
	.string "Adventure Rule No. 2\n"
	.string "Record your progress with SAVE.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf3:
	.string "It's crammed full of books with all\n"
	.string "sorts of Pokemon information.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf4:
	.string "There's a lot of reference material\n"
	.string "and research reports on Pokemon.$"

LittlerootTown_ProfessorBirchsLab_Text_Fridge:
	.string "The refrigerator is filled with\n"
	.string "tasty sweet! Hmm...$"

	.string "Professor Rowan invented a new\n"
	.string "Pokedex while working alongside a\l"
	.string "professor from the Kanto region!$"

	.string "I'm Dawn's father.\p"
	.string "I'll be happy to assist you on your\n"
	.string "quest for the professor.\p"
	.string "Hahaha. Eh...\n"
	.string "I'm sure we can count on you!$"
	
	.string "Rowan: Go on!\p"
	.string "{PLAYER}, your grand adventure\n"
	.string "awaits you!$"

@ LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
@ 	specialvar VAR_RESULT, HasAllHoennMons
@ 	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
@ 	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
@ 	setobjectxyperm LOCALID_RIVAL, 5, 10
@ 	end

@ LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
@ 	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
@ 	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
@ 	setobjectxyperm LOCALID_RIVAL, 5, 10
@ 	end

@ LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	@ TODO: Figure out var below
	@ goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	@ release
	@ end
