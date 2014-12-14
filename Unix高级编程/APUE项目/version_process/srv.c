#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<error.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int fd=0;
    int cfd=0;
    int r=0;
    int len=0;
    char buf[128];
    int i=0;
    char* ret=0;
    FILE* tfd=NULL;
    FILE* ffd=NULL;
    struct sockaddr_in addr;
    fd=socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family=AF_INET;
    addr.sin_port=htons(11111);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
    r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
        if(r==-1)printf("bind error:%m\n"),exit(-1);
	printf("bind success!\n");
    r=listen(fd,100);
        if(r==-1)printf("listen error:%m\n"),exit(-1);
	printf("listen success!\n");
	
	
    cfd=accept(fd,0,0);
        if(cfd==0)printf("accept error:%m\n");
	printf("accept success!\n");
    while(1)
    {		
	r=recv(cfd,&len,4,MSG_WAITALL);
            if(r==-1)printf("recv error:%m\n"),exit;
	r=recv(cfd,buf,len,MSG_WAITALL);
	    if(r==-1)printf("recv error:%m\n"),exit;
	buf[r]='\0';
	if(strncmp("cmd",buf,3)!=0 && strncmp("get",buf,3)!=0 )
	{
	    strcpy(buf,"命令格式错误，请重新输入！");
	    len=strlen(buf);
	    send(cfd,&len,4,0);
	    send(cfd,buf,len,0);
	    continue;
	}
	if(strncmp("cmd",buf,3)==0)
	{
	    for(i=3;buf[i]==' ';i++);
	    strcpy(buf,&buf[i]);
	    ffd=popen(buf,"r");

            strcpy(buf,"cmd");
	    len=strlen(buf);
            send(cfd,&len,4,0);
	    send(cfd,buf,len,0);
	    while(1)
            {	//每读一次，立即发一次，接收端马上打印出来，只要没有\n看起来就像一次接收的！
	        ret=fgets(buf,127,ffd); 
	            if(ret==NULL)
		    {
		        strcpy(buf,"已发送完成！");
			len=strlen(buf);
			send(cfd,&len,4,0);
			send(cfd,buf,len,0);
		        break;
		    }
                len=strlen(buf);
	        send(cfd,&len,4,0);
	        send(cfd,buf,len,0);				
	    }
	}
	if(strncmp("get",buf,3)==0)
	{
	    for(i=3;buf[i]==' ';i++);
	    strcpy(buf,&buf[i]);
            //get /root/Unix高级编程
	   tfd= fopen(buf,"r+");
	   if(tfd==NULL)
	   {
	       strcpy(buf,"该文件不存在，请重新输入！");
	       len=strlen(buf);
	       send(cfd,&len,4,0);
	       send(cfd,buf,len,0);
	       continue;
	   }
           strcpy(buf,"get");
	   len=strlen(buf);
           send(cfd,&len,4,0);
	   send(cfd,buf,len,0);
           while(1)
           {	//每读一次，立即发一次，接收端马上打印出来，只要没有\n看起来就像一次接收的！
	       ret=fgets(buf,127,tfd); 
	           if(ret==NULL)
		   {
		       strcpy(buf,"已到文件尾！");
                       len=strlen(buf);
	               send(cfd,&len,4,0);
	               send(cfd,buf,len,0);	
		       fclose(tfd);
		       break;
		   }
               len=strlen(buf);
	       send(cfd,&len,4,0);
	       send(cfd,buf,len,0);				
	   }


	}

     }
	return 0;
}

































