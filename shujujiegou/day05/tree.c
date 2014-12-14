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
void travel(tree** root)
{
   if((*root)==NULL)return;
   printf("%d\n",(*root)->data);
   travel(&((*root)->left));
   travel(&((*root)->right));
}
//2 clear
void clear(tree** root)
{
  if((*root)==NULL)
  {
      return;
  }
  clear(&((*root)->left));
  clear(&((*root)->right));
  free(*root);
  *root=NULL;
}
//3insert
void insert(tree** root,tree** new_Node)
{
   if((*root)==NULL&&(*new_Node)==NULL)return;

   if((*root)==NULL)
   {
      (*root)=(*new_Node);
      return;
   }
   if((*new_Node)->data<(*root)->data)
   {
      //放到左子树
      insert(&((*root)->left),new_Node);
   }else{
      //放到右子树
     insert(&((*root)->right),new_Node);
   }
}
// 在二叉树种查找某一个指定元素
tree* search(tree** root,int a)
{

  printf("search_root:%p\n",*root);
    if((*root)==NULL)return NULL;
    if(((*root)->data)==a)return (*root);
    if(a<(*root)->data)
    {
     
            return search(&((*root)->left),a);
    }
    if(a>(*root)->data){ 
            return search(&((*root)->right),a);
    }
    
}
void search_xxx(tree** root,int a,tree** p)
{


  if((*root)==NULL)return;
  search_xxx(&((*root)->left),a,p);
  if((*root)->data==a)
  {
     *p=(*root);
  }
  search_xxx(&((*root)->right),a,p);
}
tree* search_root(tree** root,tree** p)
{

  if((*root)==NULL)return NULL;
  if((*root)->left==*p||(*root)->right==(*p))return *root;
  if((*p)->data<(*root)->data){
        return search_root(&((*root)->left),p);
    }
   if((*p)->data>(*root)->data){
       return search_root(&((*root)->right),p);
    }
}
void del(tree** root,int a)
{
  tree* p=NULL;
  tree* p_root=NULL;
  p=search(&(*root),a);
  printf("del p:%p\n",p);
  p_root=search_root(&(*root),&p);
  printf("del proot:%p\n",p_root);
    if(p==p_root->left)
   {
       p_root->left=NULL;
       if(p->left!=NULL)
       {
           insert(&p_root,&(p->left));
       }
       if(p->right!=NULL)
       {
            insert(&p_root,&(p->right));
       }
      
    }
    if(p==p_root->right)
    {
         p_root->right=NULL;
        if(p->right!=NULL)
        {
            insert(&p_root,&(p->right));
        }
        if(p->left!=NULL)
        {
           insert(&p_root,&(p->left));
        }

    }
 
  free(p);
  p=NULL;
}



int main()
{
  tree* root=NULL;
  tree* a1=(tree*)malloc(sizeof(tree));
  memset(a1,0,sizeof(tree));
  a1->data=1;

  tree* a2=(tree*)malloc(sizeof(tree));
  memset(a2,0,sizeof(tree));
  a2->data=2;
  
  tree* a3=(tree*)malloc(sizeof(tree));
  memset(a3,0,sizeof(tree));
  a3->data=3;

  tree* a4=(tree*)malloc(sizeof(tree));
  memset(a4,0,sizeof(tree));
  a4->data=4;

  tree* a5=(tree*)malloc(sizeof(tree));
  memset(a5,0,sizeof(tree));
  a5->data=5;
  insert(&root,&a3);
  insert(&root,&a1);
  insert(&root,&a2);
  insert(&root,&a4);
  insert(&root,&a5);
  tree* ptr=NULL;
  ptr=search(&root,1);
  printf("ptr:%p\n",ptr);
  printf("ptr:%d\n",ptr->data);

  tree* p=search_root(&root,&ptr);
  printf("p:%p\n",p);
  printf("p:%d\n",p->data);
  del(&root,2);
  travel(&root);
 return 0;
}






