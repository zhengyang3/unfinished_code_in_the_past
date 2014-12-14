void* do_it(void*arg)
{
	while(1)
	{
		lock();
		if(queue_isempty())
			pthread_cond_wait(&can_get,&lock);
		
		cli_sock=queuq_out();+
		
		unlock()
		
		do_something_with_client(cli_sock);
		
		close(cli_sock);
	}
}



int main()
{
	socket;
	bind();
	listen();
	while(100)
		pthread_create();
	
	while(1)
	{
		cli_sock = accept()
		if(allthread is busy)
			send("all connection is full"),close(clist_sock);
		lock();  //pthread_cond_wait没有其实就没锁的必要
		queue_in(cli_sock);
		pthread_cond_signal(&can_get);
		unlock();
	}
}
