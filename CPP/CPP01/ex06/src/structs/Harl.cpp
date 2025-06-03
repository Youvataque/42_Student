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
	int lvlIndex = -1;

	for (int i = 0; i < 4; i++) {
		if (lvls[i] == lvl) {
			lvlIndex = i;
		}
	}

	switch (lvlIndex) {
		case 0:
			std::cout << "[ DEBUG ]\n"; this->debug();
		case 1:
			std::cout << "[ INFO ]\n"; this->info();
		case 2:
			std::cout << "[ WARNING ]\n"; this->warning();
		case 3:
			std::cout << "[ ERROR ]\n"; this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
};