#include "structs/Point/Point.hpp"

int main() {
	Point A(0.0f, 0.0f);
	Point B(2.0f, 0.0f);
	Point C(0.0f, 2.0f);
	Point P(1.0f, 1.0f);
	std::cout << A.aire(B, C) << std::endl << A.isPointIn(B, C, P) << std::endl; // Doit afficher 2 et true(1) pour la présence du point

	Point a(1, 2);
	Point b(7, 4);
	Point c(4, 10);
	Point p(10, 10);
	std::cout << a.aire(b, c).toFloat() << std::endl << a.isPointIn(b, c, p) << std::endl; // Doit afficher 21 et false(0) pour la présence du point
}