/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:39:51 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/11 16:06:30 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*file;

	if (ac != 2)
		return (ft_error());
		printf("%s\n%s\n", av[0], av[1]);
	if ((fd = open(av[1], O_RDONLY) < 0))
		return (ft_error());
	printf("fd = %d\n", fd);
	if (!(ft_read(fd, &file)))
		return (ft_error());
	return (0);
}
