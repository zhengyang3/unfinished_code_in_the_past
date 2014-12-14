#include<stdio.h>
struct student {
    int no;
    char name[15];
    int gender;
    float score;
    };
    typedef struct student stu;
int main()
{
    stu a;
    printf("input your no: ");
    scanf("%d",&(a.no));
    printf("input your name:");
    scanf("%d",a.name);
    printf("input your gender:");
    scanf("%d",&a.gender);
    printf("input your score:");
    scanf("%g",&a.score);

    printf("学号:%d--名字:%s--性别:%d--学分:%f\n",a.no,a.name,a.gender,a.score);

   /* a.no=1;
    a.name="名字";  
    a.gender=1;
    a.score=12;*/

    return 0;
}
