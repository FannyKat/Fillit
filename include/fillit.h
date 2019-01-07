# ifndef FILLIT_H
#define FILLIT_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "../libft/libft.h"

int		main(int ac, char **av);
int		valid_tetrimino(char **tetri);
void	resolve(char *tab_tetri[26][4]);

#endif
