#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<linux/un.h>
#include<string.h>
#include<error.h>
int main()
{
	int fd=0;
	int cfd=0;
	int r=0;
	char buf[128];
	fd=socket(AF_UNIX,SOCK_STREAM,0);
		if(fd==-1)printf("socket error:%m\n"),exit(-1);
	printf("创建套接字成功！\n");
	struct sockaddr_un addr={0};
	addr.sun_family=AF_UNIX;
	memcpy(addr.sun_path, "cs.sock",strlen("cs.sock"));
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("bind error:%m\n"),exit(-1);
	printf("绑定地址成功...........\n");
	r=listen(fd,10);
		if(r==-1)printf("listen error:%m\n"),exit(-1);
	printf("listen 成功！\n");
	cfd=accept(fd,0,0);
		if(cfd==-1) printf("accept error:%m\n"),exit(-1);
	printf("创建新连接成功！\n");
	
	while(1)
	{	
		sleep(1);
		memset(buf,'\0',sizeof(buf));
		r=read(cfd,buf,sizeof(buf));
		
		if(r==0)
		{
			printf("客户端退出！\n");
			break;
		}
		if(r==-1)
		{
			printf("网络故障！\n");
			break;
		}
		buf[r]='\0';
		printf("MSG:%s\n",buf);
		
	}
	close(cfd);
	close(fd);
	unlink("cs.sock");
	return 0;
}
