/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:19:03 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/12 16:21:04 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_map(t_tetri *tetri, t_map **map_ref)
{
	unsigned int	i;
	t_map			*save;
	t_map			*map;

	map = *map_ref;
	map = map->head;
	i = 1;
	while (map->index != tetri->pos_y)
		map = map->next;
	save = map;
	while (i <= tetri->length)
	{
		map->line ^= (set_fblock_bit(tetri->tetri, i, tetri->decal) >>
		(i - 1) * 4);
		map = map->next;
		i += 1;
	}
	*map_ref = save;
}

t_map	*map_gen(int n_tetri)
{
	t_map	*map;
	t_map	*save;
	int		i;

	map = NULL;
	i = 0;
	while (i < ft_square(n_tetri * 4))
	{
		map = ft_lpb_map(&map, ft_square(n_tetri * 4), i);
		if (i == 0)
			save = map;
		i += 1;
	}
	return (save);
}
