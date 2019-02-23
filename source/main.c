/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/23 18:10:44 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/fillit.h"



int	main(int ac, char **av)
{
	char *path;
	int	fd;
	t_tetri	*tetri;
	int n_tetri;
	int count;
	t_map *map;

	count = 0;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (!(n_tetri = ft_read(fd, &path)))
		return (0);
	tetri = parser_file(path, n_tetri);
	map = map_gen(n_tetri);
	solver(&tetri, &map);
//	print_map_bit(map);
//	printf("\n");
//	print_map_final(tetri, map);
	return (0);
}
