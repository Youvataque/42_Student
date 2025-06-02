#include "Zombie.hpp"
#include "iostream"

Zombie::Zombie(): name(""){};

Zombie::Zombie(const std::string name): name(name){};

Zombie::Zombie(const Zombie &toCopie) {
	this->name = toCopie.name;
};

Zombie& Zombie::operator=(const Zombie &toCopie) {
	if (this != &toCopie) {
		this->name = toCopie.name;
	}
	return *this;
};

Zombie::~Zombie() {
	std::cout << this->name
			  << ": will be destroyed !\n";
};

void Zombie::announce() {
	std::cout << this->name
			  << ": BraiiiiiiinnnzzzZ...\n";
};