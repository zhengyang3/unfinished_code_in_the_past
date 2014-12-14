#include<stdio.h>

int main()
{
	while(1)
	{
		char a[100];
		int pid=0;
		printf("Please Input:");
		scanf("%s",&a);
		if(strcmp(a,"exit")==0)
		{
			return 0;
		}
		fork();
		if(pid<0)
		{
			printf("创建进程失败！\n");
			exit(-1);
		}
		if(pid==0)
		{
			
		}
	}
	return 0;
}
