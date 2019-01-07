#include "../include/fillit.h"

void	error(int ac)
{
	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit (EXIT_FAILURE);
	}
	write(1, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int			fd;
	int			i;
	int			j;
	int			ret;
	char		*tab_tetri[26][4];
	char 		buffer[6];

	i = 1;
	j = 0;
	error(ac);	
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error(ac);	
	while (j < 26 && read(fd, buffer, 5) > 0)
	{
		buffer[5] = 0;
		tab_tetri[j][i - 1] = ft_strdup(buffer);
		if (i == 4)
		{
			if (valid_tetrimino(tab_tetri[j]) == 1)
			{
				write(1, "Thats a valid shape\n", 20);
				ret = read(fd, buffer, 1);
				if (ret == 0)
					break ;
				else if (ret > 0)
				{
					if (buffer[0] != '\n')
						error(ac);
				}
				i = 1;
				j++;
				continue ;
			}
			else
				error(ac);	
		}
		i++;
	}
	resolve(tab_tetri);
	if (i != 4)
		error(ac);
	close(fd);
	return (0);
}