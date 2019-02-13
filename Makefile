NAME := fillit
CC := gcc
FLAGS := -Wall -Wextra -Werror
SRC := parsing.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $^

read: main.o ft_read.o ft_error.o
	make libft
	$(CC) $(FLAGS) -o $@ $^ ./libft/libft.a

libft:
	make -C ./libft/

%.o: ./source/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

unmap:
	rm -f Map/*

.PHONY: libft


