#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp=NULL;
    char buf[200];
    memset(buf,'\0',200);
    fp=fopen("./1.c","r+");
    if(fp==NULL)
    {
	printf("file error\n");
	return -1;    
    }
    fgets(buf,199,fp);

    puts(buf);
    fclose(fp);

    return 0;
}
