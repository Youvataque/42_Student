#include "RPN.hpp"

/////////////////////////////////////////////////////////////////////////// méthodes privées
bool RPN::_isValidChar(char c) {
	return (c <= '9' && c >= '0') || c == '+' || c == '-' || c == '*' || c == '/' || " ";
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
		if (!(_isValidChar(arg.at(i)))) {
			return false;
		}

		std::size_t nbSpace = 0;
		for (std::size_t i = 0; i < arg.size(); i++) {
			if (arg.at(i) == ' ')
				nbSpace++;
		}
		if (arg.size() - nbSpace != nbSpace)
			return false;
	}
	return true;
}

double	selectOp(double nb1, double nb2, char c) {
	switch (c)
	{
	case '+':
		return nb1 + nb2;
	case '-':
		return nb1 - nb2;
	case '/':
		return nb1 / nb2;
	case '*':
		return nb1 * nb2;
	default:
		break;
	}
}

double RPN::calcul(std::string arg) {
	(void)arg;
	double result;
	std::vector<double> temp;
	for (std::size_t i = 0; i < arg.size(); i++) {
		if (isdigit(arg.at(i))) {
			temp.push_back(static_cast<double>((arg.at(i))));
		} else if (isalpha(arg.at(i)) && arg.at(i) != ' ') {
			if (!result) {
				result = selectOp(temp[temp.size() - 1], temp[temp.size() - 1], arg.at(i));
				temp.pop_back();
				temp.pop_back();
				temp.push_back(result);
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////// exceptions