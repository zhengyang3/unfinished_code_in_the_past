#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[5]={1,2,3,4,5};
    FILE* fp=NULL;
    fp=fopen("333.c","w");
    if(fp==NULL)
    {
	puts("creat file error!");
	return -1;
    }
    fwrite(a,sizeof(int),5,fp);
    fclose(fp);
    return 0;
}
