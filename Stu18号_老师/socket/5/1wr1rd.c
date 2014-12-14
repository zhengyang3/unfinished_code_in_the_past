#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read=PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write=PTHREAD_COND_INITIALIZER;

char c;
int j=0;
int box=0;

void *do_write(void*p)
{
	for(c='a';c<'z'+1;c++)
	{
		pthread_mutex_lock(&lock);
		if (box != 0) {
			pthread_cond_wait(&can_write,&lock);
		}

		box = c;	// produce
		pthread_cond_signal(&can_read);
		pthread_mutex_unlock(&lock);
	}
}
void*do_read(void*p)
{
	for(j=0;j<26;j++)
	{
		pthread_mutex_lock(&lock);
		if (box==0) {
			pthread_cond_wait(&can_read,&lock);
		}	

		sleep(1);
		printf("%c\t", c);
		fflush(stdout);
		box=0;
		pthread_cond_signal(&can_write);
		pthread_mutex_unlock(&lock);
	}
}
int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t2,NULL,do_read,NULL);
	pthread_create(&t1,NULL,do_write,NULL);

	pthread_join(t2,NULL);
	pthread_join(t1,NULL);
}
