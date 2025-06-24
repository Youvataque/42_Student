#include "Form.hpp"

/////////////////////////////////////////////////////////////////////////// constructeur
Form::Form() : name("default"), isSigned(false), signGrade(1), execGrade(1) {};

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {};

Form::~Form() {};

/////////////////////////////////////////////////////////////////////////// getter / setter
const std::string	Form::getName() const {};
const bool			Form::getStatus() const {};
const int			Form::getSignGrade() const {};
const int			Form::getExecGrade() const {};

/////////////////////////////////////////////////////////////////////////// méthodes
void				Form::beSigned(const Bureaucrat& bureau) {};

/////////////////////////////////////////////////////////////////////////// surcharge op
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
};