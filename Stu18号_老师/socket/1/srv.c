#include <stdio.h>

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
	int cli_sock = Accept(srv_sock, NULL, NULL);

	int c;
	while (1) {

		ret = Recv(cli_sock, buf, 127, 0);
		if (ret == 0) {
			printf("peer is close, disconnect\n");
			close(cli_sock);
			break;
		}
		buf[ret+1] = '\0';

		printf("%s\n", buf);

		FILE * f = popen(buf, "r");
		
		while ((c = fgetc(f)) != EOF)
		{
			printf("%c", (unsigned char)c);
			Send(cli_sock, &c, 1, 0);
		}
	}

	close(srv_sock);

	return 0;
}
