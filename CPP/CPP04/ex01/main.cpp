#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void printLine(const std::string& title) {
	std::cout << "\n\033[1;33m=== " << title << " ===\033[0m\n" << std::endl;
}

void test() {
	Dog dog;
	Dog temp;
	temp = dog;
}

int main() {
	printLine("Test de destruction préliminaire");
	test();
	printLine("Création d'un tableau d'Animal*");

	const int size = 6;
	Animal* animals[size];

	for (int i = 0; i < size; ++i) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	printLine("Appel de makeSound()");
	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();

	printLine("Suppression des animaux");
	for (int i = 0; i < size; ++i)
		delete animals[i];

	printLine("Test de copie profonde (Dog)");
	Dog original;
	Dog copy(original); // Copy constructor

	printLine("Test de copie profonde (Cat)");
	Cat originalCat;
	Cat copyCat(originalCat); // Copy constructor

	printLine("Fin du programme ex01");
	return 0;
}