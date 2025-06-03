#include "Harl.hpp"

// I LIKE WRITE FOR NOTHING !
Harl::Harl() {};
Harl::Harl(const Harl& toCopie) {
	(void)toCopie;
};
Harl& Harl::operator=(const Harl& toCopie) {
	(void)toCopie;
	return *this;
};
Harl::~Harl() {};

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string lvl) {
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*screams[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (lvls[i] == lvl) {
			(this->*screams[i])();
		}
	}
};