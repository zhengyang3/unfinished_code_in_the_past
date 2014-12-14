#include<iostream>
using namespace std;
class animal
{
	public:
		int foot;
		int hand;
	public:
		void eat();
		void sleep();
		animal();
		~animal(){}		
};

void animal:: eat()
{
	cout<<"eat"<<endl;
}
void sleep::sleep()
{
	cout<<"sleep"<<endl;
}
animal::~animal()
{

}
int main()
{	
	
		
	return 0;
}
