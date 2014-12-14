#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
	int a[5]={1,2,3,4,5};
	char* str="123456";
	vector<int>v1(a,a+5);
	//vector<char>v2(str,str+strlen(str));
	//cout<<v1[0]<<endl;
	//定义一个迭代器，用指针的方式来打印数据 
	v1.push back(6)
	for(vector<int>::const_iterator p=v1.begin();  p!=v1.end(); ++p)
	{
		cout<<*p<<" ";
	}
	cout<<endl;
	return 0;
}
