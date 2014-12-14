#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
 };
 typedef struct Node tree;
//1 travel
void travel (tree** root)
{
    if(*root==NULL) return;
    printf("%d\n",(*root)->data);
    travel(&((*root)->left));
    travel(&((*root)->right));

}

//2 clear
void clear(tree** root)
{
    if(*root==NULL) return;
    clear(&((*root)->left));
    clear(&((*root)->right));
    free(*root);
    *root=NULL;    
}

//3 insert
void insert(tree** root,tree** new_Node)
{
    if((*root)==NULL&&(*new_Node)==NULL) return;
    if(*root==NULL)
    {
	(*root)=(*new_Node);
	return;
    }
    if((*new_Node)->data<(*root)->data)
    {
	insert(&((*root)->left),new_Node);    
    }else{
	insert(&((*root)->right),new_Node);
    }

}

//在二叉树中查找某一个元素！
tree* search(tree** root,int a)
{
    if((*root)==NULL) return;
    if((*root)->data==a) return(*root);
    if(a<(*root)->data)
    {
	return search(&((*root)->left),a);
    }
    if(a>(*root)->data)
    {   
    search(&((*root)->right),a);
    }
}
//在二叉树中查找某一个元素的第二种方法！
void search_XXX(tree** root,int a,tree** p)
{
    if((*root)==NULL) return NULL;
    if((*root)->left==*p||(*root)->right==(*p)) return *root;
    search_XXX(&((*root)->left),a,p);
    if((*root)->data==a)
    {
	*p=(*root);
    }
    search_root(&((*root)->right),a,p);
}

void del(tree** root,int a)
{
    tree* p=NULL;
    tree* p_root=NULL;
    p=search(root,a);
    p_root=search_root(root,&p);
    if(p==p_root->left)
    {
	insert(&p_root,&(p->left));	
    }else{
	insert(&p_root,&(p->right));    
    }
    free(p);
    p=NULL;

}

tree* search_root(tree** root,tree** p)
{
    if((*root)==NULL) return;
    search_root(&((*root)->left),p);
    if((*root)->left==*p||(*root)->right==(*p))
    {
	return *root;
    }
    search_root(&((*root)->right),p);
}



int main()
{   
    tree* a1=(tree*)malloc(sizeof(tree));
    memset(a1,0,sizeof(tree)); 
    a1->data=1;
    tree*a2=(tree*)malloc(sizeof(tree)); 
    memset(a2,0,sizeof(tree)); 
    a1->data=2;
    tree*a3=(tree*)malloc(sizeof(tree));
    memset(a3,0,sizeof(tree)); 
    a3->data=3;
    tree*a4=(tree*)malloc(sizeof(tree));
    memset(a4,0,sizeof(tree));
    a4->data=4;
    tree*a5=(tree*)malloc(sizeof(tree));
    memset(a5,0,sizeof(tree)); 
    a5->data=5;

   tree* root=NULL;
    insert(&root,&a3);
    insert(&root,&a1);
    insert(&root,&a2);
    insert(&root,&a4);
    insert(&root,&a5);
    tree* ptr=NULL;
    search_XXX(&root,3,&ptr);
    //ptr=search(&root,3); 
    printf("ptr:\n",ptr);
    printf("a3:\n,a3");
    puts("-----------------");
    travel(&root);
    puts("-----------------");
//    del(&root,3);
    return 0 ;



}







