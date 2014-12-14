#include<iostream>
using namespace std;
class test
{
	private:
		int data;
	public:
		test(const int& d):data(d){}
		test(const test& p)  //拷贝构造函数
		{
			if(&p==this) return;
			cout<<"11111111"<<endl;
			this->data=p.data;			
		}
		~test(){}
		void print()
		{
			cout<<data<<endl;
		}
};
int main()
{
	test t1(1);
	test t2(t1);
	//t2.test(t1);
	t2.print();
	return 0;

}
