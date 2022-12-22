#include "Contact.h"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getName()
{
	return name;
}

void Contact::setName(const std::string& str)
{
	name = str;
}

void Contact::setPhone(const std::string& str)
{
	phone = str;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	os << contact.name << "," << contact.phone;
	return os;
}
