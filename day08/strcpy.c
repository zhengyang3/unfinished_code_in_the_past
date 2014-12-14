#include<stdio.h>
#include<string.h>
int main()
{   
    char a[5]="12345";
    char b[5]="99";
    strcpy(a,b);

    //const char* c = b;//const* = const* !const*
    //char* d = c; //!const* !const*

    b[2] = '1';
    printf("%s",a);

    return 0;
}
