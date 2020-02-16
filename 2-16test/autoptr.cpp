#include<iostream>
#include"autoptr.h"

using namespace std;

class tool{
	
public:
	int value = 0;
	tool(){
		cout << "tool������" << endl;
	}
	tool(int t){
		cout << "������������,������t" << t << endl;
	}
	tool(const tool&){
		cout << "tool����������" << endl;
	}
	tool(tool&&){
		cout << "tool�ƶ�������" << endl;
	}
	~tool(){
		cout << "tool������" << endl;
	}
	tool& operator = (tool&&){
		cout << "tool�ƶ���ֵ��" << endl;
		return *this;
	}
	tool& operator = (const tool&){
		cout << "tool������ֵ��" << endl;
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