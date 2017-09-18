/* https://www.hackerrank.com/challenges/find-the-median
In the Quicksort challenges, you sorted an entire array. Sometimes, you just need specific information
about a list of numbers, and doing a full sort would be unnecessary. Can you figure out a way to use 
your partition code to find the median in an array?
Challenge
Given a list of numbers, can you find the median?
Input Format
There will be two lines of input:
- n the size of the array
- an numbers that makes up the array
Output Format
Output one integer, the median.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int MAXSIZE = 1000001;
int arr[MAXSIZE] = { 0 };

// Takes data, array source, size of array, position to find.
int findMedian(int* data, int arrSz, int k) {
	// Use the selection algorithm.
	
	// To cover the case where the median is repeated - check input array for all duplicates.
	int dup = data[0];
	bool isDup = true;
	for (int i = 0; i < arrSz; i++) {
		if (data[i] != dup) {
			isDup = false;
			break;
		}
	}

	if (arrSz == 1 || isDup) {
		return data[0];
	}

	int median = 0;
	int pivot = rand() % arrSz;
	int candidate = data[pivot];

	// Now split the array based on the pivot position.
	int i = 0;
	int* leftArr = new int[arrSz];
	int* rightArr = new int[arrSz];

	int leftSz = 0, rightSz = 0;
	while (i < arrSz) {
		if (candidate > data[i]) {
			leftArr[leftSz] = data[i];
			leftSz++;
		}
		else if (candidate <= data[i]) {
			rightArr[rightSz] = data[i];
			rightSz++;
		}
		i++;
	}

	if (leftSz == k) {
		median = candidate;
	}
	else if (leftSz > k) {
		// Recursively find the median on the left-side array
		median = findMedian(leftArr, leftSz, k);
	}
	else { // left > right
		// Recursively find the median on the right-side array
		median = findMedian(rightArr, rightSz, k - leftSz);
	}
	
	delete[] leftArr;
	delete[] rightArr;

	return median;
}

int main() {
	clock_t start = clock();
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// Median is at n/2 position in a sorted array.
	cout << findMedian(arr, n, n/2) << endl;
	cout << "Time:" << (float)(clock() - start) / CLOCKS_PER_SEC << " seconds." << endl;
	return 0;
}