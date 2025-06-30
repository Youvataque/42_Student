NAME = AForm
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

SRC = AForm.cpp Bureaucrat.cpp Derived/ShrubberyCreationForm.cpp Derived/RobotomyRequestForm.cpp Derived/PresidentialPardonForm.cpp main.cpp
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