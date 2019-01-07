#include "../include/fillit.h"

void	putdot_to_map(char map[42][42], int x, int y)
{
	map[x][y] = '.';
}

void	print_char(char map[42][42], int x, int y)
{
	write(1, &map[x][y], 1);
}

void	for_map(char map[42][42], int size, void (*f)(char map[42][42], int x, int y))
{
	int	x;
	int	y;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			f(map, x, y);
		}
		if (f == &print_char)
			ft_putchar('\n');
	}
}

void	puton_topleft(char *tab_tetri[26][4], char map[42][42], int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab_tetri[0][j])
	{
		map[x][y] = *tab_tetri[0][j];
		j++;
		y++;
	}
}

void	resolve(char *tab_tetri[26][4])
{
	char	map[42][42];
	int		size;

	size = 4;
	(void)tab_tetri;
	for_map(map, size, &putdot_to_map);
//	for_map(map, size, &print_char);
//	puton_topleft(&tab_tetri[0], map, 0, 0);
	for_map(map, size, &print_char);	
}
