#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<error.h>
#include<sys/mman.h>
#include <sys/types.h>
#include<fcntl.h>
void handle(int sig)
{
	printf("rev 14!\n");
}
int main()
{	
	signal(14,handle);
	printf("1111111111\n");
	//usleep(2000000);
	pause();
	
	printf("22222222222222\n");
	return 0;
}
