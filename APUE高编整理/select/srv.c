#include <stdio.h>
#include <string.h>

#include "wrap.h"

int main()
{
	int maxfd = 0;

	fd_set rset;
	FD_ZERO(&rset);

	int srv_sock = Socket(AF_INET, SOCK_STREAM, 0);
	maxfd = (srv_sock > maxfd) ? srv_sock : maxfd;

	struct sockaddr_in srv_addr;
	mkaddr(&srv_addr, "127.0.0.1", "2345");
	Bind(srv_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	Listen(srv_sock, 5);

	int ret = 0;
	char buf[128];
	int i = 0;
	while (1) {
		printf("debug maxfd is %d\n", maxfd);
		for (i = 0; i <= maxfd; i++) {
			FD_SET(i, &rset);
		}

		ret = Select(maxfd+1, &rset, NULL, NULL, NULL);
		printf("debug ret is %d\n", ret);
		for (i = 0; i <= maxfd; i++)
		{
			if (FD_ISSET(i, &rset))
			{
				if (i == srv_sock)
				{
					// if srv_sock has data to read
					int cli_sock = Accept(srv_sock, NULL, NULL);
					maxfd = (cli_sock > maxfd) ? cli_sock : maxfd;
					printf("debug someone connect me\n");
				}
				else
				{
					// if cli_sock has data to read
					int len = recv_all(i, buf);
					if (len == -1)
					{
						close(i);
						if (i >= maxfd)
							maxfd = i-1;
						break;
					}
					else if (len == 0)
						break;

					send_back(i, buf, len);
				}
			}
		}
	}
	close(srv_sock);

	return 0;
}
