       
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


   //多用户
   多个用户接收数据，之前发送数据的用户现在还能再次发送吗
   不可以：虽然每accept一次就会创建一个cli_sock文件，每次都不一样，之前的创
   建的cli_sock还在，但是发送端发送了数据，这边并没有代码去接收！
