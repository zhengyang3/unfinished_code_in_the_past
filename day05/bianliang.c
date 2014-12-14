#include<stdio.h>

void fun()
{
   static int a=0;
    int b=2;
    a++;
    b++;
    printf("a:%d b:%d\n",a,b);
}
int main()
{
    static int c;
    int a=3;
    int b=2;
    
    printf("%d\n",c);
    fun();

    fun();
    fun();
    return 0;
}
