#include "TEXT_S.H"

#include "CONTROL.H"
#include "SPECIFIC.H"
#include "GPU.H"
#include "TEXT.H"
#include "TYPES.H"
#include "SPECTYPES.H"
#include <assert.h>
#include <LIBGTE.H>
#include <stdio.h>

struct CHARDEF loc_92020[139] =
{
{ 0x10 ,0x04 ,0x00 ,0x21 ,0x10 ,0x43 ,0x00 },
{ 0x00 ,0x00 ,0x52 ,0x84 ,0x74 ,0x33 ,0x83 },
{ 0x8F ,0xC0 ,0x10 ,0x12 ,0x00 ,0x21 ,0x10 },
{ 0x43 ,0x00 ,0x06 ,0x00 ,0x42 ,0x94 ,0x0B },
{ 0x00 ,0x10 ,0x3C ,0x90 ,0xB5 ,0x10 ,0x26 },
{ 0x82 ,0x10 ,0x02 ,0x00 ,0x0F ,0x00 ,0x42 },
{ 0x30 ,0x21 ,0x98 ,0x42 ,0x02 ,0x10 ,0x00 },
{ 0x03 ,0x8E ,0x00 ,0x00 ,0x00 ,0x00 ,0x2A },
{ 0x10 ,0x72 ,0x00 ,0x06 ,0x00 ,0x40 ,0x14 },
{ 0x2A ,0x10 ,0x73 ,0x00 ,0x04 ,0x00 ,0x40 },
{ 0x10 ,0xFF ,0xFF ,0x01 ,0x24 ,0x10 ,0x00 },
{ 0x01 ,0xAE ,0xA4 ,0x45 ,0x02 ,0x0C ,0x21 },
{ 0x20 ,0x20 ,0x02 ,0x01 ,0x00 ,0x31 ,0x26 },
{ 0x18 ,0x00 ,0x22 ,0x2A ,0xF3 ,0xFF ,0x40 },
{ 0x14 ,0x24 ,0x00 ,0x10 ,0x26 ,0x20 ,0x00 },
{ 0xBF ,0x8F ,0x1C ,0x00 ,0xB3 ,0x8F ,0x18 },
{ 0x00 ,0xB2 ,0x8F ,0x14 ,0x00 ,0xB1 ,0x8F },
{ 0x10 ,0x00 ,0xB0 ,0x8F ,0x08 ,0x00 ,0xE0 },
{ 0x03 ,0x24 ,0x00 ,0xBD ,0x27 ,0xFC ,0x0E },
{ 0x81 ,0x8F ,0x0B ,0x00 ,0x02 ,0x3C ,0x90 },
{ 0xB5 ,0x42 ,0x24 ,0x08 ,0x00 ,0x20 ,0x10 },
{ 0xFF ,0xFF ,0x03 ,0x24 ,0x18 ,0x00 ,0x04 },
{ 0x24 ,0x10 ,0x00 ,0x43 ,0xAC ,0xFF ,0xFF },
{ 0x84 ,0x24 ,0xFD ,0xFF ,0x80 ,0x14 ,0x24 },
{ 0x00 ,0x42 ,0x24 ,0x4D ,0x47 ,0x02 ,0x08 },
{ 0x00 ,0x00 ,0x00 ,0x00 ,0x08 ,0x00 ,0xE0 },
{ 0x03 ,0x00 ,0x00 ,0x00 ,0x00 ,0xFF ,0xFF },
{ 0x03 ,0x24 ,0x0B ,0x00 ,0x02 ,0x3C ,0x90 },
{ 0xB5 ,0x42 ,0x24 ,0x18 ,0x00 ,0x04 ,0x24 },
{ 0x10 ,0x00 ,0x43 ,0xAC ,0xFF ,0xFF ,0x84 },
{ 0x24 ,0xFD ,0xFF ,0x80 ,0x14 ,0x24 ,0x00 },
{ 0x42 ,0x24 ,0x01 ,0x00 ,0x02 ,0x24 ,0x08 },
{ 0x00 ,0xE0 ,0x03 ,0xFC ,0x0E ,0x82 ,0xAF },
{ 0xAE ,0x34 ,0x04 ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x62 ,0x3A ,0x07 ,0x05 ,0xF6 ,0x01 ,0x05 },
{ 0x52 ,0x1A ,0x0E ,0x0C ,0xF6 ,0x01 ,0x0B },
{ 0x4E ,0x26 ,0x0A ,0x0E ,0xF6 ,0x01 ,0x0D },
{ 0xD6 ,0x0D ,0x0F ,0x0C ,0xF7 ,0x02 ,0x0C },
{ 0x28 ,0x1A ,0x0E ,0x0C ,0xF6 ,0x01 ,0x0B },
{ 0x9E ,0x39 ,0x05 ,0x05 ,0xF5 ,0x00 ,0x04 },
{ 0xCC ,0x27 ,0x06 ,0x10 ,0xF4 ,0x00 ,0x0D },
{ 0x22 ,0x28 ,0x06 ,0x10 ,0xF5 ,0x00 ,0x0E },
{ 0xB8 ,0x3B ,0x05 ,0x05 ,0xF5 ,0x00 ,0x04 },
{ 0x16 ,0x28 ,0x0B ,0x0B ,0xF7 ,0x02 ,0x0B },
{ 0xB2 ,0x3B ,0x05 ,0x05 ,0xFE ,0x08 ,0x0C },
{ 0x6A ,0x3C ,0x08 ,0x03 ,0xFC ,0x06 ,0x09 },
{ 0x72 ,0x3C ,0x05 ,0x04 ,0xFE ,0x08 ,0x0B },
{ 0xD4 ,0x26 ,0x09 ,0x0F ,0xF4 ,0x00 ,0x0C },
{ 0x58 ,0x31 ,0x0A ,0x0A ,0xF8 ,0x03 ,0x0B },
{ 0xC8 ,0x37 ,0x06 ,0x0A ,0xF8 ,0x03 ,0x0B },
{ 0x2E ,0x34 ,0x09 ,0x0A ,0xF8 ,0x03 ,0x0B },
{ 0x58 ,0x26 ,0x08 ,0x0B ,0xF8 ,0x03 ,0x0C },
{ 0x3E ,0x28 ,0x0B ,0x0B ,0xF8 ,0x03 ,0x0C },
{ 0x8E ,0x30 ,0x09 ,0x0C ,0xF7 ,0x02 ,0x0C },
{ 0xE8 ,0x32 ,0x09 ,0x0B ,0xF7 ,0x02 ,0x0B },
{ 0x78 ,0x2F ,0x09 ,0x0C ,0xF7 ,0x02 ,0x0C },
{ 0x16 ,0x33 ,0x09 ,0x0B ,0xF7 ,0x02 ,0x0B },
{ 0x6E ,0x31 ,0x09 ,0x0B ,0xF8 ,0x03 ,0x0C },
{ 0x98 ,0x39 ,0x05 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x88 ,0x39 ,0x05 ,0x0A ,0xF9 ,0x04 ,0x0C },
{ 0xB2 ,0x28 ,0x0C ,0x0A ,0xF8 ,0x03 ,0x0B },
{ 0xD2 ,0x35 ,0x0B ,0x07 ,0xF9 ,0x04 ,0x09 },
{ 0xF0 ,0x28 ,0x0C ,0x0A ,0xF8 ,0x03 ,0x0B },
{ 0x0C ,0x27 ,0x0A ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x42 ,0x0D ,0x10 ,0x0E ,0xF6 ,0x01 ,0x0D },
{ 0x82 ,0x0D ,0x0E ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xD6 ,0x19 ,0x0D ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x84 ,0x23 ,0x0B ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x00 ,0x1A ,0x0D ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x0E ,0x1A ,0x0D ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x42 ,0x1B ,0x0C ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xB6 ,0x1B ,0x0C ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xC8 ,0x0D ,0x0E ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xDE ,0x36 ,0x05 ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x38 ,0x34 ,0x05 ,0x10 ,0xF5 ,0x00 ,0x0E },
{ 0xE6 ,0x0F ,0x0D ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x90 ,0x23 ,0x0B ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x30 ,0x0D ,0x12 ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x90 ,0x0D ,0x0E ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x36 ,0x1A ,0x0C ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xC8 ,0x1A ,0x0C ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xF0 ,0x00 ,0x0E ,0x0F ,0xF5 ,0x00 ,0x0D },
{ 0x9E ,0x0D ,0x0E ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x9C ,0x23 ,0x0B ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xAC ,0x0D ,0x0E ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x62 ,0x0D ,0x0F ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x52 ,0x0D ,0x0F ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x18 ,0x0D ,0x17 ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xBA ,0x0D ,0x0D ,0x0E ,0xF5 ,0x00 ,0x0C },
{ 0x72 ,0x0D ,0x0F ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0xE4 ,0x1C ,0x0C ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x3E ,0x3C ,0x06 ,0x04 ,0xFC ,0x06 ,0x09 },
{ 0xF8 ,0x3B ,0x06 ,0x04 ,0xFC ,0x06 ,0x09 },
{ 0x58 ,0x3B ,0x08 ,0x04 ,0xFC ,0x06 ,0x09 },
{ 0x8E ,0x3C ,0x07 ,0x03 ,0xFD ,0x07 ,0x09 },
{ 0x78 ,0x3B ,0x08 ,0x04 ,0xFC ,0x06 ,0x09 },
{ 0xF2 ,0x3B ,0x05 ,0x05 ,0xF5 ,0x00 ,0x04 },
{ 0x62 ,0x31 ,0x0B ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x60 ,0x23 ,0x0B ,0x0E ,0xF4 ,0x00 ,0x0B },
{ 0x48 ,0x34 ,0x09 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x00 ,0x27 ,0x0B ,0x0C ,0xF6 ,0x01 ,0x0B },
{ 0xA4 ,0x34 ,0x09 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0xA8 ,0x26 ,0x0A ,0x0E ,0xF4 ,0x00 ,0x0B },
{ 0x78 ,0x23 ,0x0C ,0x0C ,0xF9 ,0x04 ,0x0E },
{ 0x6C ,0x23 ,0x0B ,0x0E ,0xF4 ,0x00 ,0x0B },
{ 0xC2 ,0x1B ,0x06 ,0x0C ,0xF6 ,0x01 ,0x0B },
{ 0x28 ,0x33 ,0x06 ,0x10 ,0xF6 ,0x01 ,0x0E },
{ 0x1C ,0x1A ,0x0C ,0x0E ,0xF4 ,0x00 ,0x0B },
{ 0x52 ,0x34 ,0x06 ,0x0D ,0xF5 ,0x00 ,0x0B },
{ 0x60 ,0x1A ,0x12 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x98 ,0x30 ,0x0C ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x3E ,0x33 ,0x0A ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0xF4 ,0x0F ,0x0B ,0x0D ,0xF9 ,0x04 ,0x0E },
{ 0x34 ,0x27 ,0x0A ,0x0D ,0xF9 ,0x04 ,0x0E },
{ 0x0A ,0x34 ,0x0A ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0xBE ,0x34 ,0x09 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x00 ,0x33 ,0x09 ,0x0B ,0xF7 ,0x02 ,0x0B },
{ 0xB2 ,0x32 ,0x0B ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x82 ,0x30 ,0x0C ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x84 ,0x1A ,0x12 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0xF2 ,0x32 ,0x0B ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0x28 ,0x26 ,0x0B ,0x0D ,0xF9 ,0x04 ,0x0E },
{ 0xE8 ,0x29 ,0x08 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0xDE ,0x29 ,0x09 ,0x0D ,0xF9 ,0x04 ,0x0E },
{ 0x82 ,0x39 ,0x06 ,0x09 ,0xF9 ,0x04 ,0x0B },
{ 0xC2 ,0x27 ,0x0A ,0x0D ,0xF6 ,0x01 ,0x0C },
{ 0x20 ,0x38 ,0x05 ,0x0C ,0xF6 ,0x01 ,0x0B },
{ 0x00 ,0x0D ,0x18 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0xC0 ,0x00 ,0x18 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0xA8 ,0x00 ,0x18 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0xD8 ,0x00 ,0x18 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0x96 ,0x1A ,0x12 ,0x09 ,0xF8 ,0x06 ,0x0B },
{ 0xA8 ,0x1A ,0x0D ,0x0C ,0xF7 ,0x06 ,0x0B },
{ 0x72 ,0x1A ,0x12 ,0x09 ,0xF8 ,0x06 ,0x0B },
{ 0xF0 ,0x1C ,0x0D ,0x0C ,0xF7 ,0x06 ,0x0B },
{ 0x00 ,0x00 ,0x29 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0x54 ,0x00 ,0x29 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0x2A ,0x00 ,0x29 ,0x0D ,0xF6 ,0x06 ,0x0B },
{ 0x7E ,0x00 ,0x29 ,0x0D ,0xF6 ,0x06 ,0x0B },
};

struct CHARDEF word_9230E[32] =
{
{ 0x1C, 0x1A, 0x0C, 0x0E, 0xF4, 0x00, 0x0B },
{ 0x52, 0x34, 0x06, 0x0D, 0xF5, 0x00, 0x0B },
{ 0x60, 0x1A, 0x12, 0x09, 0xF9, 0x04, 0x0B },
{ 0x98, 0x30, 0x0C, 0x09, 0xF9, 0x04, 0x0B },
{ 0x3E, 0x33, 0x0A, 0x09, 0xF9, 0x04, 0x0B },
{ 0xF4, 0x0F, 0x0B, 0x0D, 0xF9, 0x04, 0x0E },
{ 0x34, 0x27, 0x0A, 0x0D, 0xF9, 0x04, 0x0E },
{ 0x0A, 0x34, 0x0A, 0x09, 0xF9, 0x04, 0x0B },
{ 0xBE, 0x34, 0x09, 0x09, 0xF9, 0x04, 0x0B },
{ 0x00, 0x33, 0x09, 0x0B, 0xF7, 0x02, 0x0B },
{ 0xB2, 0x32, 0x0B, 0x09, 0xF9, 0x04, 0x0B },
{ 0x82, 0x30, 0x0C, 0x09, 0xF9, 0x04, 0x0B },
{ 0x84, 0x1A, 0x12, 0x09, 0xF9, 0x04, 0x0B },
{ 0xF2, 0x32, 0x0B, 0x09, 0xF9, 0x04, 0x0B },
{ 0x28, 0x26, 0x0B, 0x0D, 0xF9, 0x04, 0x0E },
{ 0xE8, 0x29, 0x08, 0x09, 0xF9, 0x04, 0x0B },
{ 0xDE, 0x29, 0x09, 0x0D, 0xF9, 0x04, 0x0E },
{ 0x82, 0x39, 0x06, 0x09, 0xF9, 0x04, 0x0B },
{ 0xC2, 0x27, 0x0A, 0x0D, 0xF6, 0x01, 0x0C },
{ 0x20, 0x38, 0x05, 0x0C, 0xF6, 0x01, 0x0B },
{ 0x00, 0x0D, 0x18, 0x0D, 0xF6, 0x06, 0x0B },
{ 0xC0, 0x00, 0x18, 0x0D, 0xF6, 0x06, 0x0B },
{ 0xA8, 0x00, 0x18, 0x0D, 0xF6, 0x06, 0x0B },
{ 0xD8, 0x00, 0x18, 0x0D, 0xF6, 0x06, 0x0B },
{ 0x96, 0x1A, 0x12, 0x09, 0xF8, 0x06, 0x0B },
{ 0xA8, 0x1A, 0x0D, 0x0C, 0xF7, 0x06, 0x0B },
{ 0x72, 0x1A, 0x12, 0x09, 0xF8, 0x06, 0x0B },
{ 0xF0, 0x1C, 0x0D, 0x0C, 0xF7, 0x06, 0x0B },
{ 0x00, 0x00, 0x29, 0x0D, 0xF6, 0x06, 0x0B },
{ 0x54, 0x00, 0x29, 0x0D, 0xF6, 0x06, 0x0B },
{ 0x2A, 0x00, 0x29, 0x0D, 0xF6, 0x06, 0x0B },
{ 0x7E, 0x00, 0x29, 0x0D, 0xF6, 0x06, 0x0B }
};

#if 1

void PrintString(unsigned short x, unsigned short y, unsigned char colourFlag, char* string, unsigned short flag)//8DB4C, 8FB90
{
	char c;
	unsigned short var_2E;
	unsigned short var_2C;
	unsigned short var_30;
	int s2 = 0;
	//s0 = a0
	//s4 = a1
	int s3 = colourFlag;
	//s5 = string
	//s6 = flag
	//at = GnFrameCounter

#if _DEBUG
	printf("PrintString: %s X: %d Y: %d\n", string, x, y);
#endif

	if ((flag & 0x2000) && (GnFrameCounter & 0x10))
	{
		//loc_8DD68
		return;
	}
	//loc_8DBA0
	//v0 = (flag >> 12) & 1;
	ScaleFlag = (flag >> 12) & 1;
	int v0 = GetStringLength(string, 0, &var_30);

	/*
	sub_8FDD4
	*/

	if ((flag & 0x8000))
	{
		s2 = x - (v0 >> 1);
	}
	else if ((flag & 0x4000))
	{
		s2 = x + v0;
	}
	else
	{
		s2 = x;
	}


	c = *string++;
	if (c != 0)
	{
		//v0 = 0x20
		do
		{
			if (c == 0xA)
			{
				//v0 = *string
				//a1 = &var_2E

				if (c == *string)
				{
					//a0 = string
					//var_30 = 0
					y += 16;
					//j loc_8DD54
				}
				else
				{
					//loc_8DBE8
					v0 = GetStringLength(string, &var_2E, &var_2C);
					
					if ((flag & 0x8000))
					{
						s2 = x - (v0 >> 1);
					}
					else if ((flag & 0x4000))
					{
						s2 = x + v0;
					}
					else
					{
						s2 = x;
					}

					//jal sub_8DD90
					//v1 = var_30
					//v0 = var_2E
					//a0 = var_2C
					//v1 -= v0
					//v1 += 2;
					y += (var_30 - var_2E) + 2;
					var_30 = var_2C;
					//j       loc_8DD54
				}
			}//v0 = 0x9
			else if (c == 0x20)
			{
				//loc_8DC14
				if (!(flag & 0x1000))
				{
					s2 += 2;
				}
				else
				{
					s2 += 6;
				}
				//j loc_8DD54
			}
			else if (c == 0x9)
			{
				//loc_8DC30
				s2 += 0x28;
				//j loc_8DD54
			}//v0 = c - 1
			else if (c < 0x14)
			{
				s3 = (c - 1) & 0xFF;
				//j       loc_8DD54
			}
			else if ((unsigned int)(c - 0x80) < 0x2E)
			{
				assert(0);//Not debugged
				//t1 = &aUEAAAAEEEAAEOO[(c- 0x80) << 1];
				//v1 = t1[-1]
				//s1 = &loc_92020[1];

				//v0 = v1 << 3;
				//v0 -= v1;
				//s1 += v0

				//DrawChar(s2, y, s3, s1);

				//v1 = t1[0]
				//at = 0x20
				//v0 = v1 << 3
				///if (t1[0] == 0x20)
				{
					//jmp loc_8DD3C? continue?
				}

				//v0 -= v1
				//a3 = &loc_92020[1];
				//a3 = v0 + a3;

				//a0 = ((s1[2] >> 1) + s2) - 3;
				//a1 = s4 + s1[4]

				///DrawChar(a0, a1, a2, a3);
				//addiu   $ra, 0x60  ***************** check where i land!
			}
			else//CHECKME might not be else case see above addiu ra
			{
				//loc_8DCDC
				//v0 = c << 3
				//v0 -= c
				//at = a0 < 0x20 ? 1 : 0
				//a2 = s3
				if (c < 0x20)
				{
					//v1 = &word_9230E
					c -= 0x18;
					//s1 = v0 + v1
					if (c > 3)
					{
						DrawChar(s2, y, 0, &word_9230E[c + 0x18]);
						//addiu ra 0x1C ***************checkme
					}//loc_8DD0C
					else
					{
						DrawChar(s2, y, s3, &word_9230E[c + 0x18]);
						//addiu ra 0x1C ***************checkme
					}
				}
				//loc_8DD20
				CHARDEF* s1 = &loc_92020[c];
				DrawChar(s2, y, s3, s1);

				if ((flag & 0x1000))
				{
					s2 += s1->w - (s1->w >> 2);
				}
				else
				{
					//loc_8DD50
					s2 += s1->w;
				}
			}

			//loc_8DD54
			c = *string++;
		} while (c != 0);
	}

	ScaleFlag = 0;
}

int GetStringLength(char* string, unsigned short* a1, unsigned short* a2)//8DEDC(<), 8FF20(<)
{
	int t5 = 0;
	int t0 = 0;
	int t2 = -1024;
	char c = *string++;//a3
	int t1 = 1024;
	int a3 = 0;
	int t3 = 0;
	int v0 = 0;
	struct CHARDEF* a33;

	if (c != 0)
	{
		if (c != 0xA)
		{
			t3 = ScaleFlag;

			//loc_8DF18
		loc_8DF18:
			if (c == 0x20)
			{
				if (ScaleFlag != 0)
				{
					t0 -= 2;
				}
				else
				{
					t0 += 8;
				}
			}
			else if (c == 0x9)
			{
				//loc_8DF30
				t0 += 0x28;

				if (t1 > -0xA)
				{
					t1 = -12;
				}//loc_8DF4C

				if (t2 < 2)
				{
					t2 = 2;
				}
			}
			else if (c > 0x13)
			{
				//loc_8DF5C
				if (c < 0x20)
				{
					a33 = &CharDef[c + 74];
				}
				else
				{
					//loc_8DF7C
					if ((unsigned int)(c - 0x80) < 0x2E)
					{
						a3 = AccentTable[0][c - 0x80];
						t5 = 1;
						assert(0);//Not debugged, colliding register type here!
					}

					//loc_8DF98
					a33 = &CharDef[c - 33];
				}
				//loc_8DFA8
				v0 = a33->w;

				if (t3 != 0)
				{
					v0 = a33->w - (a33->w >> 2);
				}

				//loc_8DFB8
				t0 += v0;

				if (a33->YOffset < t1)
				{
					t1 = a33->YOffset;
				}//loc_8DFD4

				if (t2 < a33->YOffset + a33->h)
				{
					t2 = a33->YOffset + a33->h;
				}
			}
			//loc_8DFE4
			c = *string++;

			//v0 = 0xA
			if (c != 0)
			{
				//v0 = 0x20
				if (c != 0xA)
				{
					goto loc_8DF18;
				}
			}//loc_8DFFC
		}//loc_8DFFC
	}
	//loc_8DFFC
	if (a1 != NULL)
	{
		if (t5 != 0)
		{
			t1 -= 4;
		}//loc_8E010

		*a1 = t1;
	}//loc_8E014

	if (a2 != NULL)
	{
		*a2 = t2;
	}

	return t0;
}

void GetStringDimensions(char* string, unsigned short* w, unsigned short* h)
{
	unsigned short dw;//sp 0x18
	unsigned short dh;//sp 0x16
	int fw;
	int fh;
	int strlength;
	char c;//a0

	fw = GetStringLength(string, &dw, &dh);
	fh = (dh - dw) + 2;

	//loc_8E070
	while (c = *string++)
	{
		if (c == 0xA)
		{
			if (*string != 0xA)
			{
				//loc_8E094
				if (*string != 0x0)
				{
					strlength = GetStringLength(string, &dw, &dh);

					fh = (fh + 2) + dh;
					if (fw < strlength)
					{
						fw = strlength;
					}
				}
			}
			else
			{
				fh += 16;
			}
		}
		//loc_8E0CC
	}

	*h = fh;
	*w = fw;
}
#endif

void DrawChar(unsigned short a0, unsigned short a1, unsigned short colourFlag, struct CHARDEF* a3)//8DDBC(<), 8FE00(<) (F)
{
	CVECTOR* TopShade;//$v0
	CVECTOR* BottomShade;//$at
	long v1;

	colourFlag &= 0xFFFF;
	if ((unsigned long) &db.polyptr[0] < (unsigned long) &db.polybuf_limit[0])
	{
		//v1 = &FontShades[0][0];

		TopShade = &FontShades[colourFlag][a3->TopShade];
		BottomShade = &FontShades[colourFlag][a3->BottomShade];

		*((long*) &db.polyptr[4])= *(long*) &TopShade->r;
		*((long*) &db.polyptr[28]) = *(long*) &BottomShade->r;
		*((long*) &db.polyptr[16]) = *(long*) &TopShade->r;
		*((long*) &db.polyptr[40]) = *(long*) &BottomShade->r;

		((char*) db.polyptr)[7] = 0x3C;//#define TAG_PGT4                    0x3C

		*(short*) &db.polyptr[14] = 4197;
		*(short*) &db.polyptr[26] = 41;
		//sizeof(POLY_GT4);

		v1 = a3->w;
		a1 += a3->YOffset;

		if (ScaleFlag != 0)
		{
			v1 = (a3->w >> 2) - a3->w + 1;
		}

		//loc_8DE5C
		*(short*) &db.polyptr[8] = a0;
		*(short*) &db.polyptr[10] = a1;
		*(short*) &db.polyptr[20] = a0 + v1;
		*(short*) &db.polyptr[22] = a1;

		*(short*) &db.polyptr[32] = a0;
		*(short*) &db.polyptr[34] = a1 + a3->h;
		*(short*) &db.polyptr[44] = a0 + v1;
		*(short*) &db.polyptr[46] = a1 + a3->h;

		*(char*) &db.polyptr[12] = a3->u;
		*(char*) &db.polyptr[13] = a3->v;
		*(char*) &db.polyptr[24] = a3->u + v1;
		*(char*) &db.polyptr[25] = a3->v;

		*(char*) &db.polyptr[36] = a3->u;
		*(char*) &db.polyptr[37] = a3->v + a3->h;
		*(char*) &db.polyptr[48] = a3->u + a3->w;
		*(char*) &db.polyptr[49] = a3->v + a3->h;

		//a3 = db.ot
		//v0 = db.ot[0] | 0xC000000;
		*(long*)&db.polyptr[0] = db.ot[0] | 0xC000000;
		db.ot[0] = (unsigned long)db.polyptr;
		

		//db.ot[0] = (unsigned long)db.polyptr;
		//*(long*)&db.polyptr[0] = db.ot[0] | 0xC000000;
		db.polyptr += 0x34;
	}//locret_8DED4
}

void UpdatePulseColour()//8E0F8(<), 9013C(<) (F)
{
	int i;
	unsigned int localPulseCnt = 0;

	localPulseCnt = PulseCnt = (++PulseCnt & 0x1F);
	if (localPulseCnt > 15)
	{
		localPulseCnt = -localPulseCnt;
	}

	//loc_8E11C
	//loc_8E138
	for (i = 0; i < 16; i++)
	{
		((int*)&FontShades[1][i])[0] = ((localPulseCnt << 3) & 0xFF) | (((localPulseCnt << 3) & 0xFF) << 8) | (((localPulseCnt << 3) & 0xFF) << 16);
		((int*)&FontShades[9][i])[0] = (GlobalCounter << 3) - (GlobalCounter & 0x3F);
	}
	return;
}