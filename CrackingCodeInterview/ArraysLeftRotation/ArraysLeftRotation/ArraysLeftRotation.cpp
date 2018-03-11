/*
Given an array of n integers and a number, d, perform d left rotations on the array.
Then print the updated array as a single line of space-separated integers.*/
#include <iostream>
using namespace std;

int main() {
	int n, d;
	int array[100000]; // allocate at max size
	cin >> n; // Array size
	cin >> d; // Number of left rotations

	// Read-in array, set array[0] for rotating.
	for (int i = 0; i <= n; i++) {
		cin >> array[i];
	}

	// Instead of rotating, define an index to the leftmost array element
	// and 'walk' that index to the right for the new initial position of the array.
	int newIndex = d;

	// Output rotated array, starting from the newIndex.
	for (int i = newIndex; i < n; i++) {
		cout << array[i] << " ";
	}
	// Now output from the initial position to the new index.
	for (int i = 0; i < newIndex; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}