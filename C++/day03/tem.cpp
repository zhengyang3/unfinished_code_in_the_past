#include<iostream>
using namespace std;
class A
{
	public:
		A(const int& d):data(d){}
		~A(){}
		void print()
		{
			cout<<data<<endl;
		}
	private:
		int data;
};
class B
{
	public:
		B(const double& d):data(d){}
		~B(){}
		void print()
		{
			cout<<data<<endl;
		}
	private:
		double data;
};
//定义一个支持任意类型的模板
template<class T>
class temp
{
	public:
		temp(const T& d):data(d){}
		~temp(){}
		void print()
		{
			cout<<data<<endl;
		}
	private:
		T data;
};
int main()
{
	temp<int>t1(1);
	temp<double>t2(2.123);
	temp<string>t3("1234");
	t1.print();
	t2.print();
	t3.print();
		
	return 0;
}













