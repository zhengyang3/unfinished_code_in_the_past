#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<fcntl.h> //文件操作
int main()
{
	int fd[2];
	int r=0;
	char buf[30]={0};
	r=pipe(fd);
	write(fd[1],"hello",5);
	write(fd[1],"hello",5);
	r=read(fd[0],buf,30);
	buf[r]='\0';
	printf("%s\n",buf);
	return 0;
}
