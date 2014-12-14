#include<stdio.h>
#include<stdlib.h>
void sort_mp(int* a,int n)
{
    int i=0;
    int j=0;
    int tmp=0;
    for(i=0;i<n-1;i++)
    {
	for( j=0;j<n-1;j++)
	{
	    if(a[j]>a[j]+1)
	    {
		tmp=a[j];
		a[j]=a[j+1];
		a[j+1]=tmp;
	    }
	}
    
    }

}




int main()
{
   int x[5]={3,5,1,8,2};
   sort_mp(x,5);
   int i=0;
   for(i=0;i<5;i++)
   {
	printf("%d ",x[i]);
   }

    return 0;
}
