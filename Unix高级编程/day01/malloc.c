#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int* a=(int*)malloc(4);
	*a=4;
	*(a+1)=5;
	*(a+10)=14;
	
	free (a);
	return 0;
}
