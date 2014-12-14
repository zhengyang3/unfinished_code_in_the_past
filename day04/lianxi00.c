#include<stdio.h>
int main()
{
    int i=0;
    float a[5]={0};

    for(i=0;i<5;i++)
    {
    printf("input your,score:\n");
     scanf("%f",&a[i]);
    }
    printf("%f\n",a[5]);
    
    return 0;
}
