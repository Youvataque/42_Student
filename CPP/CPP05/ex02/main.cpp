#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void printTitle(const std::string& title) {
	std::cout << "\033[1;32m\n=========== " << title << " ===========\033[0m\n";
}

int main() {
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

	return 0;
}