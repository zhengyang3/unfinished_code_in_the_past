#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<fcntl.h>
int fd=0;
void handle(int sig)
{
	close(fd);
	unlink("my.pipe");
	exit(-1);
}
int main()
{
	
	signal(2,handle);
	int i=0;
	mkfifo("my.pipe",0777);
    fd=open("my.pipe",O_RDWR);
	while(1)
	{
		sleep(1);
		write(fd,&i,4);
		i++;
	}

	return 0;
}
