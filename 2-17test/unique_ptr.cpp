#include<iostream>
#include<memory>
#include"unique.h"

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
	L_uniquePtr<tool>ptr1(new tool);
	L_uniquePtr<tool>ptr2(move(ptr1));
	L_uniquePtr<tool>ptr3;
	ptr3 = move(ptr2);
}