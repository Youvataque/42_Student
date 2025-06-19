#include "ScavTrap.hpp"
#include <iostream>

void printLine(std::string title = "") {
	std::cout << "\n\033[1;34m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
	printLine("Default constructor");
	ScavTrap def;

	printLine("Constructor with name");
	ScavTrap bob("Bob");

	printLine("Copy constructor");
	ScavTrap bobCopy(bob);

	printLine("Assignment operator");
	ScavTrap rob("Rob");
	rob = bob;

	printLine("Testing attack");
	bob.attack("Target 1");

	printLine("Testing takeDamage");
	bob.takeDamage(20);

	printLine("Testing beRepaired");
	bob.beRepaired(10);

	printLine("Testing guardGate");
	bob.guardGate();

	printLine("Deplete energy");
	for (int i = 0; i < 55; ++i) {
		bob.attack("Dummy");
	}

	printLine("Try to attack with 0 energy");
	bob.attack("Still Dummy");

	printLine("Try to be repaired with 0 energy");
	bob.beRepaired(5);

	printLine("Take fatal damage");
	bob.takeDamage(200);

	printLine("Try to do actions while dead");
	bob.attack("Ghost");
	bob.beRepaired(5);
	bob.guardGate();

	printLine("End of main");
	return 0;
}