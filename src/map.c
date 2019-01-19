#include "../include/fillit.h"

int			map_size(int tetri_nbr)
{
	t_etri 	data;

	data.area = 2;
	while ((data.area * data.area) < tetri_nbr)
		data.area++;
	return (data.area);
}

void			display_box(t_point tetri_set[26][4], int tetri_nbr, int x, int y)
{
	int		i;
	int		j;
	char		c;

	i = 0;
	c = 'A';
	while (i <= tetri_nbr)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri_set[i][j].x == x && tetri_set[i][j].y == y)
			{
				c = i + 'A';
				ft_putchar(c);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_putchar('.');
}

void			display(t_point tetri_set[26][4], int tetri_nbr, int area)
{
	int		x;
	int		y;

	y = 0;
	while (y < area)
	{
		x = 0;
		while (x < area)
		{
			display_box(tetri_set, tetri_nbr, x, y);	
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

void			resolve(char *tab_tetri[26][4], int tetri_nbr)
{
	t_point		tab[26][4];
	t_point		vect_it;	
	t_etri		data;

	vect_it.x = 0;
	vect_it.y = 0;
	data.current = 0;
	data.area = map_size((tetri_nbr + 1) * 4);
	get_coord(tab_tetri, tab, tetri_nbr);
	find_solution(tab, tetri_nbr, vect_it, data);
}
