#include "wrap.h"

void mkaddr(struct sockaddr_in * addr, char * ip, char * port) ;
int recv_len(int fd);
int recvn(int fd, void* buf, int n);
int recv_all(int cli_sock, void * buf);
void send_back(int cli_sock, void* buf, int len);
