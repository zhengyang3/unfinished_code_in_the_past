#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main(int argc, char* argv[])
{
	int pid=atoi(argv[1]);
	int sig=atoi(argv[2]);
	kill(pid, sig);
	return 0;
}
