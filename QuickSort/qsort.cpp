using namespace std;

#include<iostream>
#define OK			(0)
#define	ERROR		(0)


typedef unsigned int U32;

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

	U32 loc = this->partition(src, start, end);
	if(loc > 0)	quickSort(src, start, loc - 1);
	if(end > 0)	quickSort(src, loc + 1, end);
	return OK;
}

template<typename T>
U32  QSort<T>::partition(T *src, U32 start, U32 end) {
	T tmp = src[start];

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