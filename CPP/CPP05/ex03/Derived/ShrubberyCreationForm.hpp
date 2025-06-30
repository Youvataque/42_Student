#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "../AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
	bool		_writeAfile() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	/////////////////////////////////////////////////////////////////////////// méthodes
	void	execute(Bureaucrat const & executor) const;

	/////////////////////////////////////////////////////////////////////////// exceptions
	class runtimeErrorException : public std::exception {
		public:
			 virtual const char* what() const throw() {
				return "ShrubberyCreationForm: Error, can't create or open file !\n";
			}
	};
};

#endif