
using namespace std;

#include<vector>
#include<algorithm>

/* 实现非重复集合的所有子集求解，我们采用了两种方法：递归思路和非递归思路，下面详解。 
	递归思路写法简单，但是空间复杂度高，很容易造成栈空间溢出
	非递归思路简单，但是思路比较难懂 */

class Solution {

		/* 非递归思路如下：
			1、对每个元素，我们只需要将他分别加入到当前已经存在的每个子集中即可；
			2、如果对子集有特殊要求，我们需要在最开始对初始元素做排序操作，保证最后的子集元素的顺序；
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
	/* 递归思路中，基本思路如下：
	1、一般情况下，我们选取未加入子集的一个元素，该元素只有和已经成立的子集只有两种情况 a） 要么加入该子集。 b）要么不加入该子集。
	2、一次获得递归思路：对当前所的元素执行如下操作：
	选取一个元素，如果开始位置和结束位置形同，表示递归结束，我们没有能进一步可取的元素。
	对每个元素和每个已经产生的自己做加入和不加入两种操作；
	分别针对加入和不加入之后，执行开始位置向前步进1的递归操作；
	3、最终我们能活的全部的子集，包含空集；
	4、若要求子集中的元素是顺序排列的，我们需要在最开始做初始元素的排序操作；*/
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