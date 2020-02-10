#include <iostream>
#include"ifdef.h"
#include"ifdef.h"//在有两个头文件时，也可执行
using namespace std;
#if 0 
int x;
#endif;
#if DEBUG
#error xx; 
#endif;
int main()
{
	A a;
	a.run();
}
void A::run()
{
	cout << "输出" << endl;
}