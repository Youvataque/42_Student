NAME = philo
CC = gcc
CFLAGS = 
SRC = src/main.c src/utils.c src/philo_act.c src/philo_act2.c
OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(LIBFT_FILE) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf ./obj

fclean: clean
	rm -f $(NAME)

re: fclean all

obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re