#include <stdio.h>
#include <pthread.h>

void* do_it_a(void * p)
{
	printf("hello world\n");
}

void* do_it_b(void * p)
{
	printf("goodbye\n");
}

int main()
{
	do_it_a();
	do_it_b();
/*
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, do_it_a, NULL);
	pthread_join(t1, NULL);	

	pthread_create(&t2, NULL, do_it_b, NULL);
	pthread_join(t2, NULL);
*/
	return 0;
}
