#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;
int i = 0;

void * do_it_a(void * p)
{
	pthread_mutex_lock(&lock);
	if (i != 0)
		pthread_cond_wait(&can_write, &lock);
	i = 10;
	pthread_cond_signal(&can_read);
	pthread_mutex_unlock(&lock);
}

void * do_it_b(void * p)
{
	pthread_mutex_lock(&lock);
	if (i != 0)
		pthread_cond_wait(&can_write, &lock);
	i = 100;
	pthread_cond_signal(&can_read);
	pthread_mutex_unlock(&lock);
}

void * do_it_add(void * p)
{
	pthread_mutex_lock(&lock);
	if (i == 0)
		pthread_cond_wait(&can_read, &lock);

	int a = i;
	i = 0;
	pthread_cond_signal(&can_write);
	pthread_mutex_unlock(&lock);

	pthread_mutex_lock(&lock);
	if (i == 0)
		pthread_cond_wait(&can_read, &lock);
	int b = i;
	pthread_cond_signal(&can_write);
	pthread_mutex_unlock(&lock);

	printf("%d\n", a+b);
}

int main()
{
	pthread_t t1;	
	pthread_t t2;	
	pthread_t t3;	

	pthread_create(&t1, NULL, do_it_a, NULL);
	pthread_create(&t2, NULL, do_it_b, NULL);
	pthread_create(&t3, NULL, do_it_add, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	return 0;
}







