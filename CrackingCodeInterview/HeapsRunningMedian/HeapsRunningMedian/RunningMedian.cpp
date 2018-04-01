/*
The median of a dataset of integers is the midpoint value of the dataset for which an equal number of integers are less than and greater than the value.
To find the median, you must first sort your dataset of integers in non-decreasing order, then:

If your dataset contains an odd number of elements, the median is the middle element of the sorted sample. In the sorted dataset {1,2,3}, 2 is the median.
If your dataset contains an even number of elements, the median is the average of the two middle elements of the sorted sample.
In the sorted dataset {1, 2, 3, 4}, 2.5 is the median.
Given an input stream of n integers, you must perform the following task for each ith integer:

Add the ith integer to a running list of integers.
Find the median of the updated list (i.e., for the first element through the ith element).
Print the list's updated median on a new line. The printed value must be a double-precision number scaled to 1 decimal place (i.e., 12.3 format).
*/
#include <iostream>
using namespace std;

int minHeap[100001];
int maxHeap[100001];
int minHeapNumEls = 0;
int maxHeapNumEls = 0;
float median = 0;

void initHeaps() {
	for (int i = 0; i <= 100000; i++) {
		minHeap[i] = -1;
		maxHeap[i] = -1;
	}
}

void insertToMinHeap(int element) {
	// First insert at the end 
	int idx = minHeapNumEls + 1;
	minHeap[idx] = element;
	minHeapNumEls++;

	// Now bubble up.
	if (idx != 1) {
		// It is not an empty heap
		// Check if the parent is greater than the current element, and if it is, swap.
		while (idx != 1) {
			int parent = idx / 2;
			if (minHeap[parent] > minHeap[idx]) {
				int temp = minHeap[parent];
				minHeap[parent] = minHeap[idx];
				minHeap[idx] = temp;
				idx = parent;
			}
			else {
				break;
			}
		}
	}
}

void insertToMaxHeap(int element) {
	// First insert at the end 
	int idx = maxHeapNumEls + 1;
	maxHeap[idx] = element;
	maxHeapNumEls++;

	// Now bubble up.
	if (idx != 1) {
		// It is not an empty heap
		// Check if the parent is greater than the current element, and if it is, swap.
		while (idx != 1) {
			int parent = idx / 2;
			if (maxHeap[parent] == -1) {
				break;
			}
			if (maxHeap[parent] < maxHeap[idx]) {
				int temp = maxHeap[parent];
				maxHeap[parent] = maxHeap[idx];
				maxHeap[idx] = temp;
				idx = parent;
			}
			else {
				break;
			}
		}
	}
}


void moveMinToMax() {
	int min = minHeap[1];
	insertToMaxHeap(min);

	// Now fix the minHeap, using siftdown procedure.
	minHeap[1] = minHeap[minHeapNumEls];
	minHeap[minHeapNumEls] = -1;
	minHeapNumEls--;
	int idx = 1;
	while (idx < minHeapNumEls) {
		int child1 = idx * 2;
		int child2 = (idx * 2) + 1;

		// Pick child to compare
		int chosen;
		if (minHeap[child1] == -1 && minHeap[child2] == -1) {
			break;
		}
		else if (minHeap[child1] == -1 && minHeap[child2] != -1) {
			chosen = child2;
		}
		else if (minHeap[child1] != -1 && minHeap[child2] == -1) {
			chosen = child1;
		}
		else if (minHeap[child1] < minHeap[child2] && minHeap[child1] != -1) {
			chosen = child1;
		}
		else {
			chosen = child2;
		}
		
		if (minHeap[chosen] < minHeap[idx]) {
			int temp = minHeap[chosen];
			minHeap[chosen] = minHeap[idx];
			minHeap[idx] = temp;
			idx = chosen;
		}
		else {
			break;
		}
	}
}

void moveMaxToMin() {
	int max = maxHeap[1];
	insertToMinHeap(max);


	// Now fix the maxHeap, using siftdown procedure.
	maxHeap[1] = maxHeap[maxHeapNumEls];
	maxHeap[maxHeapNumEls] = -1;
	maxHeapNumEls--;
	int idx = 1;
	while (idx < maxHeapNumEls) {
		int child1 = idx * 2;
		int child2 = (idx * 2) + 1;

		// Pick child to compare
		int chosen;
		if (maxHeap[child1] == -1 && maxHeap[child2] == -1) {
			break;
		}
		else if (maxHeap[child1] == -1 && maxHeap[child2] != -1) {
			chosen = child2;
		}
		else if (maxHeap[child1] != -1 && maxHeap[child2] == -1) {
			chosen = child1;
		}
		else if (maxHeap[child1] > maxHeap[child2] && maxHeap[child1] != -1) {
			chosen = child1;
		}
		else {
			chosen = child2;
		}

		if (maxHeap[chosen] > maxHeap[idx]) {
			int temp = maxHeap[chosen];
			maxHeap[chosen] = maxHeap[idx];
			maxHeap[idx] = temp;
			idx = chosen;
		}
		else {
			break;
		}
	}
}

float getMedian(int element) {
	if (element > median) {
		insertToMinHeap(element);
	}
	else {
		insertToMaxHeap(element);
	}

	// Rebalance if necessary.
	if (minHeapNumEls > maxHeapNumEls + 1) {
		moveMinToMax();
	}
	else if (maxHeapNumEls > minHeapNumEls + 1) {
		moveMaxToMin();
	}

	// Return the Median
	if (minHeapNumEls > maxHeapNumEls) {
		median = (float) minHeap[1];
	}
	else if (minHeapNumEls < maxHeapNumEls) {
		median = (float) maxHeap[1];
	}
	else {
		median = (((float) maxHeap[1] + (float) minHeap[1]) / 2);
	}
	return median;
}

int main() {
	int n;
	initHeaps();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		cout << fixed;
		cout.precision(1);
		cout << getMedian(element) << endl;
	}
}