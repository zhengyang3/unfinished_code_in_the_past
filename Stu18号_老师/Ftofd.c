#include <stdio.h>

int main()
{
	// FILE * --> fd
	int fd = fileno(stdout);
	write(fd, "1234\n", 5);

	// fd --> FILE *
	FILE* f = fdopen(1, "w+");
	fprintf(f, "5678\n");

	return 0;
}
