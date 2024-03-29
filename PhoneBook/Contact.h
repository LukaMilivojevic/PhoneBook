#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
class Contact
{
public:
	Contact();
	virtual ~Contact();
	Contact(std::string& name, std::string& phone) : name(name), phone(phone) {};

	friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

	std::string getName();

	void setName(const std::string& str);
	void setPhone(const std::string& str);

private:
	std::string name, phone;
};

#endif
