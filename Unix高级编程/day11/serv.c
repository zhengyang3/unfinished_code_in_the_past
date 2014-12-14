#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct Node{
		char user_name[32];
		char user_pass[32];
		struct Node* next;
};
typedef struct Node Node;
Node* head=NULL;
void insert (Node** head,Node** new_Node)
{
	if(*head==NULL) 
	{
		*head=*new_Node ;
		return;
	}
	Node* p=*head;
	while(p->next!=NULL)
	{
		p=p->next;		
	}
	p->next=*new_Node;
	
}
int find(Node** head,Node** user_Node)
{
	Node* p=(*head);
	while(p!=NULL)
	{	
		if(strcmp(usr_Node->user_name,p->user_name)==0)
		{
			if(strcmp(usr_Node->user_name,p->user_name)==0)
			{
				return 1;
			}else
			{
				return 2;
			}
		}
		p=p->next;
	}
	return 3;
}

int main()
{
	int fd=0;
	int cfd=0;
	int r=0;
	char* tmp=NULL;
	fd=socket(AF_INET,SOCK_STREAM,0);
	 	if(fd==-1)printf("socket error:%m\n"),exit(-1);
	 struct sockaddr_in addr={0};
	 addr.sin_family=AF_INET;
	 addr.sin_port=htons(11111);
	 addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	 r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	 	if(r==-1)printf("bind error:%m\n"),close(fd),exit(-1);
	 printf("服务器建立成功！\n");
	 r=listen(fd,10);
	 	if(r==-1)printf("listen error:%m\n"),close(fd),exit(-1);
	 cfd=accept(fd,0,0);
	 	if(cfd==-1)printf("accept error:%m\n"),close(fd),exit(-1);
	 
	 while(1)
	 {
	 	tmp=(char*)malloc(50);
	 	memset(tmp,0,50);
	 	r=recv(cfd,tmp,50,MSG_WAITALL);
	 	if((*(int*)(tmp+46))==1)	
	 	{
			puts("注册中....");
			Node* new_p=(Node*)malloc(sizeof(Node));
			memset(new_p,'\0',sizeof(Node));
			strcpy(new_p->user_name,(char*)(tmp+16));
			strcpy(new_p->user_pass,(char*)(tmp+31));
			insert(&head,&new_p);
			char* res_data=(char*)malloc(35);
			memset(res_data,0,35);
			*((int*)(res_data+12))=3;
			strcpy((char*)(res_data+16),new_p->user_name);
			*((int*)(res_data+31))=1;
			send(cfd,res_data,35,0);
			free(res_data);	
	 	}
	 	if((*(int*)(tmp+46))==2)
	 	{
	 		puts("登陆中......");
	 		Node* new_p=(Node*)malloc(sizeof(Node));
			memset(new_p,'\0',sizeof(Node));
			strcpy(new_p->user_name,(char*)(tmp+16));
			strcpy(new_p->user_pass,(char*)(tmp+31));
			int i=0;
			i=find(&head,&new_p);
			char* res_p=(char*)malloc(35));
			memset(res_p,'\0',35);
			*(int*)(res_p+12)=12;
			strcpy((char*)(res_p+16),new_p->user_name);
			*((int*)res_p+31)=i;
			r=send(cfd,res_p,35,0);
			free(res_p);
			free(new_p);
			if(i==1) 
			{
						
			}
			if(i==2)
			{
			
			}
			if(i==3)
	 		{
	 		
	 		}
	 	}
	 }
	 close(cfd);
	 close(fd);
	 return 0;
}
