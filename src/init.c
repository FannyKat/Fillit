#include "../include/fillit.h"

void			*error(char *str)
{
	ft_putendl(str);
	exit (EXIT_FAILURE);
}

int			check_error(int ac, char **av, int fd)
{
	if (ac != 2)
		error("usage: ./fillit source_file");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error("error");
	return (fd);
}

int			check_newline(int fd, char buffer[6])
{
	int		ret;

	ret = read(fd, buffer, 1);
	if (ret == 0)
		return (0);
	else if (ret > 0)
		if (buffer[0] != '\n')
			error("error");
	return (1);
}

void			read_fd(int fd, char *tab_tetri[26][4], char buffer[6], int j)
{
	int		i;
	
	i = 0;
	while (i < 26 && read(fd, buffer, 5) > 0)
	{
		buffer[5] = 0;
		tab_tetri[i][j - 1] = ft_strdup(buffer);
		if (j == 4)
		{
			if (valid_tetrimino(tab_tetri[i]) == 1)
			{
				if (check_newline(fd, buffer) == 0)
					break ;	
				j = 1;
				i++;
				continue ;
			}
			else
				error("error");
		}
		j++;
	}
	if (j != 4)
		error("error");
	resolve(tab_tetri, i);
}

int			main(int ac, char **av)
{
	int		j;
	int		fd;
	char		*tab_tetri[26][4];
	char 		buffer[6];

	j = 1;
	fd = 0;
	fd = check_error(ac, av, fd);
	read_fd(fd, tab_tetri, buffer, j);
	close(fd);
	return (0);
}
