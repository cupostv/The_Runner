#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <inttypes.h>
#include "../../map/src/map.h"
#include "../../player/src/player.h"


#define DEPTH 32

SDL_Window* window;
SDL_Surface* loading_surface;
SDL_Renderer* renderer;

SDL_Texture* background;
SDL_Texture* map_part[ROWS][COLUMNS];
SDL_Texture* player_texture;

int initGUI (void);

void initMap (void);

void initPlayerTexture (void);

void clearScreen (void);
void updatePlayer(PLAYER* player);
void renderBackground(void);
void renderMap(void);
void renderPlayer(PLAYER* player);
void draw(void);

void destroyGUI(void);

#endif