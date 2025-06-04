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
	Fixed& operator=(const Fixed& toCopy);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);