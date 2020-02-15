#include<iostream>
using namespace std;


template<class T, class...args>void Lprint(T f,args... d)
{
	cout << f << endl;
	Lprint(d...);
}

void Lprint()
{
	cout << "结束" << endl;
}

int main()
{
	Lprint(2, 3.0, 5, "123");
}

//模板参数包  递归拆包过程
//print的功能，传入任意多个参数，全输出到屏幕上

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