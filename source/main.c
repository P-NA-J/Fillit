/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/25 14:57:20 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		n_tetri;

	if (ac != 2)
		return (ft_usage());
	if (ft_read(av[1]) < 0)
		return (ft_error());
	if (!ft_check_all())
	if (!fillit(file))
}
