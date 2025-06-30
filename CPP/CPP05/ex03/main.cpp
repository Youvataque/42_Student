#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void printTitle(const std::string& title) {
	std::cout << "\033[1;32m\n=========== " << title << " ===========\033[0m\n";
}

int main() {
	Intern stagiaire;
	Bureaucrat boss("Boss", 1);
	Bureaucrat employe("Employe", 70);
	Bureaucrat stagiaireBureau("Stagiaire", 150);

	printTitle("Creation des formulaires par l'Intern");
	AForm* shrub = NULL;
	AForm* robot = NULL;
	AForm* pardon = NULL;
	AForm* inconnu = NULL;
	try {
		shrub = stagiaire.makeForm("shrubbery creation", "Jardin");
		robot = stagiaire.makeForm("robotomy request", "Bender");
		pardon = stagiaire.makeForm("presidential pardon", "Arthur");
		// Test d'un formulaire inconnu
		inconnu = stagiaire.makeForm("formulaire inconnu", "Cible");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("Affichage des formulaires");
	if (shrub) std::cout << *shrub;
	if (robot) std::cout << *robot;
	if (pardon) std::cout << *pardon;

	printTitle("Signature des formulaires");
	if (shrub) boss.signForm(*shrub);
	if (robot) employe.signForm(*robot);
	if (pardon) stagiaireBureau.signForm(*pardon); // Doit échouer
	if (pardon) boss.signForm(*pardon); // Doit réussir

	printTitle("Execution des formulaires");
	if (shrub) boss.executeForm(*shrub);
	if (robot) employe.executeForm(*robot);
	if (pardon) boss.executeForm(*pardon);

	printTitle("Tests d'exceptions");
	try {
		if (shrub) stagiaireBureau.executeForm(*shrub); // Trop bas
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		if (robot) boss.executeForm(*robot); // Peut échouer si non signé
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Nettoyage
	delete shrub;
	delete robot;
	delete pardon;
	delete inconnu;
	return 0;
}