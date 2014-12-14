#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>



int main()
{
    int pid=1;
    int fd[110][2]={0};
    pipe(fd[0]);
    pipe(fd[1]);
    pid=fork();
    int i=0;
    for(i=2;i<101;i++)
    {
        if(pid>0)
        {
            pipe(fd[i]);
            pipe(fd[i+1]);
            pid=fork();
        }
    }
    if(pid==0)
    {
        
    }
    getchar();

    return 0;
}
