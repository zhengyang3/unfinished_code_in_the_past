#include <stdio.h>

void do_it(char *argv[])
{
	while (argv[i] != NULL)
	{
		printf("%s ", argv[i]);
		i++;
	}

	printf("\n");
}

int main()
{
	char * argv[] = {"ls", "-l", "-a", NULL};

	do_it(argv);

	return 0;
}
