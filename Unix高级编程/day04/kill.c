#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<error.h>
int main()
{
	int pid=0;
	pid=fork();
	int i=0;
	if(pid==0)
	{
		while(1)
		{
			printf("CCCCCCC P\n");
			sleep(1);
			
		}
	}else if(pid>0)
	{
		while(1)
		{
			printf("FFFF p\n");
			i++;
			sleep(1);
			if(i==5)
			{
				kill(pid, 9);
			}
		}
	}else
	{
		printf("%m\n");
		return -1;
	}
	return 0;
}
