
int main()
{
	Socket();
	Bind();
	Listen();

	while (1) {
		select()/poll()/epoll();

		if () {
			Accept();
		}
		else {
			while (1) {
				Recv() / Send();
			}
		}
	}

	return 0;
}
