#include <stdio.h>
#include <string.h>

#include "wrap.h"

int main()
{
	int ret = 0;
	int maxfd = -1;
	int n = 0;
	int i = 0;

	fd_set rset;
	FD_ZERO(&rset);

	int srv_sock = Socket(AF_INET, SOCK_STREAM, 0);
	FD_SET(srv_sock, &rset);
	maxfd = (srv_sock > maxfd) ? srv_sock : maxfd;

	struct sockaddr_in srv_addr;
	mkaddr(&srv_addr, "127.0.0.1", "1234");
	Bind(srv_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	Listen(srv_sock, 5);

	int cli_sock = -1;
	char buf[128];
	while (1) {
		n = Select(maxfd+1, &rset, NULL, NULL, NULL);

		for (i = 3; i <= maxfd; i++)
		{
			if (!FD_ISSET(i, &rset))
				continue;

			if (i == srv_sock) {
				cli_sock = Accept(srv_sock, NULL, NULL);
				maxfd = (cli_sock > maxfd) ? cli_sock : maxfd;

				printf("debug: someone connect me\n");
			}
			else 
			{
				int len = recv_all(i, buf);
				sleep(10);
				send_back(i, buf, len);
				printf("debug: recv and sendback %s\n", buf);
			}
		}

		for (i = 3; i <= maxfd; i++) {
			FD_SET(i, &rset);
			printf("\ndebug: goto select, check fd %d\n", i);
		}
	}

	close(srv_sock);

	return 0;
}
