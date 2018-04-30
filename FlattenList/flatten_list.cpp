
using namespace std;
#include<vector>

/* NestedInteger类由lintcode内部实现，所以在这里是不能调试的
	但是lintcode上面测试通过了。*/
class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer,
	// rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds,
	// if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds,
	// if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class Solution {
public:
	// @param nestedList a list of NestedInteger
	// @return a list of integer
	vector<int> flatten(vector<NestedInteger> &nestedList) {
		vector<int> ret;

		if (nestedList.empty()) { return ret; }
		
		flattenHelper(nestedList, ret);
		return ret;
	}

	int flattenHelper(const vector<NestedInteger> &nestedList, vector<int> &ret) {
		for (int i = 0; i < nestedList.size(); i++) {
			if (nestedList[i].isInteger()) {
				ret.push_back(nestedList[i].getInteger());
			}
			else {
				flattenHelper(nestedList[i].getList(), ret); // 递归思路解决，牺牲空间复杂度；
			}
		}
		return 0;
	}
};



int main() {
	return 0;
}