#include<stdio.h>

int main()
{
	printf("%f \n", calcsss(120));
	return 0;
}

long calcsss(long inp)
{
	long n = 0;
	while (inp)
	{
		inp /= 5;
		n += inp;
	}
	return n;
}