#include<iostream>
#include"weak_ptr.h"
using namespace std;

class node
{
public:
	Weakptr<node>pre;//LSharedPtr<node>pre;
	Weakptr<node>next;//LSharedPtr<node>next;
	~node()
	{
		cout << "节点已析构" << endl;
	}
};
int main()
{
	LSharedPtr<node>node1 = { new node };
	LSharedPtr<node>node2 = { new node };
	node1->next = node2;
	node2->pre = node1;
}