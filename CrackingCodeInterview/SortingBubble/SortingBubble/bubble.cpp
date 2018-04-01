/*
Given an n-element array, A = a0, ... an-1, of distinct elements, sort array A in ascending order using the Bubble Sort algorithm above.
Once sorted, print the following three lines:

1. Array is sorted in numSwaps swaps., where numSwaps is the number of swaps that took place.
2. First Element: firstElement, where firstElement is the first element in the sorted array.
3. Last Element: lastElement, where lastElement is the last element in the sorted array.
*/
#include <iostream>
using namespace std;

int arr[600];

int main() {
	int numSwaps = 0;
	int i = 0, n;

	cin >> n;
	while (i < n) {
		cin >> arr[i];
		i++;
	}

	// Now run the bubble sort.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1]) {
				numSwaps++;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "Array is sorted in " << numSwaps << " swaps." << endl;
	cout << "First Element : " << arr[0] << endl;
	cout << "Last Element : " << arr[n - 1] << endl;
}