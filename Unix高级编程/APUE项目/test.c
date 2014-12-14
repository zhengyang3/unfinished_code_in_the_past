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
		    char buf[128]={0};
		    strcpy(buf,"111111111222222222223333333333");
	//strcpy(buf,buf+10);
rintf("%s\n",&buf[10]);
	
}
