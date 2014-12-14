#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE* fp=NULL;  
    char buf[40];
    strcpy(buf,"yang,24");
    fp=fopen("1.cxx","w");
    if(fp==NULL)
    {
	puts("create file error!");
	return 0;
    }
    fwrite(buf,1,40,fp);
    fclose(fp);

    return 0;
}
