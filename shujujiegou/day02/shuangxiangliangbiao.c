#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    struct Node* pre;
    int data;
    struct Node* next;
};
typedef struct Node Node;
void print(Node* p)
{   
    Node* ptr=NULL;
    ptr=p;   
    if(p==NULL)
    {
	puts("链表为空！");
	return;
    }
    if(p->next==NULL)
    {   
	while(ptr!=NULL)
	{
	printf("data:%d\n",p->data);
	ptr=ptr->pre;
	}
    }else{
	while(ptr!=NULL)
	{
	    printf("data:%d\n",p->data);
	    ptr=ptr->next;
	}
    }

}

void insert_tail(Node* head,Node* new_Node)
{
    Node* p=NULL;
    p=head;
    while(p->next!=NULL)
    {
	p=p->next;
    }
    p->next=new_Node;
    new_Node->pre=p;
}


int main()
{
    Node a1={NULL,1,NULL};
    Node a2={NULL,2,NULL};
    Node a3={NULL,3,NULL};
    Node a4={NULL,4,NULL};
    Node a5={NULL,5,NULL};
    a1.next=&a2;
    a2.pre=&a1;
    a2.next=&a3;
    a3.pre=&a2;
    a3.next=&a4;
    a4.pre=&a3;
    a4.next=&a5;
    a5.pre=&a4;
    printf(&a1);


    return 0;
}
