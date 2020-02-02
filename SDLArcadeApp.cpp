#include <iostream>
#include <SDL.h>
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int argc, char* argv[])
{
	
	Screen theScreen;

	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	
	Line2D line = { Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT) };

	theScreen.Draw(line, Color::Green());

	theScreen.SwapScreens();
	

	SDL_Event sdlEvent;
	bool running = true;

	// Mainloop
	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}


	}

	

	return 0;
}

