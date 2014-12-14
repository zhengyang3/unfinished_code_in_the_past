#include<stdio.h>
#include<string.h>
struct stu {
	    int no;
	    char name[15];
	    int age;
    };
int main(int argc,char* argv[])
{
    struct stu a;
    a.no=atoi(argv[1]);
    strcpy(a.name,argv[2]);
    a.age=atoi(argv[3]);
    printf("no:%d     name:%s    age:%d\n",a.no,a.name,a.age);
    return 0;
}
