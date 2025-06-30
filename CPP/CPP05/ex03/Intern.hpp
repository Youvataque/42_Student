#ifndef INTERN
#define INTERN

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Derived/ShrubberyCreationForm.hpp"
#include "Derived/RobotomyRequestForm.hpp"
#include "Derived/PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string name, const std::string target) const;

	Intern& operator=(const Intern& other);

	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "❌ Intern: Erreur, le nom du formulaire est inconnu.";
		}
	};
};

#endif