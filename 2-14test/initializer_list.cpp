#include<iostream>
#include<vector>
#include<initializer_list>
//#define NDEBUG ����ʧЧ
#include<assert.h>

using namespace std;
static_assert(sizeof(int) != 32, "�����ʵ�int��С");
class vec //Ŀ���Ǵ���һ��vector������һ�������ռ�obj��Ȼ��ͨ����ʼ���б��ʼ��
{
	int* obj;
	std::vector<int>a;
public:
	vec(std::initializer_list<int>arr):a(arr)//�������������ڴ����ͷŵ�,intҲ�ɸ�Ϊ������ͣ�����double��дʲô������main�����оʹ�ʲô����
	{
		//arr.size();//�����ж��ٸ�Ԫ��
		//arr.begin();//�����һ��Ԫ�ص�ָ��
		//arr.end();//�������һ��Ԫ�ص���һ��Ԫ�ص�ָ��

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
			
			obj[i] = *(arr.begin() + i);//��obj��ĵ�i�����*(arr.begin() + i)���ֵ,����������ᶼ�浽obj��
		    
		}

	}
	~vec()
	{
		delete[]obj;
	}
	int &operator [](unsigned int index)//���������ò����޸�v[i]��ֵ
	{
		assert(index >= 0 && index < a.size());
		return obj[index];
	}

	
};

int main()
{

	vec v({ 1, 2, 3, 4 });//��vec v = { 1, 2, 3, 4 }; ��ʼ���б��б�֮�������ôд
	cout << v[2] << endl;//3
	v[2] = 5;
	cout << v[2] << endl;//5
	cout << v[-2] << endl;//���Ա���
}