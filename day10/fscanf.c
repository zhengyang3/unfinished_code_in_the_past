#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fp=NULL;
    int a=100;
    int b=0;
    fp=fopen("123.cc","r");
    if(fp==NULL)
    {
	puts("create file error!");
	return -1;
    }
    fprintf(fp,"%d",a);
    fscanf(fp,"%d",&b);
    printf("%d\n",b);
    fclose(fp);
    return 0;

}
