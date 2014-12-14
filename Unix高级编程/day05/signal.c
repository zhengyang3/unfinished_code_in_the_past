#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void handle(int sig)
{	
	printf("signal 14\n");
}
	
int main()
{
	printf("pid:%d\n",getpid());
	//处理说明
	signal(14, handle); //用自已指定的方式处理
	getchar();
	return 0;
}
