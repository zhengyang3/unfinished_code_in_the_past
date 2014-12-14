#include <poll.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char buf[32] = {0};

	struct pollfd sets[2];
	sets[0].fd = 0;
	sets[0].events = POLLIN;
	sets[1].fd = open("1.txt", O_RDWR);
	sets[1].events = POLLIN | POLLOUT;

	int ret = poll(sets, 2, 5);

	printf("%d\n", ret);

	int i = 0;
	for (; i < 2; i++)
	{
		if ((sets[i].revents & POLLIN) == POLLIN) {
			read(sets[i].fd, buf, 31);
		}
		if ((sets[i].revents & POLLOUT) == POLLOUT) {
			write(sets[i].fd, "hello", 6);
		}
	}

	return 0;	
}



