#include "Intern.hpp"

Intern::Intern() {};
Intern::Intern(const Intern& other) {
	(void)other;
};
Intern::~Intern() {};

AForm* Intern::makeForm(const std::string name, const std::string target) const {
	const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; ++i) {
		if (name == formNames[i]) {
			std::cout << "✅ Intern crée le formulaire : " << formNames[i] << std::endl;
			for (int j = 0; j < 3; ++j) {
				if (j != i)
					delete forms[j];
			}
			return forms[i];
		}
	}
	for (int j = 0; j < 3; ++j)
		delete forms[j];
	throw FormNotFoundException();
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
};