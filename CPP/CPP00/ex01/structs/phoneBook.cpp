#include "phoneBook.hpp"

////////////////////////////////////////////////////////////////////////////////////////////// Partie construction / destruction

///////////////////////////////////////////////////////////////////////////////
// constructeur simple
PhoneBook::PhoneBook() : index(0) {}

///////////////////////////////////////////////////////////////////////////////
// par copie
PhoneBook::PhoneBook(const PhoneBook &toCopy) {
	this->index = 0;
	for (int i = 0; i < 8; i++) {
		this->contacts[i] = toCopy.contacts[i];
	}
}

///////////////////////////////////////////////////////////////////////////////
// par assignation 
PhoneBook& PhoneBook::operator=(const PhoneBook& toCopy) {
    if (this != &toCopy) {
		this->index = 0;
        for (int i = 0; i < 8; ++i) {
            this->contacts[i] = toCopy.contacts[i];
        }
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// destructeur
PhoneBook::~PhoneBook() {}

//////////////////////////////////////////////////////////////////////////////////////////////  methodes de la classe

int PhoneBook::stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

std::string PhoneBook::intToString(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

///////////////////////////////////////////////////////////////////////////////
// convertit une var pour affichage
std::string PhoneBook::formatVar(const std::string var) {
	std::string result = "|";
	if (var.length() > 10) {
		result += var.substr(0, 9) + ".";
	} else {
		result += std::string(10 - var.length(), ' ') + var;
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Affiche un contacte dans le terminal
void PhoneBook::writeContat(Contact contact, int mode, int index) {
	if (mode) {
		std::cout << "First name    : " << contact.name << std::endl;
		std::cout << "Last name     : " << contact.lastName << std::endl;
		std::cout << "Nickname      : " << contact.nickName << std::endl;
		std::cout << "Phone number  : " << contact.phone << std::endl;
		std::cout << "Darkest secret: " << contact.darkest << std::endl;
	} else {
		std::cout
			<< intToString(index)
			<< formatVar(contact.name)
			<< formatVar(contact.lastName)
			<< formatVar(contact.nickName)
			<< std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////////
// ajoutes un contact à l'objet en utilisant un index. Retourne au début si
// plus de place.
void PhoneBook::addContact(Contact contact) {
	if (this->index == 7) {
		this->index = 0;
	}
	this->contacts[index] = contact;
	index++;
}

///////////////////////////////////////////////////////////////////////////////
// Affiche l'ensemble des contactes dans le terminal et propose de sélectionner
void PhoneBook::searchContact() {
	int i = 0;
	while (!this->contacts[i].isEmpty()) {
		writeContat(this->contacts[i], 0, i);
		i++;
	}
	while (true) {
		if (!std::cin) break;
		std::string command;
		std::cout << "Entrer RETOUR pour sortir de la recher ou l'index de contact souhaité.\n";
		std::getline(std::cin, command);
		if (command == "RETOUR") {
			break ;
		} else if (command == "0" || command == "1" || command == "2" || command == "3" || command == "4" || command == "5" || command == "6" || command == "7") {
			int index = stringToInt(command);
			if (this->contacts[index].isEmpty()) {
				std::cout << "Erreur, l'index est invalide !\n";
				break ;
			}
			writeContat(this->contacts[stringToInt(command)], 1, stringToInt(command));
		} else {
			std::cout << "Erreur, veuillez entrer Retour ou un index\n";
		}
	}
}