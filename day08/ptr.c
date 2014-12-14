#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[10];
    char b='a';
    memset(a,'\0',10);
    strcpy(a,"wstringab");
    char* ptr=NULL;
    ptr=strchr(a,b);
    if(ptr==NULL)
    {
	printf("not found\n");
    }else{
	printf("%c\n",*ptr);
	
    }
    
    
    return 0;

}
