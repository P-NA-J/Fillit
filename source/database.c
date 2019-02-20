/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:56:03 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/14 14:25:48 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*database(void)
{
	int *tab;

	if (!(tab = malloc(19 * sizeof(int))))
		return (NULL);
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
	return (tab);
}

int	power(int base, int exposant)
{
	int count;
	int result;

	count = 1;
	if (exposant == 0)
		return (1);
	result = base;
	while (count < exposant)
	{
		result *= base;
		count += 1;
	}
	return (result);
}
