NAME := fillit

SRC := parsing.c
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

test:
	for number in 1 2 3 4; do \
		echo $$number; \
	done

gen:
	for i in `seq 1 ${test}` ; do \
		for j in `seq 1 50` ; do \
			echo "$$i $$j"; \
			./binaire/gen valid $$i > Map/valid_$$i\_$$j; \
			cat Map/valid_$$i\_$$j; \
		done \
	done \
	