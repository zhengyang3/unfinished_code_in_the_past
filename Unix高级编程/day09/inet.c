#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	char* ip="192.168.0.1";
	in_addr_t nip;
	nip=inet_addr("192.168.0.1");
	printf("addr---nip--->%d\n",nip);
	//in_addr_t tip=192<<24|168<<16|0<<8|1;
	//printf("addr---tip--->%d\n",tip);

	//struct to string
	struct in_addr sip={0};
	sip.s_addr=nip;
	printf("string IP:%s\n",inet_ntoa(sip));

	
	char ip2[4]={192,168,0,1};   //4字节整型表示IP的方式
	printf("%d\n",*(int*)ip2);//强制类型转换
	//4字节整型转换成一个一个的整型
	printf("%hhu.%hhu.%hhu.%hhu\n",nip>>0&255,nip>>8&255,nip>>16&255,nip>>24&255);
	
	//字符串转换成结构体
	struct in_addr addr;
	inet_aton("192.168.0.1",&addr);
	
	
	return 0;
}































