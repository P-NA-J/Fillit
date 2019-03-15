NAME := fillit
CC := gcc
FLAGS := -Wall -Wextra -Werror
SRC := database.c \
	   ft_check.c \
	   ft_error.c \
	   ft_list.c \
	   ft_read.c \
	   main.c \
	   map_gen.c \
	   math.c \
	   parsing.c \
	   print_map.c \
	   setting_tetri.c \
	   setting_map.c \
	   solver.c \

OBJ := $(SRC:.c=.o)
LIB := libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

comp_libft:
	make -C libft

clean: clean_libft
	rm -f $(OBJ)

clean_libft:
	make clean -C libft

fclean_libft: clean_libft
	rm -f libft/libft.a

fclean: clean fclean_libft
	rm -f $(NAME)

re: fclean all


.PHONY: libft


