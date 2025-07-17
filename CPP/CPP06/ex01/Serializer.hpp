#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data {
	int         id;
	std::string name;
	float       score;
};

class Serializer {
private:
	/////////////////////////////////////////////////////////////////////////// constructeur
	Serializer();
	Serializer(const Serializer& other);
	~Serializer();
	Serializer& operator=(const Serializer& other);

	/////////////////////////////////////////////////////////////////////////// méthodes privées

	/////////////////////////////////////////////////////////////////////////// attributs

public:
	/////////////////////////////////////////////////////////////////////////// méthodes
	static unsigned long serialize(Data* ptr);
	static Data* deserialize(unsigned long raw);

};

#endif