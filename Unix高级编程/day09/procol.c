#include<stdio.h>
#include<sys/utsname.h>
#include<netdb.h>
int main()
{
	struct protoent* ent;
	ent=getprotobyname("tcp");
	printf("name:%s----nub:%d\n",ent->p_name,ent->p_proto);
	struct utsname name;
	uname(&name);
	printf("%s\n",name.machine);
	printf("%s\n",name.sysname);
	printf("%s\n",name.nodename);
	printf("%s\n",name.version);
	//printf("%s\n",name.domainname);
	return 0;
}
