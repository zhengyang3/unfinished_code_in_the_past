#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
	int data;
	struct Node* next;
};
type struct Node Node;
static int size=0;
int is_empty()
{
    if(size==0)
    {
	puts("queue is empty!");
	return 0;    
    }
    return 1;
}

int is_full()
{
    if(size==10)
    {
	puts("queue is full");
	return 1;    
    }
    return 0;
}
void push(Node* head,Node* new_Node)
{   
    if(head==NULL)
    {
	head=new_Node;
	size++;
	return;
    }
    Node* p=head;
    while(p->next!=NULL)
    {
	p=p->next;
    }
    p->next=new_Node;
}


void pop(Node** head)
{
    if(is_empty==0) return;
    Node* p=NULL;

    *(head)=(*head)->next;
    
}


















