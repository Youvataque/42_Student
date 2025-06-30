#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int 			_signGrade;
	const int 			_execGrade;
	void				_testGrade() const;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm& other);
	virtual ~AForm();

	/////////////////////////////////////////////////////////////////////////// getter / setter
	std::string		getName() const;
	bool			getStatus() const;
	int				getSignGrade() const;
	int				getExecGrade() const;

	/////////////////////////////////////////////////////////////////////////// méthodes
	void			beSigned(const Bureaucrat& bureau);
	virtual void			execute(Bureaucrat const & executor) const = 0;

	/////////////////////////////////////////////////////////////////////////// exeception
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm: Error your grade is too high.\n";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm: Error your grade is too low.\n";
			}
	};

	class NotSignedException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm: Error the form is not signed ! Can't execute.\n";
			}
	};

	class SignedException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm: Error the form is already signed !\n";
			}
	};

	/////////////////////////////////////////////////////////////////////////// surcharge op
	AForm& operator=(const AForm& other);
};

std::ostream& operator<<(std::ostream& out, const AForm& i);

#endif