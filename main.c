/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/11 22:33:36 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

int	main(int ac, char **av)
{
	int		n_tetri;
	char	*path;
	char	**print;
	t_tetri	*tetri;
	t_map	*map;

	if (ac != 2)
		return (ft_usage());
	if (!(n_tetri = ft_read(&path, av)))
		return (ft_error());
	if (n_tetri > 26)
		return (ft_error());
	if(!(tetri = parser_file(path, n_tetri)))
		return (ft_error());
	map = map_gen(n_tetri);
	while (solver(tetri, map) == 0)
		map = grow_up_map(map, tetri);
	print = print_tab_gen(tetri, map->width);
	print_map_final(print, map->width);
	return (0);
}
