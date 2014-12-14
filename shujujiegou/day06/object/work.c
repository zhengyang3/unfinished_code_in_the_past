#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"object.h"
void print(char* name,char* pass)
{
	int i=0;
    int j=0;
    for (i=0;i<20;i++)
    {
	printf("_");
    }
    printf("\n");
    for (j=0;j<10;j++)
    {
	for (i=0;i<20;i++)
	 {
	    if(i==0||i==19) printf("|");
	    printf(" ");
	
	 } 
	 printf("\n");
     }
    for (i=0;i<20;i++)
     {
         printf("_");
     }
    printf("\n");

}
void fun()

void insert_tail(user_Node** head,user_Node** new_Node)
{
    if(*head==NULL)
    {
	*head = *new_head;
	return;

    }
    user_Node* p=*head;
    while (p->next!=NULL)
    {
	p=p->next;    
    }
    p->next=*new_Node;
}

void print_list(user_Node** head)
{
    user_Node* p=*head;
    while(p!=NULL)
    {
	printf("ID:%d\n",p->id);
	p=p->next;
    }
}

void fun ()
{
    



}


void load_user_info(user_Node** head)
{
   FILE* fp=NULL;
   fp=fopen()


}






















int main()
{
    user_Node*head=NULL;
    load_user_info(&head);
    char name[15]={0};
    char pass[15]={0};
    print(name,pass);


    return 0;
}























