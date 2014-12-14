#include<stdio.h>
int main()
{
	int a=1;
	int b=2;
	int c=8;
	scanf("%d %d,%d",&a,&b,&c);
	if(a>b)
	{
	if(a>c)
	{
	printf("a:%d\n",a);
	}
	else
	printf("c:%d\n",c);
        }
	if(a<b)
	{
	if(b<c)
	printf("c:%d\n",c);
	else
	printf("b:%d\n",b);
	} 


	return 0;
}
