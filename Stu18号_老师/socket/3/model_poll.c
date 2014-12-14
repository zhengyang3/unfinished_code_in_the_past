#include <>

/*
 * server
 */
int main()
{
	struct pollfd arr[512];

	fd = Socket();
	arr[0].fd = fd; 
	arr[0].events = POLLIN;

	Bind();

	Listen();

	while (1)	
	{
		poll(arr);

		if ((arr[0].revents & POLLIN) == POLLIN)
		{
			arr[n].fd = Accept(fd);
			arr[n].events = POLLIN | POLLRDHUP;
		}

		for (i = 1; i < 512; i++) {
			if ((arr[i].revents & POLLIN) == POLLIN) {
				Recv(arr[i].fd);
			}
			if ((arr[i].revents & POLLRDHUP) == POLLRDHP) {
				close(arr[i].fd);
			}
		}
		
		close(cli_sock);
	}

	close(fd);

	return 0;
}








