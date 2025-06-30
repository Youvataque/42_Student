#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private: 
	const std::string	name;
	int					grade;
	void				_testGrade(int grade) const;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	Bureaucrat();
	Bureaucrat(const std::string, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	/////////////////////////////////////////////////////////////////////////// méthodes
	std::string getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(AForm& form);
	void		executeForm(AForm& form);

	/////////////////////////////////////////////////////////////////////////// exeception
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Bureaucrat: Error your grade is < 1\n";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Bureaucrat: Error your grade is > 150\n";
			}
	};

	/////////////////////////////////////////////////////////////////////////// surcharge op
	Bureaucrat& operator=(const Bureaucrat& other);

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& i);


#endif