#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/////////////////////////////////////////////////////////////////////////// constructeur
Base::Base() {
	// default constructor
}

Base::Base(const Base& other) {
	(void)other;
}

Base::~Base() {
	// destructor
}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
Base& Base::operator=(const Base& other) {
	(void)other;
	return *this;
}

/////////////////////////////////////////////////////////////////////////// méthodes
Base* Base::generate(void) {
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void Base::identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception error) {
		(void)error;
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (std::exception error) {
			(void)error;
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (std::exception error) {
				(void)error;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////// exceptions