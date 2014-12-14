#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<error.h>
#include<dirent.h>
int mysort(const void* a, const void* b)
{
	return alphasort(a, b);
}
int my_filter(const struct dirent* d)
{
	if(memcmp(d->d_name, ".", 1)==0)   //看看这里面的readdir(3)的结构体
	{
		return 0;
	}else
	{
		return -1;
	}
}
int main(int argc, char* argv[])
{	
	struct dirent** d=NULL;
	int r=scandir(argv[1], &d, my_filter, mysort);
	int tmp[r];
	int i=0;
	for(i=0;i<r;i++)
	{	
		if(d[i]->d_type=='d')
		{
			tmp[i]=i;
		}
		printf("%s\n",d[i]->d_name);
	}
	for(i=0;i<r;i++)
	{
		if(tmp[i]==i)
		{
			
		}
	}
	
/*	while(*d)
	{
		printf("%s\n",(*d)->d_name);
		d++;
	}
*/
	return 0;
}
