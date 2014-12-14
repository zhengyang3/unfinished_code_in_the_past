#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read=PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write=PTHREAD_COND_INITIALIZER;


struct Node 
{
	int data;
	struct Node* next;
};
typedef struct Node Node;

vo

int main()
{
	int i=0;
	pthread_t t[100];
	Node new_Node;
	
	for(i=0;i<100;i++)
	{
		pthread_create(&t[i],NULL,do_it_a,NULL);
	}
	for(i=0;i<100;i++)
	{
		pthread_join(t[i],NULL);
	}
} 
