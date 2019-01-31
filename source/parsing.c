/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:11:49 by pauljull          #+#    #+#             */
/*   Updated: 2019/01/29 17:01:41 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	*database(void)
{
	int *tab;

	if (!(tab = (int *)malloc(sizeof(int) * 19)))
		return (0);
	tab[0] = 4369;
	tab[1] = 15;
	tab[2] = 51;
	tab[3] = 785;
	tab[4] = 547;
	tab[5] = 23;
	tab[6] = 116;
	tab[7] = 275;
	tab[8] = 802;
	tab[9] = 113;
	tab[10] = 71;
	tab[11] = 561;
	tab[12] = 54;
	tab[13] = 306;
	tab[14] = 99;
	tab[15] = 114;
	tab[16] = 562;
	tab[17] = 305;
	tab[18] = 39;
	return (tab);
}

int	check_file(int *tetri, int n_tetri)
{
	int i;
	int j;
	int check;
	int	*tab;

	i = 0;
	j = 0;
	check = 0;
	tab = database();
	while (i < n_tetri)
	{
		while (j < 19)
		{
			if (tetri[i] == tab[j++])
			{
				check += 1;
				break;
			}
		}
		i += 1;
		j = 0;
	}
	if (check != n_tetri)
		return (0);
	return (1);
}

int	power(int multiplier, int multiplicateur)
{
	int	i;
	int	result;

	i = 1;
	result = multiplier;
	if (multiplicateur == 0)
		return (1);
	while (i < multiplicateur)
	{
		result *= multiplier;
		i += 1;
	}
	return (result);
}

int	check_column(char *file)
{
	if (*file == '#' || *(file + 5) == '#' || *(file + 10) == '#' || *(file + 15) == '#')
		return (1);
	return (0);
}

int	check_line(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\n')
	{
		if (file[i] == '#')
			return (1);
		i += 1;
	}
	return (0);
}

int	convert_tetri(char *file, int decal)
{
	int	i;
	int	k;
	int	link;
	int	tetri_j;

	i = 0;
	link = 0;
	k = decal;
	tetri_j = 0;
	while (link < 4)
	{
		if (file[i] == '#')
		{
			tetri_j += power(2, k - decal);
			link += 1;
		}
		if (file[i] != '\n')
			k += 1;
		i += 1;
	}
	return (tetri_j);
}

int	parser_tetri(char *file, int i_tetri, int tetri)
{
	int	line;
	int	raw;
	int	i;
	int	decal;

	i = 0;
	while (!(check_column(&file[i_tetri + i])))
		i += 1;
	raw = i + 1;
	i = 0;
	while (!(check_line(&file[i_tetri + i])))
		i += 5;
	line = i / 5 + 1;
	decal = i_tetri + 5 * (line - 1) + raw - 1;
	tetri = convert_tetri(&file[decal], decal);
	return (tetri);
}

int	*parser_file(char *file, int n_tetri)
{
	int i;
	int	*tetri;

	if (!(tetri = (int *)malloc(sizeof(int) * n_tetri)))
		return (0);
	i = 0;
	while (i < n_tetri)
	{
		tetri[i] = parser_tetri(file, i * 21, tetri[i]);
		i += 1;
	}
	return (tetri);
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char file[546];
	int ret = read(fd, file, 545);
	int	*tetri;
	int n_tetri;
	int i;

	file[ret] = 0;
	n_tetri = (ret / 21) + 1;
	i = 0;
	if (fd < 0)
		return (0);
	tetri = parser_file(file, n_tetri);
	if (check_file(tetri, n_tetri))
		printf("VALID");
	else
		printf("INVALID");
	return (0);
}
