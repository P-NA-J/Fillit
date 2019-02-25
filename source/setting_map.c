/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:06:38 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/25 22:52:55 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"


int		first_one(int tetri)
{
	int mask;

	mask = 1;
	print_bit_int(tetri);
	while (!(mask & tetri))
	{
		mask <<= 1;
	}
	return (mask);
}

void	set_tetri_map(t_tetri **tetri, t_map **map)
{
	int mask;
	int i;
	int tmp;
	t_tetri *l_tetri;
	t_map *l_map;

	l_tetri = *tetri;
	l_map = *map;
	i = 1;
	mask = 1;
	tmp = set_fblock_bit(l_tetri->tetri, 1, l_tetri->decal) | (((set_fblock_bit(l_tetri->tetri, 2, l_tetri->decal) >> 4) | ((set_fblock_bit(l_tetri->tetri, 3, l_tetri->decal) >> 8) | (set_fblock_bit(l_tetri->tetri, 4, l_tetri->decal) >> 12))));
	l_tetri->pos_y = l_map->index;
	while (!(mask & tmp))
		mask <<= 1;
	l_tetri->pos_x = mask;
	while (i <= l_tetri->length)
	{
		l_map->line += set_fblock_bit(l_tetri->tetri, i, l_tetri->decal) >> 4 * (i - 1);
		i += 1;
		l_map = l_map->next;
	}	
}