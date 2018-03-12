/*
A kidnapper wrote a ransom note but is worried it will be traced back to him. He found a magazine and wants to know
if he can cut out whole words from it and use them to create an untraceable replica of his ransom note.
The words in his note are case-sensitive and he must use whole words available in the magazine, meaning 
he cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly
using whole words from the magazine; otherwise, print No.

Input Format
The first line contains two space-separated integers describing the respective values of m (the number of words in the
magazine) and n (the number of words in the ransom note).
The second line contains m space-separated strings denoting the words present in the magazine.
The third line contains n space-separated strings denoting the words present in the ransom note.
*/
#include <iostream>
#include <cstring>
using namespace std;

struct HashNode {
	char str[6];
	int count; // For the number of times this word appears in the dictionary.
	HashNode* next;
};

const int HASH_SIZE = 500000;
HashNode* hashTable[HASH_SIZE];

int hashFunc(char* str) {
	int hash = 7;
	for (unsigned int i = 0; i < strlen(str); i++) {
		hash = hash * 31 + *(str+i);
	}
	return hash % HASH_SIZE;
}

// Tries to find the word in the hash table.
bool findWord(char* str) {
	int hashPos = hashFunc(str);
	HashNode* ptr = hashTable[hashPos];
	// Try to find in the hash table
	while (ptr != NULL) {
		if (strcmp(str, ptr->str) == 0) {
			// found the word, reduce the count
			ptr->count--;
			if (ptr->count == 0) {
				delete ptr;
				ptr = NULL;
			}
			return true;
		}
		else {
			// not found, check for any other words in this hash list
			if (ptr->next != NULL) {
				ptr = ptr->next;
				break;
			}
			else {
				// cannot find in the table list.
				return false;
			}
		}
	}
}

int main() {
	bool missingWords = false;
	int m, n;
	cin >> m;
	cin >> n;

	// Read in all the words in the magazine, creating hashes for them.
	for (int i = 0; i < m; i++) {
		char word[6];
		memset(word, '\0', 6);
		cin >> word;

		int hashPos = hashFunc(word);
		if (hashTable[hashPos] == NULL) {
			// ie hash is empty at the position.
			HashNode* newNode = new HashNode();
			strcpy(newNode->str, word);
			newNode->count = 1;
			newNode->next = NULL;
			hashTable[hashPos] = newNode;
		}
		else {
			// Same string, or collision?
			HashNode* ptr = hashTable[hashPos];
			bool isNewWord = true;

			int cmp = strcmp(ptr->str, word);

			if (strcmp(ptr->str, word) == 0) {
				isNewWord = false;
			}

			while (ptr->next != NULL && isNewWord == true) {
				if (strcmp(ptr->str, word) == 0) {
					// this word already appeared once, so do not create a new node,
					// just update the existing one.
					isNewWord = false;
					break;
				}
				ptr = ptr->next;
			}
			if (isNewWord) {
				HashNode* newNode = new HashNode();
				strcpy(newNode->str, word);
				newNode->next = NULL;
				ptr->next = newNode;
			}
			else {
				ptr->count++;
			}
		}
	}

	// Read ransom words and try to find them in the magazine.
	for (int i = 0; i < n; i++) {
		bool wordFound = false;
		char ransomWord[6];
		cin >> ransomWord;
		if (!findWord(ransomWord)) {
			// word not found, so stop now the search.
			missingWords = true;
			break;
		}
	}

	if (missingWords) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}
