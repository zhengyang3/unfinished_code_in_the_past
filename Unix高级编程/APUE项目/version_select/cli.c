#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<error.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int fd=0;
    int i=0;
    int r=0;
    int len=0;
    FILE* tfd=NULL;
    char buf[128]={0};
    char con[128]={0};
    struct sockaddr_in addr;
    fd=socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family=AF_INET;
    addr.sin_port=htons(11111);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
 	if(r==-1)printf("connect error:%m\n");
	printf("connect success!\n");
    while(1)
    {	
	printf("请输入：");
	fgets(buf,127,stdin);
	buf[strlen(buf)-1]='\0';
	//没考虑如果输入了127个字符的情况（没有\n）
	len=strlen(buf);
	if(strncmp(buf,"get",3)==0)
	{
	    for(i=(len-1);buf[i]!='/';i--);
	    strcpy(con,"/root/Unix高级编程/APUE项目/downloads");
	    strcat(con,&buf[i]);
        }
	send(fd,&len,4,0);
	send(fd,buf,len,0);
        r=recv(fd,&len,4,MSG_WAITALL);
            if(r==-1)printf("recv error:%m\n"),exit(-1);
        r=recv(fd,buf,len,MSG_WAITALL);
            if(r==-1)printf("recv error:%m\n"),exit(-1);
        buf[r]='\0';
        if(strcmp(buf,"命令格式错误，请重新输入！")==0)
        {
            printf("%s\n",buf);
            fflush(stdout);
            continue;
        }
        if(strcmp(buf,"cmd")==0)
        {
            while(1)
            {
                r=recv(fd,&len,4,MSG_WAITALL);
		    if(r==-1)printf("recv error:%m\n"),exit(-1);
	        r=recv(fd,buf,len,MSG_WAITALL);
		    if(r==-1)printf("recv error:%m\n"),exit(-1);
                buf[r]='\0';
		if(strcmp(buf,"已发送完成！")==0)
		{ 
		 break;
                }
                printf("%s",buf);
                fflush(stdout);
            }
        }
        if(strcmp(buf,"该文件不存在，请重新输入！")==0)
	{	    
            printf("%s\n",buf);
            fflush(stdout);
            continue;

	}

	if(strcmp(buf,"get")==0)
	{
            tfd=fopen(con,"a+");
            while(1)
            {
                r=recv(fd,&len,4,MSG_WAITALL);
		    if(r==-1)printf("recv error:%m\n"),exit(-1);
	        r=recv(fd,buf,len,MSG_WAITALL);
		    if(r==-1)printf("recv error:%m\n"),exit(-1);
                buf[r]='\0';
		if(strcmp(buf,"已到文件尾！")==0) 
		{  
		    fclose(tfd);
                    break;
                }
                fwrite(buf,strlen(buf),1,tfd);
	    }
	}

    }
    return 0;
}
















