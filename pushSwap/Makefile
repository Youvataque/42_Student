NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c tools/s_tools.c tools/p_tools.c tools/r_tools.c tools/rr_tools.c sorts/sort_two_select.c sorts/monotone_sort.c sorts/quartile_sort.c sorts/sorts_utils.c sorts/quick_sorts.c sorts/sort_utils2.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re