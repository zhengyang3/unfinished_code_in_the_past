#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<fcntl.h>
int main()
{
	int i=0;
	int fd=open("my.pipe",O_RDWR);
	while(1)
	{
		read(fd,&i,4);
		printf("%d\n",i);
		sleep(1);
	
	}
	close(fd);
	return 0;
}
