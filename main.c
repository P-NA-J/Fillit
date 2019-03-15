/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/13 17:59:53 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

void	free_tetri_list(t_tetri *tetri)
{
	t_tetri *tmp;

	while (tetri)
	{
		tetri->tetri = 0;
		tetri->letter = 0;
		tetri->pos_x = 0;
		tetri->pos_y = 0;
		tetri->length = 0;
		tetri->width = 0;
		tetri->decal = 0;
		tetri->prev = NULL;
		tmp = tetri->next;
		tetri->next = NULL;
		free(tetri);
		tetri = tmp;
	}
}

void	ft_free_map(t_map *map)
{
	t_map *tmp;

	while (map)
	{
		map->line = 0;
		map->index = 0;
		map->width = 0;
		tmp = map->next;
		map->head = NULL;
		map->prev = NULL;
		tmp = map->next;
		map->next = NULL;
		free(map);
		map = tmp;
	}
}

void	ft_free(t_tetri *tetri, t_map *map, char *path)
{
	free_tetri_list(tetri);
	free_map_list(map);
	ft_bzero(path, ft_strlen(path));
	free(path);
}

int	main(int ac, char **av)
{
	unsigned int	n_tetri;
	char			*path;
	char			**print;
	t_tetri			*tetri;
	t_map			*map;

	if (ac != 2)
		return (ft_usage());
	if (!(n_tetri = ft_read(&path, av)))
		return (ft_error());
	if (n_tetri > 26)
		return (ft_error());
	if (!(tetri = parser_file(path, n_tetri)))
		return (ft_error());
	map = map_gen(n_tetri);
	while (solver(tetri, map) == 0)
		map = grow_up_map(map, tetri);
	print = print_tab_gen(tetri, map->width);
	print_map_final(print, map->width);
	ft_free(tetri, map, path);
	return (0);
}
