/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:56:03 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/28 20:22:40 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*database(void)
{
	int tab[19];

	tab[0] = 4369;
	tab[1] = 15;
	tab[2] = 51;
	tab[3] = 785;
	tab[4] = 547;
	tab[5] = 23;
	tab[6] = 116;
	tab[7] = 275;
	tab[8] = 802;
	tab[9] = 113;
	tab[10] = 71;
	tab[11] = 561;
	tab[12] = 54;
	tab[13] = 306;
	tab[14] = 99;
	tab[15] = 114;
	tab[16] = 562;
	tab[17] = 305;
	tab[18] = 39;
	return (tab)
}

int	check_file(int *tetri, int tab[19], int n_tetri)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	check = 0;
	while (i < n_tetri)
	{
		while (j < 19)
			if (tetri[i] == tab[j++])
				check += 1;
		i += 1;
	}
	if (check != n_tetri)
		return (0);
	return (1);
}
