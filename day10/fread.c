#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
    char buf[200];
    memset(buf,'\0',200);
    FILE* fp=NULL;
    fp=fopen(argv[1],"r+");
    if(fp==NULL)
    {
    puts("open file error!");
    return -1;
    }
    fread(buf,199,1,fp);
    printf("%s\n",buf);

    fclose(fp);
    return 0;
}

