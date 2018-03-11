/*
A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
Complete the function provided in the editor below. It has one parameter: a pointer to a Node object named head
that points to the head of a linked list. Your function must return a boolean denoting whether or not there is a cycle in the list.
If there is a cycle, return true; otherwise, return false.

Note: If the list is empty, head will be null.
*/
#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};


bool has_cycle(Node* head) {
	// Complete this function
	// Do not write the main method
	int nodeCount = 0;
	Node* listPtr = head;
	while (listPtr != NULL && listPtr->next != NULL) {
		nodeCount++;
		if (nodeCount > 100) {
			return true; // cycle found
		}
		listPtr = listPtr->next;
	}
	return false;
}

int main() {
	Node* head = new Node();
	Node* first = new Node();
	Node* second = new Node();
	head->next = first;
	first->next = second;
	second->next = NULL;

	if (has_cycle(head)) {
		cout << "Has Cycle" << endl;
	}
	else {
		cout << "Does not have a Cycle" << endl;
	}
}