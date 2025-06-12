#include "DiamondTrap.hpp"

int main() {
	std::cout << "\n=== CONSTRUCTION ===\n";
	DiamondTrap d1("Yannis");
	DiamondTrap d2("Mayleen");

	std::cout << "\n=== ACTIONS DE BASE ===\n";
	d1.attack("Training Dummy");
	d1.takeDamage(20);
	d1.beRepaired(15);

	std::cout << "\n=== WHO AM I ? ===\n";
	d1.whoAmI();
	d2.whoAmI();

	std::cout << "\n=== MÉTHODES HÉRITÉES ===\n";
	d1.guardGate();        // méthode de ScavTrap
	d2.highFivesGuys();    // méthode de FragTrap

	std::cout << "\n=== TEST COPIE / AFFECTATION ===\n";
	DiamondTrap d3(d1);    // copy constructor
	DiamondTrap d4;
	d4 = d2;               // assignment operator

	d3.whoAmI();
	d4.whoAmI();

	std::cout << "\n=== ATTAQUE EN BOUCLE ===\n";
	for (int i = 0; i < 55; ++i) {
		d1.attack("Target X");
	}

	std::cout << "\n=== DESTRUCTORS ===\n";
	return 0;
}