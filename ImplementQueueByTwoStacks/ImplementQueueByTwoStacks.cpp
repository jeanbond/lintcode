
using namespace std;
#include<iostream>
#include<stack>


class MyQueue {
public:
	stack<int> s1, s2;
	MyQueue() {
		// do intialization if necessary
	}

	/*
	* @param element: An integer
	* @return: nothing
	*/
	void push(int element) {
		// write your code here
		while (!s2.empty()) { 
			s1.push(s2.top());
			s2.pop();
		};
		s1.push(element);
		return;
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		int out = s2.top();
		s2.pop();
		return out;
	}

	/*
	* @return: An integer
	*/
	int top() {
		// write your code here
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		int out = s2.top();
		return out;
	}
};

int main() {
	
	return 0;
}