#include "Point.hpp"

Point::Point() : x(0), y(0) {};
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {};
Point::Point(const Point& other) : x(other.x), y(other.y) {};
Point::~Point() {}
Point& Point::operator=(const Point& other) {
	// Ne peut pas marcher avec des const ...
	(void)other;
	return *this;
}

Fixed Point::getX(void) const {
	return this->x;
}

Fixed Point::getY(void) const {
	return this->y;
}

// bonus utile pour de l'aithmétie
Fixed Point::distance(const Point& other) const {
	Fixed temp = Fixed::sqrt(
		(other.getX() - this->getX()) * (other.getX() - this->getX())
		+
		(other.getY() - this->getY()) * (other.getY() - this->getY())
	);
	return temp;
}

Fixed Point::aire(const Point& b, const Point& c) const {
	Fixed x1 = this->getX();
	Fixed y1 = this->getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();

	Fixed result = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2));
	if (result < Fixed(0))
		result = result * -1;

	return result / Fixed(2);
}

bool Point::isPointIn(const Point& b, const Point& c ,const Point& p) const {
	Fixed epsilon(0.01f);
	return ((this->aire(b, p) + this->aire(c, p) + b.aire(c, p)) - this->aire(b, c)) < epsilon;
}
