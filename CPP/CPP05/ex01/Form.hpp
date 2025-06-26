#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name;
	bool				isSigned;
	const int 			signGrade;
	const int 			execGrade;
	void			testGrade() const;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form& other);
	~Form();

	/////////////////////////////////////////////////////////////////////////// getter / setter
	std::string		getName() const;
	bool			getStatus() const;
	int				getSignGrade() const;
	int				getExecGrade() const;

	/////////////////////////////////////////////////////////////////////////// méthodes
	void			beSigned(const Bureaucrat& bureau);

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

	class FormSignedException : public std::exception {
		public:
			const char* what() const throw() {
				return "Error the form is already signed !\n";
			}
	};

	/////////////////////////////////////////////////////////////////////////// surcharge op
	Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& out, const Form& i);

#endif