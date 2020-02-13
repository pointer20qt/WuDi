#include<iostream>
using namespace std;

class people//基类
{
public:
	people()
	{
		cout << "people" << endl;
	}
	virtual ~people()//虚析构（基类析构函数常常定义成虚析构）
	{
		cout << "~people" << endl;
	}
	virtual void dowork()//虚函数
	{
		cout << "吃饭睡觉打豆豆" << endl;
	}
};
class student:public people//派生类
{
public:
	student()
	{
		cout << "student" << endl;
	}
	~student()
	{
		cout << "~student" << endl;
	}
	void dowork()
	{
		cout << "吃饭睡觉打游戏" << endl;
	}
};



int main()
{
	people *c = new student;//父类指针指向子类对象（有可能不走子类析构）
	//c->dowork(); 不加virtual时：输出“吃饭睡觉打豆豆”，函数隐藏时看指针类型调用函数
	c->dowork(); //加了virtual后：输出“吃饭睡觉打游戏”，看指针中存的谁的地址
	delete c;
	//student s;
	//s.dowork();//输出“吃饭睡觉打游戏”，函数隐藏，隐藏了基类的dowork
	return 0;
}