#include <stdio.h>
#include <unistd.h>

int main(int xxx, char * yyy[])
{
	printf("hello \n");

	execlp("pwd", "pwd", NULL);

	printf("world \n");

	return 0;
}
