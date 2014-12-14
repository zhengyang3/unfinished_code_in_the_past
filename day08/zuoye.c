#include<stdio.h>
int main()
{
    int i=0;
    int sw=0;
    printf("%s",a);
    for(i=0;i<5;i++)
    {
	   sw= a[i];
	   a[4-i]=sw;
	   printf("%d",a[4-i]);
    }
    return 0;

}
