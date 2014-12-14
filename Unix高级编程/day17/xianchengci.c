
void* do_it(void*arg)
{
	printf("hello world\n");
}


int main()
{
	
	
	while(100)
	{
		pthread_create(do_it);
	}
	pthread_join;
}
