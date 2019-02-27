/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:16:53 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/26 22:27:54 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_map	*reset_map(t_tetri *tetri, t_map *map)
{
	char i;
	t_map *save;

	save = map;
	i = 1;
	while (map->index != tetri->pos_y)
		map = map->next;
	while (i <= tetri->length)
	{
		
		map->line ^= (set_fblock_bit(tetri->tetri, i, tetri->decal) >> (i - 1) * 4);	
		map = map->next;
		i += 1;
	}
	return (save);
}

void	solver_iteratif(t_tetri **tetri_ref, t_map **map_ref)
{
	t_tetri	*l_tetri;
	t_map	*l_map;
	t_tetri *save;
	int		decal;

	l_tetri = *tetri_ref;
	l_map = *map_ref;
	decal = 0;
	while (l_tetri)
	{
		while (l_map->next && l_tetri)
		{
			if (multi_check(l_tetri, l_map))
			{
				set_tetri_map(&l_tetri, &l_map);
				l_tetri = l_tetri->next;
				l_map = *map_ref;
				decal = 0;
			}
			else if (l_tetri->pos_x << (1 + l_tetri->width) <= power(2, l_map->width))
			{	
				l_tetri->tetri <<= 1;
				l_tetri->pos_x <<= 1;
				decal += 1;
			}
			else if (l_map->next && l_tetri->length <= (l_map->width - l_map->next->index))
			{
				l_map = l_map->next;
				l_tetri->tetri >>= decal;
				l_tetri->pos_y += 1;
				l_tetri->pos_x = 1;
				decal = 0;
			}
		}
		if (l_tetri)
			l_tetri = l_tetri->next;
	}
}

void solver_recursif(t_tetri *tetri, t_map *map)
{
	if (multi_check(tetri, map))
	{
		set_tetri_map(&tetri, &map);
		if (tetri->next)
			solver_recursif(tetri->next, map->head);
	}
	else if (tetri->pos_x << (1 + tetri->width) <= power(2, map->width))
	{	
		tetri->tetri <<= 1;
		tetri->pos_x <<= 1;
		tetri->decal += 1;
		solver_recursif(tetri, map);
	}
	else if (map->next && tetri->length <= (map->width - map->next->index))
	{
		map = map->next;
		tetri->tetri >>= tetri->decal;
		tetri->pos_y += 1;
		tetri->pos_x = 1;
		tetri->decal = 0;
		solver_recursif(tetri, map);
	}
	else
	{
		map = reset_map(tetri->prev, map->head);
		tetri->prev->tetri <<= 1;
		tetri->prev->decal += 1;
		solver_recursif(tetri->prev, map);
	}
}