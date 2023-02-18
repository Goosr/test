LittlerootTown_NewProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_NewProfessorBirchsLab_OnLoad
	.byte 0


LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf::
	lockall
	compare VAR_SECRET_BUTTON, 1
	goto_if_ne LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_2
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_2
LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_1:
	releaseall
	end

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_2:
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_5
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_1
	waitmessage
	goto LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_1

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_5:
	call LittlerootTown_NewProfessorBirchsLab_EventScript_Yes
	goto LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_1


LittlerootTown_NewProfessorBirchsLab_OnLoad::
	compare VAR_SECRET_BUTTON, 1
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_OnLoad_2
LittlerootTown_NewProfessorBirchsLab_OnLoad_1:
	compare VAR_SECRET_PC, 1
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_OnLoad_5
LittlerootTown_NewProfessorBirchsLab_OnLoad_4:
	end

LittlerootTown_NewProfessorBirchsLab_OnLoad_2:
	call LittlerootTown_NewProfessorBirchsLab_EventScript_OpenSecretRoom
	goto LittlerootTown_NewProfessorBirchsLab_OnLoad_1

LittlerootTown_NewProfessorBirchsLab_OnLoad_5:
	call LittlerootTown_NewProfessorBirchsLab_EventScript_OpenedWall
	goto LittlerootTown_NewProfessorBirchsLab_OnLoad_4


LittlerootTown_NewProfessorBirchsLab_EventScript_Yes::
	setvar VAR_SECRET_BUTTON, 1
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_0
	waitmessage
	playse SE_BANG
	call LittlerootTown_NewProfessorBirchsLab_EventScript_OpenSecretRoom
	waitse
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_1, MSGBOX_AUTOCLOSE
	waitmessage
	return


LittlerootTown_NewProfessorBirchsLab_EventScript_OpenSecretRoom::
	setmetatile 2, 6, 0x27D, TRUE
	setmetatile 2, 7, 0x283, FALSE
	setmetatile 3, 6, 0x22C, TRUE
	setmetatile 3, 7, 0x234, TRUE
	setmetatile 4, 6, 0x22D, TRUE
	setmetatile 4, 7, 0x235, TRUE
	setmetatile 4, 8, 0x23E, FALSE
	special DrawWholeMapView
	return


LittlerootTown_NewProfessorBirchsLab_EventScript_SecretPC::
	lockall
	compare VAR_SECRET_PC, 1
	goto_if_ne LittlerootTown_NewProfessorBirchsLab_EventScript_SecretPC_2
	msgbox SecretPC2
LittlerootTown_NewProfessorBirchsLab_EventScript_SecretPC_1:
	releaseall
	end

LittlerootTown_NewProfessorBirchsLab_EventScript_SecretPC_2:
	msgbox SecretPC1
	waitmessage
	call LittlerootTown_NewProfessorBirchsLab_EventScript_Wall
	goto LittlerootTown_NewProfessorBirchsLab_EventScript_SecretPC_1


LittlerootTown_NewProfessorBirchsLab_EventScript_Wall::
	setvar VAR_SECRET_PC, 1
	playse SE_BANG
	call LittlerootTown_NewProfessorBirchsLab_EventScript_OpenedWall
	waitse
	msgbox SecretPC3
	waitmessage
	return


LittlerootTown_NewProfessorBirchsLab_EventScript_OpenedWall::
	setmetatile 18, 2, 0x273, TRUE
	setmetatile 18, 3, 0x270, TRUE
	setmetatile 18, 4, 0x278, TRUE
	setmetatile 18, 5, 0x271, FALSE
	setmetatile 18, 6, 0x269, FALSE
	setmetatile 18, 7, 0x268, FALSE
	setmetatile 18, 8, 0x27B, TRUE
	setmetatile 19, 5, 0x277, FALSE
	setmetatile 19, 6, 0x269, FALSE
	setmetatile 19, 7, 0x269, FALSE
	setmetatile 19, 8, 0x269, FALSE
	special DrawWholeMapView
	return


LittlerootTown_NewProfessorBirchsLab_SignPost_PC::
	msgbox BasicPC, MSGBOX_AUTOCLOSE
	waitmessage
	end


LittlerootTown_NewProfessorBirchsLab_SignPost_Bookshelf::
	msgbox BasicBookshelf, MSGBOX_AUTOCLOSE
	waitmessage
	end


LittlerootTown_NewProfessorBirchsLab_SignPost_Mashine::
	msgbox Mashine, MSGBOX_AUTOCLOSE
	waitmessage
	end


LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_0:
	.string "There is a lever behind\n one of the books.\p Do you want to flip it?$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_1:
	.string "You didn't flip the lever.$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_2:
	.string "The lever was already flipped.$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_0:
	.string "You flipped the lever.$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_1:
	.string "The bookshelf moved aside!$"

SecretPC1::
	.string "This PC looks strange.\nIt is built into the wall.\pWhat if there is...?$"

SecretPC2::
	.string "By playing around with the PC\nYou activated a secret mechanism.$"

SecretPC3::
	.string "The Wall opened up!$"

BasicPC::
	.string "It's a PC used for research.\nBetter not mess around with it.$"

BasicBookshelf::
	.string "It's crammed with books on POKéMON.$"

Mashine::
	.string "It's a serious-looking mashine.\nThe PROF must use it for research.$"
