/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:57:09 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/14 17:02:16 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	ft_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	return (0);
}

int		check_piece(char *tab)
{
	int piece;
	int tetri;

	piece = 0;
	tetri = 0;
	while (piece < 20)
	{
		if (tab[piece] == '#')
		{
			tetri += 1;
			if (tetri > 4)
				return (0);
			if (tetri < 4 && piece > 0 && tab[piece - 1] != '#')
				if (tetri < 4 && piece > 4 && tab[piece - 5] != '#')
					if (tetri < 4 && piece < 14 && tab[piece + 5] != '#')
						if (tetri < 4 && piece < 18 && tab[piece + 1] != '#')
							return (0);
		}
		if ((piece + 1) % 5 == 0 && tab[piece] != '\n')
			return (0);
		piece += 1;
	}
	return (1);
}

int		ft_fill_tab(char tab[26][22], char *file, int ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ret)
	{
		ft_strncpy(tab[j], &file[i], 20);
		tab[j][20] = 'A' + j;
		tab[j][21] = 0;
		if (!check_piece(tab[j]))
		{
			printf("piece numero %d\n", j + 1);
			return (0);
		}
		i += 21;
		j += 1;
	}
	return (1);
}

int		ft_error(char *av)
{
	char file[546];
	char tab[26][22];
	int fd;
	int ret;

	if ((fd = open(av, O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (0);
	}
	ret = read(fd, file, 575);
	file[ret] = 0;
	if (ret == 545)
		if (read(fd, file, 1))
			return (0);
	if ((ret % 21) != 20)
		return (0);
	if(!(ft_fill_tab(tab, file, ret)))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_usage());
	if (!ft_error(av[1]))
	{
		ft_putendl("FICHIER INVALIDE");
		return (0);
	}
	ft_putendl("FICHIER VALIDE");
	return (0);
}
