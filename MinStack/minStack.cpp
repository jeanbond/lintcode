
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
		dataStack.pop();
		int tmp = minStack.top();
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
	return 0;
}