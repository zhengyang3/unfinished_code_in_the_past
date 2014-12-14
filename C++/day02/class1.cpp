#include<iostream>
using namespace std;
              //覆盖   在两个void eat()前面加上virtual就变成了“重写“！
				//加上virtual 就表示允许其子类对其进行修改！
				//只能是父类的指针指向子类的对象
class A
{
	public:
		void eat()
		{
			cout<<"A eat"<<endl;
		}		
};
class B:public A
{
	public:
		void eat()
		{
			cout<<"B eat"<<endl;			
		}
};
int main()
{
	B b;
	b.eat();
	return 0;
}
