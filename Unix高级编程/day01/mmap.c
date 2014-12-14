#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int* p=NULL;
	p=mmap(NULL,
			getpagesize(),
			PROT_READ|PROT_WRITE,
			MAP_ANONYMOUS|MAP_SHARED,
			0,0);
	*p=20;
	*(p+1)=30;
	printf("%d\n",*p);
	munmap(p,4096);
	return 0;
}
