#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
int main()
{
	int pid=0;
	int i=0;
	pid=fork();
	if(pid==0)
	{
		while(1)
		{
			printf("111111111\n");
			i++;
			sleep(1);
			if(i==20) return -2;
		}
	}else if(pid>0)
	{
		while(1)
		{
			printf("222222222\n");
			i++;
			sleep(1);
			if(i==5) return -1; //这个时候结束的是进程不是主函数；
		}	
	}else
	{
		printf("::%m\n");
		return -1;
	}
	
	return 55;
}
