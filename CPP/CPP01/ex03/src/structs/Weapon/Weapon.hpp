#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;
public:
	Weapon();
	Weapon(const std::string type);
	Weapon(const Weapon& toCopie);
	Weapon& operator=(const Weapon& toCopie);
	~Weapon();

	const std::string& getType(void);
	void setType(std::string newType);
};

#endif