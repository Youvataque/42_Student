#include "DiamondTrap.hpp"
#include <iostream>

void printLine(std::string title = "") {
	std::cout << "\n\033[1;35m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
	printLine("Default constructor");
	DiamondTrap def;

	printLine("Constructor with name");
	DiamondTrap jean("Jean");

	printLine("Copy constructor");
	DiamondTrap jeanCopy(jean);

	printLine("Assignment operator");
	DiamondTrap dup("Dup");
	dup = jean;

	printLine("Testing attack");
	jean.attack("Target");

	printLine("Testing takeDamage");
	jean.takeDamage(40);

	printLine("Testing beRepaired");
	jean.beRepaired(20);

	printLine("Testing whoAmI()");
	jean.whoAmI();

	printLine("Testing whoAmI() after death");
	jean.takeDamage(500); // Mort
	jean.whoAmI();

	printLine("Testing no energy case");
	DiamondTrap empty("Empty");
	for (int i = 0; i < 50; ++i)
		empty.attack("Wall");
	empty.attack("Ghost");
	empty.beRepaired(5);
	empty.whoAmI();

	printLine("Final destruction of all objects");
	return 0;
}