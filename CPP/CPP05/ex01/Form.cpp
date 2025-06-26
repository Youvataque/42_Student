#include "Form.hpp"

/////////////////////////////////////////////////////////////////////////// constructeur
Form::Form() : name("default"), isSigned(false), signGrade(1), execGrade(1) {
	testGrade();
};

Form::	Form(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	testGrade();
};

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {
	testGrade();
};

Form::~Form() {};

/////////////////////////////////////////////////////////////////////////// getter / setter
std::string	Form::getName() const {
	return this->name;
};

bool		Form::getStatus() const {
	return this->isSigned;
};

int			Form::getSignGrade() const {
	return this->signGrade;
};

int			Form::getExecGrade() const {
	return this->execGrade;
};

/////////////////////////////////////////////////////////////////////////// méthodes
void		Form::testGrade() const {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooHighException();
	if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooLowException();
}


void		Form::beSigned(const Bureaucrat& user) {
	if (this->isSigned) {
		throw FormSignedException();
	}
	if (user.getGrade() <= this->signGrade) {
		std::cout << user.getName() << " sign " << this->name <<" !\n";
		this->isSigned = true;
	} else {
		throw GradeTooLowException();
	}
};

/////////////////////////////////////////////////////////////////////////// surcharge op
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
};

std::ostream& operator<<(std::ostream& out, const Form& i) {
	out << "form : " << i.getName() << " isSigned : " << i.getStatus() << " signGrade : "
		<< i.getSignGrade() << " execGrade : " << i.getExecGrade() << std::endl;
	return out;
}