using namespace std;

#include<vector>

class Solution {
public:
	/**
	* @param A: sorted integer array A
	* @param B: sorted integer array B
	* @return: A new sorted integer array
	*/
	vector<int>::iterator one;
	vector<int>::iterator two;

	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		// write your code here
		one = A.begin();
		two = B.begin();
		vector<int> out;

		while (one != A.end() && two != B.end()) {
			if ( one != A.end() && *one <= *two) {
				out.push_back(*one);
				one++;			
			}else if (two != B.end() && *one >= *two) {
				out.push_back(*two);
				two++;
			}
		}
		//check 
		if (one != A.end()) {
			while (one != A.end()) {
				out.push_back(*one);
				one++;
			}
		}
		else if (two != B.end()) {
			while (two != B.end()) {
				out.push_back(*two);
				two++;
			}
		}
		return out;
	}
};

int main() {
	Solution s = Solution();
	vector<int> a = {7};
	vector<int> b = {5,7};
	s.mergeSortedArray(a, b);
	return 0;
}