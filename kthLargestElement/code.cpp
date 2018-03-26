using namespace std;
#include<vector>
#include<iostream>

class Solution {
public:

	int kthLargestElement(int n, vector<int> &nums) {
		// write your code here
	}

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int partition(vector<int> &src, int start, int end) {
		int tmp = src[start];

		while (start < end) {
			while (start < end && src[end] >= tmp) end--;
			swap(src[start], src[end]);
			while (start < end && src[start] <= tmp) start++;
			swap(src[start], src[end]);
		}

		return start;
	}
	int QSort(vector<int> &src, int start, int end) {
		if (start >= end) { return 0; }

		int mid = partition(src, start, end);
		QSort(src, start, mid - 1);
		QSort(src, mid + 1, end);
		return 0;
	}
};

int main()
{
	vector<int> src = {3,6,5,1,2,45,8,99,66,25,63,55,44,88,77,15,65,45,89,25,15,5465,546,215,125};
	Solution s = Solution();
	s.QSort(src, 0, src.size() - 1);
	for (vector<int>::iterator s = src.begin(); s != src.end(); s++)  cout << *s << " ";
	return 0;
}