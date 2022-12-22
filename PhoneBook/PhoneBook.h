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
	std::string filepath_;
	std::list<Contact*> contacts;
	std::list<Contact*> history;
	Tries tree;
	int option(const std::string& s);
	void search();
	Contact* select();
	bool search(Contact* newContact);
	bool addNewContact(Contact* newContact);
	void call(Contact* toCall);
	void deleteContact(Contact* selected);
	bool editContact(Contact* selected);

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