#include "Ice.hpp"

Ice::Ice() : AMateria() {
	this->type = "ice";
};

Ice::Ice(std::string& type) : AMateria(type) {};

Ice::Ice(const Ice& other) : AMateria(other) {};

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
};

Ice::~Ice() {};

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
};