#include <stdio.h>

void do_it()
{
	printf("hello world\n");
//	return;
	exit(0);
}

int main()
{
	do_it();
	printf("goodbye\n");
	return 0;
}
