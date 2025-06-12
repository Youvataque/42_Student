#include "ScavTrap.hpp"

/////////////////////////////////////////////////////////////////////////////// constructor

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "def constructor scav\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_health = 100;
	this->_stamina = 50;
	this->_dmg = 20;
	std::cout << "param constructor scav\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "copy constructor scav\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		std::cout << "operator constructor scav\n";
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "destructor scav\n";
}

/////////////////////////////////////////////////////////////////////////////// Public

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " has entered Gate keeper mode.\n";
}