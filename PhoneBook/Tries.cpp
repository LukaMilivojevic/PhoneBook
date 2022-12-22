#include "Contact.h"
#include "Tries.h"
#include <list>
#include <string>

void Tries::insert(Contact* cont)
{
	if (root == nullptr) root = new Node();
	if (searchOne(cont->getName()) != nullptr) return;
	Node* curr = root;
	for (const auto& it : cont->getName()) {
		int index = findInd(it);
		Node* next = curr->children[index];
		if (next == nullptr) {
			next = new Node();
			curr->children[index] = next;
		}
		curr->nodeContacts.push_back(cont);
		curr = next;
	}
	curr->nodeContacts.push_back(cont);
	curr->isEnd = true;
}

std::list<Contact*>* Tries::search(const std::string& query)
{
	if (root == nullptr) return nullptr;

	Node* curr = root;
	int index;
	for (const auto& it : query) {
		index = findInd(it);
		curr = curr->children[index];

		if (curr == nullptr) return nullptr;
	}
	if (curr->nodeContacts.size()) return &(curr->nodeContacts);
	else return nullptr;
}

Contact* Tries::searchOne(const std::string& query)
{
	if (root == nullptr) return nullptr;

	Node* curr = root;
	int index;
	for (const auto& it : query) {
		index = findInd(it);
		curr = curr->children[index];

		if (curr == nullptr) return nullptr;
	}
	if (curr->isEnd) {
		for (auto& it : curr->nodeContacts)
			if (query == (*it).getName()) return it;
		//return &(curr->nodeContacts);
	}
	else return nullptr;
}

void Tries::deleteContact(Contact* contact)
{
	const std::string& query = contact->getName();
	Node* curr = root;
	for (const auto& it : query) {
		for (auto itr = curr->nodeContacts.begin(); itr != curr->nodeContacts.end(); itr++) {
			if ((*itr)->getName() == contact->getName()) {
				curr->nodeContacts.erase(itr);
				//curr->nodeContacts.remove(*itr);
				break;
			}
		}
		curr = curr->children[findInd(it)];
	}
	for (auto itr = curr->nodeContacts.begin(); itr != curr->nodeContacts.end(); itr++) {
		if ((*itr)->getName() == contact->getName()) {
			curr->nodeContacts.erase(itr);
			//curr->nodeContacts.remove(*itr);
			break;
		}
	}
}

int Tries::findInd(unsigned char c)
{
	if (c == ' ') return size - 1;
	if (c >= 'a' && c <= 'z') return c - 'a';
	if (c >= 'A' && c <= 'Z') return c - 'A'+26;
	if (c >= '0' && c <= '9') return c - '0' + 52;
}