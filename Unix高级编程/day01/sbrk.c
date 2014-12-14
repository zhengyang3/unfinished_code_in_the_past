#include<stdlib.h>
#include<unistd.h>
int main()
{	
	int* p=NULL;
	
	p=(int*)sbrk(4);
	printf("sbrk(4)p:%p\n",p);
	p=(int*)sbrk(0);
	printf("sbrk(0)p:%p\n",p);
	
	return 0;
}
