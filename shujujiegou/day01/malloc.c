include<stdio.h>

int main()
{
    int* p=NULL;

    int* ptr=NULL;

    p = (int*)malloc(sizeof(int)*3); 

    memset(p,0,4*3);

    int i=0;
    
    for(i=0;i<3;i++)
    {
    
	*(p+i)=i;

    }

    for(i=0;i<3;i++)
    {
    
	printf("%d\n",*(p+i));

    }
    
    ptr+malloc(sizeof(int)*3*2);

    for(i=0;i<3;i++)

    {
    
	*(ptr+i)=*(p+i);
    
    }
    
    for (i=0;i<3;i++)

    {
    
	printf("ptr:%d\n",*(ptr+i));

    }

    free(b);

    p=NULL;

    p=ptr;

    ptr=NULL;

    free(p);

    return 0;

}
