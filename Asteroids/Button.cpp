#include <iostream>
#include <SDL.h>

using namespace std;

bool XYInRect(const SDL_Rect& rect, int x, int y)
{
	return (true);
}

int main(int argc, char* argv[])
{
	bool running = true;
	SDL_Event event;
	Uint8 *keyStates = SDL_GetKeyState(0);

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface *screen;
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	SDL_Surface *encryptBMP;
	encryptBMP = SDL_LoadBMP("Encrypt.bmp");

	Uint32 screenColor = SDL_MapRGB(screen->format, 25, 23, 90);

	SDL_Rect offset;
	offset.x = 40;
	offset.y = 40;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}


		if (event.type == SDL_MOUSEBUTTONDOWN) // if the user clicked a mousebutton
		{
			if (XYInRect(offset, event.motion.x, event.motion.y)) // so if the mouse-click is on the button
			{
				offset.x = 70;
				offset.y = 70;
			}
		}

		SDL_FillRect(screen, NULL, screenColor);
		SDL_BlitSurface(encryptBMP, NULL, screen, &offset);
		SDL_Flip(screen);
	}
	SDL_FreeSurface(screen);
	SDL_FreeSurface(encryptBMP);
	SDL_Quit();
}