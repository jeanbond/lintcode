using namespace std;
#include<vector>
#include<iostream>
class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @param target: An integer you want to search in matrix
	* @return: An integer indicate the total occurrence of target in the given matrix
	*/
	int searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.size() < 1) return 0;

		unsigned int cnt = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (target == matrix[i][j]) cnt++;
				if (target < matrix[i][j]) break;
			}
			if (matrix[i][0] > target) break;
		}
		return cnt;
	}
};
int  main() {
	return 0;
}