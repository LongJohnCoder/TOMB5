﻿#include "TITSEQ.H"

#include "EFFECTS.H"
#include "GAMEFLOW.H"
#include "GPU.H"
#include "LOADSAVE.H"
#include "MEMCARD.H"
#include "PSXINPUT.H"
#include "SAVEGAME.H"
#include "SOUND.H"
#include "SPOTCAM.H"
#include "TEXT_S.H"
#include "MISC.H"

#include <stdio.h>//deleteme

#define BLOCK_SPLINE_CAM (1)

#if PSX_VERSION && RELOC
void* func_titseq[] __attribute__((section(".header"))) =
{
	&TitleOptions(int Name),
};
#endif

unsigned char byte_46 = 0;
unsigned char byte_47 = 0;
unsigned char byte_1A8 = 0;

unsigned short unk_3C[] = { STR_MOVIE_TRAILER, STR_STORYBOARDS_PART_1, STR_NEXT_GENERATION_CONCEPT_ART, STR_STORYBOARDS_PART_2, STR_NEXT_GENERATION_PREVIEW };
unsigned int word_38 = 1;

enum
{
	MENU_MAIN_MENU,
	MENU_LOAD_MENU,
	MENU_LEVEL_SELECT_MENU,
	MENU_SPECIAL_FEATURES_MENU
};

void Test()
{
}

int TitleOptions(int Name)
{
	int a1;
#if DEBUG_VERSION
	char buf[80];//0x18(sp)
#endif
	int ret; //0x68(sp)
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	int y = 0;//s3 = 0 = runtimecheckfailure
	int i = 0;//s4
	unsigned short* s4;
	int s5 = 0;
	int s6;

	//v0 = 0xA0000
	//v1 = PadConnected
	ret = 0;
	//0x98(sp) = Name

#if BLOCK_SPLINE_CAM
	current_spline_position = 0;
#endif

	if (PadConnected == 0)
	{
		byte_46 = 0;
		Chris_Menu = MENU_MAIN_MENU;
		dels_cutseq_selector_flag = 0;
	}
	//loc_49C
	//a0 = gfGameMode
	if (gfGameMode == 2)
	{
		return 0;
	}

	//v1 = dels_cutseq_selector_flag
	//v0 = 0xA0000
	if (dels_cutseq_selector_flag != 0)
	{
		//v1 = 0x00000
		Chris_Menu = MENU_MAIN_MENU;
		byte_46 = 0;
		return sub_1054();
	}//loc_4DC

	//a0 = Chris_Menu
	//v1 = 1
	//s7 = v0
	if (Chris_Menu != MENU_LOAD_MENU && Chris_Menu != MENU_SPECIAL_FEATURES_MENU)
	{
		if (bDoCredits == 0)
		{
			sub_2B0();
		}
	}
	else if (bDoCredits == 0)
	{
		//loc_514
#if DEBUG_VERSION
		if (bDoCredits == 0)
		{
			sprintf(&buf[0], "Savegame = %d bytes", 0x3B4);
			PrintString(256, 232, 5, &buf[0], 0x9064);
		}//loc_558
#endif
	}

	
	//loc_558
	a1 = last_camera;
	//a0 = current_sequence

	if (current_sequence == 2)
	{
		a1 = current_sequence - 1;
	}
	//loc_57C
	//v0 = current_spline_camera

	if (current_spline_camera > a1 && 0xCB20 < current_spline_position)
	{
		title_controls_locked_out = 1;
	}

	//loc_5AC
	if (title_controls_locked_out)
	{
		RawEdge = 0;
	}

	//loc_5C0
	//v1 = Chris_Menu
	//v0 = Chris_Menu < 2 ? 1 : 0 
	if (Chris_Menu == MENU_LOAD_MENU)
	{
		//loc_91C
		s1 = LoadGame();

		if (s1 != 0)
		{
			Chris_Menu = MENU_MAIN_MENU;
			byte_46 = 0;
			if (s1 > 0)
			{
				ret = 2;
			}
		}//loc_EB4

		return ret;
	}
	else if (Chris_Menu == MENU_LEVEL_SELECT_MENU)
	{
		//loc_948
		//v0 = 0
		//a0 = byte_46
		s1 = byte_46 - 6;
		if (s1 < 0)
		{
			s1 = 0;
		}//loc_964

		if ((RawEdge & 0x10) && byte_46 != 0)
		{
			SoundEffect(SFX_MENU_SELECT, NULL, 2);
			--byte_46;
		}
		else if ((RawEdge & 0x40) && byte_46 < Gameflow->nLevels - 2)
		{
			SoundEffect(SFX_MENU_SELECT, NULL, 2);
			++byte_46;
		}
		else if ((RawEdge & 0x200))
		{
			byte_46 = Gameflow->nLevels - 2;
		}
		else if ((RawEdge & 0x100))
		{
			byte_46 = 0;
		}
		else if ((RawEdge & 0x800))
		{
			byte_46 = ((Gameflow->nLevels - 2) + ((Gameflow->nLevels - 2) >> 31)) >> 1;
		}
		else if ((RawEdge & 0x400))
		{
			byte_47 ^= 1;

		}
		//loc_A98
		//v1 = Gameflow
		//Gameflow->nLevels -1
		//v0 = s1 < v0 ? 1 : 0

		i = 0;
		if (s1 < Gameflow->nLevels - 1)
		{
			//s5 = 0x8000
			//s6 = &gfLevelNames
			y = 0x70;
			//s2 = 0x70
			//v0 = 0

			//v1 = byte_47
			//t0 = 5
			//loc_AD8
			do
			{
				if (byte_47)
				{
					//a3 = 0
					//v0 = byte_46
					//a1 = s2 & 0xFFFF
					if (byte_46 == s1)
					{
						//t0 = 1
					}//loc_B00

					//a0 = 0x100
					//s9 = s1 + 1
					///TODO la      $v0, unk_2608


				}
				else
				{
					//loc_B48
					//a2 = 5
					//v1 = 0
					//v0 = byte_46
					//a1 = s3 & 0xFFFF

					//s5 = 0x8000
					//a0 = 0x100
					//s0 = s1 + 1
					//v1 = &gfLevelNames[s0]
					//a3 = 0xA0000
					//v0 = gfLevelNames[s0]
					//t0 = gfStringOffset
					//a3 = gfStringWad
					//a3 = &gfStringWad[gfStringOffset[gfLevelNames[s1 + 1]]];



				///@TODO tomorrow
				}
				//loc_B94

				if (byte_46 == s1)
				{
					PrintString(256, y & 0xFFFF, 1, &gfStringWad[gfStringOffset[gfLevelNames[s1 + 1]]], 0x8000);
				}
				else
				{
					PrintString(256, y & 0xFFFF, 5, &gfStringWad[gfStringOffset[gfLevelNames[s1 + 1]]], 0x8000);
				}
				y += 18;
				//v0 = s0
				s1++;
				s2 += 18;
				//v0 = 
				//s4++;
				if (s1 > Gameflow->nLevels - 1)
				{
					break;
				}
			} while (++i < 7);
		}
		//loc_BD4

		//v1 = RawEdge
		if ((RawEdge & 0x4000))
		{
			SoundEffect(SFX_MENU_CHOOSE, NULL, 2);
			ret = 3;
			Chris_Menu = MENU_MAIN_MENU;
			gfLevelComplete = byte_46 + 1;
			byte_46 = 0;
		}
		else if ((RawEdge & 0x1000))
		{
			//loc_C20
			SoundEffect(SFX_MENU_CHOOSE, NULL, 2);
			Chris_Menu = MENU_MAIN_MENU;
		}

		return ret;
	}
	else if (Chris_Menu == MENU_SPECIAL_FEATURES_MENU)
	{
		//loc_C3C
		//a0 = 256
		//a1 = 32
		//a2 = 6
		s6 = 0;
		s1 = 0;
		//s2 = 0x404040
		//s5 = 0
		//v0 = gfStringOffset
		//a3 = gfStringWad
		PrintString(256, 32, 6, &gfStringWad[gfStringOffset[STR_SPECIAL_FEATURES]], 0x8000);
		//v0 = 0xB0000
		//fp = &savegame.CampaignSecrets
		s4 = &unk_3C[0];

		//v1 = &savegame.CampaignSecrets[s1];
		//loc_C8C
		for (s1 = 0; s1 < 5; s1++, s4++)
		{
			if (s1 != 0)
			{
				if (savegame.CampaignSecrets[s1 - 1] < 9)
				{
					//loc_DDC
					continue;
				}
			}

			//loc_CA8
			//v0 = 0
			//v1 = dword_38
			//a2 = 2

			y = ((s5 - (word_38 * 12) + 0x70)) & 0xFF;

			//nop
			//addiu   $a1, $s3, 4
			if (byte_46 == s6)
			{
				PrintString(256, y + 4, 1, &gfStringWad[gfStringOffset[s4[0]]], 0x8000);
			}
			else
			{
				PrintString(256, y + 4, 2, &gfStringWad[gfStringOffset[s4[0]]], 0x8000);
			}

			//loc_CE4
			s5 += 24;

			DrawF4(64, y - 11, 384, 22, 0, 0x2A800000);
			DrawTPage(0, 0);
			DrawLineH(66, y - 10, 380, 0, s2, 0);
			DrawLineH(66, y + 9, 380, 0, s2, 0);
			DrawLineV(66, y - 10, 20, 0, s2, 0);
			DrawLineV(445, y - 10, 20, 0, s2, 0);

			DrawTPage(0, 1);

			s6++;

			//loc_DDC
		}

		if ((RawEdge & 0x10) && byte_46 != 0)
		{
			--byte_46;
			//j loc_EB4
		}
		else if ((RawEdge & 0x40) && byte_46 < word_38 - 1)
		{
			++byte_46;
			//j loc_EB4
		}
		else if ((RawEdge & 0x1000))
		{
			Chris_Menu = MENU_MAIN_MENU;
			byte_46 = CanLoad + 1;
			//j loc_EB4
		}
		else if ((RawEdge & 0x4000))
		{

		}

		return ret;
	}
	else if (Chris_Menu == MENU_MAIN_MENU)
	{
		//loc_600
		//v1 = Gameflow
		//s3 = 0xC0

		//Overidden in gameflow script disable loading now.
		if (!Gameflow->LoadSaveEnabled)
		{
			y = 192;
			//loc_6B4
			//s1 = a0
			if (CanLoad == 1)
			{
				byte_46 = 0;
				CanLoad = 0;
			}//loc_6D4
		}
		else if (mcGetStatus() != 0)
		{
			y = 192;
			//loc_6B8
			if (CanLoad == 1)
			{
				byte_46 = 0;
				CanLoad = 0;
			}//loc_6D4
		}
		else if (mcNumFiles != 0)
		{
			//loc_6B0
			y = 208;
			if (CanLoad == 0)
			{
				byte_46 = 0;
				CanLoad = 1;
			}//loc_664

			if (byte_46 == 1)
			{
				PrintString(256, 192, 1, &gfStringWad[gfStringOffset[STR_LOAD_GAME_BIS]], 0x8000);
			}
			else
			{
				PrintString(256, 192, 2, &gfStringWad[gfStringOffset[STR_LOAD_GAME_BIS]], 0x8000);
			}
		}//loc_6B0 mcnumfiles
		else
		{
			//loc_6B0
			y = 192;
		}

		//j loc_6D8
	}
	else
	{
		return ret;
	}

	//loc_6D8
	if (byte_46 == 0)
	{
		PrintString(256, 176, 1, &gfStringWad[gfStringOffset[STR_SAVE_GAME_BIS]], 0x8000);
	}
	else
	{
		PrintString(256, 176, 2, &gfStringWad[gfStringOffset[STR_SAVE_GAME_BIS]], 0x8000);
	}

	//a0 = 0
	
	if (byte_46 == 2)
	{
		//v0 = 1
		PrintString(256, y, 1, &gfStringWad[gfStringOffset[STR_SPECIAL_FEATURES]], 0x8000);
	}
	else if (byte_46 != 1)
	{
		PrintString(256, y, 2, &gfStringWad[gfStringOffset[STR_SPECIAL_FEATURES]], 0x8000);
	}
	else if (CanLoad != 0)
	{
		PrintString(256, y, 2, &gfStringWad[gfStringOffset[STR_SPECIAL_FEATURES]], 0x8000);
	}
	else
	{
		PrintString(256, y, 1, &gfStringWad[gfStringOffset[STR_SPECIAL_FEATURES]], 0x8000);
	}

	//v0 = gfStringOffset
	//a1 = y
	//v1 = ;
	if ((RawEdge & 0x10) && byte_46 != 0)//Up
	{
		SoundEffect(SFX_MENU_SELECT, NULL, 2);
		--byte_46;
	}//loc_7C0
	else if((RawEdge & 0x40) && byte_46 < CanLoad + 1)//Down
	{
		//loc_7C0
		SoundEffect(SFX_MENU_SELECT, NULL, 2);
		++byte_46;
	}//loc_810



	if ((RawEdge & 0x4000))//X pressed
	{
		if (byte_46 == 1)
		{
			if (CanLoad != 0)
			{
				Chris_Menu = MENU_LOAD_MENU;
			}
			else
			{
				//loc_850
				//sub_3A8();
				Chris_Menu = MENU_SPECIAL_FEATURES_MENU;
				byte_46 = 0;
			}
			
			//loc_904
			SoundEffect(SFX_MENU_CHOOSE, NULL, 2);
		}//loc_86C
		else
		{
			//loc_86C
			if (byte_46 != 0)
			{
				//loc_8EC
				//sub_3A8();
				Chris_Menu = MENU_SPECIAL_FEATURES_MENU;
				byte_46 = 0;
			}
			else
			{
				if (Gameflow->PlayAnyLevel)
				{
					Chris_Menu = MENU_LEVEL_SELECT_MENU;
				}
				else
				{
					//loc_89C
					ret = 3;
					Chris_Menu = MENU_MAIN_MENU;
					
					if ((RawPad & 0x400))
					{
						gfLevelComplete = 4;
					}
					else
					{
						gfLevelComplete = 1;
					}

					//loc_8C8
					if ((RawPad & 0x100))
					{
						gfLevelComplete = 8;
					}

					if ((RawPad & 0x800))
					{
						gfLevelComplete = 11;
					}
				}
			}
		}
	}
	else
	{
		//loc_EB4
		return ret;
	}

	//loc_904
	SoundEffect(SFX_MENU_CHOOSE, NULL, 2);

	//s1 = LoadGame(); //Disabled due to crashing

	if (s1 == 0)
	{
		return ret;
	}

	Chris_Menu = MENU_MAIN_MENU;
	byte_46 = 0;

	if (s1 <= 0)
	{
		return ret;
	}
	else
	{
		ret = 2;
	}

	return ret;
}

void sub_2B0()
{
	if ((unsigned long)db.polyptr < (unsigned long)db.polybuf_limit)
	{
		((int*)db.polyptr)[4] = 0x2C808080;
		((char*)db.polyptr)[3] = 9;
		((short*)db.polyptr)[5] = 24;
		((short*)db.polyptr)[9] = 24;
		((short*)db.polyptr)[13] = 80;
		((short*)db.polyptr)[17] = 80;
		((short*)db.polyptr)[4] = 56;
		((short*)db.polyptr)[12] = 56;
		((short*)db.polyptr)[8] = 440;
		((short*)db.polyptr)[16] = 440;
		((char*)db.polyptr)[13] = 68;
		((char*)db.polyptr)[21] = 68;
		((char*)db.polyptr)[29] = 124;
		((char*)db.polyptr)[37] = 124;
		((char*)db.polyptr)[12] = 0;
		((char*)db.polyptr)[20] = 255;
		((char*)db.polyptr)[28] = 0;
		((char*)db.polyptr)[36] = 255;
		((short*)db.polyptr)[7] = 7972;
		((short*)db.polyptr)[11] = 41;

		((unsigned long*)db.polyptr)[0] = ((unsigned long*)db.polyptr)[0] & 0xFFFFFF | (db.ot[0] & 0xFFFFFF);
		db.ot[0] = (db.ot[0] & 0xFF000000) | ((unsigned long)db.polyptr & 0xFFFFFF);

		db.polyptr += sizeof(POLY_FT4);
	}//locret_3A0
}

int sub_1054()
{
	int s3;
	sub_2B0();
	PrintString(256, 102, 6, &gfStringWad[gfStringOffset[STR_SELECT_CUTSCENE]], 0x8000);

	//v0 = 0
	//fp = 0
	//a0 = byte_1A8
	//a3 = byte_1A8 - 4;
	if ((byte_1A8 - 4) < 0)
	{
		//a3 = 0;
	}//loc_10DC

	//v0 = RawEdge
	//s4 = v1
	if ((RawEdge & 0x10) && byte_1A8 != 0)
	{
		--byte_1A8;
		//j loc_1128
	}
	else if ((RawEdge & 0x40) && byte_1A8 < 35)
	{
		++byte_1A8;
	}

	//s2 = 0
	//loc_1128
	if ((byte_1A8 - 4) < 36)
	{
		//v0 = 0;
		//s5 = &unk_1AC
	}//loc_11B8



#if 0
		beqz    $v0, loc_11B8
		move    $s2, $zero
lui     $v0, 0
addiu   $s5, $v0, unk_1AC
li      $s1, 0x88
li      $a2, 5

loc_1144:                                # CODE XREF : sub_1054 + 15C↓j
	lbu     $v0, 0x1A8($s3)
	nop
	bne     $v0, $a3, loc_1158
	andi    $a1, $s1, 0xFFFF
	li      $a2, 1

	loc_1158 : # CODE XREF : sub_1054 + F8↑j
	li      $a0, 0x100
	addiu   $s1, 0x12
	addiu   $s2, 1
	addiu   $s0, $a3, 1
	sll     $v0, $s0, 1
	addu    $v0, $s0
	sll     $v0, 1
	addu    $v0, $s5
	lhu     $v1, 0($v0)
	lw      $a3, 0x202C($s6)
	sll     $v1, 1
	addu    $v1, $a3
	lhu     $t0, 0($v1)
	lw      $a3, 0x203C($s7)
	li      $v0, 0x8000
	sw      $v0, 0x40 + var_30($sp)
	jal     0x8DB4C
	addu    $a3, $t0
	move    $a3, $s0
	slti    $v0, $a3, 0x24
	beqz    $v0, loc_11B8
	slti    $v0, $s2, 5

	bnez    $v0, loc_1144
	li      $a2, 5

	loc_11B8:                                # CODE XREF : sub_1054:loc_112C↑j
	# sub_1054 + 154↑j
	lw      $v0, 0x4520($s4)
	nop
	andi    $v0, 0x4000
	beqz    $v0, loc_1240
	li      $a0, 0x6F  # 'o'
	move    $a1, $zero
	jal     0x91780
	li      $a2, 2
	li      $fp, 3
	lui     $v0, 0xA
	sh      $zero, 0xA05C2
	lui     $v0, 0xA
	lui     $a1, 0
	lbu     $v1, 0x1A8($s3)
	la      $a1, unk_1AC
	sw      $zero, 0xA09A0
	move    $a2, $v1
	addiu   $v1, 1
	sll     $v0, $v1, 1
	addu    $v0, $v1
	sll     $v0, 1
	addu    $v0, $a1, $v0
	lui     $v1, 0xA
	addiu   $a2, 1
	sb      $zero, 0x1A8($s3)
	lbu     $a0, 2($v0)
	sll     $v0, $a2, 1
	addu    $v0, $a2
	sll     $v0, 1
	addu    $a1, $v0
	sb      $a0, 0xA2034
	lhu     $v1, 4($a1)
	lui     $v0, 0xA
	sh      $v1, 0xA05C4

	loc_1240:                                # CODE XREF : sub_1054 + 170↑j
	lw      $v0, 0x4520($s4)
	nop
	andi    $v0, 0x1000
	beqz    $v0, loc_1258
	lui     $v0, 0xA
	sh      $zero, 0xA05C2

	loc_1258:                                # CODE XREF : sub_1054 + 1F8↑j
	move    $v0, $fp
	lw      $ra, 0x40 + var_4($sp)
	lw      $fp, 0x40 + var_8($sp)
	lw      $s7, 0x40 + var_C($sp)
	lw      $s6, 0x40 + var_10($sp)
	lw      $s5, 0x40 + var_14($sp)
	lw      $s4, 0x40 + var_18($sp)
	lw      $s3, 0x40 + var_1C($sp)
	lw      $s2, 0x40 + var_20($sp)
	lw      $s1, 0x40 + var_24($sp)
	lw      $s0, 0x40 + var_28($sp)
	jr      $ra
	addiu   $sp, 0x40
#endif

	return 0;
}