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
	int r=0;
	int i=0;
	int fd=0;
	int cfd=0;
	int len=0;
	int max=0;
	char buf[128];
	struct sockaddr_in addr;
 
   fd_set rfds,wfds;
   struct timeval tv;
   int retval;

	
	
	fd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	
	r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1)printf("bind error:%m\n"),exit(-1);
	printf("bind success\n");
	r=listen(fd,10);
		if(r==-1)printf("listen error:%m\n"),exit(-1);
	
	max=(fd>cfd)?fd:cfd;

	FD_ZERO(&rfds);
	FD_SET(fd,&rfds);
	while(1)
	{
		for(i=0 ;i<=max;i++)
		{
			FD_SET(i,&rfds);
		}
		retval=select(max+1,&rfds,0,0,0);
		for(i=0;i<=max;i++)
		{
			if(FD_ISSET(i,&rfds))
			{
				if(i==fd)
				{
					cfd=accept(fd,0,0);
					
					max=(max>cfd)?max:cfd;	
				
				}
				else
				{	
					r=recv(i,&len,4,MSG_WAITALL);
					if(r==-1)
					{
						close(i);
						if(cfd==max)
						{
							max=i-1;
						}
						break;
					}
					r=recv(i,buf,len,MSG_WAITALL);
					buf[r]='\0';
      				printf("接收到的消息是：%s\n",buf);
      			
      				len=strlen(buf);
      				send(i,&len,4,0);
      				send(i,buf,len,0);	
				}
			}
		}
	  
      	
	}
	close(fd);
	
	
/*	
		if (retval == -1)
  			perror("select()");
  		
       else if (FD_ISSET(fd,&rfds))
        {
       	cfd=accept(fd,0,0);
       	if(cfd==-1)printf("accept error:%m\n"),exit(-1);
        }
       else if(FD_ISSET(cfd,&rfds))
		{
      		r=recv(cfd,buf,127,0);
      		printf("接收到%d个字节\n",r);
      		buf[r]='\0';
      		printf("接收到的消息是：%s\n",buf);
      		send(cfd,buf,strlen(buf),0);	
   		} 
      	FD_SET(fd,&rfds);
      	FD_SET(cfd,&rfds);
      	max=(fd>cfd)?fd:cfd;	
       
     } 
*/
	
	return 0;
}























