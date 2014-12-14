#include<stdio.h>
//n代表的是方块的数量，s代表的是源，t代表的是目标，c中转
void han(int i ,char s,char t,char c)
{
    if(i==0) return;
    //将n-1个方块从源移到中转
    han(i-1,s,c,t);
    //将第i个方块移到目标
    printf("%d:%c--->%c\n",i,s,t);
    //将n-1个方块从中转转移到目标　
    han(i-1,c,t,s);

}


int main()
{
    int n;
    printf("input:\n");
    scanf("%d",&n);
    han(n,'a','c','b');
    return 0;
  
}
