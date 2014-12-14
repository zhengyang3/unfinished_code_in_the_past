#include <stdio.h>

/*
 * server
 */

int main()
{
	sockfd = Socket();	
	Bind();
	Listen(sockfd);

	select(rset);

	printf("1\n");
	Accept(sockfd);
	printf("2\n");

	return 0;
}





