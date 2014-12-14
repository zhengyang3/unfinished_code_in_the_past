#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Reg
{
	char user[15];
	char psd[20];
	char Email[35];
	char name[15];
	char gender[10];
	int  age;
};

struct Reg_info
{
	struct Reg data;
	struct Reg_info* next;
};
typedef struct Reg Reg;
typedef struct Reg_info Reg_info;



//函数声明专区
void UI();
void Login();
void Register();
void Password_retake();
void Reg_list();



//全局变量
Reg_info* head=NULL;





//从文件中读取数据生成链表
void Reg_list()
{
	FILE* fp=NULL;
	fp=fopen("reg.dat","a+");	
	Reg_info* p=NULL;
	p=(Reg_info*)malloc(sizeof(Reg_info));
	memset(p,0,sizeof(Reg_info));
	fread(&(p->data),sizeof(Reg),1,fp);
	head=p;
	Reg_info* tmp=NULL;
	int ref=1;
	while(ref>0)  //不断地分配空间，却又要不指定变量名，只有地址变量能做到；
	{			
		tmp=(Reg_info*)malloc(sizeof(Reg_info));
		memset(tmp,0,sizeof(Reg_info));
		ref=fread(&(tmp->data),sizeof(Reg),1,fp);
		if(ref>0)
		{
		puts("正在构建链表！");
		p->next=tmp;
		p=tmp;
		}
		if(ref<0) break;
	}	
	puts("链表生成成功！");
	fclose(fp);
}




//在链表尾部插入数据
void Reg_list_tail(Reg_info* head, Reg_info* new)
{	
	if(head==NULL) 
	{
		head=new;
		return;
	}
	Reg_info* p=head;
	while(p->next!=NULL)
	{				
		p=p->next;		
	}
	p->next=new;	

}





void print(Reg_info* head)
{
	Reg_info* p=head;
	int i=0;
	if(p==NULL) return;
	while(p!=NULL)
	{	
		
		printf("%s\n",(p->data).user);
		if(p->next==NULL) return;
		else p=p->next;		
	}
}





void Login()
{	
	int i=1;
	int k=0;
	char b[5]={0};
	static int j=0;
	Reg a={0};
	Reg_info* p=head;
	printf("            用户登陆\n");
	printf("     用户名：");
	scanf("%s",&a.user);
	while(i!=0 && p!=NULL)
	{
		i=strcmp(p->data.user, a.user);
		if(0==i) break;
		if(p->next==NULL)
		{	
			k++;
			j++;
			break;		
		}
		p=p->next;
	}
	
	printf("     密码：");
	scanf("%s",&a.psd);
	if(1==k) 
	{	
		
		if(5==j) 
		{
			j=0;
			printf("用户名不存在，请按任意键转入主界面！");
			scanf("%s",&b);
			return UI();			
		}
		printf("用户名不存在，您还有%d次机会！\n",5-j);
		return Login();
	}
	if(strcmp(p->data.psd, a.psd)==0) 
	{
		printf("登陆成功！\n");
		j=0;
		return UI();
	}	
	if(strcmp(p->data.psd, a.psd)!=0)
	{
		
		j++;
		if(5==j) 
		{
			j=0;
			printf("密码错误，请按任意键转入主界面！");
			scanf("%s",&b);
			return UI();
		}
		printf("密码错误，您还有%d次机会！\n",5-j);
		return Login();
	}

}




void Register()
{
	Reg a={0};	
	Reg_info* b=NULL;  //Reg_info b={0};  错误！
	b=(Reg_info*)malloc(sizeof(Reg_info));
	memset(b,0,sizeof(Reg_info));
	FILE* fp=NULL;
	fp=fopen("reg.dat","a+");	
	printf("            用户注册\n");
	printf("      用户名：");
	scanf("%s",&a.user);
	printf("      密码：");
	scanf("%s",&a.psd);
	printf("      邮箱：");
	scanf("%s",&a.Email);
	printf("      姓名：");
	scanf("%s",&a.name);
	printf("      性别：");
	scanf("%s",&a.gender);
	printf("      年龄：");
	scanf("%d",&a.age);
	printf("\n");	
	fwrite(&a,sizeof(Reg),1,fp);
	b->data=a;
	Reg_list_tail(head,b);
	fclose(fp);
	printf("注册成功\n");
	return UI();
}


void Password_retake()
{	
	int i=1;
	static int j=0;
	char b[5]={0};
	Reg a={0};
	Reg_info* p=head;
	printf("            找回密码\n");
	printf("      用户名：");
	scanf("%s",a.user);
	while(i!=0 && p!=NULL)
	{
		i=strcmp(p->data.user, a.user);
		if(i==0) break;
		if(p->next==NULL)
		{
			j++;
			if(j==5) 
			{
				j=0;	
				printf("用户名不存在，请按任意键转入主界面！！\n");
				scanf("%s",&b);
				return UI();
			}
			printf("用户名不存在，您还有%d次机会！\n",5-j);
			return Password_retake();		
		}
		p=p->next;
	}
	while(1)
	{
		printf("      邮箱：");
		scanf("%s",a.Email);	
		if(strcmp(p->data.Email, a.Email)!=0)
		{			
			j++;
			if(j==5) 
			{
				j=0;
				printf("邮箱错误，请按任意键转入主界面！！\n");
				scanf("%s",&b);
				return UI();
			}
			printf("邮箱错误，您还有%d次机会！\n",5-j);
		}
		if(strcmp(p->data.Email, a.Email)==0)
		break;
	}
	while(1)
	{
		printf("      姓名：");
		scanf("%s",a.name);
		if(strcmp(p->data.name, a.name)!=0)
		{
			
			j++;
			if(j==5) 
			{
				j=0;
				printf("姓名错误，请按任意键转入主界面！！\n");
				scanf("%s",&b);
				return UI();
			}
			printf("姓名错误，您还有%d次机会！\n",5-j);
		}
		if(strcmp(p->data.name, a.name)==0)
		break;		
	}
	while(1)
	{
		printf("      性别：");
		scanf("%s",a.gender);
		if(strcmp(p->data.gender, a.gender)!=0)
		{
			
			j++;
			if(j==5) 
			{
				j=0;
				printf("性别错误，请按任意键转入主界面！！\n");
				scanf("%s",&b);				
				return UI();
			}
			printf("性别错误，您还有%d次机会！\n",5-j);
		}
		if(strcmp(p->data.gender, a.gender)==0)
		break;			
	}
	while(1)
	{
		printf("      年龄：");
		scanf("%d",&a.age);  //整型要取地址符！
		if(p->data.age != a.age)
		{
			
			j++;
			if(j==5) 
			{
				j=0;
				printf("年龄错误，请按任意键转入主界面！！\n");
				scanf("%s",&b);	
				return UI();
			}
			printf("年龄错误，您还有%d次机会！\n",5-j);
		}
		if(p->data.age == a.age)
		break;					
	}
	j=0;
	printf("\n");
	printf("您的密码是：%s\n",p->data.psd);	
	return UI();
	
}

void UI()
{
	int i=0;
	printf("++++++++++++++++++++++++++\n");
	printf("请选择入口:              +\n");
	printf("                         +\n");
	printf("            用户登陆     +\n");
	printf("    1：登陆              +\n");
	printf("    2: 注册              +\n");
	printf("    3: 找回密码          +\n");
	printf("                         +\n");
	printf("++++++++++++++++++++++++++\n");
	//printf("\n");
	printf("请输入序号:");
	scanf("%d",&i);
	
	
	if(1==i) Login();
	else if(2==i) Register();
	else if(3==i) Password_retake();
	else 
	{
		puts("输入错误,请重新输入");
		return UI();
	}
}


int main()
{
		

	Reg_list();	
	//print(head);
	//UI	();
	UI	();
	//print(head);
	//UI();
	return 0;

}

















