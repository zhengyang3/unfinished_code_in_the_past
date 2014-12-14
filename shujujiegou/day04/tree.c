#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
void clear(tree** root)
{
    

}
typedef struct Node tree;
void print(tree** root)
{
    if(*root=NULL)
    {
	printf("empty!");
    }
    tree* p=*root;
    if(p==NULL) return;
    printf("%d\n-->>",p->data);
    print(&(p->left));
    print(&(p->right));

}
int main()
{
    tree* a1=NULL;
    a1=(tree*)malloc(sizeof(tree));
    memset (a1,0,sizeof(tree));
    a1->data=1;

     tree* a2=NULL;
     a2=(tree*)malloc(sizeof(tree));
     memset (a2,0,sizeof(tree));
     a2->data=2;


     tree* a3=NULL;
     a3=(tree*)malloc(sizeof(tree));
     memset (a3,0,sizeof(tree));
     a3->data=3;


     tree* a4=NULL;
     a1=(tree*)malloc(sizeof(tree));
     memset (a4,0,sizeof(tree));
     a4->data=4;

    

     tree* a5=NULL;
     a5=(tree*)malloc(sizeof(tree));
     memset (a5,0,sizeof(tree));
     a5->data=5;



    tree* root = NULL;
    root = a1;
    a1->left=&a2;
    a2->right=&a3;
    a1->right=&a4;
    a4->left=&a5;
    printf(&root);

    return 0;
}
