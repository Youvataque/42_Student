#include "DiamondTrap.hpp"

/////////////////////////////////////////////////////////////////////////////// constructor

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("User_diam") {
	std::cout << "def constructor diam\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	this->_health = FragTrap::_health;
	this->_stamina = ScavTrap::_stamina;
	this->_dmg = FragTrap::_dmg;
	std::cout << "param constructor diam\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << "copy constructor diam\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		std::cout << "operator constructor diam\n";
		_name = other._name;
		ClapTrap::operator=(other);
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "destructor diam\n";
}

/////////////////////////////////////////////////////////////////////////////// Public

void DiamondTrap::whoAmI() {
	std::cout << "🧠 I am DiamondTrap: " << _name
	          << ", and my ClapTrap name is: " << ClapTrap::getName()
	          << std::endl;
}

void DiamondTrap::attack(std::string& name) {
	ScavTrap::attack(name);
}