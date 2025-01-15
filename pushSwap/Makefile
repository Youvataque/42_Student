NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c utils.c tools/s_tools.c tools/p_tools.c tools/r_tools.c tools/rr_tools.c sorts/sort_two_three.c sorts/quartile_sort.c sorts/sorts_utils.c sorts/quick_sorts.c sorts/sort_utils2.c sorts/quartile_calculate.c sorts/quartile_operand.c
OBJ = $(SRC:%.c=obj/%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf ./obj
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
