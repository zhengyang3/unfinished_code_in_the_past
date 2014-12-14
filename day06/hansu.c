#include<stdio.h>
int susu(int a)
{   
    int i=0;
    for(i=2;i<a;i++)
    {
      if(0==a%i)
    return 1;
    }
    return 0;

}
int main()
{
    int a=0;
    printf("Input a number:");
    scanf("%d",&a);
    if(1==susu(a))
    {
    printf("%d不是素数！",a);
       
    }else{
	printf("%d是素数！",a);    
       	}
    

    return 0;
}
