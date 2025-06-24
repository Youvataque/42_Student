#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string	name;
	bool				isSigned;
	const int 			signGrade;
	const int 			execGrade;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	Form();
	Form(const Form& other);
	~Form();

	/////////////////////////////////////////////////////////////////////////// getter / setter
	const std::string	getName() const;
	const bool			getStatus() const;
	const int			getSignGrade() const;
	const int			getExecGrade() const;

	/////////////////////////////////////////////////////////////////////////// méthodes
	void				beSigned(const Bureaucrat& bureau);

	/////////////////////////////////////////////////////////////////////////// exeception
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Error your grade is too high.\n";
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Error your grade is too low.\n";
			}
	};

	/////////////////////////////////////////////////////////////////////////// surcharge op
	Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& out, const Form& i);

#endif