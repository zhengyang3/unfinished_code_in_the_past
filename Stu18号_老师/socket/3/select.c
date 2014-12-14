#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval;

	int fd = open("1.txt", O_RDWR);

	/* Watch stdin (fd 0) to see when it has input. */
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	FD_SET(fd, &rfds);

	int maxfd = (fd > 0) ? fd : 0;

	/* Wait up to five seconds. */
	tv.tv_sec = 5;
	tv.tv_usec = 0;

	char buf[32] = {0};

	retval = select(maxfd+1, &rfds, NULL, NULL, &tv);
	if (retval == -1)
		perror("select()");
	else if (retval) {
		printf("Data is available now.\n");
		if (FD_ISSET(0, &rfds)) {
			read(0, buf, 31);
			printf("%s\n", buf);
		}
		if (FD_ISSET(fd, &rfds)) {
			read(fd, buf, 31);
			printf("%s\n", buf);
		}
	}	
	else
		printf("No data within five seconds.\n");

	exit(EXIT_SUCCESS);
}
