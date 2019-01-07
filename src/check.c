#include "../include/fillit.h"

static int 	has_no_neighbors(char **tetri, int i, int j)
{
	int		n;

	n = 0;
	if (j < 3 && tetri[i][j + 1] == '#')
		return (0);
	if (j > 0 && tetri[i][j - 1] == '#')
		return (0);
	if (i > 0 && tetri[i - 1][j] == '#')
		return (0);
	if (i < 3 && tetri[i + 1][j] == '#')
		return (0);
	return (1);
}

static int	has_four_pieces(char **tetri)
{
	int		i;
	int		j;
	int		count;
	
	count = 0;
	i = 0;
	while (i < 4 && tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
			{
				count++;
				if (has_no_neighbors(tetri, i, j) == 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int		valid_tetrimino(char **tetri)
{
	int	i;
	int	j;

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
