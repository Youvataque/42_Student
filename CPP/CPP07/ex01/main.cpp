#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(const int& n) {
	std::cout << "Const print int: " << n << std::endl;
}

void printDouble(const double& n) {
	std::cout << "Const print int: " << n << std::endl;
}

void incrementInt(int& n) {
	n++;
}

void printString(const std::string& str) {
	std::cout << "String: " << str << std::endl;
}

void toUpper(std::string& str) {
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

void printTitle(const std::string& title) {
	std::cout << "\033[1;36m" // gras cyan
			  << "\n=== " << title << " ===\n"
			  << "\033[0m";
}



int main() {
	printTitle("INT ARRAY");
	int intTab[] = {1, 2, 3, 4, 5};
	iter(intTab, 5, printInt);
	iter(intTab, 5, incrementInt);
	iter(intTab, 5, printInt);

	printTitle("STRING ARRAY");
	std::string strTab[] = {"hello", "world", "42"};
	iter(strTab, 3, printString);
	iter(strTab, 3, toUpper);
	iter(strTab, 3, printString);

	printTitle("DOUBLE ARRAY (TEMPLATE FUNC)");
	double dtab[] = {1.1, 2.2, 3.3};
	iter(dtab, 3, printDouble);

	return 0;
}