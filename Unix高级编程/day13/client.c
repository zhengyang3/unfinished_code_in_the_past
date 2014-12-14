#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<error.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{	
	int fd=0;
	int r=0;
	int len=0;
	char buf[120]={0};
	struct sockaddr_in addr;
	fd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1) printf("connect error:%m\n");
	while(1)
	{	
		printf("Input:");
		fgets(buf,119,stdin);
		buf[strlen(buf)-1]='\0';
		len=strlen(buf);
		send(fd,&len,4,0);		
		send(fd,buf,len,0);
		
		r=recv(fd,&len,4,MSG_WAITALL);
		if(r==-1)break;
		r=recv(fd,buf,len,MSG_WAITALL);
      	buf[r]='\0';
     	printf("接收到的消息是：%s\n",buf);
	}
	
	
	return 0;
}
























