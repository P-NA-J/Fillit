/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:57:09 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/11 21:53:03 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_tetri(t_tetri *tetri)
{
	tetri->tetri >>= tetri->decal;
	tetri->decal = 0;
	tetri->pos_x = 1;
	tetri->pos_y = 0;
}

int		ft_usage(void)
{
	ft_putendl("usage : ./fillit file");
	return (0);
}

int		ft_error(void)
{
	ft_putendl("error");
	return (0);
}
