#include "Contact.h"
#include "PhoneBook.h"
#include "Tries.h"
#include <fstream>
#include <iostream>
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
		std::cout << "File nije pronadjen";
	}
	input.close();
	//for (const auto& i : this->contacts) {
	//	std::cout << *(i) << std::endl;
	//}
}

void PhoneBook::openTerminal()
{
	std::string choice;
	int flag = 1;
	std::cout << text;
	while (flag) {
		std::cout << "Select an option: " << std::endl;
		std::cin >> choice;
		switch (option(choice))
		{
		case NEW:
			break;
		case SEARCH: {
			std::cout << "Enter a query: " << std::endl;
			std::string query;
			std::cin >> query;
			//if (tree.search(query)) std::cout << "IMA" << std::endl;
			//else std::cout << "NEMA" << std::endl;
			break;
		}
		case SELECT:
			break;
		case DELETE:
			break;
		case EDIT:
			break;
		case CALL:
			break;
		case CALL_HISTORY:
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
