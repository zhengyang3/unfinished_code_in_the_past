#include<stdio.h>
int main()
{
	int j=0;
	int i=0;
	for(i=100;i<1000;i++)
	{
	for(j=2;j<i;j++)
	{
	if(i%j==0)
	{
	break;	
	}
}
	if(j==i)
	{printf("%d ",i);
	}
	}
	





	return 0;
}
