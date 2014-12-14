#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read=PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write=PTHREAD_COND_INITIALIZER;

char buf[10];
void* do_it_a(void*p)
{
	char i;
	int j=0;
	for(i='a';i<='z';i++)
	{
		buf[j]=i;
		j++;
		if()
	
	}
}


int main()
{
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	pthread_create(&t1,NULL,do_it_a,NULL);
	pthread_create(&t2,NULL,do_it_b,NULL);	
	pthread_create(&t3,NULL,do_it_c,NULL);
	pthread_create(&t4,NULL,do_it_d,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	return 0;
}
