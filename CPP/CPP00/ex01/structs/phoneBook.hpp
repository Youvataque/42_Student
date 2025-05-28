#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contacts.hpp"
#include <iostream>
#include <sstream>

class PhoneBook {
	private:
		Contact contacts[8];
		int		index ;
		void writeContat(Contact contact, int mode, int index);
		std::string formatVar(std::string var);
		std::string intToString(int n);
		int stringToInt(const std::string& str);
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();
		void addContact(Contact contact);
		void searchContact();
};

#endif