#include<iostream>
#include<string>

using namespace std;

using s = string;//ʹ��using

class principal{
	friend class school;//��Ԫ��
	s name;
	principal(s name){
		this->name = name;
	}
	~principal(){
		cout << "����" << endl;
	}

};



class school{
public:
	s schoolName;
	s schoolType;
	s address;
	principal *master;
	school(s schoolName, s schoolType, s address){
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("����ʦ");
	}
	school(const school& a)
	{
		cout << "�������캯��" << endl;
		//master = new principal(*(p.master));
	}
	school(school&& other) :schoolType(other.schoolType), schoolName(other.schoolName), address(other.address)
	{
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
	~school(){
		delete master;
	}

};

school getschool(){
	school s2("����ʯ�ʹ�ѧ", "��ѧ", "����");
	return s2;
}
int main()
{
	school s1(getschool());
	//school s2(std::move(s1));
	return 0;
}