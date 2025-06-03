#include "structs/Harl.hpp"

int main(int ac, char **av) {
	Harl harl2 = Harl();
	if (ac == 2)
		harl2.complain(av[1]);
	else	
		std::cout << "Error, need one arguments, not less not more !\n";
}