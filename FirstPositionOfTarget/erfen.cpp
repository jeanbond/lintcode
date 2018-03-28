
using namespace std;

#include<vector>

class Solution {
public:
	/**
	* @param nums: The integer array.
	* @param target: Target to find.
	* @return: The first position of target. Position starts from 0.
	*/
	int binarySearch(vector<int> &nums, int target) {
		// write your code here
		int low = 0, high = nums.size()-1 , mid = 0;
		mid = (low + high) / 2;

		//�����жϣ��ų��쳣
		while (mid >= 0 && low >= 0 && low < nums.size() && high >= 0 && high < nums.size()) {
			if (nums[mid] == target) { 
				break;
			}
			else if (nums[mid] < target) {
				//�ų�����ѭ��
				if (low != mid) { low = mid; }
				else { return -1; }
			}
			else {
				//�ų�����ѭ��
				if (high != mid) { high = mid; }
				else { return -1; }
			}
			mid = (low + high) / 2;
		}
		if (mid == 0) { return mid; }
		else {
			//�ų�ǰ��������ͬ��
			while (mid > 0) {
				if (nums[mid-1] == target) { mid--; }
				else { return mid; }
			}
		}
		
		return -1;
	}
};

int main() {
	Solution s = Solution();
	vector<int> in = { 2,6,8,13,15,17,17,18,19,20 };
	s.binarySearch(in, 15);
	return 0;
}