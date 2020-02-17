#include<iostream>
//#include<memory>
#include"shared_ptr.h"

using namespace std;

class tool{
public:
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
int main()
{
	LSharedPtr<tool>ptr1(new tool);
	cout << "��ǰ���ü���" << ptr1.use_count() << endl;//1
	LSharedPtr<tool>ptr2(ptr1);
	LSharedPtr<tool>ptr3;
	ptr3 = ptr2;
	cout << "��ǰ���ü���" << ptr1.use_count() << endl;//3
}