
using namespace std;

#include<vector>
#include<algorithm>

/* ʵ�ַ��ظ����ϵ������Ӽ���⣬���ǲ��������ַ������ݹ�˼·�ͷǵݹ�˼·��������⡣ 
	�ݹ�˼·д���򵥣����ǿռ临�Ӷȸߣ����������ջ�ռ����
	�ǵݹ�˼·�򵥣�����˼·�Ƚ��Ѷ� */

class Solution {

		/* �ǵݹ�˼·���£�
			1����ÿ��Ԫ�أ�����ֻ��Ҫ�����ֱ���뵽��ǰ�Ѿ����ڵ�ÿ���Ӽ��м��ɣ�
			2��������Ӽ�������Ҫ��������Ҫ���ʼ�Գ�ʼԪ���������������֤�����Ӽ�Ԫ�ص�˳��
			*/
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret(1);
		if (nums.empty()) { return ret; }

		for (int i = 0; i < nums.size(); i++) {
			int size = ret.size();
			for (int j = 0; j < size; j++) {
				ret.push_back(ret[j]);
				ret.back().push_back(nums[i]);
			}
		}
		return ret;
	}

};


class Solution1 {
	/* �ݹ�˼·�У�����˼·���£�
	1��һ������£�����ѡȡδ�����Ӽ���һ��Ԫ�أ���Ԫ��ֻ�к��Ѿ��������Ӽ�ֻ��������� a�� Ҫô������Ӽ��� b��Ҫô��������Ӽ���
	2��һ�λ�õݹ�˼·���Ե�ǰ����Ԫ��ִ�����²�����
	ѡȡһ��Ԫ�أ������ʼλ�úͽ���λ����ͬ����ʾ�ݹ����������û���ܽ�һ����ȡ��Ԫ�ء�
	��ÿ��Ԫ�غ�ÿ���Ѿ��������Լ�������Ͳ��������ֲ�����
	�ֱ���Լ���Ͳ�����֮��ִ�п�ʼλ����ǰ����1�ĵݹ������
	3�����������ܻ��ȫ�����Ӽ��������ռ���
	4����Ҫ���Ӽ��е�Ԫ����˳�����еģ�������Ҫ���ʼ����ʼԪ�ص����������*/
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		vector<vector<int>> ret;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		if (nums.empty()) { ret.push_back(tmp); return ret; }

		subsetF(nums, ret, tmp, 0, nums.size());
		return ret;
	}

private:

	int subsetF(vector<int> &in, vector<vector<int>> &out, vector<int> &tmp, int start, int end) {
		if (in.empty()) { return 0; }

		if (start == end) { out.push_back(tmp); return 0; }

		tmp.push_back(in[start]);
		subsetF(in, out, tmp, start + 1, end);
		tmp.pop_back();
		subsetF(in, out, tmp, start + 1, end);
		return 0;
	}
};

int main() {
	Solution s = Solution();
	vector<int> in = {0};
	s.subsets(in);
	system("pauze");
	return 0;
}