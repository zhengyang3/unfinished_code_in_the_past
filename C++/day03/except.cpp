#include<iostream>
#include<exception>
using namespace std;
int main()
{
	int i=0;
	
	cin>>i;
	try
	{	
		if(i==1) throw (1);
		if(i==2) throw (3.12); 
		if(i==3) throw ("sdfkja");
		if(i==4) throw ('c');
	}catch(int a)
	{
		cout<<"int exception"<<endl;
	}catch(double b)
	{
		cout<<"double exception"<<endl;
	}catch(const char* e)
	{
		cout<<"const char* exception"<<endl;
	}catch(...)
	{
		cout<<"exception"<<endl
	}
	cout<<"-----------"<<endl;
	return 0;
}
