#include <string>
#include <iostream>

int main() {
	std::string var = "HI THIS IS BRAIN";
	std::string* stringPTR = &var;
	std::string& stringREF = var;
	std::cout << "Adresse de var      : " << &var << std::endl;
	std::cout << "Adresse via pointer : " << stringPTR << std::endl;
	std::cout << "Adresse via ref     : " << &stringREF << std::endl;

	std::cout << "Valeur via var      : " << var << std::endl;
	std::cout << "Valeur via pointer  : " << *stringPTR << std::endl;
	std::cout << "Valeur via ref      : " << stringREF << std::endl;
}