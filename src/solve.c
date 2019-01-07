#include "../include/fillit.h"

int		solve(char *tab_tetri[26][4], char map[42][42], int size)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y++ <= size)
	{
		x = 0;
		while (x++ <= size)
		{
			if (solve(tab_tetri, map, size))
			{
				fill(map, x, y);
				return (1);
			}
			ft_clean(tab_tetri, map, size);
		}
	}
	return (0);
}
