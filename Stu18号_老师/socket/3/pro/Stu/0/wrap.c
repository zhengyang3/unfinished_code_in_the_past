#include <stdlib.h>
#include <errno.h>

#include "wrap.h"

int Socket(int domain, int type, int protocol)
{
	int ret = socket(domain, type, protocol);
	if (ret == -1) {
		perror("socket");
		exit(1);
	}
}

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	int ret = bind(sockfd, addr, addrlen);
	if (ret == -1) {
		perror("socket");
		exit(1);
	}
}

int Listen(int sockfd, int backlog)
{
	int ret = listen(sockfd, backlog);
	if (ret == -1) {
		perror("listen");
		exit(1);
	}
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int ret = accept(sockfd, addr, addrlen);
	if (ret == -1) {
		perror("accept");
		exit(1);
	}

	return ret;
}

ssize_t Recv(int sockfd, void *buf, size_t len, int flags)
{
	int ret = recv(sockfd, buf, len, flags);
	if (ret == -1) {
		perror("recv");
		exit(1);
	}

	return ret;
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	int ret = connect(sockfd, addr, addrlen);
	if (ret == -1) {
		perror("connect");
		exit(1);
	}
}

ssize_t Send(int sockfd, const void *buf, size_t len, int flags) {
	ssize_t ret = send(sockfd, buf, len, flags);
	if (ret == -1) {
		perror("send");
		exit(1);
	}

	return ret;
}

int Select(int nfds, fd_set *readfds, fd_set *writefds,
                  fd_set *exceptfds, struct timeval *timeout)
{
	int ret = select(nfds, readfds, writefds, exceptfds, timeout);
	if (ret == -1) {
		perror("select");
		exit(1);
	}

	return ret;
}











