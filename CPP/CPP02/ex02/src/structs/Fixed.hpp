#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	const static int bit = 8;
	int value;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& toCopy);
	~Fixed();

	Fixed& operator=(const Fixed& toCopy);
	Fixed operator*(const Fixed& other);
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator/(const Fixed& other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt(void) const;
	float toFloat(void) const;
	const static Fixed& min(const Fixed& v1, const Fixed& v2);
	static Fixed& min(Fixed& v1, Fixed& v2);
	const static Fixed& max(const Fixed& v1, const Fixed& v2);
	static Fixed& max(Fixed& v1, Fixed& v2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif