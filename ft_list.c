/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:11:35 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/11 21:14:12 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_lpb_map(t_map **map_ref, int width, int index)
{
	t_map *l_map;
	t_map *node;
	t_map *save;

	l_map = *map_ref;
	save = l_map;
	if (!(node = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	node->next = NULL;
	node->index = index;
	node->width = width;
	if (!l_map)
	{
		l_map = node;
		l_map->prev = NULL;
		l_map->head = node;
		return (l_map);
	}
	while (l_map->next)
		l_map = l_map->next;
	l_map->next = node;
	node->prev = l_map;
	node->head = l_map->head;
	return (save);
}

t_tetri	*ft_lpb_tetri(t_tetri **list)
{
	t_tetri *l_list;
	t_tetri *node;
	t_tetri *save;

	l_list = *list;
	save = l_list;
	if (!(node = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	node->next = NULL;
	node->pos_x = 1;
	if (!l_list)
	{
		l_list = node;
		l_list->prev = NULL;
		return (l_list);
	}
	while (l_list->next)
		l_list = l_list->next;
	l_list->next = node;
	node->prev = l_list;
	return (save);
}

t_tetri	*ft_init_list(int n_tetri)
{
	t_tetri	*tmp;
	int		count;

	count = 1;
	tmp = NULL;
	while (count <= n_tetri)
	{
		tmp = ft_lpb_tetri(&tmp);
		count += 1;
	}
	return (tmp);
}
