#include "Bureaucrat.hpp"

void Bureaucrat::testGrade(int grade) const {
	if (grade > 150) {
		throw GradeTooLowException();
	} else if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	testGrade(grade);
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
	testGrade(newGrade);
	this->grade = newGrade;
};

void		Bureaucrat::decrementGrade() {
	int newGrade = this->grade + 1;
	testGrade(newGrade);
	this->grade = newGrade;
};

void		Bureaucrat::signForm(Form& form) {
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
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