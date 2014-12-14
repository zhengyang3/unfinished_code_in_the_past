#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/time.h>
#include<signal.h>
void handle(int sig)
{
	printf("处理特定信号\n");
	
} 
int main()
{
	int i=0;
	int sum=0;
	sigset_t sigs;
	sigset_t sigp;
	sigset_t sigq;
	sigemptyset(&sigs);//清空
	sigemptyset(&sigp);
	sigemptyset(&sigq);
	sigaddset(&sigs,SIGINT);//添加要屏蔽的信号到信号集合
	
	
	signal(SIGINT,handle);    
	sigprocmask(SIG_BLOCK,&sigs,0);//开始屏蔽信号
	for(i=0;i<3;i++)
	{
		sigpending(&sigq);
		printf("sigpending:%d\n",sigismember(&sigq,2));
		sum+=i;
		printf("for sum:%d\n",sum);
		/*if(sigismember(&sigp,2)==0)
		{
			sigsuspend(&sigp);
		}*/
		sleep(1);
	}
	sigprocmask(SIG_UNBLOCK,&sigs,0);//解除屏蔽！
	printf("sum:%d\n",sum);
	getchar();
	return 0;
}
