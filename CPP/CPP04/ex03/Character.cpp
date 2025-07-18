#include "Character.hpp"

Character::Character() : name("default"), trashI(0) {
	std::cout << "Character constructor\n";
	for (int i = 0; i < 1000; i++) {
		this->trash[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
};

Character::Character(const std::string& name) : name(name), trashI(0) {
	std::cout << "Character constructor with name\n";
	for (int i = 0; i < 1000; i++) {
		this->trash[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
};

Character::Character(const Character& other) {
	std::cout << "Character copy constructor\n";
	this->name = other.name;
	this->trashI = 0;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	for (int i = 0; i < 1000; i++) {
		this->trash[i] = NULL;
	}
};

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		std::cout << "Character assign constructor\n";
		this->name = other.name;
		this->trashI = 0;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		for (int i = 0; i < 1000; i++) {
			this->trash[i] = NULL;
		}
	}
	return *this;
};

Character::~Character() {
	for (int i = 0; i < 1000; i++) {
		if (this->trash[i] != NULL)
			delete this->trash[i];
	}
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

std::string const & Character::getName() const {
	return this->name;
};

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			std::cout << "equip: materia " << m->getType() << " added in slot x\n";
			this->inventory[i] = m;
			break ;
		}
	}
};

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		if (this->inventory[idx] != NULL) {
			std::cout << "unequip: slot " << idx << " cleared\n";
			this->trash[this->trashI] = this->inventory[idx];
			this->inventory[idx] = NULL;
			this->trashI++;
		}
	}
};

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
		std::cout << "use AMateria on a target !\n";
		this->inventory[idx]->use(target);
	} else {
		std::cout << "can't use AMateria, error !\n";
	}
};