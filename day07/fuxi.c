#include<stdio.h>
#include<string.h>
int main()
{
   /* int a=5;
    float b=5;
    double c=5; 
    printf("%d--%.2f--%lf\n",a,b,c);*/





/*
    int a=0;
    printf("Input a number:");
    scanf("%d",&a);
    printf("%d\n",a);
*/




/*
    char name[15]={0};
    strcpy(name,"yangzheng");
    int age=24;
    double b=11111.254;
    printf("%s %d %lf\n",name,age,b);
*/


/*

    char a='r';
    short int b=5;
    printf("%d %d",sizeof(a),sizeof(b));
*/


/*
    int a=0;
    printf("Input your gongzhi:");
    scanf("%d",&a);
    if(a>10000)
    {
    printf("huiji");
    }

    if(5000<a&&a<10000)
    {
    printf("huoche");
    }
    if(3000<a&&a<5000)
    {
    printf("car");
    }
    if(1500<a&&a<3000)
    {
    printf("bike");
    }
    if(a<1500) 
    {
    printf("bus");
    }

*/



/*



    int a=0;
    int b=0;
    printf("Input the year and the month:");
    scanf("%d %d",&a,&b);
    if(((a%4==0)&&(a%100!=0))||(a%400==0))
    {
    if(b==4||b==6||b==9||b==11)
    {
              printf("30days");
    }else if(b==2)
          {
              printf("29days");
           }else
                {
	            printf("31days");
	        }

    }
    else if(b==4||b==6||b==9||b==11)
    {
	printf("30days");
    }else if(b==2)
	    {
		printf("28days");
	    }else
	     printf("31days");
	    

*/

/*
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    printf("Input 4 numbers:");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int max=0;
    max=a;
    if(max<b)
       max=b;
    if(max<c)
       max=c;
    if(max<d)
       max=d;
      printf("%d",max);

*/


/*   
    int i=0;
    for(i=1;i<11;i++)
    {
	printf("%d",i);
    }
    
*/



/*
    int i=0;
    for(i=1;i<100;i=i+2)
    {
    printf("%d",i);
    
    }

*/



/*

    double sum=0;
    double a;
    for(i=1;i<6;i++)
    {
    scanf("%lf",&a);
    sum+=a;
    }

*/

 ///*


    int i=1;
    double sum=0;
    double a;
    for (i=1;i>0;i++)
    {
	printf("input");
	scanf("%lf",&a);
	sum+=a;
	if(a==-1)
	{
	break;
	}
	   
    }
    printf("%lf",sum/i);

//*/

/*

    int i=0;
    for(i=1;i<30;i++)
    {
	if(i%4!=0)
	{
	//另一种方法：i%4==0  continue;
	printf("%d ",i);
	}
    }


*/


    








































































	























    return 0;
}
