NAME = pipex
NAME_BONUS = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./libft

SRCS = 	pipex.c\
		utils.c\
		utils2.c\

SRCS_BONUS = ./bonus/pipex_bonus.c\
			 ./bonus/utils_bonus.c\

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft
		gcc $(OBJ) ./libft/libft.a $(CFLAGS) -o $(NAME)

bonus: $(OBJ_BONUS)
		make -C ./libft
		gcc $(OBJ_BONUS) ./libft/libft.a $(CFLAGS) -o $(NAME_BONUS)
clean:
	make clean -C ./libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
