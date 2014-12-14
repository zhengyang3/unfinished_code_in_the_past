#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<error.h>
#include<signal.h>
int main()
{
	int fd=0;
	int r=0;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("192.168.0.251");
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	write(fd,"sdfsdf时枯井",strlen("sdfsdf时枯井"));
	close(fd);
	
	
	
	return 0;
}
