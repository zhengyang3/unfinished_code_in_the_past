#include<iostream>
#include<list>
#include<cstring>
using namespace std;
int main()
{
	list<int> l, l1;
	l.push_back(12);
	l.push_back(13);
	l.push_front(1);
	for(list<int>::iterator it=l.begin(); it!=l.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	l.sort();
	for(list<int>::iterator it=l.begin(); it!=l.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	l.reverse();
	for(list<int>::iterator it=l.begin(); it!=l.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;

}
