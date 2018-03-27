using namespace std;
#include<vector>
#include<iostream>


class Solution {
public:

	int kthLargestElement(int n, vector<int> &nums) {
		// 强制转换，消除编译告警。
		if (n > (int)nums.size()) {
			cout << "Input order[" << n << "] is over the list size[" << nums.size() << "] !!!" << endl;
			return -1;
		}

		return findN(n, nums);
	}

	/* 注意： 在这里我们采用的是全局位置标识，在实际应用的过程中不能这样应用
			   思路上保持快速排序的思路，重点是提取快排中的partition的思想，
			   从而减小时间复杂度，空间复杂度为O(0)，因为我们没有额外开销。*/
	int findN(int order, vector<int> &src) {
		int loc = QSort(src, 0, src.size() - 1, order);
		return src[loc];
	}	

	int QSort(vector<int> &src, int start, int end, int order) {
		/* 因为快排中使用递归的思路，所以在递归的函数中必须有条件退出的语句，否则死循环。*/
		if (start >= end) { return start; }

		int mid = partition(src, start, end);
		// if we find the location,as we partitioned the order
		int dis = end - mid+1;

		if (dis == order) {
			return mid;
		}
		/* 由于我们需要返回每次递归之后的位置，这个位置就是我们目标元素的地址序列号
		   所以我们在使用的时候必须使用return递归。*/
		else if (order > dis) {
			return QSort(src, start, mid - 1, order-dis);
		}
		else{
			return QSort(src, mid + 1, end, order);
		}
		/* 编译器有可能在这里报警，可以适当的修改if的逻辑顺序排除该问题 */
	}

	int partition(vector<int> &src, int start, int end) {
		int tmp = src[start];

		if (start >= end)return start;

		while (start < end) {
			while (start < end && src[end] >= tmp) end--;
			swap(src[start], src[end]);
			while (start < end && src[start] <= tmp) start++;
			swap(src[start], src[end]);
		}
		return start;
	}

	void swap(int &a, int &b) {int tmp = a;a = b;b = tmp;}
};

int main()
{
	vector<int> src = { 
		44,3,4,6,3,22,55,66,77,343
	};
	int order = 5;
	Solution s = Solution();
	for (int i = 1; i < 22; i++) {
		order = i;
		cout << "The order is: " << order << endl << "The element is: "
			<< s.kthLargestElement(order, src) << endl;
		for (vector<int>::iterator s = src.begin(); s != src.end(); s++)  cout << *s << " ";
		cout << endl;
	}
	return 0;
}