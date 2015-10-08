#include "main.h"

int main (int argc, char* argv[])
{
	

	if (!loadMapFromFile ("maps/level1.map"))
	{
		printf ("Can't locate map!");
	}

	initGUI();
	initMap();

	SDL_Event e;
	int quit = 0;

	while (!quit)
	{
		while (SDL_PollEvent (&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
		}
			
		clearScreen();
		renderBackground();
		renderMap();
		draw();
	}

	destroyGUI();

	return 0;
}