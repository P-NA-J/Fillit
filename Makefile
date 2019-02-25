NAME := fillit
CC := gcc
FLAGS := -Wall -Wextra -Werror
SRC := source/database.c \
	   source/ft_check.c \
	   source/ft_error.c \
	   source/ft_list.c \
	   source/ft_read.c \
	   source/main.c \
	   source/map_gen.c \
	   source/math.c \
	   source/osef.c \
	   source/parsing.c \
	   source/print_map.c \
	   source/setting_tetri.c \
	   source/setting_map.c \
	   source/solver.c \
		
OBJ := $(SRC:.c=.o)
LIB := libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

libft:
	make -C ./libft/

%.o: ./source/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f source/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

unmap:
	rm -f Map/*

.PHONY: libft


