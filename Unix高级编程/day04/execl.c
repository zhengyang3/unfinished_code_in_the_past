#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	execl("a.out","./a.out",NULL);
	//execlp("ls","ls","-l",);
	return 0 ;
}
