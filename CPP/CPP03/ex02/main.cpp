#include "FragTrap.hpp"
#include <iostream>

void printLine(std::string title = "") {
	std::cout << "\n\033[1;36m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
	printLine("Default constructor");
	FragTrap def;

	printLine("Constructor with name");
	FragTrap alice("Alice");

	printLine("Copy constructor");
	FragTrap aliceCopy(alice);

	printLine("Assignment operator");
	FragTrap bob("Bob");
	bob = alice;

	printLine("Testing attack");
	alice.attack("Bob");

	printLine("Testing takeDamage");
	bob.takeDamage(30);

	printLine("Testing beRepaired");
	bob.beRepaired(20);

	printLine("Testing highFivesGuys (normal case)");
	alice.highFivesGuys();

	printLine("Testing highFivesGuys (dead)");
	bob.takeDamage(200);
	bob.highFivesGuys();

	printLine("Testing highFivesGuys (no energy)");
FragTrap exhausted("Tired");
	for (int i = 0; i < 100; ++i)
		exhausted.attack("Nobody");

	exhausted.highFivesGuys();

	printLine("Testing beRepaired (no energy)");
	exhausted.beRepaired(5);

	printLine("Testing attack (no energy)");
	exhausted.attack("Ghost");

	printLine("Final destruction of all objects");
	return 0;
}