#include <stdio.h>

int main()
{
	FILE * f = fopen("1.txt", "r");

	char buf[128] = {0};

	int ret = fread(buf, 128, 1, f);
	if (ret == 0) {
		printf("here\n");
		printf("%s\n", buf);
	}
	
	return 0;
}


