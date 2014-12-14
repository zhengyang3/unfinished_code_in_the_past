void * do_it(void * arg)
{
	while (forever)
	{
		lock();
		if (queue_isempty())
			pthread_cond_wait(&can_get, &lock);

		cli_sock = queue_out();
		unlock();

		while (forever) {
			Recv()/Send();
			if (client is closed)
				break;
		}

		close(cli_sock);
	}
}

int main()
{
	Socket();
	Bind();
	Listen();

	while (100)
		pthread_create(do_it);

	while (1)
	{
		cli_sock = Accept();
		if (all thread is busy) {
			send("the server is busy, please connect later.");
			close(clist_sock);
		}

		lock();
		queue_in(cli_sock);
		pthread_cond_signal(&can_get);
		unlock();
	}


	return 0;
}
