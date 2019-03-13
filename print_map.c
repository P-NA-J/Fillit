/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:17:47 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/12 16:22:44 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_print_set(t_tetri *tetri, t_map *map)
{
	unsigned int	mask;
	unsigned int	i;
	unsigned int	tmp;

	i = 1;
	mask = 1;
	tmp = set_fblock_bit(tetri->tetri, 1, tetri->decal) |
	(((set_fblock_bit(tetri->tetri, 2, tetri->decal) >> 4) |
	((set_fblock_bit(tetri->tetri, 3, tetri->decal) >> 8) |
	(set_fblock_bit(tetri->tetri, 4, tetri->decal) >> 12))));
	tetri->pos_y = map->index;
	while (!(mask & tmp))
		mask <<= 1;
	tetri->pos_x = mask;
	while (i <= tetri->length)
	{
		map->line += set_fblock_bit(tetri->tetri, i, tetri->decal) >>
		4 * (i - 1);
		i += 1;
		map = map->next;
	}
	return (1);
}

void	print_map_final(char **print, int width)
{
	int i;

	i = 0;
	while (i < width)
		ft_putendl(print[i++]);
}

void	print_tab_fill(t_tetri *tetri, char **print)
{
	unsigned int count_x;
	unsigned int count_y;
	unsigned int mask;

	mask = 1;
	count_x = 0;
	count_y = 0;
	while (count_y != tetri->pos_y)
		count_y += 1;
	while (!(mask & tetri->pos_x))
	{
		mask <<= 1;
		count_x += 1;
	}
	mask = 1;
	while (!(mask & tetri->tetri))
		mask <<= 1;
	while (mask & tetri->tetri)
	{
		print[count_y][count_x] = tetri->letter;
		count_x += 1;
		mask <<= 1;
	}
}

void	set_point(int width, char **print)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < width)
	{
		while (j < width)
		{
			if (print[i][j] < 'A' || print[i][j] > 'Z')
				print[i][j] = '.';
			j += 1;
		}
		print[i][j] = 0;
		j = 0;
		i += 1;
	}
}

char	**print_tab_gen(t_tetri *tetri, int width)
{
	char	**print;
	int		i;

	i = 0;
	if (!(print = (char **)malloc(sizeof(char *) * width)))
		return (NULL);
	while (i < width)
		if (!(print[i++] = (char *)malloc(width + 1)))
			return (NULL);
	set_point(width, print);
	while (tetri)
	{
		i = 1;
		tetri->tetri >>= tetri->decal;
		while (tetri->tetri)
		{
			tetri->pos_x = 1 << (first_one(tetri->tetri) + tetri->decal);
			print_tab_fill(tetri, print);
			tetri->tetri >>= 4;
			tetri->pos_y += 1;
			i += 1;
		}
		tetri = tetri->next;
	}
	return (print);
}
