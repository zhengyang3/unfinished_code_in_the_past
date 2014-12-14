#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
     int data;
     int id;
     char user_name[15];
     int  LV;
     struct Node* next;    
};
typedef struct Node Node;
/*void travel(Node* head)
{
   
}*/
//查找ID号为多少的用户信息
void find_user(Node* head,int id)
{
   Node* p=NULL;
   p=head;
   while(p!=NULL)
   {
     if(p->id==id)
     {
         printf("ID:%d\n",p->id);
         printf("user name:%s\n",p->user_name);
         printf("user LV:%d\n",p->LV);
         return;
     }
     p=p->next;
   }
   printf("user not found!!!!\n");
}
    
void print(Node* head)
{
  Node* p=NULL;
  p=head;
  while(p!=NULL)
  {
    printf("data:%d\n",(*p).data);//p->data
    p=p->next;
  }
}
int size(Node* head)
{
  int sum=0;
  Node* p=head;
  while(p!=NULL)
  {
     sum++;
     p=p->next;
  }
  return sum;
}
//在链表的末尾添加节点
void insert_tail(Node* head,Node* new_Node)
{
  if(head==NULL)
  {
     head=new_Node;
     return;
  }
  Node* p=head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=new_Node;
}
//始终在链表的前面添加节点
void insert_head(Node* head,Node* new_Node)
{
  if(head==NULL)
  {
      head=new_Node;
      return;
  }
  new_Node->next=head;
  
}
//在指定位置处插入节点
void insert(Node* head,Node* new_Node,int pos)
{
   int i=0;
   Node* p=head;
    //如果输入的节点数等于0的话就是直接插入到第一个位置
    if(pos==0)
    { 
       insert_head(head,new_Node); 
       return;
    }
    //如果输入的节点位置数不规范统一的插入到最后一个位置去
    if(pos<0||pos>size(head))
     { 
         insert_tail(head,new_Node);
         return;
     }
    for(i=1;i<pos;i++)
    {
      p=p->next;
    }
   new_Node->next=p->next;
   p->next=new_Node;
}
void clear(Node* head)
{
   Node* p=NULL;
   
   while(head!=NULL)
   {
      p=head->next;
      free(head);
      head=p;
   }
}
//删除指定位置的节点
void del_Node(Node* head,int pos)
{
  Node* p=head;
  Node* pn=NULL;
  int i=0;
  for(i=1;i<pos-1;i++)
  {
     p=p->next;
  }
  pn=p->next;
  p->next=pn->next;
  free(pn);
  
}
//逆序链表第一种方法：
Node* rev(Node*head)
{
    Node* p=NULL;
    if(head==NULL)
    {
	return head;    
    }
    Node* pre,*cur,*ne;
    pre=head;
    cur=head->next;
    while(cur!=NULL)
    {
	ne=cur->next;
	cur->next=pre;
	pre=cur;
	cur=ne;
    }
    head->next=NULL;
    head=pre;
}
//逆序第二种方法：递归法
Node* new_rev(Node* p,Node* head)
{
    if(p==NULL||p->next==NULL)
    {
	
	head=p;
	return p;    
    }
    Node* tmp=new_rev(p->next,head);
    tmp->next=p;
    return p;

}
int main()
{
  Node a1={1,1,"aaaaaa",1,NULL};
  Node a2={2,2,"bbbbb",12,NULL};
  Node a3={3,3,"cccccc",15,NULL};
  Node a4={4,4,"hjahssd",100,NULL};
  
  Node* ptr=NULL;
  ptr=(Node*)malloc(sizeof(Node));

  a1.next=&a2;
  a2.next=&a3;
  print(&a1);
  insert_tail(&a1,&a4);
  puts("------------------");
  print(&a1);
  Node a5={5,5,"hjah123",88,NULL};
  insert_head(&a1,&a5);
  puts("-++++++++++++++++++++++-");
  print(&a5);
  Node a6={6,6,"hjahs123123sd",97,NULL};
  insert(&a5,&a6,2);
  puts("-++++++++++++++++++++++-");
  print(&a5);
  puts("-++++++-");
  // find_user(&a5,3);
  print(new_rev(&a5,&a5));
  return 0;
}




