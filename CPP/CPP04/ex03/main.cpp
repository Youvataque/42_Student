#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void printLine(const std::string& title) {
	std::cout << "\n\033[1;36m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
	printLine("Créer une source de matéria");
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Ce 5e apprentissage ne doit rien faire (slots pleins)
	src->learnMateria(new Ice());

	printLine("Créer un personnage");
	ICharacter* me = new Character("me");

	printLine("Créer des matéria et les équiper");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Cette matéria ne sera pas équipée (inventaire plein)
	tmp = src->createMateria("ice");
	me->equip(tmp); // ne doit rien faire

	printLine("Créer une cible : bob");
	ICharacter* bob = new Character("bob");

	printLine("Utiliser les matérias");
	me->use(0, *bob); // ice
	me->use(1, *bob); // cure
	me->use(2, *bob); // ice
	me->use(3, *bob); // cure

	printLine("Tester index invalide");
	me->use(4, *bob); // rien
	me->use(-1, *bob); // rien

	printLine("Unequip un slot et test");
	// On récupère le pointeur pour delete à la main
	AMateria* toDelete = src->createMateria("ice");
	me->equip(toDelete);
	me->unequip(1); // On enlève l'ancien cure

	delete toDelete; // Important !

	printLine("Utiliser un slot unequipé");
	me->use(1, *bob); // ne doit rien faire

	printLine("Deep copy de personnage");
	Character* original = new Character("original");
	original->equip(src->createMateria("cure"));

	Character* clone = new Character(*original); // copy constructor

	printLine("Test d'utilisation clone et original");
	original->use(0, *clone);
	clone->use(0, *original);

	printLine("Nettoyage");
	delete me;
	delete bob;
	delete src;
	delete original;
	delete clone;

	printLine("Fin du programme ex03");
	return 0;
}