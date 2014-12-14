#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int data;
    
    struct Node* next;

};

typedef struct Node Node;

void print(Node* head)
{
    if(head==NULL)
    {
	puts("链表为空！");
	
	return -1;
    }

    Node* p = head;

    while(p!=NULL)
    {
	printf("%d\n",p->data);

	p = p->next;
    
    }


}

int sum (Node* head)
{
    int n=0;
    Node* p=head;
    while(p!=NULL)
    {
	n++;
	p=p->next;    
    
    }
	return n;
}

//在最后一个节点后面插入一个数据。
void insert (Node* head,Node* p)
{
    Node* p = head;

    while( p->next !=NULL)  //查找最后一个节点！
    {
	p=p->next;
    
    }
    p->next=n;  //将最后一个节点的next里面的值变成新创建的地址

}

//在链表的任意位置插入一个节点
void insert_pos(Node*head,Node*new_node,int pos)
{
    Node* p = head;
    int i=0;
    if(pos<0||pos>sum(p))
    {
	insert(p,new_node);
	return;
    }
    
    for (i=0;i<pos;i++)
    {
	p=p->next;   //next里面保存的是下一个节点整个的地址，包括date和next!
	break;    
    }
    (*new_node).next=p->next;
    p->next =new_node;


}







int main()
{
    Node a = {1,NULL};

    Node a1 = {2,NULL};

    Node a2 = {3,NULL};
     
    Node a3 = {4,NULL};
    
    Node a4 = {5,NULL};

    a.next = &a1;

    a1.next = &a2;

    a2.next = &a3;

    a3.next = &a4;
    
    print(&a); 



    int n = sum(&a);

    printf("总共有%d个节点！\n",n);




/*
    Node* p = NULL;
    
    p = &a;

    while(p != NULL)
    {
	printf("%d\n",p->data);

	p = p->next;
        
    }
*/
    

   
    return 0;
}
