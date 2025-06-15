#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	std::cout << "=== Création de la source de materia ===\n";
	IMateriaSource* src = new MateriaSource();

	std::cout << "=== Apprentissage de Ice et Cure ===\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "=== Création du personnage 'me' ===\n";
	ICharacter* me = new Character("me");

	std::cout << "=== Création de 2 materia depuis la source ===\n";
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");

	std::cout << "=== Équipement de ces 2 materia ===\n";
	me->equip(tmp1);
	me->equip(tmp2);

	std::cout << "=== Création du personnage cible 'bob' ===\n";
	ICharacter* bob = new Character("bob");

	std::cout << "=== Utilisation des materia ===\n";
	me->use(0, *bob); // ice
	me->use(1, *bob); // cure

	std::cout << "=== Test d’index invalide ===\n";
	me->use(4, *bob);
	me->use(-1, *bob);

	std::cout << "=== Unequip de l’index 1 (cure) ===\n";
	me->unequip(1);
	me->use(1, *bob);  // rien ne se passe

	std::cout << "=== Test de clone indirect ===\n";
	AMateria* cloned = tmp1->clone();
	std::cout << "Clone de ice : " << cloned->getType() << std::endl;

	std::cout << "=== Test du constructeur de copie ===\n";
	Character copy1(*(Character*)me);
	copy1.use(0, *bob);  // ice doit marcher
	copy1.use(1, *bob);  // rien (slot 1 est vide chez 'me')

	std::cout << "=== Test de l’opérateur d’affectation ===\n";
	Character copy2("copy2");
	copy2 = *(Character*)me;
	copy2.use(0, *bob);

	std::cout << "=== Libération mémoire ===\n";
	delete src;
	delete me;
	delete bob;
	delete cloned;

	return 0;
}