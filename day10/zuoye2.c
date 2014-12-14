#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fp=NULL;
    char buf[20];
    strcpy(buf,"zheng,24");
    fp=fopen("1.cxx","r+");
    if(fp==NULL)
    {
	puts("error!");
	return 0;
    }
    fseek(fp,60l,0);
    fwrite(buf,20,1,fp);
    fclose(fp);

    return 0;
}
