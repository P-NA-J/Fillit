/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:16:53 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/03 20:42:56 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

t_tetri	*clean_list_tetri(t_tetri *tetri)
{
	t_tetri *save;

	while (tetri->prev)
		tetri = tetri->prev;
	save = tetri;
	while (tetri)
	{
		tetri->tetri >>= tetri->decal;
		tetri->pos_x = 1;
		tetri->pos_y = 0;
		tetri->decal = 0;
		tetri = tetri->next;
	}
	return (save);
}

void	reset_tetri(t_tetri *tetri)
{
	tetri->tetri >>= tetri->decal;
	tetri->pos_x = 1;
	tetri->pos_y = 0;
	tetri->decal = 0;
}

t_map	*grow_up_map(t_map *map)
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
	return (save);
}

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
	map = save->head;
	while (map->index != tetri->pos_y)
		map = map->next;
	return (map);
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
	static int i;
	t_map		*save;

	save = map;
		ft_putstr("######### TOUR No ");
		ft_putnbr(i);
		ft_putstr(" #########");
		ft_putchar('\n');
		print_map_bit(map->head);
		bilan_tour(tetri, map);
	if (multi_check(tetri, map))
	{
		set_tetri_map(&tetri, &map);
		i += 1;
		if (tetri->next)
			solver_recursif(tetri->next, map->head);
		else
		{
//			ft_putendl("La derniere piece a été posé");
			ft_putnbr(i);
			ft_putchar('\n');
			print_map_bit(map->head);
		}
	}
	else if (tetri->pos_x << (1 + tetri->width) <= power(2, map->width))
	{
		tetri->tetri <<= 1;
		tetri->pos_x <<= 1;
		tetri->decal += 1;
		i += 1;
		solver_recursif(tetri, map);
	}
	else if (map->next && tetri->length <= (map->width - map->next->index))
	{
		map = map->next;
		tetri->tetri >>= tetri->decal;
		tetri->pos_y += 1;
		tetri->pos_x = 1;
		tetri->decal = 0;
		i += 1;
		solver_recursif(tetri, map);
	}
	else if (!tetri->prev)
	{
		map = grow_up_map(map->head);
		tetri = clean_list_tetri(tetri);
		i += 1;
		solver_recursif(tetri, map);
	}
	else
	{
		map = reset_map(tetri->prev, map->head);
		reset_tetri(tetri);
		tetri = tetri->prev;
		tetri->tetri <<= 1;
		tetri->pos_x <<= 1;
		tetri->decal += 1;
		i += 1;
		solver_recursif(tetri, map);
	}
}
