/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:59:57 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/21 02:58:17 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	set_tetri(t_tetri *tetri)
{
	tetri->length = set_tetri_length(tetri->tetri);
	tetri->width = set_tetri_width(tetri->tetri, tetri->length);
}

int		analyze_tetri_line(int tetri, int line)
{
	int mask;
	int i;

	i = 0;
	mask = 1;
	line = set_fblock_bit(tetri , line);
	while (mask & line)
	{	
		i += 1;
		mask <<= 1;
	}
	return (i);
}

int		set_tetri_width(int tetri, int length)
{
	int line;
	int j;

	line = set_fblock_bit(tetri, 1) | ((set_fblock_bit(tetri, 2) >> 4) | ((set_fblock_bit(tetri, 3) >> 8) | (set_fblock_bit(tetri, 4) >> 12)));
	j = analyze_tetri_line(line, 1);	
	return (j);
}

int		set_tetri_length(int tetri)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		if (!set_fblock_bit(tetri, i))
			return (i - 1);
		i += 1;
	}
	return (i - 1);
}

int	set_fblock_bit(int tetri, int block)
{
	int mask;
	int i;
	int bit;

	mask = 1 << ((block - 1) * 4);
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