#include<stdio.h>
int main()
{

        int a=1;			
	int b=5;	
	int c=8;
        int i;
       i=(((a>b)?a:b)>c)?((a>b)?a:b):c;
       printf("%d\n",i);

	return 0;
}
