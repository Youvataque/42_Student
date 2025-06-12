#include "ClapTrap.hpp"

/////////////////////////////////////////////////////////////////////////////// Private

const std::string ClapTrap::_errorMes = "Nooo, not enough stamina !!\n";

void ClapTrap::_reduceStam(void) {
	this->_stamina--;
}

/////////////////////////////////////////////////////////////////////////////// constructor


ClapTrap::ClapTrap() : _name("User"), _health(10), _stamina(10),  _dmg(0) {
	std::cout << "def constructor\n";
};

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _stamina(10),  _dmg(5) {
	std::cout << "param constructor\n";
};

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _health(other._health), _stamina(other._stamina),  _dmg(other._dmg) {
	std::cout << "copy constructor\n";
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		std::cout << "operator constructor\n";
		this->_name = other._name;
		this->_health = other._health;
		this->_stamina = other._stamina;
		this->_dmg = other._dmg;
	}
	return *this;
};

ClapTrap::~ClapTrap() {
	std::cout << "destructor\n";
};

/////////////////////////////////////////////////////////////////////////////// Public

std::string ClapTrap::getName(void) {
	return this->_name;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_stamina >= 1) {
		std::cout << "ClapTrap " << this->_name <<  " attacks " << target <<", causing " << this->_dmg << " points of damage!\n";
		this->_reduceStam();
	} else {
		std::cout << this->_errorMes;
	}
};

void ClapTrap::takeDamage(unsigned int amount) {
		if (this->_health >= 1) {
			std::cout << "ClapTrap " << this->_name <<  " take  " << amount << " points of damage !\n";
			this->_health -= amount;
		} else {
			std::cout << "Already dead, you can stop hit ;)\n";
		}
	};

void ClapTrap::beRepaired(unsigned int amount) {
		if (this->_stamina >= 1) {
			if (this->_health == 0) {
				std::cout << "ClapTrap " << this->_name << " you can't heal something who's already dead :/\n";
			} else {
				std::cout << "ClapTrap " << this->_name <<  " gain  " << amount << " health points !\n";
				this->_health += amount;
				this->_reduceStam();
			}
		} else {
			std::cout << this->_errorMes;
		}
	};