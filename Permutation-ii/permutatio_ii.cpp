
using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		permut(nums, 0, nums.size(), ret);
		show(ret);
		return ret;
    }

	int permut(vector<int> &in, int start, int end, vector<vector<int>> &out){
		if (start == end ){
			if (!isExistedList(out, in)) {
				out.push_back(in);
				return 0;
			}
		}
		for (int i = start; i < end; i++) {
			if (i != start && in[start] == in[i]) { continue; }
			swap(in[start], in[i]);
			permut(in, start + 1, end, out);
			//swap(in[start], in[i]);
		}
		return 0;
	}

	int swap(int &a, int &b) {
		int c = a;
		a = b;
		b = c;
		return 0;
	}

	bool isExistedList(vector<vector<int>> src, vector<int> val) {
		int i, j;
		if (src.empty()) { return false; }
		if (val.empty()) { return true; }
		
		
		for (i = 0; i < (int)src.size(); i++) {
			if (src[i].size() != val.size()) { continue; }
			for (j = 0; j < (int)src[i].size(); j++) {
				if (src[i][j] != val[j]) { break; }
			}
			if (j == val.size()) { return true; }
		}
		return false;
	}
	void show(vector<vector<int>> in) {
		cout << "The total count is : " << in.size() << endl;
		for (int i = 0; i < (int)in.size(); i++) {
			for (int j = 0; j < (int)in[i].size(); j++) {
				cout << in[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Solution s = Solution();
	vector<int> in = { -1,2,-1,2,1,-1,2,1 };
	s.permuteUnique(in);
	system("pause");
	return 0;
}

class Solution1 {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of unique permutations.
	*/
	vector<vector<int> > permuteUnique(vector<int> &nums) {
		// write your code here
		vector<vector<int> > permutations;
		if (nums.empty() && permutations.empty()) {
			permutations.push_back(nums);
			return permutations;
		}
		if (nums.empty()) return permutations;
		vector<int> copy(nums.begin(), nums.end());
		nextPermutation(nums);
		permutations.push_back(nums);
		while (nums != copy) {
			nextPermutation(nums);
			permutations.push_back(nums);
		}
		return permutations;
	}
private:
	void nextPermutation(vector<int>& nums) {
		int k = -1, n = nums.size();
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				k = i;
				break;
			}
		}
		if (k == -1) {
			reverse(nums.begin(), nums.end());
			return;
		}
		int l;
		for (int i = n - 1; i > k; i--) {
			if (nums[i] > nums[k]) {
				l = i;
				break;
			}
		}
		swap(nums[l], nums[k]);
		reverse(nums.begin() + k + 1, nums.end());
	}
};

class Solution2 {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of unique permutations.
	*/
	vector<vector<int> > permuteUnique(vector<int> &nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		vector<vector<int> > permutations;
		if (nums.empty() && permutations.empty()) {
			permutations.push_back(nums);
			return permutations;
		}
		if (nums.empty()) return permutations;
		permutate(nums, 0, permutations);
		return permutations;
	}
private:
	void permutate(vector<int> nums, int start, vector<vector<int> >& permutations) {
		if (start == nums.size()) {
			permutations.push_back(nums);
			return;
		}
		for (int i = start; i < (int)nums.size(); i++) {
			if (i == start || nums[i] != nums[start]) {
				swap(nums[start], nums[i]);
				permutate(nums, start + 1, permutations);
			}
		}
	}
};