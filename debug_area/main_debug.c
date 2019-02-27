#include "../include/fillit.h"
#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int		print_block(t_tetri *tetri)
{
	int mask;
	int swipe;

	swipe = 0;
	mask = tetri->pos_x;
	while (mask & tetri->tetri)
	{
		write(1, &tetri->letter, 1);
		mask <<= 1;
		swipe += 1;
	}
	tetri->tetri >>= 4;
	tetri->pos_y += 1;
	mask = 1;
	while (!(mask & tetri->tetri))
		mask <<= 1;
	tetri->pos_x = mask;
	return (swipe);
}

int main(int ac, char **av)
{
	t_tetri *a;
	a = malloc(sizeof(t_tetri));

	a->tetri = 785;
	a->tetri <<= 3;
	a->pos_y = 1;
	a->letter = 'A';
	a->pos_x = 1 << 3;
	print_block(a);
	return (0);
}