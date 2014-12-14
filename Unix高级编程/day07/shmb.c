#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>
#include<sys/shm.h>
int* p=NULL;
int shmid=0;
void handle(int s)
{
	if(s==SIGINT)
	{
		printf("signal SIGINT....\n");
		shmdt(p);
		exit(0);
	}
}
int main()
{	
	signal(2,handle);
	
	key_t key=0;
	
	int i=0;
	key=ftok(".",255);
		if(key==-1) printf("frok error:%m\n"),exit(-1);
	shmid=shmget(key,4,0);
		if(shmid==-1) printf("get error:%m\n"),exit(-1);
	p=shmat(shmid,0,0);
		if(p==(int*)-1) printf("shmat error:%m\n"),exit(-1);
	while(1)
	{
		printf("%d\n",*p);
		sleep(1);
	
	
	}
	
	return 0;
}
