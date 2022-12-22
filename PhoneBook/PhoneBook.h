#ifndef PHONEBOOK_H
#define PHONEBOOK_h

#include "Contact.h"
#include "Tries.h"
#include <list>
#include <string>

class PhoneBook
{
public:
	PhoneBook();

	virtual ~PhoneBook();

	void loadPhonebook(const std::string& filepath);
	void openTerminal();


private:
	std::list<Contact*> contacts;
	Tries tree;
	int option(const std::string& s);

	enum OPTIONS
	{
		NEW,
		SEARCH,
		SELECT,
		DELETE,
		EDIT,
		CALL,
		CALL_HISTORY,
		EXIT
	};

	const char* text =
		"---***--- \n"
		"Options: \n"
		"NEW - add a new contact \n"
		"SEARCH - search for contacts with a given prefix \n"
		"SELECT - select contact \n"
		"DELETE - delete contact \n"
		"EDIT - edit the selected contact \n"
		"CALL - call the selected contact \n"
		"CALL_HISTORY - last 10 calls \n"
		"EXIT - exit the app \n"
		"---***--- \n";
};

#endif