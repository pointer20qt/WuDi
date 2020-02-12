#include<iostream>
#include<string>

using namespace std;

using s = string;//使用using

class principal{
	friend class school;//友元类
	s name;
	principal(s name){
		this->name = name;
	}
	~principal(){
		cout << "析构" << endl;
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
		master = new principal("杨老师");
	}
	school(const school& a)
	{
		cout << "拷贝构造函数" << endl;
		//master = new principal(*(p.master));
	}
	school(school&& other) :schoolType(other.schoolType), schoolName(other.schoolName), address(other.address)
	{
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}
	~school(){
		delete master;
	}

};

school getschool(){
	school s2("东北石油大学", "大学", "大庆");
	return s2;
}
int main()
{
	school s1(getschool());
	//school s2(std::move(s1));
	return 0;
}