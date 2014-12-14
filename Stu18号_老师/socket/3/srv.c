
// server
int main()
{
	Socekt();

	Bind();

	while (1) {
		Accept();
		fork();
		if (child) {
			Recv();
			sleep(10);
			Send();
			close();
		}
		else (parent)
		{

		}
	}
	
	return 0;
}
