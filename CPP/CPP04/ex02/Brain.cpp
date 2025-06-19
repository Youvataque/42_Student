#include "Brain.hpp"

Brain::Brain() {
	std::cout << "brain def constructor\n";
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = "no idea";
	}
}

Brain::Brain(const std::string ideas[100]) {
	std::cout << "brain arg constructor\n";
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = ideas[i];
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "brain copy constructor\n";
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		std::cout << "brain operator constructor\n";
		for (int i = 0; i < 100; ++i) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "brain def destructor\n";
}

const std::string& Brain::getIdea(int index) const {
	static const std::string errorMsg = "badIndex";
	if (index < 100) {
		return this->ideas[index];
	}
	return errorMsg;
}