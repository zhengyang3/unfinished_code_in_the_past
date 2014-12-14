
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


// I/O多路复用     弊端：不能多个用户同时收发数据！
