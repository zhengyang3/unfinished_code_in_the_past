#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read=PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write=PTHREAD_COND_INITIALIZER;

char c;
char box;

void *do_write(void*p)
{
	pthread_mutex_lock(&lock);

	char c;
	for (c = 'a'; c <= 'z'; c++)
	{
		box = c;

		pthread_cond_signal(&can_read);
		pthread_cond_wait(&can_write, &lock);
	}
	pthread_mutex_unlock(&lock);
}

void* do_read(void*p)
{
	pthread_mutex_lock(&lock);

	int i = 0;
	for(i=0; i<26; i++)
	{
		if (box == 0) {
			pthread_cond_wait(&can_read, &lock);
		}

		printf("%c ", box);
		fflush(stdout);
		box = 0;

		pthread_cond_signal(&can_write);
	}

	pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1,NULL,do_write,NULL);
	pthread_create(&t2,NULL,do_read,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
