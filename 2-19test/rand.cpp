#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

bool probability(int n)
{
	int p = rand() % 100;//����0-100�������
	if (p < n)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool probability(double n)
{
	double p = ((double)rand()) / RAND_MAX;
	if (p <n)
	{
		return true;
	}
	else
	{
		return false;
	}

}


//����[0,a)����
void Wrun(int a)
{
	int w = rand() % a;
	cout << w << endl;
}
//����[a,b)����
void Wrun(int a, int b)
{	
	int w = rand() % (b - a) + a;
	cout << w << endl;
}
//����һ��0~1�����С��
void Wrun(double a)
{
	double w = ((double)rand()) / RAND_MAX;
	cout << w << endl;
}
//����a~b�����С��
void Wrun2(int a, int b)
{
	double w = ((double)rand()) / (RAND_MAX / (b - a)) + a;
	cout << w << endl;
}


int main()
{
	srand(time(0));
	int t = 0, f = 0;
	for (int i = 0; i < 100; i++)
	{
		if (probability(0.01))
		{
			cout << "��" << endl;
			t++;
		}
		else
		{
			cout << "����" << endl;
			f++;
		}
	}
	cout << t << "��" << f << endl;
	Wrun(4);
	Wrun(2,10);
	Wrun(0.6);
	Wrun2(3, 10);
}