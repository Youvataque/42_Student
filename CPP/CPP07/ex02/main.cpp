#include "Array.hpp"
#include <iostream>
#include <string>

void printTitle(const std::string& title) {
	std::cout << "\033[1;35m\n=== " << title << " ===\033[0m\n";
}

int main() {
	printTitle("CREATION VIDE");
	Array<int> empty;
	std::cout << "empty.size(): " << empty.size() << std::endl;

	printTitle("CREATION INT AVEC N");
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i * 10;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	printTitle("COPIE CONSTRUCTEUR");
	Array<int> b(a);
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	printTitle("OPERATEUR D'AFFECTATION");
	Array<int> c;
	c = a;
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	printTitle("MODIFICATION DU TABLEAU COPIE");
	b[0] = 999;
	std::cout << "b[0] = " << b[0] << std::endl;
	std::cout << "a[0] = " << a[0] << " (doit rester inchangé)" << std::endl;

	printTitle("TABLEAU DE STRINGS");
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "!";
	for (unsigned int i = 0; i < strArr.size(); ++i)
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;

	printTitle("TEST EXCEPTION OUT OF RANGE");
	try {
		std::cout << a[42] << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception attrapée: " << e.what() << std::endl;
	}

	return 0;
}