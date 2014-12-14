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
	char filename[32];
	memset(filename,'\0',32);
	strcpy(filename,argv[1]);
	int fd=open(filename,O_RDWR);
	if(fd==-1)
	{
		fd=open(filename,O_CREAT);	
	}
	int i=0;
	int j=0;
	for(j=100,j<1000,j++)
	{
		for(i=2,i<j,i++)
		{
			if(j%i==0) \
			{
				while(1)
				{
					r=write(fd,&j,4);
				}
				break;	
			}
		}
	}
	return 0;	
}
	







