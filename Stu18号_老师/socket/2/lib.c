#include <stdio.h>

#include "lib.h"

void mkaddr(struct sockaddr_in * addr, char * ip, char * port)
{
	int p = atoi(port);

	addr->sin_family = AF_INET;
	addr->sin_port = htons(p);
	inet_aton(ip, &(addr->sin_addr));
}

int recv_len(int cli_sock)
{
	int len = 0;

	int ret = Recv(cli_sock, &len, 4, MSG_WAITALL);
	if (ret == 0) {
		printf("peer is closed, disconnected\n");
		return -1;
	}

	return len;	
}
