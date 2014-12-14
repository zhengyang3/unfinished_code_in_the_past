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
int main()
{
	int fd=0;
	int cfd=0;
	int r=0;
	int creat_fd=0;
	char buf[128];
	fd=socket(AF_INET,SOCK_STREAM,0);
		 if(fd==-1)printf("erorr:"),exit(-1);
	struct sockaddr_in addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));

	r=listen(fd,10);
		if(r==-1)printf("listen error:%m\n"),exit(-1);
	cfd=accept(fd,0,0);
	
		memset(buf,'\0',sizeof(buf));
		r=read(cfd,buf,sizeof(buf));
		buf[r]='\0';
		printf("filename:%s\n",buf);
		creat_fd=creat(buf,0777);	
			if(creat_fd==-1)printf("creat error:%m\n"),exit(-1);
		printf("creat file %s success!\n",buf);
				
	

	close(cfd);
	close(fd);
	return 0;
}
