/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:59:29 by pauljull          #+#    #+#             */
/*   Updated: 2019/02/27 03:16:59 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct      s_map
{
    int             line;
    int             index;
    int             width;
    struct s_map    *next;
    struct s_map    *prev;
    struct s_map    *head;
}                   t_map;

typedef struct      s_tetri
{
    int             tetri;
    char            letter;
    char            pos_x;
    char            pos_y;
    char            length;
    char            width;
    char            decal;
    struct s_tetri  *next;
    struct s_tetri  *prev;
}                   t_tetri;

int                 ft_error(void);
int                 ft_read(int fd, char **file_ref);
int                 *database(void);
int	                check_file(t_tetri *tetri, int n_tetri);
int                 multi_check(t_tetri *tetri, t_map *map);
t_map               *ft_lpb_map(t_map **map_ref, int width, int index);
t_tetri	            *ft_lpb_tetri(t_tetri **list);
t_tetri             *ft_init_list(int n_tetri);
t_map               *gen(t_map **map_ref, int width);
t_map               *map_gen(int n_tetri);
int	                ft_square(int nb);
int	                power(int base, int exposant);
int	                check_column(char *file);
int	                check_line(char *file);
int	                convert_tetri(char *file, int decal);
int	                parser_tetri(char *file, int i_tetri, int tetri, char *letter);
t_tetri	            *parser_file(char *file, int n_tetri);
int		            print_fblock_bit(t_tetri **tetri_ref);
int		            check(t_tetri *tetri, int index, int mask);
void	            print_map_final(t_tetri *tetri, t_map *map);
void	            set_tetri_map(t_tetri **tetri, t_map **map);
void	            set_tetri(t_tetri *tetri);
int		            analyze_tetri_line(int tetri, int line);
int		            set_tetri_width(int tetri, int length);
int		            set_tetri_length(int tetri);
int	                set_fblock_bit(int tetri, int block, int decal);
int		            backtracking(t_tetri *tetri, t_map *map);
void	            solver(t_tetri **tetri_ref, t_map **map_ref);
void solver_recursif(t_tetri *tetri, t_map *map);
int	                validity_check(char *file, int n_tetri);
int		            first_one(int tetri);
void	            print_list_tetri(t_tetri *tetri);
void	            print_list_map(t_map *map);
void	ft_print_map_final(t_tetri *tetri, t_map *map);

void	            print_bit_int(int wallah);
void	            print_tetri_bit(int tetri);
void	            print_map_bit(t_map *map);
void	            print_tetri(t_tetri *tetri);
void	            bilan_tetri(t_tetri **tetri);

#endif
