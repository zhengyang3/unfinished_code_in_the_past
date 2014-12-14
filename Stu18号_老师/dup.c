#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	/*
	close(1);

	int fd1 = open("./data1", O_RDWR|O_CREAT, 0644);	
	*/
	int fd1 = open("./data1", O_RDWR|O_CREAT, 0644);	
	dup2(fd1, 1);

	execlp("pwd", "pwd", NULL);

	printf("hello world\n");

	return 0;
}
