#include<stdio.h>
#include<unistd.h>
int main()
{	
	printf("pid:%d\n",getpid());	
	while(1)
	{
		sleep(3);
	}
	
	return 0;
}
