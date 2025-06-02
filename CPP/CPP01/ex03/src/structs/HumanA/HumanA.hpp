#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "../Weapon/Weapon.hpp"
class HumanA {
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(const std::string name, Weapon& weapon);
	HumanA(const HumanA& toCopie);
	HumanA& operator=(const HumanA& toCopie);
	~HumanA();

	void attack(void);
};

#endif