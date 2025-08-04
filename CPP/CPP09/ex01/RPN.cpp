#include "RPN.hpp"

/////////////////////////////////////////////////////////////////////////// méthodes privées
bool RPN::_isValidChar(char c) {
	return (c <= '9' && c >= '0') || c == '+' || c == '-' || c == '*' || c == '/' || " ";
}

/////////////////////////////////////////////////////////////////////////// constructeur
RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN::~RPN() {}

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
	}
	std::size_t nbSpace = 0;
	std::size_t nbOperand = 0;
	for (std::size_t i = 0; i < arg.size(); i++) {
		char c = arg.at(i);
		if (c == ' ')
			nbSpace++;
		if (c == '+' || c == '-' || c == '/' || c == '*')
			nbOperand++;
	}
	if (arg.size() - nbSpace != nbSpace + 1)
		return false;
	if (arg.size() - nbSpace - nbOperand <= nbOperand)
		return false;
	return true;
}

double	RPN::_selectOp(double nb1, double nb2, char c) {
	switch (c)
	{
		case '+':
			return nb1 + nb2;
		case '-':
			return nb1 - nb2;
		case '/':
			if (nb2 != 0)
				return nb1 / nb2;
			else
				throw std::runtime_error("Division par zéro");
		case '*':
			return nb1 * nb2;
		default:
			throw std::runtime_error("Opérateur invalide");
	}
}

double RPN::calcul(std::string arg) {
	std::deque<double> temp;
	for (std::size_t i = 0; i < arg.size(); i++) {
		if (isdigit(arg.at(i))) {
			temp.push_back(static_cast<double>(arg.at(i) - '0'));
		} else if (arg.at(i) != ' ') {
			if (temp.size() < 2) {
				throw std::runtime_error("Nombre insuffisant d'opérandes");
			}
			double nb2 = *(temp.end() - 1);
			temp.erase(temp.end() - 1);
			double nb1 = *(temp.end() - 1);
			temp.erase(temp.end() - 1);
			double resultat = _selectOp(nb1, nb2, arg.at(i));
			temp.push_back(resultat);
		}
	}
	if (temp.size() != 1) {
		throw std::runtime_error("Nombre incorrect d'opérandes ou d'opérateurs");
	}
	return temp[0];
}
