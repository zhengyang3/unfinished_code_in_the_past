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
	int r=0;
	char buf[128];
	int i=0;
	fd=socket(AF_UNIX,SOCK_STREAM,0);
		if(fd==-1)printf("socket error:%m\n"),exit(-1);
	printf("创建套接字成功！\n");
	struct sockaddr_un addr={0};
	addr.sun_family=AF_UNIX;
	memcpy(addr.sun_path, "cs.sock",strlen("cs.sock"));
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("connect error:%m\n"),exit(-1);
	printf("绑定地址成功...........\n");
	while(1)
	{	
		/*memset(buf,'\0',sizeof(buf));
		r=read(fd,buf,sizeof(buf));
		buf[r]='\0';
		*/
		write(fd,"hello-->",strlen("hello-->"));
		sleep(2);  //流数据没有边界
		i++;
		if(i==10) break;
	}
	close(fd);
	return 0;
}
