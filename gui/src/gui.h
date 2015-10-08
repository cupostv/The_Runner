#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <inttypes.h>
#include "../../map/src/map.h"


#define DEPTH 32

SDL_Window* window;
SDL_Surface* loading_surface;
SDL_Renderer* renderer;

SDL_Texture* background;
SDL_Texture* map_part[ROWS][COLUMNS];

int initGUI (void);

void initMap (void);

void clearScreen (void);
void renderBackground(void);
void renderMap(void);
void draw(void);

void destroyGUI(void);

#endif