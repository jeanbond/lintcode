#include <stdio.h>

int main()
{
	testadd();
	testsubs();
	testchen();
	testchu();
	return 0;
}

int testadd(void)
{
	printf("%d\n", add(3, 4));
	printf("%d\n", add(-3, -4));
	printf("%d\n", add(3, -4));
	printf("%d\n", add(-3, 4));
}

int testsubs(void)
{
	printf("%d\n", subs(10, 4));
	printf("%d\n", subs(4, 11));
	printf("%d\n", subs(-3, -4));
	printf("%d\n", subs(-3, 4));
	printf("%d\n", subs(3, -4));
}

int testchen(void)
{
	printf("%d\n", chen(10, 4));
	printf("%d\n", chen(-4, -11));
	printf("%d\n", chen(3, -4));
	printf("%d\n", chen(-3, 4));
}

int testchu(void)
{
	printf("%d\n", chu(10, 4));
	printf("%d\n", chu(-10, 4));
	printf("%d\n", chu(-10, -4));
	printf("%d\n", chu(10, -4));
	printf("%d\n", chu(10, 0));
	printf("%d\n", chu(10, 11));
	printf("%d\n", chu(10, -11));
	printf("%d\n", chu(-10, 11));
}

int add(int a, int b)
{
	int sum;
	while (b)
	{
		sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return sum;
}

int subs(int a, int b)
{
	return add(a, add(~b, 1));
}

int chen(int a, int b)
{
	int outp = 0;
	int bb = b, aa = a;
	if (b < 0) { bb = add(~b, 1); }
	if (a < 0) { aa = add(~a, 1); }
	while (bb)
	{
		outp = add(outp, aa);
		bb--;
	}
	if ((a ^ b) < 0)
	{
		outp = add(~outp, 1);
	}
	return outp;
}

int chu(int a, int b)
{
	int aa = a, bb = b;
	int cnt = 0;
	
	if (b == 0)
	{
		return -1;
	}
	if (b < 0) { bb = add(~b, 1); }
	if (a < 0) { aa = add(~a, 1); }

	while (aa >= bb)
	{
		aa = subs(aa, bb);
		cnt++;
	}

	if ((a^b) < 0)
	{
		cnt = add(~cnt, 1);
	}
	return cnt;
}