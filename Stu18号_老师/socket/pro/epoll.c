int main()
{
	int epollfd = epoll_create(10);

	int srv_sock = Socket();

	struct epoll_event ev;
	ev.data.fd = srv_sock;
	ev.events = EPOLLIN;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, srv_sock, &ev);

	nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);

	close(epollfd);	
}





