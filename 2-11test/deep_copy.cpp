#include<iostream>
using namespace std;

class people
{
	int age;
	char*name;
public:
	void setage(int age)
	{
		this->age = age;
	}
	int getage()
	{
		return age;
	}
	people()
	{
		name = (char*)malloc(20);
		strcpy(name, "xxx");
	}
	char*getname()
	{
		return name;
	}

	people(int a)
	{

	}
	people(const people& rgh)//不用深拷贝 程序崩溃
	{
		this->age = rgh.age;
		this->name = rgh.name;
	}
	//people(const people& rgh)//深拷贝
	//{
	//	this->age = rgh.age;
	//	this->name = (char*)malloc(20);
	//	strcpy(this->name, rgh.name);
	//}

	~people()
	{
		free(name);
	}
};

people printpeople()
{
	people rgh;//game over
	rgh.setage(10);
	return rgh;
}
int main()
{
	people p;
	cout << p.getname() << endl;
	people p2(p);
	cout << p2.getname() << endl;
 
	return 0;
}
