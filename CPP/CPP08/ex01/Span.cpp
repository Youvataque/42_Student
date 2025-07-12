#include "Span.hpp"

/////////////////////////////////////////////////////////////////////////// méthodes privées

/////////////////////////////////////////////////////////////////////////// constructeur
Span::Span() {
	std::cout << "Ne devrait jamais être appelé\n";
}

Span::Span(unsigned int maxLen): _maxLen(maxLen), _length(0) {}

Span::Span(const Span& other): _maxLen(other._maxLen), _length(other._length), _tab(other._tab) {}

Span::~Span() {
	std::cout << "destructor span\n";
}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_maxLen = other._maxLen;
		this->_length = other._length;
		this->_tab = other._tab;
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////// getter / setter

/////////////////////////////////////////////////////////////////////////// méthodes
void			Span::addNumber(int nb) {
	if (this->_length < this->_maxLen) {
		this->_tab.push_back(nb);
		this->_length++;
	} else {
		throw std::out_of_range("Erreur: cette liste est pleine !" + std::to_string(nb));
	}
}

void			Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::size_t len = static_cast<std::size_t>(std::distance(begin, end));
	if (len > this->_maxLen - this->_length)
		throw std::out_of_range("Erreur, la liste à ajouter est trop longue !");
	while (begin != end) {
		addNumber(*begin);
		begin++;
	} 
}


unsigned int	Span::shortestSpan() {
	if (_length < 2)
		throw std::range_error("Erreur: cette lsite contient moins de 2 éléments !");
	int result = INT_MAX;

	for (std::size_t i = 0; i < this->_length; i++) {
		int val1 = this->_tab.at(i);
		for (std::size_t j = 0; j < this->_length; j++) {
			if (i != j) {
				int val2 = this->_tab.at(j);
				int temp = val1 < val2 ? val2 - val1 : val1 - val2;
				result = temp < result ? temp : result;
			}
		}
	}
	return result;
};

unsigned int	Span::longestSpan() {
	if (_length < 2)
		throw std::range_error("Erreur: cette lsite contient moins de 2 éléments !");
	int result = INT_MIN;

	for (std::size_t i = 0; i < this->_length; i++) {
		int val1 = this->_tab.at(i);
		for (std::size_t j = 0; j < this->_length; j++) {
			if (i != j) {
				int val2 = this->_tab.at(j);
				int temp = val1 < val2 ? val2 - val1 : val1 - val2;
				result = temp > result ? temp : result;
			}
		}
	}
	return result;
};

std::ostream& operator<<(std::ostream& out, Span& span) {
	out << "[";
	for (std::size_t i = 0; i < span._length; i++) {
		out << span._tab.at(i);
		if (i != span._length - 1)
			out << ", ";
	}
	out << "]\n";
	return out;
}
