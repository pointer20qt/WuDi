#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5, 6 };
	try{
		for (int i = 0; i < 7; i++)
		{
			cout << arr.at(i) << endl;
			
		}//�����쳣����ת��catch �쳣1
		throw 2;//�Լ��׳��쳣 �쳣2 ��ֻ��catch��ǰ����쳣��
		cout << "��ӡ����" << endl;
	}
	catch (int test)
	{
		cout << "�������쳣,�쳣����"<<test << endl;
	}
	catch (out_of_range & e)
	{
		cout << "������Խ���쳣" << endl;//��ƥ���쳣��catchƥ����֮�󣬾Ͳ������������쳣
	}
	catch (...)//(...)�����쳣����catch
	{
		cout << "�������쳣" << endl;
	}
	cout << "�������һ��" << endl;//������Ȼ��������

}