#include<stdio.h>
int main()
{
    FILE* f=fopen("./1.c","r+");
    if(f!=NULL)
    {
	puts("open");
	p=fgetc(f);
	printf("%c\n",p);
	    
    }else{
    
	puts("NULL");
    }
    fclose(f);
    return 0;
}
