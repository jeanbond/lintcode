
using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
		vector<vector<int>> ret;
		/* 两种特殊情况处理 */
		if (nums.empty() && ret.empty()) {
			ret.push_back(nums);
			return ret;
		}
		if (nums.empty()) return ret;

		permut(nums, 0, ret);
		show(ret);

		return ret;
    }

	/* 这个地方要特别注意：
		1、in作为入参的时候，在非重复的全排列中，必须使用引用传递参数，不能使用传值传递参数。
		2、在重复全排列中，必须使用传值，不能使用引用传递，避免交换之后获得和原来一样的队列。
			为何在重复全排列中必须使用传值：在函数内部没有重复元素判断（为了提高效率），所以采用
										 值传递，在每一个上层递归结束后，能保证下次传递进入的数据是原始数据。
										 这样一来就保证了在每次递归的下级递归中使用的数据都是一致的。
										 思路2： 也可以使用引用传递，这样需要在函数内部加入重复判断，如此一来
										 函数的时间复杂度就增大了。*/
	int permut(vector<int> in, int start, vector<vector<int>> &out){
		if (start == in.size() ){
			out.push_back(in);
			return 0;
		}
		for (int i = start; i < in.size(); i++) {
			if (i == start || in[start] != in[i]) {
				/* 只交换一次的前提是：in 参数必须是值传递，如果是引用传递，就必须交换回去，
					同时在最后推入数组的时候必须去重。
					两次交换和去重判断操作相关的代码已经测试过，函数功能实现没问题，但是时间
					复杂度增加，不能通过lintcode测试。
					结论：为了通过lintcode 必须使用值传递 */
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
	/* 该函数借鉴STL中的next_permutation函数的思路，大致如下：
		1、从后向前找一对【小、大】的序列位置，标记该元素为T，T元素的位置为k 。
		2、如果k为-1，表示next_permutation已经执行完了一个周期，需要将整个
		队列反序，同时将该序列输出，便于下次的next_permutation。
		3、如果T元素的位置为非-1，那么从最后依次找一个大于该位置的元素，同时命名为T1。一定能找到，因为采用的是升序排列。
		4、将T和T1交换位置。
		5、最后将T后面的所有元素反序，构成一个降序排列，便于下次next_permutation。 */
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