#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/time.h>
#include<signal.h>
void handle(int sig)
{
	printf("起床！\n");
}
int main()
{
	struct itimerval v={0};
	
	v.it_value.tv_sec=10;
	v.it_value.tv_usec=1;
	
	v.it_interval.tv_sec=1;
	v.it_interval.tv_usec=1;
	signal(14, handle);
	setitimer(ITIMER_REAL,&v,0 );
	getchar();
	return 0;
}
