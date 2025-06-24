#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void printLine(std::string title) {
	std::cout << "\n\033[1;32m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
	printLine("Instanciations");

	const Animal* a = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* cat2 = new WrongCat();

	printLine("Type check");
	std::cout << "Animal: " << a->getType() << std::endl;
	std::cout << "Dog: " << dog->getType() << std::endl;
	std::cout << "Cat: " << cat->getType() << std::endl;

	printLine("Make sounds");
	a->makeSound();    // Should call Animal::makeSound()
	dog->makeSound();  // Should call Animal::makeSound() too (BUG)
	cat->makeSound();  // Should call Animal::makeSound() too (BUG)
	cat2->makeSound();

	printLine("Destruction");
	delete a;
	delete dog;
	delete cat;
	delete cat2;

	return 0;
}