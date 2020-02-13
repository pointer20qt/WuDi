#include<iostream>
using namespace std;

class A {
public:
	virtual void get() = 0;
};

class B :public A {
public:
	void get()
	{
		cout << "派生类" << endl;
	}

};

int main()
{
	//A a;错误
	A * a = new B;//正确
	a->get();
	delete a;
	
	B b;
	b.get();

}