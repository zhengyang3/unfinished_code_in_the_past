#include <stdio.h>
#include <pthread.h>

int i = 0;

void* do_it_a(void * p)
{
	// ret == 0 
	i = 100;
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, do_it_a, NULL);	// fork();

	pthread_join(t1, NULL);	// wait();

	printf("%d\n", i);

	return 0;
}
