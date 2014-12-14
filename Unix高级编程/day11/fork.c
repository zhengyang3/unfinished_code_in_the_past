#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>
int main()
{
	printf("1111111\n");
	if(fork()==0) printf("2222222222222\n");
	else if(fork()>0)  printf("3333333333333\n");
   else	printf("44444444444444\n");

	return 0;
}
