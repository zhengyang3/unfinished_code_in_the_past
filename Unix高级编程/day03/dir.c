#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<error.h>
#include<dirent.h>
int main(int argc, char* argv[])
{
	rmdir(argv[1]);
	
	return 0;
}
