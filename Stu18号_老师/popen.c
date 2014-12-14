#include <stdio.h>
#include <unistd.h>

int main()
{
	/*
	FILE * f = popen("ls -l -a", "r");

	char buf[512];
	while (1) {
		char * ret = fgets(buf, 512, f);
		if (ret == NULL)
			break;
		printf("%s", buf);
	}
	*/

	int arr[2];
	pipe(arr);

	char* cmd = "pwd";

	int pid = fork();
	if (pid == -1) {
		fprintf(stderr, "fork() error\n");
		return 1;
	} else if (pid == 0) {
		close(arr[0]);
		dup2(arr[1], 1);
		execlp("pwd", "pwd", NULL);
		//execl("/bin/bash", "sh", "-c", cmd, NULL);
	}

	close(arr[1]);
	int c;
	int ret ;
	while (1) {
		ret = read(arr[0], &c, 1);
		if (ret == 0)
			break;

		putchar(c);
	}


	return 0;
}




