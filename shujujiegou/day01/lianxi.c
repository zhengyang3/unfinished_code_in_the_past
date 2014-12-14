#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[15];
    
    int age;
    
    struct student* next;

};

typedef struct student stu;

int main ()
{
    stu a1 = {"Jim1",10};

    stu a2 = {"Jim2",11};
    
    stu a3 = {"Jim3",14};
    
    stu a4 = {"Jim4",15};
    
    stu a5 = {"Jim5",16};
    
    a1.next = &a2;

    a2.next = &a3;

    a3.next = &a4;

    a4.next = &a5;

    stu* p = NULL;

    p = &a1;

    while(p != NULL)
    {
	printf("name:%s---age:%d\n",p->name,p->age);
	
	p = p->next;
	
    
    }


    return 0;
}
