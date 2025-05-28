
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    std::string name;
    std::string lastName;
    std::string nickName;
    std::string phone;
	std::string darkest;

	Contact() : name(""), lastName(""), nickName(""), phone(""), darkest("") {}

    Contact(const std::string& name,
            const std::string& lastName,
            const std::string& nickName,
            const std::string& phone,
			const std::string& darkest
	) : name(name), lastName(lastName), nickName(nickName), phone(phone) , darkest(darkest) {}

    Contact(const Contact& other)
        : name(other.name), lastName(other.lastName),
          nickName(other.nickName), phone(other.phone), darkest(other.darkest) {}

    Contact& operator=(const Contact& other) {
        if (this != &other) {
            name = other.name;
            lastName = other.lastName;
            nickName = other.nickName;
            phone = other.phone;
			darkest = other.darkest;
        }
        return *this;
    }

    ~Contact() {}

    bool isEmpty() const {
        return name.empty() && lastName.empty() && phone.empty() && nickName.empty() && darkest.empty();
    }
};

#endif