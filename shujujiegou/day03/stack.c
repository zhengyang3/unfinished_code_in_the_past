#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sta[10];
static int top=0;


int is_empty()
{
    if(top==0) return 0;
    return 1;
}

int is_full()
{
    if(top==9) return 1;
    return 0;

}

//进栈
void push(int* a,int data)
{
    if(is_full()==1)
    {
	puts("full\n");
    }
    top++;
    a[top]=data;

}


//出栈
void pop(int* a)
{
    if(is_empty()==0)
    {
	puts("empty!");
    }
    printf("pop:%d\n",a[top]);
    top--;
}


int main()
{
    push(sta,1);
    push(sta,2);
    push(sta,3);
    push(sta,4);
    push(sta,5);
    puts("***********");
    pop(sta);
    pop(sta);
    pop(sta);
    pop(sta);
    pop(sta);
    return 0;
}
