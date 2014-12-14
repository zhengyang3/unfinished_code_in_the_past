#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<error.h>
int main(int argc ,char* argv[])
{
	int fd;
	struct sockaddr_in addr;
	char buf[100];
	int r;
	int port=atoi(argv[2]);
	fd=socket(AF_INET,SOCK_DGRAM,0);
		if(fd==-1) printf("socket error:%m\n"),exit(-1);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=inet_addr(argv[1]);
	//connect (fd,(struct sockaddr*)&addr,sizeof(addr));
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		printf("Input data:");
		//scanf("%s",buf);
		r=read(0,buf,sizeof(buf)-1);
			if(r==0) break;
		buf[r]='\0';
		r=sendto(fd,buf,sizeof(buf),0,(struct socketaddr*)&addr,sizeof(addr));
									//指定后面两个参数，可以掉connect				
	}
	
	return 0;
}
