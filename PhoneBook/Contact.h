#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
class Contact
{
public:
	Contact();
	virtual ~Contact();
	Contact(const std::string& name, const std::string& phone) : name(name), phone(phone) {};

	friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

	std::string getName();

private:
	std::string name, phone;
};

#endif
