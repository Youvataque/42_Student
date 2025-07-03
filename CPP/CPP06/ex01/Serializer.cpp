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
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}