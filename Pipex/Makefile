NAME = pipex
CC = gcc
CFLAGS = 
SRC = src/main.c src/utils.c
OBJ = $(SRC:%.c=obj/%.o)

LIBFT_PATH = MyLibft
LIBFT_FILE = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_FILE) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) -o $(NAME)

$(LIBFT_FILE):
	make -C $(LIBFT_PATH)


clean:
	rm -rf ./obj
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re