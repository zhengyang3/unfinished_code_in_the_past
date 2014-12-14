#include<stdio.h>
int main()
{	
	int a=0;
	printf("请输入一个整数：");
	scanf("%d",&a);
	if(sushu(a)==1) printf("%d是一个素数\n",a);
	else printf("%d不是一个素数\n",a);
	return 0;

}
