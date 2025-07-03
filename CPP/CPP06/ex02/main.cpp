#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

void printline(const std::string& title) {
	std::cout << "\033[1;36m" << title << "\033[0m" << std::endl;
}
int main() {
	printline("TEST DYNAMIC CAST IDENTIFICATION");

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 10; ++i) {
		printline("Test #" + std::to_string(i + 1));

		Base* random = Base::generate();

		std::cout << "[*] Pointer address : " << random << std::endl;

		std::cout << "[>] identify(Base*)  : ";
		Base::identify(random);

		std::cout << "[>] identify(Base&)  : ";
		Base::identify(*random);

		delete random;
	}

	printline("END OF TESTS");
	return 0;
}