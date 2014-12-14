#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<error.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main(int argc ,char* argv[])
{
	int fd,ffd,r;
	int len;
	char buf[128];
	struct sockaddr_in addr;
	fd=socket(AF_INET,SOCK_STREAM,0);
		if(fd==-1)printf("socket error:%m\n"),exit(-1);
	printf("socket success\n");
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	inet_aton("127.0.0.1",&addr.sin_addr);
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("connect error:%m\n"), close(fd),exit(-1);
	printf("连接服务器成功！\n");
	ffd=open(argv[1],O_RDONLY);
		if(ffd==-1)printf("open file fail:%m\n"),close(fd),exit(-1);
	printf("open success!\n");
	printf("开始发送文件.......\n");
	len=strlen(argv[1]);
	r=send(fd,&len,sizeof(len),0);
	r=send(fd,argv[1],len,0);
		if(r==-1)printf("发送失败：%m\n"),close(fd),exit(-1);
	printf("发送文件名成功！\n");
	while(1)
	{
		len=read(ffd,buf,128);
			if(len==-1) break;
			if(len==0)break;
			if(len>0)
			{
				//先发送本次文件内容的长度！
				r=send(fd,&len,sizeof(len),0);
					if(r==-1)break;
				//本次发送的内容
				r=send(fd,buf,len,0);
					if(r==-1)break;
			}
	}
	len=0;
	r=send(fd,&len,sizeof(len),0);
	close(ffd);
	close(fd);
	printf("发送文件完成！\n");
	return 0;
}















































