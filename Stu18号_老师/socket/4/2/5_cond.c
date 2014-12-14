#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t go = PTHREAD_COND_INITIALIZER;

void * do_it(void * p)
{
	sleep(3);
	pthread_mutex_lock(&lock);
	printf("hello world!\n");
	pthread_cond_signal(&go);
	pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t t1;	
	pthread_create(&t1, NULL, do_it, NULL);
	pthread_mutex_lock(&lock);
	pthread_cond_wait(&go, &lock);
	pthread_join(t1, NULL);
	pthread_mutex_unlock(&lock);
	printf("here\n");

	return 0;
}







