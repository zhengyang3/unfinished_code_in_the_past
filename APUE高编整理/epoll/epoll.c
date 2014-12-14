#include <sys/epoll.h>
#include <stdio.h>

int main()
{
	struct epoll_event events[16];

	int epfd = epoll_create(16);

	events[0].data.fd = 0;
	events[0].events = EPOLLIN;

	epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &events[0]);
	
	int nr_events = epoll_wait(epfd, events, 1, -1);
	int i;
	for (i = 0; i < nr_events; i++) {
		printf("event=%ld on fd=%d\n", 
				events[i].events, events[i].data.fd);
	}


	return 0;
}
