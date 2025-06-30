#include "Bureaucrat.hpp"

void Bureaucrat::_testGrade(int grade) const {
	if (grade > 150) {
		throw GradeTooLowException();
	} else if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	_testGrade(grade);
	this->grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {};

Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName() const {
	return this->name;
};

int			Bureaucrat::getGrade() const {
	return this->grade;
};

void		Bureaucrat::incrementGrade() {
	int newGrade = this->grade - 1;
	_testGrade(newGrade);
	this->grade = newGrade;
};

void		Bureaucrat::decrementGrade() {
	int newGrade = this->grade + 1;
	_testGrade(newGrade);
	this->grade = newGrade;
};

void		Bureaucrat::signForm(AForm& form) {
	try
	{
		form.beSigned(*this);
		std::cout << "✅ " << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "❌ " << this->name << " cannot sign " << form.getName() << " because -> " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm& form) {
	try
	{
		form.execute(*this);
		std::cout << "✅ " << this->name << " execute " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "❌ " << this->name << " cannot exectue " << form.getName() << " because -> " << e.what() << std::endl;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& i) {
	out << i.getName() << ", bureaucrat grade " << i.getGrade();
	return out;
}