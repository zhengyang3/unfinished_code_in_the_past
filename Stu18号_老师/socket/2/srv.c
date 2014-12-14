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
	char cmd[128];
	char buf[128];
	int cli_sock = Accept(srv_sock, NULL, NULL);

	int c;
	int len;
	while (1) {
		// get cmd len
		len = recv_len(cli_sock);
		if (len == 0)
			break;
		printf("debug1: recv len %d\n", len);
		cmd[len] = '\0';

		// get cmd string
		ret = Recv(cli_sock, cmd, len, MSG_WAITALL);
		if (ret == 0) {
			printf("peer is closed, disconnected\n");
			close(cli_sock);
			return 0;
		}
		printf("debug2: %s\n", cmd);

		// exec cmd
		FILE * f = popen(cmd, "r");
		while (1) {
			bzero(buf, 128);
			ret = fread(buf, 128, 1, f);
			int i = strlen(buf);
			if (i == 0) {
				Send(cli_sock, &i, 4, 0);
				break;
			}
			else {
				Send(cli_sock, &i, 4, 0);
				Send(cli_sock, buf, i, 0);
			}
		}
	}

	close(srv_sock);

	return 0;
}
