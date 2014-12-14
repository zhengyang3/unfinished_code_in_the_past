#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<fcntl.h> //文件操作
#include<string.h>
int idx=0;
int fdata;
void handle(int s)
{
	int status;
	if(s==17)
	{
		wait(&status);
		idx++;
		if(idx==2)
		{
			close(fdata);
			printf("end\n");
			exit(-1);
		}
	}
}
int isprimer(int a)
{
	int i=2;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
/*
	//创建三个进程
	int i=0;
	for(i=0;i<2;i++)
	{
	//	fork();//子进程中也有这段代码，所以不能直接这样写
		
	}
*/	
	signal(17,handle);
	int a, b;
	int id=1;
	int fd[2];
	
	pipe(fd);
	while(1)
	{
		if(id==1)
		{
			a=2;
			b=5000;
		}
		if(id==2)
		{
			a=5001;
			b=10000;
		}
		if(fork())
		{
			id++;
			if(id>2)
			{
				break;
			}
			continue;
		}else
		{
			int i;
			close(fd[0]);
			for(i=a;i<=b;i++)
			{
				if(isprimer(i))
				{
					write(fd[1],&i,sizeof(int));
				}
			}
		printf("pid:%d\n",getpid());
		exit(0);
		}
	}
	int re;
	char buf[20];
	close(fd[1]);
	fdata=open("res.dat",O_RDWR|O_CREAT,0777);
	while(1)
	{
		read(fd[0],&re,sizeof(int));
		sprintf(buf,"%d\n",re);
		write(fdata,buf,sizeof(buf));
	
	}
	return 0;
}





















