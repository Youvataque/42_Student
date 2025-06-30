#include "PresidentialPardonForm.hpp"

/////////////////////////////////////////////////////////////////////////// constructeur
PresidentialPardonForm::PresidentialPardonForm() : AForm("SuperForgiveness", 25, 5), _target("PresiTarget") {};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("SuperForgiveness", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	this->_target = other._target;
};

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Pres destructor\n";
};

/////////////////////////////////////////////////////////////////////////// méthodes

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getStatus() == false) {
		throw PresidentialPardonForm::NotSignedException();
	}
	if (executor.getGrade() > this->getExecGrade()) {
		throw PresidentialPardonForm::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};