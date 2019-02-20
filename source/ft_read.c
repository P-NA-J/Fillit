/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:43:12 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/14 14:27:06 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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
	return ((ret / 21) + 1);
}