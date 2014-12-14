#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int* a,int* b)
{
    int c=*a;
    *a=*b;
    *b=c;

}
void sort(int* a,int n)
{
    if(n<=0) return;
    int L=0;
    int R=n-1;
    int piv=a[L];
    while(L<R)
    {
	while(L<R&&a[R]>=piv)
	{
	    --R;
	}
	swap(&a[L],&a[R]);
	while(L<R&&a[L]<=piv)
	{
	    ++L;
	}
	swap(&a[L],&a[R]);
    }
    sort(a,L);
    sort(a+L+1,n-L-1);

}
int main()
{
    int a[5]={4,3,2,1,5};
    sort(a,5);
    int i=0;
    for (i=0;i<5;i++)
    {
	printf("%d\n",a[i]);
    }


    return 0;
}
