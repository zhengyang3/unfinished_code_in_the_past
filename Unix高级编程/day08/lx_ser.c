#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<error.h>
int main()
{
	int fd=0;
	int cfd=0;
	char buf[128];
	char r=0;
	fd=socket(AF_INET,SOCK_STREAM,0);
		if(fd==-1)printf("socket error:%m\n"),exit(-1);
	printf("构建成功！\n");
	struct sockaddr_in addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons("11111");
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1) printf("bind error:%m\n"),exit(-1);
	printf("绑定成功！\n");
	r=listen(fd,10);
		if(r==-1)printf("监听失败:%m\n"),exit(-1);
	cfd=accept(fd,0,0);
		if(cfd==-1)printf("接收失败:%m\n"),exit(-1);
	printf("创建新连接成功！\n");
	while(1)
	{
		sleep(2);
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

	return 0;
}
