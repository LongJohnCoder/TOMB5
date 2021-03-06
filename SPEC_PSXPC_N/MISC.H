#ifndef MISC_H
#define MISC_H

#include <SYS/TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>

extern void S_MemSet(char* p, int value, int length);
extern void S_LongMemCpy(unsigned long* pDest, unsigned long* pSrc, unsigned long size);
extern void DrawF4(unsigned short x, unsigned short y, unsigned short w, unsigned short h, int unk, int unk2);
extern void DrawTPage(unsigned char a0, unsigned char a1);
extern void DrawLineH(unsigned short a0, unsigned short a1, unsigned short a2, unsigned char a3, unsigned long a4, unsigned long a5);
extern void DrawLineV(unsigned short a0, unsigned short a1, unsigned short a2, unsigned char a3, unsigned long a4, unsigned long a5);
extern void LOAD_VSyncHandler();
extern void LOAD_DrawEnable(unsigned char isEnabled);
extern void GPU_BeginScene();
extern void draw_rotate_sprite(long a0, long a1, long a2);
extern void GPU_ClearVRAM();
extern void clear_a_rect(RECT16* r);
extern void GPU_GetScreenPosition(short* x, short* y);
extern void GPU_SetScreenPosition(short x, short y);
extern void GPU_SyncBothScreens();
extern void GPU_FlipToBuffer(int buffer_index);
extern void S_AnimateTextures(long nFrames);
extern void PrintGauge(int x, int y, int length);
extern long GetRandomControl();
extern void SeedRandomControl(long seed);
extern long GetRandomDraw();
extern void SeedRandomDraw(long seed);
extern void S_MemCpy(char* dst, char* src, int size);
#endif