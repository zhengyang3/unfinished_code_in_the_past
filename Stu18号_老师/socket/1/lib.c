#include "lib.h"

void mkaddr(struct sockaddr_in * addr, char * ip, char * port)
{
	int p = atoi(port);

	addr->sin_family = AF_INET;
	addr->sin_port = htons(p);
	inet_aton(ip, &(addr->sin_addr));
}

