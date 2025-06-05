#include "Fixed.hpp"

/////////////////////////////////////////////////////////////////////////////// constructeurs 

Fixed::Fixed() : value(0) {
};

Fixed::Fixed(const int n) {
	this->value = n << Fixed::bit;
}

Fixed::Fixed(const float n) {
	this->value = roundf(n * (1 << Fixed::bit));
}

Fixed::Fixed(const Fixed& toCopy) {
	this->value = toCopy.value;
};

Fixed::~Fixed() {
};

/////////////////////////////////////////////////////////////////////////////// op

Fixed& Fixed::operator=(const Fixed& toCopy) {
	if (this != &toCopy) {
		this->value = toCopy.value;
	}
	return *this;
};

Fixed Fixed::operator*(const Fixed& other) {
	Fixed result;

	long temp = (this->value * other.value);
	result.value = temp >> Fixed::bit;
	return result;
}

/////////////////////////////////////////////////////////////////////////////// partie 1

int Fixed::getRawBits( void ) const {
	return this->value;
};

void Fixed::setRawBits( int const raw ) {
	this->value = raw;
};

/////////////////////////////////////////////////////////////////////////////// partie 2

int Fixed::toInt(void) const {
	return (this->value >> Fixed::bit);
}

float Fixed::toFloat(void) const {
	return (float)this->value / (1 << Fixed::bit);
}

/////////////////////////////////////////////////////////////////////////////// partie 3

const Fixed& Fixed::min(const Fixed& v1, const Fixed& v2) {
	if (v1.value < v2.value)
		return v1;
	else
		return v2;
}

Fixed& Fixed::min(Fixed& v1, Fixed& v2) {
	if (v1.value < v2.value)
		return v1;
	else
		return v2;
}

const Fixed& Fixed::max(const Fixed& v1, const Fixed& v2) {
	if (v1.value > v2.value)
		return v1;
	else
		return v2;
}

Fixed& Fixed::max(Fixed& v1, Fixed& v2) {
	if (v1.value > v2.value)
		return v1;
	else
		return v2;
}

/////////////////////////////////////////////////////////////////////////////// surcharge d'op

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}