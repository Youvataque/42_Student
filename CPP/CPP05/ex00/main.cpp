#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bur1 = Bureaucrat("Yannis", 151);
		bur1.downgrade();
		std::cout << bur1.getGrade() << " - " << bur1.getName() << std::endl;
	} catch (Bureaucrat::GradeTooHighException e) {
		std::cerr << "error : " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cerr << "error : " << e.what() << std::endl;
	}
}