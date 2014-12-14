#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
/*
void travel(Node* head)
{
    

}
*/
void print(Node* head)
{   
    Node* p=NULL;
    p=head;
    while(1)
    {
	printf("data:%d\n",p->data);

    
    }
    printf("")

}

void insert_at_head(Node* head,Node* new.node)
{
    Node* p=NULL;
    p=head;
    new.next=p;

}


void insert(Node* head ,Node* new_Node,int pos)
{
    




}


void del_Node(Node* head,int pos)
{
    Node* p=head;
    Node* pn=NULL;
    int i=0;
    for(i=1;i<pos-1;i++)
    {
	p=p->next
    }
    pn=p->next;
    p->next=pn->next;
    free(pn);//如果是用malloc赋值的话，必须释放。
    
}


// 查询函数
void find_user(Node* head,int id)
{   
    Node a;
    Node* p=NULL;
    p=head;
    int n=id
    int i=0;
    while(a.id!=n)
    {
	for(;;)
	{
	    
	
	
	}
    
    
    }


}



int main()
{
    Node a1={1,NULL};
    Node a2={2,NULL};
    Node a3={3,NULL};
    Node a4={4,NULL};
    a1.next=&a2;
    a2.next=&a3;
    print(&a1);
    insert_tail(&a1,&a4);
    puts("------------------");
    print(&a1);
    Node































    return 0;
}
