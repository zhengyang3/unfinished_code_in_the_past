
int main()
{
	Socket();
	Bind();
	Listen();

	while (1) {
		Accept();
		while (1) {
			Recv() / Send();
		}
	}

	return 0;
}
