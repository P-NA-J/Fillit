/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:57:39 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/14 14:26:58 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
