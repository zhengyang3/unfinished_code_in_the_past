#include <pthread.h>
#include <stdio.h>

void * do_it(void * p)
{
	printf("hello world\n");
}

int main()
{
	pthread_t t1;	

	pthread_create(&t1, NULL, do_it, NULL);
	pthread_join(t1, NULL);

	pthread_create(&t1, NULL, do_it, NULL);
	pthread_join(t1, NULL);

	pthread_create(&t1, NULL, do_it, NULL);
	pthread_join(t1, NULL);

	pthread_create(&t1, NULL, do_it, NULL);
	pthread_join(t1, NULL);

	return 0;
}







