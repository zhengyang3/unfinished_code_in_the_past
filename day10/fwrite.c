#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
    char buf[200];
    memset(buf,'\0',200);
    strcpy(buf,"2365465498798sdhfwueioyr");
    FILE*fp=NULL;
    fp=fopen(argv[1],"w+");
    if(fp==NULL)
    {
    puts("open file error!");
    return -1;
    }

    fwrite(buf,strlen(buf)+1,1,fp);
    fclose(fp);
    return 0;

}
