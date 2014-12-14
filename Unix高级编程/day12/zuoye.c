	int arr[2];
	pipe(arr);//无名管道，父子进程用
	char* cmd="pwd";
	int pid=fork();
	if(pid==-1)
	{
		fprintf(stderr,"fork error\n");
	}
	else if(pif==0)
	{
		close(arr[0]);
		dup2(arr[1],1);
		execlp("pwd","pwd",NULL);
	}
	int c;
	int ret;
	while(1)
	{
		ret=read(arr[0],&c,1);
		
		if(ret==0)
			break;
		putchar(c);
	}
