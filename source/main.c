/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/20 17:03:19 by pauljull         ###   ########.fr       */
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

	count = 0;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	n_tetri = ft_read(fd, &path);
	tetri = parser_file(path, n_tetri);
	if (check_file(tetri, n_tetri))
		printf("VALID");
	else
		printf("INVALID");
	
	return (0);
}
