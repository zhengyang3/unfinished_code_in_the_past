#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{	
	//1.找到空闲空间的首地址
	int* p=(int*)sbrk(0);
	printf("sbrk(0):%p\n",p);
	//2.分配空间
	brk(p+1);
	printf("brk:%p\n",p);
	//3.使用空间
	*p=800;
	//4. 释放空间
	brk(p);
	
	return 0;
}
