#include "map.h"

int loadMapFromFile (char* path)
{
	FILE* level = fopen (path, "r");
	if (level == NULL)
	{
		return 0;
	}
	int c;
	int i = 0;
	int j = 0;
	while ((c = fgetc(level)) != EOF)
	{
		if (c == '\n')
		{
			i++;
			j = 0;
			c = fgetc(level);
		}
		if (c == ' ')
		{
			c = fgetc(level);
		}
		map[i][j++] = c - '0';
	}
	return 1;
}