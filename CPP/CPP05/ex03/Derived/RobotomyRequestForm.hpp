#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	/////////////////////////////////////////////////////////////////////////// méthodes
	void	execute(Bureaucrat const & executor) const;
};

#endif