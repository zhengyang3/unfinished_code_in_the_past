#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
//	execl("/bin/ls", "ls", "/home/ben", NULL);
//	execlp("ls", "ls", "/home/ben", NULL);

	char * xxxx[] = {"ls", "/home/ben", "-l", "-a", NULL};
	execv("/bin/ls", xxxx);

	return 0;
}


/*
例子说明：

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

*/






