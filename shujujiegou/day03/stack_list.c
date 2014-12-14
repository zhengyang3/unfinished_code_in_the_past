#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
struct Node{
      int data;
      struct Node* next;
};
static int size=0;
typedef struct Node Node;
//is_empty
int is_empty()
{
   if(size==0)
   {   
      puts("queue is empty!");
        return 0;
   }
   return 1;
}
//is_full
int is_full()
{
    if(size==5)
    {
       puts("queue id full!");
       return 1;
    }
    return 0;
}
//push
void push(Node** head,Node** new_Node)
{
  if((*head)==NULL)
  {
     (*head)=(*new_Node);
     size++;
     return;
  }
  Node* p=(*head);
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=(*new_Node);
  size++;
}
//pop
void pop(Node** head)
{
   puts("pop start!");
   printf("head:%p\n",(*head));
   if(0==is_empty())return;
 
   Node* p=NULL;
   p=(*head);

   int i=0;
   
   for(i=1;i<(size-1);i++)
   {
     printf("p:%p\n",p);
     p=p->next;
   }
   if(size==1)
   {
        printf("pop:%d\n",p->data);
       free(p);
       (*head)=NULL;
       size--;
       return;
   }
   printf("pop:%d\n",(p->next)->data);
   free(p->next);
   p->next=NULL;
   size--;
   puts("pop end!");
   
}
int main()
{

  Node* a1=(Node*)malloc(sizeof(Node));
  memset(a1,0,sizeof(Node));
  a1->data=1; 
  a1->next=NULL;


  Node* a2=(Node*)malloc(sizeof(Node));
  memset(a2,0,sizeof(Node));
  a2->data=2; 
  a2->next=NULL;

 
  Node* a3=(Node*)malloc(sizeof(Node));
  memset(a3,0,sizeof(Node));
  a3->data=3;
  a3->next=NULL;
 
  Node* head=NULL;
 
  push(&head,&a1);

  push(&head,&a2);

  push(&head,&a3);

  pop(&head);
  pop(&head);
  pop(&head);
  pop(&head);
 return 0;
}






