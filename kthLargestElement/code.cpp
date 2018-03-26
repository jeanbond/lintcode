using namespace std;
#include<vector>


class Solution {
public:
	int heapSize;

	int parent(int idx) {
		return (idx - 1) >> 1;
	}
	int left(int idx) {
		return (idx << 1) + 1;
	}
	int right(int idx) {
		return (idx << 1) + 2;
	}


	int kthLargestElement(int n, vector<int> &nums) {
		// write your code here
	}
};

int main()
{
	return 0;
}