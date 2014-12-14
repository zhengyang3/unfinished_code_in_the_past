#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char* argv[])
{	
	
	char filename[32];
	memset(filename,'\0',32);
	strcpy(filename,argv[1]);
	int fd=open(filename,O_RDWR);
	if(fd==-1)
	{
		printf("open file failed\n");
		return -1;
	}
	printf("open file success\n");
	close(fd);

	return 0;
}
