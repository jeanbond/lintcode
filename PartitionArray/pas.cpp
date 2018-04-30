
using namespace std;

#include<vector>

class Solution {
public:
	int partitionArray(vector<int> &nums, int k) {
		return partion(nums,k,0,nums.size()-1);
	}

private:
	int partion(vector<int> &in, int k, int low, int high) {
		if (in.empty()) { return 0; }
		while (low < high) {
			/* 解决：当首位的元素相同的时候，陷入无限死循环；*/
			if (in[low] == in[high] && in[low] == k) { high--; }
			while (low < high && in[high] > k) high--;
			while (low < high && in[low] < k) low++;
			swap(in[low], in[high]);
		}

		if (in[low] < k) 
		{ low++; }
		return low;
	}
};

int main() {
	Solution s = Solution();
	vector<int> in = { 9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9 };
	s.partitionArray(in, 9);

	system("pause");
	return 0;
}