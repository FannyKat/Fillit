# ifndef FILLIT_H
#define FILLIT_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct		s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct		s_etri
{
	int		current;
	int		area;
}			t_etri;

int	main(int ac, char **av);
void	read_fd(int fd, char *tab_tetri[26][4], char buffer[6], int j);
int	valid_tetrimino(char **tetri);
void	resolve(char *tab_tetri[26][4], int tetri_nbr);
void	get_coord(char *tab_tetri[26][4], t_point tab[26][4], int tetri_nbr);
void	find_solution(t_point tab[26][4], int tetri_nbr, t_point vect_it, t_etri data);
int	map_size(int tetri_nbr);
void	set_tetri(t_point set[4], t_point ref[4], t_point vect_it);
void	delete_last(t_point tetri_set[4]);
void	display(t_point tetri_set[26][4], int tetri_nbr, int area);

t_point	vect_zero(t_point vect_it);
t_point	last_vect(t_point vect_it, t_etri data, t_point set[26][4], t_point ref[26][4]);

#endif
