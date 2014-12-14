#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
	int fd=0;
	int r=0;
void UI_main()
{
	int i=0;
	printf("         用户管理系统\n");
	printf("    1:用户登陆\n");
	printf("    2:用户注册\n");
	printf("请选择需要的操作：");
	scanf("%d",&i);	
}
void UI_register()
{
	int i=0;
	printf("         用户注册\n");
	printf("    1:用户名\n");
	scanf()
	printf("    2:密码\n");
	
}
void UI_login()
{
	char user_name[32];
	char user_pass[32];
	memset(user_name,'\0',sizeof(user_name));
	memset(user_pass,'\0',sizeof(user_name));
	printf("         用户登陆\n");
	printf("    1:用户名\n");
	scanf("%s",&user_name);
	printf("    2:用户密码\n");
	scanf("%s",&user_pass);	
	//数据打包，使用fd发送
	char* tmp=NULL;
	tmp=(char*)malloc(50);
	memset(tem,0,50);
	*(int*)(tmp+12)=2;//这样就可以一次性操作4个字节
	strcpy((char*)(tmp+16),user_name);
	strcpy((char*)(tmp+31),user_pass);
	*(int*)(tmp+46)=1;
	send(fd,tmp,50,0);
		if(r==-1)printf("send error:%m\n"),close(fd),exit(-1);
	free(tmp);
	tmp=(char*)malloc(35);
	memset(tmp,0,35);
	r=recv(fd,tmp,35,MSG_WAITALL);
	printf("用户：%s",(char*)(tmp+16));
	if(*(int*)(tmp==31)==1)
	{
		printf("用户名不存在！\n");
	
	}
	if(*(int*)(tmp==31)==2)
	{
		printf("密码错误！\n");
		
	}
	if(*(int*)(tmp==31)==1)
	{
		printf("登陆成功！\n");
	
	}
	//getchar();
}
void UI choose(int i)
{
	while(1)
	{
		if(i==1)UI_login();
		if(i==2)UI_register();
	}
}

int main()
{

	fd=socket(AF_INET,SOCK_STREAM,0);
		if(fd==-1) printf("socket error:%m\n"),exit(-1);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(11111);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		if(r==-1)printf("connect error:%m\n"),close(fd),exit(-1);
	printf("连接服务器成功！\n");
	
	return 0;
}





















