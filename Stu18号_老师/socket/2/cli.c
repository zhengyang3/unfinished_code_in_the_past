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
	char buf[256] = {0};
	int len;
	while (1) {
		printf("[remote sh]$ ");
		fgets(cmd, 63, stdin);
		cmd[strlen(cmd)-1] = '\0';

		if (strncmp(cmd, "exit", 4) == 0)
			break;

		len = strlen(cmd);

		// send cmd len.			eg.   	3
		Send(cli_sock, &len, 4, 0);

		printf("debug: send len over\n");
		// send cmd string.			eg. 	"pwd"
		Send(cli_sock, cmd, strlen(cmd), 0);

		// recv the result of cmd	eg.		"/home/xx/xx/xx"
		int ret = 0;
		int len = 0;
		while (1) {
			ret = Recv(cli_sock, &len, 4, MSG_WAITALL);
			if (ret == 0) {
				printf("peer is closed, disconnect\n");
				close(cli_sock);
				break;
			}

			if (len == 0) {
				break;
			} else {
				buf[len] = '\0';
				Recv(cli_sock, buf, len, MSG_WAITALL);
				printf("%s", buf);
				fflush(stdout);
			}
		} 
	}

	close(cli_sock);

	return 0;
}
