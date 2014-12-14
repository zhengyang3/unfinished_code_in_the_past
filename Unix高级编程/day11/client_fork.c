//client
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/mman.h>
#include<netinet/in.h>
#include<error.h>
int fd;
int main()
{
	
	int cfd;
	int r=0;
	
	char buf[256];
	struct sockaddr_in addr;
	
	fd=socket(AF_INET,SOCK_STREAM,0);
	memset(buf,0,4096);	
		if(fd==-1) printf("socket error:%m\n"),exit(-1);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("connect error:%m\n"),exit(-1);
	while(1)
	{
		//memset(buf,'\0',256);
		//r=recv(fd,buf,255,0);
		//printf("消息：%s\n");
		printf("please input:");
		scanf("%s",buf);
		send(fd,buf,strlen(buf)+1,0);
		
	}
	close(fd);

	return 0;
}

