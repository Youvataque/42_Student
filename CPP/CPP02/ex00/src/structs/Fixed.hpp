#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	const static int bit = 8;
	int value;
public:
	Fixed();
	Fixed(const Fixed& toCopy);
	Fixed& operator=(const Fixed& toCopy);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif