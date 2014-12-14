#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<error.h>
#include<string.h>
struct stu
{
	char name[20];
	int age;
	float score;
};
int main(int argc, char* argv[])
{
	int fd=0;
	fd=open(argv[1], O_RDWR|O_CREAT|O_EXCL,0777);
	if(fd==-1)
	{
		fd=open(argv[1],O_RDWR);
		if(fd==-1) printf("error:%m\n"),exit(-1);
	}
	struct stat tmp={0};
	fstat(fd, &tmp);
	int size=tmp.st_size;
	char* s=NULL;
	s=mmap(0, size, PROT_READ|PROT_WRITE,  MAP_SHARED, fd, 0);
		//将文件映射到虚拟地址
	//strcpy(s,"11111111");   //改变的是内存中的内容，但是文件中的内容也会变！	
	printf("%s\n",s);
	munmap(s, size); //卸载虚拟地址
	close(fd);
	return 0;
}














