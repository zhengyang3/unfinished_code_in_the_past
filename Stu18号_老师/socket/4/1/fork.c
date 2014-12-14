#include <unistd.h>
#include <stdio.h>

int i = 0;

int main()
{
	int ret = fork();
	if (ret == 0) {
		i = 100;
		return 0;
	}

	wait(NULL);

	printf("%d\n", i);

	return 0;
}
