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
	mkaddr(&srv_addr, "127.0.0.1", "2345");
	Bind(srv_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	Listen(srv_sock, 5);

	int cli_sock = -1;
	char buf[128];
	while (1) {
		// 1. set [srv_sock]
		// 2. set [srv_sock, cli_sock1]
		n = Select(maxfd+1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(srv_sock, &rset)) {
			cli_sock = Accept(srv_sock, NULL, NULL);
			maxfd = (cli_sock > maxfd) ? cli_sock : maxfd;
			printf("debug: someone connect me\n");
		}
		else if (FD_ISSET(cli_sock, &rset)) {
			int len = recv_all(cli_sock, buf);
			send_back(cli_sock, buf, len);
			printf("debug: recv and sendback %s\n", buf);
		}

		FD_SET(srv_sock, &rset);
		FD_SET(cli_sock, &rset);
	}

	close(srv_sock);

	return 0;
}
