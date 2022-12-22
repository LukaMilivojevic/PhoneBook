#ifndef TRIES_H
#define TRIES_H
#include "Contact.h"
#include <list>


class Tries {
public:

	Tries() : root(nullptr) {};

	void insert(Contact* cont);

	bool search();

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