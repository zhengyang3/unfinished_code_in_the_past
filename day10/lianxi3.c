#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Person
{
    char name[30];
    char gender[20];
    int age;
    double salary;
};
typedef struct Person Pson;

int main()
{
    Pson p1={"name1","male",12,200};
    Pson p2={"name2","female",14,1000};
    Pson p3={"name3","male",18,3000};
    

    Pson ps[3]={p1,p2,p3};
    FILE*fp=NULL;
    fp=fopen("222.txt","w");
    if(fp==NULL)
    {
	puts("create file error!");
	return -1;
    }
    fwrite(ps,sizeof(Pson),3,fp);


    fclose(fp);

    return 0;
}

