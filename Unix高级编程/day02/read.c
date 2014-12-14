#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char* argv[])
{
	int fd=0;
	int r=0;
	char buf[10]={0};
	fd=open(argv[1],O_CREAT|O_RDONLY);
	if(fd==-1)
	{
		printf("open file error\n");
		return -1;		
	}
	printf("open file success\n");
	while(1)
	{
		r=read(fd,buf,9);
		if(r==0)
		{
			printf("end of file\n");
			break;
		}
		if(r<0)
		{
			printf("read file error\n");
			break;
		}
		buf[r]='\0';
		printf("%s",buf);
	}
	close(fd);
	return 0;
}
