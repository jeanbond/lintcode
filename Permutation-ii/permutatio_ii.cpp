
using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
		vector<vector<int>> ret;
		/* ��������������� */
		if (nums.empty() && ret.empty()) {
			ret.push_back(nums);
			return ret;
		}
		if (nums.empty()) return ret;

		permut(nums, 0, ret);
		show(ret);

		return ret;
    }

	/* ����ط�Ҫ�ر�ע�⣺
		1��in��Ϊ��ε�ʱ���ڷ��ظ���ȫ�����У�����ʹ�����ô��ݲ���������ʹ�ô�ֵ���ݲ�����
		2�����ظ�ȫ�����У�����ʹ�ô�ֵ������ʹ�����ô��ݣ����⽻��֮���ú�ԭ��һ���Ķ��С�
			Ϊ�����ظ�ȫ�����б���ʹ�ô�ֵ���ں����ڲ�û���ظ�Ԫ���жϣ�Ϊ�����Ч�ʣ������Բ���
										 ֵ���ݣ���ÿһ���ϲ�ݹ�������ܱ�֤�´δ��ݽ����������ԭʼ���ݡ�
										 ����һ���ͱ�֤����ÿ�εݹ���¼��ݹ���ʹ�õ����ݶ���һ�µġ�
										 ˼·2�� Ҳ����ʹ�����ô��ݣ�������Ҫ�ں����ڲ������ظ��жϣ����һ��
										 ������ʱ�临�ӶȾ������ˡ�*/
	int permut(vector<int> in, int start, vector<vector<int>> &out){
		if (start == in.size() ){
			out.push_back(in);
			return 0;
		}
		for (int i = start; i < in.size(); i++) {
			if (i == start || in[start] != in[i]) {
				/* ֻ����һ�ε�ǰ���ǣ�in ����������ֵ���ݣ���������ô��ݣ��ͱ��뽻����ȥ��
					ͬʱ��������������ʱ�����ȥ�ء�
					���ν�����ȥ���жϲ�����صĴ����Ѿ����Թ�����������ʵ��û���⣬����ʱ��
					���Ӷ����ӣ�����ͨ��lintcode���ԡ�
					���ۣ�Ϊ��ͨ��lintcode ����ʹ��ֵ���� */
				swap(in[start], in[i]);
				permut(in, start + 1, out);
			}
		}
		return 0;
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



class Solution1 {
public:
	vector<vector<int> > permuteUnique(vector<int> &nums) {
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
	/* �ú������STL�е�next_permutation������˼·���������£�
		1���Ӻ���ǰ��һ�ԡ�С���󡿵�����λ�ã���Ǹ�Ԫ��ΪT��TԪ�ص�λ��Ϊk ��
		2�����kΪ-1����ʾnext_permutation�Ѿ�ִ������һ�����ڣ���Ҫ������
		���з���ͬʱ������������������´ε�next_permutation��
		3�����TԪ�ص�λ��Ϊ��-1����ô�����������һ�����ڸ�λ�õ�Ԫ�أ�ͬʱ����ΪT1��һ�����ҵ�����Ϊ���õ����������С�
		4����T��T1����λ�á�
		5�����T���������Ԫ�ط��򣬹���һ���������У������´�next_permutation�� */
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


int main() {
	Solution1 s = Solution1();
	vector<int> in = { 1,2,2 };
	s.permuteUnique(in);
	system("pause");
	return 0;
}