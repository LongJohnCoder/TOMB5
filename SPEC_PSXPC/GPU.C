#include "GPU.H"

#include "PROFILE.H"
#include "PSXPCINPUT.H"
#include "SHADOWS.H"

#include <stdlib.h>
#include <stdio.h>

unsigned long GnFrameCounter = 19;
unsigned long GnLastFrameCount = 19;
struct PSXTEXTSTRUCT* psxtextinfo;
struct PSXSPRITESTRUCT* psxspriteinfo;
int rgbscaleme = 256;
int gfx_debugging_mode;
struct DB_STRUCT db;
struct MMTEXTURE* RoomTextInfo;
unsigned long GadwOrderingTables_V2[512];
static int LnFlipFrame;
unsigned long GadwOrderingTables[5128];
unsigned long GadwPolygonBuffers[52260];

SDL_Window* g_window = NULL;

void GPU_UseOrderingTables(unsigned long* pBuffers, int nOTSize)//5DF68(<), 5F1C8(<)
{
	//Should be safe to use 32-bit ptrs tho
	db.order_table[0] = (unsigned long*)((unsigned long)pBuffers);
	db.order_table[1] = (unsigned long*)((unsigned long)&pBuffers[nOTSize]);
	db.nOTSize = nOTSize;
	db.pickup_order_table[0] = (unsigned long*)((unsigned long)&db.disp[1]);
	db.pickup_order_table[1] = (unsigned long*)((unsigned long)&GadwOrderingTables_V2[256]);
	return;
}

void GPU_UsePolygonBuffers(unsigned long* pBuffers, int nPBSize)//5DFB0(<), 
{
	db.nPBSize = nPBSize;
	db.poly_buffer[0] = (unsigned long*)((unsigned long)pBuffers);
	db.poly_buffer[1] = (unsigned long*)((unsigned long)&pBuffers[nPBSize]);
	return;
}

void GPU_EndScene()//5DFDC(<), 5F23C(<) (F)
{
#if DEBUG_VERSION
	int nPolys = 0;
	static int nWorstPolys;

	//nPolys = ((int)&db.polyptr[0] - (int)&db.curpolybuf[0]) * 0x4EC4EC4F / 16 - (((long)&db.polyptr[0] - (long)&db.curpolybuf[0]) >> 31);

	if (psxtextinfo->u2v2pad < nPolys)
	{
		psxtextinfo->u2v2pad = nPolys;
	}

	//loc_5E020
#endif

	OptimiseOTagR(&db.ot[0], db.nOTSize);

#if DEBUG_VERSION
	ProfileRGB(255, 255, 255);
	do_gfx_debug_mode(&db.ot[db.nOTSize - 1]);
	ProfileRGB(0, 255, 255);
#endif

	SDL_GL_SwapWindow(g_window);

	return;
}

int GPU_FlipNoIdle()//5E078(<), 5F264(<)
{
#if DEBUG_VERSION
	if (ProfileDraw)
	{
		ProfileRGB(255, 255, 255);
		ProfileAddOT(&db.ot[0]);
	}//loc_5E0B0
#endif

#if DEBUG_VERSION
	if (ProfileDraw)
	{
		ProfileAddDrawOT(&db.ot[0]);
	}//loc_5E0D8
#endif

	LnFlipFrame = GnLastFrameCount;

	if (LnFlipFrame < 2)
	{
		//loc_5E0F4
		do
		{
			LnFlipFrame++;
		} while (LnFlipFrame < 2);
	}
	else
	{
		//loc_5E120
		LnFlipFrame++;
	}

	//loc_5E138
	GnLastFrameCount = 0;

#if DEBUG_VERSION
	ProfileStartCount();
#endif

	db.current_buffer ^= 1;

	return LnFlipFrame;
}

void do_gfx_debug_mode(unsigned long* otstart)
{
#if 0
	unsigned long* data;
	unsigned char code;
	int ntri;
	int nquad;
	unsigned short x0;
	unsigned short y0;
	unsigned short x1;
	unsigned short y1;
	unsigned short x2;
	unsigned short y2;
	//LINE_F2* line2;
	char txbuf[64];

	if (RawEdge & 8)
	{
		gfx_debugging_mode++;
	}

	//loc_5E1E0
	nquad = 0;

	if (gfx_debugging_mode > 2)
	{
		gfx_debugging_mode = 0;
	}

	//loc_5E1F8
	data = (unsigned long*)otstart[0];
	ntri = 0;

	if (((unsigned long)data & 0xFFFFFF) != 0xFFFFFF)
	{
		do
		{
			if (data[0] & 0xFF000000 != 0)
			{
				code = ((char*)data)[7];//getcode

				if (gfx_debugging_mode < 2)
				{
					if ((code & 0xFC) == 0x7C)
					{
						if (gfx_debugging_mode != 0)
						{
							((short*)data)[13] &= 0xFF9F;
						}
						else
						{
							//loc_5E27C
							((char*)data)[7] = (code & 2) | 0x3C;//setcode
						}

						nquad = 1;
					}
					else if ((code & 0xFC) == 0x74)
					{
						//loc_5E290
						if (gfx_debugging_mode != 0)
						{
							((char*)data)[7] = 0x36;
							((short*)data)[13] &= 0xFF9F;
						}
						else
						{
							//loc_5E2B4
							((char*)data)[7] = (code & 2) | 0x34;
						}

						ntri = 1;
					}//loc_5E3C4
				}
				else if (gfx_debugging_mode == 2)
				{
					//loc_5E2C8

					if ((code & 0xFC) == 0x7C)
					{
						x0 = ((unsigned short*)data)[4];
						y0 = ((unsigned short*)data)[5];
						x1 = ((unsigned short*)data)[10];
						y1 = ((unsigned short*)data)[11];
						x2 = ((unsigned short*)data)[16];
						y2 = ((unsigned short*)data)[17];

						nquad++;

						((char*)data)[7] = 0x4C;
						((char*)data)[4] = 0x0;
						((char*)data)[5] = 0x50;
						((char*)data)[6] = 0x0;
						((long*)data)[6] = 0x55555555;

						((short*)data)[8] = ((unsigned short*)data)[22];

						//line2 = (struct LINE_F2*)&data[6];

						((short*)data)[9] = ((unsigned short*)data)[23];

						((short*)data)[4] = x0;
						((short*)data)[5] = y0;
						((short*)data)[6] = x1;
						((short*)data)[7] = y1;
						((short*)data)[10] = x2;
						((short*)data)[11] = y2;

						/*line2->code = 0x40;
						line2->x0 = x0;
						line2->y0 = y0;
						line2->x1 = x2;
						line2->y1 = y2;
						line2->r0 = 0;
						line2->g0 = 80;
						line2->b0 = 0;*/

						((char*)data)[3] = 9;
					}
					else if ((code & 0xFC) == 0x74)
					{
						//loc_5E368
						ntri++;

						x0 = ((unsigned short*)data)[4];
						y0 = ((unsigned short*)data)[5];
						x1 = ((unsigned short*)data)[10];
						y1 = ((unsigned short*)data)[11];
						x2 = ((unsigned short*)data)[16];
						y2 = ((unsigned short*)data)[17];

						((char*)data)[7] = 76;
						((char*)data)[4] = 0;
						((char*)data)[5] = 80;
						((char*)data)[6] = 0;
						((long*)data)[6] = 0x55555555;
						((char*)data)[3] = 6;
						((short*)data)[4] = x0;
						((short*)data)[5] = y0;
						((short*)data)[6] = x1;
						((short*)data)[7] = y1;
						((short*)data)[8] = x2;
						((short*)data)[9] = y2;
						((short*)data)[10] = x0;
						((short*)data)[11] = y0;
					}
				}//loc_5E3C4
			}
		} while (data[0] != 0xFFFFFF);
		//loc_5E3C4
	}

	//loc_5E3D8
	if (gfx_debugging_mode == 0)
	{
		return;
	}

	sprintf(&txbuf[0], "TRI %d", ntri);
	PrintString(34, 220, 3, &txbuf[0], 0);

	sprintf(&txbuf[0], "QUAD %d", nquad);
	PrintString(34, 232, 3, &txbuf[0], 0);
#endif
}

void GPU_FlipStory(unsigned long* gfx)//5E448(<), * (F)
{
#if 0
	RECT r;
	RECT* fuckmyanalpassage;

	fuckmyanalpassage = (RECT*) &db.disp[db.current_buffer ^ 1].disp;
	r.x = fuckmyanalpassage->x;
	r.y = fuckmyanalpassage->y;
	r.w = fuckmyanalpassage->w;
	r.h = fuckmyanalpassage->h;
	LoadImage(&r, gfx);

	DrawOTagEnv(&db.ot[db.nOTSize - 1], &db.draw[db.current_buffer]);
	db.current_buffer ^= 1;
#endif
}