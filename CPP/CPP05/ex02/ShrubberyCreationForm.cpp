#include "ShrubberyCreationForm.hpp"

/////////////////////////////////////////////////////////////////////////// constructeur
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defaultShru", 145, 137), _target("ShruTarget") {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("defaultShru", 145, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	this->_target = other._target;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shru destructor\n";
};

/////////////////////////////////////////////////////////////////////////// méthodes
bool	ShrubberyCreationForm::_writeAfile() const {
	const std::string temp[] = {
		"       _-_\n",
		"    /~~   ~~\\\n",
		" /~~         ~~\\\n",
		"{               }\n",
		" \\  _-     -_  /\n",
		"   ~  \\\\ //  ~\n",
		"_- -   | | _- _\n",
		"  _ -  | |   -_\n",
		"      // \\\\\n"
	};
	std::ofstream file(this->_target + "_shrubbery");

	if (!file) {
		return false;
	}

	const int size = sizeof(temp) / sizeof(temp[0]);
	for (int i = 0; i < size; i++) {
		file << temp[i];
	}

	file.close();
	return true;
};

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade()) {
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	bool result = _writeAfile();
	if (!result) {
		throw ShrubberyCreationForm::runtimeErrorException();
	}
};