#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fp=NULL;
    char buf[128];
    memset(buf,'\0',128);
    strcpy(buf,"asdfghjkl");
    fp=fopen("./123","w");
    if(fp==NULL)
    {
	puts("Creat error");
	return -1;
    }
    fputs(buf,fp);
    
    fclose(fp);
    return 0;
}
