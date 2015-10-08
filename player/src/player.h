#ifndef PLAYER_H
#define PLAYER_H

#include <inttypes.h>

#define FACING_LEFT -1
#define FACING_RIGHT 1

	typedef struct player
	{
		uint32_t x_position;
		uint32_t y_position;
		uint8_t speed;
		uint8_t jump_speed;
		uint8_t orientation;
		uint32_t score;
		uint8_t health;
	} PLAYER;

	PLAYER* createPlayer ();
	
	void setPosition (PLAYER* player, uint32_t x, uint32_t y);

	void setSpeed (PLAYER* player, uint8_t speed);

	void moveLeft (PLAYER* player);

	void moveRight (PLAYER* player);

	void jump (PLAYER* player);

	void deletePlayer (PLAYER* player);

#endif