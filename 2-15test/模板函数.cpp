#include<iostream>
using namespace std;

//��ģ�壬����ģ��
template<class T> T Wmax(T a, T b)
{
	cout << "ʹ����ģ��" << endl;
	return a > b ? a : b;
}
double Wmax(double a, double b)
{
	cout << "ʹ����double" << endl;
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
	cout << a1 << "����" << a2 << endl;
	int x1 = 2, x2 = 6;
	Wswap(x1, x2);//ʵ����swap����
	cout << x1 << "����" << x2 << endl;
	double d1 = 5.4, d2 = 7.3;
	//��ʽ�Ƶ�
	cout << Wmax(x1, x2) << endl;
	//��ʾ�Ƶ�
	cout << Wmax<int>(d2, x2) << endl;
	//��ʾָ��ģ��
	cout << Wmax(d1, d2) << endl;
	cout << Wmax<>(d2, d1) << endl;//������ʹ��ģ�庯���Ƶ��ĺ���������ʹ�÷�ģ�庯����
}