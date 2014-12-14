#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
    char name[10];
    memset(name,'0',10);
    int a [100];
    memset (a,0,100);
    strcpy(name,argv[1]);
    a[0]=aton(argv[1]);
   // a[1]=atoi(argv[2])
    printf("%s\n",name);

     return 0;
}
