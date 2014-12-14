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
int main()
{
	int sfd,cfd,ffd;
	int r;
	int len;
	char filename[320];
	char buf[128];
	struct sockaddr_in addr;
	sfd=socket(AF_INET,SOCK_STREAM,0);
		if(sfd==-1) printf("socket error!\n"),exit(-1);
	printf("建立服务器成功！\n");
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("bind error:%m\n"),exit(-1);
	printf("bind success\n");
	r=listen(sfd,10);
		if(r==-1)printf("listen error:%m\n"),exit(-1);
	cfd=accept(sfd,0,0);
		if(cfd==-1)printf("accept error:%m\n"),exit(-1);
	printf("开始接收文件..........\n");
	r=recv(cfd,&len ,sizeof(len),0);
	printf("文件名的长度：%d\n",len);
	r=recv(cfd,filename,len, 0);
	filename[len]='\0';
	printf("传输的文件名是：%s\n",filename);
	ffd=open(filename,O_RDWR|O_CREAT|O_EXCL,0666);
		if(ffd==-1) printf("创建文件:%m\n"),exit(-1);
	while(1)
	{
		r=recv(cfd,&len,sizeof(len),0);
			if(len==0) break;
		printf("file length:%d\n",len);
			r=recv(cfd,buf,len,0);
			write(ffd,buf,len);
	
			
	}
	close(ffd);
	close(cfd);
	close(sfd);
	printf("接收文件完毕！\n");
	return 0;

}
























