#include <stdio.h>

int main()
{
	// part 2
	int fd = open("1.txt", O_CREAT|O_RDWR, 0644);
	read(fd, buf, 32);
	printf("%s\n", buf);

	// part 1
	char buf[32] = 0;
	read(0, buf, 31);
	printf("%s\n", buf);

	return 0;
}
