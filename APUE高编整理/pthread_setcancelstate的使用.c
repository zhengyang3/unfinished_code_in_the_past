#include <pthread.h>
#include <stdio.h>

void * do_it(void * p)
{
	int old;
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old);
	if (old == PTHREAD_CANCEL_ENABLE)
		printf("old is enable\n");

	int i = 0;
	for (; i < 100; i++) {
		sleep(1);
		printf(".");
		fflush(stdout);
	}

}

int main()
{
	pthread_t t1;	

	pthread_create(&t1, NULL, do_it, NULL);

	pthread_cancel(t1);

	pthread_join(t1, NULL);

	return 0;
}







