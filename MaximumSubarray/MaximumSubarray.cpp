
using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/
	int maxSubArray(vector<int> &nums) {
		// write your code here
		int ans = -1111111;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum > ans) {
				ans = sum;
			}
			if (sum < 0) {
				sum = 0;
			}
		}
		return ans;
	}
};

int main() {
	return 0;
}