/* 
In this challenge, you must first implement a queue using two stacks. Then process q queries, where each
query is one of the following 3 types:
1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
*/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {

public:
	stack<int> stack_newest_on_top, stack_oldest_on_top;
	void push(int x) {
		// Push Stack - keep the newest on top,
		// only copy over to the other stack when necessary.
		stack_newest_on_top.push(x);
	}

	void pop() {
		// To perform one pop operation, copy over the contents
		// from the newest stack to the oldest one.
		
		// First check if the oldest_on_top is empty. If it is not,
		// pop from the stack.
		if (!stack_oldest_on_top.empty()) {
			stack_oldest_on_top.pop();
		}
		else {
			// Oldest stack is empty, so bring the data from the push stack.
			while (!stack_newest_on_top.empty()) {
				int temp = stack_newest_on_top.top();
				stack_newest_on_top.pop();
				stack_oldest_on_top.push(temp);
			}
			// Now pop the oldest.
			stack_oldest_on_top.pop();
		}
	}

	int front() {
		// To perform one front operation, copy over the contents
		// from the newest stack to the oldest one.

		// First check if the oldest_on_top is empty. If it is not,
		// return from the stack.
		int ret = 0;
		if (!stack_oldest_on_top.empty()) {
			ret = stack_oldest_on_top.top();
		}
		else {
			// Oldest stack is empty, so bring the data from the push stack.
			while (!stack_newest_on_top.empty()) {
				int temp = stack_newest_on_top.top();
				stack_newest_on_top.pop();
				stack_oldest_on_top.push(temp);
			}
			// Now return the oldest.
			ret = stack_oldest_on_top.top();
		}
		return ret;
	}


};

int main() {
	MyQueue q1;
	int q, type, x;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			q1.push(x);
		}
		else if (type == 2) {
			q1.pop();
		}
		else cout << q1.front() << endl;
	}
	return 0;
}
