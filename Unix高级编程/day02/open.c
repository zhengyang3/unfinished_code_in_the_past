#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
int main()
{
	int fd=0;
	fd=open("222",O_CREAT|O_RDWR);
	if(fd==-1)
	{
		printf("creat file error!\n");
		return -1;
	
	}
	printf("creat file success\n");
	close(fd);
	return 0;
}
