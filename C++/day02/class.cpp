#include<iostream>
using namespace std;
class Person
{
	public:
		void eat(){cout<<"eat"<<endl;}
		void sleep(){cout<<"sleep"<<endl;}
};
class teacher:public virtual Person
{
	public:
		void teach(){cout<<"teach"<<endl;}
};
class worker:public virtual Person
{
	public:
		void work(){cout<<"work"<<endl;}
		
};
class jianzhi:public teacher,public worker
{
	public:
		void fun(){cout<<"兼职"<<endl;}
};


int main()
{
	jianzhi x;
	x.teach();
	x.work();
	x.eat(); //重复继承（虚继承）
	x.fun();
	Person* p=NULL;
	teacher t;
	p=&t;
	p->eat();
	return 0;
}
