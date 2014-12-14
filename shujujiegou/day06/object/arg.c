#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct usr_info{
    int usr_id;
    char usr_name[15];
    char usr_psd[15];
};
typedef struct usr_info usr;
int main()
{
    usr a1={1,"a",1};
    usr a2={2,"b",2};
    usr a3={3,"c",3};
    usr a4={4,"d",4};
    usr a5={5,"e",5};
    usr a6={6,"f",6};
    usr a[6]={a1,a2,a3,a4,a5,a6};
    FILE* fp=NULL;
    fp=fopen(".dat","w");
    fwrite(a,sizeof(usr),6,fp);
    fclose(fp);


    return 0;
}
