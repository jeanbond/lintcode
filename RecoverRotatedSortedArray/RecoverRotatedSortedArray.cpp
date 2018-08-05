
using namespace std;
#include<iostream>
#include<vector>


class Solution {
public: 
	// split two area;
    void recoverRotatedSortedArray(vector<int> &nums) {
		vector<int> out;
		if (nums.size() <= 0) return;		
		// find split location
		unsigned int l = 1;
		while (l < nums.size()) {
			if (nums[l] < nums[0]) break;
			l++;
		}
		int si = 0;
		while (si < nums.size() ) {
			out.push_back(nums[l%nums.size()]);
			si++;
			l++;
		}
		si = 0;
		nums.clear();
		while (si < out.size()) {
			nums.push_back(out[si]);
			si++;
		}
		return;
    }
};

int main() {
	Solution s = Solution();
	vector<int> st = { 4,5,1,2,3 };
	s.recoverRotatedSortedArray(st);
	return 1;
}