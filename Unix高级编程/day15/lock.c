#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read=PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write=PTHREAD_COND_INITIALIZER;

char a='0';
void* do_it_a(void*p)
{
	pthread_mutex_lock(&lock);
	char i;
	for(i='a';i<='z';i++)
	{	
		a=i;
		pthread_cond_signal(&can_write);
		//sleep(2);
		pthread_cond_wait(&can_read,&lock);	
		
	}
	pthread_mutex_unlock(&lock);
}

void* do_it_b(void*p)
{	
	pthread_mutex_lock(&lock);
	
	while(1)
	{	
		if(a=='0')
		{
			pthread_cond_signal(&can_read);
			pthread_cond_wait(&can_write,&lock);
			continue;
		}
		printf("%c \n",a);
		if(a=='z')
		{
		//	pthread_mutex_unlock(&lock);
		 	exit();
		}
		pthread_cond_signal(&can_read);
		pthread_cond_wait(&can_write,&lock);
		//sleep(1);
	}
	pthread_mutex_unlock(&lock);
	
}

int main()
{
	pthread_t t2;
	pthread_t t1;
	pthread_create(&t2,NULL,do_it_a,NULL);
	pthread_create(&t1,NULL,do_it_b,NULL);	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
}
















