using namespace std;

#include<iostream>
#define OK			(0)
#define	ERROR		(0)

typedef unsigned int U32;


//������ģ��ķ�ʽд�������Ժ�������ֲ����չ��
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

	/* quickSort ��������
		1������ʹ��ѭ��������������˵������ֻ��һ������Ҳ���ǣ�
		   �ҵ�partition��λ�ã�Ȼ������ҷֱ�����������ѭ������ȫ���ˡ�
		2�����start/end/length�ȱ�ǲ���ʹ�õ����޷��ŵ����ݣ���Ҫ����0xf~ff�����⣬
		   ��ֹ0��һ֮��õ�һ���ǳ���������ô�������ԣ�
		3���ڴ˻�����˼�����ҵ���K��С�������ݵĽ����ʽ������ʾ��˼·�����֣�1���Ƚ�
		   ֱ�۵���ʹ�ö����򣬲��ô�С��������������⡣2�����ñ仯���Ŀ��������㷨��
		   ʱ�临�Ӷ���O(n/2logN)������������Ŀǰ���ϱȽϿ��˼·��
	*/
	U32 loc = this->partition(src, start, end);
	if (loc > 0)	quickSort(src, start, loc - 1);
	if (end > 0)	quickSort(src, loc + 1, end);

	return OK;
}

template<typename T>
U32  QSort<T>::partition(T *src, U32 start, U32 end) {
	T tmp = src[start];

	/* Partition ��������
		1��partition������Ŀ�����Ե�һ��Ԫ�صĴ�С��Ϊ��׼��������Ԫ�ط�����
		   �ȸ�Ԫ��С��ȫ������ߣ��ȸ�Ԫ�ش�ķ����ұߣ����������һ��partition��
		2��partition�����б���ʹ��ѭ��������ÿ��partition�������Ǹ�λ�ñ������
		   ���ǲ��õĵ�һ��У׼Ԫ�أ���Ԫ�ؿ���������һ����������ָ����
		3��swap���������ǵ�ַ���ݣ�����ֵ���ݣ�cpp��&����ʵ����Ҳ���ǵ�ַ���ݣ�
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