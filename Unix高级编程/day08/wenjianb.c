#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<error.h>
#include<signal.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	int fd=0;
	int r=0;
	fd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("connect error:%m\n"),exit(-1);
	write(fd,argv[1],strlen(argv[1]));
	close(fd);
	return 0;
}
