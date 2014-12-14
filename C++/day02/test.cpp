#include<iostream>
using namespace std;
class test
{
	virtual void fun()
	{
		cout<<"123424"<<endl;
	}
	virtual void fun()
	{
		cout<<"123424"<<endl;
	}
};
struct a{};
int main()
{
	cout<<sizeof(a)<<endl;
	cout<<sizeof(test)<<endl;
	 //有函数没有实际变量还是 1；加上virtual会加上一个虚表指针, 大小就是4个字节；
	 //然后再增加一个virtual,大小还是4个字节，因为它只会生成一个虚表指针；
	return 0;
}
