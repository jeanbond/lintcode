#include<stdio.h>
#include<math.h>

int main()
{
	printf("%d \n", digitCounts(1, 1));
	printf("%d \n", digitCounts(1, 12));
	printf("%d \n", digitCounts(0, 19));
	return 0;
}


int digitCounts1(int k, int n) {
	// write your code here

	int tmp = 1;
	int cnt = 0;

	if (k == 0 && n >= 0) { cnt = 1; }

	while (tmp <= n) {
		for (int level = 1; tmp / (int)(pow(10, level - 1)); level++) {
			int cur = (tmp%(int)pow(10, level)) / (int)(pow(10, level - 1));
			if (cur == k) { cnt++; }
		}
		tmp++;
	}
	return cnt;
}

int digitCounts(int k, int n) {
	// write your code here
	if (k > 9 || k < 0) { return -1; }
	int ret = 0;
	int base = 1;
	if (k == 0 && n == 0) { ret = 1; }
	while (n / base) {
		if (n == k) { ret++; }
		int cur =0, low = 0,  high = 0;
		cur = (n / base) % 10;
		high = n / (base * 10);
		low = n % base;
		if (cur == k) {
			ret += (high * (base)) + low;
		}
		else if (cur > k) {
			ret += (high + 1) * (base);
		}
		else if (cur < k) {
			ret += high * (base);
		}
		base *= 10;
	}
	return ret;
}