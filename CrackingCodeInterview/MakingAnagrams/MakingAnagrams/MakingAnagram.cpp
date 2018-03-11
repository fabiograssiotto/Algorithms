/*
Given two strings,  and , that may or may not be of the same length, determine the minimum number of character deletions
required to make  and  anagrams. Any characters can be deleted from either of the strings.
*/
#include <iostream>
using namespace std;

int numberNeeded(char* a, char* b) {
	int aFreq[26], bFreq[26];
	int deleteNum = 0;

	// clear out frequencies.
	for (int i = 0; i < 26; i++) {
		aFreq[i] = 0;
		bFreq[i] = 0;
	}

	// Now loop through and count
	int i = 0;
	while (a[i] != '\0') {
		aFreq[a[i] - 'a']++;
		i++;
	}

	i = 0;
	while (b[i] != '\0') {
		bFreq[b[i] - 'a']++;
		i++;
	}

	// Final loop: compare frequencies and adjust so both strings will have the same amount.
	for (int i = 0; i < 26; i++) {
		int delta = aFreq[i] - bFreq[i];
		if (delta < 0) {
			delta = -delta;
		}
		deleteNum += delta;
	}
	return deleteNum;
}


int main() {
	char a[10000];
	char b[10000];

	cin >> a;
	cin >> b;

	cout << numberNeeded(a, b) << endl;
}