NAME := fillit

SRC := ft_error.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $^ ./libft/libft.a

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
