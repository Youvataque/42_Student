#include "Fixed.hpp"

//vous noterez sans doute une lègère différence dans les logs vs l'attendu en raison 
// de ce que je pense être une erreur dans le sujet.

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << Fixed::bit;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << Fixed::bit));
}

Fixed::Fixed(const Fixed& toCopy) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = toCopy.value;
};

Fixed& Fixed::operator=(const Fixed& toCopy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy) {
		this->value = toCopy.value;
	}
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
};

void Fixed::setRawBits( int const raw ) {
	this->value = raw;
};

int Fixed::toInt(void) const {
	return (this->value >> Fixed::bit);
}

float Fixed::toFloat(void) const {
	return (float)this->value / (1 << Fixed::bit);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}