#include <iostream>
#include <deque>
#include <list>
#include <queue>
#include <stack>
using namespace std;

void reverseSwS(stack<int> &c) {
	stack<int> s;
	stack<int> *temp;

	// put reverse into temp, delete entries of c
	while (!c.empty()) {
		s.push(c.top());
		c.pop();
	}

	temp = &c; // copies pointer to current c stack

	c = s; // c points to the new stack s

	s = *temp; // makes s point to where c used to point.

	// O(n) function
}

void reverseQwS(queue<int> &c) {
    stack<int> temp;

	// copies to the stack, which reverses order, and deletes items until empty
	while (!c.empty()) {
		temp.push(c.front());
		c.pop();
	}

	// puts reversed order into the queue
	while (!temp.empty()) {
		c.push(temp.top());
		temp.pop();
	}

	// O(n) function
}

int main() {
	
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	reverseSwS(s); // reverse the elements in s using only stacks
	
	// Print the stack
	while (!s.empty()) {
    		cout << s.top() << " " << endl;
    		s.pop();
	}
	

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);  
 
	reverseQwS(q); // reverse elements in q using a stack
 
	// Print the queue
	while (!q.empty()) {
    		cout << q.front() << " " << endl;
    		q.pop();
	}

	return 0;
}
