/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:43:12 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/15 15:03:13 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	analyze_block(char *file)
{
	int i;
	int hash;

	hash = 0;
	i = 0;
	while (i < 20)
	{
		if ((i + 1) % 5)
		{
			if (file[i] != '.' && file[i] != '#')
				return (0);
		}
		else if ((i + 1) % 5 == 0)
		{
			if (file[i] != '\n')
				return (0);
		}
		if (file[i] == '#')
			hash += 1;
		i += 1;
	}
	if (hash != 4)
		return (0);
	return (1);
}

int	validity_check(char *file, int ret)
{
	int i;

	i = 0;
	while (i < ret)
	{
		if (analyze_block(&file[i]) == 0)
			return (0);
		i += 20;
		if (i < ret && file[i] != '\n')
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_read(char **file, char **av)
{
	int		ret;
	int		fd;

	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(*file = (char *)malloc(546)))
		return (0);
	ft_bzero(*file, 546);
	if ((ret = read(fd, *file, 546)) < 0)
		return (0);
	if (validity_check(*file, ret) == 0)
		return (0);
	if ((ret % 21) != 20)
	{
		ft_bzero(*file, 546);
		free(*file);
		return (0);
	}
	return ((ret / 21) + 1);
}
