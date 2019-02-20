/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:16:53 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/20 14:16:56 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	set_fblock_bit(int tetri, int block)
{
	int mask;
	int i;
	int bit;

	mask = 1 << ((block - 1) * 4);
	printf("%d\n", ((block - 1) * 4));
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