
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
	/* ����˼·����subsets���̣��˹��̽�����ظ�Ԫ�ص����⣬��������Լ��Ľ���˼·�ο���һ��subset���� */
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		vector<vector<int>> ret(1);
		sort(nums.begin(), nums.end());
		if (nums.empty()) { return ret; }

		for (int i = 0, cnt = 0; i < nums.size(); i++) {
			int size = ret.size();
			for (int j = 0; j < size; j++) {
				/* 3���������ʼԪ�أ�iΪ0���м�Ԫ�أ��໥�Ƚϣ�����ǰԪ�ؼ��뵽���λ�ã����λ������� */
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