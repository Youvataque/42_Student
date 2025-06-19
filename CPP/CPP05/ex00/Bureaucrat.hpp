#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
private: 
	const std::string	name;
	int					grade;
	void		testGrade(int grade) const;
public:
	Bureaucrat(const std::string, int grade);
	~Bureaucrat();

	std::string getName() const;
	int			getGrade() const;
	void		upgrade();
	void		downgrade();

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Error your grade is < 1\n";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Error your grade is > 150\n";
			}
	};
};

#endif