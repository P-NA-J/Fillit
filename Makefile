NAME := fillit
CC := gcc
FLAGS := -Wall -Wextra -Wframe-larger-than=1024 -g
SRC := database.c \
	   ft_check.c \
	   ft_error.c \
	   ft_list.c \
	   ft_read.c \
	   main.c \
	   map_gen.c \
	   math.c \
	   osef.c \
	   parsing.c \
	   print_map.c \
	   setting_tetri.c \
	   setting_map.c \
	   solver.c \
		
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
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: libft


