.set LOCALID_RIVAL, 1
.set LOCALID_PROF, 2
.set LOCALID_DAWN, 3
.set LOCALID_LUCAS, 4

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

	@ State descriptions for VAR_ROUTE101_STATE
	@ 1: Prior to first lake event
	@ 2: Post first lake event
	@ 3: Returned from first lake event
	@ 4: Post professor event

Route101_OnTransition:
	call Common_EventScript_SetupRivalGfxId
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
	setvar VAR_ROUTE101_STATE, 1
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8004, 1, Route101_EventScript_RivalShift1
	call_if_eq VAR_0x8004, 2, Route101_EventScript_RivalShift2
	call_if_eq VAR_0x8004, 3, Route101_EventScript_RivalShift3
	call_if_eq VAR_0x8004, 4, Route101_EventScript_RivalShift4
	msgbox Route101_Text_RivalMeet, MSGBOX_SIGN
	setflag FLAG_HIDE_ROUTE_101_RIVAL
	loadword 0 Route101_EventScript_Rival
	setfollower LOCALID_RIVAL 0x100
	release
	end

Route101_EventScript_RivalShift1::
	applymovement LOCALID_RIVAL, Route101_Movement_RivalShift1
	waitmovement 0
	return

Route101_Movement_RivalShift1:
	walk_left
	walk_left
	walk_down
	step_end

Route101_EventScript_RivalShift2::
	applymovement LOCALID_RIVAL, Route101_Movement_RivalShift2
	waitmovement 0
	return

Route101_Movement_RivalShift2:
	walk_left
	walk_down
	step_end

Route101_EventScript_RivalShift3::
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	return

Route101_EventScript_RivalShift4::
	applymovement LOCALID_RIVAL, Route101_Movement_RivalShift4
	waitmovement 0
	return

Route101_Movement_RivalShift4:
	walk_right
	walk_down
	step_end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_Rival::
	@ TODO: Faceplayer not working
	faceplayer
	goto_if_eq VAR_FOLLOWER_TEXT, 0, Route101_EventScript_RivalTalk1
	goto_if_eq VAR_FOLLOWER_TEXT, 1, Route101_EventScript_RivalTalk2
	goto_if_eq VAR_FOLLOWER_TEXT, 2, Route101_EventScript_RivalTalk3
	goto_if_eq VAR_FOLLOWER_TEXT, 3, Route101_EventScript_RivalTalk4
	goto_if_eq VAR_FOLLOWER_TEXT, 4, Route101_EventScript_RivalTalk5
	goto_if_eq VAR_FOLLOWER_TEXT, 5, Route101_EventScript_RivalTalk6

Route101_EventScript_RivalTalk1::
	setvar VAR_FOLLOWER_TEXT, 1
	msgbox Route101_Text_RivalTalk1, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk2::
	setvar VAR_FOLLOWER_TEXT, 2
	msgbox Route101_Text_RivalTalk2, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk3::
	setvar VAR_FOLLOWER_TEXT, 3
	msgbox Route101_Text_RivalTalk3, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk4::
	setvar VAR_FOLLOWER_TEXT, 4
	msgbox Route101_Text_RivalTalk4, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk5::
	setvar VAR_FOLLOWER_TEXT, 5
	msgbox Route101_Text_RivalTalk5, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk6::
	msgbox Route101_Text_RivalTalk6, MSGBOX_SIGN
	end

Route101_EventScript_FollowLeave::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route101_Text_FollowLeave, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	release
	end

Route101_EventScript_FollowGrass::
	lock
	msgbox Route101_Text_FollowGrass, MSGBOX_SIGN
	goto_if_eq VAR_FACING, DIR_NORTH, Route101_EventScript_FollowGrassSpecial
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	release
	end

Route101_EventScript_FollowGrassSpecial::
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	release
	end

Route101_EventScript_Professor1::
	lock
	setvar VAR_ROUTE101_STATE, 4
	setflag FLAG_HIDE_ROUTE_101_PROF
	setflag FLAG_HIDE_ROUTE_101_HELPER
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox Route101_Text_RivalProf, MSGBOX_SIGN
	delay 48
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	applymovement LOCALID_PROF, Route101_Movement_Prof1
	waitmovement 0
	msgbox Route101_Text_Prof1, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route101_Text_Prof2, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Route101_Movement_Helper1
	applymovement LOCALID_PROF, Route101_Movement_ProfLeave
	waitmovement 0
	removeobject LOCALID_PROF
	msgbox Route101_Text_Helper1, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route101_Text_Helper2, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Route101_Movement_HelperLeave
	waitmovement 0
	removeobject LOCALID_HELPER
	msgbox Route101_Text_RivalLeave, MSGBOX_SIGN
	delay 48
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 1, 5
	fadescreen FADE_TO_BLACK
	destroyfollower
	release
	end

Route101_EventScript_Professor2::
	lock
	setvar VAR_ROUTE101_STATE, 4
	setflag FLAG_HIDE_ROUTE_101_PROF
	setflag FLAG_HIDE_ROUTE_101_HELPER
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox Route101_Text_RivalProf, MSGBOX_SIGN
	delay 48
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	applymovement LOCALID_PROF, Route101_Movement_Prof2
	waitmovement 0
	msgbox Route101_Text_Prof1, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route101_Text_Prof2, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Route101_Movement_Helper2
	applymovement LOCALID_PROF, Route101_Movement_ProfLeave
	waitmovement 0
	removeobject LOCALID_PROF
	msgbox Route101_Text_Helper1, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route101_Text_Helper2, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Route101_Movement_HelperLeave
	waitmovement 0
	removeobject LOCALID_HELPER
	msgbox Route101_Text_RivalLeave, MSGBOX_SIGN
	delay 48
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 1, 5
	fadescreen FADE_TO_BLACK
	destroyfollower
	release
	end

Route101_Movement_Prof1:
	walk_left
	walk_left
	step_end

Route101_Movement_Prof2:
	walk_left
	walk_down
	walk_left
	step_end

Route101_Movement_ProfLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route101_Movement_Helper1:
	delay_16
	delay_16
	walk_in_place_right
	step_end

Route101_Movement_Helper2:
	delay_16
	walk_up
	walk_in_place_down
	walk_in_place_right
	step_end

Route101_Movement_HelperLeave:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route101_Text_RouteSign:
	.string "{DOWN_ARROW} R.201\n"
	.string "   Twinleaf Town$"

@ TODO: Figure out how to add delimited quotes to string
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

Route101_Text_RivalTalk1:
	.string "{RIVAL}: Hey, if we run into a\n"
	.string "Pokemon, I'm gonna catch it somehow.\p"
	.string "Because I'm gonne be a Pokemon\n"
	.string "Trainer.\p"
	.string "You know what a Trainer does, right?\n"
	.string "Makes Pokemon battle and all that?$"

Route101_Text_RivalTalk2:
	.string "{RIVAL}: Pokemon all have\n"
	.string "different moves, huh?\p"
	.string "A Trainer makes his Pokemon battle\n"
	.string "by ordering them to use moves.\p"
	.string "That's so awesomely cool.$"
	
Route101_Text_RivalTalk3:
	.string "{RIVAL}: I want Pokemon of my\n"
	.string "own, and not too soon, either.\p"
	.string "I'd be able to go everywhere with my\n"
	.string "Pokemon that way.$"
	
Route101_Text_RivalTalk4:
	.string "{RIVAL}: That lake has a mirage\n"
	.string "Pokemon living in it.\p"
	.string "Everyone says nothing lives there,\n"
	.string "but I know I'm right.$"
	
Route101_Text_RivalTalk5:
	.string "{RIVAL}: I'm gonna become\n"
	.string "a Pokemon Trainer for sure.\p"
	.string "Not just any trainer either.\n"
	.string "I'm going to be the greatest ever.\l"
	.string "That's my dream.$"
	
Route101_Text_RivalTalk6:
	.string "{RIVAL}: Hey, that's enough\n"
	.string "talking already.\p"
	.string "I'm itching to get going to the lake.\n"
	.string "Come on, come on!$"

Route101_Text_FollowLeave:
	.string "{RIVAL}: Hey!\n"
	.string "Where are you wandering off to?!\p"
	.string "That mystery Pokemon on TV!\n"
	.string "It's calling out to me!\p"
	.string "Forget about going back home!$"

@ TODO: Figure out how to add delimited quotes to string
Route101_Text_FollowGrass:
	.string "Remember what your mother said?\p"
	.string "Mom: '{PLAYER}!\n"
	.string "Don't go into the tall grass!\p"
	.string "'Remember, wild Pokemon may attack\n"
	.string "you if you're walking in the tall grass.\p"
	.string "'It would be OK if you had your\n"
	.string "own Pokemon, but...'$"

Route101_Text_RivalProf:
	.string "{RIVAL}: Hey, it's those people!\n"
	.string "Is that old guy staring at us?$"

Route101_Text_Prof1:
	.string "Professor: Hmm...\p"
	.string "I heard from Dawn that\n"
	.string "you used our Pokemon?\l"
	.string "Let me see them, please.\p"
	.string "Hmm...\n"
	.string "CHIMCHAR and PIPLUP...\p"
	.string "...\p"
	.string "Hmm...\p"
	.string "I see...\n"
	.string "That's how it is...$"

Route101_Text_Prof2:
	.string "Dawn!\n"
	.string "I'm going back to my lab!$"

Route101_Text_Helper1:
	.string "Dawn: Um...Yes!\n"
	.string "Professor, please wait for me!$"

Route101_Text_Helper2:
	.string "I think you should visit our lab\n"
	.string "later.\p"
	.string "OK, see you!$"

Route101_Text_RivalLeave:
	.string "{RIVAL}: What was all that\n"
	.string "craziness about?\p"
	.string "I mean, if he was angry, he could've\n"
	.string "just yelled at us, or whatever...\p"
	.string "And didn't he want their Pokemon\n"
	.string "back...?\p"
	.string "{PLAYER}...\n"
	.string "We should go home, too...$"
