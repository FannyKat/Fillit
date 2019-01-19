#include "../include/fillit.h"

void		set_tetri(t_point set[4], t_point ref[4], t_point vect_it)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		set[j].x = ref[j].x + vect_it.x;
		set[j].y = ref[j].y + vect_it.y;
		j++;
	}
}

void		delete_last(t_point tetri_set[4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		tetri_set[j].x = 0;
		tetri_set[j].y = 0;
		j++;
	}	
}

t_point		vect_zero(t_point vect_it)
{
	vect_it.x = 0;
	vect_it.y = 0;
	return (vect_it);
}

t_point		last_vect(t_point vect_it, t_etri data, t_point set[26][4], t_point ref[26][4])
{
	vect_it.x = (set[data.current][0].x - ref[data.current][0].x) + 1;
	vect_it.y = set[data.current][0].y;
	delete_last(set[data.current]);
	return (vect_it);
}
