#include "gui.h"

int initGUI ()
{
	window = SDL_CreateWindow( "The Runner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( window == NULL )
	{ 
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return 0;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{ 
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return 0;
	}
	loading_surface = SDL_GetWindowSurface( window );

	SDL_FillRect (loading_surface, NULL, SDL_MapRGB(loading_surface->format, 0xFF, 0xFF, 0xFF));
	background = SDL_CreateTextureFromSurface (renderer, loading_surface);

	return 1;
}

void initMap ()
{
	SDL_Surface* loader = NULL;
	int i;
	int j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			if (map [i][j] == 1)
			{
				loader = SDL_CreateRGBSurface (0, CELL_WIDTH, CELL_HEIGHT, DEPTH, 0x00, 0x00, 0x00, 0xFF);
			}
			else 
			{
				loader = SDL_CreateRGBSurface (0, CELL_WIDTH, CELL_HEIGHT, DEPTH, 0xFF, 0xFF, 0xFF, 0xFF);
			}

			map_part[i][j] = SDL_CreateTextureFromSurface (renderer, loader);

			SDL_FreeSurface (loader);
		}
	}
}

void initPlayerTexture (void)
{
	SDL_Surface* loader = NULL;
	loader = SDL_CreateRGBSurface (0, PLAYER_WIDTH, PLAYER_HEIGHT, DEPTH, 0x00, 0x00, 0x00, 0xFF);
	player_texture = SDL_CreateTextureFromSurface (renderer, loader);
}


void clearScreen ()
{
	SDL_RenderClear(renderer);
}

void renderBackground()
{
	SDL_RenderCopy(renderer, background, NULL, NULL);
}

void renderMap()
{
	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	dst.w = CELL_WIDTH;
	dst.h = CELL_HEIGHT;
	int i;
	int j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			dst.x = j * CELL_WIDTH;
			dst.y = i * CELL_HEIGHT;
			SDL_RenderCopy(renderer, map_part[i][j], NULL, &dst);
		}
	}
}

void renderPlayer(PLAYER* player)
{
	SDL_Rect dst;
	dst.x = player->x_position;
	dst.y = player->y_position;
	dst.w = PLAYER_WIDTH;
	dst.h = PLAYER_HEIGHT;
	SDL_RenderCopy (renderer, player_texture, NULL, &dst);
}

void draw()
{
	SDL_RenderPresent(renderer);
}

void destroyGUI(void)
{
	SDL_FreeSurface (loading_surface);
	SDL_DestroyTexture(background);
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			SDL_DestroyTexture (map_part[i][j]);
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow (window);
	SDL_Quit();
}
