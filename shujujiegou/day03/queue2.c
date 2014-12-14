//queue
//1 is emty
//2 is full
//3 push
//4 pop
//list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
static int size=0;
//1 is emty
int is_empty()
{
   if(size==0)
   {
      puts("queue id empty!");
      return 0;
   }
   return 1;
}
//2 is full
int is_full()
{
   if(size==10)
   {
       puts("queue is full!");
       return 1;
   }
   return 0;
}

//3 push
void push(Node** head,Node** new_Node)
{
  if(*head==NULL)
  {
       *head=*new_Node;
       size++;
       return;
  }
  Node* p=*head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=*new_Node;
  size++;
}
//4 pop
void pop(Node** head)
{
    if(is_empty()==0)return;
    Node* p=NULL;
    p=*(head);
    printf("pop--data:%d\n",p->data);
    *(head)=(*head)->next;
    
    free(p);
    size--;
    
}
int main()
{
   Node* a1=(Node*)malloc(sizeof(Node));
   memset(a1,0,sizeof(a1));
   a1->data=1;
  
   Node* a2=(Node*)malloc(sizeof(Node));
   memset(a2,0,sizeof(a2));
   a2->data=2;

   Node* a3=(Node*)malloc(sizeof(Node));
   memset(a3,0,sizeof(a3));
   a3->data=3;

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









