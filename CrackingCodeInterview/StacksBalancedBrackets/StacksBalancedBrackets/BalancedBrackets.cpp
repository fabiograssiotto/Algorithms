/*
Given n strings of brackets, determine whether each sequence of brackets is balanced. 
If a string is balanced, print YES on a new line; otherwise, print NO on a new line.
*/
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;


bool isBalanced(char* str) {
	stack<char> bracketStack;

	for (int i = 0; i < strlen(str); i++) {
		char c = str[i];
		if (c == '{' || c == '[' || c == '(') {
			bracketStack.push(c);
		}
		else {
			// closing brackets
			if (bracketStack.empty()) {
				// closing, but no opening...
				return false;
			}

			char popCh = bracketStack.top();
			if ((popCh == '{' && c == '}') ||
				(popCh == '[' && c == ']') ||
				(popCh == '(' && c == ')')) {
				// pop and keep going
				bracketStack.pop();
			}
			else {
				// unmatched.
				return false;
			}
		}
	}

	if (bracketStack.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char string[1001];
		cin >> string;
		if (isBalanced(string)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}