//server
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<error.h>
int fd;
void handle(int s)
{
	if(s==2)
	{
		//close(cfd);
		close(fd);
		exit(1);
	}
}
int main()
{
	signal(2,handle);
	
	int* cfd=NULL;
	int index=0;
	int r,i;
	
	struct sockaddr_in addr;
	cfd=mmap(0,4096,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,0,0);
	fd=socket(AF_INET,SOCK_STREAM,0);	
		if(fd==-1) printf("socket error:%m\n"),exit(-1);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("bind error:%m\n"),exit(-1);
	r=listen(fd,10);
		if(r==-1)printf("listen error:%m\n"),exit(-1);
	
	while(1)
	{
		cfd[index]=accept(fd,0,0);
		if(cfd[index]==-1) break;
		printf("有新的用户连接！\n");
		if(fork())
		{//父进程   接受到新的客户就创建新的连接
			index++;
			continue;
		}
		else
		{//子进程专门用来接收客户端发送过来的消息
			
			char buf[256];
			printf("%d开始工作........\n",cfd[index]);
			while(1)
			{//开始接受数据
				memset(buf,'\0',256);
				r=recv(cfd[index],buf,255,0);
				printf("接受到%d个字节\n",r);
				if(r==0)
				{
					printf("客户端退出！\n");
					close(cfd[index]);
					cfd[index]=0;
					break;
				}
				if(r==-1)
				{
					printf("网络出错了！\n");
					close(cfd[index]);
					cfd[index]=0;
					break;
				}
				buf[r]='\0';
				printf("接受到的消息：%s\n",buf);
				//将服务器接收到的所有消息转发给所有除自己之外的所有客户端
				for(i=0;i<index10;i++)
				{
					if(cfd[i]>0)
					{
						if(cfd[i]!=cfd[index])
						{
							send(cfd[i],buf,r,0);
						}
					}
				}
			}
			exit(0);
		}
	}
	
	
	return 0;
}








































