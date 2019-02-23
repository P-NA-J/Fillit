/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:11:49 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/21 02:09:41 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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

int	parser_tetri(char *file, int i_tetri, int tetri, char *letter)
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
	*letter = i_tetri / 21 + 'A';
	return (tetri);
}

t_tetri	*parser_file(char *file, int n_tetri)
{
	int 	i;
	t_tetri	*tetri;
	t_tetri *head;

	if (!(tetri = ft_init_list(n_tetri)))
		return (0);
	head = tetri;
	i = 0;
	while (i < n_tetri)
	{
		tetri->tetri = parser_tetri(file, i * 21, tetri->tetri, &tetri->letter);
		set_tetri(tetri);
		tetri = tetri->next;
		i += 1;
	}
	return (head);
}