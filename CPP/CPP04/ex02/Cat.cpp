#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
};

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		std::cout << "Cat assignment operator called" << std::endl;
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "CAT IS CURIOUS, MEW !\n";
}

Brain& Cat::getBrain() const {
	return *this->brain;
}