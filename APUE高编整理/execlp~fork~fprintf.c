#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char input[128];
	while (1)
	{
		printf("mysh$ ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input)-1] = '\0';
		//printf("debug: %s\n", input);

		if (strncmp(input, "exit", 4) == 0)
			return 0;

		int pid = fork();
		if (pid == -1) {
			fprintf(stderr, "fork error\n");
			return 1;
		}
		else if (pid == 0) {
			execlp(input, input, NULL);
			fprintf("stderr", "exec error\n");
		}
		wait(NULL);
	}

	return 0;
}
