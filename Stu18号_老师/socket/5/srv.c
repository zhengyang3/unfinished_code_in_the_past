do_it()
{
	Recv()/Send();
}

int main()
{
	Socket();
	Bind();
	Listen();

	pthread_create(100, do_it);

	while (1) {
		Accept();
	}


}
