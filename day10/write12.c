#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fp=NULL;
    fp=fopen("333.c","r");
    if(fp==NULL)
    {
	puts("error!");
	return -1;
    }
    int buf[5];

    fread(buf,sizeof(int),5,fp);
    fclose(fp);
    int i=0;
    for (i=0;i<5;i++)
    {
	printf("%d\n",buf[i]);
    }
   
    return 0;
}
