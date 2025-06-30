#include "RobotomyRequestForm.hpp"

/////////////////////////////////////////////////////////////////////////// constructeur
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomization", 72, 45), _target("RobotTarget") {};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomization", 52, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	this->_target = other._target;
};

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Rob destructor\n";
};

/////////////////////////////////////////////////////////////////////////// méthodes

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getStatus() == false) {
		throw RobotomyRequestForm::NotSignedException();
	}
	if (executor.getGrade() > this->getExecGrade()) {
		throw RobotomyRequestForm::GradeTooLowException();
	}
	std::cout << "BZZZZZZZZZZZZZZZZ, BZZZZZZZZZ\n";
	if (std::rand() % 2) {
		std::cout << "✅ " << executor.getName() << " successfully robotomize " << this->_target << std::endl;
	} else {
		std::cout << "❌ Nooo " << this->_target << " is dead.\n";
	}
};