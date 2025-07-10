#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <limits>

class Span {
private:
	Span();
	/////////////////////////////////////////////////////////////////////////// méthodes privées
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

	/////////////////////////////////////////////////////////////////////////// exceptions
	
	friend std::ostream& operator<<(std::ostream& out, Span& i);

};

#endif