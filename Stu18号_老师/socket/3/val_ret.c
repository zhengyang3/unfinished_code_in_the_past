#include <stdio.h>

int dbl1(int i)
{
	int j = 2 * i;

	return j;
}

void dbl2(int i, int * p)
{
	int j = 2 * i;	
	*p = j;
}

void dbl3(int *p)
{
	int j = 2 * (*p);
	*p = j;
}

int main()
{
	int i = 10;
	
	printf("%d\n", dbl(i));	

	return 0;
}
