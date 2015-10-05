#include "player.h"
#include <stdio.h>

PLAYER* createPlayer ()
{
	PLAYER* player = (PLAYER*) malloc (sizeof (PLAYER));
	player->x_position = 0;
	player->y_position = 0;
	player->speed = 0;
	return player;
}

void setPosition (PLAYER* player, uint32_t x, uint32_t y)
{
	player->x_position = x;
	player->y_position = y;
}

void setSpeed (PLAYER* player, uint8_t speed)
{
	player->speed = speed;
}
	
void moveLeft (PLAYER* player)
{
	player->x_position -= player->speed;
	player->orientation = FACING_LEFT;
}

void moveRight (PLAYER* player)
{
	player->x_position += player->speed;
	player->orientation = FACING_RIGHT;
}

void jump (PLAYER* player)
{

}

void deletePlayer (PLAYER* player)
{
	free (player);
}