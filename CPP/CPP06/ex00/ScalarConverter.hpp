#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cstdlib>

class ScalarConverter {
private:
	/////////////////////////////////////////////////////////////////////////// constructeur
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
	ScalarConverter& operator=(const ScalarConverter& other);

	/////////////////////////////////////////////////////////////////////////// méthodes privées
	static std::string 	charValue(std::string literal);
	static std::string	intValue(std::string literal);
	static std::string 	floatValue(std::string literal);
	static std::string	doubleValue(std::string literal);
	static bool 		isChar(const std::string& literal);
	static bool			isInt(const std::string& literal);
	static bool			isFloat(const std::string& literal);
	static bool 		isDouble(const std::string& literal);
	static bool			isnan(double x);
	static bool			isinf(double x);
	static std::string	_to_string(double value);
	static std::string	_fixDot(std::string nb);
	static bool 		_checkStart(const std::string& str);

public:
	/////////////////////////////////////////////////////////////////////////// méthodes
	static void convert(const std::string& literal);
};

#endif