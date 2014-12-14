#include<iostream>
using namespace std;
class List
{
	struct Node	//内部类型
	{
		int data;
		Node* next;
		Node(const int& d)
		{
			data=d;
			next=NULL;
		}		
		~Node(){}		
	};
	Node* head;
	public:
		List():head(NULL){}
		~List(){clear();}
		void clear()
		{
			Node*p=head;
			while(head!=NULL)
			{
				p=head->next;
				delete head;
				head=p;
			}
		
		}
		List& insert(const int& d)
		{
			Node* p=new Node(d);
			p->next=head;
			this->head=p;
			return *this;//当前对象指针
		}
		List& insert(const int& d ,int pos)
		{
			if(pos<0||pos>size()) pos=0;
			if(pos==0)
			{
				insert(d);//根据参数的个数找到的是上面的那个 insert
				return *this;
			}
			Node* p=new Node(d);
			Node* ptr=head;
			for(int i=1;i<pos;i++)
			{
				ptr=ptr->next;
			}
			p->next=ptr->next;
			ptr->next=p;
			return *this;
		}
		void print()
		{
			Node* p=head;
			while(p!=NULL)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
		}
		int size()
		{
			int n=0;
			Node* p=head;
			while(p!=NULL)
			{
				n++;
				p=p->next;
			}
			return n;
		}
		
};		

int main()
{	
	List list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);	
	list.insert(5);
    list.insert(6,3);
	list.print();	
	return 0;
}
