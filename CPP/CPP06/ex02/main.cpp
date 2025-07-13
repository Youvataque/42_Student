#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

std::string to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

Base* generate(void) {
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception error) {
		(void)error;
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (std::exception error) {
			(void)error;
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (std::exception error) {
				(void)error;
			}
		}
	}
}

void printline(const std::string& title) {
	std::cout << "\033[1;36m" << title << "\033[0m" << std::endl;
}

int main() {
	printline("TEST DYNAMIC CAST IDENTIFICATION");

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 10; ++i) {
		printline("Test #" + to_string(i + 1));

		Base* random = generate();

		std::cout << "[*] Pointer address : " << random << std::endl;

		std::cout << "[>] identify(Base*)  : ";
		identify(random);

		std::cout << "[>] identify(Base&)  : ";
		identify(*random);

		delete random;
	}

	printline("END OF TESTS");
	return 0;
}