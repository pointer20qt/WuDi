#include<iostream>
#include"autoptr.h"

using namespace std;

class tool{
	
public:
	int value = 0;
	tool(){
		cout << "tool构造了" << endl;
	}
	tool(int t){
		cout << "单参数构造了,参数是t" << t << endl;
	}
	tool(const tool&){
		cout << "tool拷贝构造了" << endl;
	}
	tool(tool&&){
		cout << "tool移动构造了" << endl;
	}
	~tool(){
		cout << "tool析构了" << endl;
	}
	tool& operator = (tool&&){
		cout << "tool移动赋值了" << endl;
		return *this;
	}
	tool& operator = (const tool&){
		cout << "tool拷贝赋值了" << endl;
		return *this;
	}
};
void run()
{
	_autoptr<tool>ptr1{ new tool };
	_autoptr<tool>ptr2(ptr1);
	_autoptr<tool>ptr3;
	ptr3 = ptr2;
	(*ptr2).value;
	ptr2->value;
}

int main()
{
	run();
}