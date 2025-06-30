#include "AForm.hpp"

/////////////////////////////////////////////////////////////////////////// private méthode
void		AForm::_testGrade() const {
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw GradeTooLowException();
}

/////////////////////////////////////////////////////////////////////////// constructeur
AForm::AForm() : _name("default"), _isSigned(false), _signGrade(1), _execGrade(1) {
	_testGrade();
};

AForm::	AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	_testGrade();
};

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	_testGrade();
};

AForm::~AForm() {};

/////////////////////////////////////////////////////////////////////////// getter / setter
std::string	AForm::getName() const {
	return this->_name;
};

bool		AForm::getStatus() const {
	return this->_isSigned;
};

int			AForm::getSignGrade() const {
	return this->_signGrade;
};

int			AForm::getExecGrade() const {
	return this->_execGrade;
};

/////////////////////////////////////////////////////////////////////////// méthodes
void		AForm::beSigned(const Bureaucrat& user) {
	if (this->_isSigned) {
		throw SignedException();
	}
	if (user.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
		std::cout << "✅ " << user.getName() << " successfully sign " << this->getName() << std::endl;
	} else {
		throw GradeTooLowException();
	}
};

/////////////////////////////////////////////////////////////////////////// surcharge op
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
};

std::ostream& operator<<(std::ostream& out, const AForm& i) {
	out << "AForm : " << i.getName() << " isSigned : " << i.getStatus() << " signGrade : "
		<< i.getSignGrade() << " execGrade : " << i.getExecGrade() << std::endl;
	return out;
}