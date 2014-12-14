#include <stdio.h>
#include <string.h>

#include "wrap.h"

int main()
{
	struct pollfd fds[3];
	fds[0].fd = -1;
	fds[1].fd = -1;
	fds[2].fd = -1;

	int srv_sock = Socket(AF_INET, SOCK_STREAM, 0);
	fds[0].fd = srv_sock;
	fds[0].events = POLLIN;

	struct sockaddr_in srv_addr;
	mkaddr(&srv_addr, "127.0.0.1", "2345");
	Bind(srv_sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

	Listen(srv_sock, 5);

	int ret = 0;
	char buf[128];
	int i = 1;
	while (1) {
		printf("debug: going to poll().... "); 
		fflush(stdout);
		ret = Poll(fds, i, -1);
		printf("%d\n", ret);

		int j = 0;
		for (j = 0; j < i; j++)
		{
			if (fds[j].fd == -1)
				continue;

			if ((fds[j].fd == srv_sock) && ((fds[j].revents & POLLIN) == POLLIN)) {
				int cli_sock = Accept(srv_sock, NULL, NULL);
				fds[i].fd = cli_sock;
				fds[i].events = POLLIN;
				i++;

				printf("debug: create a new connection\n");
				if (--ret == 0)
					break;
			}

			if ((fds[j].revents & POLLIN) == POLLIN) {
				printf("debug: is on the cli_sock %d\n", fds[j].fd);
				int len = recv_all(fds[j].fd, buf);
				if (len == -1) {
					close(fds[j].fd);
					fds[j].fd == -1;
					bzero(&fds[j], sizeof(struct pollfd));
					printf("here\n");
					break;
				}

				send_back(fds[j].fd, buf, len);
				printf("debug: send back %s\n", buf);
			}

			if ((fds[j].revents & POLLHUP) == POLLHUP) {
				close(fds[j].fd);
				printf("debug POLLUP\n");
			}

		}
	}

	close(srv_sock);

	return 0;
}
