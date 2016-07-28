#include "../../unity/unity_fixture.h"
#include "../src/map.h"

TEST_GROUP(MapTest);

TEST_GROUP_RUNNER(MapTest)
{
	RUN_TEST_CASE (MapTest, TestLoadMap);
	RUN_TEST_CASE (MapTest, TestGetRow);
	RUN_TEST_CASE (MapTest, TestGetColumn);
}

TEST_SETUP(MapTest)
{	 

}

TEST_TEAR_DOWN(MapTest)
{

}

TEST(MapTest, TestLoadMap)
{
	uint8_t allValid = loadMapFromFile ("maps/level1.map");
	uint8_t i;
	uint8_t j;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			if ((map[i][j] != BLOCKED) && (map[i][j] != AIR))
			{
				allValid = 0;
			}
		}
	}
	TEST_ASSERT_TRUE (allValid == 1);
}

TEST(MapTest, TestGetRow)
{
	uint8_t y_position = 70;
	TEST_ASSERT_TRUE (getCurrentRow(y_position) == 2);
}

TEST(MapTest, TestGetColumn)
{
	uint8_t x_position = 70;
	TEST_ASSERT_TRUE (getCurrentColumn(x_position) == 2);
}