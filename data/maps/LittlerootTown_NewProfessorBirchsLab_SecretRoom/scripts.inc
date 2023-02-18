LittlerootTown_NewProfessorBirchsLab_SecretRoom_MapScripts::
	.byte 0


LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew::
	lockall
	showmonpic SPECIES_MEW, 10, 3
	msgbox LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_2
	hidemonpic
	msgbox LittlerootTown_NewProfessorBirchsLab_SecretRoom_NotChosen
LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_1:
	waitmessage
	releaseall
	end

LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_2:
	givemon SPECIES_MEW, 50, ITEM_CHERISH_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_6
	hidemonpic
	msgbox LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_2
	goto LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_1

LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_1
	removeobject 1
	setflag FLAG_RECEIVED_MEW
	call NicknamePartyMon
	goto LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_1

LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_1
	removeobject 1
	setflag FLAG_RECEIVED_MEW
	call NicknameBoxMon
	goto LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_1


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_0:
	.string "Do you want to take MEW with you?$"

LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_1:
	.string "Received Mew$"

LittlerootTown_NewProfessorBirchsLab_SecretRoom_Mew_Text_2:
	.string "No more room$"

NicknamePartyMon_Text_0:
	.string "Give it a Nickname?$"

NicknameBoxMon_Text_0:
	.string "Transferred to PC$"

LittlerootTown_NewProfessorBirchsLab_SecretRoom_NotChosen::
	.string "You did not choose the Pokemon$"
