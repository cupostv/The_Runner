#include "../../unity/unity_fixture.h"
#include "../src/gui.h"

TEST_GROUP(GuiTest);

TEST_GROUP_RUNNER(GuiTest)
{
	RUN_TEST_CASE (GuiTest, TestInitGui);
	RUN_TEST_CASE (GuiTest, TestInitMap);
}

TEST_SETUP(GuiTest)
{	 

}

TEST_TEAR_DOWN(GuiTest)
{
	destroyGUI();
}

TEST(GuiTest, TestInitGui)
{
	TEST_ASSERT_TRUE(initGUI() == 1);
}

TEST(GuiTest, TestInitMap)
{
	initGUI();
	initMap();
	int success = 1;
	int i;
	int j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			if (map_part[i][j] == NULL)
			{
				success = 0;
			}
		}
	}
	TEST_ASSERT_TRUE (success == 1);
}