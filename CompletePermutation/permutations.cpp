using namespace std;

#include<vector>
#include<iostream>

class Solution {
private:
	vector<int> tmp;

public:
	void show(vector<vector<int>> in) {
		cout << "The total count is : " << in.size() << endl;
		for (int i = 0; i < (int)in.size(); i++) {
			for (int j = 0; j < (int)in[i].size(); j++) {
				cout << in[i][j] << " ";
			}
			cout << endl;
		}
	}	

	int completePermut(vector<int> &in, int cnt, int total) {
		/* 过程中两个函数的参数详细解释：
		   combination(vector<int> &in, int cnt, int total, vector<vector<int>> &out)中
				 cnt是选取的最终个数，total是被选择序列的个数，他们均不能为0，最小为1，因为
				 数据选取个数不能为0，只能从1开始计数。
		   permut(vector<int> &in, int start,  int end, vector<vector<int>> &out)
				 全排列函数中：start位置从0开始（可以修改函数从1开始），
				 end表示的是结束位置（从0计数的结束位置）。
		   两个函数参数差别大，使用的时候请注意，多有不便。 */
		vector<vector<int>> comRet;
		vector<vector<int>> ret;
		/* 先从序列中找到所有组合 */
		combination(in, cnt, total,comRet);
		for (int i = 0; i < comRet.size(); i++) {
			/* 然后针对每个组合做全排列 */
			vector<int> it = comRet[i];
			permut(it, 0, it.size(), ret);
		}
		show(ret);
		return 0;
	}

private:
	int isExsitedInHighLoc(vector<int> in, int loc, int val) {
		for (int i = loc+1; i < in.size(); i++) {
			if (in[i] == val) { return true; }
		}
		return false;
	}

	int combination(vector<int> &in, int cnt, int total, vector<vector<int>> &out) {
		if (cnt > total) { tmp.clear(); return -1; }
		for (int i = tmp.size(); i < cnt ; i++) {
			tmp.push_back(-1);
		}

		for (int j = total-1; j >= cnt-1 && j >= 0; j--) {
			/* 排除当前位置重复选择高位置已经选取过的数据，重要 */
			if (isExsitedInHighLoc(tmp, cnt - 1, in[j])) { continue; }
			tmp[cnt-1] = in[j];
			if (cnt > 1) {
				combination(in, cnt - 1, total - 1, out);
			}
			else {
				out.push_back(tmp);
			}
		}
		return 0;
	}

	/* --------------------------------------------------------------------------------
	采用倒排递归： 只适用于全排列
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
	int permut(vector<int> &in, int start,  int end, vector<vector<int>> &out) {
		if (end <= start) {
			out.push_back(in);
			return 0;
		}

		//核心区块
		for (int i = start; i < end; i++) {
			swap(in[i], in[start]);// 这个交换是为了获取新数据
			permut(in, start + 1, end, out);
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
	vector<int> in = {0,1,2};
	s.completePermut(in, 2, in.size());
	system("pause");
	return 0;
}


