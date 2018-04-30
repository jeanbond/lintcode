
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
	/* 答题思路参照subsets工程，此工程解决带重复元素的问题，求解所有自己的解题思路参考上一个subset工程 */
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		vector<vector<int>> ret(1);
		sort(nums.begin(), nums.end());
		if (nums.empty()) { return ret; }

		for (int i = 0, cnt = 0; i < nums.size(); i++) {
			int size = ret.size();
			for (int j = 0; j < size; j++) {
				/* 3种情况：开始元素，i为0；中间元素，相互比较；将当前元素加入到最后位置，最后位置情况； */
				if (i == 0 || nums[i-1] != nums[i] || j >= cnt) {
					ret.push_back(ret[j]);
					ret.back().push_back(nums[i]);
				}
			}
			cnt = size;
		}
		return ret;
	}
};

int main() {
	Solution s = Solution();
	vector<int> in = {0,1};
	s.subsetsWithDup(in);
	system("pause");
	return 0;
}