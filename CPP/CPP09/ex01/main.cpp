#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: bad args !\n";
		return 1;
	}
	std::string arg = av[1];
	if (!RPN::checkFormat(arg)) {
		std::cerr << "Erreur: bad string !\n";
		return 1;
	}
	
}