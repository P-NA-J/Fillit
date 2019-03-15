/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:59:57 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/12 16:24:34 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_tetri(t_tetri *tetri)
{
	tetri->length = set_tetri_length(tetri->tetri);
	tetri->width = set_tetri_width(tetri->tetri);
	tetri->decal = 0;
	tetri->pos_y = 0;
	tetri->pos_x = 1;
}

int		analyze_tetri_line(int tetri, int line)
{
	int mask;
	int i;

	i = 0;
	mask = 1;
	line = set_fblock_bit(tetri, line, 0);
	while (mask & line)
	{
		i += 1;
		mask <<= 1;
	}
	return (i);
}

int		set_tetri_width(int tetri)
{
	int line;
	int j;

	line = set_fblock_bit(tetri, 1, 0) |
	((set_fblock_bit(tetri, 2, 0) >> 4) |
	((set_fblock_bit(tetri, 3, 0) >> 8) |
	(set_fblock_bit(tetri, 4, 0) >> 12)));
	j = analyze_tetri_line(line, 1);
	return (j);
}

int		set_tetri_length(int tetri)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		if (!set_fblock_bit(tetri, i, 0))
			return (i - 1);
		i += 1;
	}
	return (i - 1);
}

int		set_fblock_bit(int tetri, int block, int decal)
{
	int mask;
	int i;
	int bit;

	mask = 1;
	while (mask < power(2, decal))
		mask <<= 1;
	mask <<= ((block - 1) * 4);
	i = 0;
	bit = 0;
	while (i < 4)
	{
		if ((tetri & mask) != 0)
			bit += (tetri & mask);
		mask <<= 1;
		i += 1;
	}
	return (bit);
}
