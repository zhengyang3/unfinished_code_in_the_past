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
    Pson ps[3]={0};
    FILE*fp=NULL;
    fp=fopen("222.txt","r");
    if(fp==NULL)
    {
	puts("open file error!");
	return -1;
    
    }
    fread(ps,sizeof(Pson),3,fp);
    fclose(fp);
    int i=0;
    for(i=0;i<3;i++)
    {
	    printf("%s,%s,%d,%g\n",ps[i].name,ps[i].gender,ps[i].age,ps[i].salary);
    
    }

    return 0;
}
