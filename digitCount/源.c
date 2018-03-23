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
	int level = 1;
	if (k == 0 && n == 0) { ret = 1; }
	
	while (n / base) {
		if (n == k) { ret++; return ret; }
		int cur =0, low = 0,  high = 0;
		int cbase = 0;
		cur = (n / base) % 10;
		high = n / (base * 10);
		low = n % base;

		if (base > 1) {
			cbase = pow(11, level - 1);
		}
		if (cur == k) {
			ret += (high * (cbase)) + low+1;
		}
		else if (cur > k) {
			ret += (high + 1) * (cbase);
		}
		else if (cur < k) {
			ret += high * (cbase);
		}
		base *= 10;

		if (base > 1) {			
			int other = pow(10, level-2);
			ret += other;
		}
		level++;
	}
	return ret;
}