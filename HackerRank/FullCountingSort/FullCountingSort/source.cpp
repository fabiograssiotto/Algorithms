/*
In this challenge you need to print the data that accompanies each integer in a list.
In addition, if two strings have the same integers, you need to print the strings in their original order.
Hence, your sorting algorithm should be stable, i.e. the original order should be maintained for equal elements.
Insertion Sort and the simple version of Quicksort were stable, but the faster in-place version of Quicksort was not
(since it scrambled around elements while sorting). In cases where you care about the original order, it is important
to use a stable sorting algorithm. In this challenge, you will use counting sort to sort a list while keeping the order
of the strings (with the accompanying integer) preserved.
Challenge
In the previous challenge, you created a "helper array" that contains information about the starting position of each element
in a sorted array. Can you use this array to help you create a sorted array of the original list?
Hint: You can go through the original array to access the strings. You can then use your helper array to help determine where
to place those strings in the sorted array. Be careful about being one off.
Details and a Twist
You will be given a list that contains both integers and strings. Can you print the strings in order of their accompanying integers?
If the integers for two strings are equal, ensure that they are print in the order they appeared in the original list.
The Twist - Your clients just called with an update. They don't want you to print the first half of the original array.
Instead, they want you to print a dash for any element from the first half.
Input Format
- n, the size of the list ar.
- n lines follow, each containing an integer x and a string s.
Output Format
Print the strings in their correct order.
Constraints
1 <= n < 10000000
n is even
1 <= length(s) <= 10
0 <= x < 100, x E ar 
The characters in every string in lowercase.
*/
#include <iostream>
#include <string.h>
using namespace std;
 
struct Data {
	int key;
	char str[10];
};

Data input[10000000];
Data sorted[10000000];
int countArr[100] = { 0 };

// Runs counting sort algorithm
void countSort(int n) {
	// First step is, of course, count ocurrences.
	for (int i = 0; i < n; i++) {
		countArr[input[i].key]++;
	}

	// Copy to sorted array based on the number of ocurrences.
	int sortedPos = 0;
	for (int j = 0; j < 100; j++) {
		int ocurrences = countArr[j];
		if (ocurrences != 0) {
			// At least one ocurrence, search in the unsorted array and copy over.
			for (int i = 0; i < n && ocurrences > 0; i++) {
				if (input[i].key == j) {
					sorted[sortedPos].key = input[i].key;
					if (i < n/2) {
						// Skip first half of the original array.
						memcpy(sorted[sortedPos].str, "-", 1);
					}
					else {
						memcpy(sorted[sortedPos].str, input[i].str, 10);
					}
					ocurrences--;
					sortedPos++;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i].key;
		cin >> input[i].str;
	}

	countSort(n);

	// output
	for (int i = 0; i < n; i++) {
		cout << sorted[i].str << " ";
	}
	cout << endl;
}