do_it()
{
	while (1) {
		Recv() / Send();
	}
}

int main()
{
	Socket();
	Bind();
	Listen();

	while (1) {
		Accept();
		pthread_create(do_it);
	}

	return 0;
}

//多线程版本
