#include <iostream>
#include "../structs/phoneBook.hpp"

Contact askForParam() {
	std::string name;
	std::string lastName;
    std::string nickName;
    std::string phone;
	std::string darkest;

	std::cout << "Veuillez entrer le prénom du contact.\n";
	std::getline(std::cin, name);
	std::cout << "Veuillez entrer le nom du contact.\n";
	std::getline(std::cin, lastName);
	std::cout << "Veuillez entrer le pseudo du contact.\n";
	std::getline(std::cin, nickName);
	std::cout << "Veuillez entrer le numéro de téléphone du contact.\n";
	std::getline(std::cin, phone);
	std::cout << "Veuillez entrer le plus grand secret du contact.\n";
	std::getline(std::cin, darkest);
	return Contact(name, lastName, nickName, phone, darkest);
}

int main(void) {
	PhoneBook phoneBook = PhoneBook();
	while (true) {
		if (!std::cin) break;
		std::string command;
		std::cout << "Veuillez entrer ADD, SEARCH ou EXIT\n";
		std::getline(std::cin, command);
		
		if (command == "ADD") {
			Contact newContact = askForParam();
			if (newContact.isEmpty()) {
				std::cout << "Contact invalide, tous les champs sont requis.\n";
				continue;
			}
			phoneBook.addContact(newContact);
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break ;
		} else {
			std::cout << "Commande inconnue. Veuillez taper ADD, SEARCH ou EXIT.\n";
		}
	}
}