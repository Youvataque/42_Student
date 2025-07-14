#include "ScalarConverter.hpp"


/////////////////////////////////////////////////////////////////////////// constructeur
ScalarConverter::ScalarConverter() {
	// default constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter::~ScalarConverter() {
	// destructor
}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

/////////////////////////////////////////////////////////////////////////// méthodes privées (checkers)
std::string ScalarConverter::_to_string(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

bool ScalarConverter::isChar(const std::string& literal) {
	return literal.length() == 3 && 
	       literal[0] == '\'' && 
	       literal[literal.length() - 1] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal) {
	char* end;
	long val = strtol(literal.c_str(), &end, 10);
	return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}

bool ScalarConverter::isFloat(const std::string& literal) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (literal[literal.length() - 1] == 'f' && literal[0] >= '0' && literal[0] <= '9')
		return true;
	return false;
}

bool ScalarConverter::isDouble(const std::string& literal) {
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (literal.find('.') != std::string::npos)
		return true;
	return false;
}

bool isnan(double x) { return x != x; }
bool isinf(double x) { return !isnan(x) && isnan(x - x); }

/////////////////////////////////////////////////////////////////////////// méthodes privées (printers)
std::string ScalarConverter::charValue(std::string literal) {
	std::string result;
	try {
		if (isChar(literal)) {
			result =  std::string(1, literal[1]);
		} else if (isInt(literal)) {
			result = std::string(1, static_cast<char>(std::strtol(literal.c_str(), NULL, 10)));
		} else if (isFloat(literal)) {
			float f = atof(literal.c_str());
			if (isnan(f) || isinf(f))
				return "impossible";
			result = std::string(1, static_cast<char>(f));
		} else if (isDouble(literal)) {
			double d = atof(literal.c_str());
			if (isnan(d) || isinf(d))
				return "impossible";
			result = std::string(1, static_cast<char>(d));
		} else {
			result = "Impossible";
		}

		if (result == "Impossible")
			return result;
		if (std::isprint(result[0])) {
			return "'" + result + "'";
		}
		return "Non displayable";
	} catch (const std::exception&) {
		return "impossible";
	}
}

std::string ScalarConverter::intValue(std::string literal) {
	std::ostringstream oss;

	if (isChar(literal)) {
		oss << std::fixed << std::setprecision(0) << static_cast<int>(literal[1]);
	} else if (isInt(literal)) {
		oss << std::fixed << std::setprecision(0) << static_cast<int>(strtol(literal.c_str(), NULL, 10));
	} else if (isFloat(literal)) {
		float f = strtof(literal.c_str(), NULL);
		if (isnan(f) || isinf(f)) return "impossible";
		oss << std::fixed << std::setprecision(0) << static_cast<int>(f);
	} else if (isDouble(literal)) {
		double d = strtod(literal.c_str(), NULL);
		if (isnan(d) || isinf(d)) return "impossible";
		oss << std::fixed << std::setprecision(0) << static_cast<int>(d);
	} else {
		return "Impossible";
	}
	return oss.str();
}

std::string ScalarConverter::floatValue(std::string literal) {
	std::ostringstream result;
	try {
		if (isChar(literal)) {
			result << std::fixed << std::setprecision(1) << static_cast<float>(literal[1]);
		} else if (isInt(literal)) {
			long intVal = strtol(literal.c_str(), NULL, 10);
			float f = static_cast<float>(intVal);
			if (static_cast<long>(f) != intVal)
				return "impossible";
			result << std::fixed << std::setprecision(1) << f;
		} else if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
			return literal;
		} else if (isFloat(literal)) {
			float f = static_cast<float>(atof(literal.c_str()));
			result << std::fixed << std::setprecision(1) << f;
		} else if (isDouble(literal)) {
			float f = static_cast<float>(atof(literal.c_str()));
			result << std::fixed << std::setprecision(1) << f;
		} else {
			return "Impossible";
		}
		if (result.str()[result.str().length() - 1] != 'f')
			result << "f";
		return result.str();
	} catch (const std::exception&) {
		return "impossible";
	}
}

std::string ScalarConverter::doubleValue(std::string literal) {
	std::ostringstream result;
	try {
		if (isChar(literal)) {
			result << std::fixed << std::setprecision(1) << static_cast<double>(literal[1]);
		} else if (isInt(literal)) {
			result << std::fixed << std::setprecision(1) << static_cast<double>(strtol(literal.c_str(), NULL, 10));
		} else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
			return literal;
		} else if (isFloat(literal)) {
			double d = static_cast<double>(atof(literal.c_str()));
			result << std::fixed << std::setprecision(1) << d;
		} else if (isDouble(literal)) {
			double d = atof(literal.c_str());
			result << std::fixed << std::setprecision(1) << d;
		} else {
			return "Impossible";
		}
		return result.str();
	} catch (const std::exception&) {
		return "impossible";
	}
}

/////////////////////////////////////////////////////////////////////////// méthodes
void ScalarConverter::convert(const std::string& literal) {
	try {
		std::cout << "char: " << charValue(literal) << std::endl;
		std::cout << "int: " << intValue(literal) << std::endl;
		std::cout << "float: " << floatValue(literal) << std::endl;
		std::cout << "double: " << doubleValue(literal) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}