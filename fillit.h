/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:59:29 by pauljull          #+#    #+#             */
/*   Updated: 2019/03/12 16:23:28 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_map
{
	unsigned int	line;
	unsigned int	index;
	unsigned int	width;
	struct s_map	*next;
	struct s_map	*prev;
	struct s_map	*head;
}					t_map;

typedef struct		s_tetri
{
	unsigned int	tetri;
	char			letter;
	unsigned int	pos_x;
	unsigned int	pos_y;
	unsigned int	length;
	unsigned int	width;
	unsigned int	decal;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

int					ft_error(void);
int					ft_read(char **file, char **av);
unsigned int		*database(void);
int					check_file(t_tetri *tetri, unsigned int n_tetri);
int					multi_check(t_tetri *tetri, t_map *map);
t_map				*ft_lpb_map(t_map **map_ref, int width, int index);
t_tetri				*ft_lpb_tetri(t_tetri **list);
t_tetri				*ft_init_list(int n_tetri);
t_map				*gen(t_map **map_ref, int width);
t_map				*map_gen(int n_tetri);
int					ft_square(int nb);
int					power(int base, int exposant);
int					check_column(char *file);
int					check_line(char *file);
int					convert_tetri(char *file, int decal);
int					parser_tetri(char *file, int i_tetri,
					int tetri, char *letter);
t_tetri				*parser_file(char *file, int n_tetri);
int					print_fblock_bit(t_tetri **tetri_ref);
int					check(t_tetri *tetri, int index, int mask);
void				print_map_final(char **print, int width);
void				set_tetri_map(t_tetri **tetri, t_map **map);
void				set_tetri(t_tetri *tetri);
int					analyze_tetri_line(int tetri, int line);
int					set_tetri_width(int tetri);
int					set_tetri_length(int tetri);
int					set_fblock_bit(int tetri, int block, int decal);
t_tetri				*backtracking(t_tetri *tetri, t_map **map);
int					solver(t_tetri *tetri, t_map *map);
int					first_one(int tetri);
void				print_list_tetri(t_tetri *tetri);
void				print_list_map(t_map *map);
void				ft_print_map_final(t_tetri *tetri, t_map *map);
int					solver(t_tetri *tetri, t_map *map);
void				print_bit_int(int wallah);
void				print_tetri_bit(int tetri);
void				print_map_bit(t_map *map);
void				print_tetri(t_tetri *tetri);
void				bilan_tetri(t_tetri **tetri);
void				bilan_tour(t_tetri *tetri, t_map *map);
t_map				*grow_up_map(t_map *map, t_tetri *tetri);
char				**print_tab_gen(t_tetri *tetri, int width);
void				print_tab_fill(t_tetri *tetri, char **print);
void				reset_tetri(t_tetri *tetri);
int					ft_print_set(t_tetri *tetri, t_map *map);
void				reset_map(t_tetri *tetri, t_map **map_ref);
int					ft_usage(void);
int					put_check(t_tetri *tetri, t_map *map);

#endif
