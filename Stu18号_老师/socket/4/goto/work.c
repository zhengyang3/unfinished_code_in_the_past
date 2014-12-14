int <stdio.h>

int main()
{
	int i = 0;
	do {
		printf("hello world\n");
		i++
	} while( i != 10)

	int j = 0;
loop:
	printf("hello world\n");
	j++;
	if (j != 10)
		goto loop;

	return 0;
}
