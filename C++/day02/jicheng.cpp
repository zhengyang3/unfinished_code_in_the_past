#include<iostream>
using namespace std;
class A
{
	public:
	A()
	{
		cout<<"A 构造"<<endl;
	}
	~A()
	{
		cout<<"A 析构"<<endl;
	}
};
 
class B:public A
{
	public:
		B(){cout<<"B 构造"<<endl;}
		~B(){cout<<"B 析构"<<endl;}

};
class C:public B
{
	public:
		C(){cout<<"C 构造"<<endl;}
		~C(){cout<<"C 析构"<<endl;}

};

int main()
{	
	C c;
	
	return 0;
}
