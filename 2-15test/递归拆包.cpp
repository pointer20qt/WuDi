#include<iostream>
using namespace std;


template<class T, class...args>void Lprint(T f,args... d)
{
	cout << f << endl;
	Lprint(d...);
}

void Lprint()
{
	cout << "����" << endl;
}

int main()
{
	Lprint(2, 3.0, 5, "123");
}

//ģ�������  �ݹ�������
//print�Ĺ��ܣ�����������������ȫ�������Ļ��

/*void Lprint(const char* f){
cout << f << endl;
Lprint();
}
void Lprint(int f,const char* d){
cout << f << endl;
Lprint(d);
}
void  Lprint(double f, int d1, const char* d2){
cout << f << endl;
Lprint(d1,d2);
}
void Lprint(int f,double d1,int d2,const char* d3){
cout << f << endl;
Lprint(d1,d2,d3);
}*/