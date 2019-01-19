#include "../include/fillit.h"

static int 		count_neighbors(char **tetri, int i, int j, int n)
{
	if (j < 3 && tetri[i][j + 1] == '#')
		n++;
	if (j > 0 && tetri[i][j - 1] == '#')
		n++;
	if (i > 0 && tetri[i - 1][j] == '#')
		n++;	
	if (i < 3 && tetri[i + 1][j] == '#')
		n++;
	return (n);
}

static int		has_four_pieces(char **tetri)
{
	int		i;
	int		j;
	int		n;
	int		count;
	
	count = 0;
	n = 0;
	i = 0;
	while (i < 4 && tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
			{
				count++;
				n = count_neighbors(tetri, i, j, n);
			}
			j++;
		}
		i++;
	}
	if (count == 4 && (n == 6 || n == 8))
		return (1);
	return (0);
}

int			valid_tetrimino(char **tetri)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4 && tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] != '.' && tetri[i][j] != '#' && tetri[i][j] != '\n')
				return (0);
			if (tetri[i][4] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (has_four_pieces(tetri) == 1)
		return (1);
	return (0);
}
