#include<iostream>
#include<memory>
#include"unique.h"

using namespace std;

class tool{
public:
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
int main()
{
	L_uniquePtr<tool>ptr1(new tool);
	L_uniquePtr<tool>ptr2(move(ptr1));
	L_uniquePtr<tool>ptr3;
	ptr3 = move(ptr2);
}