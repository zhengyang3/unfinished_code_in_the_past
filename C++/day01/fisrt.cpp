#include<iostream>
using namespace std;

int main()
{	
	int* a=new int;//
	int* p=new int[5]
	int* b=new int(100);
 	*a=5;
 	cout<<*a<<endl;
	cout<<*b<<endl;
 	delete a;	
  	delete [] p;
  	delete b;
	return 0;
}
