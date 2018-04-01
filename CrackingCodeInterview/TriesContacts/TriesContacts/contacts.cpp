/*
We're going to make our own Contacts application! The application must perform two types of operations:
add name, where name is a string denoting a contact name. This must store name as a new contact in the application.
find partial, where partial is a string denoting a partial name to search the application for.
It must count the number of contacts starting with partial and print the count on a new line.
Given n sequential add and find operations, perform each operation in order.
n <= 10^5
name, partial lengths <= 21
*/
#include <iostream>
#include <cstring>
using namespace std;

const char ADD_OP[] = "add";
const char FIND_OP[] = "find";

struct TrieNode{
	char c;
	TrieNode *leafs[26];
	int numWords;

	TrieNode() {
		// Init structure
		c = '\0';
		numWords = 0;
		for (int i = 0; i < 26; i++) {
			leafs[i] = NULL;
		}
	}
};


void addContact(char* name, TrieNode* trie) {
	TrieNode* ptr = trie;
	for (unsigned int i = 0; i < strlen(name); i++) {
		// For each char check if there isn't a node
		TrieNode** childPtr = &(ptr->leafs[name[i] - 'a']);
		if (*childPtr == NULL) {
			TrieNode* child = new TrieNode;
			child->c = name[i];
			child->numWords = 1;
			*childPtr = child;
		}
		else {
			// Just update the number of words that use this node.
			(*childPtr)->numWords++;
		}
		ptr = *childPtr;
	}
}


int findContact(char* part, TrieNode* trie) {
	int found = 0;

	// Walk through the Trie until finding all the characters in the partial string.
	TrieNode* ptr = trie;
	for (unsigned int i = 0; i < strlen(part); i++) {
		if (ptr->leafs[part[i] - 'a'] == NULL) {
			// not found, so return zero as the number of strings found.
			break;
		}
		else {
			// Last char in partial string?
			if (i == strlen(part) - 1) {
				found = ptr->leafs[part[i] - 'a']->numWords;
			}
			else {
				// Next char
				ptr = ptr->leafs[part[i] - 'a'];
			}
		}
	}
	return found;
}

int main() {
	// Create Trie
	TrieNode* root = new TrieNode();

	int n;
	char name[21], partial[21], op[5];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> op;
		if (strcmp(op, ADD_OP) == 0) {
			// Add operation
			cin >> name;
			addContact(name, root);
		}
		else {
			cin >> partial;
			cout << findContact(partial, root) << endl;
		}
	}
}