#include "RPN.hpp"

/////////////////////////////////////////////////////////////////////////// méthodes privées
bool RPN::_isValidChar(char c) {
	return (c <= '9' && c >= '0') || c == '+' || c == '-' || c == '*' || c == '/';
}
/////////////////////////////////////////////////////////////////////////// constructeur
RPN::RPN() {
	// default constructor
}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN::~RPN() {
	// destructor
}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

/////////////////////////////////////////////////////////////////////////// getter / setter

/////////////////////////////////////////////////////////////////////////// méthodes
bool RPN::checkFormat(std::string arg) {
	for (std::size_t i = 0; i < arg.size(); i++) {
		if (!(_isValidChar(arg.at(i)) || arg.at(i) == ' ')) {
			return false;
		}

	}
	return true;
}

double RPN::calcul(std::string arg) {
	(void)arg;
	return 1;
}
/////////////////////////////////////////////////////////////////////////// exceptions