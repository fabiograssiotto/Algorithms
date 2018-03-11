/*
For the purposes of this challenge, we define a binary search tree to be a binary tree with the following ordering properties:

The data value of every node in a node's left subtree is less than the data value of that node.
The data value of every node in a node's right subtree is greater than the data value of that node.
Given the root node of a binary tree, can you determine if it's also a binary search tree?

Complete the function in your editor below, which has  parameter: a pointer to the root of a binary tree.
It must return a boolean denoting whether or not the binary tree is a binary search tree. 
You may have to write one or more helper functions to complete this challenge.
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};


bool checkBST(Node* root) {

	static Node* prevNode = NULL;

	if (root != NULL) {

		if (!checkBST(root->left)) {
			return false;
		}
		
		if (prevNode != NULL && root->data <= prevNode->data) {
			return false;
		}

		prevNode = root;

		return checkBST(root->right);
	}
	return true;
}




int main() {
	// Read in Tree from input.
	int n;
	cin >> n; // Number of nodes.
	int* nodes = new int[n];
	
	
	for (int i = 0; i < n; i++) {
		cin >> nodes[i];
	}

	// Create tree structure, hardcoded.
	Node* root = new Node();
	root->data = nodes[3];
	Node* left1 = new Node();
	Node* right1 = new Node();
	left1->data = nodes[1];
	right1->data = nodes[5];
	root->left = left1;
	root->right = right1;
	
	Node* left2 = new Node();
	Node* right2 = new Node();
	Node* left3 = new Node();
	Node* right3 = new Node();
	left2->data = nodes[0];
	right2->data = nodes[2];
	left3->data = nodes[4];
	right3->data = nodes[6];
	left1->left = left2;
	left1->right = right2;
	right1->left = left3;
	right1->right = right3;
	left2->left = NULL;
	left2->right = NULL;
	right2->left = NULL;
	right2->right = NULL;
	left3->left = NULL;
	left3->right = NULL;
	right3->left = NULL;
	right3->right = NULL;

	if (checkBST(root)) {
		cout << "BST OK" << endl;
	}
	else {
		cout << "BST NOK" << endl;
	}
}