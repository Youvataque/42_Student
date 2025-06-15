#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
	std::string name;
	AMateria* inventory[4];
	AMateria* trash[1000];
	int	trashI;

public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif