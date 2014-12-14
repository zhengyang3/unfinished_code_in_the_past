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

int recv_all(int cli_sock, void * buf)
{
	char * p = (char *)buf;

	int len = recv_len(cli_sock);
	if (len == -1)
		return -1;

	p[len] = '\0';
	int ret = Recv(cli_sock, buf, len, MSG_WAITALL);
	if (ret == 0) {
		// printf("peer is closed, disconnected\n");
		close(cli_sock);
		return -1;
	}

	// printf("debug recv: %s\n", p);

	return len;
}

void send_back(int cli_sock, void* buf, int len)
{
	Send(cli_sock, &len, sizeof(int), 0);
	Send(cli_sock, buf, len, 0);
}


