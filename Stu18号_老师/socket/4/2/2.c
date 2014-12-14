#include <stdio.h>
#include <pthread.h>

void * do_it(void * p)
{ 
	int i = 0;
	for (i = 0; i < 100; i++) {
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}

int main()
{
	pthread_t t1;

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_create(&t1, &attr, do_it, NULL);

	pthread_join(t1, NULL);

	pthread_attr_destroy(&attr);

	printf("hello world\n");

	return 0;
}
