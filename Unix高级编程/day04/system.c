#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int a=0;
	a=system("./a.out");
	printf("system end,a:%d\n",WEXITSTATUS(a));
	
	return 0;
}
