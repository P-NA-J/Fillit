/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:57:39 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/28 19:14:20 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_line(char *file)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (file[i] != '.' && file[i] != '#')
			return (0;
		i += 1;
	}
	if (file[i] != '\n')
		return (0);
	return (1);
}

int	ft_check(char *file, int ret)
{
	int i;

	i = 0;
	if ((ret % 21) != 20)
		return (0);
	while (file[i])
	{
		if (file[i] == '\n')
			i += 1;
		else if (file[i] != '#' && file[i] != '.')
			return (0);
		if (!ft_check_line(&file[i]))
			return (0);
		i += 5;
	}
	return ((ret / 21) + 1);
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char file[546];
	int ret = read(fd, file, 545);

	file[ret] = 0;
	if (ft_check(file, ret) != 0)
		printf("Ca marche");
	else
		printf("Ca marche pas");
	return (0);
}
