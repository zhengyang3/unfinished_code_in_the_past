#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd=creat("111",0644);
	if(fd==-1) 
	{
		printf("crate file failed\n");
		return -1;
	}
	printf("create success:%d\n",fd);
	close(fd);
	return 0;
}
