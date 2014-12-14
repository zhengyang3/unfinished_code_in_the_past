#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{   
    char buf[200];
    memset(buf,'\0',200);
    strcpy(buf,"杨正 0945050229");
    char buf1[200];
    memset (buf1,'\0',200);
    strcpy(buf1,"24  爷们！");
    FILE* fp=NULL;
    fp= fopen(argv[1],"w+");
    fwrite(buf,strlen(buf),1,fp);
    fclose(fp);
    FILE*fp2=NULL;
    fp2=fopen(argv[1],"a+");
    fwrite(buf1,strlen(buf1),1,fp2);
    char buf2[400];
    memset(buf2,'\0',400);
    
    fread(buf2,199,1,fp2);
    printf("%s\n",buf2);
    fclose(fp2);
    return 0;
}
