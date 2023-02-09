NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./libft

SRCS = 	pipex.c\
		utils.c\
		utils2.c\


OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft
		gcc $(OBJ) ./libft/libft.a $(CFLAGS) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
