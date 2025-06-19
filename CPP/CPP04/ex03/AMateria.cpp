#include "AMateria.hpp"

AMateria::AMateria() : type("null") {};

AMateria::AMateria(const std::string& type) : type(type) {};

AMateria::AMateria(const AMateria& other) : type(other.type) {};

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

AMateria::~AMateria() {
	std::cout << "AMateria (" << this->type << ") destroyed\n";
};

const std::string& AMateria::getType() const {
	return this->type;
};

void AMateria::use(ICharacter& target) {
	std::cout << "* do something to" << target.getName() << std::endl;
};