/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:17:47 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/27 04:54:05 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		check(t_tetri *tetri, int index, int mask)
{
//	if (index == 2 && tetri->letter == 'B')
//		printf("pos_x = %d\npos_y = %d\nmask = %d\n", tetri->pos_x, tetri->pos_y, mask);


	if ((tetri->pos_y == index) && (tetri->pos_x == mask))
		return (1);
	return (0);
}

int		print_block(t_tetri *tetri)
{
	int mask;
	int swipe;

	swipe = 0;
	mask = tetri->pos_x;
	while (mask & tetri->tetri)
	{
		write(1, &tetri->letter, 1);
		mask <<= 1;
		swipe += 1;
	}
	tetri->tetri >>= 4;
	tetri->pos_y += 1;
	if (tetri->tetri)
	{
		mask = tetri->pos_x;
		while (!(mask & tetri->tetri))
			mask <<= 1;
	}
	tetri->pos_x = mask;
	return (swipe);
}

void	ft_print_map_final(t_tetri *tetri, t_map *map)
{
	int mask;
	t_tetri *head;

	head = tetri;
	while (map)
	{
		mask = 1;
		while (mask < (1 << map->width))
		{
			if (!(mask & map->line))
			{
				write(1, ".", 1);
				mask <<= 1;
			}
			else
			{
				while (!check(tetri, map->index, mask))
					tetri = tetri->next;
				if (tetri)
					mask <<= print_block(tetri);
				tetri = head;
			}
		}
		map = map->next;
		tetri = head;
		ft_putchar('\n');
	}
}