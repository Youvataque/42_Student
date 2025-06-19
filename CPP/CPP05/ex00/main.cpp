#include "Bureaucrat.hpp"
#include <iostream>

void printLine(const std::string& title) {
	std::cout << "\n\033[1;35m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
	printLine("Créer Bureaucrat valide");
	try {
		Bureaucrat a("Jean", 42);
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	printLine("Créer Bureaucrat avec grade trop bas");
	try {
		Bureaucrat b("Bernard", 151); // trop bas
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	printLine("Créer Bureaucrat avec grade trop haut");
	try {
		Bureaucrat c("Lucie", 0); // trop haut
		std::cout << c << std::endl;
	} catch (std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	printLine("Tester increment et decrement");
	try {
		Bureaucrat d("Mathilde", 75);
		std::cout << d << std::endl;

		std::cout << "↓ Dégrader" << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;

		std::cout << "↑ Améliorer" << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
	} catch (std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	printLine("Tester exception sur grade 1 → increment");
	try {
		Bureaucrat elite("Albert", 1);
		std::cout << elite << std::endl;

		std::cout << "Tentative d'upgrade au-delà de 1" << std::endl;
		elite.incrementGrade(); // devrait throw
	} catch (std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	printLine("Tester exception sur grade 150 → decrement");
	try {
		Bureaucrat larbin("Kevin", 150);
		std::cout << larbin << std::endl;

		std::cout << "Tentative de downgrade au-delà de 150" << std::endl;
		larbin.decrementGrade(); // devrait throw
	} catch (std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	printLine("Fin du test complet C++05 ex00");
	return 0;
}