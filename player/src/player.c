#include "player.h"
#include <stdio.h>

PLAYER* createPlayer ()
{
	PLAYER* player = (PLAYER*) malloc (sizeof (PLAYER));
	player->x_position = 0;
	player->y_position = 0;
	player->speed = 0;

	player->left = 0;
	player->right = 0;
	player->jumping = 0;
	player->falling = 0;
	player->current_jump_height = 0;


	player->decrease_jump = 0;
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

void updatePlayer(PLAYER* player)
{
	int8_t dx = 0;
	int8_t dy = 0;

	uint8_t row_top = 0;
	uint8_t row_bottom = 0;
	uint8_t column_left = 0;
	uint8_t column_right = 0;

	uint16_t right = player->x_position + PLAYER_WIDTH - 1;
	uint16_t left = player->x_position;
	uint16_t top = player->y_position;
	uint16_t bottom = player->y_position + PLAYER_HEIGHT - 1;

	row_bottom = getCurrentRow (bottom);
	column_left = getCurrentColumn (left);
	column_right = getCurrentColumn (right);

	if (player->left)
	{
		dx -= player->speed;
		column_left = getCurrentColumn (left + dx);
		row_bottom = getCurrentRow (bottom);
		row_top = getCurrentRow (top + dy);

		if (map[row_top][column_left] == BLOCKED || map[row_bottom][column_left] == BLOCKED)
		{
			dx = -(dx + ((left - dx) % CELL_WIDTH));
		}
	}

	if (player->right)
	{
		dx += player->speed;
		column_right = getCurrentColumn (right + dx);
		row_bottom = getCurrentRow (bottom);
		row_top = getCurrentRow (top + dy);

		if (map[row_top][column_right] == BLOCKED || map[row_bottom][column_right] == BLOCKED)
		{
			dx = dx - ((left + dx) % CELL_WIDTH);
		}
	}

	row_bottom = getCurrentRow (bottom);
	column_left = getCurrentColumn (left + dx);
	column_right = getCurrentColumn (right + dx);

	if (player->jumping)
	{
		dy -= player->jump_speed;
		player->current_jump_height += player->jump_speed;
		if (player->current_jump_height > MAX_JUMP_HEIGHT)
		{
			player->jumping = 0;
			player->falling = 1;
			player->current_jump_height = 0;
		}
		row_top = getCurrentRow (top + dy);
		column_left = getCurrentColumn (left + dx);
		column_right = getCurrentColumn (right + dx);

		if (map[row_top][column_left] == BLOCKED || map[row_top][column_right] == BLOCKED)
		{
			dy = -(dy + ((player->y_position - dy) % CELL_HEIGHT));
			player->jumping = 0;
			player->falling = 1;
			player->current_jump_height = 0;
		}
	}
	else if (map[row_bottom][column_left] == AIR && map[row_bottom][column_right] == AIR)
	{
		player->falling = 1;
		dy += GRAVITY;

		row_bottom = getCurrentRow (bottom + dy);
		column_left = getCurrentColumn (left + dx);
		column_right = getCurrentColumn (right + dx);

		if (map[row_bottom][column_left] == BLOCKED || map[row_bottom][column_right] == BLOCKED)
		{
			dy = dy - ((player->y_position + dy) % CELL_HEIGHT);
			player->falling = 0;
		}
		
	}

	player->x_position += dx;
	player->y_position += dy;
}

void deletePlayer (PLAYER* player)
{
	free (player);
}

