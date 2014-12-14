#include <string.h>
#include <stdio.h>

#include "wrap.h"

int main()
{
	int cli_sock = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in srv_addr;
	mkaddr(&srv_addr, "127.0.0.1", "1234");

	Connect(cli_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	char cmd[64] = {0};
	char buf[256] = {0};
	int len;
	while (1) {
		printf("[please input a string]$ ");
		fgets(cmd, 63, stdin);
		cmd[strlen(cmd)-1] = '\0';

		if (strncmp(cmd, "exit", 4) == 0)
			break;

		len = strlen(cmd);

		Send(cli_sock, &len, 4, 0);

		// printf("debug: send len over\n");
		Send(cli_sock, cmd, strlen(cmd), 0);

		int ret = recv_all(cli_sock, buf);
		if (ret == -1)
			break;
		buf[ret] = '\0';
		printf("echo back: %s\n", buf);
	}

	close(cli_sock);

	return 0;
}
