/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:06:38 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/12 16:25:07 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*grow_up_map(t_map *map, t_tetri *tetri)
{
	t_map *save;

	save = map;
	while (map->next)
	{
		map->line = 0;
		map->width += 1;
		map = map->next;
	}
	map->line = 0;
	map->width += 1;
	map = ft_lpb_map(&map->head, map->width, map->index + 1);
	map = save;
	reset_tetri(tetri);
	return (save);
}

int		first_one(int tetri)
{
	int mask;
	int count;

	mask = 1;
	count = 0;
	while (!(mask & tetri))
	{
		mask <<= 1;
		count += 1;
	}
	return (count);
}

void	set_tetri_map(t_tetri **tetri, t_map **map)
{
	int				mask;
	unsigned int	i;
	int				tmp;
	t_tetri			*l_tetri;
	t_map			*l_map;

	l_tetri = *tetri;
	l_map = *map;
	i = 1;
	mask = 1;
	tmp = set_fblock_bit(l_tetri->tetri, 1, l_tetri->decal) |
	(((set_fblock_bit(l_tetri->tetri, 2, l_tetri->decal) >> 4) |
	((set_fblock_bit(l_tetri->tetri, 3, l_tetri->decal) >> 8) |
	(set_fblock_bit(l_tetri->tetri, 4, l_tetri->decal) >> 12))));
	l_tetri->pos_y = l_map->index;
	while (!(mask & tmp))
		mask <<= 1;
	l_tetri->pos_x = mask;
	while (i <= l_tetri->length)
	{
		l_map->line += set_fblock_bit(l_tetri->tetri, i, l_tetri->decal)
		>> 4 * (i - 1);
		i += 1;
		l_map = l_map->next;
	}
}
