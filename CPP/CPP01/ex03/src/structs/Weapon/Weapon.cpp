#include "Weapon.hpp"

Weapon::Weapon() : type(""){};

Weapon::Weapon(std::string type) : type(type){};

Weapon::Weapon(const Weapon& toCopie) {
	this->type = toCopie.type;
};

Weapon& Weapon::operator=(const Weapon& toCopie) {
	if (this != &toCopie) {
		this->type = toCopie.type;
	}
	return *this;
};

Weapon::~Weapon() {};

const std::string& Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}