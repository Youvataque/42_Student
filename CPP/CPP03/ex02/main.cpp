#include "FragTrap.hpp"

int main() {
	std::cout << "\n=== CONSTRUCTION ===\n\n";

	FragTrap frag1("Fraggy");
	FragTrap frag2("TankBoy");

	std::cout << "\n=== ACTIONS DE BASE ===\n\n";

	frag1.attack("DummyBot");
	frag2.takeDamage(25);
	frag2.beRepaired(15);

	std::cout << "\n=== CAPACITÉ SPÉCIALE ===\n\n";

	frag1.highFivesGuys();
	frag2.highFivesGuys();

	std::cout << "\n=== TEST DE COPIE & AFFECATION ===\n\n";

	FragTrap cloneFrag(frag1);       
	FragTrap assignedFrag;           
	assignedFrag = frag2;              

	std::cout << "\n=== BOUCLE D’ATTAQUE ===\n\n";

	for (int i = 0; i < 5; ++i) {
		frag1.attack("TargetX");
	}

	std::cout << "\n=== ÉNERGIE ÉPUISÉE ? ===\n\n";

	for (int i = 0; i < 100; ++i) {
		frag1.attack("LastTarget");
	}

	std::cout << "\n=== DESTRUCTION AUTOMATIQUE ===\n\n";

	return 0;
}