#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "../Weapon/Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB();
	HumanB(const std::string name);
	HumanB(const HumanB& toCopie);
	HumanB& operator=(const HumanB& toCopie);
	~HumanB();

	void attack(void);
	void setWeapon(Weapon& weapon);
};

#endif