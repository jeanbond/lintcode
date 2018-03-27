using namespace std;
#include<vector>
#include<iostream>


class Solution {
public:

	int kthLargestElement(int n, vector<int> &nums) {
		// ǿ��ת������������澯��
		if (n > (int)nums.size()) {
			cout << "Input order[" << n << "] is over the list size[" << nums.size() << "] !!!" << endl;
			return -1;
		}

		return findN(n, nums);
	}

	/* ע�⣺ ���������ǲ��õ���ȫ��λ�ñ�ʶ����ʵ��Ӧ�õĹ����в�������Ӧ��
			   ˼·�ϱ��ֿ��������˼·���ص�����ȡ�����е�partition��˼�룬
			   �Ӷ���Сʱ�临�Ӷȣ��ռ临�Ӷ�ΪO(0)����Ϊ����û�ж��⿪����*/
	int findN(int order, vector<int> &src) {
		int loc = QSort(src, 0, src.size() - 1, order);
		return src[loc];
	}	

	int QSort(vector<int> &src, int start, int end, int order) {
		/* ��Ϊ������ʹ�õݹ��˼·�������ڵݹ�ĺ����б����������˳�����䣬������ѭ����*/
		if (start >= end) { return start; }

		int mid = partition(src, start, end);
		// if we find the location,as we partitioned the order
		int dis = end - mid+1;

		if (dis == order) {
			return mid;
		}
		/* ����������Ҫ����ÿ�εݹ�֮���λ�ã����λ�þ�������Ŀ��Ԫ�صĵ�ַ���к�
		   ����������ʹ�õ�ʱ�����ʹ��return�ݹ顣*/
		else if (order > dis) {
			return QSort(src, start, mid - 1, order-dis);
		}
		else{
			return QSort(src, mid + 1, end, order);
		}
		/* �������п��������ﱨ���������ʵ����޸�if���߼�˳���ų������� */
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