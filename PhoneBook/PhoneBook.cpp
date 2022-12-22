#include "Contact.h"
#include "PhoneBook.h"
#include "Tries.h"
#include <fstream>
#include <iostream>
#include <list>
#include <string>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
	for (auto& it : this->contacts) delete it; 
	this->contacts.clear();
}

void PhoneBook::loadPhonebook(const std::string& filepath)
{
	filepath_ = filepath;
	std::ifstream input;
	input.open(filepath);
	if (input.is_open()) {
		std::string name;
		std::string phone;
		while (getline(input, name, ',')){
			getline(input, phone);
			Contact* temp = new Contact(name, phone);
			this->contacts.push_back(temp);
			this->tree.insert(temp);
		}
	}
	else {
		std::cout << "File not found." << std::endl;
	}
	input.close();
}

int PhoneBook::option(const std::string& s)
{
		if (s == "NEW") return 0;
		if (s == "SEARCH") return 1;
		if (s == "SELECT") return 2;
		if (s == "DELETE") return 3;
		if (s == "EDIT") return 4;
		if (s == "CALL") return 5;
		if (s == "CALL_HISTORY") return 6;
		if (s == "EXIT") return 7;
		return -1;
}

// pretraga za korisnika
void PhoneBook::search()
{
	std::cout << "- Enter the contact name or first few letters: ";
	std::string query;
	std::getline(std::cin, query); // preskakanje ulaza iz fajla
	std::getline(std::cin, query, '\n');
	std::list<Contact*>* result = tree.search(query);
	if (result != nullptr) {
		std::cout << "- " << (*result).size() << " contacts have been found:" << std::endl;
		for (const auto& it : *result) {
			std::cout << "--- " << *it << std::endl;
		}
	}
	else std::cout << "- No contact has been found." << std::endl;
}

Contact* PhoneBook::select()
{
	std::cout << "- Enter the contact name: ";
	std::string query;
	std::getline(std::cin, query); // preskakanje ulaza iz fajla
	std::getline(std::cin, query, '\n');
	Contact* result = tree.searchOne(query);
	if (result != nullptr) {
		std::cout << "Selected contact: " << (*result) << std::endl;
		return result;
	}
	else std::cout << "- No contact has been found." << std::endl;
	return nullptr;
}

// pretraga za dodavanje novog kontakta
bool PhoneBook::search(Contact* newContact)
{
	std::string query = newContact->getName();
	std::list<Contact*>* result = tree.search(query);
	if (result != nullptr) return true;
	else return false;
}

bool PhoneBook::addNewContact(Contact* newContact)
{
	//std::ofstream output; ako se otkomentarisu linije u ovoj f-ji, kontakt se dodaje u file
	//output.open(filepath_, std::ios_base::app);
	if (!search(newContact)) {
		contacts.push_back(newContact);
		tree.insert(newContact);
		//output << *newContact << std::endl;
		//output.close();
		return true;
	}
	//output.close();
	return false;
}

void PhoneBook::call(Contact* toCall)
{
	if(history.size() < 10) history.push_front(toCall);
	else {
		history.pop_back();
		history.push_front(toCall);
	}
	std::cout << "Contact called successfully." << std::endl;
}

void PhoneBook::deleteContact(Contact* selected)
{
		tree.deleteContact(selected);
		for (auto itr = contacts.begin(); itr != contacts.end(); itr++) {
			if ((*itr)->getName() == selected->getName()) {
				contacts.erase(itr);
				break;
			}
		}
}

bool PhoneBook::editContact(Contact* selected)
{
	unsigned char choice;
	std::cout << "Change name (press n) or phone (press p): " << std::endl;
	std::cin >> choice;
	if (choice == 'p') {
		std::cout << "Enter the new phone number: ";
		std::string newPhone;
		std::cin >> newPhone;
		selected->setPhone(newPhone);
		return true;
	}
	else if (choice == 'n') {
		std::cout << "Enter the new name: ";
		std::string newName;
		std::getline(std::cin, newName);
		std::getline(std::cin, newName, '\n');
 		deleteContact(selected);
		selected->setName(newName);
		addNewContact(selected);
	}
	return false;
}

void PhoneBook::openTerminal()
{
	std::string choice;
	int flag = 1;
	Contact* selected = nullptr;
	std::cout << text;
	while (flag) {
		std::cout << "Enter the command: ";
		std::cin >> choice;
		switch (option(choice))
		{
		case NEW: {
			std::cout << "Enter new contact in format: Name,Phone" << std::endl;
			Contact* newContact = new Contact();
			std::string temp;
			std::getline(std::cin, temp); //preskakanje newline
			std::getline(std::cin, temp, ',');
			newContact->setName(temp);
			std::getline(std::cin, temp, '\n');
			newContact->setPhone(temp);
			if (addNewContact(newContact)) std::cout << "New contact added: " << (*newContact) << std::endl;
			else std::cout << "Contact with that name already exists." << std::endl;
			break;
		}
		case SEARCH: {
			search();
			break;
		}
		case SELECT:
			selected = select();
			break;
		case DELETE: {
			if (selected != nullptr) deleteContact(selected);
			selected = nullptr;
			std::cout << "Contact removed." << std::endl;
			break;
		}
		case EDIT:
			if (selected != nullptr) editContact(selected);
			break;
		case CALL:
			if(selected != nullptr) call(selected);
			break;
		case CALL_HISTORY:
			std::cout << "CALL HISTORY: " << std::endl;
			for (const auto& it : history) {
				std::cout << "--- " << (*it) << std::endl;
			}
			break;
		case EXIT:
			flag = 0;
			break;
		default:
			std::cout << "Invalid option selected. Enter a valid option or EXIT to close the terminal." << std::endl;
			std::cout << text;
		}
	}
}

