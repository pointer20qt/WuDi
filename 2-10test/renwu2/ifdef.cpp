#include <iostream>
#include"ifdef.h"
#include"ifdef.h"//��������ͷ�ļ�ʱ��Ҳ��ִ��
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
	cout << "���" << endl;
}