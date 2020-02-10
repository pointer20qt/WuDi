#include "test.h"
#include<iostream>


test::test()
{
	std::cout << "创建" << std::endl;
}


test::~test()
{
	std::cout << "析构" << std::endl;
}
void test::run()
{
	std::cout << "调用了run函数" << std::endl;
}
