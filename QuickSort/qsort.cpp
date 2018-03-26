using namespace std;

#include<iostream>
#define OK			(0)
#define	ERROR		(0)

typedef unsigned int U32;


//采用类模板的方式写，便于以后代码的移植和扩展。
template <typename T=int>
class QSort
{
public:
	U32  quickSort(T *src, U32 start, U32 end);
	U32  showList(T *src, U32 len);
private:
	U32  partition(T *src, U32 start, U32 end);
	U32  swap(T &a, T &b);
};

template<typename T> 
U32 QSort<T>::quickSort(T *src, U32 start, U32 end) {
	if (start >= end) { return OK; }

	/* quickSort 函数解释
		1、不能使用循环，对于整体来说，我们只做一次排序，也就是：
		   找到partition的位置，然后对左右分别快速排序，如果循环就完全乱了。
		2、如果start/end/length等标记参数使用的是无符号的数据，需要处理0xf~ff的问题，
		   防止0减一之后得到一个非常大的数，该错误很明显；
		3、在此基础上思考“找到第K大（小）的数据的解决方式。（提示：思路有两种，1、比较
		   直观的是使用堆排序，采用大（小）堆来处理该问题。2、采用变化过的快速排序算法，
		   时间复杂度是O(n/2logN)，这种做法是目前公认比较快的思路。
	*/
	U32 loc = this->partition(src, start, end);
	if (loc > 0)	quickSort(src, start, loc - 1);
	if (end > 0)	quickSort(src, loc + 1, end);

	return OK;
}

template<typename T>
U32  QSort<T>::partition(T *src, U32 start, U32 end) {
	T tmp = src[start];

	/* Partition 函数解释
		1、partition函数的目的是以第一个元素的大小作为标准来将所有元素分区，
		   比该元素小的全部在左边，比该元素大的放在右边，这样就完成一次partition。
		2、partition函数中必须使用循环，而且每次partition出来的那个位置必须放置
		   我们采用的第一个校准元素，该元素可以是任意一个，但必须指定。
		3、swap函数必须是地址传递，不能值传递，cpp的&引用实际上也就是地址传递；
	*/
	while (start < end) {
		while (start < end && src[end] >= tmp && end > 0) end--;
		swap(src[start], src[end]);
		while (start < end && src[start] <= tmp && start > 0) start++;
		swap(src[start], src[end]);
	}
	return start;
}

template<typename T>
U32 QSort<T>::swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
	return 0;
}

template<typename T>
U32 QSort<T>::showList(T *src, U32 len) {
	cout << "To show all ordered list:\n";
	cout << "Data list count: " << (sizeof(src) / sizeof(src[0])) << " \n";
	cout << "Data detail: \n";
	while (len) {
		cout << src[--len]<<", ";
	}
	cout << endl;
	return 0;
}

U32 main() {
	U32 src[] = { 2,56,6,9,55,12,85,48,99,5,65,4654,121,58458,21,31,546,46,546,546,5465,4,4,5 };
	QSort<U32> q = QSort<U32>();
	U32 len = (sizeof(src) / sizeof(src[0]));
	q.quickSort(src, 0, len - 1);
	q.showList(src, len);
	return OK;
}