/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:02:42 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/20 21:45:10 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filit.h"


int	ft_square(int nb)
{
	int sqr;
	
	sqr = 1;
	while (sqr * sqr < nb)
		sqr += 1;
	return (sqr);
}

t_map    *ft_lpb_map(t_map **map_ref, int width)
{
    t_map *l_map;
    t_map *node;
    t_map *save;

    l_map = *map_ref;
	save = l_map;
    if (!(node = (t_map *)malloc(sizeof(t_map))))
        return (NULL);
    node->next = NULL;
	node->width = width;
    if (!l_map)
    {
        l_map = node;
        l_map->prev = NULL;
        return (l_map);
    }
    while (l_map->next)
        l_map = l_map->next;
    l_map->next = node;
    node->prev = l_map;
	return (save);
}

t_map   *gen(t_map **map_ref, int width)
{
    int     i;
	t_map	*l_map;

	l_map = *map_ref;
    i = 0;
    while (i <= width)
	{
        l_map = ft_lpb_map(&l_map, width);
		i += 1;
	}
	return (l_map);
}

t_map   *map_gen(int n_tetri)
{
    t_map   *map;

	map = NULL;
    return (gen(&map, 5));
  //  return (gen(&map, ft_square(n_tetri * 4)));
}
