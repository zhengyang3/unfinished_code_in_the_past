#include<stdio.h>
#include<unistd.h>
#include<error.h>
int main()
{
	int pid=0;
	pid=fork();
	int i=100;
	if(pid==0)
	{
		while(1)
		{
			printf("this is child proc!--->i:%d\n",i--);
			sleep(1);
		}
	}else
	{
		while(1)
		{
			printf("this is father proc--->i:%d\n",i++);
			sleep(1);
		}
	}
	return 0;
}
