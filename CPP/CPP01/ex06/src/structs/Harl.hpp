#include <string>
#include <iostream>

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl();
	Harl(const Harl& toCopie);
	Harl& operator=(const Harl& toCopie);
	~Harl();
	void complain(std::string lvl);
};