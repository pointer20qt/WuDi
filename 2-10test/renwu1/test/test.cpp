#include<iostream>
#include"test.h"
#pragma comment(lib,"libtest.lib")
int main()
{
	std::cout << "��ʼ����" << std::endl;
	test t;
	t.run();
}
