#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	Animal* tab[10];
	for(int i = 0; i < 5; i++) {
		tab[i] = new Dog();
	}
	for(int i = 5; i < 10; i++) {
		tab[i] = new Cat();
	}
	for(int i = 0; i < 5; i++) {
		tab[i]->makeSound();
		if (Dog* dog = dynamic_cast<Dog*>(tab[i])) {
			dog->makeSound();
			std::cout << dog->getBrain().getIdea(3) << std::endl;
		}
	}
	for(int i = 5; i < 10; i++) {
		tab[i]->makeSound();
		if (Cat* cat = dynamic_cast<Cat*>(tab[i])) {
			cat->makeSound();
			std::cout << cat->getBrain().getIdea(3) << std::endl;
		}
	}
	for (int i = 0; i < 10; i++) {
		delete tab[i];
	} 
}