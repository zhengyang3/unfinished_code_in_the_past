#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<error.h>
#include<signal.h>
int fd=0;
void handle(int s)
{
	if(s==2)
	{
		printf("SIGINT handling...\n");
		close(fd);
		exit(0);
	}
}
int main()
{
	
	int r=0;
	char buf[128];
	signal(2,handle);
	fd=socket(AF_INET,SOCK_DGRAM,0);
		if(fd==-1)printf("socket error:%m\n"),exit(-1);
	printf("构建成功！\n");
	//构建地址
	struct sockaddr_in addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	//绑定
	r=bind(fd,(struct sockaddr*)&addr, sizeof(addr));
		if(r==-1)printf("bind error:%m\n"),exit(-1);
	printf("地址绑定成功！\n");
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		r=read(fd,buf,sizeof(buf));	
		buf[r]='\0';
		printf("接收消息：%s\n",buf);
		
	}
	return 0;
}












