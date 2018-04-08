using namespace std;

#include<vector>
#include<time.h>

class Solution {
public:
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		vector<vector<int>> out;
		//考虑使用递归方法，将递归函数独立出来
		permut(nums, nums.size(), 0, out);
		return out;
	}

private:
	/* --------------------------------------------------------------------------------
	采用倒排递归：
		考虑从0开始进行全排列，我们依次选取N个元素（N为最大元素的个数），这样我们必须假设最开始
		的数据顺序是固定的，我们必须基于这个固定的顺序上进行选取，否则会混乱。第一次选取第一个，
		第二次选取第二个... ... 以此类推，我们能一直选取到最后一个元素：所以递归中退出的条件为：
		当前选取元素的下标为最后一个元素，我们就退出，将当前序列记录下来，就是我们该次的全排列。
		那么考虑中间的任何一个情况，既有：假设这个元素是当前第M个元素（M<=N），第M个元素必须要、
		做的是事情分为：1）他需要和后面未构成全排列内容的元素进行位置互换，构成新的可能性。在每、
		一种可能性里面，需要对M+1个元素进行全排列（递归）,针对第M个元素做完了交换和M+1的全排列
		之后，我们需要将改元素和原来交换的元素恢复回来，也就是重新交换，这样能保证列表的顺序，
		因为我们的排列的最基本的条件之一就是该序列表顺序是给定的。一次类推，全排列就出来了。
		-------------------------------------------------------------------------------
		将数组分成两个部分，0-start部分位已经选择好的区间，start-end为待选择的区间
		每次从待选择的区间选择一个加入，然后递归下一个回合；
		
	-----------------------------------------------------------------------------------*/
	int permut(vector<int> &in, int size, int start, vector<vector<int>> &out) {
		if (size <= start) {
			out.push_back(in);
			return 0;
		}

		//核心区块
		for (int i = start; i < size; i++) {
			swap(in[i], in[start]);// 这个交换是为了获取新数据
			permut(in, size, start + 1, out);
			swap(in[i], in[start]);// 这个交换是为了恢复到原来的数据序列，因为我们的前提是数据序列是固定的，
								   // 在固定的顺序基础上得到不同的排列过。
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


