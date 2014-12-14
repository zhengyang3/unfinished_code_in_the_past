#include<iostream>
using namespace std;

class A
{
	public:
		A(){cout<<"A gouzao"<<endl;}
		~A(){cout<<"A xigou"<<endl;}
};

int main()
{
	A* a=new A[3]; 
	delete[] a; //释放的是数组的话，必须要加上中括号！！
	return 0;
}
