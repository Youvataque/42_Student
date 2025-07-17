#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>

class Span {
private:
	Span();
	/////////////////////////////////////////////////////////////////////////// méthodes privées
	std::string		_to_string(double value);
	/////////////////////////////////////////////////////////////////////////// attributs
	unsigned int _maxLen;
	unsigned int _length;
	std::vector<int> _tab;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	Span(unsigned int maxLen);
	Span(const Span& other);
	~Span();

	/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
	Span& operator=(const Span& other);

	/////////////////////////////////////////////////////////////////////////// méthodes
	void			addNumber(int nb);
	void			addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	///////////////////////////////////////////////////////////////////////////// WARNING
	// friend est utilisé dans le cadre d'un bonus visant à rendre la lisibilité du correcteur
	// meilleur. La surcharge ci dessous n'étant pas demandé dans l'exercice, elle ne nécéssite
	// pas sanction :). ps -> je peux justifier ce choix !
	friend std::ostream& operator<<(std::ostream& out, Span& i);

};

#endif