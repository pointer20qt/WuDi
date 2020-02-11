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
			
		}//出现异常会跳转到catch 异常1
		throw 2;//自己抛出异常 异常2 （只会catch最前面的异常）
		cout << "打印完了" << endl;
	}
	catch (int test)
	{
		cout << "发生了异常,异常对象"<<test << endl;
	}
	catch (out_of_range & e)
	{
		cout << "发生了越界异常" << endl;//有匹配异常的catch匹配了之后，就不会再跳入别的异常
	}
	catch (...)//(...)所有异常都会catch
	{
		cout << "发生了异常" << endl;
	}
	cout << "程序最后一句" << endl;//程序依然会往下走

}