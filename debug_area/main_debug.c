

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