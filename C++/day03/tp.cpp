#include<iostream>
using namespace std;
template<class T,class T1,class T2>

T2 add(T a , T1 b)
{
	return a+b;
};
int main()
{
	cout<<add<int ,int,int>(1,2)<<endl;
	return 0;
}
