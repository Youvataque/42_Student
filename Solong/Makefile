NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/main.c
OBJ = $(SRC:%.c=obj/%.o)

LIBFT_PATH = MyLibft
LIBFT_FILE = $(LIBFT_PATH)/libft.a
MLX_PATH = minilibx-linux
MLX_FILE = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L/usr/X11R6/lib -lX11 -lXext

all: $(NAME)

$(NAME): $(LIBFT_FILE) $(OBJ)
	make -C minilibx-linux/
		$(CC) $(CFLAGS) $(OBJ) $(MLX_FILE) $(MLX_FLAGS) $(LIBFT_FILE) -o $(NAME)

$(LIBFT_FILE):
	make -C $(LIBFT_PATH)

$(MLX_FILE):
	make -C $(MLX_PATH)

clean:
	rm -rf ./obj
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re