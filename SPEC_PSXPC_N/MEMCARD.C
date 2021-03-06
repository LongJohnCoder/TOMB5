#include "MEMCARD.H"

#include "3D_OBJ.H"
#include "GAMEFLOW.H"

#include <string.h>
#include <KERNEL.H>

#include <LIBMCRD.H>
#include <LIBETC.H>
#include <STRINGS.H>

unsigned char mcInit;
unsigned char mcStatus;
unsigned long mcNumFiles;
unsigned char mcBlocksFree;
char mcFileNames[7][20];
int mcFileLengths[7];
static unsigned char mcActualStatus;

void mcDir()//61EE8(<), 625CC(<)
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct DIRENTRY* dir = (struct DIRENTRY*)&tsv_buffer[0];

	MemCardGetDirentry(0, "*", dir, (long*)&mcNumFiles, 0, 0);

	mcBlocksFree = 15;
	
	if(mcNumFiles > 0)
	{
		//loc_61F50
		for(i = 0; i < mcNumFiles; i++, j++, k++, dir++)
		{
			//loc_61F68
			mcBlocksFree -= dir->size + 0x1FFF < 0 ? dir->size + 0x3FFE : dir->size + 0x1FFF;
			
			if(strncmp(&gfStringWad[gfStringOffset[STR_PSX_GAME_ID]], dir->name, 12) == 0)
			{
				((int*)&mcFileNames[i][0])[0] = ((int*)&dir->name)[0];
				((int*)&mcFileNames[i][4])[0] = ((int*)&dir->name[4])[0];
				((int*)&mcFileNames[i][8])[0] = ((int*)&dir->name[8])[0];
				((int*)&mcFileNames[i][12])[0] = ((int*)&dir->name[12])[0];
				((int*)&mcFileNames[i][16])[0] = ((int*)&dir->name[16])[0];
				
				mcFileLengths[j] = dir->size;
			}
		}
	}//loc_62028
	
	//loc_62028
	mcNumFiles = k;//k
	return;
}

void mcOpen(int sync)//6204C(<), 62730(<) (F)
{
	int i;

	mcInit = 1;
	mcNumFiles = 0;
	mcBlocksFree = 0;
	mcStatus = 4;
	mcActualStatus = 0;

	MemCardStart();

	if (sync != 0)
	{
		for (i = 0; i < 4; i++)
		{
			//loc_62084
			mcGetStatus();
			VSync(0);
		}
	}

	//loc_6209C
	return;
}

void mcClose()//620AC //(F)
{
	MemCardStop();
	mcInit = 0;
	
	return;
}

unsigned char mcGetStatus()//620CC(<), 627B0 (F)
{
	long stat;
	unsigned long cmd;
	unsigned long res;

	stat = MemCardSync(1, (long*)&cmd, (long*)&res);

	if (stat == 0)
	{
		//loc_62130
		if (cmd == McFuncReadFile)
		{
			mcStatus = 5;
		}//loc_62150
		else if (cmd == McFuncWriteData)
		{
			mcStatus = cmd;
		}
		else if (cmd == McFuncAccept)
		{
			mcStatus = 4;
		}
	}
	else if (stat > 0)
	{
		//loc_62110
		if (stat == 1)
		{
			//loc_62178
			if (cmd == 2)
			{
				//loc_62210
				if (res == 3)
				{
					//loc_62248
					mcDir();
					mcActualStatus = 0;
					mcStatus = 0;
				}
				else if (res > 3)
				{
					//loc_62238
					if (res == 4)
					{
						//loc_6225C
						mcStatus = cmd;
						mcActualStatus = cmd;
					}
				}
				else if (res == 0)
				{
					//loc_6228C
					mcStatus = 0;
				}
				else
				{
					//loc_6226C
					mcStatus = 3;
					mcActualStatus = 3;
				}
			}
			else if (cmd > 2)
			{
				//loc_621A0
				if (cmd == 3)
				{
					//loc_6227C
					if (res != 0)
					{
						MemCardAccept(0);
						mcStatus = 3;
					}
					else
					{
						mcStatus = 0;
					}
				}
				else if (cmd == 6)
				{
					//loc_62298
					if (res != 0)
					{
						//loc_622B8
						MemCardAccept(0);
						mcStatus = 3;
					}
					else
					{
						mcDir();
						mcStatus = 0;
					}
				}
			}
			else if (cmd == stat)
			{
				//loc_621B8
				if (res != 0)
				{
					//loc_621B8
					if (res == 3)
					{
						//loc_621EC
						MemCardAccept(0);
						mcStatus = 4;
					}
					else
					{
						//loc_62204
						mcStatus = 1;
					}
				}
				else
				{
					//loc_621D8
					mcStatus = mcActualStatus;
				}
			}
		}
	}
	else if (stat == -1)
	{
		//loc_62120
		MemCardExist(0);
	}

	//loc_622C4
	return mcStatus;
}

long mcFormat()//622D8(<), 629BC(<) (F)
{
	unsigned long cmd;
	unsigned long res;

	MemCardSync(0, (long*)&cmd, (long*)&res);

	res = MemCardFormat(0);
	if (res == 0)
	{
		mcActualStatus = 0;
		mcDir();
	}

	//loc_6230C
	return res;
}