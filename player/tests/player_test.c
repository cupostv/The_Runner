#include "../../unity/unity_fixture.h"
#include "../src/player.h"

PLAYER* player;

TEST_GROUP(PlayerTest);

TEST_GROUP_RUNNER(PlayerTest)
{
	RUN_TEST_CASE (PlayerTest, TestAllocatePlayer);
	RUN_TEST_CASE (PlayerTest, TestPlayerPosition);
	RUN_TEST_CASE (PlayerTest, TestSpeed);
	RUN_TEST_CASE (PlayerTest, TestMoveLeft);
	RUN_TEST_CASE (PlayerTest, TestMoveRight);
}

TEST_SETUP(PlayerTest)
{	 
	deletePlayer (player);
	player = createPlayer();
}

TEST_TEAR_DOWN(PlayerTest)
{

}

TEST(PlayerTest, TestAllocatePlayer)
{
	TEST_ASSERT_TRUE (player != NULL);
}

TEST(PlayerTest, TestPlayerPosition)
{
	setPosition(player, 10, 10);
	TEST_ASSERT_TRUE (player->x_position == 10 && player->y_position == 10);
}

TEST(PlayerTest, TestSpeed)
{
	setSpeed(player, 2);
	TEST_ASSERT_TRUE(player->speed == 2);
}

TEST(PlayerTest, TestMoveLeft)
{
	setPosition(player, 10, 10);
	setSpeed(player, 2);
	moveLeft (player);
	uint32_t current_position = player->x_position;
	uint32_t expected_position = 10 - player->speed;
	TEST_ASSERT_TRUE (expected_position == current_position);
}

TEST(PlayerTest, TestMoveRight)
{
	setPosition(player, 10, 10);
	setSpeed(player, 2);
	moveRight (player);
	uint32_t current_position = player->x_position;
	uint32_t expected_position = 10 + player->speed;
	TEST_ASSERT_TRUE (expected_position == current_position);
}