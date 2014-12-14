#include <>

int main()
{
	Socket();
	Bind();
	Listen();

	for (1000) {
		fork();
		if (parent)
			goto parent_do;
		else if (child)
			goto child_do;
	}

parent_do:
	while (1) {
	}

	return 0;

child_do:
	cli_sock = Accept();
	recv_all(cli_sock);
	send_back();

	return 0;
}
