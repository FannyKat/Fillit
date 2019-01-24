/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:58:43 by fcatusse          #+#    #+#             */
/*   Updated: 2019/01/24 19:50:20 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void			*error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int				check_error(int ac, char **av, int fd)
{
	if (ac != 2)
		error("usage: ./fillit source_file");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error("error");
	return (fd);
}

int				check_newline(int fd, char buffer[6])
{
	int			ret;

	ret = read(fd, buffer, 1);
	if (ret == 0)
		return (0);
	else if (ret > 0)
		if (buffer[0] != '\n')
			error("error");
	return (1);
}

void			reader(int fd, char *tab_tetri[26][4], char buff[6], int j)
{
	int			i;
	int			ret;

	i = 0;
	while (i < 26 && ((ret = read(fd, buff, 5)) > 0))
	{
		buff[5] = 0;
		tab_tetri[i][j] = ft_strdup(buff);
		ret != 5 ? error("error") : 0;
		if (j == 3)
		{
			if (valid_tetrimino(tab_tetri[i]) == 1)
			{
				if (check_newline(fd, buff) == 0)
					break ;
				j = 0;
				i++;
				continue ;
			}
			else
				error("error");
		}
		j++;
	}
	(j != 3 || !tab_tetri[i][j]) ? error("error") : resolve(tab_tetri, i);
}

int				main(int ac, char **av)
{
	int			j;
	int			fd;
	char		*tab_tetri[26][4];
	char		buffer[6];

	j = 0;
	fd = 0;
	fd = check_error(ac, av, fd);
	reader(fd, tab_tetri, buffer, j);
	close(fd);
	return (0);
}
