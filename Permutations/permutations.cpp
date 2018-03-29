using namespace std;

#include<vector>

class Solution {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		vector<vector<int>> out;
		permut(nums, nums.size(), 0, out);
		return out;
	}

private:
	int permut(vector<int> &in, int size, int n, vector<vector<int>> &out) {
		if (size <= n) {
			out.push_back(in);
			return 0;
		}

		for (int i = n; i < size; i++) {
			swap(in[i], in[n]);
			permut(in, size, n + 1, out);
			swap(in[i], in[n]);  // ¿¼ÂÇ¸ÃÓï¾äÊÇ·ñ¿ÉÒÔÉ¾³ıµô¡£
		}
		return 0;
	}

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
		return;
	}
};


int main() {
	Solution s = Solution();
	vector<int> in = {0,1};
	s.permute(in);
	return 0;
}


