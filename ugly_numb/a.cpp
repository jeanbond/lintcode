
using namespace std;

#include<stdio.h>
#include<vector>

class Solution {
public:
	/**
	* @param n: An integer
	* @return: the nth prime number as description.
	*/
	//to store all ugly number
	vector<int> allUglyNum = { 1 };
	//which base number to calc
	vector<int> baseUg = {2,3,5};

	int nthUglyNumber(int n) {
		// write your code here
		while (true) {
			if (allUglyNum.size() >= n) { return allUglyNum[n]; }

			for (int i = 0; i < allUglyNum.size(); i++) {
				for (int j = 0; j < baseUg.size(); j++) {
					if (!isExsit(allUglyNum, baseUg[j] * allUglyNum[i])) {
						allUglyNum.push_back(baseUg[j] * allUglyNum[i]);
						if (allUglyNum.size() >= n) { return allUglyNum[n]; }
					}
				}

			}
		}
	}

	bool isExsit(vector<int> set, int ss) {
		for (vector<int>::iterator i = set.begin();
			i != set.end(); i++) {
			if (*i == ss) { return true; }
		}
		return false;
	}
};

int main() {
	Solution s = Solution();
	s.nthUglyNumber(9);
	return 0;
}