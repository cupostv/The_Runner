#include "main.h"

static void initPlayer (void);
static void processInput (void);

int main (int argc, char* argv[])
{


	if (!loadMapFromFile ("maps/level1.map"))
	{
		printf ("Can't locate map!");
	}

	initGUI();
	initMap();
	initPlayer();

	SDL_Event e;
	int quit = 0;

	int start_time;
	int urd_time;
	int wait_time;
	int target_time = 1000/FPS;

	while (!quit)
	{
		start_time = SDL_GetTicks();

		while (SDL_PollEvent (&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			else if( e.type == SDL_KEYDOWN)
			{
				processInput ();
			}
			else
			{
				player->left = 0;
				player->right = 0;
			}
		}

		clearScreen();
		updatePlayer (player);
		renderBackground();
		renderMap();
		renderPlayer (player);
		draw();

		urd_time = (SDL_GetTicks() - start_time);
		wait_time = target_time - urd_time;

		SDL_Delay (wait_time);
	}

	destroyGUI();
	deletePlayer (player);

	return 0;
}

static void initPlayer (void)
{
	player = createPlayer();
	setPosition (player, 50, 50);
	setSpeed (player, 2);
	player->jump_speed = 4;
	initPlayerTexture();
}

static void processInput(void)
{
    uint8_t* keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_LEFT])
    {
    	player->left = 1;
    }
    if (keystate[SDL_SCANCODE_RIGHT])
    {
    	player->right = 1;
    }
    if (keystate[SDL_SCANCODE_UP] && !player->falling)
    {
    	player->jumping = 1;
    }
}
