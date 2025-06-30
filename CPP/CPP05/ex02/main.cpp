#include <iostream>
#include "Bureaucrat.hpp"
#include "Derived/ShrubberyCreationForm.hpp"
#include "Derived/RobotomyRequestForm.hpp"
#include "Derived/PresidentialPardonForm.hpp"

void printTitle(const std::string& title) {
	std::cout << "\033[1;32m\n=========== " << title << " ===========\033[0m\n";
}

int main() {
	std::srand(std::time(NULL));
	printTitle("FORM CREATION (no log here)");
	Bureaucrat mike("Mike", 137);  // peut signer mais pas exécuter
	Bureaucrat bob("Bob", 140);    // trop bas pour éxécuter
	Bureaucrat alice("Alice", 130); // peut signer et exécuter

	ShrubberyCreationForm form("home");

	printTitle("STATUS");
	std::cout << mike << std::endl;
	std::cout << bob << std::endl;
	std::cout << alice << std::endl;
	std::cout << form << std::endl;

	printTitle("BOB TRYING TO SIGN");
	bob.signForm(form);

	printTitle("MIKE TRYING TO SIGNS AN ALREDY SIGNED FORM");
	mike.signForm(form);

	printTitle("BOB EXECUTES FORM");
	bob.executeForm(form);

	printTitle("ALICE EXECUTES FORM");
	alice.executeForm(form);

	printTitle("FINAL STATUS");
	std::cout << form << std::endl;

	printTitle("ROBOTOMY FORM CREATION (no log here)");
	RobotomyRequestForm robotForm("Yannis");
	Bureaucrat mayleen("mayleen", 25);

	printTitle("ROBOTOMY STATUS");
	std::cout << robotForm << std::endl;

	printTitle("BOB TRYING TO SIGN ROBOTOMY");
	bob.signForm(robotForm);

	printTitle("MIKE TRYING TO SIGN ROBOTOMY");
	mike.signForm(robotForm);

	printTitle("BOB EXECUTES ROBOTOMY FORM");
	bob.executeForm(robotForm);

	printTitle("ALICE EXECUTES ROBOTOMY FORM");
	alice.executeForm(robotForm);

	printTitle("MAYLEEN SIGN & EXECUTES ROBOTOMY FORM");
	mayleen.signForm(robotForm);
	mayleen.executeForm(robotForm);

	printTitle("FINAL ROBOTOMY STATUS");
	std::cout << robotForm << std::endl;

	printTitle("PRESIDENTIAL FORM CREATION (no log here)");
	PresidentialPardonForm presForm("Arthur Dent");
	Bureaucrat zaphod("Zaphod", 5); // Peut tout faire

	printTitle("PRESIDENTIAL STATUS");
	std::cout << presForm << std::endl;

	printTitle("ZAPHOD TRY EXECUTES PRESIDENTIAL FORM BEFORE SIGN");
	zaphod.executeForm(presForm);

	printTitle("BOB TRYING TO SIGN PRESIDENTIAL");
	bob.signForm(presForm);

	printTitle("MIKE TRYING TO SIGN PRESIDENTIAL");
	mike.signForm(presForm);

	printTitle("ALICE TRYING TO SIGN PRESIDENTIAL");
	alice.signForm(presForm);

	printTitle("ZAPHOD SIGNS PRESIDENTIAL");
	zaphod.signForm(presForm);

	printTitle("BOB EXECUTES PRESIDENTIAL FORM");
	bob.executeForm(presForm);

	printTitle("ALICE EXECUTES PRESIDENTIAL FORM");
	alice.executeForm(presForm);

	printTitle("ZAPHOD EXECUTES PRESIDENTIAL FORM");
	zaphod.executeForm(presForm);

	printTitle("FINAL PRESIDENTIAL STATUS");
	std::cout << presForm << std::endl;

	return 0;
}