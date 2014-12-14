#include<iostream>
using namespace std;
class stu
{
	public:
		int age;
		char name[15];
		float getscore()
		{
			erturn score;
		}		
		float setscore()
		{
			return score;
		}
	private:
		float score;
	public:
		void fun()
		{
			cout<<"study"<<endl;
		}	
	stu()  // 构造函数,没有返回值
	{
		cout<<"gou zao han su "<<endl;
	}
	~stu()
	{
		cout<<"析构函数"<<endl;
	}
};
int main()
{
	stu s1;
	stu* s2;
	s1.fun();
	s1.age=80;
	strcpy(s1.name,"123456");
	s1.setscore(99);
	cout<<s1.age<<endl;
	cout<<s1.name<<endl;
	cout<<s1.getscore()<<endl;
	return 0;
	
}





















