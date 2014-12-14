#include <string.h>
#include <stdio.h>

#include "wrap.h"

int main()
{
	int cli_sock = Socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in srv_addr;
	mkaddr(&srv_addr, "127.0.0.1", "2345");

	Connect(cli_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	char cmd[64] = {0};
	while (1) {
		fgets(cmd, 63, stdin);
		cmd[strlen(cmd)-1] = '\0';

		if (strncmp(cmd, "exit", 4) == 0)
			break;

		Send(cli_sock, cmd, strlen(cmd), 0);

		while (1)
		{
			Recv(cli_sock, );

		}
	}

	close(cli_sock);

	return 0;
}
