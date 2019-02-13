/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:59:29 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/11 09:46:48 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct  s_map
{
    int         line;
    int         index;
}               t_map;

typedef struct  s_tetri
{
    int         tetri;
    char        letter;
    char        pos_x;
    char        pos_y;
}               t_tetri;

int             ft_error(void);
int             ft_read(int fd, char **file_ref);

#endif
