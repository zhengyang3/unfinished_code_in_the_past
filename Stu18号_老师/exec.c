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

