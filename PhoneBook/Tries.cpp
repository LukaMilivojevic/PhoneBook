#include "Contact.h"
#include "Tries.h"
#include <string>

void Tries::insert(Contact* cont)
{
	if (root == nullptr) root = new Node();
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
	curr->isEnd = true;
}

bool Tries::search()
{
	return false;
}

int Tries::findInd(unsigned char c)
{
	if (c == ' ') return size - 1;
	if (c >= 'a' && c <= 'z') return c - 'a';
	if (c >= 'A' && c <= 'Z') return c - 'A'+26;
	if (c >= '0' && c <= '9') return c - '0' + 52;
}
