#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* p = NULL;
   
    p = (int*) malloc (sizeof(int)*3);
   
    memset (p,0,sizeof(int)*3);
    
    realloc (&p,sizeof(int)*3);

    return 0;
}
