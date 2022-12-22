#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>


template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() :root(nullptr) {}

	virtual ~BinarySearchTree() {};


	T* insert(const char key, T* val) {
		if (root == nullptr) {
			root = new Node(key, val);
			return root->val;
		}
		Node* curr = root;
		while (curr != nullptr) {
			if (key < curr->key) {
				if (curr->left) curr = curr->left;
				else {
					curr->left = new Node(key, val);
					return curr->val;
				}
			}
			else if (key > curr->key) {
				if (curr->right) curr = curr->right;
				else {
					curr->right = new Node(key, val);
					return curr->val;
				}
			}
			else return curr->val;
		}
	};

	T* find(const char key) const {
		Node* curr = root;
		while (curr != nullptr) {
			if (key < curr->key){
				if (curr->left) curr = curr->left;
				else return nullptr;
			}
			else if (key > curr->key) {
				if (curr->right) curr = curr->right;
				else return nullptr;
			}
			else return curr->val;
		}
		return nullptr;
	};

private:
	struct Node {
		Node* left, *right;
		char key;
		T* val;
		Node(char key, T* val) :key(key), val(val), left(nullptr), right(nullptr) {};
	};

	Node* root;

};
#endif
