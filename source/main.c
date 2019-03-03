/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/03 20:33:58 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/fillit.h"
#define KNRM  "\x1B[0m"


int	main(int ac, char **av)
{
	char *path;
	int	fd;
	t_tetri	*tetri;
	int n_tetri;
	int count;
	t_map *map;
	t_tetri *save;
	int mask;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (!(n_tetri = ft_read(fd, &path)))
		return (0);
	tetri = parser_file(path, n_tetri);
	map = map_gen(n_tetri);
	solver_recursif(tetri, map);
//	ft_print_map_final(tetri, map);
	return (0);
}
