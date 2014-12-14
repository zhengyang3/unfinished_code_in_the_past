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
	int msgid=0;
	key_t key=0;
	int i=0;
	key=ftok(".",1);
		if(key==-1) printf("ftok error:%m\n"),exit(-1);
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0666);
		if(msgid==-1)printf("msgget error:%m\n"),exit(-1);
	struct msgbuf msg={0};	
	for(i=1;i<=20;i++)
	{
		//以下三步是构建消息 
		bzero(msg.data,sizeof(msg.data));
		msg.type=1;
		//sprintf(msg.data, "MSG:%d",i);
		printf("请输入消息：");
		scanf("%s",msg.data);
		msgsnd(msgid,&msg,sizeof(msg.data),0);
		sleep(1);
	}	
	msgctl(msgid,IPC_RMID,0);
	return 0;
}


















