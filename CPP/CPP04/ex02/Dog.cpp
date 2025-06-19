#include "Dog.hpp"

Dog::Dog() : Animal(){
	const std::string ideas[100] = {"pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser", "pute", "taper", "manger", "chocholat", "casser" ,"pute", "taper", "manger", "chocholat", "casser"};
	this->type = "Dog";
	this->brain = new Brain(ideas);
	std::cout << "Dog default constructor called" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "DOG IS ANGRY, WOUF !\n";
}

Brain& Dog::getBrain() const {
	return *this->brain;
}