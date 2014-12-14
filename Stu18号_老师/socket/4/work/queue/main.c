#include <pthread.h>
#include <stdio.h>

#include "queue.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;

void * produce_s(void * arg)
{
	char c;
	for (c = 'a'; c <= 'z'; c++)
	{
		sleep(1);
		pthread_mutex_lock(&lock);
		if (is_full())
			pthread_cond_wait(&can_write, &lock);

		in_queue(c);

		pthread_cond_signal(&can_read);
		pthread_mutex_unlock(&lock);
	}
}

void * produce_b(void * arg)
{
	char c;
	for (c = 'A'; c <= 'Z'; c++)
	{
		pthread_mutex_lock(&lock);
		while (is_full()) {
			pthread_cond_wait(&can_write, &lock);
		}

		in_queue(c);

		pthread_cond_signal(&can_read);
		pthread_mutex_unlock(&lock);
	}
}

void * custmer(void * arg)
{
	int i = 0;
	for (i = 0; i < 26; i++)
	{
		sleep(1);
		pthread_mutex_lock(&lock);
		while (is_empty())
			pthread_cond_wait(&can_read, &lock);

		printf("%c ", out_queue());
		fflush(stdout);

		pthread_cond_signal(&can_write);
		pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t t1;	
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;

	pthread_create(&t1, NULL, produce_s, NULL);
	pthread_create(&t2, NULL, produce_b, NULL);
	pthread_create(&t3, NULL, custmer, NULL);
	pthread_create(&t4, NULL, custmer, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);

	printf("\n");

	return 0;
}




