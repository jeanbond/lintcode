
using namespace std;

#include<vector>
#include<iostream>

class Solution {
private:
	unsigned int SlCnt;
public:
	int totalNQueens(int n) {
		this->SlCnt = 0;
		vector<string> qu(n, string(n,'.'));
		helperQ(qu, 0);
		return SlCnt;
	}
private:
	int helperQ(vector<string> &qu, int row) {
		if (row == qu.size()) SlCnt++;

		for (int col = 0; col < qu.size(); col++) {
			if (judgeLoc(qu, row, col)) {
				qu[row][col] = 'Q';
				helperQ(qu, row + 1);
				qu[row][col] = '.';  // restore current location flag.
			}
		}
	}

	bool judgeLoc(vector<string> &qu, int row, int col) {
		for(int i = 0; i < qu.size(); i++) {
			for (int j = 0; j < qu.size(); j++) {
				if (qu[i][j] == 'Q') {
					if (i == row || j == col || abs(row - i) == abs(j - col)) return false;
				}
			}
		}
		return true;
	}
};

int main() {
	return 0;
}