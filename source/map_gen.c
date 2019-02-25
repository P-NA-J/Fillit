/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:02:42 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/25 23:16:31 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_map   *map_gen(int n_tetri)
{
    t_map   *map;
	t_map *save;
	int     i;

	map = NULL;
 	i = 0;
    while (i < 5)
	{
        map = ft_lpb_map(&map, 5, i);
		if (i == 0)
			save = map;
		i += 1;
	}
    return (save);
}
