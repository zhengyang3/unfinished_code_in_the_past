#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<error.h>
void handle(int sig)
{
	printf("接受到信号17\n");
}
int main()
{
	int pid=fork();
	int i=0;
	signal(17,handle);
	if (pid==0)
	{
		while(1)
		{
			printf("我是子进程！\n");
	    	i++;
	    	sleep(1);
	    	if(i==10) return -1;
	    
	    }
	}else if(pid==-1)
	{
		printf("%m\n");
		return -1;
	
	}else
	{
		while(1)
		{
			printf("我是父进程!\n");
			sleep(1);
		}
	}
	
	return 0;
}
