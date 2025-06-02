#include "string"

class Zombie {

private:
	std::string name;
public:
	Zombie();
	Zombie(const std::string name);
	Zombie(const Zombie &toCopie);
	Zombie &operator=(const Zombie &toCopie);
	~Zombie();

	void announce(void);
	void setName(std::string name);
}; 