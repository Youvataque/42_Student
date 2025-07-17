#include "Serializer.hpp"


/////////////////////////////////////////////////////////////////////////// constructeur
Serializer::Serializer() {
	// default constructor
}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer::~Serializer() {
	// destructor
}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

/////////////////////////////////////////////////////////////////////////// méthodes
unsigned long Serializer::serialize(Data* ptr) {
	return reinterpret_cast<unsigned long>(ptr);
}

Data* Serializer::deserialize(unsigned long raw) {
	return reinterpret_cast<Data*>(raw);
}