#include "LIBETC.H"

#include <stdio.h>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "EMULATOR.H"
#include "EMULATOR_GLOBALS.H"


void(*vsync_callback)(void) = NULL;

int ResetCallback(void)
{
	vsync_callback = NULL;
	UNIMPLEMENTED();
	return 0;
}

int VSync(int mode)
{
	if (mode == 0)
	{
		if (vsync_callback != NULL)
		{
			vsync_callback();
		}

		while (lastTime - SDL_GetTicks() < (1000 / 60))
		{
			SDL_Delay(1);
		}

		Emulator_EndScene();
	}

	return 0;
}

int VSyncCallback(void(*f)(void))
{
	vsync_callback = f;
	return 0;
}

long GetVideoMode(void)
{
	return MODE_NTSC;
}
