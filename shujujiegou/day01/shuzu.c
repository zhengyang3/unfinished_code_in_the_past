#include<stdio.h>
#include<stdlib.h>
void append(int n,int** a)  // 数组扩容函数
{
    if(a==NULL)
    {
	*a=(int*)malloc(sizeof(int)*n);
	
    }else{
	*a=(int*)realloc(a,n*2*4);
    }

}

int main()
{
    int* p=NULL;
    append(5,&p);
    int i=0;
    for(i=0;i<5;i++)
    {
	*(p+i)=i;
	    
    }
    for(i=0;i<5;i++)
    {
	printf("%d\n",*(p+i));
    }
    append(10,&p);//再次扩容 ；
    


  /*  int* p=NULL;
    int* ptr=NULL;
    //  int a[5];
    p=(int*)malloc(sizeof(int)*5);  //在堆里面分配
    memset(p,0,20);
    *p=1;
    *(p+1)=2;  //移动四个字节；
    *(p+2)=3;
    *(p+3)=4;
    *(p+4)=5;
    ptr=(int*)malloc(sizeof(int)*5*2);
    for(i=0;i<5;i++)
    {
	*(ptr+i)=*(p+i);
    }
    free(p);//还是指针，只过空间被释放掉了，悬空指针;
    p=NULL;  //作为约定，释放掉之后，把它变成空指针，好过悬空指针；
    p=ptr;
    ptr=NULL;
*/

    return 0;
}
