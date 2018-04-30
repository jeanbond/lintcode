
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
		// cur�Ǹ���λ��������¼���е��м����ݣ�Q��ʾ���ã�.��ʾδ���ã�
		vector<string> cur(n, string(n, '.'));
		helper(cur, 0);// ��0�п�ʼ
		return ret;
	}

	void helper(vector<string> &cur, int row) { // helper�ǵݹ麯���������м�����͵�ǰ�������С�
		if (row == cur.size()) {// �ݹ���������������ж�������ϣ����ҵ�ȷ���𰸣�
			this->ret.push_back(cur);
			return;
		}
		for (int col = 0; col < cur.size(); col++) {
			if(isValid(cur, row, col)) {
				cur[row][col] = 'Q'; // ��ǵ�ǰλ��
				helper(cur, row + 1); // ����һ�н��еݹ������Ҳ��������һ�м���Ѱ���ܷ��õ�λ�ã�
				cur[row][col] = '.'; // Ϊ�˻��ݣ����뽫��ǰλ���ڴ������֮��ԭ�������޷����ݣ������ǵݹ��˼·����������д��
			}
		}
	}

	bool isValid(vector<string> &cur, int row, int col) {
		// �ж��Ƿ��ܷ��õķ����кࣺܶ�ַ�����ǣ����ֱ�ǣ������Ʊ��
		// ���жϷ������иĽ��ĵط������磺����Ҫ��ȫ���ռ������ֻ��Ҫ���Ѿ����õĿռ䴦��
		// �Ѿ����õĿռ�Ҳ���ǣ���ǰλ�õ� ���Ͻ�  �� ���Ͻǣ��������ַ��������Ч�ʣ�
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

//�ο���ַ��http://www.cnblogs.com/TenosDoIt/p/3801621.html