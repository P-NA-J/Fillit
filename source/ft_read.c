/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:43:12 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/03 20:32:56 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	validity_check(char *file, int n_tetri)
{
	int i;
	int j;
	int tetri;

	i = 0;
	j = 0;
	tetri = 0;
	while (file[i])
	{
		if (j < 4)
		{
			if (file[i] != '#' && file[i] != '.')
				return (0);
			if (file[i] == '#')
				tetri += 1;
			if (tetri > 4)
				return (0);
			j += 1;
		}
		else if (j == 4)
		{
			if (file[i] != '\n')
				return (0);
			j = 0;
		}
		i += 1;
		if ((i % 21) == 20)
		{
			i += 1;
			tetri = 0;
		}
	}
	return (n_tetri);
}

int	ft_read(int fd, char **file_ref)
{
	char	*file;
	int		ret;

	if (!(*file_ref = (char *)malloc(546)))
		return (0);
	ft_bzero(*file_ref, 545);
	file = *file_ref;
	if ((ret = read(fd, file, 545)) < 0)
		return (0);
	file[ret] = 0;
	if ((ret % 21) != 20)
	{
		ft_bzero(file, 545);
		free(file);
		return (0);
	}
	return (validity_check(file, (ret / 21) + 1));
}