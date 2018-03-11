#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

// Make the hash table very large to avoid collisions.
list<string> hashTable[30000];

int hashCode(string input) {
	// Simple hash code
	int hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}


void put(string input) {
	int hash = hashCode(input);
	hashTable[hash].push_front(input);
}


bool ransom_note(vector<string> magazine, vector<string> ransom) {
	// Create a hash table for all the words in the magazine.
	for (int i = 0; i < magazine.size(); i++) {
		put(magazine[i]);
	}

	// Now check if the note words can be found in the hash table.
	// If a word is found, remove it to account for duplicate words.
		
	return false;
}

int main() {
	int m;
	int n;
	cin >> m >> n;
	vector<string> magazine(m);
	for (int magazine_i = 0; magazine_i < m; magazine_i++) {
		cin >> magazine[magazine_i];
	}
	vector<string> ransom(n);
	for (int ransom_i = 0; ransom_i < n; ransom_i++) {
		cin >> ransom[ransom_i];
	}
	if (ransom_note(magazine, ransom))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}