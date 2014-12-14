#include<netdb.h>
#include<stdio.h>
int main()
{
	struc hostent* ent=NULL;
	ent=gethostbyname("");
	printf("")
	printf("host name:%s\n",ent->h_name);
	printf("aliases:%s\n",ent->h_aliases[0]);

}
