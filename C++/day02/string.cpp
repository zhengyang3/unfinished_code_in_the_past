#include<iostream>
using namespace std;
class String
		{
			public:
				String(const char* str=NULL);//通用构造函数
				String(const string& a);//拷贝构造函数
				~String();
				String& operator=(const String& a) //运算符重载
			private:
				char* m_data;
				
		} ;
String::String(const char* str)      //很重要，必考题！
{
	if(str==NULL)
	{
		m_data=new char[1];
		m_data[0]='\0';
	}
	else
	{
		m_data=new char[strlen(str)+1];
		strcpy(m_data,str);
	}
	
}


String::String(const string& a);//拷贝构造函数
{
	m_data=new char[strlen(a.m_data)+1];
	strcpy(m_data,a.m_data);
}

String& String::String& operator=(const String& a)//运算符重载(赋值函数)
{
	if(this==&a) return *this;
	delete []m_data; //删除原来的数据新开辟一块内存；
	m_data=new char[strlen(a.m_data)+1];
	strcpy(m_data,a.m_data);
	return *this;
}

String::~String()
{
	delete[] m-data;
}






