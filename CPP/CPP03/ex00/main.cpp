#include "ClapTrap.hpp"

int main() {
	ClapTrap yannis = ClapTrap("Yannis");
	ClapTrap mayleen = ClapTrap("Mayleen");

	std::cout << "step 1\n\n";
	yannis.attack(mayleen.getName());
	mayleen.takeDamage(5);
	std::cout << "step 2\n\n";
	mayleen.beRepaired(5);
	std::cout << "step 3\n\n";
	yannis.attack(mayleen.getName());
	mayleen.takeDamage(5);
	std::cout << "step 4\n\n";
	yannis.attack(mayleen.getName());
	mayleen.takeDamage(5);
	std::cout << "step 5\n\n";
	yannis.attack(mayleen.getName());
	mayleen.takeDamage(5);
	std::cout << "step 6\n\n";
	mayleen.beRepaired(5);
}