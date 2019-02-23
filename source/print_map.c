/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:17:47 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/21 06:04:06 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		print_fblock_bit(t_tetri **tetri_ref)
{
	int swipe;
	int	line_tetri;
	int mask;
	t_tetri *l_tetri;


	l_tetri = *tetri_ref;
	line_tetri = l_tetri->tetri;
	swipe = 0;
	mask = 1;
	while (mask & line_tetri)
	{
		ft_putchar(l_tetri->letter);
		swipe += 1;
		mask <<= 1;
	}
	l_tetri->tetri >>= 4;
	l_tetri->pos_y += 1;
	mask = 1;
	while ((l_tetri->tetri != 0) && !(l_tetri->tetri & mask))
	{	
		mask <<= 1;
		l_tetri->pos_x <<= 1;
	}
	return (swipe);
}

int		check(t_tetri *tetri, int index, int mask)
{
	if ((tetri->pos_y == index) && (tetri->pos_x == mask))
		return (1);
	return (0);
}

void	print_map_final(t_tetri *tetri, t_map *map)
{
	t_tetri *head;
	int 	mask;

	head = tetri;
	mask = 1;
	while (map->next)
	{
		while (mask < power(2, map->width))
		{	
			while (tetri && !check(tetri, map->index, mask))
				tetri = tetri->next;
			if (!tetri)
			{
				ft_putchar('.');
				mask <<= 1;
			}
			else
				mask <<= print_fblock_bit(&tetri);
			tetri = head;
		}
		ft_putchar('\n');
		mask = 1;
		tetri = head;
		map = map->next;
	}
}