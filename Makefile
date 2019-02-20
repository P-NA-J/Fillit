NAME := fillit
CC := gcc
FLAGS := -Wall -Wextra -Werror
SRC := source/main.c
OBJ := $(SRC:.c=.o)
LIB := libft/libft.a
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)
	rm source/*.o

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


