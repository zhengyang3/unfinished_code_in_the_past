#include <stdio.h>

#define LEN 4 

int front = 0;
int tail = 0;
int size = 0;
int arr[LEN] = {0}; 

void in_queue(char input)
{
	if (is_full()) {
		printf("\nin_queue: queue is full\n");
		printf("debug: size %d\n", size);
		return;
	}
	
	arr[tail] = input;

	tail = (tail + 1) % LEN;
	size++;
}

char out_queue()
{
	if (is_empty()) {
		printf("\nout_queue: queue is empty\n");
		printf("debug: size %d\n", size);
		return 0;
	}
	
	char ret = arr[front];

	front = (front + 1) % LEN;

	size--;
	return ret;
}

int is_full()
{
	if (((tail + 1) % LEN) == front)	
		return 1;
	else
		return 0;
}

int is_empty()
{
	if (front == tail)
		return 1;
	else
		return 0;
}

int queue_size()
{
	return size;
}

