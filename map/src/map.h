#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <inttypes.h>

#define BLOCKED 1
#define AIR 0
#define CELL_WIDTH 30
#define CELL_HEIGHT 30
#define SCREEN_WIDTH 630
#define SCREEN_HEIGHT 630
#define ROWS ((SCREEN_WIDTH)/(CELL_WIDTH))
#define COLUMNS ((SCREEN_HEIGHT)/(CELL_HEIGHT))

uint8_t map[ROWS][COLUMNS];

int loadMapFromFile (char* path);

int getCurrentRow (int y_pixel);
int getCurrentColumn (int x_pixel);


#endif