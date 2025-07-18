#include "Cure.hpp"

Cure::Cure() : AMateria() {
	this->type = "cure";
};

Cure::Cure(std::string& type) : AMateria(type) {};

Cure::Cure(const Cure& other) : AMateria(other) {};

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
};

Cure::~Cure() {};

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
};