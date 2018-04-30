
using namespace std;
#include<vector>
#include<iostream>

class Solution {
private:
	vector<vector<string>> ret;
public:
	/*
	* @param n: The number of queens
	* @return: All distinct solutions
	*/
	vector<vector<string>> solveNQueens(int n) {
		// cur是个二位向量，记录行列的中间数据，Q表示放置，.表示未放置；
		vector<string> cur(n, string(n, '.'));
		helper(cur, 0);// 从0行开始
		return ret;
	}

	void helper(vector<string> &cur, int row) { // helper是递归函数，输入中间变量和当前操作的行。
		if (row == cur.size()) {// 递归结束条件，所有行都处理完毕，并找到确定答案；
			this->ret.push_back(cur);
			return;
		}
		for (int col = 0; col < cur.size(); col++) {
			if(isValid(cur, row, col)) {
				cur[row][col] = 'Q'; // 标记当前位置
				helper(cur, row + 1); // 对下一行进行递归操作，也就是在下一行继续寻找能放置的位置；
				cur[row][col] = '.'; // 为了回溯，必须将当前位置在处理完毕之后还原，否则无法回溯，考虑是递归的思路，才能这样写；
			}
		}
	}

	bool isValid(vector<string> &cur, int row, int col) {
		// 判断是否能放置的方法有很多：字符串标记，数字标记，二进制标记
		// 在判断方法上有改进的地方，比如：不需要对全部空间遍历，只需要对已经放置的空间处理
		// 已经放置的空间也就是：当前位置的 左上角  和 右上角，采用这种方法能提高效率；
		for (int i = 0; i < cur.size(); i++) {
			for (int j = 0; j < cur.size(); j++) {
				if (cur[i][j] == 'Q') {
					if (row == i || j == col || abs(i - row) == abs(col - j))
						return false;
				}
			}
		}
		return true;		
	}
};

int  main() {
	system("pause");
	return 0;
}

//参考地址：http://www.cnblogs.com/TenosDoIt/p/3801621.html