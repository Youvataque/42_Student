#include "HumanB.hpp"

HumanB::HumanB() : name("") {};

HumanB::HumanB(std::string name) : name(name) {};

HumanB::HumanB(const HumanB& toCopie) : name(toCopie.name), weapon(toCopie.weapon) {};

HumanB& HumanB::operator=(const HumanB& toCopie) {
	if (this != &toCopie) {
		this->name = toCopie.name;
		this->weapon = toCopie.weapon;
	}
	return *this;
};

HumanB::~HumanB() {};

void HumanB::attack() {
	if (weapon != NULL) {
		std::cout << this->name
				  << " attacks with their "
				  << (*this->weapon).getType()
			  	  << std::endl;
	}
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
