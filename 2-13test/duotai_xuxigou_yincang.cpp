#include<iostream>
using namespace std;

class people//����
{
public:
	people()
	{
		cout << "people" << endl;
	}
	virtual ~people()//�������������������������������������
	{
		cout << "~people" << endl;
	}
	virtual void dowork()//�麯��
	{
		cout << "�Է�˯���򶹶�" << endl;
	}
};
class student:public people//������
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
		cout << "�Է�˯������Ϸ" << endl;
	}
};



int main()
{
	people *c = new student;//����ָ��ָ����������п��ܲ�������������
	//c->dowork(); ����virtualʱ��������Է�˯���򶹶�������������ʱ��ָ�����͵��ú���
	c->dowork(); //����virtual��������Է�˯������Ϸ������ָ���д��˭�ĵ�ַ
	delete c;
	//student s;
	//s.dowork();//������Է�˯������Ϸ�����������أ������˻����dowork
	return 0;
}