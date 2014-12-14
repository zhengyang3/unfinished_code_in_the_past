#include <stdio.h>
int main()
{
	int a=0;
	char b1 ='A';
  	
	char* b=NULL;// 
	b=&b1;
	printf("b value:%p\n",b);
	printf("b address:%p\n",&b);
	printf("b1 address:%p\n",&b1);
	printf("b1 value:%c\n",b1);
	printf("%d\n",sizeof(b));
	return 0;
}
