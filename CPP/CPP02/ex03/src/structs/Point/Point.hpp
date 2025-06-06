#ifndef POINT_HPP
#define POINT_HPP

#include "../Fixed/Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Fixed distance(const Point& other) const;
	Fixed aire(const Point& b, const Point& c) const;
	Fixed getX(void) const;
	Fixed getY(void) const;
	bool isPointIn(const Point& b, const Point& c, const Point& p) const;
};

#endif