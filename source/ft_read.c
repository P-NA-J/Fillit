/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:43:12 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/11 15:38:30 by pauljull         ###   ########.fr       */
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
	printf("fd = %d\n", fd);
	if ((ret = read(fd, file, 545)) < 0)
		return (0);
	file[ret] = 0;
	printf("ret = %d\n", ret);
	if ((ret % 21) != 20)
	{
		ft_bzero(file, 545);
		free(file);
		return (0);
	}
	return (1);
}