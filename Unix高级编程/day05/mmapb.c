#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<error.h>
#include<sys/mman.h>
#include<fcntl.h>
#include <sys/types.h>

int main(int argc ,char* argv[])
{
	int fd=0;
	int* s=NULL;
	int size=0;
	int i=0;
	//open
	fd=open(argv[1], O_RDWR|O_CREAT|O_EXCL,777);
	if(fd==-1)
	{
		fd=open(argv[1],O_RDWR);
			if(fd==-1) printf("error:%m\n"),exit(-1);
	}
	//size
	//mmap
	s=mmap(0,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	//read write
	while(1)
	{	
		*s=i;
		sleep(1);
		i++;
	}
	//munmmap
	munmmap(s,4);
	//close
	close(fd);
	return 0;
}
