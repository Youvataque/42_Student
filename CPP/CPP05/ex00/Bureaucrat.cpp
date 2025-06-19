#include "Bureaucrat.hpp"

void Bureaucrat::testGrade(int grade) const {
	if (grade > 150) {
		throw GradeTooLowException();
	} else if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	testGrade(grade);
	this->grade = grade;
};

Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName() const {
	return this->name;
};

int			Bureaucrat::getGrade() const {
	return this->grade;
};

void		Bureaucrat::upgrade() {
	int newGrade = this->grade - 1;
	testGrade(newGrade);
	this->grade = newGrade;
};

void		Bureaucrat::downgrade() {
	int newGrade = this->grade + 1;
	testGrade(newGrade);
	this->grade = newGrade;
};