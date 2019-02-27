#include "../include/fillit.h"

void	print_list_map(t_map *map)
{
	while (map)
	{
		print_bit_int(map->line);
		printf("index = %d\n", map->index);
		printf("width = %d\n", map->width);
		printf("Head = %p\n", map->head);
		map = map->next;
	}
}

void	print_list_tetri(t_tetri *tetri)
{
	while (tetri)
	{
		printf("### Debut du tetri ###\n");
		printf("tetri :\n");
		print_tetri_bit(tetri->tetri);
		printf("tetri->pos_x = \n");
		print_bit_int(tetri->pos_x);
		printf("tetri->pos_y = %d\n\n", tetri->pos_y);
		tetri = tetri->next;
	}
}

void	bilan_tetri(t_tetri **tetri)
{
	int i;
	t_tetri *l_tetri;

	l_tetri = *tetri;
	i = 1;
	while (l_tetri)
	{
		printf("### Tetri numero %d ###\n", i++);
		printf("%c\n", l_tetri->letter);
		printf("pos_y = %d\n", l_tetri->pos_y);
		printf("pos_x = %d\n", l_tetri->pos_x);
		printf("\n");
		l_tetri = l_tetri->next;
	}
}

void	print_tetri(t_tetri *tetri)
{
	print_tetri_bit(tetri->tetri);
	printf("\nletter : %c\n", tetri->letter);
	printf("length : %d\n", tetri->length);
	printf("width : %d\n", tetri->width);
	printf("pos_x : %d\n\n", tetri->pos_x);
	printf("pos_y : %d\n###############################\n\n", tetri->pos_y);
}

void	print_map_bit(t_map *map)
{
	int mask;
	int i;

	mask = 1;
	i = 0;
	while (map)
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
	printf("\n");
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
	ft_putchar('\n');
}

void	print_bit_int(int wallah)
{
	unsigned int mask;
	int i;

	i = 0;
	mask = 1;
	while (mask < 2147483648)
	{
		if (mask & wallah)
			write(1, "1", 1);
		else
			write (1,"0", 1);
		mask <<= 1;
		i += 1;
		if (i == 4)
		{
			write(1, " ", 1);
			i = 0;
		}	
	}
	ft_putchar('\n');
}