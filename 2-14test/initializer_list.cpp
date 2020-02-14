#include<iostream>
#include<vector>
#include<initializer_list>
//#define NDEBUG 断言失效
#include<assert.h>

using namespace std;
static_assert(sizeof(int) != 32, "不合适的int大小");
class vec //目的是创建一个vector里面存好一个堆区空间obj，然后通过初始化列表初始化
{
	int* obj;
	std::vector<int>a;
public:
	vec(std::initializer_list<int>arr):a(arr)//函数结束后会从内存中释放掉,int也可改为别的类型，例如double，写什么类型在main函数中就传什么类型
	{
		//arr.size();//代表有多少个元素
		//arr.begin();//代表第一个元素的指针
		//arr.end();//代表最后一个元素的下一个元素的指针

		//for (int i = 0; i < arr.size(); i++)
		//{
		//	cout << *(arr.begin() + i) << endl;
		//}

		//for (auto i = arr.begin(); i != arr.end(); i++)
		//{
		//	cout << *i << endl;
		//}
		
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			
			obj[i] = *(arr.begin() + i);//将obj里的第i个存进*(arr.begin() + i)这个值,遍历结束后会都存到obj里
		    
		}

	}
	~vec()
	{
		delete[]obj;
	}
	int &operator [](unsigned int index)//不返回引用不能修改v[i]的值
	{
		assert(index >= 0 && index < a.size());
		return obj[index];
	}

	
};

int main()
{

	vec v({ 1, 2, 3, 4 });//或vec v = { 1, 2, 3, 4 }; 初始化列表列表之后可以这么写
	cout << v[2] << endl;//3
	v[2] = 5;
	cout << v[2] << endl;//5
	cout << v[-2] << endl;//断言报错
}