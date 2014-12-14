#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int a=0;
	
	int r=read(0,&a,4);
	a[r]='\0';
	printf("%d\n",a);
	return 0;

//加密过程
int r=0;
while(1)
{
	r=read(fd,&a,1);
	if(r<=0) break;
	a=~a;
	lseek(fd,-1,SEEK_CUR);
	write(fd,&a,1);
}








}
