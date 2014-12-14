#include <stdio.h>
#include <pthread.h>
#define LEN 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;


char arr[10] = {0};
int in_pos = 0;
int out_pos = 0;

void* do_it_a(void* p)
{
	char c = 'a';
	for(; c <= 'z'; c++)
	{
		pthread_mutex_lock(&lock);

		if(((in_pos + 1)%10) == out_pos)
		{
			printf("queue is full(a)\n");
			pthread_mutex_lock(&lock);
		}

		pthread_cond_wait(&can_write,&lock);
		arr[in_pos] = c;
		in_pos = (in_pos + 1) % 10;

		pthread_cond_signal(&can_read);
		pthread_mutex_unlock(&lock);
	}
}
void* do_it_b(void* p)
{
	char c = 'A';
	for(; c <= 'Z'; c++)
	{
		pthread_mutex_lock(&lock);
		
		if(((in_pos + 1)%10) == out_pos)
		{
			printf("%d\n",(in_pos+1)%10);
			printf("%d\n",out_pos);
			printf("queue is full(b)\n");
			pthread_mutex_unlock(&lock);
		}

		arr[in_pos] = c;
		in_pos = (in_pos + 1) % 10;

		pthread_cond_signal(&can_read);
		pthread_mutex_unlock(&lock);
	}
	
}
void* do_it_c(void* p)
{
	int i = 0;
	char c = 'A';
	char box;
	for(; i <= 52; i++)
	{
		pthread_mutex_lock(&lock);
		if(in_pos == out_pos)
		{
			printf("queue is empty\n");
			pthread_mutex_unlock(&lock);
		}
		
			pthread_cond_wait(&can_read,&lock);

		for(; c <= 'Z'; c++)
		{
			if(arr[out_pos] == c)
			{
				printf("big printf:%c\n",c);
				fflush(stdout);
				out_pos = ((out_pos + 1) % 10);
			}
		}

		pthread_cond_signal(&can_write);
		pthread_mutex_unlock(&lock);
	}
	
}
void* do_it_d(void* p)
{
	int i = 0;
	char c = 'a';
	char box;
	for(; i <= 52; i++)
	{
		pthread_mutex_lock(&lock);
		if(in_pos == out_pos)
		{
			printf("queue is empty\n");
			pthread_mutex_unlock(&lock);
		}

			pthread_cond_wait(&can_read,&lock);
		for(; c <= 'z'; c++)
		{
			if(arr[out_pos] == c)
			{
				printf("small printf:%c\n",c);
				fflush(stdout);
				out_pos = ((out_pos + 1) % 10);
			}
		}

		pthread_cond_signal(&can_write);
		pthread_mutex_unlock(&lock);
	}
	
}

int main()
{
	printf("%d\n",1%10);
	
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;

	pthread_create(&t1,NULL,do_it_a,NULL);
	pthread_create(&t1,NULL,do_it_b,NULL);

	pthread_create(&t1,NULL,do_it_c,NULL);
	pthread_create(&t1,NULL,do_it_d,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	return 0;
}
