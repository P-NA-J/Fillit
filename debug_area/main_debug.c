#include "../include/fillit.h"

#include <unistd.h>
#include "../include/fillit.h"

void	print_bit_int(int wallah)
{
	unsigned int mask;

	mask = 1;
	while (mask < 2147483648)
	{
		if (mask & wallah)
			write(1, "1", 1);
		else
			write (1,"0", 1);
		mask <<= 1;	
	}
}

int	set_fblock_bit(int tetri, int block)
{
	int mask;
	int i;
	int bit;

	mask = 1 << ((block - 1) * 4);
	i = 0;
	bit = 0;
	while (i < 4)
	{
		if ((tetri & mask) != 0)
			bit += (tetri & mask);
		mask <<= 1;
		i += 1;
	}
	return (bit);
}

int		set_tetri_length(int tetri)
{
	int i;

	i = 1;
	while (i <= 4)
	{
		if (!set_fblock_bit(tetri, i))
			return (i - 1);
		i += 1;
	}
	return (i - 1);
}

int		analyze_tetri_line(int tetri, int line)
{
	int mask;
	int i;

	i = 0;
	mask = 1;
	line = set_fblock_bit(tetri , line);
	while (mask & line)
	{	
		i += 1;
		mask <<= 1;
	}
	return (i);
}

int		set_tetri_width(int tetri, int length)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < length)
	{
		if (j < analyze_tetri_line(tetri, i))
			j = analyze_tetri_line(tetri, i);
		i += 1;
	}
	return (j);
}

int	*database(void)
{
	int *tab;

	if (!(tab = malloc(19 * sizeof(int))))
		return (NULL);
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

int	power(int base, int exposant)
{
	int count;
	int result;

	count = 1;
	if (exposant == 0)
		return (1);
	result = base;
	while (count < exposant)
	{
		result *= base;
		count += 1;
	}
	return (result);
}

int	check_file(t_tetri *tetri, int n_tetri)
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
			if (tetri->tetri == tab[j++])
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


t_tetri	*ft_lpb_tetri(t_tetri **list)
{
	t_tetri *l_list;
    t_tetri *node;
    t_tetri *save;

    l_list = *list;
    save = l_list;
    if (!(node = (t_tetri *)malloc(sizeof(t_tetri))))
        return (NULL);
    node->next = NULL;
    if (!l_list)
    {
        l_list = node;
        l_list->prev = NULL;
        return (l_list);
    }
    while (l_list->next)
        l_list = l_list->next;
    l_list->next = node;
    node->prev = l_list;
    return (save);
}

t_tetri *ft_init_list(int n_tetri)
{
    t_tetri *tmp;
    int    count;

    count = 0;
	tmp = NULL;
    while (count <= n_tetri)
    {
        tmp = ft_lpb_tetri(&tmp);
        count += 1;
    }
	return (tmp);
}

int	ft_read(int fd, char **file_ref)
{
	char	*file;
	int		ret;

	if (!(*file_ref = (char *)malloc(546)))
		return (0);
	ft_bzero(*file_ref, 545);
	file = *file_ref;
	if ((ret = read(fd, file, 545)) < 0)
		return (0);
	file[ret] = 0;
	if ((ret % 21) != 20)
	{
		ft_bzero(file, 545);
		free(file);
		return (0);
	}
	return ((ret / 21) + 1);
}

int	ft_square(int nb)
{
	int sqr;
	
	sqr = 1;
	while (sqr * sqr < nb)
		sqr += 1;
	return (sqr);
}

t_map    *ft_lpb_map(t_map **map_ref, int width)
{
    t_map *l_map;
    t_map *node;
    t_map *save;

    l_map = *map_ref;
	save = l_map;
    if (!(node = (t_map *)malloc(sizeof(t_map))))
        return (NULL);
    node->next = NULL;
	node->width = width;
    if (!l_map)
    {
        l_map = node;
        l_map->prev = NULL;
        return (l_map);
    }
    while (l_map->next)
        l_map = l_map->next;
    l_map->next = node;
    node->prev = l_map;
	return (save);
}

t_map   *gen(t_map **map_ref, int width)
{
    int     i;
	t_map	*l_map;

	l_map = *map_ref;
    i = 0;
    while (i <= width)
	{
        l_map = ft_lpb_map(&l_map, width);
		i += 1;
	}
	return (l_map);
}

t_map   *map_gen(int n_tetri)
{
    t_map   *map;

	map = NULL;
    return (gen(&map, 5));
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

void	parser_tetri(char *file, int i_tetri, t_tetri *tetri)
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
	tetri->tetri = convert_tetri(&file[decal], decal);
	tetri->letter = i_tetri / 21 + 'A';
}

void	set_tetri(t_tetri *tetri)
{
	tetri->length = set_tetri_length(tetri->tetri);
	tetri->width = set_tetri_width(tetri->tetri, tetri->length);
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
		parser_tetri(file, i * 21, tetri);
		set_tetri(tetri);
		tetri = tetri->next;
		i += 1;
	}
	return (head);
}

int		print_fblock_bit(t_tetri **tetri_ref)
{
	int swipe;
	int	line_tetri;
	int mask;
	t_tetri *l_tetri;


	l_tetri = *tetri_ref;
	line_tetri = l_tetri->tetri;
	swipe = 0;
	mask = 1;
	while (mask & line_tetri)
	{
		ft_putchar(l_tetri->letter);
		swipe += 1;
		mask <<= 1;
	}
	l_tetri->tetri >>= 4;
	l_tetri->pos_y += 1;
	mask = 1;
	while ((l_tetri->tetri != 0) && !(l_tetri->tetri & mask))
	{	
		mask <<= 1;
		l_tetri->pos_x <<= 1;
	}
	return (swipe);
}

int		check(t_tetri *tetri, int index, int mask)
{
	if ((tetri->pos_y == index) && (tetri->pos_x == mask))
		return (1);
	return (0);
}




void	print_map_final(t_tetri *tetri, t_map *map)
{
	t_tetri *head;
	int 	mask;

	head = tetri;
	mask = 1;
	while (map->next)
	{
		while (mask < power(2, map->width))
		{	
			while (tetri && !check(tetri, map->index, mask))
				tetri = tetri->next;
			if (!tetri)
			{
				ft_putchar('.');
				mask <<= 1;
			}
			else
				mask <<= print_fblock_bit(&tetri);
			tetri = head;
		}
		ft_putchar('\n');
		mask = 1;
		tetri = head;
		map = map->next;
	}
}

void	print_tetri_bit(int tetri)
{
	int mask;
	int count;

	count = 0;
	mask = 1;
	while (mask < 65536)
	{
		if ((tetri & mask) != 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask <<= 1;
		count += 1;
		if (count == 4)
		{
			write(1, "\n", 1);
			count = 0;
		}
	}
}

void	print_map_bit(t_map *map)
{
	int mask;
	int i;

	mask = 1;
	i = 0;
	while (map->next)
	{
		while (i < map->width)
		{
			if ((map->line & mask) != 0)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			i += 1;
			mask <<= 1;
		}
		write(1, "\n", 1);
		i = 0;
		mask = 1;
		map = map->next;
	}
}

int multi_check(t_tetri *tetri, t_map *map)
{
	int i;

	i = 1;
	while (i <= tetri->length)
	{
		if ((map->line + set_fblock_bit(tetri->tetri, i)) != (map->line | set_fblock_bit(tetri->tetri, i)))
			return (0);
		map = map->next;
		i += 1;
	}
	return (1);
}

void	print_tetri(t_tetri *tetri)
{
	print_tetri_bit(tetri->tetri);
	printf("\nletter : %c\n", tetri->letter);
	printf("length : %d\n", tetri->length);
	printf("width : %d\n", tetri->width);
	printf("pos_x : %d\n", tetri->pos_x);
	printf("pos_y : %d\n###############################\n", tetri->pos_y);
}

void	set_tetri_map(t_tetri *tetri, t_map *map)
{
	int	mask;
	int	i;

	i = 1;
	while (i <= tetri->length)
	{
		mask = 1;
		tetri->pos_y = map->index;
		while (!(mask & tetri->tetri))
			mask <<= 1;
		while (mask & tetri->tetri)
			mask <<= 1;
		tetri->pos_x = mask;
		print_bit_int(set_fblock_bit(tetri->tetri, i));
		printf("DEBUG MODE\nmap->line = %d\ntetri_line = %d\nFIN DEBUG MODE\n", map->line, set_fblock_bit(tetri->tetri, i));
		map->line += set_fblock_bit(tetri->tetri, i);
		i += 1;
		map = map->next;
	}
}





/*
int		backtracking(t_tetri *tetri, t_map *map)
{
	if ((tetri->pos_x <<= (1 + tetri->length)) <= map->width)
	{	
		tetri->tetri <<= 1;
		tetri->pos_x <<= 1;
		if (multi_check(tetri, map))


	}
}
*/
void	solver(t_tetri **tetri_ref, t_map **map_ref)
{
	t_tetri	*l_tetri;
	t_map	*l_map;
	t_tetri *save;


	l_tetri = *tetri_ref;
	l_map = *map_ref;
	while (l_tetri)
	{
//		while (l_map && l_tetri)
//		{
			save = l_tetri;
			if (multi_check(l_tetri, l_map))
			{
				set_tetri_map(l_tetri, l_map);
				print_map_bit(l_map);
				l_tetri = l_tetri->next;
				l_map = *map_ref;
			}
/*			else if ((l_tetri->pos_x <<= (1 + l_tetri->length)) <= l_map->width)
			{	
				l_tetri->tetri <<= 1;
				l_tetri->pos_x <<= 1;
			}
			else
			{
				l_map = l_map->next;
				l_tetri = save;
			}
*/		}
/*		if (!l_map)
			if (backtracking(l_map, l_tetri->prev) == 1)
				print_map_final(*tetri_ref, *map_ref);
	}
*/

//	print_map_final(*tetri_ref, *map_ref);
}




int main(int ac, char **av)
{
	t_tetri *tetri;
	t_map	*map;
	int n_tetri;
	int fd;
	char *file;

	if(!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(n_tetri = ft_read(fd, &file)))
		return (0);
	tetri = parser_file(file, n_tetri);
	map = gen(&map, 5);
	print_bit_int(map->line);
	solver(&tetri, &map);
	return (0);
}