/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:16:53 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/11 21:47:18 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_shift(t_tetri *tetri)
{
	tetri->tetri <<= 1;
	tetri->pos_x <<= 1;
	tetri->decal += 1;
}

void	ft_next_line(t_tetri *tetri)
{
	tetri->tetri >>= tetri->decal;
	tetri->pos_x = 1;
	tetri->pos_y += 1;
	tetri->decal = 0;
}

int		posable_piece(t_tetri *tetri, t_map *map)
{
	if (put_check(tetri, map))
		return (ft_print_set(tetri, map));
	return (0);
}

t_tetri	*backtracking(t_tetri *tetri, t_map **map)
{
	reset_tetri(tetri);
	tetri = tetri->prev;
	reset_map(tetri, map);
	tetri->tetri <<= 1;
	tetri->pos_x <<= 1;
	tetri->decal += 1;
	return (tetri);
}

int		solver(t_tetri *tetri, t_map *map)
{
	while (tetri)
	{
		while (posable_piece(tetri, map))
		{
			tetri = tetri->next;
			if (!tetri)
				return (1);
			map = map->head;
		}
		if ((tetri->pos_x << (1 + tetri->width) <= (1 << map->width)) &&
		(tetri->length <= (map->width - map->index)))
			ft_shift(tetri);
		else if (map->next && tetri->length <= (map->width - map->next->index))
		{
			ft_next_line(tetri);
			map = map->next;
		}
		else if (!tetri->prev)
			return (0);
		else
			tetri = backtracking(tetri, &map);
	}
	return (1);
}
