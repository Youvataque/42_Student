#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other.materia[i])
			this->materia[i] = other.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->materia[i])
				delete this->materia[i];
			if (other.materia[i])
				this->materia[i] = other.materia[i]->clone();
			else
				this->materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->materia[i])
			delete this->materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	std::cout << "learnMateria: learning " << materia->getType() << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materia[i] == NULL) {
			this->materia[i] = materia->clone();
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	std::cout << "createMateria: requested '" << type << "' ";
	for (int i = 0; i < 4; i++) {
		if (this->materia[i] != NULL && this->materia[i]->getType() == type) {
			std::cout << "→ clone successful\n";
			return this->materia[i]->clone();
		}
	}
	std::cout << "→ unknown materia\n";
	return NULL;
}
