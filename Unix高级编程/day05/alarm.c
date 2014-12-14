#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void handle(int sig)
{
	printf("recv 14\n");
}
int main()
{
	signal(14, handle);
	alarm(5);//秒数，在多少秒之后，给调用它的进程发送一个14号信号；
	getchar();
	
	return 0;
}
