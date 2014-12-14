#include <stdio.h>
#include <string.h>

#include "wrap.h"

int main()
{
	int srv_sock = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in srv_addr;
	mkaddr(&srv_addr, "127.0.0.1", "2345");
	Bind(srv_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	Listen(srv_sock, 5);

	int ret = 0;
	char buf[128];
	while (1) {
		int cli_sock = Accept(srv_sock, NULL, NULL);

		while (1) {
			// recv anythind and send back.
			int len = recv_all(i, buf);
			if (len == 0) {
				printf("client is closed. Disconnect!\n");
				close(cli_sock);
				break;
			}
			send_back(i, buf, len);
		}
	}

	close(srv_sock);

	return 0;
}
