#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<fcntl.h> //文件操作
#include<string.h>
int main()
{	
	int fd[2];
	pipe(fd);
	if(fork())
	{
		printf("我是父进程！\n");
		close(fd[0]);//	一个进程里面只能操作一个描述符，多余的必须关闭
		while(1)
		{
			write(fd[1],"我是父进程", strlen("我是父进程"));
		}	
	}else
	{
		char buf[20]={0};
		int r=0;
		printf("我是子进程！\n");
		close(fd[1]);
		while(1)
		{
			r=read(fd[0],buf,20);
			//buf[r]=0;
			sleep(1);
			printf("子进程：%s\n",buf);
		}
	}
	return 0;
}
