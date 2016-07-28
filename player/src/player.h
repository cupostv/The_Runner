#ifndef PLAYER_H
#define PLAYER_H

#include <inttypes.h>
#include "../../map/src/map.h"

#define FACING_LEFT -1
#define FACING_RIGHT 1
#define PLAYER_WIDTH 30
#define PLAYER_HEIGHT 30
#define MAX_JUMP_HEIGHT 65

	typedef struct player
	{
		uint32_t x_position;
		uint32_t y_position;
		uint8_t speed;
		int8_t jump_speed;
		uint8_t orientation;
		uint32_t score;
		uint8_t health;
		uint8_t left;
		uint8_t right;
		uint8_t jumping;
		uint8_t falling;
		uint8_t current_jump_height;
		uint8_t decrease_jump;
	} PLAYER;

	PLAYER* createPlayer ();

	void setPosition (PLAYER* player, uint32_t x, uint32_t y);

	void setSpeed (PLAYER* player, uint8_t speed);

	void moveLeft (PLAYER* player);

	void moveRight (PLAYER* player);

	void updatePlayer(PLAYER* player);

	void deletePlayer (PLAYER* player);

#endif
