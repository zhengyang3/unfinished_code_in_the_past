#include<stdio.h>
int main()
{
    /*
    char* s1=“aflk”;(常量字符串可以这样定义，s1是指向这个常量字符串的首地址)      字符串变量一般是用字符数组定义，若非要用指针去定义，可以如下：
                 char* a=NULL;           
        	     a=(char*)malloc(10);
		与下面有什么区别：
		 char a[20];
		 bzoro(a,20);


     char a[10]={0};打印的时候为什么不会打印出0；

 const char *mode      这种形式表示这个位置放的是字符串





    char* s2=
    char* p=NULL;
    */
    //依次就可以用for;
    //字符是可以直接加减的，它不是也可以直接用整型给字符赋值嘛！
    //字符串可以吗？

    char a[4]="abc";
    int i=0;
  
    
    for(;;)
    {
	if(a[i]>'Z')
	{
	a[i]=a[i]+('A'-'a');
	i++;
	}
	if(a[i]=='\0')
	{
	break;
	}
	if(a[i]<'Z')
	{
	a[i]=a[i];
	}
    }
	printf("%s",a);
    
    


    
    return 0;
}
