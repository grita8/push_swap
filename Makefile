NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ilibft/includes

SRC = main.c push.c reverse.c rotate.c sorting5.c swap.c helper.c sort.c utils.c helper1.c check.c utils2.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all