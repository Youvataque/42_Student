NAME = fixed3
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIRS = src/ src/structs/
OBJ_DIR = obj

SRC = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all