
using namespace std;

#include<iostream>

#include<stdio.h>
#include<vector>

/*
问题:有些数的素因子只有3,5,7，请设计一个算法，找出其中第k个数。
分析：第k个数是指第k小的数吧?这个题目应该是剑指offer或编程之美中的丑数。
丑数的关键是寻找下一个丑数，
下一个丑数 = 在之前生成的丑数数组中寻找一个数 * (3或5或7)，即大于当前丑数的最小值
设当前丑数为M
设第一个乘以3大于M的数为M3，同理M5,M7,则M = min(M3, M5 , M7)
对于丑数3而言，必定存在T3使得T3之前的数乘以3都小于M,T3之后的丑数
关键是寻找丑数数组中第一个乘以3大于当前最大丑数的数T3,寻找丑数数组中第一个乘以5大于最大丑数的数T5,同理T7
使得：
设当前丑数为M
3*T3=M3 > M  【公式(1)】
5*T5=M5 > M  【公式(2)】
7*T7=M7 > M  【公式(3)】
从中令新的M = min(M3 , M5 , M7)，并更新T3,T5,T7，使得新的T3,有3*T3 > M，同理T5,T7    【操作1】
如果不更新，带来的问题就是，会陷入死循环
比如刚开始M=1,初始T3=T5=T7=1,满足上述条件后，M=3,此时3*T3 <= M,则T3=1没有等于3,同理后续T5=1,T7=1,而M=7,
之后就发现T3,T5,T7中没有一个能符合上述公式(1),(2),(3)，则M一直变成7不再变化；
为了防止这种情况，要进行上述操作1的处理，为的就是能够作为下一个丑数M的候选值能够一直变大
输入:
7(k)
输出:
25

关键：
1 下一个丑数 = 在之前生成的丑数数组中寻找一个数 * (3或5或7)，即大于当前丑数的最小值
设当前丑数为M
3*T3=M3 > M  【公式(1)】
5*T5=M5 > M  【公式(2)】
7*T7=M7 > M  【公式(3)】
从中令新的M = min(M3 , M5 , M7)，并更新T3,T5,T7，使得新的T3,有3*T3 > M，同理T5,T7    【操作1】
如果不更新，带来的问题就是，会陷入死循环
比如刚开始M=1,初始T3=T5=T7=1,满足上述条件后，M=3,此时3*T3 <= M,则T3=1没有等于3,同理后续T5=1,T7=1,而M=7,
之后就发现T3,T5,T7中没有一个能符合上述公式(1),(2),(3)，则M一直变成7不再变化；
为了防止这种情况，要进行上述操作1的处理，为的就是能够作为下一个丑数M的候选值能够一直变大
*/

class Solution {
public:
	int *ug = NULL;
	
	int nthUglyNumber(int n) {
		//数组动态分配的时候注意：1、使用 new 关键字； 2、必须使用 [] ，不能使用 （）
		ug = new int[n + 1];
		*ug = 1;
		int *p2 = ug;
		int *p3 = ug;
		int *p5 = ug;
		int cnt = 0;

		while (cnt < n) {
			int mixx = min(*p2 * 2, *p3 * 3, *p5 * 5);
			cnt++;
			ug[cnt] = mixx;
			/* key area start */
			while (*p2 * 2 <= mixx) p2++;
			while (*p3 * 3 <= mixx) p3++;
			while (*p5 * 5 <= mixx) p5++;
			/* key area end */
		}
		int ret = ug[n-1];
		// 释放动态分配的堆内存的时候注意：
		//1、使用关键字 new 。
		//2、分配和释放数组的堆空间必须用[]，不能用（）。
		delete[] ug;
		return ret;
	}

private:
	int min(int a, int b, int c)
	{
		int minNum = a < b ? a : b;
		minNum = minNum < c ? minNum : c;
		return minNum;
	}
};


int main() {
	Solution s = Solution();
	cout<<hex<<s.nthUglyNumber(9);
	return 0;
}
  
