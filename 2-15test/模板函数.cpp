#include<iostream>
using namespace std;

//类模板，函数模板
template<class T> T Wmax(T a, T b)
{
	cout << "使用了模板" << endl;
	return a > b ? a : b;
}
double Wmax(double a, double b)
{
	cout << "使用了double" << endl;
	return a > b ? a : b;
}
template<class T> void Wswap(T& a, T& b)
{
	T tem = a;
	a = b;
	b = tem;
}
class A
{
public:
	int value = 0;
	char*p;
	A(int v)
	{
		p = new char[100];
		value = v;
	}
	A(const A& other)
	{
		p = new char[100];
		value = other.value;
	}
	A& operator=(const A& other)
	{
		delete[]p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	operator int()
	{
		return value;
	}
	~A()
	{
		delete[]p;
	}
};
int main()
{
	A a1(20), a2(23);
	Wswap(a1, a2);
	cout << a1 << "交换" << a2 << endl;
	int x1 = 2, x2 = 6;
	Wswap(x1, x2);//实现了swap函数
	cout << x1 << "交换" << x2 << endl;
	double d1 = 5.4, d2 = 7.3;
	//隐式推导
	cout << Wmax(x1, x2) << endl;
	//显示推导
	cout << Wmax<int>(d2, x2) << endl;
	//显示指定模板
	cout << Wmax(d1, d2) << endl;
	cout << Wmax<>(d2, d1) << endl;//（必须使用模板函数推导的函数，不能使用非模板函数）
}