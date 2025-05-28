#include <iostream>
#include <cctype>

int main(int ac, char **av) {
	int i = 1;
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (i < ac) {
		for (int x = 0; av[i][x]; x++) {
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][x])));
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}