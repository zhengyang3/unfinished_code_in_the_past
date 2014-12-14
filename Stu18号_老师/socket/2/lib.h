#include "wrap.h"

void mkaddr(struct sockaddr_in * addr, char * ip, char * port) ;
int recv_len(int fd);
int recvn(int fd, void* buf, int n);

