#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int main(int argc,char* argv[])
{	
	union sigval val ={0};
	int pid=atoi(argv[1]);
	int sig=atoi(argv[2]);
	val.sival_int =4444;
	
	printf("loading.......\n");
	sleep(10);
	sigqueue(pid,sig,val);

	

	return 0;
}
