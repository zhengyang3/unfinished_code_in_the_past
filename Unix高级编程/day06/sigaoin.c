#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void handle(int s, siginfo_t* info, void* d)
{
	printf("11111111111\n");
	printf("value:%d\n",info->si_value);
	act.sa_sigaction=handle;
	sleep(5);
	printf("2222222222222\n");
}
int main()
{	
	struct sigaction act={0};
	printf("pid:%d\n",getpid());
	act.sa_handler=handle;
	sigemptyset(&act.sa_mask);//信号的集合不能直接用==
	act.sa_flags=SA_SIGINFO;
	sigaddset(&(act.sa_mask),SIGINT);
	
	sigaction(14, &act, NULL);
	//alarm(6);
	while(1);
	return 0;
}
