#include<stdio.h>
#include<stdlib.h>
void insert_sort(int *a,int n)
{
    int tmp=0;
    int pos=0;
    int i=0;
    for(i=1;i<n;i++)
    {
	tmp=a[i];
	pos=i-1;
	while((pos>=0)&&(tmp<a[pos]))
	{
	    a[pos+1]=a[pos];
	    pos--;	
	}
	a[pos+1]=tmp;
    }
}

int main()
{
    int x[5]={1,5,2,4,8};
    insert_sort(x,5);
    int i=0;
    for(i=0;i<5;i++)
    {
	printf("%d\n",x[i]);
    }

    return 0;
}
