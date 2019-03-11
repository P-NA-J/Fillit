/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:43:12 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/11 23:04:52 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_read(char **file, char **av)
{
	int		ret;
	int		fd;
	int		i;

	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(*file = (char *)malloc(546)))
		return (0);
	ft_bzero(*file, 546);
	if ((ret = read(fd, *file, 546)) < 0)
		return (0);
	if ((ret % 21) != 20)
	{
		ft_bzero(*file, 546);
		free(*file);
		return (0);
	}
	return ((ret / 21) + 1);
}
