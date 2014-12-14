#include <>

/* 
 * server
 */
int main()
{
	fd = Socket();
	FD_SET(fd, &rset);

	Bind();

	Listen();

	while (1)
	{
		select(rset);

		cli_sock = Accept(fd);
		FD_SET(cli_sock, &rset);


		recv(cli_sock) / send(cli_sock);
		close(cli_sock);
	}

	return 0;
}








