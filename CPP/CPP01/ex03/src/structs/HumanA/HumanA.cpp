#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {};

HumanA::HumanA(const HumanA& toCopie) : name(toCopie.name), weapon(toCopie.weapon) {};

HumanA& HumanA::operator=(const HumanA& toCopie) {
	if (this != &toCopie) {
		this->name = toCopie.name;
		this->weapon = toCopie.weapon;
	}
	return *this;
};

HumanA::~HumanA() {};

void HumanA::attack() {
	std::cout << this->name
			  << " attacks with their "
			  << this->weapon.getType()
			  << std::endl;
}