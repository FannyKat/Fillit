/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:26:55 by fcatusse          #+#    #+#             */
/*   Updated: 2019/01/22 13:26:56 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			overlap(t_point set[26][4], t_point ref[4], int curr, t_point vect)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < curr)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if ((ref[j].y + vect.y == set[i][k].y) &&
					(ref[j].x + vect.x == set[i][k].x))
					return (1);
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			overflow_x(t_point vect_it, t_point ref[4], int area)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if ((ref[j].x + vect_it.x >= area))
			return (1);
		j++;
	}
	return (0);
}

int			overflow_y(t_point vect_it, t_point ref[4], int area)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if ((ref[j].y + vect_it.y >= area))
			return (1);
		j++;
	}
	return (0);
}

int			find_pos_for(t_etri data, t_point vect_it, t_point ref[4],
															t_point set[26][4])
{
	while (overflow_y(vect_it, ref, data.area) == 0)
	{
		while (overflow_x(vect_it, ref, data.area) == 0)
		{
			if (overlap(set, ref, data.current, vect_it) == 0)
			{
				set_tetri(set[data.current], ref, vect_it);
				return (1);
			}
			vect_it.x += 1;
		}
		vect_it.y += 1;
		vect_it.x = 0;
	}
	return (0);
}

void		find_solution(t_point ref[26][4], int tetri_nbr, t_point vect_it
																, t_etri data)
{
	t_point		set[26][4];

	while (data.current <= tetri_nbr)
	{
		if (find_pos_for(data, vect_it, ref[data.current], set) == 1)
		{
			data.current++;
			vect_it = vect_zero(vect_it);
		}
		else
		{
			if (data.current == 0)
			{
				vect_it = clean(set[data.current], vect_it);
				data.area++;
			}
			else
			{
				data.current -= 1;
				vect_it = last_vect(vect_it, data, set, ref);
				delete_last(set[data.current]);
			}
		}
	}
	display(set, tetri_nbr, data.area);
}
