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
	char buf[100];

	struct sockaddr_in addr;  // 本机ip
	struct sockaddr_in snd;  //发送者IP
	socklen_t len; //发送者IP长度
	int port=atoi(argv[2]);  //输入的是字符串，端口号是整型
	int r;
	//socket
	fd=socket(AF_INET,SOCK_DGRAM,0);
		if(fd==-1)printf("socket error:%m\n"),exit(-1);
	printf("socket 创建成功！\n");
	//sockaddr
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);  //本地字节序转换成网络字节序(unix系统之间可以不用转换)
	//addr.sin_addr.s_addr=inet_addr(argv[1])  //转换成4字节的IP地址网络字节序
	inet_aton(argv[1],&addr.sin_addr);  //转换成结构体的IP地址网络字节序（2选1）
	//bind
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1) printf("bind error:%m\n"),exit(-1);
	printf("bind success!\n");
	//write read
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		r=recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr*)&addr,&len);
		if(r>0)
		{
			buf[r]='\0';
			printf("发送者的IP:%s 端口：%hu  数据：%s\n",inet_ntoa(snd.sin_addr),snd.sin_port,buf);
		}
		if(r==0)
		{
			printf("close!用户退出！\n");
			break;
		}
		if(r==-1) 
		{
			printf("网络故障！\n");
			break;
		}
	}
	
	//close
	close(fd);
	return 0;
}












