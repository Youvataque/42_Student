#include "ScalarConverter.hpp"
#include <iostream>

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void printline(const std::string& title) {
	std::cout << "\033[1;36m" << title << "\033[0m" << std::endl;
}

// int main() {
// 	printline("=== INT ===");
// 	ScalarConverter::convert("0");
// 	ScalarConverter::convert("42");
// 	ScalarConverter::convert("-2147483648");
// 	ScalarConverter::convert("2147483647");
// 	std::cout << std::endl;

// 	printline("=== FLOAT ===");
// 	ScalarConverter::convert("42.0f");
// 	ScalarConverter::convert("3.14f");
// 	ScalarConverter::convert("-0.0f");
// 	ScalarConverter::convert("+inff");
// 	ScalarConverter::convert("-inff");
// 	ScalarConverter::convert("nanf");
// 	std::cout << std::endl;

// 	printline("=== DOUBLE ===");
// 	ScalarConverter::convert("42.0");
// 	ScalarConverter::convert("3.14");
// 	ScalarConverter::convert("+inf");
// 	ScalarConverter::convert("-inf");
// 	ScalarConverter::convert("nan");
// 	std::cout << std::endl;

// 	printline("=== CHAR ===");
// 	ScalarConverter::convert("'a'");
// 	ScalarConverter::convert("'0'");
// 	ScalarConverter::convert("'\\n'");
// 	std::cout << std::endl;

// 	printline("=== INVALID ===");
// 	ScalarConverter::convert("coucou");
// 	ScalarConverter::convert("42n");
// 	ScalarConverter::convert("nanfffff");
// 	ScalarConverter::convert("2147483648");  // overflow int
// 	std::cout << std::endl;

// 	return 0;
// }

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}