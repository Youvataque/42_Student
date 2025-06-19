#include "FragTrap.hpp"

/////////////////////////////////////////////////////////////////////////////// constructor

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "def constructor frag\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_health = 100;
	this->_stamina = 100;
	this->_dmg = 30;
	std::cout << "param constructor frag\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "copy constructor frag\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		std::cout << "operator constructor frag\n";
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "destructor frag\n";
}

/////////////////////////////////////////////////////////////////////////////// Public

void FragTrap::highFivesGuys() {
	if (this->_health <= 0)
		std::cout << "FragTrap " << this->_name << " is dead and can't high five anyone 😵‍💫" << std::endl;
	else if (this->_stamina <= 0)
		std::cout << "FragTrap " << this->_name << " is too tired to high five... 💤" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " throws a BIG HIGH FIVE ✋😎" << std::endl;
}