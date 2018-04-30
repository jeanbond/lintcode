
using namespace std;


#include<vector>
class Solution {
public:
	/**
	* @param matrix: matrix, a list of lists of integers
	* @param target: An integer
	* @return: a boolean, indicate whether matrix contains target
	*/
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty()) { return false; }

		int i, j;

		for (i = 0; i < matrix.size(); i++) {
			if (matrix[i][0] <= target) { continue; }
			else { break; }
		}
		if (i > 0) { i--; }
		for (j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == target) { return true; }
		}
		if (j >= matrix[i].size()) { return false; }
	}
};

int main() {
	Solution s = Solution();
	vector<vector<int>> in = { {1,3,5,7 },{ 10,11,16,20 },{ 23,30,34,50 } };
	s.searchMatrix(in, 7);
	return 0;
}