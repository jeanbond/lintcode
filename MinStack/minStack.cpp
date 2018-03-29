
using namespace std;

#include<stack>

class MinStack {
private:
	stack<int> dataStack;
	stack<int> minStack;
public:
	MinStack() {
		// do intialization if necessary
	}

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number) {
		// write your code here
		dataStack.push(number);

		if (minStack.empty() || number <= minStack.top()) {
			minStack.push(number);
		}
		else {
			minStack.push(minStack.top());
		}
		return;
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		int tmp = dataStack.top();
		dataStack.pop();		
		minStack.pop();
		return tmp;
	}

	/*
	* @return: An integer
	*/
	int min() {
		// write your code here
		return minStack.top();
	}
};

int main() {
	MinStack m = MinStack();
	m.push(-1);
	m.push(-2);
	m.min();
	m.pop();
	m.push(-3);
	m.push(3);
	m.push(2);
	m.pop();
	m.pop();
	m.pop();
	m.pop();
	m.push(400);
	m.push(3);
	m.push(200);
	m.push(1);
	m.min();
	m.pop();
	m.min();
	return 0;
}