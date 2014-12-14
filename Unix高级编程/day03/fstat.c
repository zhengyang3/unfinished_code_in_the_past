#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<error.h>
int main(int argc, char* argv[])
{
	int fd=open(argv[1], O_RDWR);
	struct stat tmp ={0};
	fstat(fd, &tmp);
	printf("file size:%d\n",tmp.st_size);
	close(fd);
	return 0;
}
