
#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
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

int	set_fblock_bit(int tetri, int block, int decal)
{
	int mask;
	int i;
	int bit;

	mask = 1;
	while (mask < power(2, decal))
		mask <<= 1;
	mask  <<= ((block - 1) * 4);
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

int main(int ac, char **av)
{
	int a = 785;
	int map1 = 7;
	int map2 = 7;
	int map3 = 15;
	
	a <<= 2;

	print_bit_int(map1);
	print_bit_int(map2);
	print_bit_int(map3);

	printf("\n");

	print_bit_int(set_fblock_bit(a, 1, 2));
	print_bit_int(set_fblock_bit(a, 2, 2) >> 4);
	print_bit_int(set_fblock_bit(a, 3, 2) >> 8);

	map1 ^= set_fblock_bit(a, 1, 1);
	map2 ^= set_fblock_bit(a, 2, 1) >> 4;
	map3 ^= set_fblock_bit(a, 3, 1) >> 8;

	printf("\n");
	print_bit_int(map1);
	print_bit_int(map2);
	print_bit_int(map3);
	return (0);
}