/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:57:39 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/25 18:06:08 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_error(void)
{
	return (0);
}

int	ft_check_line(char *file)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (file[i] != '.' && file[i] != '#')
			return (ft_error());
		i += 1;
	}
	if (file[i] != '\n')
		return (ft_error());
	return (1);
}

int	ft_check(char *file, int ret)
{
	int i;
	int	n_tetri;

	i = 0;
	if ((ret % 21) != 20)
		return (ft_error());
	while (file[i])
	{
		if (file[i] == '\n')
			i += 1;
		else if (file[i] != '#' && file[i] != '.')
			return (ft_error());
		if (!ft_check_line(&file[i]))
			return (ft_error());
		i += 5;
	}
	n_tetri = (ret / 21) + 1;
	printf("%d\n", n_tetri);
	return (1);
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
