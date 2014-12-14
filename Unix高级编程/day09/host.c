#include<stdio.h>
#include<netdb.h>
int main()
{
	//打开主机的配置文件
	sethostent(1);
	
	struct hostent* ent;
	ent=gethostent();
	printf("主机名称：%s\n",ent->h_name);
	printf("别名：%s\n",ent->h_aliases[0]);
	printf("IP addr:%hhu.%hhu.%hhu.%hhu\n",ent->h_addr[0],ent->h_addr[1],ent->h_addr[2],ent->h_addr[3]);
	endhostent();
	return 0;
}
