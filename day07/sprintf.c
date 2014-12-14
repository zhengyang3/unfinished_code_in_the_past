#include<stdio.h>
#include<string.h>
int main()
{
    int src=123;
    char dest[15];
    memset(dest,'0',15);
    printf("%s\n",dest);
    sprintf(dest,"%d",src);
    printf("%s\n",dest);
    return 0;
}
