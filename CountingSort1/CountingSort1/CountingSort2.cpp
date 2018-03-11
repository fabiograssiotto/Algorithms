/* https://www.hackerrank.com/challenges/countingsort2
Often, when a list is sorted, the elements being sorted are just keys to other values. 
For example, if you are sorting files by their size, the sizes need to stay connected to their respective files.
You cannot just take the size numbers and output them in order, you need to output all the required file information.

However, if you are not concerned about any other information, then you can simply sort those numbers alone.
This makes counting sort very simple. If you already counted the values in the list, you don't need to access the original list again.
This challenge involves a simple counting sort where the elements being sorted are all that matter.

Challenge
Given an unsorted list of integers, output the integers in order.

Hint: You can use your previous code that counted the items to print out the actual values in order.

Constraints
100 <= n <= 10^7
0 <= x < 100
*/

#include <iostream>
using namespace std;

// Make this global to avoid a stack overflow
int sorted[1000000] = { 0 };

int main() {
	// Frequency counter is the first step for Counting Sort.
	int frequency[100] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		frequency[data]++;
	}

	// Now that frequencies are set, create a new sorted array based off it.
	
	int insPos = 0;
	for (int j = 0; j < 100; j++) {
		for (int k = 0; k < frequency[j] && k < n; k++) {
			sorted[insPos] = j;
			insPos++;
		}
	}

	// Output
	for (int i = 0; i < n; i++) {
		cout << sorted[i] << " ";
	}
	return 0;
}