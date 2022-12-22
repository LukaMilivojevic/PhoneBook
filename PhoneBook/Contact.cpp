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

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	os << contact.name << " " << contact.phone;
	return os;
}
