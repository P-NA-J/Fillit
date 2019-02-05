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

unmap:
	rm -f Map/*

gen:
	for i in `seq 1 ${test}` ; do \
		for	j in `seq 1 26` ; do \
			for k in `seq 1 50` ; do \
				./binaire/gen valid $$j > Map/valid_$$j\_$$k; \
				./binaire/gen invalid $$j > Map/invalid_$$j\_$$k; \
			done \
		done \
	done \

parser:
	$(VAR) = `./binaire/parser Map/valid_1_1`
	echo $(VAR)
