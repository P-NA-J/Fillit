/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:43:12 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/25 14:57:25 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_read(char *file_name)
{
	char	*file;
	int		ret;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	if ((ret = read(fd, file, 545)))
		return (0);
	if ((ret % 21) != 20)
		return (0);
	if ((n_tetri = ft_check(file)) == 0)
		return (0);
	return (parsing(file));
}
