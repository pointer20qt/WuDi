#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

bool probability(int n)
{
	int p = rand() % 100;//生成0-100的随机数
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


//生成[0,a)的数
void Wrun(int a)
{
	int w = rand() % a;
	cout << w << endl;
}
//生成[a,b)的数
void Wrun(int a, int b)
{	
	int w = rand() % (b - a) + a;
	cout << w << endl;
}
//生成一个0~1的随机小数
void Wrun(double a)
{
	double w = ((double)rand()) / RAND_MAX;
	cout << w << endl;
}
//生成a~b的随机小数
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
			cout << "中" << endl;
			t++;
		}
		else
		{
			cout << "不中" << endl;
			f++;
		}
	}
	cout << t << "和" << f << endl;
	Wrun(4);
	Wrun(2,10);
	Wrun(0.6);
	Wrun2(3, 10);
}