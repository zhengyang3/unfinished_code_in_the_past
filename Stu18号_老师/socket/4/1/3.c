#include <stdio.h>
#include <pthread.h>

struct arg {
	int a;
	int b;
};

void* do_it_a(void * p)
{
	struct arg * q = (struct arg *)p;

	printf("hello world %d\n", q->a + q->b);

	char * str = "goodbye";	

	return str;
}

int main()
{
	pthread_t t1;
	int i = 100;

	struct arg x = {10, 20};
	pthread_create(&t1, NULL, do_it_a, &x);

	void * ret;
	pthread_join(t1, &ret);

	printf("%s\n", (char *)ret);

	return 0;
}
