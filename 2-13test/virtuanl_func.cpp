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
		cout << "������" << endl;
	}

};

int main()
{
	//A a;����
	A * a = new B;//��ȷ
	a->get();
	delete a;
	
	B b;
	b.get();

}