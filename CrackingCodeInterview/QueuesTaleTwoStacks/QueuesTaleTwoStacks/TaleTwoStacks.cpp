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
		stack_newest_on_top.push(x);
		while (!stack_oldest_on_top.empty()) {
			int temp = stack_oldest_on_top.top();
			stack_oldest_on_top.pop();
			stack_newest_on_top.push(temp);
		}
		while (!stack_newest_on_top.empty()) {
			int temp = stack_newest_on_top.top();
			stack_newest_on_top.pop();
			stack_oldest_on_top.push(temp); 
		}
	}

	void pop() {
		stack_oldest_on_top.pop();
	}

	int front() {
		return stack_oldest_on_top.top();
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
