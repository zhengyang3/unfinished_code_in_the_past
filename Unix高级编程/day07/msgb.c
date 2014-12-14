#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<strings.h>
#include<sys/msg.h>
struct msgbuf
{
	long type;
	char data[32];		
};
int main()
{
	key_t key=0;
	int msgid=0;
	int i;
	key=ftok(".",1);
		if(key==-1) printf("ftok error:%m\n"),exit(-1);
	msgid=msgget(key,0);
		if(msgid==-1)printf("msgget error:%m\n"), exit(-1);
	struct msgbuf msg={0};
	while(1)
	{
		bzero(&msg,sizeof(msg));
		msg.type=1;
		msgrcv(msgid,&msg,sizeof(msg.data),1,0);
		printf("%s\n",msg.data);
	}
	return 0;
}
