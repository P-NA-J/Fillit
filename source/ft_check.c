/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:57:39 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/03 11:59:51 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	check_file(t_tetri *tetri, int n_tetri)
{
	int i;
	int j;
	int check;
	int	*tab;

	i = 0;
	j = 0;
	check = 0;
	tab = database();
	while (i < n_tetri)
	{
		while (j < 19)
		{
			if (tetri->tetri == tab[j++])
			{
				check += 1;
				break;
			}
		}
		i += 1;
		j = 0;
	}
	if (check != n_tetri)
		return (0);
	return (1);
}

int multi_check(t_tetri *tetri, t_map *map)
{
	int i;

	i = 1;
	if (tetri->width + tetri->decal > map->width)
		return (0);
	if (tetri->length > (map->width - map->index))
		return (0);
	while (i <= tetri->length)
	{
		if ((map->line + (set_fblock_bit(tetri->tetri, i, tetri->decal) >> (i - 1) * 4)) 
		!= (map->line | set_fblock_bit(tetri->tetri, i, tetri->decal) >> (i - 1) * 4))
			return (0);
		map = map->next;
		i += 1;
	}
	return (1);
}