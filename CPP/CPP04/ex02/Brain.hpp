#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const std::string ideas[100]);
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	const std::string& getIdea(int index) const;
};

#endif