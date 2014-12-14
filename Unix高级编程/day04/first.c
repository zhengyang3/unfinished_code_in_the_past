#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<error.h>
#include<dirent.h>
#include <fcntl.h>
#include <sys/mman.h>
struct stu
{
	char name[20];
	int age;
	float score;
};
int main(int argc, char* argv[])
{
	int fd=0;
	struct stu* s=NULL;
	struct stat st;
	int size=0;
	int count=0;
	fd=open(argv[1],O_RDWR|O_CREAT|O_EXCL,0777);
	if(fd==-1)
	{
		fd=open(argv[1], O_RDWR);
		 if(fd==-1) printf("open:%m\n"),exit(-1);
	}
	fstat(fd,&st);
	size=st.st_size;
	count=size/sizeof(struct stu);
	ftruncate(fd, sizeof(struct stu));
	s=mmap(0,size+sizeof(struct stu), PROT_READ|PROT_WRITE, 
				MAP_SHARED, fd, 0);
	printf("input name:");
	scanf("%s",s[count].name);
	fflush(stdin); // setbuf(stdin,NULL)也可以；
	printf("input age:");
	scanf("%d",&(s[count].age));
	printf("input score:");
	scanf("%f",&(s[count].score));
	munmap(s,sizeof(struct stu)+size);
	close(fd);
	return 0;
}
