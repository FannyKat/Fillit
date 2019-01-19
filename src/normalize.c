#include "../include/fillit.h"

void			normalize(t_point tetri[4], t_point min)
{
	int		j;

	j = -1;
	while (++j < 4)
	{
		tetri[j].x -= min.x;
		tetri[j].y -= min.y;	
	}
}

void			norm_coord(t_point tab[26][4], int tetri_nbr)
{
	int		i;
	int		j;
	t_point		min;

	i = 0;
	while (i <= tetri_nbr)
	{
		min.x = 4;
		min.y = 4;
		j = -1;
		while (++j < 4)
		{
			if (min.x > tab[i][j].x)
				min.x = tab[i][j].x;
			if (min.y > tab[i][j].y)
				min.y = tab[i][j].y;
		}
		normalize(tab[i], min);
		i++;
	}
}

void			get_coord(char *tab_tetri[26][4], t_point tab[26][4], int tetri_nbr)
{
	int		i;
	int		j;
	int		k;
	int		c;

	i = -1;
	while (++i <= tetri_nbr)
	{
		j = -1;
		c = 0;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				if (tab_tetri[i][j][k] == '#')
				{
					tab[i][c].x = k;	
					tab[i][c].y = j;
					c++;
				}
			}
		}
	}
	norm_coord(tab, tetri_nbr);
}
