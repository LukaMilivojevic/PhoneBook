#ifndef TRIES_H
#define TRIES_H
#include "Contact.h"
#include <list>
#include <string>

class Tries {
public:

	Tries() : root(nullptr) {};

	void insert(Contact* cont);

	std::list<Contact*>* search(const std::string& query);

	Contact* searchOne(const std::string& query);

	void deleteContact(Contact* contact);

private:
	static const int size = 2 * 26 + 10 + 1; //velika i mala slova + cifre + space
	struct Node {
		bool isEnd = false;
		Node* children[size];
		std::list<Contact*> nodeContacts;
		Node() {
			for (int i = 0; i < size; i++) children[i] = nullptr;
		}
	};
	Node* root;

	int findInd(unsigned char c);
};

#endif